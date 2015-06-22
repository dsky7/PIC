	#include <p33ep32mc202.h>
	#include <libpic30.h>
	#include <i2c.h>

void delay_us(unsigned int);
void delay_ms(unsigned int);

void R_LED_ON(void);
void R_LED_OFF(void);
void B_LED_ON(void);
void B_LED_OFF(void);
void KEEP_ANGLE_PD(float);
void LED(int,int);

void ROTATE_N(float);
void ROTATE_R(float);
void init_pic(void);