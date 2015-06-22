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

extern long                 tarVel1;
extern int                  idR;
extern float                speKp,speKi,speKd;
extern int                  fDsky;
extern unsigned int            cntA;
/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int16_t main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();
    speKp = 1.00;
    speKi = 1.00;
    speKd = 1.00;           //0-1.5
   
//    BLINK(0,100,4);

    T1CONbits.TON = 1;      //Bluetooth detect
    T2CONbits.TON = 1;      //keep speed
//    T3CONbits.TON = 1;

    while(1){delay_ms(1000);}
/******************************************/


/******************************************/
}
