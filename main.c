//********************************************************* 
/*  文件名: main.c
*	功能：  
*   IC:    FT62F088 LQFP32
*   内部： 16M
*   内部： 16M/2T                                
*   说明：  
*
*   参考原理图 
*/
//*********************************************************
#include "header.h"
#include "key.h"
#include "Dim.h"

//**********************************************************
//***********************宏定义*****************************
 
unchar	 FCount;
uint32   Timer1Cnt = 0;
uint8_t  Timer20msFlag = 0;
uint32_t Timer20msCnt = 0;
uint32   Timer2Cnt = 0;
uint32   Timer2CntTemp = 0;

uint8_t  Timer1000msFlag = 0;	// 1S flag for test
uint32_t Timer1000msCnt = 0;	// 1S cnt for test

uint8_t  exint1sflag = 0;	// 1S flag for test
uint32_t exint1scnt = 0;	// 1S cnt for test

//volatile  unchar receivedata[10] =0;
//volatile  unchar senddata	=0;
//volatile  unchar    toSend[11]={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa};
//unchar    i=0;
//volatile unchar    k;

//定时器参数
u8 upside = 0;
u8 idalen = 0;
u8 Timer10msFlag = 0;
uint8 PowerFlag = 0;
uint8 PowerFlag_last = 0;
uint8 PowerFlag_Bak = 0;

//按键状态
uint8 KeyDIMLearnval = 0;
uint8 KeyPowerVal = 0;
uint8 KeyPowerOnVal = 0;
uint8 KeyPowerOffVal = 0;
//调光参数
uint8 DimPercentDataOppose = 0;						// 等于(100-DimPercentData)
uint32 DelayTimer = 0;								// 过0位然后开启硅的延时时间
uint32 DelayTimerPre = 0;							// 过0位然后开启硅的延时时间
uint32 SiOpenTimer = 0;								// 可控硅驱动处于高电平的时间
//延时时间
uint8 PowerFirstNumer = 0;
//型号选择
uint8 PidFlag = 0;									//0:SD06D;1:SD06E
//是否正常ota
uint8 UpdatingFlag = 0;								//1代表正在ota
//工厂测试
uint8 FactoryFlag = 0;
uint8 FactoryState = 0;
uint16 FactoryNumer = 0;
uint8 FactoryFirstFlag = 0;	//工厂模式第一次上电检测

uint32 Timer1CntforTest = 0;

uint8_t ReceiveFinishFlag;

uint8 SiCtlState = 0;										// 可控硅状态控制

uint8_t Led_Switch;
uint8_t Led_Switch_Last;

extern uint8_t travell_flag_ch0;
extern uint8_t travell_flag_ch1;
extern uint8_t travell_flag_ch0_last;
extern uint8_t travell_flag_ch1_last;
extern uint16_t sample_data_load;	
extern uint8_t travell_flag_load;

extern unint tempadcread;

extern uint8 FactoryFlag;
extern uint8 AngleMin;
extern uint8 PowerFirstFlag;
extern uint16 ADCNtcValue;
extern uint8 DimPercentData;									//范围是1-100
extern uint8 DimPercentDataPre;
extern uint8 BufDimPercentData;
extern uint8 TempDimPercentData ;
extern uint8 UsartRecByte;
extern uint8 UsartSendByte;
extern uint8 DimMin;

extern uint8 ZCDIntFlag;
extern uint8 ZCDIntTimer;

extern u8 Timer10msFlag;
extern u8 upside;
extern uint8 PowerFlag;
extern uint8 FadeFlag;
extern uint8 PowerFirstFlag;
//extern TMR_TimerBaseInitType  TMR_TMReBaseStructure;

extern uint8 DimPercentData;
extern uint32 DelayTimer;								// 过0位然后开启硅的延时时间
extern uint32 DelayTimerPre;						// 过0位然后开启硅的延时时间
extern uint32 SiOpenTimer;							// 可控硅持续打开时间

extern uint8 dataBuffer[TEST_BUFEER_SIZE]; 															// 在ram中的位置
extern uint8 FlashDataBuffer[TEST_BUFEER_SIZE];

extern uint16_t sample_data_ch0[30];  
extern uint8_t travell_flag_ch0;
extern uint8_t UartTxBuf[10];
extern uint8_t Switch_Ctrl_Flag;

extern void Led7Run(void);
extern void DimData_Deal(void);

/*-------------------------------------------------
 *  函数名：interrupt ISR
 *	功能：  中断处理函数
 *  输入：  无
 *  输出：  无
 --------------------------------------------------*/
void interrupt ISR(void)				//PIC_HI-TECH使用
{ 
	if(LVDIF)
    {
		LVDIF = 1;
		//EEPROM Write
        Isp_Write(TEST_FLASH_ADDRESS_START,dataBuffer);
    }
	if(EPIF0 & 0x02)	// PA1 EINT1			
	{
		EPIF0 |= 0x02;		//写1清中断1响应标志位 
		//PEIE = 0;
         
        ZCDIntFlag = 1;		///ZCD标志,用于指接上了电源板
		//	延时打开dim时间：{(min-40)percent+4000}/18000*8333}//60HZ，半周期8333us	，约数是为了方便计算
		DelayTimer = DelayTimerPre;											//DelayTimerPre;
		SiOpenTimer = 28532 - DelayTimer;								//SiOpenTimer =(8333-1200-(DelayTimer/4))*4
		//TMRx_ResetPeriod(TMR3,DelayTimer,DISABLE);			//清中断标志,重设周期,从0开始计算,除能定时器
        TIM2_ResetPeriod(DelayTimer,DISABLE);
		if((PowerFlag||FadeFlag)&&(PowerFirstFlag)&&(!UpdatingFlag))	//非ota才允许打开
		{
//			TMR_Cmd(TMR3, ENABLE);												//开调光定时器	
            TIM2CR1 |= 0x1;		
//			EXTI_InitStructure.EXTI_LineEnable = DISABLE; //关闭ZCD外部中断，防止打开可控硅会引起过零点再次触发中断
//			EXTI_Init(&EXTI_InitStructure); 
//			EXTI_ClearIntPendingBit(EXTI_Line6);///<Clear the  EXTI line 6 pending bit一定要清零，否则关闭该中断之后，清不了标志导致一直在这个中断中
			
			SiCtlState = 1;//开
		}  
               
	}
	if(EPIF0 & 0x01)	// PC0 EINT0			
	{
		EPIF0 |= 0x01;		//写1清中断1响应标志位    
        sample_data_load++;
         
    }
        
	if(T1UIE && T1UIF)      // 1mS          	
	{
		T1UIF = 1;        	//写1清零标志位              

        Timer1Cnt++;
        //Load_Scan();		// 1mS
        
        if(Timer1Cnt >= 10)        
        {
			Timer1Cnt = 0;
            Timer10msFlag = TRUE;                          
        }
        Timer20msCnt++;
        if(Timer20msCnt >= 20)      
        {
          Timer20msCnt = 0;
          Timer20msFlag = TRUE;
        }  
        
        Timer1000msCnt++;
        if(Timer1000msCnt >= 1000)      
        {
          Timer1000msCnt = 0;
          Timer1000msFlag = TRUE;
        }  
                         
	}   
	if(T2UIE && T2UIF)                	// 40uS
	{
		T2UIF = 1;                    	//写1清零标志位             

 		if(SiCtlState == 1)
		{
			//GPIO_SetBits(GPIOA,GPIO_Pins_7);
            DIM_ON();
			//TMRx_ResetPeriod(TMR3,SiOpenTimer,ENABLE);	//清中断标志,重设周期,从0开始计算
            TIM2_ResetPeriod(SiOpenTimer,ENABLE);
			SiCtlState = 0;	
		}
		else 
		{
			//GPIO_ResetBits(GPIOA,GPIO_Pins_7);
            DIM_OFF();
			//TMR_Cmd(TMR3, DISABLE);		 //关闭调光定时器		
            TIM2CR1 &= ~(0x1); 
//			EXTI_InitStructure.EXTI_LineEnable = ENABLE; //使能ZCD外部中断
//			EXTI_Init(&EXTI_InitStructure); 
//			EXTI_ClearIntPendingBit(EXTI_Line6);///<Clear the  EXTI line 6 pending bit一定要清零
		}           
	} 
	if(T4UIE && T4UIF)                	
	{
		T4UIF = 1;                    	//写1清零标志位             
		Load_Scan();
	} 
        
 	if(URRXNE && RXNEF)       //接收中断         	
	{        
		UartReceiveData(URDATAL);
        NOP();
	} 
    //----------------------------

}  

/*-------------------------------------------------
 *  函数名: main 
 *	功能：  主函数
 *  输入：  无
 *  输出：  无
 --------------------------------------------------*/
void main(void)
{
	Isp_Read(TEST_FLASH_ADDRESS_START,FlashDataBuffer);										//读flash,先读,防止下面中断干扰	
	SysInitial();				//系统初始化
    IoIntInitial();
    Time1Initial();   //初始化timer1
    Time2Initial();   //初始化timer2
    Time4Initial();   //初始化timer4
	UartInitial();
	WdtInitial();
	AdcInitial(); 
    //LvdInitial();    
    //DelayS(2);  
    
    
	while(1)
	{
        CLRWDT();       //clear WDT
        DelayTimerPre = ((unlong)((unlong)((AngleMin-ANGLE_MAX)*DimPercentDataOppose+ANGLE_START)*31578)/18000);
        
		if(Timer10msFlag)
		{
			Timer10msFlag = 0;
			if(++PowerFirstNumer >= 50)								//上电延时300ms
			{
				PowerFirstNumer = 0;
				PowerFirstFlag = 1;
			}
			Factory_Test_Mode();											//测试模式
			if(PowerFirstFlag == 1)
			{
				Led7Run();		
            }														//5led驱动，工厂模式和非工厂模式共用
			if(FactoryFlag == 0)
			{                      
				KeyDIMLearnval = KeyCheakDIM_PMLearn();			//D+/D-	
				KeyPowerOnVal = KeyCheakPowerOn();				//POWER_ON
				KeyPowerOffVal = KeyCheakPowerOff();			//POWER_OFF
 				
                Connect_With_Switch();
				DimData_Deal();		
                SynDataReset_Deal();                        	                
                UartB_Process();                  
	                                          
			}            
		}
        if(Timer20msFlag)
        {
			Timer20msFlag = 0;            
            innotech_led_process();
            if(0x1 == PowerFlag)
            {
				LED_WHITE_OFF();
            }
			else if(0x0 == PowerFlag)
            {
				LED_WHITE_ON(); 
            }                                     
        }
        
		// for temp test
        if(Timer1000msFlag)
        {
			Timer1000msFlag = 0;        
            
//			UartTxBuf[0] = 0x55;
//			UartTxBuf[1] = 0xAA;
//			UartTxBuf[2] = UART_CMD_DEBUG;
//			UartTxBuf[3] = 111;
//			UartTxBuf[4] = PowerFlag;
//			UartTxBuf[5] = PowerFlag_last;
//			UartTxBuf[6] = travell_flag_ch0;
//			UartTxBuf[7] = sample_data_load;
//			UartTxBuf[8] = travell_flag_load;
//			UartTxBuf[9] = Switch_Ctrl_Flag;                                   
//             
//			mcu_dp_value_update_debug(UART_CMD_DEBUG);    
        }  
                  
    }

    
}