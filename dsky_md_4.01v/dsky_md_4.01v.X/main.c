/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <p33ep32mc202.h>
/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif
	

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include <libpic30.h>
/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

extern long            tarVel1;
extern int              idR;

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/


int16_t main(void)
{

    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();
//    T2CONbits.TON = 1;
//    T1CONbits.TON = 1;

    LED();
TMR3 = 9000;
//    tarVel1 = 18;
    InitT3();
    T3CONbits.TON = 1;

    LED(1,1000);
    while(1){LED(1,500);    T3CONbits.TON = 0;TMR3 = 0;    T3CONbits.TON = 1;delay_ms(500);    T3CONbits.TON = 0;TMR3 = 0;    T3CONbits.TON = 1;}

    ROTATE_N(100);
    delay_ms(1000);
        T2CONbits.TON = 1;
    while(1){delay_ms(1000);}

    int i;
    LED(0,2000);
    while(1){
        for(i=0;i<4;i++){
            tarVel1 = i;
            LED(1,1000);
            delay_ms(1000);
        }
    }
    while(1){delay_ms(1000);}
    ROTATE_N(100);
    while(1){
        if(POS1CNTL<-1760){R_LED_ON();B_LED_OFF();}else{B_LED_ON();R_LED_OFF();}
    }


    while(1){
        idR = 2*PORTBbits.RB7 + PORTBbits.RB8;          //R18=RB07   R17=RB08

        switch(idR){
            case 0:
                B_LED_OFF();
                R_LED_OFF();
                break;
            case 1:
                B_LED_ON();
                R_LED_OFF();
                break;
            case 2:
                B_LED_OFF();
                R_LED_ON();
                break;
            case 3:
                B_LED_ON();
                R_LED_ON();
                break;
        }
    }

    /* TODO <INSERT USER APPLICATION CODE HERE> */

//    EnableAngleControl();
//    EnableSpeedControl();


}
