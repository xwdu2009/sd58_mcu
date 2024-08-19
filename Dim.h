#ifndef _Dim_h_
#define _Dim_h_
//#include "Global.h"
//#include "at32_board.h"


//=============================================================================
//WIFI,��wifi.h��
//=============================================================================
#define         SMART_CONFIG_STATE              0x00
#define         AP_STATE                        0x01
#define         WIFI_NOT_CONNECTED              0x02
#define         WIFI_CONNECTED                  0x03
#define         WIFI_CONN_CLOUD                 0x04
#define         WIFI_LOW_POWER                  0x05
#define         SMART_AND_AP_STATE              0x06
#define         WIFI_SATE_UNKNOW                0xff

//��Դ�Ƶ�pwmֵ
#define PWM_CLOSE 100			//�ߵ�ƽ�ر�
#define PWM_HIGH	0				//����
#define PWM_LOW		70			//����

//ģ�⴮�ڽ���λ��
#define DATA_STARTBIT						0
#define DATA_TOTALBIT						22//8
#define DATA_FINISHBIT						(RECDATA_TOTALBIT+1)
//flash��д��С�͵�ַ����31ҳ��������dim����
#define TEST_BUFEER_SIZE  6//10
#define TEST_FLASH_ADDRESS_START  0x0//(0x8000000+1024*31)							//��31ҳ(0-31ҳ)



#define   PWMDUTY					3
#define   PWMCYCLE				6

#define   KEYTIMER				3							//�ϴ�wifi��ʱ
#define   TIMER1_ENABLE	    0							//�򿪶�ʱ��1
#define   REJECT_ENABLE		1							//�޳�����ʹ��
#define   WBYTE_ENABLE		1

//��������
#define 	BRIGHT_INIT			0xe41b
#define 	ANGLE_MIN			142//140								//�Ƕ�ֵԽ������ԽС�������������MIn��ʾ
#define 	ANGLE_MAX			42//30	//40						//�Ƕȷ�Χ��40-140�ĳ�30-140
#define   ANGLE_START 			(ANGLE_MAX*100)	

//��������
#define 	NO_COMMAND			0x00
#define 	MIN_COMMAND      	0xe6				//wifi������С����ֵdim�ͷ��͸�����(��8λ��ָ���8λ������wifi����С����ֵ),���Ż��ᷢ����С����ֵ��16λ�ֽڳ���
//#define LOW_COMMAND      0xf3					//Ŀǰ��������֪����ʲô����
#define 	RESET_COMMAND    	0xf4				//������λ�ᷢ��������
#define 	SET_COMMAND      	0xf5				//������˳����� ѧϰģʽ:
																				//����ѧϰģʽ�ᷢ���������(��8λ��ָ���8λ�Ǹ�8λȡ��)�����ŷ�����С����ֵ16λ�ֽڳ�����
																				//���ͨ����ָ���˳�������Ҫ���������С����ֵ,��ʱ�ᷢ���������(��8λ��ָ���8λ�Ǹ�8λȡ��)�����ŷ��͵�ǰ�����ȳ�������ע�⵱ǰ����
#define 	EXIT_COMMAND     	0xf6				//��ʱ�˳�ѧϰģʽ������

//���ڰٷֱ�ԭʼ����
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

