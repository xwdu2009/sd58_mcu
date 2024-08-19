/*-----------------------------------------------------------------------------
Copyright 2019-2022 INNOTECH Technology Co.,Ltd All Rights Reserved.
FileName: macro.h
Author: 
Version:V1.0.0
Date:
Description: 
Function List: 
History:<author> <time> <version > <desc>
-----------------------------------------------------------------------------*/
#include "ramdef.h"
#include "fundef.h"

#ifndef _MACRO_H
#define _MACRO_H


#define		unchar				unsigned char 
#define		unint				unsigned int
#define		unlong				unsigned long

typedef unsigned char  		 boolean;
typedef unsigned char  		 uint8;
typedef signed   char  		 int8;
typedef unsigned short int   uint16;                   
typedef signed   short int   int16;                   
typedef unsigned        int  uint32;                   
typedef signed          int  int32;


typedef unsigned char  		 uint8_t;
typedef signed   char  		 int8_t;
typedef unsigned short int   uint16_t;                   
typedef signed   short int   int16_t;                   
typedef unsigned        int  uint32_t;                   
typedef signed          int  int32_t;

typedef unsigned char        u8;
typedef unsigned short int   u16;                   
typedef unsigned int         u32;

#define		DemoPortOut	    PB3   
#define		DemoPortIn		RC3

#define		DemoPortOut1     PC1	// Red LED
#define		DemoPortOut2     PB7	// Green LED
#define		DemoPortOut3     PB5
#define		DemoPortOut4     PB4
#define		DemoPortOut5     PB3
#define		DemoPortOut6     PB2
#define		DemoPortOut7     PC4
#define		DemoPortOut8     PC5
#define		DemoPortOut9     PC6

//#define FIRMWARE_VERSION “1.2_2024-06-18”

#define TRUE 1
#define FALSE 0

#define ENABLE 1
#define DISABLE 0

#define		IO_DIMP			PD1
#define		IO_DIMM			PD2
#define 	IO_POWER_ON		PD3
#define 	IO_POWER_OFF	PB1

#define LED1_ON() 		PC1 = 0;	// red LED
#define LED1_OFF() 		PC1 = 1;
#define LED2_ON() 		PB7 = 0;	// green LED
#define LED2_OFF() 		PB7 = 1;

#define LED_RED_ON() 		PC1 = 0;	// red LED
#define LED_RED_OFF() 		PC1 = 1;
#define LED_GREEN_ON() 		PB7 = 0;	// green LED
#define LED_GREEN_OFF() 	PB7 = 1;
#define LED_RED_TOGGLE() 	PC1 ^= 1;
#define LED_GREEN_TOGGLE() 	PB7 ^= 1;

#define LED_WHITE_ON() 		PB6 = 0;	// white LED
#define LED_WHITE_OFF() 	PB6 = 1;
#define LED_WHITE_TOGGLE() 	PB6 ^= 1;

#define LED3_ON() 		PB5 = 0;
#define LED3_OFF() 		PB5 = 1;
#define LED4_ON() 		PB4 = 0;
#define LED4_OFF() 		PB4 = 1;
#define LED5_ON() 		PB3 = 0;
#define LED5_OFF() 		PB3 = 1;
#define LED6_ON() 		PB2 = 0;
#define LED6_OFF() 		PB2 = 1;
#define LED7_ON() 		PC4 = 0;
#define LED7_OFF() 		PC4 = 1;
#define LED8_ON() 		PC5 = 0;
#define LED8_OFF() 		PC5 = 1;
#define LED9_ON() 		PC6 = 0;
#define LED9_OFF() 		PC6 = 1;

#define DIM_ON() 		PB0 = 1;
#define DIM_OFF() 		PB0 = 0;

#define RELAY_ON() 		PA0 = 1;
#define RELAY_OFF() 	PA0 = 0;
#define RELAY_TOGGLE() 	PA0 ^= 1;

#define LOAD_DETECT     PC0

//串口数据
#define FRAME_HEAD_1            0xAA       

#define UART_MODE               0x00
#define UART_SWITCH             0x9A
#define UART_BRIGHT_VALUE       0x9B
#define UART_BRIGHT_VALUE_MIN   0x9C
#define UART_BRIGHT_KEY_PRESS   0x9D
#define UART_SWITCH_ON          0x9E

#define POWER_ON           0x01
#define POWER_OFF          0x00
#define CONNECT_READY      0x01
#define CONNECT_WIFI       0x02
#define CONNECT_COMMISION  0x03

#define UARR_FRAME_HEAD_1  0x55
#define UARR_FRAME_HEAD_2  0xAA
#define UART_CMD_POWER     0x01
#define UART_CMD_BRIGHT    0x02
#define UART_CMD_RESET     0x03
#define UART_CMD_CONNECT   0x04
#define UART_CMD_PARAMETER 0x05
#define UART_CMD_IDENTIFY  0x06


#define UART_CMD_DEBUG     0x0A

#define ON             1
#define OFF            0

#ifndef LOW
#define         LOW                0
#endif

#ifndef HIGH
#define         HIGH               1
#endif

#define ADC_VAL  2860//3300     	// 需要重新计算，原参考电压2.6V，2.09V,3300
                                    //                 参考电压3.0V，2.09V,2860

#endif
