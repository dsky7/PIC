/***********PIN ASSIGN*********************************/
	VPP				for program
	VDD				5v-3.3v
	GND				gnd
	PGD				for program		&	for i2c data
	PGC				for program		&	for i2c clock
	TX				for uart
	RX				for uart
	3.3V			3.3v

/***********I2C Protocol*********************************/
[mode]
	KeepAngleE	100
	KeepAngleA	101
	KeepAngleI	102

[KeepEasyMode]
	address
	mode
	data1
	data2
	data3
	data4

	*data2=data3=data4=0


[KeepAbsoluteMode]
	address
	mode
	data1
	data2
	data3
	data4


[KeepRelativeMode]
	address	
	mode
	data1
	data2
	data3
	data4

/**********Command***************************************/
delay_ms(int);
void R_LED_ON(void);
void R_LED_OFF(void);
void B_LED_ON(void);
void B_LED_OFF(void);

void LED(int rgb,int time);
	rgb=0	rgb ON
	rgb=1	r	ON
	rgb=2	g	ON
	rgb=3	b	ON
	*this bord doesn't have green LED

void ROTATE_N(float);
void ROTATE_R(float);