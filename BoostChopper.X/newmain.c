/* 
 * File:   newmain.c
 * Author: dsky
 *
 * Created on 2015/02/07, 2:43
 */


// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
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
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable (All VCAP pin functionality is disabled)
#pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

#include <pic16f1936.h>
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 16000000   // 500kHz?__delay_ms??????????????
#define     LEDmax  1

char R[LEDmax],G[LEDmax],B[LEDmax];

unsigned char CheckVoltage()
{
    unsigned int ad1, ad2, thresh, i;

    // A/D converter enable
    ADCON0 = 0b00010101;    // Select AN5, GO=0, ADON=1

 
    __delay_us(100);

    // A/D????
    ADCON0 = 0b00011011;    // Select AN6, GO=1, ADON=1

    // A/D??????
    while(ADCON0 & 0x02);

    ad2 = ((unsigned int)ADRESH << 8) | (unsigned int)ADRESL; 
}

void Data1(){       //no nop 0.125us
    LATCbits.LATC0=1;//     0.88us
    asm(" nop");
    asm(" nop");
    asm(" nop");
    asm(" nop");
    asm(" nop");
    LATCbits.LATC0=0;
    //asm(" nop");
}
void Data0(){
    LATCbits.LATC0=1;//     0.38us
    asm(" nop");
    LATCbits.LATC0=0;
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
    __delay_us(50);

}


int main(int argc, char** argv) {

    TRISCbits.TRISC0=0;
//    OSCCONbits.IRCF = 0b0111;       //500kHz
//    OSCCONbits.IRCF = 0b1111;       //16MHz
    OSCCONbits.IRCF = 0b1110;       //32MHz


    unsigned int i;
    R[0]=64;G[0]=64;B[0]=64;

    while(1){
        SendLED(1);
        R[0]=i;
        G[0]=i;
        B[0]=i;
        i++;
        __delay_ms(10);
    }

    return (EXIT_SUCCESS);
}

