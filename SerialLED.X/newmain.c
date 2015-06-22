
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <math.h>
//#define _XTAL_FREQ 500000   // 62.5kHz?__delay_ms??????????????
#define _XTAL_FREQ 80000000
//#define     LEDmax 40
// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection (HS Oscillator, High-speed crystal/resonator connected between OSC1 and OSC2 pins)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

#define     LED1        PORTAbits.RA1
#define     Nop()       asm(" nop")
#define     LEDfront    10
#define     DelayTime1   10
#define     DelayTimeMyColor    24
#define     DelayTimeEnd        5
#define     DelayTimeAlarmAccession        50
#define     BrightnessStart     30
#define     BrightnessEnd       30
#define     BrightnessAlarmAccession    252
#define     LEDmax  40
#define     DecayRate      0.8

char    Color1[3] = {0,140,158};
char    Color2[3] = {136,196,37};
char    Color3[3] = {255,0,111};
char    Color4[3] = {250,80,0};

char R[LEDmax],G[LEDmax],B[LEDmax];
double rad1;
double pi = 3.14;
int i0,i1,i2;

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

void Data0(void){
    LED1 = 1;//9

    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();

    LED1 = 0;//14
}
void Data1(void){
        LED1 = 1;//9
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();

    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();

    Nop();
    Nop();

    LED1 = 0;//14


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
    __delay_us(50);

}

void Decay(){
   for(i1=0;i1<20;i1++){
        for(i2=0;i2<LEDmax;i2++){
            R[i2]=R[i2]*0.9;
            G[i2]=G[i2]*0.9;
            B[i2]=B[i2]*0.9;
        }    SendLED(LEDmax);
        __delay_ms(10);
    }
}

void Start(){
    for(i1=0;i1<BrightnessStart;i1++){
        for(i2=0;i2<LEDmax;i2++){
            R[i2]=i1;
            G[i2]=i1;
            B[i2]=i1;
        }
        SendLED(LEDmax);
        __delay_ms(DelayTime1);
    }

    for(i0=0;i0<3;i0++){
        for(i1=0;i1<LEDmax-8;i1++){
            for(i2=0;i2<LEDmax;i2++){
                R[i2]=BrightnessStart;
                G[i2]=BrightnessStart;
                B[i2]=BrightnessStart;
            }
            R[i1]=BrightnessStart;
            G[i1]=BrightnessStart;
            B[i1]=BrightnessStart + 100;

            R[i1+1]=BrightnessStart;
            G[i1+1]=BrightnessStart;
            B[i1+1]=BrightnessStart + 180;

            R[i1+2]=BrightnessStart;
            G[i1+2]=BrightnessStart;
            B[i1+2]=BrightnessStart + 200;

            R[i1+3]=BrightnessStart;
            G[i1+3]=BrightnessStart;
            B[i1+3]=BrightnessStart + 220;

            R[i1+4]=BrightnessStart;
            G[i1+4]=BrightnessStart;
            B[i1+4]=BrightnessStart + 220;

            R[i1+5]=BrightnessStart;
            G[i1+5]=BrightnessStart;
            B[i1+5]=BrightnessStart + 200;

            R[i1+6]=BrightnessStart;
            G[i1+6]=BrightnessStart;
            B[i1+6]=BrightnessStart + 180;

            R[i1+7]=BrightnessStart;
            G[i1+7]=BrightnessStart;
            B[i1+7]=BrightnessStart + 100;

            SendLED(LEDmax);
            __delay_ms(10);
        }
    }
Decay();
//    for(i1=0;i1<20;i1++){
//        for(i2=0;i2<LEDmax;i2++){
//            R[i2]=R[i2]*0.9;
//            G[i2]=G[i2]*0.9;
//            B[i2]=B[i2]*0.9;
//        }    SendLED(LEDmax);
//        __delay_ms(10);
//    }

    for(i2=0;i2<255;i2++){
        for(i1=0;i1<LEDmax;i1++){
            R[i1]=i2;
            G[i1]=i2;
            B[i1]=i2;
        }SendLED(LEDmax);
    }
    for(i2=255;i2>=0;i2--){
        for(i1=0;i1<LEDmax;i1++){
            R[i1]=i2;
            G[i1]=i2;
            B[i1]=i2;
        }SendLED(LEDmax);
        delay_ms(6);
    }
    __delay_ms(2000);

}

void MyColor(){
    for(i2=0;i2<LEDmax;i2++){
        R[i2]=0;
        G[i2]=0;
        B[i2]=0;
    }
    SendLED(LEDmax);


    for(i1=0;i1<255;i1++){
        for(i2=0;i2<LEDmax;i2++){
            R[i2]=i1;
            G[i2]=0;
            B[i2]=0;
        }SendLED(LEDmax);
        delay_ms(4);
    }

    for(i1=0;i1<255;i1++){
        for(i2=0;i2<LEDmax;i2++){
            R[i2]=255-i1;
            G[i2]=0;
            B[i2]=i1;
        }
        SendLED(LEDmax);
        delay_ms(DelayTimeMyColor);
    }

    for(i1=0;i1<255;i1++){
        for(i2=0;i2<LEDmax;i2++){
            R[i2]=0;
            G[i2]=i1;
            B[i2]=255-i1;
        }
        SendLED(LEDmax);
        delay_ms(DelayTimeMyColor);
    }

    for(i1=0;i1<255;i1++){
        for(i2=0;i2<LEDmax;i2++){
            R[i2]=i1;
            G[i2]=255-i1;
            B[i2]=0;
        }
        SendLED(LEDmax);
        delay_ms(DelayTimeMyColor);
    }


    for(i2=255;i2>=0;i2--){
    for(i1=0;i1<LEDmax;i1++){
        R[i1]=i2;
        G[i1]=0;
        B[i1]=0;
    }
    SendLED(LEDmax);
    __delay_ms(10);
    }
    __delay_ms(1000);
}


void AlarmAccessionLeft(){
 /*left*/
      for(i1=0;i1<BrightnessAlarmAccession;i1=i1+4){
        for(i2=0;i2<LEDmax;i2++){
            if(i2>30 && i2<41){
                R[i2]=i1;
                G[i2]=0;
                B[i2]=0;
            }else{
                R[i2]=0;
                G[i2]=0;
                B[i2]=0;

            }
        }SendLED(LEDmax);
    }
    __delay_ms(DelayTimeAlarmAccession);
    for(i1=BrightnessAlarmAccession;i1=0;i1=i1-4){
        for(i2=0;i2<LEDmax;i2++){
            if(i2>30 && i2<41){
                R[i2]=i1;
                G[i2]=0;
                B[i2]=0;
            }else{
                R[i2]=0;
                G[i2]=0;
                B[i2]=0;
            }
        }SendLED(LEDmax);
    }

    __delay_ms(DelayTimeAlarmAccession);
    for(i1=0;i1<BrightnessAlarmAccession;i1=i1+4){
        for(i2=0;i2<LEDmax;i2++){
            if(i2>30 && i2<41){
                R[i2]=i1;
                G[i2]=0;
                B[i2]=0;
            }else{
                R[i2]=0;
                G[i2]=0;
                B[i2]=0;

            }
        }SendLED(LEDmax);
    }
    __delay_ms(DelayTimeAlarmAccession);
    for(i1=BrightnessAlarmAccession;i1>=0;i1=i1-4){
        for(i2=0;i2<LEDmax;i2++){
            if(i2>30 && i2<41){
                R[i2]=i1;
                G[i2]=0;
                B[i2]=0;
            }else{
                R[i2]=0;
                G[i2]=0;
                B[i2]=0;
            }
        }SendLED(LEDmax);
    }


//    __delay_ms(500);
//
//    for(i1=255;i1>0;i1--){
//        for(i2=0;i2<LEDmax;i2++){
//            R[i2]=i1;
//            G[i2]=0;
//            B[i2]=0;
//        }SendLED(LEDmax);
//    }
    __delay_ms(500);
}
void AlarmAccession(){

//    /*all*/
//    for(i1=0;i1<BrightnessAlarmAccession;i1=i1+4){
//        for(i2=0;i2<LEDmax;i2++){
//            R[i2]=i1;
//            G[i2]=0;
//            B[i2]=0;
//        }SendLED(LEDmax);
//    }
//    __delay_ms(DelayTimeAlarmAccession);
//    for(i1=BrightnessAlarmAccession;i1=0;i1=i1-4){
//        for(i2=0;i2<LEDmax;i2++){
//            R[i2]=i1;
//            G[i2]=0;
//            B[i2]=0;
//        }SendLED(LEDmax);
//    }
//
//    __delay_ms(DelayTimeAlarmAccession);
//
//    for(i1=0;i1<BrightnessAlarmAccession;i1++){
//        for(i2=0;i2<LEDmax;i2++){
//            R[i2]=i1;
//            G[i2]=0;
//            B[i2]=0;
//        }SendLED(LEDmax);
//    }
//    __delay_ms(DelayTimeAlarmAccession);
//    for(i1=BrightnessAlarmAccession;i1>=0;i1--){
//        for(i2=0;i2<LEDmax;i2++){
//            R[i2]=i1;
//            G[i2]=0;
//            B[i2]=0;
//        }SendLED(LEDmax);
//    }
//
////
////    __delay_ms(500);
////    for(i1=255;i1>0;i1--){
////        for(i2=0;i2<LEDmax;i2++){
////            R[i2]=i1;
////            G[i2]=0;
////            B[i2]=0;
////        }SendLED(LEDmax);
////    }
//    __delay_ms(500);
/*right*/
    for(i1=0;i1<BrightnessAlarmAccession;i1=i1+4){
        for(i2=0;i2<LEDmax;i2++){
            if(i2>=10 && i2<20){
                R[i2]=i1;
                G[i2]=0;
                B[i2]=0;
            }else{
                R[i2]=0;
                G[i2]=0;
                B[i2]=0;

            }
        }SendLED(LEDmax);
    }
    __delay_ms(DelayTimeAlarmAccession);
    for(i1=BrightnessAlarmAccession;i1=0;i1=i1-4){
        for(i2=0;i2<LEDmax;i2++){
            if(i2>=10 && i2<20){
                R[i2]=i1;
                G[i2]=0;
                B[i2]=0;
            }else{
                R[i2]=0;
                G[i2]=0;
                B[i2]=0;
            }
        }SendLED(LEDmax);
    }

    __delay_ms(DelayTimeAlarmAccession);
    for(i1=0;i1<BrightnessAlarmAccession;i1=i1+4){
        for(i2=0;i2<LEDmax;i2++){
            if(i2>=10 && i2<20){
                R[i2]=i1;
                G[i2]=0;
                B[i2]=0;
            }else{
                R[i2]=0;
                G[i2]=0;
                B[i2]=0;

            }
        }SendLED(LEDmax);
    }
    __delay_ms(DelayTimeAlarmAccession);
    for(i1=BrightnessAlarmAccession;i1>=0;i1=i1-4){
        for(i2=0;i2<LEDmax;i2++){
            if(i2>=10 && i2<20){
                R[i2]=i1;
                G[i2]=0;
                B[i2]=0;
            }else{
                R[i2]=0;
                G[i2]=0;
                B[i2]=0;
            }
        }SendLED(LEDmax);
    }

//    __delay_ms(500);
//    for(i1=255;i1>0;i1--){
//        for(i2=0;i2<LEDmax;i2++){
//            R[i2]=i1;
//            G[i2]=0;
//            B[i2]=0;
//        }SendLED(LEDmax);
//    }
    __delay_ms(1000);
}

void FadeIn(char Red,char Green,char Blue,char start1,char goal1,char delay){
    char goal,start,start0,goal0,i3;
    for(i1=0;i1<255;i1++){
        if(start1>goal1){
            goal = LEDmax-1;
            for(i3=0;i3<=goal1;i3++){
                R[i3]=i1 * Red /255;
                G[i3]=i1 * Green /255;
                B[i3]=i1 * Blue /255;
            }
        }else{goal=goal1;}
        
        for(i2=start1;i2<=goal;i2++){
            R[i2]=i1 * Red /255;
            G[i2]=i1 * Green /255;
            B[i2]=i1 * Blue /255;
        }
        SendLED(LEDmax);
        delay_us(delay);

    }
}
void FireWorks(){
    for(i2=0;i2<LEDmax;i2++){
        R[i2]=0;
        G[i2]=0;
        B[i2]=0;
    }


    FadeIn(Color1[0],Color1[1],Color1[2],7,12,1);
    delay_ms(1000);

    FadeIn(Color2[0],Color2[1],Color2[2],27,32,1);
    delay_ms(1000);

    FadeIn(Color3[0],Color3[1],Color3[2],37,2,1);
    delay_ms(1000);

    FadeIn(Color4[0],Color4[1],Color4[2],17,22,1);
    delay_ms(1000);



}

void FireWorksFadeOut(){
    Decay();
    Decay();



}
void ClearLED(){
    for(i2=0;i2<LEDmax;i2++){
        R[i2]=0;
        G[i2]=0;
        B[i2]=0;
    }
}


int main(int argc, char** argv) {
//    OSCCONbits.IRCF = 0b1110;   //8M OR 32M Hz
    OSCCONbits.IRCF = 0b1110;   //16M Hz
    OSCCONbits.SPLLEN = 0b1;
    LATA = 0b00000000;
    TRISA = 0;
    ANSELA = 0b00000000;

//    while(1){
//
//
//        FadeIn(Color1[0],Color1[1],Color1[2],7,12,1);
//    delay_ms(1000);
//
//    FadeIn(Color2[0],Color2[1],Color2[2],27,32,1);
//    delay_ms(1000);
//
//    FadeIn(Color3[0],Color3[1],Color3[2],37,2,1);
//    delay_ms(1000);
//
//    FadeIn(Color4[0],Color4[1],Color4[2],17,22,1);
//    delay_ms(1000);
//
//    }

  //  while(1){FadeIn(0,0,255,17,12,1000);ClearLED();delay_ms(1000);}

    while(1){
        Start();
        delay_ms(1000);
        MyColor();
        delay_ms(1000);
        AlarmAccession();
        AlarmAccessionLeft();
        delay_ms(1000);
        FireWorks();
        delay_ms(1000);
        FireWorksFadeOut();
        delay_ms(2000);
    }


    return (EXIT_SUCCESS);
}

