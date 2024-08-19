#include "header.h"
#include "Dim.h"
#include "Key.h"

extern uint8 DimPercentDataOppose;
extern uint8 PowerFlag;
extern uint8 KeyDIMLearnval;
extern uint8 KeyPowerVal;
extern uint8 KeyPowerOnVal;
extern uint8 KeyPowerOffVal;
extern uint8_t UartTxBuf[6]; 
extern uint8_t FrameSendFlag;
//extern __IO uint16_t ADCConvertedValue;


extern void wifi_uart_service(void);
//extern unsigned char mcu_dp_value_update(unsigned char dpid,unsigned long value);
//extern unsigned char mcu_dp_bool_update(unsigned char dpid,unsigned char value);
extern void mcu_dp_value_update(uint8_t sync_cmd,uint8 sync_data);
extern void mcu_start_wifitest(void);
extern void mcu_reset_wifi(void);
extern unsigned char mcu_get_wifi_work_state(void);

//��ʱ
uint16 Count100ms = 0;
//�¶ȿ���
uint16 ADCNtcValue = 0;
uint8 ADCCount = 0;
uint16 ADCSum = 0;
uint8 NtcState = 0;										//���²�����������
uint8 NtcNumer = 0;
//�ƹ⽥��
uint8 BufDimPercentData = 1;
uint8 TempDimPercentData = 1;
uint8 FadeFlag = 0;										//�Ƿ�������
uint8 FadeNumer = 0;
//��Դ�Ƶ���ر���
uint8 delaynumer = 0;
uint8 WifiWorkState = WIFI_SATE_UNKNOW;	//wifiδ֪ģʽ
uint8 PowerLedNumer = 0;
uint16 PowerLedNumer1 = 0;	//����ʱ���ʱ��wifi 3���Ӽ�ʱ
uint8 LedNum = 0;		
uint8 PowerLedFlag = 1;			//0:�� 1������ 2������
uint8 LedState = 0;					//���߼�����
uint8 LedStatePre = 0;
//wifi����
uint8 WifiPowerFlag = 0;
uint8 WifiTestFlag = 0;
uint8 Min3State = 0;
//��ʱ����
uint16 datah;
uint16 datal;
volatile uint8 cheakh;
volatile uint8 cheakl;
//ѧϰģʽ
uint16 LearnNumer = 0;
uint8 LearnNumer1 = 0;
uint8 RecLearnFlag = 0;
uint8 RecDimPercent = 0;											//����3way����ǰϵͳ������ֵ
uint8 RecDimPercentMin = 0;										//����3way����ǰ����С����ֵ

// 3-way���ڽ�������
uint8 RecFinishFlag = 0;											//���յ�һ����������
uint8 RecFlag = 0;														//��ʼģ����յı�־
uint8 SendFlag = 0;														//��ʼģ�ⷢ�͵ı�־
uint8 ZCDIntFlag = 0;													//�����жϲ����ı�־
uint8 ZCDIntTimer = 0;												//�����ж�����֮����ʱ��ʱ��
uint16 RecData = 0;														// ���ڽ�������
uint16 RecDataBuf = 0;
uint8 RecDateBitCounter = 0;									// ���յڼ�λ����
uint8 RecDateBitFilterNumer = 0;							// ÿ����һbit��ʱ�жϴ���
uint16 SendData = 0;
uint8 SendDateBitCounter = 0;				
uint8 SendMode = 0;				
uint8 SendDateBitFilterNumer = 0;			
uint16 UartData = BRIGHT_INIT;								// �����洢���ڽ��ջ��߷�������,Ĭ������100%
//�������
uint8 DimPercentData  = 100;									//��Χ��1-100
uint8 DimPercentDataPre = 100;								//�������ֵ�Ƿ�ı䣬Ȼ���͸���һ��dimmerͬ����
uint8 DimPercentDataPre1 = 100;								//�������ֵ�Ƿ�ı䣬Ȼ��ÿ��100ms���͸�app��ʵ��ͬ����
uint8 DimPercentDataNumer = 0;								//��ʱ����app����ֵ
uint8 AngleMin = ANGLE_MIN;   								// ������180��,Ĭ��140����С����
uint8 DimPercentMin = 1;											//��Χ��1-100��Ĭ����1,���ڵ�ѧϰģʽ��С����
uint8 DimPercentMinPre = 1;										//��Χ��1-100��Ĭ����1,���ڵ�ѧϰģʽ��С����
uint8 DimMin = 1;															//����dimwifi����С����ֵ����ͬ��DimPercentMin
		
//���������������־
uint8 SetCommadFlag = 0;											//���Դ��ڵĽ���ѧϰģʽ������
uint8 RecExitLearnFlag = 0;										//�˳�ѧϰģʽ������
uint8 Dim1SendPowerFlag = 0;									//���͵�Դ��־
uint8 Dim1SendPercentDataFlag = 0;						//�������Ȱٷֱȱ�־
uint8 Dim1SendSetCommandFlag = 0;							//���ͽ���ѧϰģʽ�ı�־
uint8 Dim1SendExitCommandFlag = 0;						//�����˳�ѧϰģʽ�ı�־
uint8 Dim1SendWifiMinFlag = 0;								//��������wifi����С����ֵ��־
uint8 McuSendDataFlag = 0;										//�����־��ʱ30ms������

uint8 PowerFirstFlag = 0;											//��һ���ϵ���ʱ300ms��־	
uint8 InitFlag = 0;														//��һ���ϵ�5s
uint8 PowerFirstWifiFlag = 0;									//wifi��һ���ϵ�
uint8 Min3Flag = 0;														//3������ʱ
uint8 DimPower5sFlag = 0;											//�����˸�λ����
//��ͨ���ر�־
uint8 IsOrdSwitchFlag = 0;										//�Ƿ�����ͨ���صı�־
uint8 OrdSwitchPowerFlag = 0;									//��ͨ���ؿ��ص�Դ�ı�־
//��ͨ����ʶ��
uint8 RecognizState = 0;
uint8 RecognizNumer = 0;
uint8 RecognizNumer1 = 0;
uint8 HighorLowFlag = 0;		//1Ϊ�ߣ�2Ϊ��
uint8 OrdCheakFlag = 0;			//ÿ��3-way�շ�������Ҫ��ʱ1sȥ�����ͨ���ر�־
//��������
uint8 FactoryFlag = 0;
uint8 FactoryState = 0;
uint16 FactoryNumer = 0;
uint8 FactoryFirstFlag = 0;	//����ģʽ��һ���ϵ���
//pwm
uint8 PwmDuty = PWM_CLOSE;
uint8 SendNumer = 0;				//��ʱ30ms

uint8 KeyPowerOffFlag = FALSE;
uint8 MsgSendFlag = FALSE;
//==============================================================================================//
//�������ƣ� DimData_Deal
//����˵���� ����dim1��dim2���ݣ���Դ���أ���Դ+��-
//����    �� ��
//����ֵ  �� ��
//==============================================================================================//
			
void DimData_Deal(void)
{
	//---------------------------------dim2�����ݴ�����ϱ�-------------------------------------
	//���յ�������
	
	//------------------------------------------------------------------------------------------
	//---------------------------------dim1? ��?�ݴ������??-------------------------------------
	//if(((KeyPowerVal == KEY_DIMPOWER_SHORT)||(OrdSwitchPowerFlag)||(NtcState))&&(!RecLearnFlag))//dim1�ĵ�Դ����,ѧϰģʽ�²����� 
	//if((KeyPowerOnVal == KEY_DIMPOWER_SHORT) || (KeyPowerOffVal == KEY_POWEROFF_SHORT))//dim1�ĵ�Դ����,ѧϰģʽ�²����� 
	if((KeyPowerOnVal == KEY_POWERON_SHORT) || (KeyPowerOnVal == KEY_POWERON_DOUBLE) || (KeyPowerOffVal == KEY_POWEROFF_SHORT))
	{
		//PowerFlag = !PowerFlag;													//���λ�����Դ�Ŀ��أ�1Ϊ����0Ϊ��
		
        //if(KeyPowerOnVal == KEY_DIMPOWER_SHORT)
        if(KeyPowerOnVal == KEY_POWERON_SHORT)
        {
			if((PowerFlag == 0) && (KeyPowerOffFlag == FALSE)) 
            {       				
				PowerFlag = 1;	
                mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
				RELAY_TOGGLE();
            }
        }
        else if(KeyPowerOffVal == KEY_POWEROFF_SHORT)
        {
			if(PowerFlag == 1) 
            {       
				PowerFlag = 0;	
				//RELAY_TOGGLE(); 
                mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
                KeyPowerOffFlag = TRUE; 
            }     
        }   
	    else if(KeyPowerOnVal == KEY_POWERON_DOUBLE)	     
		{
			if((PowerFlag == 0) && (KeyPowerOffFlag == FALSE)) 
            {       				
				PowerFlag = 1;	
                mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
				RELAY_TOGGLE();
				DelayMs(100);
				DimPercentData = 100;
            }
			else if(PowerFlag == 1) 
            {    
				DimPercentData = 100;
			}
		}    

		//�ϱ�
		//mcu_dp_bool_update(DPID_SWITCH_LED_1,PowerFlag);//�ϱ���wifi
        /*
		if(!OrdSwitchPowerFlag)
			Dim1SendPowerFlag = 1;													//���͸�dim2
		
		OrdSwitchPowerFlag = 0;
		NtcState = 0;
        */
	}
    DimPercentDataPre = DimPercentData;

//	if(PowerFlag)//����Դ
//	{	
//		
//		if((KeyDIMLearnval)&&(KeyDIMLearnval != KEY_DIM_BOTH_LONG)&&(!RecLearnFlag))//�����ı�����,����ѧϰģʽ����Ч//������������
//		{
//			FrameSendFlag = 1;
//			if(KeyDIMLearnval == KEY_DIMP_SHORT)													//+����
//			{
//				if(DimPercentData < PERCENT1)DimPercentData = PERCENT1;
//				else if(DimPercentData < PERCENT2) DimPercentData = PERCENT2;
//				else if(DimPercentData < PERCENT3) DimPercentData = PERCENT3;
//				else if(DimPercentData < PERCENT4) DimPercentData = PERCENT4;
//				else if(DimPercentData < PERCENT5) DimPercentData = PERCENT5;
//				else if(DimPercentData < PERCENT6) DimPercentData = PERCENT6;
//				else if(DimPercentData < PERCENT7) DimPercentData = PERCENT7;
//				else if(DimPercentData < PERCENT8) DimPercentData = PERCENT8;
//				else DimPercentData = PERCENT8;
//			}
//			else if(KeyDIMLearnval == KEY_DIMP_LONG)							//+����
//			{
//				if(++delaynumer >= KEYTIMER)
//				{
//					delaynumer = 0;
//					if(DimPercentData < 100)
//					{
//						DimPercentData++;
//					}
//				}
//			}
//			else if(KeyDIMLearnval == KEY_DIMM_SHORT)									//-����
//			{
//				if(DimPercentData > PERCENT7) DimPercentData = PERCENT7;
//				else if(DimPercentData > PERCENT6) DimPercentData = PERCENT6;
//				else if(DimPercentData > PERCENT5) DimPercentData = PERCENT5;
//				else if(DimPercentData > PERCENT4) DimPercentData = PERCENT4;
//				else if(DimPercentData > PERCENT3) DimPercentData = PERCENT3;
//				else if(DimPercentData > PERCENT2) DimPercentData = PERCENT2;
//				else if(DimPercentData > PERCENT1) DimPercentData = PERCENT1;
//				else DimPercentData = PERCENT1;
//			}
//			else if(KeyDIMLearnval == KEY_DIMM_LONG)							//-����
//			{
//				if(++delaynumer >= KEYTIMER)
//				{
//					delaynumer = 0;
//					if(DimPercentData > 1)
//					{
//						DimPercentData--;
//					}
//				}
//			}
//			if(DimPercentData <= DimMin)
//				DimPercentData = DimMin;
//			
//			
//			//�ϱ�,�����иı���ϱ�
//			if(DimPercentDataPre != DimPercentData)
//			{
//				DimPercentDataPre = DimPercentData;
////				mcu_dp_value_update(DPID_BRIGHT_VALUE_1,DimPercentData*10); //�ϱ�wifi
//				Dim1SendPercentDataFlag = 1;																//�ϱ�dim2
//			}													
//		}
//		else
//			delaynumer = 0;				
//	}
//	else
//	{
//		delaynumer = 0;
//	}


		
	if((KeyDIMLearnval)&&(KeyDIMLearnval != KEY_DIM_BOTH_LONG)&&(!RecLearnFlag))//�����ı�����,����ѧϰģʽ����Ч//������������
	{
		//FrameSendFlag = 1;
		if(PowerFlag == OFF)
		{				
			PowerFlag = ON;	
            mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
			RELAY_TOGGLE();
										
			//mcu_dp_value_update(UART_CMD_POWER,PowerFlag);		
		}
		if(KeyDIMLearnval == KEY_DIMP_SHORT)													//+����
		{		
        
			if(DimPercentData < PERCENT1)DimPercentData = PERCENT1;
			else if(DimPercentData < PERCENT2) DimPercentData = PERCENT2;
			else if(DimPercentData < PERCENT3) DimPercentData = PERCENT3;
			else if(DimPercentData < PERCENT4) DimPercentData = PERCENT4;
			else if(DimPercentData < PERCENT5) DimPercentData = PERCENT5;
			else if(DimPercentData < PERCENT6) DimPercentData = PERCENT6;
			else if(DimPercentData < PERCENT7) DimPercentData = PERCENT7;
			else if(DimPercentData < PERCENT8) DimPercentData = PERCENT8;
			else DimPercentData = PERCENT8;
            
//			if(DimPercentDataPre1 != DimPercentData)
//			{
//				DimPercentDataPre1 = DimPercentData;
//				mcu_dp_value_update(UART_CMD_BRIGHT,DimPercentData);
//			}
		}
		else if(KeyDIMLearnval == KEY_DIMP_LONG)							//+����
		{			
        
			if(++delaynumer >= KEYTIMER)
			{
				delaynumer = 0;
				if(DimPercentData < 100)
				{
					DimPercentData++;
				}
			}
		}
		else if(KeyDIMLearnval == KEY_DIMM_SHORT)									//-����
		{				
        
			if(DimPercentData > PERCENT7) DimPercentData = PERCENT7;
			else if(DimPercentData > PERCENT6) DimPercentData = PERCENT6;
			else if(DimPercentData > PERCENT5) DimPercentData = PERCENT5;
			else if(DimPercentData > PERCENT4) DimPercentData = PERCENT4;
			else if(DimPercentData > PERCENT3) DimPercentData = PERCENT3;
			else if(DimPercentData > PERCENT2) DimPercentData = PERCENT2;
			else if(DimPercentData > PERCENT1) DimPercentData = PERCENT1;
			else DimPercentData = PERCENT1;
            
//			if(DimPercentDataPre1 != DimPercentData)
//			{
//				DimPercentDataPre1 = DimPercentData;
//				mcu_dp_value_update(UART_CMD_BRIGHT,DimPercentData);
//			}
		}
		else if(KeyDIMLearnval == KEY_DIMM_LONG)							//-����
		{			
        
			if(++delaynumer >= KEYTIMER)
			{
				delaynumer = 0;
				if(DimPercentData > 1)
				{
					DimPercentData--;
				}
			}
		}
		if(DimPercentData <= DimMin)
			DimPercentData = DimMin;
		
		
		//�ϱ�,�����иı���ϱ�
		if(DimPercentDataPre != DimPercentData)
		{
			DimPercentDataPre = DimPercentData;
			Dim1SendPercentDataFlag = 1;																//�ϱ�dim2
		}													
	}
	else
		delaynumer = 0;				


}
//==============================================================================================//
//�������ƣ� Led5Run
//����˵���� ����ʾ
//����    �� ��
//����ֵ  �� ��
//==============================================================================================//
void Led7Run(void)
{
	//�ٷֱȵ�
	if(DimPercentData > 100) 					//����
		DimPercentData = 100;
	//--------------------------------------------
	//�������
	if(PowerFlag)
	{
		BufDimPercentData = DimPercentData;
		FadeFlag = 1;
	}
	else
	{
		BufDimPercentData = 1;
	}
    
	//if(++FadeNumer >= 1)
	{
		FadeNumer = 0;
		if(TempDimPercentData < BufDimPercentData) 				TempDimPercentData ++;
		else if(TempDimPercentData > BufDimPercentData)		TempDimPercentData --;
		
		//if(TempDimPercentData <= 1)		FadeFlag = 0;				//no fading allowed
        if(TempDimPercentData <= 1)
        {
			FadeFlag = 0;
			if(TRUE == KeyPowerOffFlag)
			{
				RELAY_TOGGLE();
				KeyPowerOffFlag = FALSE;
			}            	
        }			
	
		if((TempDimPercentData > 0)&&(TempDimPercentData <= 100))
			DimPercentDataOppose = 100 - TempDimPercentData;
	}
	//--------------------------------------------
	//7led����
	if((PowerFlag)||(FadeFlag))
	{
		if(TempDimPercentData <= 5)	LedNum = 1;
		else if(TempDimPercentData <= 20) LedNum = 2;
		else if(TempDimPercentData <= 35) LedNum = 3;
		else if(TempDimPercentData <= 50) LedNum = 4;
		else if(TempDimPercentData <= 65) LedNum = 5;
		else if(TempDimPercentData <= 80) LedNum = 6;
		else if(TempDimPercentData <= 100) LedNum = 7;        
	}
	else
	{
		if(!WifiTestFlag)
			LedNum = 0;
	}
	switch(LedNum)
	{
		case 1:
			LED3_ON();LED4_OFF();LED5_OFF();LED6_OFF();LED7_OFF();LED8_OFF();LED9_OFF();
			break;
		case 2:
			LED3_ON();LED4_ON();LED5_OFF();LED6_OFF();LED7_OFF();LED8_OFF();LED9_OFF();
			break;
		case 3:
			LED3_ON();LED4_ON();LED5_ON();LED6_OFF();LED7_OFF();LED8_OFF();LED9_OFF();
			break;
		case 4:
			LED3_ON();LED4_ON();LED5_ON();LED6_ON();LED7_OFF();LED8_OFF();LED9_OFF();
			break;
		case 5:
			LED3_ON();LED4_ON();LED5_ON();LED6_ON();LED7_ON();LED8_OFF();LED9_OFF();
			break;
 		case 6:
			LED3_ON();LED4_ON();LED5_ON();LED6_ON();LED7_ON();LED8_ON();LED9_OFF();
			break;
		case 7:
			LED3_ON();LED4_ON();LED5_ON();LED6_ON();LED7_ON();LED8_ON();LED9_ON();
			break;                       
		default:
			LED3_OFF();LED4_OFF();LED5_OFF();LED6_OFF();LED7_OFF();LED8_OFF();LED9_OFF();
			break;
	}
}

//==============================================================================================//
//�������ƣ� NTC_Ctl
//����˵���� �¶ȿ���
//����    �� ��
//����ֵ  �� ��
//==============================================================================================//
void NTC_Ctl(void)
{

}

//==============================================================================================//
//�������ƣ� Isp_Read��Isp_Write,Isp_Earse
//����˵���� FLASH��д����,��ȡҳ��д�ķ�ʽ
//����    �� ��
//����ֵ  �� ��
//==============================================================================================//
uint8 dataBuffer[TEST_BUFEER_SIZE]; 															// ��ram�е�λ��
uint8 FlashDataBuffer[TEST_BUFEER_SIZE];
void Isp_Write(u32 WriteAddr,u8 *pBuffer)
{
	u16 i;
	if(DimPercentData > 100) 					//����
		DimPercentData = 100;	
        
	pBuffer[0] = 0xaa;
	pBuffer[1] = PowerFlag;
	pBuffer[2] = DimPercentData;
	pBuffer[3] = DimPercentMin;
	pBuffer[4] = DimMin;
	pBuffer[5] = PowerLedFlag;
	pBuffer[6] = 0xff;
	pBuffer[7] = 0xff;
	pBuffer[8] = 0xff;
	pBuffer[9] = 0xff;
    /*
	FLASH_Unlock();
//	FLASH_ErasePage(WriteAddr);//�ϵ��Ѿ����������ﲻ��Ҫ��
	for(i=0; i<TEST_BUFEER_SIZE; i++)
	{
		FLASH_ProgramByte(WriteAddr, pBuffer[i]);
		WriteAddr++;
	}
	FLASH_Lock();
    */
	for(i=0; i<TEST_BUFEER_SIZE; i++)
	{   
		EEPROMwrite(i,pBuffer[i]);
    }
}

void Isp_Read(u32 ReadAddr,u8 *pBuffer)
{
	u16 i;
    /*
	for(i=0;i<TEST_BUFEER_SIZE;i++)
	{
		pBuffer[i] = FLASH_ReadByte(ReadAddr);//��ȡһ���ֽ�
		ReadAddr++;//ƫ��1���ֽ�.	
	}
	PowerFlag = 0;
	if(pBuffer[0]==0xaa)//�������ݱ������
	{
		//PowerFlag = pBuffer[1];
		DimPercentData = pBuffer[2];
		DimPercentMin = pBuffer[3];
		DimMin = pBuffer[4];
		PowerLedFlag = pBuffer[5];
		DimPercentDataOppose = 100 - DimPercentData;//��ʼ��,���û�оͻ�Ĭ����0������һ�ϵ�ͻ���˸һ��
	}
    */
	for(i=0;i<TEST_BUFEER_SIZE;i++)
	{
		pBuffer[i] = EEPROMread(i); ;//��ȡһ���ֽ�
	}
	PowerFlag = 0;	// �ϵ�Ĭ�Ϲص�
	if(pBuffer[0]==0xaa)//�������ݱ������
	{
		//PowerFlag = pBuffer[1];	// �ָ�����ǰ״̬
		//DimPercentData = pBuffer[2];
		DimPercentMin = pBuffer[3];
		DimMin = pBuffer[4];
		PowerLedFlag = pBuffer[5];
		DimPercentDataOppose = 100 - DimPercentData;//��ʼ��,���û�оͻ�Ĭ����0������һ�ϵ�ͻ���˸һ��

		//LED1_ON();
	}    
}



//==============================================================================================//
//�������ƣ� Uart_3way
//����˵���� ģ��3way���ڵ��շ�
//����    �� ��
//����ֵ  �� ��
//==============================================================================================//
void Uart_3way(void)
{

}

//==============================================================================================//
//�������ƣ� OrdSwitch_Recognize
//����˵���� ��ͨ����ʶ��
//����    �� ��
//����ֵ  �� ��
//==============================================================================================//
void OrdSwitch_Recognize(void)
{

}
//==============================================================================================//
//�������ƣ� Factory_Test_Mode
//����˵���� ��������ģʽ
//����    �� ��
//����ֵ  �� ��
//==============================================================================================//
void Factory_Test_Mode(void)
{

	switch(FactoryFlag)
	{
		case 0:
			FactoryState = 0;
			FactoryNumer = 0;
			if(0 == FactoryFirstFlag)
			{
				FactoryFirstFlag = 1;
				if((IO_DIMM == 0)&&(IO_DIMP == 0))
				{
                    // if(0 == PA0)
                    // {}
                    // else
                    // {
					// 	RELAY_TOGGLE();
                    // }
					// RELAY_OFF();
					LED1_ON();
                    LED2_ON();                    
					FactoryFlag = 1;
					// PwmDuty = PWM_CLOSE;
				}
			}
			break;
		case 1:
			if(++FactoryNumer >= 250)	//400->250
			{
				FactoryNumer = 0;
				FactoryState ++;
				if(FactoryState > 3)
					FactoryState = 3;
				if(FactoryState == 2)
				{
					// mcu_start_wifitest();	
				}	
			}
			if(FactoryState == 0)
			{
				// PwmDuty = PWM_CLOSE;
				AngleMin = ANGLE_MIN;		
				DimPercentData = 1;			//
				PowerFlag = 1;
			}
			else if(FactoryState == 1)
			{
				DimPercentData = 100;   //
			}
			else if(FactoryState == 2)
			{
				PowerFlag = 0;
				RELAY_ON();
			}
			else
			{
				// PwmDuty = PWM_LOW;									
				// if(WifiTestFlag)
				// 	LedNum = 5;
				// else
				// 	LedNum = 0;
			}
			// wifi_uart_service();
			// PWMDuty_Output(PwmDuty);
			break;
		default:
			break;
	}


}
//==============================================================================================//
//�������ƣ� Tonggle_TimeSet
//����˵���� �Ʒ�תʱ��,��������˸
//����    �� ��
//����ֵ  �� ��
//==============================================================================================//
uint8 Tonggle_TimeSet(uint8 timer)
{
	if(++PowerLedNumer >= timer)
	{
		PowerLedNumer = 0;
		if(PwmDuty == PWM_CLOSE)
			PwmDuty = PWM_LOW;
		else
			PwmDuty = PWM_CLOSE;
		return 1;
	}
	return 0;
}
//==============================================================================================//
//�������ƣ� PowerLedRun
//����˵���� ��Դ����ʾ
//����    �� ��
//����ֵ  �� ��
//==============================================================================================//
void PowerLedRun(void)//��Դ��
{
	//WifiWorkState = mcu_get_wifi_work_state();	//��ȡwifi����״
	
	if(RecLearnFlag)			//ѧϰģʽ
		LedStatePre = 1;			
	else if(0 == InitFlag)//�״��ϵ���˸5s
		LedStatePre = 2;	
	else
		LedStatePre = 3;
	if(LedState != LedStatePre)
	{
		LedState = LedStatePre;
		PowerLedNumer = 0;
		PowerLedNumer1 = 0; 
		Min3State = 0;
	}
	switch(LedState)
	{
		case 1:
			if(PowerLedNumer1 < 4)
			{
				if(Tonggle_TimeSet(25))
					PowerLedNumer1++;
			}
			else if(PowerLedNumer1 < 6)
			{
				if(Tonggle_TimeSet(100))
					PowerLedNumer1++;
			}
			else
				PowerLedNumer1 = 0;
			break;
		case 2:
			if(Tonggle_TimeSet(25))//
			{
				if(++PowerLedNumer1 >= 11)
				{
					PowerLedNumer1 = 0;
					InitFlag = 1;
				}
			}
			break;
		default:
			switch(Min3State)
			{
				case 0:
					PowerLedNumer = 0;
					PowerLedNumer1 = 0;
					Min3Flag = 0;
					Min3State = 1;
					break;
				case 1:
					//��һ���ϵ磬����������״̬������λһ��wifi,Ҫ�ӱ�־����3min����û����������ͣ�������ﲻ����Դ��
					if((WifiWorkState == WIFI_LOW_POWER)&&(PowerFirstWifiFlag == 0))
					{
						//if(PowerFirstWifiFlag == 0)
						{
							PowerFirstWifiFlag = 1;
							//mcu_reset_wifi();
						}
					}
					else if(DimPower5sFlag)//����5s��λʱ�䵽��
					{
						Tonggle_TimeSet(100);
						if(++PowerLedNumer1 >= 300)
						{
							PowerLedNumer1 = 0;
							DimPower5sFlag = 0;
						}
					}
					else if(WifiWorkState == WIFI_CONN_CLOUD)
					{
						Min3Flag = 0;//clear
						PowerLedNumer1 = 0;
						if(PowerLedFlag==1)PwmDuty = PWM_LOW;
						else if(PowerLedFlag==2)PwmDuty = PWM_HIGH;
						else PwmDuty = PWM_CLOSE;
					}
					else if((Min3Flag == 0)&&((WifiWorkState == SMART_CONFIG_STATE)||(WifiWorkState == AP_STATE)))
					{
						if(WifiWorkState == SMART_CONFIG_STATE)						//wifi smart mode
						{
							Tonggle_TimeSet(25);
						}
						else if(WifiWorkState == AP_STATE)								//wifi APģʽ
						{
							Tonggle_TimeSet(100);
						}
						if(++PowerLedNumer1 >= 18000)											//3min
						{
							PowerLedNumer1 = 0;
							Min3Flag = 1;//3min������־
						}
					}
					else
					{
						//Min3Flag = 0;//clear
						PowerLedNumer1 = 0;
						if(WifiWorkState == WIFI_SATE_UNKNOW)
						{
							PwmDuty = PWM_LOW;
						}
						else	//ble��һЩ�Ŀ���
						{
							if(PowerLedFlag==1)PwmDuty = PWM_LOW;
							else if(PowerLedFlag==2)PwmDuty = PWM_HIGH;
							else PwmDuty = PWM_CLOSE;
						}
					}
					break;
				default:
					break;
			}
			break;
	}
	//PWMDuty_Output(PwmDuty);
}

//==============================================================================================//
//�������ƣ� SynData_Deal
//����˵���� ͬ�����ݴ���͸�λ
//����    �� ��j
//����ֵ  �� ��
//==============================================================================================//
void SynDataReset_Deal(void)
{
	//------------------------------------------------------------------------------------------
	//-------------------------------dim1/dim2����ѧϰģʽ��������------------------------------
	//(DimPercentMin��Χ��1--100,��ôAngleMin��Χ��41-140)
	if(DimPercentMinPre != DimPercentMin)
	{
		DimPercentMinPre = DimPercentMin;
		AngleMin = (100 - DimPercentMin)+ ANGLE_MAX;//ת���ɽǶ�,Ȼ��DimPercentData���ֲ��䣬�Զ���������
	}
	//��λ
	// if((KeyPowerOnVal == KEY_DIMPOWER_LONG) || (KeyPowerOffVal == KEY_POWEROFF_LONG))	
	if((KeyPowerOnVal == KEY_POWERON_LONG) || (KeyPowerOffVal == KEY_POWEROFF_LONG))			
	{
		//mcu_reset_wifi();

		innotech_factroy_led_state_set(0x1);
       	
		//��λmcu��������
		Min3State = 0;				//��λ3���Ӽ���
		PowerLedFlag = 1;			//�ָ�����
		DimPower5sFlag = 1;		//��λ��־
		
		RecLearnFlag = 0;			//�˳�ѧϰģʽ
		//PowerFlag = 1;
		DimPercentData = 100;	//UartData = BRIGHT_INIT;
		DimPercentMin = 1;//10;	  //AngleMin = ANGLE_MIN;
		DimMin = 1;
		//�ϱ�
		Dim1SendWifiMinFlag = 1; 																//�ȷ���С����ֵ
		Dim1SendPercentDataFlag = 1;
	}
	//------------------------------------�ϴ�APP �ӳ�--------------------------------------
	if(++DimPercentDataNumer >= 25)	//ÿ��250ms���һ�� 25->10
	{
//		DimPercentDataNumer = 0;
//		if((DimPercentDataPre1 != DimPercentData) && ((IO_DIMP) && (IO_DIMM)))
//		{
//			DimPercentDataPre1 = DimPercentData;
//			//mcu_dp_value_update(DPID_BRIGHT_VALUE_1,DimPercentData*10); //�ϱ�wifi
//            mcu_dp_value_update(UART_CMD_BRIGHT,DimPercentData);
//		}

		DimPercentDataNumer = 0;
        
        if(MsgSendFlag == TRUE)
        {
			MsgSendFlag = FALSE;
            mcu_dp_value_update(UART_CMD_BRIGHT,DimPercentData);
        }
        else
        {
			if((DimPercentDataPre1 != DimPercentData) && ((IO_DIMP) && (IO_DIMM)))
			{
				DimPercentDataPre1 = DimPercentData;
				//mcu_dp_value_update(DPID_BRIGHT_VALUE_1,DimPercentData*10); //�ϱ�wifi
				mcu_dp_value_update(UART_CMD_BRIGHT,DimPercentData);
			}
        }
	}
}
//==============================================================================================//
//�������ƣ� Uart_Send
//����˵���� dim1��dim2��������
//����    �� ��
//����ֵ  �� ��
//==============================================================================================//
uint16 ChangSendCommand(uint16 command)
{
	datah = 0;datal = 0;
	datah = (command<<8)&0xff00;
	datal = (~command)&0x00ff;
	return((uint16)(datah + datal));
}
uint16 TransSendData(void)
{
	datah = 0;datal = 0;
	if(PowerFlag ==1)											//���λ�����Դ�Ŀ��أ�1Ϊ����0Ϊ��
		datah = (DimPercentData|0x80);	
	else
		datah = (DimPercentData&0x7f);
		
		datal = (~datah)&0x00ff;
		datah = (datah <<8)&0xff00;	
	return((uint16)(datah + datal));
}
void Uart_Send(void)
{
	if(SendFlag == 0)//û�з��ͽ����в�������·��͵�����
	{
		if((Dim1SendSetCommandFlag)&&(McuSendDataFlag == 0))//setcommad
		{
			Dim1SendSetCommandFlag = 0;
			UartData = ChangSendCommand(SET_COMMAND);
			McuSendDataFlag = 1;//3way����
		}
		if((Dim1SendExitCommandFlag)&&(McuSendDataFlag == 0))//exitcommad
		{
			Dim1SendExitCommandFlag = 0;
			UartData = ChangSendCommand(EXIT_COMMAND);
			McuSendDataFlag = 1;//3way����
		}
		if((Dim1SendPowerFlag)&&(McuSendDataFlag == 0))			//powerflag  ����dim2
		{
			Dim1SendPowerFlag = 0;
			UartData = TransSendData();							//��Դ�ı�ת��UartData��ʽ
			McuSendDataFlag = 1;//3way����
		}
		if((Dim1SendWifiMinFlag)&&(McuSendDataFlag == 0))		//minwifi  ����dim2
		{
			Dim1SendWifiMinFlag = 0;								//MIN_COMMAND
			datah = 0;datal = 0;
			datah = ((uint16)MIN_COMMAND<<8)&0xff00;//ָ��
			//datal = DimMin													//��С����ֵ
			UartData = datah + DimMin; 
			McuSendDataFlag = 1;//3way����
		}
		if((Dim1SendPercentDataFlag)&&(McuSendDataFlag == 0))//percentdata  ����dim2
		{
			Dim1SendPercentDataFlag = 0;
			UartData = TransSendData(); 					//��UartData��ʽ
			McuSendDataFlag = 1;//3way����
		}
		
		//��ʱ����20ms
		if((McuSendDataFlag)&&(PowerFirstFlag))//���ڷ��͵�ʱ��ͻȻ��ͻȻ����Ӳ�������жϣ���ʱ���Ա�֤�ȴ�20ms�ٷ���
		{
			if(++SendNumer >= 2)//���ܸ�
			{
				SendNumer = 0;
				McuSendDataFlag = 0;
				SendFlag = 1;				//����
			}
		}
		else
			SendNumer = 0;
	}
}

//ϵͳ�����λ
/*
void AT32_SystemReset(void)
{
	NVIC_SystemReset();
}
*/


