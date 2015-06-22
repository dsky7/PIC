/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

void InitApp(void);         /* I/O and Peripheral Initialization */
void ROTATE_N(float duty);
void ROTATE_R(float duty);
void LED(int rgb, int time);
void delay_ms(unsigned int N);
void R_LED_ON();
void R_LED_OFF();
void B_LED_ON();
void B_LED_OFF();
