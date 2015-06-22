	#include "sub.h"
	#include <i2c.h>

	#define FCY	20000000
	#define deadtime  10

_FGS(GWRP_OFF & GCP_OFF);
_FOSCSEL(FNOSC_FRCPLL & PWMLOCK_OFF & IESO_ON);
_FOSC(POSCMD_NONE & OSCIOFNC_OFF & IOL1WAY_ON & FCKSM_CSDCMD);
_FPOR(ALTI2C2_ON);
_FWDT(FWDTEN_OFF);
_FICD(ICS_PGD2 & JTAGEN_OFF);

extern int		kp,kd,di;
extern unsigned long		nPOS1CNT;
unsigned int	nDIFF[10];
extern float		nDUTY1,nDERIVATION;
extern long			nTARGET,nDIFFERENCE;
extern unsigned int i,j,k,nRESOLUTION;

void delay_us(unsigned int N)
{
    __delay32(FCY/1000000*N);
}
void delay_ms(unsigned int N)
{
    __delay32(FCY/1000*N);
}

void R_LED_ON(){
	LATBbits.LATB0=1;
}
void R_LED_OFF(){
	LATBbits.LATB0=0;
}
void B_LED_ON(){
	LATAbits.LATA0=1;
}
void B_LED_OFF(){
	LATAbits.LATA0=0;
}

void LED(int rgb, int time){
	switch(rgb){
		case 0:
			R_LED_ON();
			B_LED_ON();
			delay_ms(time);
			R_LED_OFF();
			B_LED_OFF();
			break;
		case 1:
			R_LED_ON();
			delay_ms(time);
			R_LED_OFF();
			break;
		case 2:

			break;
		case 3:
			B_LED_ON();
			delay_ms(time);
			B_LED_OFF();
			break;
	}
}

void ROTATE_N(float duty){
/*RIGHT PWM*/
	if(LATBbits.LATB12==1 && LATBbits.LATB13==1 && IOCON2bits.PENL==0 && IOCON2bits.PENH==0 && IOCON1bits.PENH==1 && IOCON1bits.PENL==1){delay_us(10);}
	else{	
		LATBbits.LATB12 = 0;		//ML_Nch
		IOCON2bits.PENL = 0;		//GPIO Controls PWM pin
		delay_us(5);
		IOCON2bits.PENH = 0;		//GPIO Controls PWM pin
		LATBbits.LATB13 = 1;		//ML_Pch
		delay_us(5);
	
		LATBbits.LATB12 = 1;		//ML_Nch

		IOCON1bits.PENH = 1;		//PWM Controls PWM pin
		IOCON1bits.PENL = 1;		//PWM Controls PWM pin
	}	
	if(duty>100){duty=100;}
	PDC1 = (int)10*duty;
}

void ROTATE_R(float duty){
/*LEFT PWM*/
	if(LATBbits.LATB14==1 && LATBbits.LATB15==1 && IOCON1bits.PENL==0 && IOCON1bits.PENH==0 && IOCON2bits.PENH==1 && IOCON2bits.PENL==1){delay_us(10);}
	else{
		LATBbits.LATB15 = 0;		//MR_Nch
		IOCON1bits.PENL = 0;		//GPIO Controls PWM pin
		delay_us(5);
		IOCON1bits.PENH = 0;		//GPIO Controls PWM pin
		LATBbits.LATB14 = 1;		//MR_Pch
		delay_us(5);
	
		LATBbits.LATB15 = 1;		//MR_Nch
	
		IOCON2bits.PENH = 1;		//PWM Controls PWM pin
		IOCON2bits.PENL = 1;		//PWM Controls PWM pin
	}
	if(duty>100){duty=100;}
	PDC2 = (int)10*duty;
}

void STOP(){
	LATBbits.LATB15 = 0;		//MR_Nch
	LATBbits.LATB12 = 0;		//ML_Nch
	IOCON1bits.PENL = 0;		//GPIO Controls PWM pin
	IOCON2bits.PENL = 0;		//GPIO Controls PWM pin
	delay_us(5);
	LATBbits.LATB14 = 1;		//MR_Pch
	LATBbits.LATB13 = 1;		//ML_Pch
	IOCON2bits.PENH = 0;		//GPIO Controls PWM pin
	IOCON1bits.PENH = 0;		//GPIO Controls PWM pin	
}

void BRAKE(){
	LATBbits.LATB14 = 1;		//MR_Pch
	LATBbits.LATB13 = 1;		//ML_Pch
	IOCON2bits.PENH = 0;		//GPIO Controls PWM pin
	IOCON1bits.PENH = 0;		//GPIO Controls PWM pin	
	delay_us(5);
	LATBbits.LATB15 = 1;		//MR_Nch
	LATBbits.LATB12 = 1;		//ML_Nch
	IOCON1bits.PENL = 0;		//GPIO Controls PWM pin
	IOCON2bits.PENL = 0;		//GPIO Controls PWM pin
}

void init_pic(){
/*FRC PLL FCY=20MHz*/
	PLLFBD = 63;  			//M=63
	CLKDIVbits.PLLPOST = 1;  //N2=4
	CLKDIVbits.PLLPRE = 1;  //N1=3

/*PORT*/
	TRISA = 0x0000;
	TRISB = 0x0E00;
	TRISBbits.TRISB11 = 0;
	LATA = 0;
	LATB = 0;
	ANSELA = 0;
	ANSELB = 0;

/*PWM*/

/*Set PWM Period on Primary Time Base*/
	PTPER = 1000;

/* Set Dead Time Values */
	DTR1 = DTR2 = DTR3 = 50;  //25
	ALTDTR1 = ALTDTR2 = ALTDTR3 = 50;  //25

/* Set Primary Time Base, Edge-Aligned Mode and Independent Duty Cycles */
	PWMCON1 = PWMCON2 = PWMCON3 = 0x0000;

/* 1:1 Prescaler */
	PTCON2 = 0x0000;

/*Set polarity*/
	IOCON1bits.POLH = 1;
	IOCON1bits.POLL = 0;

	IOCON2bits.SWAP = 1;
	IOCON2bits.POLH = 0;
	IOCON2bits.POLL = 1;

/* Enable PWM Module */
	PTCONbits.PTEN = 1;

/* P1 MR  	P2 ML */
	PDC1 = 0;
	PDC2 = 0;	
/*pmd*/
//	PMD1bits.I2C1MD = 1;
/*	PMD1bits.T5MD = 1;
	PMD1bits.T4MD = 1;

	PMD1bits.U2MD = 1;
	PMD1bits.U1MD = 0;
	PMD1bits.SPI2MD = 1;
	PMD1bits.SPI1MD = 1;
	PMD1bits.I2C1MD = 1;
	PMD1bits.AD1MD = 1;
	PMD3bits.CMPMD = 1;
	PMD3bits.CRCMD = 1;
	PMD6bits.PWM3MD = 1;
	PMD2 = 0xFFFF;
	PMD4 = 0xFFFF;
	PMD7 = 0xFFFF;
*/

	IOCON3bits.PENH = 0;		//GPIO Controls PWM pin
	IOCON3bits.PENL = 0;		//GPIO Controls PWM pin

	/*I2C*/
	
	I2C2CONbits.GCEN  = 1;
	I2C2CONbits.I2CEN = 1;//**************************************************

	IPC12bits.SI2C2IP = 6;
	IEC3bits.SI2C2IE = 1;	//1

	/*qei*/
	RPINR14bits.QEB1R = 42;
	RPINR14bits.QEA1R = 41;
	QEI1IOCbits.SWPAB = 1;

	QEI1CONbits.PIMOD = 6;//5

	QEI1CONbits.QEIEN = 1;

	QEI1LECL = 0;
	QEI1GECH = 0xFFFF;

	QEI1ICH = 0xFFFF;

//	QEI1STATbits.PCHEQIEN = 1;
//	QEI1STATbits.PCLEQIEN = 1;
/*
	IFS3bits.QEI1IF = 0;
	IPC14bits.QEI1IP = 3;
	IEC3bits.QEI1IE = 1;
*/

//	POS1CNTL = 32768;

	POS1CNTH = 0x4000;		//32bit mode

	nRESOLUTION = 26880;		//4*64*105

	SPI1CON1bits.DISSDO = 1;
	SPI1CON1bits.DISSCK = 1;

	if(RCONbits.TRAPR == 1){R_LED_ON();while(1);}
	if(RCONbits.IOPUWR == 1){while(1){LED(1,200);delay_ms(200);}}
	if(RCONbits.CM == 1){R_LED_ON();while(1);}
	if(RCONbits.EXTR == 1){LED(3,200);}
	if(RCONbits.SWR == 1){R_LED_ON();while(1);}
	if(RCONbits.WDTO == 1){R_LED_ON();while(1);}

	if(RCONbits.SLEEP == 1){R_LED_ON();while(1);}

	if(RCONbits.IDLE == 1){R_LED_ON();while(1);}

	if(RCONbits.BOR == 1){R_LED_ON();delay_ms(200);}
	if(RCONbits.POR == 1){R_LED_ON();B_LED_ON();delay_ms(200);}

}
