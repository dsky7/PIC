/*
********************************************************************************
                                                                                
Software License Agreement                                                      
                                                                                
Copyright © 2007-2008 Microchip Technology Inc. and its licensors.  All         
rights reserved.                                                                
                                                                                
Microchip licenses to you the right to: (1) install Software on a single        
computer and use the Software with Microchip 16-bit microcontrollers and        
16-bit digital signal controllers ("Microchip Product"); and (2) at your        
own discretion and risk, use, modify, copy and distribute the device            
driver files of the Software that are provided to you in Source Code;           
provided that such Device Drivers are only used with Microchip Products         
and that no open source or free software is incorporated into the Device        
Drivers without Microchip's prior written consent in each instance.             
                                                                                
You should refer to the license agreement accompanying this Software for        
additional information regarding your rights and obligations.                   
                                                                                
SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY         
KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY              
WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A          
PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE             
LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY,               
CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY           
DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY         
INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR         
LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY,                 
SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY         
DEFENSE THEREOF), OR OTHER SIMILAR COSTS.                                       
                                                                                
********************************************************************************
*/

// Created by the Microchip USBConfig Utility, Version 0.0.12.0, 3/28/2008, 8:58:18

#include "GenericTypeDefs.h"
#include "HardwareProfile.h"
#include "USB/usb.h"
#include "USB/usb_host_bluetooth.h"

// *****************************************************************************
// Client Driver Function Pointer Table for the USB Embedded Host foundation
// *****************************************************************************

CLIENT_DRIVER_TABLE usbClientDrvTable[] =
{                                        
    {
        USBHostBluetoothInit,
        USBHostBluetoothEventHandler,
        0
    },                                   
    {//add naka_at_kure
        USBHostBluetoothInit,
        USBHostBluetoothEventHandler,
        0
    },                              
    {//add naka_at_kure
        USBHostBluetoothInit,
        USBHostBluetoothEventHandler,
        0
    },
    {//add @micutil
        USBHostBluetoothInit,
        USBHostBluetoothEventHandler,
        0
    },
    {//add @micutil
        USBHostBluetoothInit,
        USBHostBluetoothEventHandler,
        0
    },
    {//add @micutil
        USBHostBluetoothInit,
        USBHostBluetoothEventHandler,
        0
    },
    {//add @micutil
        USBHostBluetoothInit,
        USBHostBluetoothEventHandler,
        0
    },
    {//add @micutil
        USBHostBluetoothInit,
        USBHostBluetoothEventHandler,
        0
    },
    {//add @micutil
        USBHostBluetoothInit,
        USBHostBluetoothEventHandler,
        0
    },
    {
        USBHostBluetoothInit,
        USBHostBluetoothEventHandler,
        0
    },
};

// *****************************************************************************
// USB Embedded Host Targeted Peripheral List (TPL)
// *****************************************************************************

USB_TPL usbTPL[] =
{
    { INIT_CL_SC_P( 0xe0ul, 0x01ul, 0x01ul ), 0, 0, {TPL_CLASS_DRV} },// (null)
    { INIT_VID_PID( 0x05B8ul, 0x1004ul ), 0, 0, {0} }, //U3312S add naka_at_kure
    { INIT_VID_PID( 0x05B8ul, 0x1006ul ), 0, 0, {0} }, //U3412S add naka_at_kure
    { INIT_VID_PID( 0x0079ul, 0x0006ul ), 0, 0, {0} }, //Generic USB Joystick (DragonRise Inc.) add @micutil
    { INIT_VID_PID( 0x046Dul, 0xC219ul ), 0, 0, {0} }, //F710 Wireless Gamepad (Logicool Inc.) D-Mode add @micutil
    { INIT_VID_PID( 0x046Dul, 0xC21Ful ), 0, 0, {0} }, //F710 Wireless Gamepad (Logicool Inc.) X-Mode add @micutil
    { INIT_VID_PID( 0x046Dul, 0xC22Ful ), 0, 0, {0} }, //F710 Wireless Gamepad (Logicool Inc.) Initialize
    { INIT_VID_PID( 0x046Dul, 0xC218ul ), 0, 0, {0} }, //F510 Rumble Gamepad (Logicool Inc.) D-Mode add @micutil
    { INIT_VID_PID( 0x046Dul, 0xC21Eul ), 0, 0, {0} }, //F510 Rumble Gamepad (Logicool Inc.) X-Mode add @micutil
    { INIT_VID_PID( 0x054Cul, 0x0268ul ), 0, 0, {0} }, //PS3Controller
};

