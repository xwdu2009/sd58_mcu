/*-----------------------------------------------------------------------------
Copyright 2019-2022 INNOTECH Technology Co.,Ltd All Rights Reserved.
FileName: public.c
Author: 
Version:V1.0.0
Date:
Description: 公共函数
History:<author> <time> <version > <desc>
-----------------------------------------------------------------------------*/

#include "header.h"

//串口处理数据
uint8_t UartRxStep = 0;        //串口接收步骤
uint8_t UartRxLen = 0;             //串口接收长度
uint8_t UartRxBuf[10];             //串口接收缓存
uint8_t ReceiveFinishFlag = 0; //串口接收完成标志
uint8_t UartRecvData0 = 0;
uint8_t UartRecvData1 = 0;
uint8_t UartRecvData2 = 0;
uint8_t UartRecvData3 = 0;
uint8_t UartTxLen = 0;             //3-Way串口发送长度
uint8_t UartTxBuf[10];              //3-Way串口发送缓存

uint8_t ConnectState = 0;
uint8_t ack_setup_mode_state = 0;

// Traveller
uint8_t sample_cnt = 0;
uint16_t sample_data_ch0[30];  
//uint16_t sample_data_ch1[10];
uint16_t sample_data_load = 0;	
uint8_t travell_flag_ch0;
uint8_t travell_flag_ch1;
uint8_t travell_flag_load;
uint8_t travell_flag_ch0_last;
uint8_t travell_flag_ch1_last;
uint8_t Dimmer_Init_Flag = TRUE;

unint tempadcread = 0;

uint8_t FrameSendFlag = 0;

uint16_t LoadLowCnt = 0;
uint8_t LoadOffHaveDetected = 0;

uint8_t Switch_Ctrl_Flag = 0xFF;
uint8_t Switch_Ctrl_Flag_Last = 0xFF;

extern uint8 PowerFlag;
extern uint8 PowerFlag_last;
extern uint8 DimPercentData;
extern uint8 KeyPowerOffFlag;
extern uint8 MsgSendFlag;
/*-------------------------------------------------
 *  函数名：POWER_INITIAL
 *	功能：  上电系统初始化
 *  输入：  无
 *  输出：  无
 --------------------------------------------------*/	
void SysInitial(void) 
{
	 
	OSCCON = 0B01110001;		//WDT 32KHZ IRCF=111=16MHz
												//Bit0=1,系统时钟为内部振荡器
												//Bit0=0,时钟源由FOSC<2：0>决定即编译选项时选择
	

	INTCON = 0B01000000;						//暂禁止所有中断
    
	PORTA = 0B00000000;		
	TRISA = 0B10010010;		//PA输入输出 0-输出 1-输入
	WPUA = 0B00000000;     	//PA端口上拉控制 1-开上拉 0-关上拉
    WPDA = 0B00000000;     	//PA端口上拉控制 1-开下拉 0-关下拉

	// PORTB = 0B10111100;	
	PORTB = 0B11111100;		// PB6 white led init->1
	TRISB = 0B00000010;		//PB输入输出 0-输出 1-输入
	WPUB = 0B00000000;     	//PB端縮上拉控制 1-开上拉 0-关上拉   
	WPDB = 0B00000000;     	//PB端口上拉控制 1-开下拉 0-关下拉

	PORTC = 0B01110010; 	
	//TRISC = 0B00001000;		//PC输入输出 0-输出 1-输入
    TRISC = 0B00001001;
	WPUC = 0B00001000;     	//PC端口上拉控制 1-开上拉 0-关上拉
	WPDC = 0B00000000;     	//PC端口上拉控制 1-开下拉 0-关下拉

    PORTD = 0B00000000;		
	TRISD = 0B00001110;		//PD输入输出 0-输出 1-输入
	WPUD = 0B00000000;     	//PD端口上拉控制 1-开上拉 0-关上拉
    
	WPDD = 0B00000000;     	//PD端口上拉控制 1-开下拉 0-关下拉
    
    PSRC0  = 0B11111111;  	//PORTA,PORTB源电流设置最大
    //BIT7~BIT6:PORTB[7:4]源电流能力控制,BIT5~BIT4:PORTB[3:0]源电流能力控制 
    //BIT3~BIT2:PORTA[7:4]源电流能力控制,BIT1~BIT0:PORTA[3:0]源电流能力控制
    
    PSRC1  = 0B11111111;    //PORTC,PORTD源电流设置最大    
    //BIT7~BIT6:PORTD[7:4]源电流能力控制,BIT5~BIT4:PORTD[3:0]源电流能力控制 
    //BIT3~BIT2:PORTC[7:4]源电流能力控制,BIT1~BIT0:PORTC[3:0]源电流能力控制
    
    PSINK0 = 0B11111111;  	//PORTA灌电流设置最大 0:最小，1:最大
    PSINK1 = 0B11111111; 	//PORTB灌电流设置最大 0:最小，1:最大
    PSINK2 = 0B11111111;	//PORTC灌电流设置最大 0:最小，1:最大
    PSINK3 = 0B11111111;	//PORTD灌电流设置最大 0:最小，1:最大
	
    ANSELA = 0B00000000;    //全为数字管脚
 
}
/*-------------------------------------------------
 *	函数名称：DelayUs
 *	功能：   短延时函数 --16M-2T--大概快1%左右.
 *	输入参数：Time 延时时间长度 延时时长Time Us
 *	返回参数：无 
 -------------------------------------------------*/
void DelayUs(unsigned char Time)
{
	unsigned char a;
	for(a=0;a<Time;a++)
	{
		NOP();
	}
}                  
/*-------------------------------------------------
 *	函数名称：DelayMs
 *	功能：   短延时函数
 *	输入参数：Time 延时时间长度 延时时长Time ms
 *	返回参数：无 
 -------------------------------------------------*/
//void DelayMs(unsigned char Time)
void DelayMs(unsigned short Time)
{
	unsigned char a,b;
	for(a=0;a<Time;a++)
	{
		for(b=0;b<5;b++)
		{
		 	DelayUs(197); 	//快1%
		}
	}
}
/*-------------------------------------------------
 *	函数名称：DelayS
 *	功能：   短延时函数
 *	输入参数：Time 延时时间长度 延时时长Time S
 *	返回参数：无 
 -------------------------------------------------*/
void DelayS(unsigned char Time)
{
	unsigned char a,b;
	for(a=0;a<Time;a++)
	{
		for(b=0;b<10;b++)
		{
		 	DelayMs(100); 
		}
	}
}

/*-------------------------------------------------
 *  函数名: IO_INT_INITIAL
 *	功能：  主函数
 *  输入：  无
 *  输出：  无
 --------------------------------------------------*/
void IoIntInitial(void)
{

//	EPS0 = 0B00000000; 	//选择PA1管脚中断
//    //Px0~Px3中断管脚选择
//    EPS1 = 0B00000000;
//    //Px4~Px7中断管脚选择
//    
//    ITYPE0 = 0B00001100;//双沿中断
//    ITYPE1 = 0B00000000;
//    
//    EPIE0 = 0B00000010;//使能中断1
// 	EPIF0 = 0xFF;					//写1清中断响应标志位 
//   
//	PEIE = 1;							//使能外部中断
//	GIE = 1;							//开总中断
  

	EPS0 = 0B00000010; 	//选择PA1,PC0管脚中断         
                        // 1:0 10 PC0  
                        // 3:2 00 PA1    
    //Px0~Px3中断管脚选择
    EPS1 = 0B00000000;
    //Px4~Px7中断管脚选择
    
    ITYPE0 = 0B00001101;//PA1 双边沿   3:2 11
                        //PC0 上升沿   1:0 01
    ITYPE1 = 0B00000000;
    
    EPIE0 = 0B00000011;//EINT0 EINT1 使能中断0 1
    
 	EPIF0 = 0xFF;					//写1清中断响应标志位 
   
	PEIE = 1;							//使能外部中断
	GIE = 1;							//开总中断    
    
}

/*-------------------------------------------------
 *  函数名：Time1Initial
 *	功能：  上电系统初始化
 *  输入：  无
 *  输出：  无
 --------------------------------------------------*/		
void Time1Initial(void)
{
	PCKEN |=0B00000010;    //使能timer1时钟模块
    CKOCON=0B00100000;
    TCKSRC=0B00000001;    //TIM1时钟为HIRC的2倍频
    //BIT7低频内振模式：1 = 256K 振荡频率模式,0 = 32K 振荡频率模式
    //BIT6~BIT4TIM2时钟源选择位
			//值	时钟源
			//0	系统时钟/主时钟
			//1	HIRC
			//2	XT时钟/外部时钟
			//3	HIRC的2倍频
			//4	XT时钟/外部时钟的2倍频
			//5	LIRC
			//6	LP时钟/外部时钟
			//7	LP时钟/外部时钟的2位频
		//BIT3:保留位
		//BIT2~BIT0:TIM1时钟源选择位
			//值	时钟源
			//0	系统时钟/主时钟
			//1	HIRC
			//2	XT时钟/外部时钟
			//3	HIRC的2倍频
			//4	XT时钟/外部时钟的2倍频
			//5	LIRC
			//6	LP时钟/外部时钟
			//7	LP时钟/外部时钟的2位频


    TIM1CR1 =0B10000101;  //预载允许，边沿对齐向上计数器，计数器使能
    //BIT7:自动预装载允许位
			//0：TIM1_ARR寄存器没有缓冲，它可以被直接写入；
			//1：TIM1_ARR寄存器由预装载缓冲器缓冲。
		//BIT6~BIT5:选择对齐模式
			//00：边沿对齐模式。计数器依据方向位(DIR)向上或向下计数。
			//01：中央对齐模式1。计数器交替地向上和向下计数。配置为输出的通道(TIM1_CCMRx寄存器中CciS=00)的输出比较中断标志位，只在计数器向下计数时被置1。 
			//10:中央对齐模式2。计数器交替地向上和向下计数。配置为输出的通道(TIM1_CCMRx寄存器中CciS=00)的输出比较中断标志位，只在计数器向上计数时被置1。
			//11：中央对齐模式3。计数器交替地向上和向下计数。配置为输出的通道(TIM1_CCMRx寄存器中CciS=00)的输出比较中断标志位，在计数器向上和向下计数时均被置1。
		//BIT4:方向
			//0：计数器向上计数；
			//1：计数器向下计数。
		//BIT3:单脉冲模式
			//0：在发生更新事件时，计数器不停止；
			//1：在发生下一次更新事件(清除CEN位)时，计数器停止。
		//BIT2:更新请求源
			//0：如果UDIS允许产生更新事件，则下述任一事件产生一个更新中断：
			//寄存器被更新(计数器上溢/下溢)
			//软件设置UG位
			//时钟/触发控制器产生的更新
			//1：如果UDIS允许产生更新事件，则只有当下列事件发生时才产生更新中断，并UIF置1：
			//寄存器被更新(计数器上溢/下溢)
		//BIT1:	禁止更新
			//0：一旦下列事件发生，产生更新(UEV)事件：
			//计数器溢出/下溢
			//产生软件更新事件
			//时钟/触发模式控制器产生的硬件复位被缓存的寄存器被装入它们的预装载值。
			//1：不产生更新事件，影子寄存器(ARR、PSC、CCRx)保持它们的值。如果设置了UG位或时钟/触发控制器发出了一个硬件复位，则计数器和预分频器被重新初始化。
		//BIT0	允许计数器
			//0：禁止计数器；
			//1：使能计数器。


    //TIM1CR2 =0B00000000;
    //BIT7：TI1选择
			//0：CC1输入管脚连到TI1(数字滤波器的输入)；
			//1：CC1、CC2和CC3管脚经异或后连到TI1。
		//BIT6~BIT4：主模式选择,该位用于选择在主模式下送到ADC或其它从定时器的同步信息(TRGO)。可能的组合如下：
			//000：复位 – TIM1_EGR寄存器的UG位被用于作为触发输出(TRGO)。如果触发输入(时钟/触发控制器配置为复位模式)产生复位，则TRGO上的信号相对实际的复位会有一个延迟。        
			//001：使能 – 计数器使能信号被用于作为触发输出(TRGO)。其用于启动多个定时器或ADC，以便控制在一段时间内使能从定时器或ADC。计数器使能信号是通过CEN控制位和门控模式下的触发输入信号的逻辑或产生。除非选择了主/从模式(见TIM1_SMCR寄存器中MSM位的描述)， 当计数器使能信号受控于触发输入时，TRGO上会有一个延迟。                                                 
			//010：更新 – 更新事件被选为触发输入(TRGO)。
			//011：比较脉冲(MATCH1) – 一旦发生一次捕获或一次比较成功，当CC1IF标志被置1时(即使它已经为高)，触发输出送出一个正脉冲(TRGO)。                                                                               
			//100：比较 – OC1REF信号被用于作为触发输出(TRGO)。
			//101：比较 – OC2REF信号被用于作为触发输出(TRGO)。
			//110：比较 – OC3REF信号被用于作为触发输出(TRGO)。
			//111：比较 – OC4REF信号被用于作为触发输出(TRGO)。
		//BIT3:D保留
		//BIT2：捕获/比较控制位的更新控制选择
			//0：当捕获/比较的控制位为预装载时(CCPC=1)，只有在COMG位置1的时候这些控制位才被更新 ；                                                                                                                                                                       1：当捕获/比较的控制位为预装载时(CCPC=1)，只有在COMG位置1或TRGI发生上升沿的时候这些控制位才被更新；
			//注：该位只对拥有互补输出的通道有效。
		//BIT1:保留，被硬件设为0。
		//BIT0：捕获/比较预装载控制位
			//0：CCIE，CCINE，CCiP，CCiNP位(TIM1_CCERx寄存器)和OCIM位(TIM1_CCMRx寄存器)
			//不是预装载的；
			//1：CCIE，CCINE，CCiP，CCiNP和OCIM位是预装载的；设置该位后，它们只在设置了
			//COMG位(TIM1_EGR寄存器)后被更新。
			//注：该位只对具有互补输出的通道起作用。


    //TIM1SMCR=0B00000000;
	    //BIT7：主/从模式
			//0：无作用；
			//1：触发输入(TRGI)上的事件被延迟了，以允许定时器1与它的从定时器间的完美同步(通过TRGO)。

		//BIT6~BIT4：触发选择,这3位选择用于选择同步计数器的触发输入。
			//000：内部触发ITR0连接到TIM6 TRGO (此设计没有TIM6，所以固定接0)	
			//001：保留	
			//010：内部触发ITR2连接到TIM5 TRGO(此设计没有TIM5，所以固定接0)
			//011：保留	
			//100：TI1的边沿检测器(TI1F_ED)
			//101：滤波后的定时器输入1(TI1FP1)
			//110：滤波后的定时器输入2(TI2FP2)
			//111：外部触发输入(ETRF)
			//注：这些位只能在未用到(如SMS=000)时被改变，以避免在改变时产生错误的边沿检测。
		//BIT3:保留
		//BIT2~BIT0：时钟/触发/从模式选择,当选择了外部信号，触发信号(TRGI)的有效边沿与选中的外部输入极性相关(见输入控制寄存器和控制寄存器的说明)
			//000：时钟/触发控制器禁止 – 如果CEN=1，则预分频器直接由内部时钟驱动。
			//001：编码器模式1 – 根据TI1FP1的电平，计数器在TI2FP2的边沿向上/下计数。
			//010：编码器模式2 – 根据TI2FP2的电平，计数器在TI1FP1的边沿向上/下计数。
			//011：编码器模式3 – 根据另一个输入的电平，计数器在TI1FP1和TI2FP2的边沿向上/下计数。
			//100：复位模式 – 在选中的触发输入(TRGI)的上升沿时重新初始化计数器，并且产生一个更新寄存器的信号。
			//101：门控模式 – 当触发输入(TRGI)为高时，计数器的时钟开启。一旦触发输入变为低，则计数器停止(但不复位)。计数器的启动和停止都是受控的。
			//110：触发模式 – 计数器在触发输入TRGI的上升沿启动(但不复位)，只有计数器的启动是受控的。
			//111：外部时钟模式1 – 选中的触发输入(TRGI)的上升沿驱动计数器。
			//注：如果TI1F_ED被选为触发输入(TS=100)时，不要使用门控模式。这是因为TI1F_ED在每次
			//TI1F变化时只是输出一个脉冲，然而门控模式是要检查触发输入的电平。

    //TIM1ETR =0B00000000;
    //BIT7：外部触发极性,该位决定是ETR还是ETR 用于触发操作。
			//0：ETR不反相，即高电平或上升沿有效；
			//1：ETR反相，即低电平或下降沿有效。
		//BIT6：外部时钟使能,该位用于使能外部时钟模式2。
			//0：禁止外部时钟模式2；
			//1：使能外部时钟模式2，计数器的时钟为ETRF的有效沿。
			//注1：ECE位置1的效果与选择把TRGI连接到ETRF的外部时钟模式1相同(TIM1_SMCR寄存器中，SMS=111，TS=111)。
			//注2：外部时钟模式2可与下列模式同时使用：触发标准模式；触发复位模式；触发门控模式。但是，此时TRGI决不能与ETRF相连(TIM1_SMCR寄存器中，TS不能为111)。
			//注3：外部时钟模式1与外部时钟模式2同时使能，外部时钟输入为ETRF。
		//BIT5~BIT4：外部触发预分频器,外部触发信号EPRP的频率最大不能超过fMASTER/4。可用预分频器来降低ETRP的频率，当
			//EPRP的频率很高时，它非常有用：
			//00：预分频器关闭；
			//01：EPRP的频率/2；
			//02：EPRP的频率/4；
			//03：EPRP的频率/8。
		//BIT3~BIT0：外部触发滤波器选择,该位域定义了ETRP的采样频率及数字滤波器长度。数字滤波器由一个事件计数器组成，它记录到N个事件后会产生一个输出的跳变：
			//0000：无滤波器，以fMASTER采样	1000：采样频率fSAMPLING=fMASTER/8，N=6
			//0001：采样频率fSAMPLING=fMASTER，N=2	1001：采样频率fSAMPLING=fMASTER/8，N=8
			//0010：采样频率fSAMPLING=fMASTER，N=4	1010：采样频率fSAMPLING=fMASTER/16，N=5
			//0011：采样频率fSAMPLING=fMASTER，N=8	1011：采样频率fSAMPLING=fMASTER/16，N=6
			//0100：采样频率fSAMPLING=fMASTER/2，N=6	1100：采样频率fSAMPLING=fMASTER/16，N=8
			//0101：采样频率fSAMPLING=fMASTER/2，N=8	1101：采样频率fSAMPLING=fMASTER/32，N=5
			//0110：采样频率fSAMPLING=fMASTER/4，N=6	1110：采样频率fSAMPLING=fMASTER/32，N=6
			//0111：采样频率fSAMPLING=fMASTER/4，N=8	1111：采样频率fSAMPLING=fMASTER/32，N=8

    TIM1IER =0B00000001;
    //BIT7：允许刹车中断
			//0：禁止刹车中断；
			//1：允许刹车中断。
		//BIT6：触发中断使能
			//0：禁止触发中断；
			//1：使能触发中断。
		//BIT5：允许COM中断
			//0：禁止COM中断；
			//1：允许COM中断。
		//BIT4：允许捕获/比较4中断
			//0：禁止捕获/比较4中断；
			//1：允许捕获/比较4中断。
		//BIT3：允许捕获/比较3中断
			//0：禁止捕获/比较3中断；
			//1：允许捕获/比较3中断。
		//BIT2：允许捕获/比较2中断
			//0：禁止捕获/比较2中断；
			//1：允许捕获/比较2中断。
		//BIT1：允许捕获/比较1中断
			//0：禁止捕获/比较1中断；
			//1：允许捕获/比较1中断。
		//BIT0：允许更新中断
			//0：禁止更新中断；
			//1：允许更新中断。

    //TIM1SR1 =0B00000000;
    //BIT7：刹车中断标记,一旦刹车输入有效，由硬件对该位置1。如果刹车输入无效，则该位可由软件清0。
			//0：无刹车事件产生；
			//1：刹车输入上检测到有效电平。
		//BIT6：触发器中断标记,当发生触发事件(当从模式控制器处于除门控模式外的其它模式时，在TRGI输入端检测到有效边沿，或门控模式下的任一边沿)时由硬件对该位置1。它由软件清0。                                        
			//0：无触发器事件产生；
			//1：触发中断等待响应。
		//BIT5：COM中断标记,一旦产生COM事件(当捕获/比较控制位：CciE、CciNE、OciM已被更新)该位由硬件置1。它由软件清0 。                                                                                                                                                  
			//0：无COM事件产生；
			//1：COM中断等待响应。
		//BIT4：捕获/比较4中断标记
			//参考CC1IF描述。
		//BIT3：捕获/比较3中断标记
			//参考CC1IF描述。
		//BIT2：捕获/比较2中断标记
			//参考CC1IF描述。
		//BIT1：捕获/比较1中断标记  如果通道CC1配置为输出模式：当计数器值与比较值匹配时该位由硬件置1，但在中心对称模式下除外(参考TIM1_CR1寄存器的CMS位)。它由软件清0。
			//0：无匹配发生；
			//1：TIMx_CNT的值与TIMx_CCR1的值匹配。
			//注：在中心对称模式下，当计数器值为0时，向上计数，当计数器值为ARR时，向下计数（它从0向上计数到ARR-1，再由ARR向下计数到1）。因此，对所有的SMS位值，这两个值都不置标记。但是，如果CCR1>ARR，则当CNT达到ARR值时，CC1IF置1。
			//如果通道CC1配置为输入模式：当捕获事件发生时该位由硬件置1，它由软件清0或通过读TIM1_CCR1L清0。
			//0：无输入捕获产生；
			//1：计数器值已被捕获(拷贝)至TIM1_CCR1(在IC1上检测到与所选极性相同的边沿)。
		//BIT0：更新中断标记,当产生更新事件时该位由硬件置1。它由软件清0。
			//0：无更新事件产生；
			//1：更新事件等待响应。当寄存器被更新时该位由硬件置1：
			//若TIM1_CR1寄存器的UDIS=0，当计数器上溢或下溢时；
			//若TIM1_CR1寄存器的UDIS=0、URS=0，当设置TIM1_EGR寄存器的UG位软件对计数器
			//CNT重新初始化时；
			//若TIM1_CR1寄存器的UDIS=0、URS=0，当计数器CNT被触发事件重新初始化时 (参考0
			//从模式控制寄存器TIM1_SMCR)。

    //TIM1SR2 =0B00000000;
    
    //TIM1EGR =0B00000000;
    //BIT7：产生刹车事件,该位由软件置1，用于产生一个刹车事件，由硬件自动清0。
			//0：无动作；
			//1：产生一个刹车事件。此时MOE=0、BIF=1，若开启对应的中断(BIE=1)，则产生相应的中断。
		//BIT6：产生触发事件,该位由软件置1，用于产生一个触发事件，由硬件自动清0。
			//0：无动作；
			//1：TIM1_SR寄存器的TIF=1，若开启对应的中断（TIE=1），则产生相应的中断。
		//BIT5：捕获/比较事件，产生控制更新该位由软件置1，由硬件自动清0。    
			//0：无动作；
			//1：当CCPC=1，允许更新CCIE、CCINE、CciP，CciNP，OCIM位。
			//注：该位只对拥有互补输出的通道有效。
		//BIT4：产生捕获/比较4事件
			//参考CC1G描述。
		//BIT3：产生捕获/比较3事件
			//参考CC1G描述。
		//BIT2：产生捕获/比较2事件
			//参考CC1G描述。
		//BIT1：产生捕获/比较1事件
			//该位由软件置1，用于产生一个捕获/比较事件，由硬件自动清0。
			//0：无动作；
			//1：在通道CC1上产生一个捕获/比较事件： 若通道CC1配置为输出：
			//设置CC1IF=1，若开启对应的中断，则产生相应的中断。若通道CC1配置为输入：
			//当前的计数器值被捕获至TIM1_CCR1寄存器，设置CC1IF=1，若开启对应的中断，则产生相应的中断。若CC1IF已经为1，则设置CC1OF=1。
		//BIT0：产生更新事件
			//该位由软件置1，由硬件自动清0。
			//0：无动作；
			//1：重新初始化计数器，并产生一个更新事件。注意预分频器的计数器也被清0(但是预分频系数不变)。若在中心对称模式下或DIR=0(向上计数)则计数器被清0；若DIR=1(向下计数)则计数器取TIM1_ARR的值。

    
    //TIM1CCMR1 =0B01101000;//CC1通道被配置为输出
		//BIT7：输出比较1清零使能
			//该位用于使能使用TIM1_TRIG引脚上的外部事件来清通道１的输出信号(OC1REF)，参考17.5.9在外部事件发生时清除OCREF信号
			//0：OC1REF 不受ETRF输入（来自TIM1_TRIG引脚）的影响；
			//1：一旦检测到ETRF输入高电平，OC1REF=0。
		//BIG6~BIT4：输出比较1模式,该3位定义了输出参考信号OC1REF的动作，而OC1REF决定了OC1的值。OC1REF是高电平有效，而OC1的有效电平取决于CC1P位。
			//000：冻结。输出比较寄存器TIM1_CCR1与计数器TIM1_CNT间的比较对OC1REF不起作用；
			//001：匹配时设置通道1的输出为有效电平。当计数器TIM1_CNT的值与捕获/比较寄存器1(TIM1_CCR1)相同时，强制OC1REF为高。
			//010：匹配时设置通道1的输出为无效电平。当计数器TIM1_CNT的值与捕获/比较寄存器1(TIM1_CCR1)相同时，强制OC1REF为低。
			//011：翻转。当TIM1_CCR1=TIM1_CNT时，翻转OC1REF的电平。
			//100：强制为无效电平。强制OC1REF为低。
			//101：强制为有效电平。强制OC1REF为高。
			//110：PWM模式1－ 在向上计数时，一旦TIM1_CNT<TIM1_CCR1时通道1为有效电平，否则为无效电平；在向下计数时，一旦TIM1_CNT>TIM1_CCR1时通道1为无效电平(OC1REF=0)， 否则为有效电平(OC1REF=1)。
			//111：PWM模式2－ 在向上计数时，一旦TIM1_CNT<TIM1_CCR1时通道1为无效电平，否则为有效电平；在向下计数时，一旦TIM1_CNT>TIM1_CCR1时通道1为有效电平，否则为无效电平。
			//注1：一旦LOCK级别设为3(TIM1_BKR寄存器中的LOCK位)并且CC1S=00(该通道配置成输出) 则该位不能被修改。
			//注2：在PWM模式1或PWM模式2中，只有当比较结果改变了或在输出比较模式中从冻结模式切换到PWM模式时，OC1REF电平才改变。(参考17.5.7PWM模式)
			//注3：在有互补输出的通道上，这些位是预装载的。如果TIM1_CR2寄存器的CCPC=1，OCM 位只有在COM事件发生时，才从预装载位取新值。
		//BIT3：输出比较1预装载使能
			//0：禁止TIM1_CCR1寄存器的预装载功能，可随时写入TIM1_CCR1寄存器，并且新写入的数值立即起作用。
			//1：开启TIM1_CCR1寄存器的预装载功能，读写操作仅对预装载寄存器操作，TIM1_CCR1的预装载值在更新事件到来时被加载至当前寄存器中。
			//注1：一旦LOCK级别设为3(TIM1_BKR寄存器中的LOCK位)并且CC1S=00(该通道配置成输出) 则该位不能被修改。
			//注2：为了操作正确，在PWM模式下必须使能预装载功能。但在单脉冲模式下(TIM1_CR1寄存器的OPM=1)，它不是必须的。
		//BIT2：输出比较1 快速使能,该位用于加快CC输出对触发输入事件的响应。
			//0：根据计数器与CCR1的值，CC1正常操作，即使触发器是打开的。当触发器的输入有一个有效沿时，激活CC1输出的最小延时为5个时钟周期。
			//1：输入到触发器的有效沿的作用就象发生了一次比较匹配。因此，OC被设置为比较电平而与比较结果无关。采样触发器的有效沿和CC1输出间的延时被缩短为3个时钟周期。
			//OCFE只在通道被配置成PWM1或PWM2模式时起作用。
		//BIT1~BIT0：捕获/比较1 选择。这2位定义通道的方向(输入/输出)，及输入脚的选择：
			//00：CC1通道被配置为输出；
			//01：CC1通道被配置为输入，IC1映射在TI1FP1上；
			//10：CC1通道被配置为输入，IC1映射在TI2FP1上；
			//11：CC1通道被配置为输入，IC1映射在TRC上。此模式仅工作在内部触发器输入被选中时(由
			//TIM1_SMCR寄存器的TS位选择)。
			//注：CC1S仅在通道关闭时(TIM1_CCER1寄存器的CC1E=0)才是可写的。


    //TIM1CCMR2 =0B00000000;
    //TIM1CCMR3 =0B00000000;
    //TIM1CCMR4 =0B00000000;
    
    //TIM1CCER1 =0B00001111; //比较1互补输出使能，低电平有效；比较器1输出使能，低电平有效
    //BIT7：输入捕获/比较2互补输出极性。参考CC1NP的描述。
		//BIT6：输入捕获/比较2互补输出使能。参考CC1NE的描述。
		//BIT5：输入捕获/比较2输出极性。参考CC1P的描述。
		//BIT4：输入捕获/比较2输出使能。参考CC1E的描述。
		//BIT3：输入捕获/比较1互补输出极性
			//0：OC1N高电平有效；
			//1：OC1N低电平有效。
			//注1：一旦LOCK级别(TIM1_BKR寄存器中的LCCK位)设为3或2且CC1S=00(通道配置为输出) 则该位不能被修改。
			//注2：对于有互补输出的通道，该位是预装载的。如果CCPC=1（TIM1_CR2寄存器），只有在
			//COM事件发生时，CC1NP位才从预装载位中取新值。
		//BIT2：输入捕获/比较1互补输出使能
			//0：关闭－ OC1N禁止输出，因此OC1N的输出电平依赖于MOE、OSSI、OSSR、OIS1、
			//OIS1N和CC1E位的值。
			//1：开启－ OC1N信号输出到对应的输出引脚，其输出电平依赖于MOE、OSSI、OSSR、
			//OIS1、OIS1N和CC1E位的值。
			//注：对于有互补输出的通道，该位是预装载的。如果CCPC=1(TIM1_CR2寄存器)，只有在
			//COM事件发生时，CC1NE位才从预装载位中取新值。
		//BIT1：输入捕获/比较1输出极性CC1通道配置为输出：
			//0：OC1高电平有效；
			//1：OC1低电平有效。
			//CC1通道配置为触发(参考图61)：
			//0：触发发生在TI1F的高电平或上升沿；
			//1：触发发生在TI1F的低电平或下降沿。
			//CC1通道配置为输入(参考图61)：
			//0：捕捉发生在TI1F的高电平或上升沿；
			//1：捕捉发生在TI1F的低电平或下降沿。
			//注1：一旦LOCK级别(TIM1_BKR寄存器中的LCCK位)设为3或2，则该位不能被修改。
			//注2：对于有互补输出的通道，该位是预装载的。如果CCPC=1（TIM1_CR2寄存器），只有在
			//COM事件发生时，CC1P位才从预装载位中取新值。
		//BIT0：输入捕获/比较1输出使能
			//CC1通道配置为输出：
			//0： 关闭－ OC1禁止输出，因此OC1的输出电平依赖于MOE、OSSI、OSSR、OIS1、OIS1N和CC1NE位的值。
			//1： 开启－ OC1信号输出到对应的输出引脚，其输出电平依赖于MOE、OSSI、OSSR、OIS1 、 OIS1N 和 CC1NE 位 的 值 。                                                                                          CC1通道配置为输入：
			//该位决定了计数器的值是否能捕获入TIM1_CCR1寄存器。
			//0：捕获禁止；
			//0：捕获使能。
			//注：对于有互补输出的通道，该位是预装载的。如果CCPC=1(TIM1_CR2寄存器)，只有在
			//COM事件发生时，CC1E位才从预装载位中取新值。

    //TIM1CCER2 =0B00000000;
    
    //TIM1CNTRH =0B00000000;//TIM1计数器
    //TIM1CNTRL =0B00000000;
    
	TIM1PSCRH = 0;//0B00000000;
	TIM1PSCRL = 15;//0B00000000;	// 16MHz/(15+1)=1MHz
    
    TIM1ARRH =0x03;        //自动重载，周期	1mS
    TIM1ARRL =0xe8;
//    TIM1ARRH =0x7D;        //自动重载，周期 32000
//    TIM1ARRL =0x00;
//    TIM1ARRH =0x3E;        //自动重载，周期 16000
//    TIM1ARRL =0x80;         
            
    GIE=1;
}

/*-------------------------------------------------
 *	函数名称：Time2Initial
 *	功能：  
 *	输入参数：
 *	返回参数：无 
 -------------------------------------------------*/
void Time2Initial(void)
{
	PCKEN |=0B00000100;    //使能timer2时钟模块
    CKOCON=0B00100000;
    TCKSRC=0B00110000;    //TIM2时钟为HIRC的2倍频
    //BIT7低频内振模式：1 = 256K 振荡频率模式,0 = 32K 振荡频率模式
    //BIT6~BIT4TIM2时钟源选择位
			//值	时钟源
			//0	系统时钟/主时钟
			//1	HIRC
			//2	XT时钟/外部时钟
			//3	HIRC的2倍频
			//4	XT时钟/外部时钟的2倍频
			//5	LIRC
			//6	LP时钟/外部时钟
			//7	LP时钟/外部时钟的2位频
		//BIT3:保留位
		//BIT2~BIT1:TIM2时钟源选择位
			//值	时钟源
			//0	系统时钟/主时钟
			//1	HIRC
			//2	XT时钟/外部时钟
			//3	HIRC的2倍频
			//4	XT时钟/外部时钟的2倍频
			//5	LIRC
			//6	LP时钟/外部时钟
			//7	LP时钟/外部时钟的2位频


    TIM2CR1 =0B10000101;  //预载允许，边沿对齐向上计数器，计数器使能
    //BIT7:自动预装载允许位
			//0：TIM2_ARR寄存器没有缓冲，它可以被直接写入；
			//1：TIM2_ARR寄存器由预装载缓冲器缓冲。
		//BIT6~BIT5:选择对齐模式
			//00：边沿对齐模式。计数器依据方向位(DIR)向上或向下计数。
			//01：中央对齐模式1。计数器交替地向上和向下计数。配置为输出的通道(TIM2_CCMRx寄存器中CciS=00)的输出比较中断标志位，只在计数器向下计数时被置1。 
			//10:中央对齐模式2。计数器交替地向上和向下计数。配置为输出的通道(TIM2_CCMRx寄存器中CciS=00)的输出比较中断标志位，只在计数器向上计数时被置1。
			//11：中央对齐模式3。计数器交替地向上和向下计数。配置为输出的通道(TIM2_CCMRx寄存器中CciS=00)的输出比较中断标志位，在计数器向上和向下计数时均被置1。
		//BIT4:方向
			//0：计数器向上计数；
			//1：计数器向下计数。
		//BIT3:单脉冲模式
			//0：在发生更新事件时，计数器不停止；
			//1：在发生下一次更新事件(清除CEN位)时，计数器停止。
		//BIT2:更新请求源
			//0：如果UDIS允许产生更新事件，则下述任一事件产生一个更新中断：
			//寄存器被更新(计数器上溢/下溢)
			//软件设置UG位
			//时钟/触发控制器产生的更新
			//1：如果UDIS允许产生更新事件，则只有当下列事件发生时才产生更新中断，并UIF置1：
			//寄存器被更新(计数器上溢/下溢)
		//BIT1:	禁止更新
			//0：一旦下列事件发生，产生更新(UEV)事件：
			//计数器溢出/下溢
			//产生软件更新事件
			//时钟/触发模式控制器产生的硬件复位被缓存的寄存器被装入它们的预装载值。
			//1：不产生更新事件，影子寄存器(ARR、PSC、CCRx)保持它们的值。如果设置了UG位或时钟/触发控制器发出了一个硬件复位，则计数器和预分频器被重新初始化。
		//BIT0	允许计数器
			//0：禁止计数器；
			//1：使能计数器。


    TIM2IER =0B00000001;
    //BIT7：允许刹车中断
			//0：禁止刹车中断；
			//1：允许刹车中断。
		//BIT6：触发中断使能
			//0：禁止触发中断；
			//1：使能触发中断。
		//BIT5：允许COM中断
			//0：禁止COM中断；
			//1：允许COM中断。
		//BIT4：允许捕获/比较4中断
			//0：禁止捕获/比较4中断；
			//1：允许捕获/比较4中断。
		//BIT3：允许捕获/比较3中断
			//0：禁止捕获/比较3中断；
			//1：允许捕获/比较3中断。
		//BIT2：允许捕获/比较2中断
			//0：禁止捕获/比较2中断；
			//1：允许捕获/比较2中断。
		//BIT1：允许捕获/比较1中断
			//0：禁止捕获/比较1中断；
			//1：允许捕获/比较1中断。
		//BIT0：允许更新中断
			//0：禁止更新中断；
			//1：允许更新中断。

    //TIM2SR1 =0B00000000;
    //BIT7：刹车中断标记,一旦刹车输入有效，由硬件对该位置1。如果刹车输入无效，则该位可由软件清0。
			//0：无刹车事件产生；
			//1：刹车输入上检测到有效电平。
		//BIT6：触发器中断标记,当发生触发事件(当从模式控制器处于除门控模式外的其它模式时，在TRGI输入端检测到有效边沿，或门控模式下的任一边沿)时由硬件对该位置1。它由软件清0。                                        
			//0：无触发器事件产生；
			//1：触发中断等待响应。
		//BIT5：COM中断标记,一旦产生COM事件(当捕获/比较控制位：CciE、CciNE、OciM已被更新)该位由硬件置1。它由软件清0 。                                                                                                                                                  
			//0：无COM事件产生；
			//1：COM中断等待响应。
		//BIT4：捕获/比较4中断标记
			//参考CC1IF描述。
		//BIT3：捕获/比较3中断标记
			//参考CC1IF描述。
		//BIT2：捕获/比较2中断标记
			//参考CC1IF描述。
		//BIT1：捕获/比较1中断标记  如果通道CC1配置为输出模式：当计数器值与比较值匹配时该位由硬件置1，但在中心对称模式下除外(参考TIM2_CR1寄存器的CMS位)。它由软件清0。
			//0：无匹配发生；
			//1：TIMx_CNT的值与TIMx_CCR1的值匹配。
			//注：在中心对称模式下，当计数器值为0时，向上计数，当计数器值为ARR时，向下计数（它从0向上计数到ARR-1，再由ARR向下计数到1）。因此，对所有的SMS位值，这两个值都不置标记。但是，如果CCR1>ARR，则当CNT达到ARR值时，CC1IF置1。
			//如果通道CC1配置为输入模式：当捕获事件发生时该位由硬件置1，它由软件清0或通过读TIM2_CCR1L清0。
			//0：无输入捕获产生；
			//1：计数器值已被捕获(拷贝)至TIM2_CCR1(在IC1上检测到与所选极性相同的边沿)。
		//BIT0：更新中断标记,当产生更新事件时该位由硬件置1。它由软件清0。
			//0：无更新事件产生；
			//1：更新事件等待响应。当寄存器被更新时该位由硬件置1：
			//若TIM2_CR1寄存器的UDIS=0，当计数器上溢或下溢时；
			//若TIM2_CR1寄存器的UDIS=0、URS=0，当设置TIM2_EGR寄存器的UG位软件对计数器
			//CNT重新初始化时；
			//若TIM2_CR1寄存器的UDIS=0、URS=0，当计数器CNT被触发事件重新初始化时 (参考0
			//从模式控制寄存器TIM2_SMCR)。

    //TIM2SR2 =0B00000000;
    
    //TIM2EGR =0B00000000;
    //BIT7：产生刹车事件,该位由软件置1，用于产生一个刹车事件，由硬件自动清0。
			//0：无动作；
			//1：产生一个刹车事件。此时MOE=0、BIF=1，若开启对应的中断(BIE=1)，则产生相应的中断。
		//BIT6：产生触发事件,该位由软件置1，用于产生一个触发事件，由硬件自动清0。
			//0：无动作；
			//1：TIM2_SR寄存器的TIF=1，若开启对应的中断（TIE=1），则产生相应的中断。
		//BIT5：捕获/比较事件，产生控制更新该位由软件置1，由硬件自动清0。    
			//0：无动作；
			//1：当CCPC=1，允许更新CCIE、CCINE、CciP，CciNP，OCIM位。
			//注：该位只对拥有互补输出的通道有效。
		//BIT4：产生捕获/比较4事件
			//参考CC1G描述。
		//BIT3：产生捕获/比较3事件
			//参考CC1G描述。
		//BIT2：产生捕获/比较2事件
			//参考CC1G描述。
		//BIT1：产生捕获/比较1事件
			//该位由软件置1，用于产生一个捕获/比较事件，由硬件自动清0。
			//0：无动作；
			//1：在通道CC1上产生一个捕获/比较事件： 若通道CC1配置为输出：
			//设置CC1IF=1，若开启对应的中断，则产生相应的中断。若通道CC1配置为输入：
			//当前的计数器值被捕获至TIM2_CCR1寄存器，设置CC1IF=1，若开启对应的中断，则产生相应的中断。若CC1IF已经为1，则设置CC1OF=1。
		//BIT0：产生更新事件
			//该位由软件置1，由硬件自动清0。
			//0：无动作；
			//1：重新初始化计数器，并产生一个更新事件。注意预分频器的计数器也被清0(但是预分频系数不变)。若在中心对称模式下或DIR=0(向上计数)则计数器被清0；若DIR=1(向下计数)则计数器取TIM2_ARR的值。

    
    //TIM2CCMR1 =0B01101000;//CC1通道被配置为输出
		//BIT7：输出比较1清零使能
			//该位用于使能使用TIM2_TRIG引脚上的外部事件来清通道１的输出信号(OC1REF)，参考17.5.9在外部事件发生时清除OCREF信号
			//0：OC1REF 不受ETRF输入（来自TIM2_TRIG引脚）的影响；
			//1：一旦检测到ETRF输入高电平，OC1REF=0。
		//BIG6~BIT4：输出比较1模式,该3位定义了输出参考信号OC1REF的动作，而OC1REF决定了OC1的值。OC1REF是高电平有效，而OC1的有效电平取决于CC1P位。
			//000：冻结。输出比较寄存器TIM2_CCR1与计数器TIM2_CNT间的比较对OC1REF不起作用；
			//001：匹配时设置通道1的输出为有效电平。当计数器TIM2_CNT的值与捕获/比较寄存器1(TIM2_CCR1)相同时，强制OC1REF为高。
			//010：匹配时设置通道1的输出为无效电平。当计数器TIM2_CNT的值与捕获/比较寄存器1(TIM2_CCR1)相同时，强制OC1REF为低。
			//011：翻转。当TIM2_CCR1=TIM2_CNT时，翻转OC1REF的电平。
			//100：强制为无效电平。强制OC1REF为低。
			//101：强制为有效电平。强制OC1REF为高。
			//110：PWM模式1－ 在向上计数时，一旦TIM2_CNT<TIM2_CCR1时通道1为有效电平，否则为无效电平；在向下计数时，一旦TIM2_CNT>TIM2_CCR1时通道1为无效电平(OC1REF=0)， 否则为有效电平(OC1REF=1)。
			//111：PWM模式2－ 在向上计数时，一旦TIM2_CNT<TIM2_CCR1时通道1为无效电平，否则为有效电平；在向下计数时，一旦TIM2_CNT>TIM2_CCR1时通道1为有效电平，否则为无效电平。
			//注1：一旦LOCK级别设为3(TIM2_BKR寄存器中的LOCK位)并且CC1S=00(该通道配置成输出) 则该位不能被修改。
			//注2：在PWM模式1或PWM模式2中，只有当比较结果改变了或在输出比较模式中从冻结模式切换到PWM模式时，OC1REF电平才改变。(参考17.5.7PWM模式)
			//注3：在有互补输出的通道上，这些位是预装载的。如果TIM2_CR2寄存器的CCPC=1，OCM 位只有在COM事件发生时，才从预装载位取新值。
		//BIT3：输出比较1预装载使能
			//0：禁止TIM2_CCR1寄存器的预装载功能，可随时写入TIM2_CCR1寄存器，并且新写入的数值立即起作用。
			//1：开启TIM2_CCR1寄存器的预装载功能，读写操作仅对预装载寄存器操作，TIM2_CCR1的预装载值在更新事件到来时被加载至当前寄存器中。
			//注1：一旦LOCK级别设为3(TIM2_BKR寄存器中的LOCK位)并且CC1S=00(该通道配置成输出) 则该位不能被修改。
			//注2：为了操作正确，在PWM模式下必须使能预装载功能。但在单脉冲模式下(TIM2_CR1寄存器的OPM=1)，它不是必须的。
		//BIT2：输出比较1 快速使能,该位用于加快CC输出对触发输入事件的响应。
			//0：根据计数器与CCR1的值，CC1正常操作，即使触发器是打开的。当触发器的输入有一个有效沿时，激活CC1输出的最小延时为5个时钟周期。
			//1：输入到触发器的有效沿的作用就象发生了一次比较匹配。因此，OC被设置为比较电平而与比较结果无关。采样触发器的有效沿和CC1输出间的延时被缩短为3个时钟周期。
			//OCFE只在通道被配置成PWM1或PWM2模式时起作用。
		//BIT1~BIT0：捕获/比较1 选择。这2位定义通道的方向(输入/输出)，及输入脚的选择：
			//00：CC1通道被配置为输出；
			//01：CC1通道被配置为输入，IC1映射在TI1FP1上；
			//10：CC1通道被配置为输入，IC1映射在TI2FP1上；
			//11：CC1通道被配置为输入，IC1映射在TRC上。此模式仅工作在内部触发器输入被选中时(由
			//TIM2_SMCR寄存器的TS位选择)。
			//注：CC1S仅在通道关闭时(TIM2_CCER1寄存器的CC1E=0)才是可写的。


    //TIM2CCMR2 =0B01101000;//CC2通道被配置为输出

    //TIM2CCMR3 =0B00000000;
    
    //TIM2CCER1 =0B00110011; //比较2互补输出使能，低电平有效；比较器1输出使能，低电平有效
		//BIT5：输入捕获/比较2输出极性。参考CC1P的描述。
		//BIT4：输入捕获/比较2输出使能。参考CC1E的描述。
		//BIT1：输入捕获/比较1输出极性CC1通道配置为输出：
			//0：OC1高电平有效；
			//1：OC1低电平有效。
			//CC1通道配置为触发(参考图61)：
			//0：触发发生在TI1F的高电平或上升沿；
			//1：触发发生在TI1F的低电平或下降沿。
			//CC1通道配置为输入(参考图61)：
			//0：捕捉发生在TI1F的高电平或上升沿；
			//1：捕捉发生在TI1F的低电平或下降沿。
			//注1：一旦LOCK级别(TIM2_BKR寄存器中的LCCK位)设为3或2，则该位不能被修改。
			//注2：对于有互补输出的通道，该位是预装载的。如果CCPC=1（TIM2_CR2寄存器），只有在
			//COM事件发生时，CC1P位才从预装载位中取新值。
		//BIT0：输入捕获/比较1输出使能
			//CC1通道配置为输出：
			//0： 关闭－ OC1禁止输出，因此OC1的输出电平依赖于MOE、OSSI、OSSR、OIS1、OIS1N和CC1NE位的值。
			//1： 开启－ OC1信号输出到对应的输出引脚，其输出电平依赖于MOE、OSSI、OSSR、OIS1 、 OIS1N 和 CC1NE 位 的 值 。                                                                                          CC1通道配置为输入：
			//该位决定了计数器的值是否能捕获入TIM2_CCR1寄存器。
			//0：捕获禁止；
			//0：捕获使能。
			//注：对于有互补输出的通道，该位是预装载的。如果CCPC=1(TIM2_CR2寄存器)，只有在
			//COM事件发生时，CC1E位才从预装载位中取新值。

    //TIM2CCER2 =0B00000000;
    
    //TIM2CNTRH =0B00000000;//TIM2计数器
    //TIM2CNTRL =0B00000000;

	TIM2PSCR = 3; 	//32MHz/8=4MHz
    
//    TIM2ARRH =0x03;        //自动重载，周期 1000
//    TIM2ARRL =0xe8;

    TIM2ARRH =0x00;        //自动重载，周期
    TIM2ARRL =0xA0; 
    
    //TIM2CCR1H =0x01;       //PWM脉宽
    //TIM2CCR1L =0xf4;
    
    //TIM2CCR2H =0x01;
    //TIM2CCR2L =0xf4;
    
    //TIM2CCR3H =0B00000000;
    //TIM2CCR3L =0B00000000;
    
    GIE =1;                //开总中断
}

/*-------------------------------------------------
 *	函数名称：Time4Initial
 *	功能：  
 *	输入参数：
 *	返回参数：无 
 -------------------------------------------------*/
void Time4Initial(void)
{
	PCKEN |=0B00001000;      //TIME4模块时钟使能
    //CKOCON=0B00110000;
    //TCKSRC=0B00000011;		
    
    TIM4CR1	=0B00000101;
    //BIT7: 0：TIM1_ARR寄存器没有缓冲，它可以被直接写入; 1：TIM1_ARR寄存器由预装载缓冲器缓冲。
    //BIT6:保留
    //BIT5~BIT4:timer4时钟选择位。
        		//00：系统时钟/主时钟
				//01：内部快时钟HIRC
				//10：LP时钟，只有当FOSC选择LP模式时才有意义
				//11：XT时钟，只有当FOSC选择XT模式时才有意义

    //BIT3:
    //			0：在发生更新事件时，计数器不停止；
	//			1：在发生下一次更新事件(清除CEN位)时，计数器停止。

    //BIT2:
   	// 		0：如果UDIS允许产生更新事件，则下述任一事件产生一个更新中断：
				//寄存器被更新(计数器上溢/下溢)
				//软件设置UG位
				//时钟/触发控制器产生的更新
	//		1：如果UDIS允许产生更新事件，则只有当下列事件发生时才产生更新中断，并UIF置1：
				//寄存器被更新(计数器上溢/下溢)

    //BIT1:
    //		0：一旦下列事件发生，产生更新(UEV)事件：
				//计数器溢出/下溢
				//产生软件更新事件
				//时钟/触发模式控制器产生的硬件复位被缓存的寄存器被装入它们的预装载值。
	//		1：不产生更新事件，影子寄存器(ARR、PSC、CCRx)保持它们的值。如果设置了UG位或时钟/触发控制器发出了一个硬件复位，则计数器和预分频器被重新初始化。

    // BIT0: 0：禁止计数器；1：使能计数器。


    TIM4IER	=0B00000001;
    //BIT0:  0：禁止更新中断；1：允许更新中断。

    TIM4SR	=0B00000000;
    //BIT0:当产生更新事件时该位由硬件置1。它由软件写1清0
			//0：无更新事件产生；
			//1：更新事件等待响应。当寄存器被更新时该位由硬件置1：
			//若TIM4_CR1寄存器的UDIS=0，当计数器上溢或下溢时；
			//若TIM4_CR1寄存器的UDIS=0、URS=0，当设置TIM4_EGR寄存器的UG位软件对计数器
			//CNT重新初始化时；
			//若TIM4_CR1寄存器的UDIS=0、URS=0，当计数器CNT被触发事件重新初始化时。

    TIM4EGR	=0B00000000;
    //BIT0:该位由软件置1，由硬件自动清0。
	//0：无动作；
	//1：重新初始化计数器，并产生一个更新事件。注意预分频器的计数器也被清0(但是预分频系数不变)。若在中心对称模式下或DIR=0(向上计数)则计数器被清0；若DIR=1(向下计数)则计数器取TIM1_ARR的值。

    TIM4CNTR=0; //TIM4 8位计数器
    
    TIM4PSCR=0B00000100;
    //预分频器对输入的CK_PSC时钟进行分频。
	//计数器的时钟频率fCK_CNT等于fCK_PSC/2(PSC[2:0])。PSC[7:3]由硬件清0。
	//PSCR包含了当更新事件产生时装入当前预分频器寄存器的值(包括由于清除TIMx_EGR寄存器的UG位产生的计数器清除事件)。这意味着如要新的预分频值生效，必须产生更新事件或者CEN=0。

    TIM4ARR	= 250;//124;
    //ARR包含了将要装载入实际的自动重装载寄存器的值。
	//当自动重装载的值为空时，计数器不工作。

    INTCON |= 0B11000000;    //开总中断和外设中断
}
  
/*-------------------------------------------------
 *  函数名: UART_INITIAL
 *	功能：  主函数
 *  输入：  无
 *  输出：  无
 --------------------------------------------------*/
void UartInitial(void)
{
	PCKEN |=0B00100000;	//打开UART时钟
    TRISA7=1;//UART_RX
    TRISA6=0;//UART_TX
    
    URIER =0B00000001;  //使送接收完成中断,发送完成中断不使能，查询发送串口数据
    URLCR =0B00000001;  //8位数据，停止位1，无奇偶校验
    URMCR =0B00011000;
    
    URDLL =52;//104;         // 9600 波特率 = Fosc/16*[URDLH:URDLL] 16M/16 * 9600    104.1666666
                             // 19200波特率 = Fosc/16*[URDLH:URDLL] 16M/16 * 19200   52.0833333
                             // 38400波特率 = Fosc/16*[URDLH:URDLL] 16M/16 * 3840000 26.0416666
    URDLH =0;
    TCF=1;
	INTCON=0B11000000;
    UROD=1;
    
    //TCF: 发送完成标志
    //TXEF:1发送寄存器为空
    //RXNEF:1按收寄存器非空
}

//*****************************************
//函数名称：WDT_INITIAL
//功能：   初始化设置看门狗1S时间复位
//相关寄存器：

//*****************************************
void WdtInitial(void)
{
	CLRWDT();              //清看门狗
    MISC0  = 0B00000000;   //看门狗时钟32k
    // 1S
	WDTCON = 0B00010101;   //WDTPS=1010=1:1024,预分频1:1
                        	//定时时间=(1024*1)/32000=32ms             
}

void UartReceiveData(uint8_t RcvData)
{
	switch(UartRxStep)
	{
		case 0:
		{
			if(RcvData == 0x55)
			{
				UartRxBuf[UartRxLen++] = RcvData;
				UartRxStep = 1;
			}
		
			break;            
		}
		case 1:
		{
			if(RcvData == 0xAA)
			{
				UartRxBuf[UartRxLen++] = RcvData;
				UartRxStep = 2;
			}            
		
			break;
		}
		case 2:
		{            
			UartRxBuf[UartRxLen++] = RcvData;
			if(UartRxLen > 3)
			{
				UartRxStep = 0;
				UartRxLen = 0;
				ReceiveFinishFlag = 1;

			}           
			break;
		}                
	   default:
			break;		
	}
}      

void UartSendData(void)
{
	unsigned char i;

	for(i=0;i<4;i++)
	{	   
		URDATAL = UartTxBuf[i];
		while(!TXEF) NOP();            
	}
}

void mcu_dp_value_update(uint8_t sync_cmd,uint8 sync_data)
{
	//if(FrameSendFlag == 1)
    {
		UartTxBuf[0] = 0x55;
		UartTxBuf[1] = 0xAA;
		UartTxBuf[2] = sync_cmd;
		UartTxBuf[3] = sync_data;
		
		UartSendData();
    }
}

void mcu_dp_value_update_debug(uint8_t sync_cmd)
{
	unsigned char i;         
	
	for(i=0;i<10;i++)
	{	   
		URDATAL = UartTxBuf[i];
		while(!TXEF) NOP();            
	}
 
}

/**************************************************************************** 
 * 函数名称 : UartB_Process
 * 功能描述 : 处理串口数据
 * 参    数 : 无
 * 参    数 : 无
 * 返 回 值 : 无
 *****************************************************************************/
void UartB_Process(void)
{
	uint32_t bright_value = 0;
	
	if(ReceiveFinishFlag == FALSE)
		return;
	
	ReceiveFinishFlag = FALSE;
	
	UartRecvData0 = UartRxBuf[0];
	UartRecvData1 = UartRxBuf[1];
	UartRecvData2 = UartRxBuf[2];
    UartRecvData3 = UartRxBuf[3];
	    
	switch(UartRecvData2)
	{
		//开关同步
		case UART_CMD_POWER:
		{
			FrameSendFlag = 0;

			// if((Switch_Ctrl_Flag == 23) && (travell_flag_load == LOW) && (travell_flag_ch0 == LOW))
			// {
			// }
			// else
			{
				//mcu_dp_value_update(UART_CMD_BRIGHT,DimPercentData);
				//RELAY_TOGGLE();
				if(UartRecvData3 == 1) 
				{       				
					if(PowerFlag == 0) 
					{       				
						PowerFlag = 1;	
						mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
						RELAY_TOGGLE();
					}
				}
				else if(UartRecvData3 == 0) 
				{       
					if(PowerFlag == 1) 
					{       
						PowerFlag = 0;	
						//RELAY_TOGGLE(); 
						mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
						KeyPowerOffFlag = TRUE; 
					} 
				} 
            }                                                      

			break;
		}
		//亮度同步
		case UART_CMD_BRIGHT:
        {
			FrameSendFlag = 0;	
            
            if(DimPercentData == UartRecvData3)
            {
            }
            else
            {	
				//if(UartRecvData3 != 0 && UartRecvData3 != 100)
				DimPercentData = UartRecvData3;
            }
            
			break;
        }     
		//联网状态同步
		case UART_CMD_CONNECT:
		{		
			//UartSendData();	
            ConnectState = UartRecvData3;
			break;
		}
		case UART_CMD_PARAMETER:
		{		
			//UartSendData();
//            if((UartRecvData3 >= 1) && (UartRecvData3 <= 100))
//				DimPercentData = UartRecvData3;

            if((UartRecvData3 >= 1) && (UartRecvData3 <= 100))
            {
				DimPercentData = UartRecvData3;
                MsgSendFlag = TRUE;
            }
                
			break;
		}		
        case UART_CMD_IDENTIFY:
        {
			LED_GREEN_TOGGLE();
			break;
        }       
                
		default:
			break;
	}
}

/*-------------------------------------------------
 *  函数名: ADC_INITIAL
 *	功能：  ADC初始化
 *  输入：  无
 *  输出：  无
 --------------------------------------------------*/
void AdcInitial(void)
{
	PCKEN |=0B00000001;      //AD模块时钟使能
    
    ANSELA = 0B00100000;    //模拟口设置，AN5为模拟管脚    
	//ANSELA = 0B00100100;      //模拟口设置，AN2,AN5配置为模拟管脚     
    
	ADCON1 = 0B11100100; 	//右对齐，转换时钟Fosc/64，负参考电压GND，正参考电压内部电压(2V)
  	//BIT7: 
		//1 = 右对齐。装入转换结果时，ADRESH的高4位被设置为0; 
		//0 = 左对齐。装入转换结果时，ADRESL的低4位被设置为0。
  
  	//BIT6~BIT4:ADC转换时钟选择位
		//000 = FOSC/2
		//001 = FOSC/8
		//010 = FOSC/32
		//011 = FRC（由专用RC振荡器提供时钟）
		//100 = FOSC/4
		//101 = FOSC/16
		//110 = FOSC/64
		//111 = FRC（由专用RC振荡器提供时钟）
	
	//BIT3~BIT2:ADC负参考电压配置位（使用PB6连接外部参考电压或外部电容）
		//00 = Int Vref（内部参考电压）
		//01 = GND
		//10 = Int Vref + Ext Cap（内部参考电压 + 外部电容）
		//11 = Ext Vref（外部参考电压）

  	//BIT1~BIT0	ADC正参考电压配置位（使用PB5连接外部参考电压或外部电容）
		//00 = Int Vref（内部参考电压）
		//01 = VDD
		//10 = Int Vref + Ext Cap（内部参考电压 + 外部电容）
		//11 = Ext Vref（外部参考电压）
                             
	ADCON0 = 0B00000000; 	//选择AD转换通道0，使能ADC
  	//BIT7~BIT4:ADC模拟通道选择位
		//0000 = AN0
		//0001 = AN1
		//0010 = AN2
		//0011 = AN3
		//0100 = AN4
		//0101 = AN5
		//0110 = AN6
		//0111 = AN7
		//1000 = 1/4 VDD
		//其余保留

    //BIT3:该位由软件设置来启动ADC校准。当校准完成后，由硬件清零。
		//0 = 校准完成。
		//1 = 写1时校准ADC，读为1时意味着校准仍在进行中。

    //BIT2:	ADC触发信号类型选择
		//该位决定启动ADC的触发条件
		//0 = 当软件设定GO/DONE位，启动AD转换
		//1 = 需要外部触发信号触发才可启动AD转换，触发事件置位GO/DONE位。
		//外部触发信号条件由寄存器ETGSEL<2:0>和ETGTYP<1:0>决定。
  
    //BIT1:
    	//0 = A/D转换完成/未进行。
		//1 = A/D转换正在进行或硬件触发延时正在计数。

    //BIT0:使能ADC  
    	//0 = ADC被禁止且不消耗工作电流
		//1 = ADC被使能
              
					   						   			 			
    ADCON2 = 0B10000000; 	//选择内部正参考电压3V，无外部触发源
    //BIT7~BIT6:ADC内部参考电压配置位
		//00 = 0.5V
		//01 = 2V
		//10 = 3V
		//11 = float（悬空）
		
	//BIT5~BIT4:外部触发信号类型选择
		//当ADEX置1，该位决定响应外部触发的类型
		//00 = PWM 或 ADC_ETR脚的下降沿
		//01 = PWM 或 ADC_ETR脚的上升沿
		//10 = 一个PWM周期的中点
		//11 = 一个PWM周期的终点
		
	//BIT3:ADC外部触发延时计数器阈值 第8位
		
	//BIT2~BIT0:外部触发源选择
		//当ADEX为1，该位选择外部触发ADC的来源
		//选择PWM源时需要配置TIMER为PWM输出模式并使能输出。
		//000 = PWM0
		//001 = PWM1
		//010 = PWM2
		//011 = PWM3
		//100 = PWM4
		//101 = PWM5
		//110 = PWM6
		//111 = ADC_ETR

    ADCON3 = 0B00000000; 
    //BIT7:ADC比较结果响应故障刹车使能
		//0 = 禁止
		//1 = ADC触发故障刹车功能使能
		
	//BIT6:ADC比较器输出极性选择位
		//0 = 若ADC结果的高八位大于或等于ADCMPH[7:0]，ADCMPO为1
		//1 = 若ADC结果的高八位小于ADCMPH[7:0]，ADCMPO为1

	//BIT5:ADC结果比较使能位
		//0 = ADC结果比较功能关闭
		//1 = ADC结果比较功能打开
		
	//BIT4:ADC比较结果输出位
		//该位输出ADCMPOP设定的比较输出结果。每次AD转换结束都会更新输出
		
	//BIT3:前沿消隐周期结束后，ADC触发使能
		//1 = 触发ADC转换
		//0 = 不触发ADC转换
		
	//BIT2:保留位
	//BIT1~BIT0 外部LVD管脚输入选择，只有当LVDM为1时才有效
		//00 = ELVD0
		//01 = ELVD1
		//10 = ELVD2
		//11 = ELVD3

    ADDLY  = 0B00000000;    //外部触发廷时，没用到
    //ADC外部触发启动延时计数器阈值低位
	//该8位寄存器与ADCON2.7组成9位计数器，用于在外部触发启动ADC之前加入一段延迟。延迟计数器结束再开始ADC转换
	//外部延迟时间 = (ADDLY+6)/FADC

    ADCMPH = 0B00000000;	//ADC比较阈值,仅8位，用于ADC结果高8位比较。


	ADCAL=1;                //校准ADC, 注意点：校准要放在配置之后
    NOP();
    while(ADCAL);       
    
    ADON=1; //全能ADC
}                      
/*-------------------------------------------------
 *  函数名: GET_ADC_DATA
 *	功能：  读取通道ADC值
 *  输入：  adcChannel 通道序号
 *  输出：  INT类型AD值(单次采样无滤波)
 --------------------------------------------------*/
unint GetAdcData(unchar adcChannel)
{ 
	ADCON0 &= 0B00001111;        				   
    ADCON0 |= adcChannel<<4; 				//重新加载通道值
	DelayUs(40);                        	//廷时等待电压稳定 Tst >10us
	GO = 1;             					//启动ADC 
    NOP();
    NOP();
	while(GO);    							//等待ADC转换完成

    return  (unint)(ADRESH<<8|ADRESL);      //整合12位AD值
} 

void LvdInitial(void)
{
	LVDCON = 0B00010011; // bit6   LVDM   LVD输入：0-VDD
                         // bit4   LVEDN  LVD使能：1-使能
                         // bit2~0 LVDL  100-2.8V
                         
	LVDIE = 1;	// LVD中断使能   
    
}

/*----------------------------------------------------
 *	函数名称：EEPROMread
 *	功能：   读EEPROM数据
 *	输入参数：EEAddr 需读取数据的地址
 *  返回参数；ReEEPROMread 对应地址读出的数据
 ----------------------------------------------------*/
unchar EEPROMread(unchar EEAddr)
{
	unchar ReEEPROMread;
    
    DRDEN=1;    
    NOP();
    NOP();      
   	EEADRL = EEAddr;
   
    CFGS =0;
    EEPGD=0; 
   	RD = 1;
    
	ReEEPROMread = EEDATL; 
    DRDEN=0;    	
	return ReEEPROMread;
}
/*---------------------------------------------------- 
 *	函数名称：EEPROMwrite
 *	功能：   写数据到EEPROM
 *	输入参数：EEAddr 需要写入数据的地址
 *	        Data 需要写入的数据
 *	返回参数：无
 ----------------------------------------------------*/
void EEPROMwrite(unchar EEAddr,unchar Data)
{
	
	while(GIE)					//等待GIE为0
		{GIE = 0;	}					//写数据必须关闭中断
	EEADRL = EEAddr; 	 			//EEPROM的地址
	EEDATL = Data;		 			//EEPROM的写数据  
      
    CFGS =0;                        //访问EEPROM存储器
    EEPGD=0;                        //
    
    WREN=1;                         //写使能
    
    EEIF = 0;
    EECON2=0x55;
    EECON2=0xAA;

	WR = 1;							//置位WR启动编程
    NOP();
    NOP();
    NOP();
    NOP();
	while(WR);      				//等待EE写入完成
    WREN = 0;
	GIE = 1;
}

void TIM2_ResetPeriod(uint16 Period, uint8 NewState)
{
    
  TIM2CR1 &= ~(0x1);  
  TIM2ARRH = (Period >> 8) & 0xFF;       
  TIM2ARRL = Period & 0xFF;  
  
  //T2CNT = 0;  
  TIM2CNTRH = 0;
  TIM2CNTRL = 0;
  
  T2UIF = 1;        	//写1清零标志位 
  
  if(NewState)
	TIM2CR1 |= 0x1;
  else
    TIM2CR1 &= ~(0x1);  
     
}

uint16_t LoadDetCnt = 0;
//uint8_t LoadDetFinishFlag = 0;
void Load_Scan(void)
{
  
//  LoadDetCnt++;
//  if(LoadDetCnt <= 2000)
//  {
//	sample_data_load += LOAD_DETECT;     
////    if(LOAD_DETECT)  
////		sample_data_load++;    
//       
//  }
//  else
//  {
//    LoadDetCnt = 0;
//    if(sample_data_load > 0)
//    {
//      travell_flag_load = HIGH;
//    }
//    else
//    {
//      travell_flag_load = LOW;
//    }
//    
//    sample_data_load = 0;
//    //LoadDetFinishFlag = 1;
//  }

  LoadDetCnt++;
  if(LoadDetCnt <= 200) // 2000->1000->400
  {       
  }
  else
  {
    LoadDetCnt = 0;
    if(sample_data_load > 0)
    {
      travell_flag_load = HIGH;
    }
    else
    {
      travell_flag_load = LOW;
    }
    
    sample_data_load = 0;
  }

}

/*****************************************************************************
函数名称 : Connect_With_Switch
功能描述 : 3-Way开关互连处理
输入参数 : 无
返回参数 : 无
*****************************************************************************/
void Connect_With_Switch(void)
{

	switch(sample_cnt)
	{
		case 0:
		case 1:
		case 2:
        case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:   
             
			sample_data_ch0[sample_cnt] = GetAdcData(5);//adc1_get_raw(ADC1_CHANNEL_0);	
			sample_cnt++;
               
			break;
		case 10:
			if((sample_data_ch0[0] < ADC_VAL) &&
			   (sample_data_ch0[1] < ADC_VAL) &&
               (sample_data_ch0[2] < ADC_VAL) &&
               (sample_data_ch0[3] < ADC_VAL) &&
               (sample_data_ch0[4] < ADC_VAL) &&
               (sample_data_ch0[5] < ADC_VAL) &&
               (sample_data_ch0[6] < ADC_VAL) &&
               (sample_data_ch0[7] < ADC_VAL) &&
               (sample_data_ch0[8] < ADC_VAL) &&                          
			   (sample_data_ch0[9] < ADC_VAL))
			{
				travell_flag_ch0 = LOW;
			}   
			else
			{
				travell_flag_ch0 = HIGH;
			}
            
            

//	switch(sample_cnt)
//	{
//		case 0:
//		case 1:
//		case 2:             
//			sample_data_ch0[sample_cnt] = GetAdcData(5);//adc1_get_raw(ADC1_CHANNEL_0);	
//			sample_cnt++;               
//			break;
//		case 3:
//			if((sample_data_ch0[0] < ADC_VAL) &&
//			   (sample_data_ch0[1] < ADC_VAL) &&                
//			   (sample_data_ch0[2] < ADC_VAL))
//			{
//				travell_flag_ch0 = LOW;
//			}   
//			else
//			{
//				travell_flag_ch0 = HIGH;
//			}
            
            
			if(Dimmer_Init_Flag == TRUE)		// Init Scan
			{
				Dimmer_Init_Flag = FALSE;
			
				if(travell_flag_ch0 == LOW)		// LIGHT ON
				{
					travell_flag_ch0_last = travell_flag_ch0;
					// travell_flag_ch1_last = travell_flag_ch1;
					if(PowerFlag == ON)
					{
						PowerFlag = ON;
                        
                        mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
						//printf("INIT SCAN POWER ON\n");
					}
					else if(PowerFlag == OFF)
					{
						travell_flag_ch0_last = HIGH;	// HIGH LOW or LOW HIGH -> OFF
						// travell_flag_ch0_last = travell_flag_ch0;
						// travell_flag_ch1_last = LOW;
						PowerFlag = OFF;
                        mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
						//GPIO_Toggle_Relay(GPIO_OUT_RELAY_PIN);
                        RELAY_TOGGLE();
						//printf("INIT SCAN POWER OFF\n");
					}							
					//printf("INIT SCAN POWER ON\n");
				}
				// // else															// LIGHT OFF
				else if(travell_flag_ch0 == HIGH) 
				{
					travell_flag_ch0_last = travell_flag_ch0;
					// travell_flag_ch1_last = travell_flag_ch1;
					if(PowerFlag == OFF)
					{
						PowerFlag = OFF;
                        mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
					}
					else if(PowerFlag == ON)
					{
						travell_flag_ch0_last = LOW;	// LOW LOW -> OFF
						// travell_flag_ch0_last = travell_flag_ch0;
						// travell_flag_ch1_last = LOW;
						PowerFlag = ON;
                        mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
						//GPIO_Toggle_Relay(GPIO_OUT_RELAY_PIN);
                        RELAY_TOGGLE();
						//printf("INIT SCAN POWER ON\n");
					}
				// 	printf("INIT SCAN POWER OFF\n");
				}				
				sample_cnt = 0;
			}            
            
			else		// Normal Scan
			{				                 
                            
				if(PowerFlag == ON) 
                {
					if(PowerFlag_last == ON)
                    {
						//LoadDetFinishFlag = 0;
						if((travell_flag_ch0 == HIGH) && (travell_flag_load == LOW))
						{
							PowerFlag = OFF;
							mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
							Switch_Ctrl_Flag = 11;
						}
						else if((travell_flag_ch0 == LOW) && (travell_flag_load == LOW))
						{
							// no load
							PowerFlag = OFF;
                            mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
							//RELAY_TOGGLE();  // Load off does not switch relay
                            Switch_Ctrl_Flag = 12;                      
						}    
                    }
                    else if(travell_flag_load == HIGH)
                    {
						PowerFlag_last = ON;
                    }               
                }
				else if(PowerFlag == OFF) 
                {
					if(PowerFlag_last == OFF)
                    {                
						//if((travell_flag_ch0 == LOW) && (travell_flag_load == HIGH))
                        if(travell_flag_ch0 == LOW)
						{
							PowerFlag = ON;
                            Switch_Ctrl_Flag = 21;
                            
                            DelayMs(50);
                            if(travell_flag_load == HIGH)
                            {
								mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
								Switch_Ctrl_Flag = 22;
                            }
                            else if(travell_flag_load == LOW)
                            {
								PowerFlag = OFF;
								Switch_Ctrl_Flag = 23;
//                                if(Switch_Ctrl_Flag != Switch_Ctrl_Flag_Last)
//                                {
//									Switch_Ctrl_Flag_Last = Switch_Ctrl_Flag;
//                                    mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
//                                }
                                
                            }
						}
//						else if((travell_flag_ch0 == LOW) && (travell_flag_load == LOW))
//						{
//							// no load
//                            Switch_Ctrl_Flag = 24;
//				
//						}
                    }
                    else if(travell_flag_load == LOW)
                    {
						PowerFlag_last = OFF;
                    }
				}                                            
				sample_cnt = 0;
			}	

//			else		// Normal Scan
//			{				                 
//                            
//				if(PowerFlag == ON) 
//                {
//					if(PowerFlag_last == ON)
//                    {
//						//LoadDetFinishFlag = 0;
//						if(travell_flag_ch0 == HIGH)
//						{
//							PowerFlag = OFF;
//							mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
//							Switch_Ctrl_Flag = 11;
//						}
//                    }
//                    else if(travell_flag_load == HIGH)
//                    {
//						PowerFlag_last = ON;
//                    }       
//                    
//					if((travell_flag_ch0 == LOW) && (travell_flag_load == LOW))
//					{
//						// no load
//						PowerFlag = OFF;
//						RELAY_TOGGLE();                        
//					}                                
//                }
//				else if(PowerFlag == OFF) 
//                {
//					if(PowerFlag_last == OFF)
//                    {                
//						//LoadDetFinishFlag = 0;
//						if(travell_flag_ch0 == LOW)
//						{
//							PowerFlag = ON;
//							mcu_dp_value_update(UART_CMD_POWER,PowerFlag);
//							Switch_Ctrl_Flag = 21;
//						}
//                    }
//                    else if(travell_flag_load == LOW)
//                    {
//						PowerFlag_last = OFF;
//                    }
//                    
//					if((travell_flag_ch0 == LOW) && (travell_flag_load == LOW))
//					{
//						// no load
//			
//					}                   
//				}                                            
//				sample_cnt = 0;
//			}	


			break;

		default:
			break;	

	}

}


