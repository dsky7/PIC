// USB Controller Device Support Library
//
// Copyright (C) 2012 Toshihiro Nakatani
// modified (C) 2012 Kunihiro Shibuya
// modified (C) 2012 Michio Ono

#include "btstack/btdebug.h"
#if	USE_USB_HID_CONTROLLER

//add @micutil
//for F510 Wireless GamePad Buffalo Inc.
static void f510_process_packet(unsigned char *hid_report,uint16_t size)
{
	WORD	button_state=0;
	//digital state

	if(hid_report[0]==0x00){
		button_state|=OUT_DIGITAL_LEFT;
	}
	if(hid_report[0]==0xFF){
		button_state|=OUT_DIGITAL_RIGHT;
	}
	if(hid_report[1]==0x00){
		button_state|=OUT_DIGITAL_UP;
	}
	if(hid_report[1]==0xFF){
		button_state|=OUT_DIGITAL_DOWN;
	}
	
	if(hid_report[4]&0x10){
		button_state|=OUT_DIGITAL_RECTANGLE;
	}
	if(hid_report[4]&0x20){
		button_state|=OUT_DIGITAL_CROSS;
	}
	if(hid_report[4]&0x40){
		button_state|=OUT_DIGITAL_CIRCLE;
	}
	if(hid_report[4]&0x80){
		button_state|=OUT_DIGITAL_TRIANGLE;
	}

	if(hid_report[5]&0x10){
		button_state|=OUT_DIGITAL_SELECT;
	}
	if(hid_report[5]&0x20){
		button_state|=OUT_DIGITAL_START;
	}
	if(hid_report[5]&0x02){
		button_state|=OUT_DIGITAL_R1;
	}
	if(hid_report[5]&0x01){
		button_state|=OUT_DIGITAL_L1;
	}
	if(hid_report[5]&0x08){
		button_state|=OUT_DIGITAL_R2;
	}
	if(hid_report[5]&0x04){
		button_state|=OUT_DIGITAL_L2;
	}
	
	sixaxis_lx=sixaxis_ly=0x80;
	unsigned char lxy=(hid_report[4]&0x0F);
	if(lxy==0x06){
		sixaxis_lx=0x00;
	} else if(lxy==0x02){
		sixaxis_lx=0xFF;
	} else if(lxy==0x04){
		sixaxis_ly=0xFF;
	} else if(lxy==0x00){
		sixaxis_ly=0x00;
	}

	sixaxis_rx=hid_report[2];
	sixaxis_ry=hid_report[3];
	sixaxis_button_state=button_state;
	return;
}

void dev_logicool_f510(void)
{
	log_info( "\r\n Logicool F510 Rumble Gamepad attached\r\n\r\n" );
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
						log_info("%02x ",hid_packet[i]);
					}
					log_info( "GET DATA\r\n" );
#endif
					f510_process_packet(hid_packet,64);
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
