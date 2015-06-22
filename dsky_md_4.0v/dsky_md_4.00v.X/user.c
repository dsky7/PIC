/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
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

#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */
#define FCY	10000000

	#define		KeepAngleE	100
	#define		KeepAngleA	101
	#define		KeepAngleI	102
	#define		KeepAngleIP	103
	#define		KeepAngleIM	104
	#define		KeepSpeedP	200
        #define         KeepSpeedM      201
        #define         LimitA          202
	#define		STAT_B		1
	#define		STAT_N		2
	#define		STAT_R		3
	#define		Home		255
/*for KeepAngle*/
int			kp,kd,kp2,FLAG_NR;
int 			nRECEIVE,nMODE;
float			ki;
unsigned int    	fGENERAL;
unsigned int            i,j,k,nRESOLUTION;
long			Vel1,Vel2,Acc1,Acceleration,VEL2,VEL3,INTE,INTE_R,INTE_N;
unsigned long           nPOS1CNT,nPOS1CNT_OLD,nTARGET;
unsigned long           nPOSCNT[4];
float			nDUTY1,nDERIVATION;
float 			ANGLE1,ANGLE_SQ;
long			nDIFFERENCE;
long			POS[10];
int			flg_n,flg_r;
int			cnt_u2,U2R_DATA[4];

/*for KeepSpeed*/
float                   LimA;
long                    Pos1,Pos2,Def1,Def2,dDef1;
/*Received Data*/
unsigned char           rcv1,rcv2,rcv3,rcv4;
/*counter*/
unsigned int            cntA,cntB;
/*extern*/
long                    tarVel1;
int                     idR;
float                   speKp,speKi,speKd;
/*flag*/
int             fDsky;
//deflection ??
/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/
void __attribute__((__interrupt__))_SI2C2Interrupt(void){
	unsigned char Temp;	//used for dummy read

	if(I2C2STATbits.I2COV == 1){B_LED_ON();R_LED_ON();while(1);}
	if(I2C2STATbits.D_A == 0){			//address
		Temp = I2C2RCV;
                //if(Temp==20){B_LED_ON();}
		nRECEIVE = 1;
	}else if(I2C2STATbits.D_A == 1){	//data

		switch(nRECEIVE){
			case 1:
				nMODE=I2C2RCV; nRECEIVE=2;
				break;
			case 2:
				rcv1 = I2C2RCV;
				nRECEIVE = 3;

				break;
			case 3:
				rcv2 = I2C2RCV;
//				nRECEIVE = 4;
                                nRECEIVE = 100;
				break;
			case 4:
				rcv3 = I2C2RCV;
				nRECEIVE = 5;
				break;
			case 5:
				rcv4 = I2C2RCV;
				if(nMODE==KeepSpeedP){}
				nRECEIVE = 100;
				break;
		}
		if(nRECEIVE == 100){
			switch (nMODE){
                            case	KeepAngleE:
                                    nTARGET = (long) 105 * rcv1;
                                    nTARGET = nTARGET + 0x40000000;
                                    break;

                            case	KeepAngleA:
                                    //nTARGET = 0X40000000;
                                    nTARGET = rcv1 + (unsigned long)0x100*rcv2 + (unsigned long)0x10000*rcv3 + (unsigned long)0x1000000*rcv4;
                                    break;

                            case	KeepAngleI:
                                    nTARGET = nTARGET + rcv1 + (unsigned int)0x100*rcv2 + (unsigned int)0x10000*rcv3 + (unsigned int)0x1000000*rcv4 - 0x40000000;
                                    break;

                            case	KeepAngleIP:
                                    nTARGET = nTARGET + rcv1 + (unsigned int)0x100*rcv2 + (unsigned int)0x10000*rcv3 + (unsigned int)0x1000000*rcv4 ;
                                    break;

                            case	KeepAngleIM:
                                    nTARGET = nTARGET - rcv1 - (unsigned int)0x100*rcv2 - (unsigned int)0x10000*rcv3 - (unsigned int)0x1000000*rcv4 ;
                                    break;

                            case	KeepSpeedP:
                                    //B_LED_ON();
                                    tarVel1 = rcv1 + 0x100*rcv2;
                                    tarVel1 = 40 * LimA * tarVel1 / 10000;//36
                                    break;

                            case	KeepSpeedM:
                                    //B_LED_ON();
                                    tarVel1 = rcv1 + 0x100*rcv2;
                                    tarVel1 = -40 * LimA * tarVel1 / 10000;//48
                                    break;

                            case        LimitA:
                                    LimA =  rcv1 + 0x100*rcv2;
                                    LimA = LimA / 1000;
                                    if(LimA>0.8){B_LED_ON();}else{B_LED_OFF();}
                                    break;

                            case 	Home:
                                    LED(1,500);

                                    nTARGET = 0x40000000;
                                    POS1CNTL = 0;
                                    POS1CNTH = 0x4000;
                                    LED(1,300);
                                    break;
			}
		}
	}
        cntA = 0;   TMR1 = 0;       //1s TIMER Interrupt clear
        R_LED_OFF();
	IFS3bits.SI2C2IF = 0;
}
void __attribute__((__interrupt__))_T1Interrupt(void){
    IFS0bits.T1IF = 0;
    cntA++;
    if(cntA > 500){        //cntA == 1000 ;1s
        cntA = 0;
        R_LED_ON();
        if(tarVel1<10 && tarVel1>-10){tarVel1=0;}else{
            
            if(tarVel1>0){
                tarVel1 = tarVel1 - 10;
            }else{
                tarVel1 = tarVel1 + 10;
            }
        }
        if(fDsky == 1){fDsky = 0;}else{fDsky = 1;}
    }
}
void __attribute__((__interrupt__))_T3Interrupt(void){
    cntA++;
    if(cntA > 1000){        //cntA == 1000 ;1s
        cntA = 0;
        if(fDsky == 1){fDsky = 0;}else{fDsky = 1;}
    }
    IFS0bits.T3IF = 0;
}
void __attribute__((__interrupt__))_T2Interrupt(void){
    cntB++;
    if(cntB > 100){        //cntA == 1000 ;1s
        cntB = 0;

	Pos1 = POS1CNTL ; //0x10000*POS1CNTH		//convert 32bit
	Vel1 = Pos1 - Pos2;
        Pos2 = Pos1;

        if(Vel1<-100){ Vel1 = Vel1 + 0x10000;}
        if(Vel1<-100){R_LED_ON();}
        if(Vel1>100){ Vel1 = Vel1 - 0x10000;}
        if(Vel1>100){R_LED_ON();}
//        if(Vel1<tarVel1){
//            B_LED_ON();
//        }else{
//            B_LED_OFF();
//        }
//        if(Vel1 > 41){R_LED_ON();}else{R_LED_OFF();}
//        if(Vel1 > 40){B_LED_ON();}else{B_LED_OFF();}
        Def1 = tarVel1 - Vel1;
        dDef1 = Def1 - Def2;
        Def2 = Def1;
//        hhh = hhh + Def1;
        nDUTY1 = nDUTY1 + (speKp*Def1) - (speKd*dDef1);

        if(nDUTY1>100){nDUTY1=100;}
        if(nDUTY1<-100){nDUTY1=-100;}

        if(nDUTY1>0){ROTATE_N(nDUTY1);}else{ROTATE_R(-1*nDUTY1);}
    }
	IFS0bits.T2IF = 0;
}
void InitT1(){
/*T1 Timer*/
    PR1 = 10000;				//0.1ms interrupt PR1 = 2000
    IPC0bits.T1IP = 6;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
}
void InitT3(){
    T2CONbits.T32 = 0;//1
    PR3 = 10000;	//305
    IPC2bits.T3IP = 4;
    IFS0bits.T3IF = 0;
    IEC0bits.T3IE = 1;
    T2CONbits.TON = 0;//1
}
void InitT2T3(){
/*T2 AND T3 32bits Timer*/
    T2CONbits.T32 = 1;//1
    PR3 = 7;	//305
    PR2 = 0;
    IPC2bits.T3IP = 4;
    IFS0bits.T3IF = 0;
    IEC0bits.T3IE = 1;
    T2CONbits.TON = 0;//1
}
void InitT2(){
/*T2 16bits Timer*/
    T2CONbits.T32 = 0;
    PR2 = 10000;
    IPC1bits.T2IP = 5;
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1;
    T2CONbits.TON = 0;//1
}
void EnableSpeedControl(){
    T2CONbits.TON = 1;
}
void EnableAngleControl(){
    T2CONbits.TON = 0;
    T1CONbits.TON = 1;
}
void InitQEI(){
/*QEI*/
	QEI1IOCbits.FLTREN = 0;		//filter
	QEI1IOCbits.QFDIV = 0B111;

	nPOSCNT[2] = nPOSCNT[1] = nPOSCNT[0] = 0x40000000;
	nPOS1CNT_OLD = 0x40000000;
	ANGLE1 = 0;
	nTARGET = ANGLE1*nRESOLUTION;
	nTARGET = nTARGET + 0x40000000;
	kp=80;		//50
	ki=0.05;//0.05;
	kd=0.5;//9

        /*qei*/
	RPINR14bits.QEB1R = 42;
	RPINR14bits.QEA1R = 41;
	QEI1IOCbits.SWPAB = 1;

	QEI1CONbits.PIMOD = 6;//5

	QEI1CONbits.QEIEN = 1;

	QEI1LECL = 0;
	QEI1GECH = 0xFFFF;

	QEI1ICH = 0xFFFF;
}
void delay_us(unsigned int N){
    __delay32(FCY/1000000*N);
}
void delay_ms(unsigned int N){
    __delay32(FCY/1000*N);
}
void R_LED_ON(){
	LATBbits.LATB4=1;
}
void R_LED_OFF(){
	LATBbits.LATB4=0;
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
		LATBbits.LATB13 = 0;		//!ML_Nch
		IOCON2bits.PENL = 0;		//GPIO Controls PWM pin
		delay_us(5);
		IOCON2bits.PENH = 0;		//GPIO Controls PWM pin
		LATBbits.LATB12 = 1;		//!ML_Pch
		delay_us(5);

		LATBbits.LATB13 = 1;		//!ML_Nch

		IOCON1bits.PENH = 1;		//PWM Controls PWM pin
		IOCON1bits.PENL = 1;		//PWM Controls PWM pin
	}
	if(duty>100*LimA){duty=100*LimA;}

//	if(duty>100*LimA){duty=100*LimA;B_LED_ON();}else{B_LED_OFF();}

	PDC1 = duty*10;
        PDC2 = 0;
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
	if(duty>100*LimA){duty=100*LimA;}
//	if(duty>100*LimA){duty=100*LimA;B_LED_ON();}else{B_LED_OFF();}
	PDC2 = duty*10;
        PDC1 = 0;
}
void STOP(){
	LATBbits.LATB15 = 0;		//MR_Nch
	LATBbits.LATB13 = 0;		//!ML_Nch
	IOCON1bits.PENL = 0;		//GPIO Controls PWM pin
	IOCON2bits.PENL = 0;		//GPIO Controls PWM pin
	delay_us(5);
	LATBbits.LATB14 = 1;		//MR_Pch
	LATBbits.LATB12 = 1;		//!ML_Pch
	IOCON2bits.PENH = 0;		//GPIO Controls PWM pin
	IOCON1bits.PENH = 0;		//GPIO Controls PWM pin
}
void BRAKE(){
	LATBbits.LATB14 = 1;		//MR_Pch
	LATBbits.LATB12 = 1;		//ML_Pch
	IOCON2bits.PENH = 0;		//GPIO Controls PWM pin
	IOCON1bits.PENH = 0;		//GPIO Controls PWM pin
	delay_us(5);
	LATBbits.LATB15 = 1;		//MR_Nch
	LATBbits.LATB13 = 1;		//ML_Nch
	IOCON1bits.PENL = 0;		//GPIO Controls PWM pin
	IOCON2bits.PENL = 0;		//GPIO Controls PWM pin
}
void InitI2C(){
    /*I2C*/
	I2C2CONbits.GCEN  = 1;
	I2C2CONbits.I2CEN = 1;//**************************************************

	IPC12bits.SI2C2IP = 6;
	IEC3bits.SI2C2IE = 1;	//1
}
void InitPWM(){
/*PWM*/
/*Set Fault input is disabled*/
    FCLCON1bits.FLTMOD = 3;
    FCLCON2bits.FLTMOD = 3;

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
	IOCON1bits.POLH = 1;        //!
	IOCON1bits.POLL = 0;

	IOCON2bits.SWAP = 0;        //not swap
	IOCON2bits.POLH = 1;
	IOCON2bits.POLL = 0;

/* Enable PWM Module */
	PTCONbits.PTEN = 1;

/* P1 MR  	P2 ML */
	PDC1 = 0;
	PDC2 = 0;

	IOCON3bits.PENH = 0;		//GPIO Controls PWM pin
	IOCON3bits.PENL = 0;		//GPIO Controls PWM pin
}
void BLINK(int rgb, int time, int n){
    for(i=0;i<n;i++){
        LED(rgb,time);
        delay_ms(time);
    }
}
void MakeAdd(){
        idR = 2*PORTBbits.RB7 + PORTBbits.RB8;          //R18=RB07   R17=RB08

        switch(idR){
            case 0:
                BLINK(1,100,2);
          	I2C2ADD = 20;
                break;
            case 1:
                BLINK(3,100,2);
               	I2C2ADD = 21;
                break;
            case 2:
                BLINK(1,100,1);
                BLINK(3,100,1);
                I2C2ADD = 22;
                break;
            case 3:
                BLINK(3,100,1);
                BLINK(1,100,1);
                I2C2ADD = 23;
                break;
        }
}
/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /*PORT*/
	TRISA = 0x0000;
	TRISB = 0x0F80;
	LATA = 0;
	LATB = 0;
        CNPUBbits.CNPUB7 = 1;
        CNPUBbits.CNPUB8 = 1;
        
    /* Setup analog functionality and port direction */
        ANSELA = 0;
	ANSELB = 0;

    /* Initialize peripherals */
        InitQEI();
        InitPWM();
        InitI2C();
        MakeAdd();
        InitT2();
        InitT1();
        POS1CNTH = 0x4000;		//32bit mode
        fDsky = 1;
	nRESOLUTION = 26880;		//4*64*105
        nTARGET = 0x40000000;
        LimA = 1;                    //limit alfa
}
