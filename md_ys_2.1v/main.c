	#include <p33ep32mc202.h>
	#include <i2c.h>
	#include <libpic30.h>
	#include "sub.h"
	#include <stdio.h>

	#define		KeepAngleE	100
	#define		KeepAngleA	101
	#define		KeepAngleI	102
	#define		KeepAngleIP	103
	#define		KeepAngleIM	104
	#define		KeepSpeed	200
	#define		STAT_B		1
	#define		STAT_N		2
	#define		STAT_R		3
	#define		Home		255

char			RX2;
char 			ds1;
int				kp,kd,kp2,FLAG_NR;
float			ki;
int 			POS1,nRECEIVE,nMODE;
unsigned char	rcv1,rcv2,rcv3,rcv4;
float 			ANGLE1,ANGLE_SQ;
unsigned int	ds,fGENERAL;
long			VEL1,Acceleration,VEL2,VEL3,INTE,INTE_R,INTE_N;

unsigned long	nPOS1CNT,nPOS1CNT_OLD,nTARGET;
unsigned long	nPOSCNT[4];
float			nDUTY1,nDERIVATION;
long			nDIFFERENCE;
unsigned int	i,j,k,nRESOLUTION;
long			POS[10];
int				flg_n,flg_r;
int				cnt_u2,U2R_DATA[4],DSKY,DSKY2;

void init_uart(void);
void init_uart2(void);
void init_qei(void);
void init_T1(void);
void init_T2T3(void);

void __attribute__((__interrupt__)) _U1TXInterrupt(void)
{
	IFS0bits.U1TXIF = 0; // Clear TX Interrupt flag
}

void __attribute__((__interrupt__)) _U1RXInterrupt(void)
{
	B_LED_ON();R_LED_ON();
	if(U1RXREG == 0){}
	else if(U1RXREG == 'a'){R_LED_ON();}

	IFS0bits.U1RXIF = 0; // Clear RX Interrupt flag
	delay_ms(3000);
	B_LED_OFF();
	R_LED_OFF();		//tx-yellow	rx-orange
}

void __attribute__((__interrupt__)) _U2ErrInterrupt(void)
{	IFS4bits.U2EIF = 0;
	U2TXREG = 'E';
}

void __attribute__((__interrupt__)) _U2RXInterrupt(void)
{
	while(U2STAbits.URXDA){
		RX2 = U2RXREG;

		U2R_DATA[1]=U2R_DATA[0];
		U2R_DATA[0]=RX2;

		if(U2R_DATA[1]==108){U2TXREG=U2R_DATA[0];DSKY=U2R_DATA[0];nTARGET = (long)2150.4*U2R_DATA[0] + 2147483648;}
	//	if(U2R_DATA[1]==114){U2TXREG=U2R_DATA[0];DSKY=U2R_DATA[0];}
	}
	IFS1bits.U2RXIF = 0; // Clear RX Interrupt flag
}

void __attribute__((__interrupt__))_SI2C2Interrupt(void){
	unsigned char Temp;	//used for dummy read

	if(I2C2STATbits.I2COV == 1){B_LED_ON();R_LED_ON();while(1);}
	if(I2C2STATbits.D_A == 0){			//address
		Temp = I2C2RCV;	
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
				rcv2 = (unsigned char)I2C2RCV;
				if(rcv2==0xFF){R_LED_ON();}
				nRECEIVE = 4;
				break;
			case 4:
				rcv3 = I2C2RCV;
				nRECEIVE = 5;
				break;
			case 5:
				rcv4 = I2C2RCV;
				if(nMODE==KeepSpeed){}
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


				case	KeepSpeed:
					LED(1,200);delay_ms(200);LED(1,200);delay_ms(200);
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
	IFS3bits.SI2C2IF = 0;
}

void __attribute__((__interrupt__))_T3Interrupt(void){
	rcv2 = rcv2 + 35;
	//rcv1 = rcv1 +32;
	//nTARGET = (long) rcv1 * 105;		//64*105*4/128=210
	//nTARGET = nTARGET + 2147483648;
	nTARGET = nTARGET + rcv1 + 0x100*rcv2 + 0x10000*rcv3 + 0x1000000*rcv4 - 2147483648;
	IFS0bits.T3IF = 0;
}

void __attribute__((__interrupt__))_T1Interrupt(void){
	IFS0bits.T1IF = 0;
	TMR1 = 0;

	nPOS1CNT = POS1CNTL + 0x10000*POS1CNTH;		//convert 32bit

//	nPOS1CNT = nPOS1CNT/4 + 0x30000000;

	VEL1 =  nPOS1CNT - nPOS1CNT_OLD;
	nPOS1CNT_OLD = nPOS1CNT;
	VEL3 = VEL2;	
	VEL2 = VEL1;
//		Acceleration = (long long)nPOSCNT[0] - 2*(long long)nPOSCNT[1] + (long long)nPOSCNT[2];
//		Acceleration = VEL1-VEL3;

//		printf("%4x\n",POS1CNTL);
//		printf("%04x %04x \n",POS1CNTH,POS1CNTL);

		nDIFFERENCE = nTARGET - nPOS1CNT;

//		Acceleration = (long long)nPOSCNT[0] - 2*(long long)nPOSCNT[1] + (long long)nPOSCNT[2];
//		Acceleration = VEL1-VEL3;

		if(-1<nDIFFERENCE && nDIFFERENCE<1){
			//BRAKE();
			//B_LED_OFF();R_LED_OFF();
			FLAG_NR = STAT_B;
		//	INTE = 0;
		}else{
			nDUTY1 = 100*( (float)kp*nDIFFERENCE/nRESOLUTION ); //+ kd*nDERIVATION)
			if(nDUTY1>=100){nDUTY1=100;}else if(nDUTY1<=-100){nDUTY1=-100;}
			nDUTY1 = nDUTY1 - kd*VEL1;// nDUTY1 - kd*VEL1 ;
			//if(SRbits.OV==1){R_LED_ON();while(1);}
			if(nDIFFERENCE<0){
				//R_LED_ON();B_LED_OFF();
				if(FLAG_NR == STAT_R){INTE_R = INTE_R + 1;}
				else{INTE_R = 0;}
				nDUTY1 = nDUTY1 - ki*INTE_R;
				//ROTATE_R(-1*nDUTY1 + ki*INTE_R );
				FLAG_NR = STAT_R;
			}else{
				//R_LED_OFF();B_LED_ON();
				if(FLAG_NR == STAT_N){INTE_N = INTE_N + 1;}
				else{INTE_N = 0;}
				nDUTY1 = nDUTY1 + ki*INTE_N;
				//ROTATE_N(nDUTY1 + ki*INTE_N );
				FLAG_NR = STAT_N;
			}
			if(nDUTY1>=100){nDUTY1=100;}else if(nDUTY1<=-100){nDUTY1=-100;}
			if(nDUTY1<0){
				ROTATE_R(-1*nDUTY1);
			}else{
				ROTATE_N(nDUTY1);
			}
		}
}

int main(void){
	I2C2ADD = 11;
	init_pic();
//	init_uart2();
	init_qei();
	init_T1();

	nTARGET = 0x40000000;

//while(1){ROTATE_N(100);}

	T1CONbits.TON = 1;
//nTARGET=nTARGET-15000;
//while(1){LED(3,2000);nTARGET=nTARGET+30000;delay_ms(2000);nTARGET=nTARGET-30000;}
	while(1){LED(3,1000);delay_ms(1000);}

	
}

void init_T1(){
/*T1 Timer*/	
	PR1 = 20000;				//0.1ms interrupt PR1 = 2000
	IPC0bits.T1IP = 2;
	IFS0bits.T1IF = 0;
	IEC0bits.T1IE = 1;
}

void init_T2T3(){
/*T2 AND T3 32bits Timer*/
	T2CONbits.T32 = 0;//1
	PR3 = 61;	//305
	PR2 = 0;
	IPC2bits.T3IP = 4;
	IFS0bits.T3IF = 0;
	IEC0bits.T3IE = 0;
	T2CONbits.TON = 0;//1
}

void init_uart(){
	U1STAbits.URXISEL = 0;
	
	IEC0bits.U1RXIE = 0;
	IPC2bits.U1RXIP = 4;
	U1STAbits.URXDA = 0;
	U1STAbits.OERR = 0;
	U1STAbits.FERR = 0;
	U1STAbits.PERR = 0;

	U1BRG = 129;				//9600
	//	RPOR2bits.RP39R = 1;	//TX RP39 CN6
	//	RPINR18	= 40;			//RX RP40 CN7
	RPOR3bits.RP40R = 1;
	RPINR18	= 0b0100111;
	U1MODEbits.UARTEN = 1;
	U1STAbits.UTXEN = 1;	//TRANSMIT ENABLE

	U1MODEbits.LPBACK = 0;		//loopback
}

void init_uart2(){
	IPC7bits.U2RXIP = 3; //UART2 RX interrupt priority, mid-range
//	IPC7bits.U2TXIP = 4; //UART2 TXinterrupt priority, mid-range
//	IPC16bits.U2EIP = 5; //UART2 Error Priority set higher

	IEC1bits.U2RXIE = 1;
//	IPC2bits.U1RXIP = 6;
	U2STAbits.URXDA = 0;
	U2STAbits.OERR = 0;
	U2STAbits.FERR = 0;
	U2STAbits.PERR = 0;

	U2BRG = 10;				//9600Hz:129  115KHz:10.86-1
	//	RPOR2bits.RP39R = 1;	//TX RP39 CN6
	//	RPINR18	= 40;			//RX RP40 CN7
	TRISBbits.TRISB7 = 1;
	RPOR3bits.RP40R = 3;		//u2tx
	RPINR19	= 0b0100111;		//u2rx
	U2MODEbits.UARTEN = 1;
	U2STAbits.UTXEN = 1;	//TRANSMIT ENABLE

	U2STAbits.URXISEL = 0;		//

	U2MODEbits.LPBACK = 0;		//loopback

	IPC7bits.U2TXIP = 3;
	IFS4bits.U2EIF = 0;
	IEC4bits.U2EIE = 1;
}

void init_qei(){
/*QEI*/
	QEI1IOCbits.FLTREN = 0;		//filter
	QEI1IOCbits.QFDIV = 111;

	nPOSCNT[2] = nPOSCNT[1] = nPOSCNT[0] = 0x40000000;
	nPOS1CNT_OLD = 0x40000000;
	ANGLE1 = 0;
	nTARGET = ANGLE1*nRESOLUTION;
	nTARGET = nTARGET + 0x40000000;
	delay_ms(500);
	LED(0,500);
	kp=80;		//50
	ki=0.05;//0.05;
	kd=0.5;//9
}
