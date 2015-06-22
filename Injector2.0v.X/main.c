//#include <stdio.h>
#include <pic16f1823.h>
#include <stdlib.h>
#include <xc.h>
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = ON          // Flash Program Memory Code Protection (Program memory code protection is enabled)
#pragma config CPD = OFF         // Data Memory Code Protection (Data memory code protection is enabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)
// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = ON      // PLL Enable (4x PLL disabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)
//#define _XTAL_FREQ 500000   // 500kHz?__delay_ms??????????????
//#define _XTAL_FREQ 125000   // 125kHz?__delay_ms??????????????
#define _XTAL_FREQ 62500   // 62.5kHz?__delay_ms??????????????
//#define _XTAL_FREQ 16000000   // 16MHz?__delay_ms??????????????
//#define _XTAL_FREQ 32000000   // 32MHz?__delay_ms??????????????
#define SELECT_SW PORTAbits.RA4
#define INJECT_SW PORTAbits.RA5
#define CHARGE_INPUT PORTCbits.RC1
#define INJECT_OUTPUT LATCbits.LATC4
#define CHECK_RESISTANCE LATCbits.LATC3
#define StatusChargeNon         1
#define StatusChargeConnected   2
#define StatusChargeCompleted   3
#define StatusBeep              4
#define     LEDmax  1
#define     NumLED  0
#define     InjectNow           1
#define     InjectDelay         2
#define     DelayTime           8000
//
//#define __delay(x) _delay((unsigned long)((x)))
//#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000000UL)))
//#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000UL)))
char R[LEDmax],G[LEDmax],B[LEDmax];
int AdcRes;
void StartBeepHigh();
void StartBeepLow();
void StopBeep();
void Inject();
unsigned char CheckVoltage();
void R_LED_ON(void){LATCbits.LATC0 = 1;}
void R_LED_OFF(void){LATCbits.LATC0 = 0;}
void G_LED_ON(void){LATAbits.LATA1 = 1;}
void G_LED_OFF(void){LATAbits.LATA1 = 0;}
void B_LED_ON(void){LATAbits.LATA0 = 1;}
void B_LED_OFF(void){LATAbits.LATA0 = 0;}
void LED(int SKY, unsigned int time);
void SerialLED_FadeIn(unsigned char ,unsigned int ,unsigned char ,unsigned char ,unsigned char );
void SerialLED_FadeOut(unsigned char ,unsigned int ,unsigned char ,unsigned char ,unsigned char );
unsigned int BatteryCheckVoltage();
unsigned int vBattery;
unsigned int i1,MyCNT;
unsigned char MyBuff;
unsigned char ChargeStatus,LastChargeStatus,BeepStatus,Status;
unsigned char cnt,cntCharge,fLED,fDsky;
unsigned int cntChargeNon;
//void SetClockHight(void){OSCCONbits.IRCF = 0b1110;       //32MHz}
//void 222L(void){
//    OSCCONbits.IRCF = 0b0100;   // 62.5kHz
//}
//void SetClockHight(void){OSCCONbits.IRCF = 0b1110;       //32MHz}
void delay_ms(int time){
    for(time;time>0;time--){
        __delay_ms(1);
    }
}
void delay_us(int utime){
    for(utime;utime>0;utime--){
        NOP();
    }
}
void Data1(){       //no nop 0.125us
    LATAbits.LATA1=1;//     0.88us
    asm(" nop");
    asm(" nop");
    asm(" nop");
    asm(" nop");
    asm(" nop");
    LATAbits.LATA1=0;
    //asm(" nop");
}
void Data0(){
    LATAbits.LATA1=1;//     0.38us
    asm(" nop");
    LATAbits.LATA1=0;
    //asm(" nop");
}
void SendLED(int num){
    int loop8,loopNum;
    int comp;
    for(loopNum=0;loopNum<num;loopNum++){
        comp=128;
        for(loop8=0;loop8<8;loop8++){
            if(comp&G[loopNum]){Data1();}else{Data0();}
            comp = comp>>1;
        }
        comp=128;
        for(loop8=0;loop8<8;loop8++){
            if(comp&R[loopNum]){Data1();}else{Data0();}
            comp = comp>>1;
        }
        comp=128;
        for(loop8=0;loop8<8;loop8++){
            if(comp&B[loopNum]){Data1();}else{Data0();}
            comp = comp>>1;
        }

    }
    __delay_ms(10);

}

void SerialLED(unsigned char r,unsigned char g,unsigned char b){
    T1CONbits.TMR1ON = 0;
    __delay_ms(1);
    OSCCONbits.IRCF = 0b1110;       //32MHz
    __delay_ms(2000);
    R[0]=r;
    G[0]=g;
    B[0]=b;
    SendLED(NumLED+1);
    OSCCONbits.IRCF = 0b0100;   // 62.5kHz
    __delay_ms(10);
    T1CONbits.TMR1ON = 1;
}
void CheckStatus(){
    if(PORTCbits.RC0==1){   //Charge Connected
        if(PORTAbits.RA2==1){//Charge Completed
            if(ChargeStatus!=StatusChargeCompleted){
                ChargeStatus=StatusChargeCompleted;
             }
        }else{  //ChargeConnected
            if(ChargeStatus!=StatusChargeConnected){
                ChargeStatus=StatusChargeConnected;
            }
        }
    }else{  //NonCharge
        if(ChargeStatus!=StatusChargeNon){
            ChargeStatus=StatusChargeNon;
        }
    }
}
void StatusDisplay1(void){
    CheckStatus();
    if(ChargeStatus!=LastChargeStatus){
        LastChargeStatus = ChargeStatus;

        if(ChargeStatus == StatusChargeConnected){
            __delay_ms(300);
            CheckStatus();if(ChargeStatus==StatusChargeConnected){SerialLED(20,0,0);}//20,0,0

//            if(LastChargeStatus!=StatusChargeCompleted){fDskySerialLED(0,20,0);}else{}
        }else if(ChargeStatus == StatusChargeCompleted){
            SerialLED(0,0,25);
        }else if(ChargeStatus == StatusChargeNon){
            if(BeepStatus!=1){
                SerialLED(0,0,0);
                TMR1H = (-1*DelayTime/4 >> 8);
                TMR1L = (-1*DelayTime/4 & 0x00ff);
                }
        }
    }
}
void StatusDisplayADC(void){
    vBattery = BatteryCheckVoltage();

    if(vBattery > 0x03ff*0.37){  //Battery full
        SerialLED(0,0,20);
    }else{  //Battery Low
        if(vBattery > 0x03ff*0.31){  //Battery Low
            SerialLED(24,13,0);
        }else{  //Battery Empty
            SerialLED(40,0,0);
        }
    }
}
void StartStatus(){
    CheckStatus();
//    OSCCONbits.IRCF = 0b1110;       //32MHz

    if(ChargeStatus == StatusChargeConnected){
        SerialLED(20,0,0);

    }else if(ChargeStatus == StatusChargeCompleted){
        SerialLED(20,0,0);

    }else if(ChargeStatus == StatusChargeNon){
        StatusDisplayADC();

    }
  //  OSCCONbits.IRCF = 0b0100;   // 62.5kHz
}

int main(int argc, char** argv)
{
    unsigned char i, checkv;
 //   unsigned char fInject;
    unsigned char nSwStat = 0, nSwStableCount = 0, bSwFixed = 0, bSwHolding = 0;
    unsigned char nSwHoldingCount = 0, bStay = 0, bBeep = 0, nBeepRepeatCount = 0, nBeepLengthCount = 0;
//    OSCCONbits.IRCF = 0b0101;   // 125kHz
    OSCCONbits.IRCF = 0b0100;   // 62.5kHz
//    OSCCONbits.IRCF = 0b0000;   // 31.25kHz
//    OSCCONbits.IRCF = 0b0111;       //500kHz
//    OSCCONbits.IRCF = 0b1111;       //16MHz
 //   OSCCONbits.IRCF = 0b1110;       //32MHz
    LATA = 0b00000000;
    LATC = 0b00000000;
    TRISA = 0b11111100;
    TRISC = 0b11000111;//rc0 input
    ANSELA = 0b00000000;
    ANSELC = 0b00000110;

    ADCON1 = 0b11110000; //ADFM=1,  Frc, VREF+ is connected to AVDD
    TMR1H = -1*32000>>8;
    TMR1L = -1*32000&0x00ff;
    
    StartStatus();
    delay_ms(50);
    SerialLED(0,0,0);
    delay_ms(50);

    StartStatus();
    delay_ms(50);
    SerialLED(0,0,0);
    delay_ms(100);
    /**Timer**/
//    INTCONbits.TMR0IE = 1;  //Timer0
    PIE1bits.TMR1IE = 1; //Timer1
   // OPTION_REGbits.TMR0CS = 0;    //Timer0 Clock Source Select bi
    T1CON = 0b00110001;

    /**Interrupt on Change**/
    IOCANbits.IOCAN5 = 1;
//  IOCAFbits.IOCAF5 = 1;
    INTCONbits.IOCIE = 1;//Interrupt On Change Enable

    INTCONbits.PEIE = 1; 
    INTCONbits.GIE = 1;

////    if(PCONbits.nRMCLR==0){    SerialLED(200,200,0);__delay_ms(1000);PCONbits.nRMCLR=1;}
////    if(PCONbits.nBOR==0){    SerialLED(200,200,200);__delay_ms(1000);PCONbits.nBOR=1;}
////    if(PCONbits.STKOVF==0){    SerialLED(200,0,200);__delay_ms(1000);}



    while(1)
    {
        if(INJECT_SW == nSwStat)
        {
            if(++nSwStableCount >= 5) bSwFixed = 1;
        }
        else
        {
            nSwStableCount = 0;
            bSwFixed = 0;
            nSwStat = 1 - nSwStat;
        }
        if(bSwFixed)
        {
            if(nSwStat == 1)
            {
                if(bBeep)
                {
                    StopBeep();
                    bBeep = 0;
                }
                bSwHolding = 0;
                nSwHoldingCount = 0;
                bStay = 0;
            }
            else
            {
                if(!bSwHolding)
                {
                    bSwHolding = 1;
                    checkv = CheckVoltage();
                    if(checkv == 1)
                    {
                        StartBeepLow();
                        __delay_ms(300);
                        StopBeep();
                        bStay = 1;
                    }
                    else if(checkv == 2)
                    {
                        StartBeepLow();
                        __delay_ms(300);
                        StopBeep();
                        __delay_ms(100);

                        StartBeepLow();
                        __delay_ms(300);
                        StopBeep();
                        bStay = 1;
                    }
                    else
                    {
                        if(SELECT_SW)
                        {
                            Inject();
                            bStay = 1;
                        }
                        else
                        {
                            StartBeepHigh();
                            bBeep = 1;
                            nBeepRepeatCount = 0;
                            nBeepLengthCount = 0;
                        }
                    }
                }
            }
        }

        if(bSwHolding && !bStay)
        {
            if(bBeep)
            {
                if(++nBeepLengthCount >= 5)
                {
                    StopBeep();
                    bBeep = 0;
                    nBeepLengthCount = 0;
                }
            }
            else
            {
                if(++nBeepLengthCount >= 40)
                {
                    if(++nBeepRepeatCount >= 3)
                    {
                        Inject();
                        bStay = 1;
                    }
                    else
                    {
                        StartBeepHigh();
                        bBeep = 1;
                        nBeepLengthCount = 0;
                    }
                }
            }
        }
        __delay_ms(10);
        StatusDisplay1();
    }
    return (EXIT_SUCCESS);
}
void StartBeepHigh()
{
    T1CONbits.TMR1ON = 0;
 //   ChargeStatus=StatusBeep;
//    T1CON = 0b00000000;
  //      INTCONbits.PEIE = 0;
    INTCONbits.GIE = 0;
    SerialLED(0,18,0);
    PR2 = 0x0c;
    CCP1CON = 0b00001100;
    CCP1CONbits.DC1B = (int)(0.5 * 4 * (0x0c + 1)) & 0x03;
    CCPR1L = (int)(0.5 * 4 * (0x0c + 1)) >> 2;
    T2CONbits.T2CKPS = 0;
    T2CONbits.TMR2ON = 1;

    BeepStatus = 1;
//    TRISCbits.TRISC5 = 0;


}
void StartBeepLow()
{
    T1CONbits.TMR1ON = 0;
//    ChargeStatus=StatusBeep;
   // T1CON = 0b00000000;
//    INTCONbits.PEIE = 0;
    INTCONbits.GIE = 0;

    delay_ms(5);
    SerialLED(20,0,0);
    delay_ms(50);
    PR2 = 0xff;
    CCP1CON = 0b00001100;
    CCP1CONbits.DC1B = (int)(0.5 * 4 * (0xff + 1)) & 0x03;
    CCPR1L = (int)(0.5 * 4 * (0xff + 1)) >> 2;
    T2CONbits.T2CKPS = 0;
    T2CONbits.TMR2ON = 1;
//    TRISCbits.TRISC5 = 0;
    BeepStatus = 1;


}
void StopBeep()
{
    T2CONbits.TMR2ON = 0;
    CCP1CON = 0x00;
    LATCbits.LATC5 = 0;  
    SerialLED(0,0,0);
//    INTCONbits.PEIE = 1;
    TMR1H = (-3);
//    T1CON = 0b00000001;
    INTCONbits.GIE = 1;
    T1CONbits.TMR1ON = 1;
    BeepStatus = 0;

        TMR1H = (-1*DelayTime >> 8);
    TMR1L = (-1*DelayTime & 0x00ff);
}
void Inject()
{
    vBattery = BatteryCheckVoltage();

    if(vBattery > 0x03ff*0.31){
        StartBeepHigh();
        B_LED_ON();
        INJECT_OUTPUT = 1;
        __delay_ms(2);
        __delay_us(300);
        INJECT_OUTPUT = 0;
        __delay_ms(1000);
        B_LED_OFF();
    }else{
        StartBeepLow();
        __delay_ms(70);
            StopBeep();
            __delay_ms(5);
        StartBeepLow();
        __delay_ms(400);
    }
    StopBeep();

   //     __delay_ms(1000);
}
unsigned int BatteryCheckVoltage()
{//AN5 ANALOG INPUT
    unsigned int ad1, ad2, thresh, i;

    // A/D converter enable
    ADCON0 = 0b00010101;    // Select AN5, GO=0, ADON=1

    // A/D????
    ADCON0 = 0b00010111;    // Select AN5, GO=1, ADON=1

    // A/D??????
    while(ADCON0 & 0x02);

    AdcRes = ((unsigned int)ADRESH << 8) | (unsigned int)ADRESL;

    return AdcRes;
}
unsigned char CheckVoltage()
{
    unsigned int ad1, ad2, thresh, i;

    // A/D converter enable
    ADCON0 = 0b00010101;    // Select AN5, GO=0, ADON=1
 //   ADCON0 = 0b00011011;    // Select AN6, GO=1, ADON=1
    CHECK_RESISTANCE = 1;
    __delay_us(100);
    ADCON0 = 0b00011011;    // Select AN6, GO=1, ADON=1
    while(ADCON0 & 0x02);

    ad2 = ((unsigned int)ADRESH << 8) | (unsigned int)ADRESL;

    CHECK_RESISTANCE = 0;

    //    thresh = (unsigned int)(0x3ff * 100.0 / 102.0 * 0.8);
    thresh = (unsigned int)(0x3ff * 100.0 / 102.0 * 0.8);

    if(ad2 < thresh)
    {
        return 1;
    }
//    thresh = (unsigned int)(0x3ff * 101.0 / 102.0);
//    thresh = (unsigned int)1013;
    thresh = (unsigned int)1013;
//    thresh = 0x3ff;
    if(ad2 > thresh)
    {
        return 2;
    }
    return 0;
}

static void interrupt isr(void) {
    if(IOCAFbits.IOCAF5 != 1){
        CheckStatus();
        if(BeepStatus!=1){
            if(PIR1bits.TMR1IF == 1) {  //Timer1
                if(ChargeStatus == StatusChargeConnected){
                    SerialLED(20,0,0);//20,0,0
                }else if(ChargeStatus == StatusChargeCompleted){
                    SerialLED(0,0,25);
                }
                        TMR1H = (-2000>>8);
                        TMR1L = (-2000 & 0x00ff);
                if(ChargeStatus == StatusChargeNon){
                    if(fLED == 0){
                        fLED = 1;
                        StatusDisplayADC();
//                        vBattery = BatteryCheckVoltage();
//                        if(vBattery > 0x03ff*0.37){  //Battery full
//                            //SerialLED_FadeIn(200,200,0,0,250);
//                                SerialLED(250,100,0);
//                        }else{  //Battery Low
//                            if(vBattery > 0x03ff*0.32){  //Battery Low
//                                SerialLED(250,100,0);
//                            }else{  //Battery Empty
//                                SerialLED(200,0,0);
//                            }
                       // }
                        TMR1H = (-1);
                        TMR1L = (0);
                    }else{
                        fLED = 0;
                        TMR1H = (-1*DelayTime >> 8);
                        TMR1L = (-1*DelayTime & 0x00ff);
                        SerialLED(0,0,0);
                    }
                }
            }
        }
        PIR1bits.TMR1IF = 0; //Timer1
    }else{IOCAFbits.IOCAF5 =0;}
}
