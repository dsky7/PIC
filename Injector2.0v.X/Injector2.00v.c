/* 
 * File:   main.c
 * Author: dsky
 *
 * Created on 2014/12/20, 15:54
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = ON          // Flash Program Memory Code Protection (Program memory code protection is enabled)
#pragma config CPD = ON         // Data Memory Code Protection (Data memory code protection is enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
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
#define     LEDmax  1
#define     NumLED  0
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
//void SetClockHight(void);

unsigned int vBattery;
unsigned int i1;
unsigned char ChargeStatus;



unsigned char cnt; //1????4?????
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

SendLED(int num){
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


void LedPWM(int Rduty,int Gduty,int Bduty){

    B_LED_ON();
    G_LED_ON();
    R_LED_ON();
    for(int i=0; i<100; i++){

        if(Rduty==0){R_LED_OFF();}
        if(Gduty==0){G_LED_OFF();}
        if(Bduty==0){B_LED_OFF();}
        Rduty = Rduty - 1;
        Gduty = Gduty - 1;
        Bduty = Bduty - 1;

    }
    B_LED_OFF();
    G_LED_OFF();
    R_LED_OFF();
}


void LED(int SKY, unsigned int time){
    switch(SKY){
            case 0:
                R_LED_ON();
                G_LED_ON();
                B_LED_ON();
                delay_ms(time);
                R_LED_OFF();
                G_LED_OFF();
                B_LED_OFF();
                break;

            case 1:
                R_LED_ON();
                delay_ms(time);
                R_LED_OFF();
                break;

            case 2:
                G_LED_ON();
                delay_ms(time);
                G_LED_OFF();
                break;

            case 3:
                B_LED_ON();
                delay_ms(time);
                B_LED_OFF();
                break;

            case 4:
                R_LED_ON();
                G_LED_ON();
                delay_ms(time);
                R_LED_OFF();
                G_LED_OFF();
                break;
            case 5:
                B_LED_ON();
                G_LED_ON();
                delay_ms(time);
                B_LED_OFF();
                G_LED_OFF();
                break;
            case 6:
                R_LED_ON();
                B_LED_ON();
                delay_ms(time);
                R_LED_OFF();
                B_LED_OFF();
                break;
            default:
	
		break;
    }
}

void LEDStart(){
    int x;
    for(x=0;x<100;x++){
        int i;
        for(i=0;i<15;i++){
            LedPWM(x,x,x);
        }
    }
}
void LEDStop(){
    int x;
    for(x=100;x>0;x--){
        int i;
        for(i=0;i<15;i++){
            LedPWM(x,x,x);
        }
    }       
}
void LEDFlash(int flash,int r, int g, int b){
    int x;
    for(flash;flash==0;flash--){
        for(x=100;x==0;x--){
            LedPWM(r,g,b);
            B_LED_OFF();
            delay_ms(1000);
        }

        
    }
}
void SerialLED(unsigned char r,unsigned char g,unsigned char b){
    R[0]=r;
    G[0]=g;
    B[0]=b;
    SendLED(NumLED+1);
}

void SerialLED_FadeIn(unsigned char delay,unsigned int time,unsigned char r,unsigned char g,unsigned char b){

    for(i1=0;i1<time;i1++){
        R[NumLED]=r/time*i1;
        G[NumLED]=g/time*i1;
        B[NumLED]=b/time*i1;
        SendLED(NumLED+1);
        delay_ms(delay);
    }
}
void SerialLED_FadeOut(unsigned char delay,unsigned int time,unsigned char r,unsigned char g,unsigned char b){

    for(i1=time;i1>0;i1--){
        R[NumLED]=(r/time*(i1-1));
        G[NumLED]=g/time*(i1-1);
        B[NumLED]=b/time*(i1-1);
        SendLED(NumLED+1);
        delay_ms(delay);
    }
}

void CheckStatus(){
    if(PORTCbits.RC0==1){   //Charge Connected
        if(PORTAbits.RA2==1){//Charge Completed
            if(ChargeStatus!=StatusChargeCompleted){
                ChargeStatus=StatusChargeCompleted;
                SerialLED_FadeIn(10,100,0,250,250);
            }
        }else{  //ChargeConnected
            if(ChargeStatus!=StatusChargeConnected){
                ChargeStatus=StatusChargeConnected;
                SerialLED_FadeIn(10,100,250,50,50);
            }
        }
    }else{  //NonCharge
        if(ChargeStatus!=StatusChargeNon){
            ChargeStatus=StatusChargeNon;
            SerialLED_FadeIn(10,100,250,250,250);
            SerialLED_FadeOut(10,100,250,250,250);
        }
    }
}

int main(int argc, char** argv)
{
    unsigned char i, checkv;
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
//    TRISA = 0b11111000;
//    TRISC = 0b11000110;

    TRISA = 0b11111100;
    TRISC = 0b11000111;//rc0 input
//    TRISC = 0b11000110;
//    ANSELA = 0b00000000;
//    ANSELC = 0b00000110;
    ANSELA = 0b00000000;
    ANSELC = 0b00000110;
  //  T1CONbits.T1CKPS = 0b11;

    // A/D clock,VREF+??
//    ADCON1 = 0b10000000; //ADFM=1,  Fosc/2, VREF+ is connected to AVDD
    ADCON1 = 0b11110000; //ADFM=1,  Frc, VREF+ is connected to AVDD
        TMR1H = (-2000 >> 8);
        TMR1L = (-2000 & 0x00ff);
    PIE1bits.TMR1IE = 1; //Timer1??????
    INTCONbits.PEIE = 1; //???????????(Timer1?????)
    INTCONbits.GIE = 1; //???????
    T1CON = 0b00110001; //???? ???Fosc/4, ???????8, TMR1ON
//    T1CON = 0b11110001; //???? ???caposc, ???????8, TMR1ON
//    unsigned char dskynum;
//    while(1){
//        __delay_ms(1000);
// //       OSCCONbits.IRCF = 0b0100;   // 62.5kHz
//        dskynum = CheckVoltage();
//  //      OSCCONbits.IRCF = 0b1110;       //32MHz
//        if(dskynum==0){
//            __delay_ms(1000);
//        }else{
//
//            LED(2,1000);
//        }
//
//    }

//        while(1){
//
//        if(PORTCbits.RC0==1){
//            SerialLED_FadeIn(10,100,0,250,250);
//            SerialLED_FadeOut(10,100,0,250,250);
//            __delay_ms(500);
//
//        }else{
//            SerialLED_FadeIn(10,100,250,250,250);
//            SerialLED_FadeOut(10,100,250,250,250);
//            __delay_ms(500);
//        }
//    }
//
//    while(1){
//        CheckStatus();
//        __delay_ms(1000);
//
//    }


       while(1){B_LED_ON();__delay_ms(2000);B_LED_OFF();__delay_ms(500);}


//       while(1){R_LED_ON();B_LED_ON();__delay_ms(1000);R_LED_OFF();B_LED_OFF();__delay_ms(1000);}
//  while(1){StopBeep();__delay_ms(1000);StartBeepHigh();__delay_ms(1000);StartBeepLow();__delay_ms(1000);}

//    while(1){
//            SerialLED_FadeIn(10,100,0,250,250);
//            SerialLED_FadeOut(10,100,0,250,250);
//CHECK_RESISTANCE = 1;
//__delay_ms(1000);
//CHECK_RESISTANCE = 0;
//
//    }


    while(1)
    {
        CheckStatus();
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
                // SW??
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
                // SW??
                if(!bSwHolding)
                {
                    bSwHolding = 1;

                    checkv = CheckVoltage();

                    if(checkv == 1)
                    {
                        // ??
                        StartBeepLow();
                        SerialLED(200,200,0);
                        __delay_ms(300);
                        SerialLED(0,0,0);
                        StopBeep();
                        bStay = 1;
                    }
                    else if(checkv == 2)
                    {
                        // ????
                        StartBeepLow();
                        SerialLED(200,200,0);
                        __delay_ms(300);
                        SerialLED(0,0,0);
                        StopBeep();


                        __delay_ms(100);


                        StartBeepLow();
                        SerialLED(200,200,0);
                        __delay_ms(300);
                        SerialLED(0,0,0);
                        StopBeep();

                        bStay = 1;
                    }
                    else
                    {
                        // ?????
                        if(SELECT_SW)
                        {
                            // ???
                            Inject();
                            bStay = 1;
                            //LED(0,1000);
                        }
                        else
                        {
                            // ???????????
                            StartBeepHigh();
                            SerialLED(0,50,0);
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
                        // ????
                        Inject();
                        bStay = 1;
                        //LED(0,1000);
                    }
                    else
                    {
                        StartBeepHigh();
                        SerialLED(0,nBeepRepeatCount*100+50,0);
                        bBeep = 1;
                        nBeepLengthCount = 0;
                    }
                }
            }
        }
        __delay_ms(10);
    }

    return (EXIT_SUCCESS);
}

void StartBeepHigh()
{
    PR2 = 0x0c;
    CCP1CON = 0b00001100;
    CCP1CONbits.DC1B = (int)(0.5 * 4 * (0x0c + 1)) & 0x03;
    CCPR1L = (int)(0.5 * 4 * (0x0c + 1)) >> 2;
    T2CONbits.T2CKPS = 0;
    T2CONbits.TMR2ON = 1;
//    TRISCbits.TRISC5 = 0;
}

void StartBeepLow()
{
    PR2 = 0xff;
    CCP1CON = 0b00001100;
    CCP1CONbits.DC1B = (int)(0.5 * 4 * (0xff + 1)) & 0x03;
    CCPR1L = (int)(0.5 * 4 * (0xff + 1)) >> 2;
    T2CONbits.T2CKPS = 0;
    T2CONbits.TMR2ON = 1;
//    TRISCbits.TRISC5 = 0;
}

void StopBeep()
{
    T2CONbits.TMR2ON = 0;
    CCP1CON = 0x00;
    LATCbits.LATC5 = 0;
//    TRISCbits.TRISC5 = 1;
    SerialLED(0,0,0);
}

// ????
void Inject()
{
    StartBeepHigh();

    INJECT_OUTPUT = 1;  // ??????
    __delay_ms(2);
    __delay_us(500);    // ????
    INJECT_OUTPUT = 0;  // ??????
    SerialLED(0,200,0);
    __delay_ms(1000);
    SerialLED(0,0,0);
    StopBeep();
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
{// ??? 0:??  1:??  2:????
    unsigned int ad1, ad2, thresh, i;

    // A/D converter enable
    ADCON0 = 0b00010101;    // Select AN5, GO=0, ADON=1
 //   ADCON0 = 0b00011011;    // Select AN6, GO=1, ADON=1
    // ????????ON
    CHECK_RESISTANCE = 1;
    __delay_us(100);

#if 0
    // A/D????
    ADCON0 = 0b00010111;    // Select AN5, GO=1, ADON=1

    // A/D??????
    while(ADCON0 & 0x02);

    ad1 = ((unsigned int)ADRESH << 8) | (unsigned int)ADRESL;
#endif

    // A/D????
    ADCON0 = 0b00011011;    // Select AN6, GO=1, ADON=1

    // A/D??????
    while(ADCON0 & 0x02);

    ad2 = ((unsigned int)ADRESH << 8) | (unsigned int)ADRESL;

    // ????????OFF
    CHECK_RESISTANCE = 0;

#if 0
    for(i=0;i<16;i++)
    {
        if(ad2 & (0x8000 >> i))
        {
            StartBeepHigh();
            __delay_ms(200);
            StopBeep();
        }
        else
        {
            StartBeepLow();
            __delay_ms(200);
            StopBeep();
        }
        __delay_ms(500);
    }
#endif

    //    thresh = (unsigned int)(0x3ff * 100.0 / 102.0 * 0.8);
    thresh = (unsigned int)(0x3ff * 100.0 / 102.0 * 0.8);
//    if(ad2 == 0)
//    {
//        // ??
////            SerialLED(200,0,0);
////    __delay_ms(1000);
////    SerialLED(0,0,0);
//        return 7;
//    }

    if(ad2 < thresh)
    {
        // ??
        return 1;
    }
//    thresh = (unsigned int)(0x3ff * 101.0 / 102.0);
    thresh = (unsigned int)1013;
//    thresh = 0x3ff;
    if(ad2 > thresh)
    {
        // ????
        return 2;
    }

    return 0;
}


static void interrupt isr(void) { //??????

    if(PIR1bits.TMR1IF == 1) {  //?????Timer1??????
        OSCCONbits.IRCF = 0b1110;       //32MHz
        if(ChargeStatus == StatusChargeNon){

            if(PORTAbits.RA2==1){
                //LED(0,100);
                SerialLED_FadeIn(2,100,250,250,250);
                SerialLED_FadeOut(2,100,250,250,250);
            }else{
                vBattery = BatteryCheckVoltage();

                if(vBattery > 0x03ff*0.35){  //Battery full
                    SerialLED_FadeIn(2,100,250,250,250);
                    SerialLED_FadeOut(2,100,250,250,250);
                }else{  //Battery Low
                    if(vBattery > 0x03ff*0.32){  //Battery Low

                        SerialLED_FadeIn(2,100,0,250,250);
                       SerialLED_FadeOut(2,100,0,250,250);

                    }else{  //Battery Empty
                        //StartBeepHigh();

                        SerialLED_FadeIn(2,100,250,0,250);
                        SerialLED_FadeOut(2,100,250,0,250);
                        //StopBeep();
                    }
                }
            }

            TMR1H = (-2000 >> 8);
            TMR1L = (-2000 & 0x00ff);

            cnt++; //4?????? ???????
            OSCCONbits.IRCF = 0b0100;   // 62.5kHz
        }
        PIR1bits.TMR1IF = 0; //Timer1???????????
    }
    
}


