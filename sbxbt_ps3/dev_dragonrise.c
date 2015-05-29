// USB Controller Device Support Library
//
// Copyright (C) 2012 Toshihiro Nakatani
// modified (C) 2012 Kunihiro Shibuya
// modified (C) 2012 Michio Ono

#include "btstack/btdebug.h"
#if	USE_USB_HID_CONTROLLER

//add @micutil
//for Generic USB Joystick DragonRise Inc.
static void dragonrise_process_packet(unsigned char *hid_report,uint16_t size)
{
	WORD	button_state;
	//digital state
	button_state=0;

/*	int n=0;
	if(hid_report[n]){
		button_state|=hid_report[n];
	}
*/
	//Analog off
/*	if(hid_report[0]==0x00){
		button_state|=OUT_DIGITAL_LEFT;
	}
	if(hid_report[0]==0xFF){
		button_state|=OUT_DIGITAL_RIGHT;
	}
	if(hid_report[1]==0x00) {
		button_state|=OUT_DIGITAL_UP;
	}
	if(hid_report[1]==0xFF){
		button_state|=OUT_DIGITAL_DOWN;
	}
*/	//Analog on
	if(hid_report[13]==0x00) {
		button_state|=OUT_DIGITAL_UP;
	} else if(hid_report[13]==0x01) {
		button_state|=OUT_DIGITAL_UP;
		button_state|=OUT_DIGITAL_RIGHT;
	} else if(hid_report[13]==0x02){
		button_state|=OUT_DIGITAL_RIGHT;
	} else if(hid_report[13]==0x03){
		button_state|=OUT_DIGITAL_RIGHT;
		button_state|=OUT_DIGITAL_DOWN;
	} else if(hid_report[13]==0x04){
		button_state|=OUT_DIGITAL_DOWN;
	} else if(hid_report[13]==0x05){
		button_state|=OUT_DIGITAL_DOWN;
		button_state|=OUT_DIGITAL_LEFT;
	} else if(hid_report[13]==0x06){
		button_state|=OUT_DIGITAL_LEFT;
	} else if(hid_report[13]==0x07){
		button_state|=OUT_DIGITAL_LEFT;
		button_state|=OUT_DIGITAL_UP;
	}

	if(hid_report[6]&0x10){
		button_state|=OUT_DIGITAL_SELECT;//OUT_DIGITAL_L3;
	}
	if(hid_report[6]&0x20){
		button_state|=OUT_DIGITAL_START;//OUT_DIGITAL_R3;
	}
/*	if(hid_report[6]&0x40){
		//button_state|=OUT_DIGITAL_L4;
	}
	if(hid_report[6]&0x80){
		//button_state|=OUT_DIGITAL_R4;
	}
*/	if(hid_report[5]&0x80){
		button_state|=OUT_DIGITAL_RECTANGLE;
	}
	if(hid_report[5]&0x40){
		button_state|=OUT_DIGITAL_CROSS;
	}
	if(hid_report[5]&0x20){
		button_state|=OUT_DIGITAL_CIRCLE;
	}
	if(hid_report[5]&0x10){
		button_state|=OUT_DIGITAL_TRIANGLE;
	}
	if(hid_report[6]&0x08){
		button_state|=OUT_DIGITAL_R1;//
	}
	if(hid_report[6]&0x04){
		button_state|=OUT_DIGITAL_L1;//
	}
	if(hid_report[6]&0x02){
		button_state|=OUT_DIGITAL_R2;//
	}
	if(hid_report[6]&0x01){
		button_state|=OUT_DIGITAL_L2;//
	}
	sixaxis_lx=hid_report[8];
	sixaxis_ly=hid_report[9];
	sixaxis_rx=hid_report[3];
	sixaxis_ry=hid_report[4];
	sixaxis_button_state=button_state;
	return;
}

void dev_dragonrise(void)
{
	log_info( "\r\n Generic USB Joystick DragonRise Inc. attached\r\n\r\n" );
	GENERAL_CONTROLLER_STATE state = CONTROLLER_INITIALIZE;
	while(deviceAddress){
		unsigned char hid_packet[64];
		switch(state){
			case CONTROLLER_INITIALIZE:
     					if (!USBHostBluetoothRxEventIsBusy(deviceAddress)){
					state = CONTROLLER_STATE_GET_DATA;
				}
				break;
			case CONTROLLER_STATE_GET_DATA:
				if(USBHostBluetoothReadEvent(deviceAddress,hid_packet,64) == USB_SUCCESS){
					state = CONTROLLER_STATE_GET_DATA_WAIT;
				}	
				break;
			case CONTROLLER_STATE_GET_DATA_WAIT:
				if (!USBHostBluetoothRxEventIsBusy(deviceAddress)){
					state = CONTROLLER_STATE_GET_DATA;
#if	0
					int i;
					for(i = 0;i < 26;i++){
						log_info("%2x",hid_packet[i]);
					}
					log_info( "GET DATA\r\n" );
#endif
					dragonrise_process_packet(hid_packet,64);
					out_button_state();
				}
				break;
			case CONTROLLER_STATE_ERROR:
				break;
		}
		USBHostTasks();
	}
}
#endif
