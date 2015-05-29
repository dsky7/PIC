// USB Controller Device Support Library
//
// Copyright (C) 2012 Toshihiro Nakatani
// modified (C) 2012 Kunihiro Shibuya
// modified (C) 2012 Michio Ono

#include "btstack/btdebug.h"
#if	USE_USB_HID_CONTROLLER

static void elecom_u3412s_process_packet2(unsigned char *hid_report,uint16_t size)
{
	WORD	button_state;
	//digital state
	button_state=0;
	if(hid_report[8]){
		button_state|=OUT_DIGITAL_LEFT;
	}
	if(hid_report[10]){
		button_state|=OUT_DIGITAL_DOWN;
	}
	if(hid_report[7]){
		button_state|=OUT_DIGITAL_RIGHT;
	}
	if(hid_report[9]){
		button_state|=OUT_DIGITAL_UP;
	}
	if(hid_report[1]&0x01){
		button_state|=OUT_DIGITAL_SELECT;
	}
	if(hid_report[1]&0x02){
		button_state|=OUT_DIGITAL_START;
	}
	if(hid_report[1]&0x04){
		button_state|=OUT_DIGITAL_L3;
	}
	if(hid_report[1]&0x08){
		button_state|=OUT_DIGITAL_R3;
	}
	if(hid_report[14]){
		button_state|=OUT_DIGITAL_RECTANGLE;
	}
	if(hid_report[13]){
		button_state|=OUT_DIGITAL_CROSS;
	}
	if(hid_report[12]){
		button_state|=OUT_DIGITAL_CIRCLE;
	}
	if(hid_report[11]){
		button_state|=OUT_DIGITAL_TRIANGLE;
	}
	if(hid_report[16]){
		button_state|=OUT_DIGITAL_R1;
	}
	if(hid_report[15]){
		button_state|=OUT_DIGITAL_L1;
	}
	if(hid_report[18]){
		button_state|=OUT_DIGITAL_R2;
	}
	if(hid_report[17]){
		button_state|=OUT_DIGITAL_L2;
	}
	sixaxis_lx=hid_report[3];
	sixaxis_ly=hid_report[4];
	sixaxis_rx=hid_report[5];
	sixaxis_ry=hid_report[6];
	sixaxis_button_state=button_state;
	return;
}

void dev_elecom_u3412s(void)
{
	log_info( "\r\n ELECOM U3412S device attached\r\n\r\n" );
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
					elecom_u3412s_process_packet2(hid_packet,64);
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
