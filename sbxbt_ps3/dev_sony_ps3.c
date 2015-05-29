// USB Controller Device Support Library
//
// Copyright (C) 2012 Toshihiro Nakatani
// modified (C) 2012 Kunihiro Shibuya
// modified (C) 2012 Michio Ono

#include "btstack/btdebug.h"

const BYTE OUTPUT_REPORT_BUFFER[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x02 /*0x00*/, 	//140201 LED1
    0xff, 0x27, 0x10, 0x00, 0x32, 
    0xff, 0x27, 0x10, 0x00, 0x32, 
    0xff, 0x27, 0x10, 0x00, 0x32, 
    0xff, 0x27, 0x10, 0x00, 0x32, 
    0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
};

static BYTE InitializeSIXAXISController(void)
{
	BYTE data[17];
    BYTE RetVal;
	int j;
	for(j = 0;j < 17;j++){
		data[j] = 0;
	}
	BYTE bmRequestType = 161;
	BYTE bRequest = 1;
	WORD wValue = 0x03f2;
	WORD wIndex = 0;
	WORD wLength = 17;
    if (!API_VALID(deviceAddress)) return USB_INVALID_STATE;
    if (gc_DevData.flags.txBusy)   return USB_BUSY;
	RetVal = USBHostIssueDeviceRequest(deviceAddress,bmRequestType,bRequest,wValue,wIndex,wLength,data,USB_DEVICE_REQUEST_SET,0);
	return RetVal;
}

#if	0
static BYTE SetupSIXAXISController(void)
{
	static BYTE setup_command[] = {0x42, 0x0c, 0x00, 0x00};	//Tells controller to start sending changes on in pipe
    BYTE RetVal;
	BYTE bmRequestType = 0x21;
	BYTE bRequest = 9;
	WORD wValue = 0x03f4;
	WORD wIndex = 0;
	WORD wLength = sizeof(setup_command);

    if (!API_VALID(deviceAddress)) return USB_INVALID_STATE;
    if (gc_DevData.flags.txBusy)   return USB_BUSY;
	RetVal = USBHostIssueDeviceRequest(deviceAddress,bmRequestType,bRequest,wValue,wIndex,wLength,setup_command,USB_DEVICE_REQUEST_SET,0);
	return RetVal;
}
#endif

static BYTE SetLedSIXAXISController(BYTE led)
{
    BYTE RetVal;
	BYTE bmRequestType = 0x21;
	BYTE bRequest = 9;
	WORD wValue = 0x0201;
	WORD wIndex = 0;
	WORD wLength = OUTPUT_REPORT_BUFFER_SIZE;

	memcpy(lineBuffer,OUTPUT_REPORT_BUFFER,OUTPUT_REPORT_BUFFER_SIZE);
	lineBuffer[9] |= (uint8_t)(((uint16_t)led & 0x0f) << 1);    

    if (!API_VALID(deviceAddress)) return USB_INVALID_STATE;
    if (gc_DevData.flags.txBusy)   return USB_BUSY;
	RetVal = USBHostIssueDeviceRequest(deviceAddress,bmRequestType,bRequest,wValue,wIndex,wLength,(BYTE*)lineBuffer,USB_DEVICE_REQUEST_SET,0);
	return RetVal;
}

#if STANDALONE_PAIRING
static BYTE RegisterAddressToSIXAXISController(BYTE address[6]){
    BYTE RetVal;
	static BYTE RegisterAddressData[8];
    RegisterAddressData[0] = 0x01;
    RegisterAddressData[1] = 0x00;
    RegisterAddressData[2] = address[0];
    RegisterAddressData[3] = address[1];
    RegisterAddressData[4] = address[2];
    RegisterAddressData[5] = address[3];
    RegisterAddressData[6] = address[4];
    RegisterAddressData[7] = address[5];

	BYTE bmRequestType = 33;
	BYTE bRequest = 9;
	WORD wValue = 0x03f5;
	WORD wIndex = 0;
	WORD wLength = 8;
    if (!API_VALID(deviceAddress)) return USB_INVALID_STATE;
    if (gc_DevData.flags.txBusy)   return USB_BUSY;
	RetVal = USBHostIssueDeviceRequest(deviceAddress,bmRequestType,bRequest,wValue,wIndex,wLength,RegisterAddressData,USB_DEVICE_REQUEST_SET,0);
	return RetVal;
}

static BYTE ReadAddressFromSIXAXISController(BYTE address[6]){
    BYTE RetVal;
	BYTE bmRequestType = 161;
	BYTE bRequest = 1;
	WORD wValue = 0x03f5;
	WORD wIndex = 0;
	WORD wLength = 8;
	BYTE errorCode;
	DWORD byteCount;
	BYTE temp[8];
	int i;
    if (!API_VALID(deviceAddress)) return USB_INVALID_STATE;
    if (gc_DevData.flags.txBusy)   return USB_BUSY;
	RetVal = USBHostIssueDeviceRequest(deviceAddress,bmRequestType,bRequest,wValue,wIndex,wLength,temp,USB_DEVICE_REQUEST_GET,0);
	if(RetVal != USB_SUCCESS){
		return RetVal;
	}
	while(!(USBHostTransferIsComplete(deviceAddress, 0,&errorCode,&byteCount))){
        USBHostTasks();
	}
	for(i = 0;i < 6;i++){
		address[i] = temp[i+2];
	}
	return USB_SUCCESS;
}
#endif

void sixaxis_process_packet(BYTE *hid_report,WORD size)
{
	WORD	button_state;

	if(hid_report[0]!=0x01 || hid_report[1]!=0x00){
		return;
	}

	//digital state
	button_state=0;
	if(hid_report[2]&0x80){
		button_state|=OUT_DIGITAL_LEFT;
	}
	if(hid_report[2]&0x40){
		button_state|=OUT_DIGITAL_DOWN;
	}
	if(hid_report[2]&0x20){
		button_state|=OUT_DIGITAL_RIGHT;
	}
	if(hid_report[2]&0x10){
		button_state|=OUT_DIGITAL_UP;
	}
	if(hid_report[2]&0x08){
		button_state|=OUT_DIGITAL_START;
	}
	if(hid_report[2]&0x04){
		button_state|=OUT_DIGITAL_R3;
	}
	if(hid_report[2]&0x02){
		button_state|=OUT_DIGITAL_L3;
	}
	if(hid_report[2]&0x01){
		button_state|=OUT_DIGITAL_SELECT;
	}
	if(hid_report[3]&0x80){
		button_state|=OUT_DIGITAL_RECTANGLE;
	}
	if(hid_report[3]&0x40){
		button_state|=OUT_DIGITAL_CROSS;
	}
	if(hid_report[3]&0x20){
		button_state|=OUT_DIGITAL_CIRCLE;
	}
	if(hid_report[3]&0x10){
		button_state|=OUT_DIGITAL_TRIANGLE;
	}
	if(hid_report[3]&0x08){
		button_state|=OUT_DIGITAL_R1;
	}
	if(hid_report[3]&0x04){
		button_state|=OUT_DIGITAL_L1;
	}
	if(hid_report[3]&0x02){
		button_state|=OUT_DIGITAL_R2;
	}
	if(hid_report[3]&0x01){
		button_state|=OUT_DIGITAL_L2;
	}
	if(hid_report[4]&0x01){
		button_state|=OUT_DIGITAL_PS;
	}
	sixaxis_button_state=button_state;

	//analog state
	sixaxis_lx=hid_report[ 6];
	sixaxis_ly=hid_report[ 7];
	sixaxis_rx=hid_report[ 8];
	sixaxis_ry=hid_report[ 9];

	out_button_state();
	return;
}

void dev_sony_ps3(void)
{
	int i;
	BYTE registeredAddressData[6];
	BYTE bluetoothAddress[6];
	int state = 3;
	unsigned char hid_packet[64];

#if STANDALONE_PAIRING
	if(read_local_bluetooth_address(bluetoothAddress)){//check if saved bluetooth address
		state = 0;//do register....
	}
#endif

	while(deviceAddress){
		switch(state){
#if STANDALONE_PAIRING
			case 0:
				if(RegisterAddressToSIXAXISController(bluetoothAddress) == USB_SUCCESS){
					log_info("RegisterAddressToSIXAXISController successfully\n");
					state++;
				}
				break;
			case 1:
					if(ReadAddressFromSIXAXISController(registeredAddressData) == USB_SUCCESS){
						for(i = 0;i < 6;i++){
							if(registeredAddressData[i] != bluetoothAddress[i]){
								state = 0;//error retry
								break;
							}
						}
						if(state != 0){
							state++;//ok 
							log_info("verify successfully\n");
						}
					}
				break;
			case 2://pairing ok
				led1_off();
				led2_on();
				state++;
				break;
#endif
			case 3://get sixaxis bt address
				if(InitializeSIXAXISController()==USB_SUCCESS){
					state++;
				}
				break;
			case 4:
				if (!USBHostBluetoothRxEventIsBusy(deviceAddress)){
					state++;
				}
				break;
			case 5:
				if(USBHostBluetoothReadEvent(deviceAddress,hid_packet,64) == USB_SUCCESS){
					state++;
				}	
				break;
			case 6:
     			if (!USBHostBluetoothRxEventIsBusy(deviceAddress)){
					if(!sixaxis_control_channel_id && hid_packet[0]==0x01){
						if(SetLedSIXAXISController(1)==USB_SUCCESS){
							sixaxis_control_channel_id=1;		//dummy for blink led
						}
					}
					state--;
#if	0
					for(i = 0;i < 26;i++){
						log_info("%02x ",hid_packet[i]);
					}
					log_info( "GET DATA\r\n" );
#endif
					sixaxis_process_packet(hid_packet,64);
					out_button_state();
				}
				break;
			default:
				break;
		}
     	USBHostTasks();
	}
	sixaxis_control_channel_id=0;
}
