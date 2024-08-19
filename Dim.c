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

//延时
uint16 Count100ms = 0;
//温度控制
uint16 ADCNtcValue = 0;
uint8 ADCCount = 0;
uint16 ADCSum = 0;
uint8 NtcState = 0;										//过温产生触发动作
uint8 NtcNumer = 0;
//灯光渐变
uint8 BufDimPercentData = 1;
uint8 TempDimPercentData = 1;
uint8 FadeFlag = 0;										//是否允许渐变
uint8 FadeNumer = 0;
//电源灯的相关变量
uint8 delaynumer = 0;
uint8 WifiWorkState = WIFI_SATE_UNKNOW;	//wifi未知模式
uint8 PowerLedNumer = 0;
uint16 PowerLedNumer1 = 0;	//灯亮时间计时，wifi 3分钟计时
uint8 LedNum = 0;		
uint8 PowerLedFlag = 1;			//0:灭 1：低亮 2：高亮
uint8 LedState = 0;					//灯逻辑控制
uint8 LedStatePre = 0;
//wifi测试
uint8 WifiPowerFlag = 0;
uint8 WifiTestFlag = 0;
uint8 Min3State = 0;
//临时变量
uint16 datah;
uint16 datal;
volatile uint8 cheakh;
volatile uint8 cheakl;
//学习模式
uint16 LearnNumer = 0;
uint8 LearnNumer1 = 0;
uint8 RecLearnFlag = 0;
uint8 RecDimPercent = 0;											//保留3way接收前系统的亮度值
uint8 RecDimPercentMin = 0;										//保留3way接收前的最小亮度值

// 3-way串口接收数据
uint8 RecFinishFlag = 0;											//接收到一个完整数据
uint8 RecFlag = 0;														//开始模拟接收的标志
uint8 SendFlag = 0;														//开始模拟发送的标志
uint8 ZCDIntFlag = 0;													//过零中断产生的标志
uint8 ZCDIntTimer = 0;												//过零中断来临之后延时的时间
uint16 RecData = 0;														// 串口接收数据
uint16 RecDataBuf = 0;
uint8 RecDateBitCounter = 0;									// 接收第几位数据
uint8 RecDateBitFilterNumer = 0;							// 每接收一bit定时中断次数
uint16 SendData = 0;
uint8 SendDateBitCounter = 0;				
uint8 SendMode = 0;				
uint8 SendDateBitFilterNumer = 0;			
uint16 UartData = BRIGHT_INIT;								// 用来存储串口接收或者发送数据,默认亮度100%
//调光参数
uint8 DimPercentData  = 100;									//范围是1-100
uint8 DimPercentDataPre = 100;								//检测亮度值是否改变，然后发送给另一个dimmer同步的
uint8 DimPercentDataPre1 = 100;								//检测亮度值是否改变，然后每隔100ms发送给app端实现同步的
uint8 DimPercentDataNumer = 0;								//延时发送app亮度值
uint8 AngleMin = ANGLE_MIN;   								// 半周期180度,默认140度最小亮度
uint8 DimPercentMin = 1;											//范围是1-100，默认是1,用于调学习模式最小亮度
uint8 DimPercentMinPre = 1;										//范围是1-100，默认是1,用于调学习模式最小亮度
uint8 DimMin = 1;															//来自dimwifi的最小亮度值，不同于DimPercentMin
		
//串口命令和其他标志
uint8 SetCommadFlag = 0;											//来自串口的进入学习模式的命令
uint8 RecExitLearnFlag = 0;										//退出学习模式的命令
uint8 Dim1SendPowerFlag = 0;									//发送电源标志
uint8 Dim1SendPercentDataFlag = 0;						//发送亮度百分比标志
uint8 Dim1SendSetCommandFlag = 0;							//发送进入学习模式的标志
uint8 Dim1SendExitCommandFlag = 0;						//发送退出学习模式的标志
uint8 Dim1SendWifiMinFlag = 0;								//发送来自wifi的最小亮度值标志
uint8 McuSendDataFlag = 0;										//这个标志延时30ms才清零

uint8 PowerFirstFlag = 0;											//第一次上电延时300ms标志	
uint8 InitFlag = 0;														//第一次上电5s
uint8 PowerFirstWifiFlag = 0;									//wifi第一次上电
uint8 Min3Flag = 0;														//3分钟延时
uint8 DimPower5sFlag = 0;											//产生了复位动作
//普通开关标志
uint8 IsOrdSwitchFlag = 0;										//是否是普通开关的标志
uint8 OrdSwitchPowerFlag = 0;									//普通开关开关电源的标志
//普通开关识别
uint8 RecognizState = 0;
uint8 RecognizNumer = 0;
uint8 RecognizNumer1 = 0;
uint8 HighorLowFlag = 0;		//1为高，2为低
uint8 OrdCheakFlag = 0;			//每次3-way刚发送完需要延时1s去检测普通开关标志
//工厂测试
uint8 FactoryFlag = 0;
uint8 FactoryState = 0;
uint16 FactoryNumer = 0;
uint8 FactoryFirstFlag = 0;	//工厂模式第一次上电检测
//pwm
uint8 PwmDuty = PWM_CLOSE;
uint8 SendNumer = 0;				//计时30ms

uint8 KeyPowerOffFlag = FALSE;
uint8 MsgSendFlag = FALSE;
//==============================================================================================//
//函数名称： DimData_Deal
//函数说明： 处理dim1和dim2数据，电源开关，电源+、-
//参数    ： 无
//返回值  ： 无
//==============================================================================================//
			
void DimData_Deal(void)
{
	//---------------------------------dim2的数据处理和上报-------------------------------------
	//接收到的数据
	
	//------------------------------------------------------------------------------------------
	//---------------------------------dim1? 氖?据处理和上??-------------------------------------
	//if(((KeyPowerVal == KEY_DIMPOWER_SHORT)||(OrdSwitchPowerFlag)||(NtcState))&&(!RecLearnFlag))//dim1的电源开关,学习模式下不允许开 
	//if((KeyPowerOnVal == KEY_DIMPOWER_SHORT) || (KeyPowerOffVal == KEY_POWEROFF_SHORT))//dim1的电源开关,学习模式下不允许开 
	if((KeyPowerOnVal == KEY_POWERON_SHORT) || (KeyPowerOnVal == KEY_POWERON_DOUBLE) || (KeyPowerOffVal == KEY_POWEROFF_SHORT))
	{
		//PowerFlag = !PowerFlag;													//最高位代表电源的开关，1为开，0为关
		
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

		//上报
		//mcu_dp_bool_update(DPID_SWITCH_LED_1,PowerFlag);//上报给wifi
        /*
		if(!OrdSwitchPowerFlag)
			Dim1SendPowerFlag = 1;													//发送给dim2
		
		OrdSwitchPowerFlag = 0;
		NtcState = 0;
        */
	}
    DimPercentDataPre = DimPercentData;

//	if(PowerFlag)//开电源
//	{	
//		
//		if((KeyDIMLearnval)&&(KeyDIMLearnval != KEY_DIM_BOTH_LONG)&&(!RecLearnFlag))//按键改变亮度,不是学习模式才有效//不是两个长按
//		{
//			FrameSendFlag = 1;
//			if(KeyDIMLearnval == KEY_DIMP_SHORT)													//+单击
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
//			else if(KeyDIMLearnval == KEY_DIMP_LONG)							//+长按
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
//			else if(KeyDIMLearnval == KEY_DIMM_SHORT)									//-单击
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
//			else if(KeyDIMLearnval == KEY_DIMM_LONG)							//-长按
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
//			//上报,数据有改变就上报
//			if(DimPercentDataPre != DimPercentData)
//			{
//				DimPercentDataPre = DimPercentData;
////				mcu_dp_value_update(DPID_BRIGHT_VALUE_1,DimPercentData*10); //上报wifi
//				Dim1SendPercentDataFlag = 1;																//上报dim2
//			}													
//		}
//		else
//			delaynumer = 0;				
//	}
//	else
//	{
//		delaynumer = 0;
//	}


		
	if((KeyDIMLearnval)&&(KeyDIMLearnval != KEY_DIM_BOTH_LONG)&&(!RecLearnFlag))//按键改变亮度,不是学习模式才有效//不是两个长按
	{
		//FrameSendFlag = 1;
		if(PowerFlag == OFF)
		{				
			PowerFlag = ON;	
            mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
			RELAY_TOGGLE();
										
			//mcu_dp_value_update(UART_CMD_POWER,PowerFlag);		
		}
		if(KeyDIMLearnval == KEY_DIMP_SHORT)													//+单击
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
		else if(KeyDIMLearnval == KEY_DIMP_LONG)							//+长按
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
		else if(KeyDIMLearnval == KEY_DIMM_SHORT)									//-单击
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
		else if(KeyDIMLearnval == KEY_DIMM_LONG)							//-长按
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
		
		
		//上报,数据有改变就上报
		if(DimPercentDataPre != DimPercentData)
		{
			DimPercentDataPre = DimPercentData;
			Dim1SendPercentDataFlag = 1;																//上报dim2
		}													
	}
	else
		delaynumer = 0;				


}
//==============================================================================================//
//函数名称： Led5Run
//函数说明： 灯显示
//参数    ： 无
//返回值  ： 无
//==============================================================================================//
void Led7Run(void)
{
	//百分比灯
	if(DimPercentData > 100) 					//防错
		DimPercentData = 100;
	//--------------------------------------------
	//渐变控制
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
	//7led控制
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
//函数名称： NTC_Ctl
//函数说明： 温度控制
//参数    ： 无
//返回值  ： 无
//==============================================================================================//
void NTC_Ctl(void)
{

}

//==============================================================================================//
//函数名称： Isp_Read，Isp_Write,Isp_Earse
//函数说明： FLASH读写功能,采取页读写的方式
//参数    ： 无
//返回值  ： 无
//==============================================================================================//
uint8 dataBuffer[TEST_BUFEER_SIZE]; 															// 在ram中的位置
uint8 FlashDataBuffer[TEST_BUFEER_SIZE];
void Isp_Write(u32 WriteAddr,u8 *pBuffer)
{
	u16 i;
	if(DimPercentData > 100) 					//防错
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
//	FLASH_ErasePage(WriteAddr);//上电已经擦除，这里不需要了
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
		pBuffer[i] = FLASH_ReadByte(ReadAddr);//读取一个字节
		ReadAddr++;//偏移1个字节.	
	}
	PowerFlag = 0;
	if(pBuffer[0]==0xaa)//代表数据被保存过
	{
		//PowerFlag = pBuffer[1];
		DimPercentData = pBuffer[2];
		DimPercentMin = pBuffer[3];
		DimMin = pBuffer[4];
		PowerLedFlag = pBuffer[5];
		DimPercentDataOppose = 100 - DimPercentData;//初始化,如果没有就会默认是0，导致一上电就会闪烁一下
	}
    */
	for(i=0;i<TEST_BUFEER_SIZE;i++)
	{
		pBuffer[i] = EEPROMread(i); ;//读取一个字节
	}
	PowerFlag = 0;	// 上电默认关灯
	if(pBuffer[0]==0xaa)//代表数据被保存过
	{
		//PowerFlag = pBuffer[1];	// 恢复掉电前状态
		//DimPercentData = pBuffer[2];
		DimPercentMin = pBuffer[3];
		DimMin = pBuffer[4];
		PowerLedFlag = pBuffer[5];
		DimPercentDataOppose = 100 - DimPercentData;//初始化,如果没有就会默认是0，导致一上电就会闪烁一下

		//LED1_ON();
	}    
}



//==============================================================================================//
//函数名称： Uart_3way
//函数说明： 模拟3way串口的收发
//参数    ： 无
//返回值  ： 无
//==============================================================================================//
void Uart_3way(void)
{

}

//==============================================================================================//
//函数名称： OrdSwitch_Recognize
//函数说明： 普通开关识别
//参数    ： 无
//返回值  ： 无
//==============================================================================================//
void OrdSwitch_Recognize(void)
{

}
//==============================================================================================//
//函数名称： Factory_Test_Mode
//函数说明： 工厂测试模式
//参数    ： 无
//返回值  ： 无
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
//函数名称： Tonggle_TimeSet
//函数说明： 灯翻转时间,低亮度闪烁
//参数    ： 无
//返回值  ： 无
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
//函数名称： PowerLedRun
//函数说明： 电源灯显示
//参数    ： 无
//返回值  ： 无
//==============================================================================================//
void PowerLedRun(void)//电源灯
{
	//WifiWorkState = mcu_get_wifi_work_state();	//获取wifi工作状
	
	if(RecLearnFlag)			//学习模式
		LedStatePre = 1;			
	else if(0 == InitFlag)//首次上电闪烁5s
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
					//第一次上电，如果出现这个状态，代表复位一次wifi,要加标志否者3min过后没有配上网会停留在这里不亮电源灯
					if((WifiWorkState == WIFI_LOW_POWER)&&(PowerFirstWifiFlag == 0))
					{
						//if(PowerFirstWifiFlag == 0)
						{
							PowerFirstWifiFlag = 1;
							//mcu_reset_wifi();
						}
					}
					else if(DimPower5sFlag)//提醒5s复位时间到了
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
						else if(WifiWorkState == AP_STATE)								//wifi AP模式
						{
							Tonggle_TimeSet(100);
						}
						if(++PowerLedNumer1 >= 18000)											//3min
						{
							PowerLedNumer1 = 0;
							Min3Flag = 1;//3min成立标志
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
						else	//ble等一些的控制
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
//函数名称： SynData_Deal
//函数说明： 同步数据处理和复位
//参数    ： 无j
//返回值  ： 无
//==============================================================================================//
void SynDataReset_Deal(void)
{
	//------------------------------------------------------------------------------------------
	//-------------------------------dim1/dim2进入学习模式重新量化------------------------------
	//(DimPercentMin范围是1--100,那么AngleMin范围是41-140)
	if(DimPercentMinPre != DimPercentMin)
	{
		DimPercentMinPre = DimPercentMin;
		AngleMin = (100 - DimPercentMin)+ ANGLE_MAX;//转化成角度,然后DimPercentData保持不变，自动重新量化
	}
	//复位
	// if((KeyPowerOnVal == KEY_DIMPOWER_LONG) || (KeyPowerOffVal == KEY_POWEROFF_LONG))	
	if((KeyPowerOnVal == KEY_POWERON_LONG) || (KeyPowerOffVal == KEY_POWEROFF_LONG))			
	{
		//mcu_reset_wifi();

		innotech_factroy_led_state_set(0x1);
       	
		//复位mcu基本参数
		Min3State = 0;				//复位3分钟计算
		PowerLedFlag = 1;			//恢复低亮
		DimPower5sFlag = 1;		//复位标志
		
		RecLearnFlag = 0;			//退出学习模式
		//PowerFlag = 1;
		DimPercentData = 100;	//UartData = BRIGHT_INIT;
		DimPercentMin = 1;//10;	  //AngleMin = ANGLE_MIN;
		DimMin = 1;
		//上报
		Dim1SendWifiMinFlag = 1; 																//先发最小亮度值
		Dim1SendPercentDataFlag = 1;
	}
	//------------------------------------上传APP 延迟--------------------------------------
	if(++DimPercentDataNumer >= 25)	//每隔250ms检测一次 25->10
	{
//		DimPercentDataNumer = 0;
//		if((DimPercentDataPre1 != DimPercentData) && ((IO_DIMP) && (IO_DIMM)))
//		{
//			DimPercentDataPre1 = DimPercentData;
//			//mcu_dp_value_update(DPID_BRIGHT_VALUE_1,DimPercentData*10); //上报wifi
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
				//mcu_dp_value_update(DPID_BRIGHT_VALUE_1,DimPercentData*10); //上报wifi
				mcu_dp_value_update(UART_CMD_BRIGHT,DimPercentData);
			}
        }
	}
}
//==============================================================================================//
//函数名称： Uart_Send
//函数说明： dim1向dim2发送数据
//参数    ： 无
//返回值  ： 无
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
	if(PowerFlag ==1)											//最高位代表电源的开关，1为开，0为关
		datah = (DimPercentData|0x80);	
	else
		datah = (DimPercentData&0x7f);
		
		datal = (~datah)&0x00ff;
		datah = (datah <<8)&0xff00;	
	return((uint16)(datah + datal));
}
void Uart_Send(void)
{
	if(SendFlag == 0)//没有发送进行中才允许更新发送的数据
	{
		if((Dim1SendSetCommandFlag)&&(McuSendDataFlag == 0))//setcommad
		{
			Dim1SendSetCommandFlag = 0;
			UartData = ChangSendCommand(SET_COMMAND);
			McuSendDataFlag = 1;//3way发送
		}
		if((Dim1SendExitCommandFlag)&&(McuSendDataFlag == 0))//exitcommad
		{
			Dim1SendExitCommandFlag = 0;
			UartData = ChangSendCommand(EXIT_COMMAND);
			McuSendDataFlag = 1;//3way发送
		}
		if((Dim1SendPowerFlag)&&(McuSendDataFlag == 0))			//powerflag  发给dim2
		{
			Dim1SendPowerFlag = 0;
			UartData = TransSendData();							//电源改变转成UartData格式
			McuSendDataFlag = 1;//3way发送
		}
		if((Dim1SendWifiMinFlag)&&(McuSendDataFlag == 0))		//minwifi  发给dim2
		{
			Dim1SendWifiMinFlag = 0;								//MIN_COMMAND
			datah = 0;datal = 0;
			datah = ((uint16)MIN_COMMAND<<8)&0xff00;//指令
			//datal = DimMin													//最小亮度值
			UartData = datah + DimMin; 
			McuSendDataFlag = 1;//3way发送
		}
		if((Dim1SendPercentDataFlag)&&(McuSendDataFlag == 0))//percentdata  发给dim2
		{
			Dim1SendPercentDataFlag = 0;
			UartData = TransSendData(); 					//成UartData格式
			McuSendDataFlag = 1;//3way发送
		}
		
		//延时发送20ms
		if((McuSendDataFlag)&&(PowerFirstFlag))//正在发送的时候突然来突然进入硬件串口中断，此时可以保证等待20ms再发送
		{
			if(++SendNumer >= 2)//不能改
			{
				SendNumer = 0;
				McuSendDataFlag = 0;
				SendFlag = 1;				//发送
			}
		}
		else
			SendNumer = 0;
	}
}

//系统软件复位
/*
void AT32_SystemReset(void)
{
	NVIC_SystemReset();
}
*/


