#ifndef _Dim_h_
#define _Dim_h_
//#include "Global.h"
//#include "at32_board.h"


//=============================================================================
//WIFI,在wifi.h中
//=============================================================================
#define         SMART_CONFIG_STATE              0x00
#define         AP_STATE                        0x01
#define         WIFI_NOT_CONNECTED              0x02
#define         WIFI_CONNECTED                  0x03
#define         WIFI_CONN_CLOUD                 0x04
#define         WIFI_LOW_POWER                  0x05
#define         SMART_AND_AP_STATE              0x06
#define         WIFI_SATE_UNKNOW                0xff

//电源灯的pwm值
#define PWM_CLOSE 100			//高电平关闭
#define PWM_HIGH	0				//高亮
#define PWM_LOW		70			//低亮

//模拟串口接收位数
#define DATA_STARTBIT						0
#define DATA_TOTALBIT						22//8
#define DATA_FINISHBIT						(RECDATA_TOTALBIT+1)
//flash读写大小和地址，第31页用来保存dim参数
#define TEST_BUFEER_SIZE  6//10
#define TEST_FLASH_ADDRESS_START  0x0//(0x8000000+1024*31)							//第31页(0-31页)



#define   PWMDUTY					3
#define   PWMCYCLE				6

#define   KEYTIMER				3							//上传wifi延时
#define   TIMER1_ENABLE	    0							//打开定时器1
#define   REJECT_ENABLE		1							//剔除功能使能
#define   WBYTE_ENABLE		1

//出厂设置
#define 	BRIGHT_INIT			0xe41b
#define 	ANGLE_MIN			142//140								//角度值越大，亮度越小，所以这个宏用MIn表示
#define 	ANGLE_MAX			42//30	//40						//角度范围由40-140改成30-140
#define   ANGLE_START 			(ANGLE_MAX*100)	

//串口命令
#define 	NO_COMMAND			0x00
#define 	MIN_COMMAND      	0xe6				//wifi发送最小亮度值dim就发送该命令(高8位是指令，低8位是来自wifi的最小亮度值),接着还会发送最小亮度值的16位字节出来
//#define LOW_COMMAND      0xf3					//目前这个命令还不知道是什么？？
#define 	RESET_COMMAND    	0xf4				//长按复位会发出该命令
#define 	SET_COMMAND      	0xf5				//进入或退出保存 学习模式:
																				//进入学习模式会发送这个命令(高8位是指令，低8位是高8位取反)，接着发送最小亮度值16位字节出来。
																				//如果通过该指令退出，则需要保存这个最小亮度值,此时会发送这个命令(高8位是指令，低8位是高8位取反)，接着发送当前的亮度出来！！注意当前亮度
#define 	EXIT_COMMAND     	0xf6				//超时退出学习模式不保存

//串口百分比原始数据
#define PERCENT1				1
#define PERCENT2				5
#define PERCENT3				20
#define PERCENT4				35
#define PERCENT5				50
#define PERCENT6				65
#define PERCENT7				80
#define PERCENT8				100

void Led7Run(void);
void DimData_Deal(void);
void Learn_Mode(void);
//void NTC_Ctl(void);

void Isp_Write(u32 WriteAddr,u8 *pBuffer);
void Isp_Read(u32 ReadAddr,u8 *pBuffer);
//void Isp_Earse(u32 WriteAddr);
//void Isp_Earse32K(u32 WriteAddr,u8 pagelen);
//void Isp_Write1K(u32 WriteAddr,const u8 *pBuffer,u16 len);

//void Uart_3way(void);
//void OrdSwitch_Recognize(void);
void Factory_Test_Mode(void);
void PowerLedRun(void);
void SynDataReset_Deal(void);
//void Uart_Send(void);

void AT32_SystemReset(void);
#endif

