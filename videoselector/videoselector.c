	#include <p33fj32mc304.h>
	#define FCY	10000000

int		mul;
int 	nINPUT;// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)

// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// FOSCSEL
#pragma config FNOSC = PRI              // Oscillator Mode (Primary Oscillator (XT, HS, EC))
#pragma config IESO = ON                // Internal External Switch Over Mode (Start-up device with FRC, then automatically switch to user-selected oscillator source when ready)

// FOSC
#pragma config POSCMD = HS              // Primary Oscillator Source (HS Oscillator Mode)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function (OSC2 pin has clock out function)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow Only One Re-configuration)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-Safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)
#pragma config LPOL = OFF               // Motor Control PWM Low Side Polarity bit (PWM module low side output pins have active-low output polarity)
#pragma config HPOL = OFF               // Motor Control PWM High Side Polarity bit (PWM module high side output pins have active-low output polarity)
#pragma config PWMPIN = OFF             // Motor Control PWM Module Pin Mode bit (PWM module pins controlled by PWM module at device Reset)

// FICD
#pragma config ICS = PGD1               // Comm Channel Select (Communicate on PGC1/EMUC1 and PGD1/EMUD1)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)


void __attribute__((__interrupt__)) _CNInterrupt(void){

    	LED(2,500);
	delay_ms(10);
	IFS1bits.CNIF = 0;
//trans_vs(240);

	nINPUT = (!PORTBbits.RB9)+(2*!PORTBbits.RB12)+(4*!PORTBbits.RB13);

	switch(nINPUT){
		case 0:
			trans_vs(250);
			break;
		case 1:
			trans_vs(240);
			break;
		case 2:
			trans_vs(230);
			break;	
		case 3:
			trans_vs(227);
			break;	
		case 4:
			trans_vs(242);
			break;	
		case 5:
			trans_vs(231);
			break;	
		case 6:
			trans_vs(225);
			break;
		case 7:
			trans_vs(228);
			break;
	}

	LED(1,500);

}

void delay_us(unsigned int N)
{
    __delay32(FCY/1000000*N);
}
void delay_ms(unsigned int N)
{
    __delay32(FCY/1000*N);
}

void R_LED_ON(){
	LATCbits.LATC9=1;	
}
void G_LED_ON(){
	LATCbits.LATC8=1;	
}
void B_LED_ON(){
	LATCbits.LATC3=1;	
}
void R_LED_OFF(){
	LATCbits.LATC9=0;	
}
void G_LED_OFF(){
	LATCbits.LATC8=0;	
}
void B_LED_OFF(){
	LATCbits.LATC3=0;	
}
void ALL_LED_OFF(){
	R_LED_OFF();
	G_LED_OFF();
	B_LED_OFF();
}

void knite_rider(int time1){
	LED(1,time1);
	LED(2,time1);
	LED(3,time1);
}

void init_pic(){
	TRISA = 0;
	TRISB = 0;
	TRISC = 0;

	TRISBbits.TRISB9 = 1;
	TRISBbits.TRISB12 = 1;
	TRISBbits.TRISB13 = 1;

	CNPU1bits.CN13PUE = 1;
	CNPU1bits.CN14PUE = 1;

	CNPU2bits.CN21PUE = 1;
//        CNPU2 = 0XFF;
//        CNPU1 = 0xFF;

	CNEN2bits.CN21IE = 1;   //rb9
	CNEN1bits.CN13IE = 1;   //rb13
	CNEN1bits.CN14IE = 1;   //rb12



	IFS1bits.CNIF = 0;
	IEC1bits.CNIE =1;
	IPC4bits.CNIP = 2;
}
void init_pwm(){
	P1TPER = 262;
	PWM1CON1bits.PMOD1 = 1;
	PWM1CON1bits.PEN1L = 1;
	PWM1CON1bits.PEN2L = 0;
	PWM1CON1bits.PEN2H = 0;
	P1DC1 = 0;
	P1TCONbits.PTEN = 1;
}

void IR_LED_ON(){
	P1DC1 = 262;
}

void IR_LED_OFF(){
	P1DC1 = 0;
}

void reader(){
	IR_LED_ON();
	delay_ms(9);
	IR_LED_OFF();
	delay_ms(4);
	delay_us(500);
}

void repeat(){
	IR_LED_ON();
	delay_ms(9);
	IR_LED_OFF();
	delay_ms(2);
	delay_us(250);
}

void databit1(){
	IR_LED_ON();
	delay_us(560);
	IR_LED_OFF();
	delay_us(560);
}

void databit0(){
	IR_LED_ON();
	delay_us(560);
	IR_LED_OFF();
	delay_ms(1);
	delay_us(690);
}

void trans_8bit(int data_8bit){
	mul = 1;
	int sky_i;
	for(sky_i=0;sky_i<8;sky_i++){
		if( (data_8bit & mul) == 0){databit0();}else{databit1();}
		mul = mul << 1;
	}
}

void stop_bit(){
	IR_LED_ON();
	delay_us(560);
	IR_LED_OFF();
}

void trans_ir(int data){
	reader();
	trans_8bit(255);
	trans_8bit(0);
	trans_8bit(data);
	stop_bit();
}

void trans_vs(int data){
	int inv_data = 255 - data;
	reader();
	trans_8bit(255);
	trans_8bit(0);
	trans_8bit(data);
	trans_8bit(inv_data);
	stop_bit();
}
void test(){
	trans_vs(250);

}

void LED(int color, int delaytime){
	switch(color) {

		case 0:
			R_LED_ON();
			G_LED_ON();
			B_LED_ON();
			delay_ms(delaytime);
			ALL_LED_OFF();
			break;

		case 1:
			R_LED_ON();
			G_LED_OFF();
			B_LED_OFF();
			delay_ms(delaytime);
			ALL_LED_OFF();
			break;

		case 2:
			R_LED_OFF();
			G_LED_ON();
			B_LED_OFF();
			delay_ms(delaytime);
			ALL_LED_OFF();
			break;

		case 3:
			R_LED_OFF();
			G_LED_OFF();
			B_LED_ON();
			delay_ms(delaytime);
			ALL_LED_OFF();
			break;
	}
}

void main(){
	//init_pic();
	init_pwm();
//	knite_rider(300);
//	knite_rider(300);
	TRISA = 0;
	TRISB = 0;
	TRISC = 0;


        	TRISBbits.TRISB9 = 1;
	TRISBbits.TRISB12 = 1;
	TRISBbits.TRISB13 = 1;
        	CNEN2bits.CN21IE = 1;   //rb9
	CNEN1bits.CN13IE = 1;   //rb13
	CNEN1bits.CN14IE = 1;   //rb12



	IFS1bits.CNIF = 0;
	IEC1bits.CNIE =1;
	IPC4bits.CNIP = 2;
	LED(2,200);
	delay_ms(200);
	LED(2,200);
	delay_ms(200);
	LED(2,200);
	delay_ms(200);

//	LED(3,1000);
	//trans_vs(250);


    //   while(1){LATBbits.LATB9=1;LATBbits.LATB12=1;LATBbits.LATB13=1;LED(3,500);LATBbits.LATB9=0;LATBbits.LATB12=0;LATBbits.LATB13=0;delay_ms(1000);}

//while(1){	LATBbits.LATB13=1;	delay_ms(500);LATBbits.LATB13=0;	delay_ms(500);}
        delay_ms(1000);
	while(1){
		LED(3,1000);
		delay_ms(1000);
	}
//while(1){if(!PORTBbits.RB13==0){LED(3,100);}else{LED(2,100);}}
//
//	while(1){
//		nINPUT = (!PORTBbits.RB9)+(2*!PORTBbits.RB12)+(4*!PORTBbits.RB13);
//
//
//	switch(nINPUT){
//		case 0:
//			trans_vs(250);
//			break;
//		case 1:
//			trans_vs(240);
//			break;
//		case 2:
//			trans_vs(230);
//			break;
//		case 3:
//			trans_vs(227);
//			break;
//		case 4:
//			trans_vs(242);
//			break;
//		case 5:
//			trans_vs(231);
//			break;
//		case 6:
//			trans_vs(225);
//			break;
//		case 7:
//			trans_vs(228);
//			break;
//	}
//
//
//
//
//
//		LED(0,500);
//		//			trans_vs(250);
//		delay_ms(500);
//		//			trans_vs(240);
//	}
}
