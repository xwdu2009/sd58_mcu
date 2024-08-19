/*-----------------------------------------------------------------------------
Copyright 2019-2022 INNOTECH Technology Co.,Ltd All Rights Reserved.
FileName: task.c
Author: Dean Zhang
Version:V1.0.0
Date:2022-04-08
Description: CK0351
Function List: 
-----------------------------------------------------------------------------*/
#include "header.h"

/*-----------------------------------------------------------------------------
Function: CheckChannelTask()
Description: 检测通道内是否有电池放入或取出
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void CheckChannelTask(unsigned int voltage, struct strChannel *ptCh)
{
    //通道有电池
	if(voltage < NO_CELL_VALUE)
	{
		if(ptCh->fbat == 0) //通道有新电池放入
		{	
            ptCh->fbat = 1;
			cellNumber++; //电池计数加1       
            
            ptCh->batPeakVoltage = voltage; //电池峰值电压赋初值
            ptCh->vSlopeLastVoltage = voltage; //电压斜率检测赋初值
            ptCh->startCellOCV = voltage;	// 充电前电池电压赋初值	
			
			if(voltage < LOW_VOLTAGE_BAT_VALUE)
			{
				ptCh->flow = 1; 
			}
			
			if(voltage > ALKALINE_BAT_VALUE)
			{
				ptCh->fbad = 1; //一次电池
			}
		}
	}
    //通道没有电池,相关寄存器清零
	else
	{
		if(ptCh->fbat == 1) //通道原来有电池，被取出了
		{
			cellNumber--; //电池计数减1
		}
		ptCh->fbat = 0;
		ptCh->fbad = 0;
		ptCh->fend = 0;
		ptCh->f1hour = 0;
		ptCh->flow = 0;
		ptCh->timeCount = 0;
		ptCh->endTimeCount = 0;
		ptCh->mosFailCount = 0;
		ptCh->cellCCV = 0;
		ptCh->cellOCV = 0;
		ptCh->dvCount = 0;
		ptCh->_0dvTimer = 0;
		ptCh->batPeakVoltage = 0;
		ptCh->batVoltageRiseCount = 0;
        ptCh->startCellOCV = 0;
		ptCh->vSlopeCount = 0;
		ptCh->vSlopeTimeCount = 0;
		ptCh->vSlopePeakValue = 0;
		ptCh->vSlopeLastVoltage = 0;
		ptCh->overTemperatureCount = 0;
		ptCh->overVoltageCount = 0;			
	}
}
/*-----------------------------------------------------------------------------
Function: OverVoltageTask()
Description: 检测电池过压
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void OverVoltageTask(unsigned int voltage, struct strChannel *ptCh)
{
	if(voltage > BAT_OVERVOLTAGE_VALUE)
	{
        if (++ptCh->overVoltageCount >= 5)
        {
            ptCh->fbad = 1;
        }
	}
    else
    {
        ptCh->overVoltageCount = 0;
    }

}
/*-----------------------------------------------------------------------------
Function: LowVoltageTask()
Description: 检测电池欠压
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void LowVoltageTask(unsigned int voltage, struct strChannel *ptCh)
{
	if((ptCh->timeCount > 15) && (voltage < BAT_LOWVOLTAGE_VALUE)) //超过30秒
	{
		if (++ptCh->lowVoltageCount >= 5)
		{
			ptCh->fbad = 1;
		}
	}
	else
	{
		ptCh->lowVoltageCount = 0;
	}
}

void PrimaryBatteryTask(unsigned int voltage, struct strChannel *ptCh)
{
	if(voltage > PRIMARY_BAT_VALUE)
	{
        if (++ptCh->primaryBatteryCount >= 5)
        {
            ptCh->fbad = 1;
        }
	}
    else
    {
        ptCh->primaryBatteryCount = 0;
    }

}


/*-----------------------------------------------------------------------------
Function: DvTask()
Description: 检测-dV和0dV
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void DvTask(unsigned int voltage, struct strChannel *ptCh)
{
    //电池电压升高
    if(voltage > ptCh->batPeakVoltage)
    {
        if(++ptCh->batVoltageRiseCount >= 5)
        {
            ptCh->batPeakVoltage+=1; //电池电压连续5次上升，电压峰值+1
            ptCh->dvCount = 0;
            ptCh->_0dvTimer = 0;
        }
    }
    //电池电压不变或下降
    else
    {
        ptCh->batVoltageRiseCount = 0;
        //-dV检测
        if((voltage < DV_THRESHOLD_VOLTAGE) || (ptCh->timeCount < 150)) //电池电压低于起判阈值或时间小于5分钟
        {
            ptCh->dvCount = 0;
        }
        //电压下降幅度超过设定阈值
        else if((ptCh->batPeakVoltage - voltage) >= DV_VALUE)
        {
            //连续10个周期-dV都超过设定阈值
            if(++ptCh->dvCount >= 10)
            {
                ptCh->fend = TRUE; //-dV满足，电池充满
            }
        }
        //电压下降幅度未超过设定阈值
        else
        {
            ptCh->dvCount = 0;
        }
        //0dV检测
        if(ptCh->batPeakVoltage < _0DV_THRESHOLD_VOLTAGE) //电池电压低于起判阈值
        {
            ptCh->_0dvTimer = 0;
        }
        else
        {
            ptCh->_0dvTimer += 1;
            if(ptCh->_0dvTimer >= _0DV_TIME)
            {
				ptCh->fend = TRUE; //0dV满足，电池充满
            }
        }
    }
}
/*-----------------------------------------------------------------------------
Function: VSlopeTask()
Description: 检测电压斜率
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void VSlopeTask(unsigned int voltage, struct strChannel *ptCh)
{
    //unsigned int voltageDifference;

    //电池OCV小于阈值
    if(voltage < VSLOPE_THRESHOLD_VOLTAGE)
    {
        ptCh->vSlopePeakValue = 0;
        ptCh->vSlopeCount = 0;
        ptCh->vSlopeLastVoltage = voltage;
        ptCh->vSlopeTimeCount = 0;
        return;
    }
    //时间间隔未到设定值，1节电池300*1=5分钟，4节电池300*4=20分钟
    if(++ptCh->vSlopeTimeCount == 60)
    {
        ptCh->vSlopeTimeCount = 0;

        //电压升高则计算两次电压差值，否则电压差值为0
        if(voltage > ptCh->vSlopeLastVoltage)
        {
			voltageDifference = voltage - ptCh->vSlopeLastVoltage;
        }
        else
        {
            voltageDifference = 0;
        }
        //更新前次电压
        ptCh->vSlopeLastVoltage = voltage;

        //为避免干扰导致的误判如果电压差值超过最大限值则电压最大差值限定为最大值
        if(ptCh->vSlopePeakValue == 0)
        {
            if(voltageDifference > VSLOPE_UPPERLIMIT)
            {
                ptCh->vSlopePeakValue = VSLOPE_UPPERLIMIT;
            }
            else
            {
                ptCh->vSlopePeakValue = voltageDifference;
            }
        }
        //如果电压差增大，则电压差峰值加1
        else if(voltageDifference > ptCh->vSlopePeakValue)
        {
            ptCh->vSlopePeakValue += 1;
            ptCh->vSlopeCount = 0;
        }
        //如果电压差减小，则电压差峰值减1以避免干扰，连续3次电压差减小则充电停止
        else if(voltageDifference < ptCh->vSlopePeakValue)
        {
            ptCh->vSlopePeakValue -= 1;
			if(++ptCh->vSlopeCount >=5)
			{
				ptCh->fend = TRUE;
				ptCh->vSlopeCount = 0;
                return;
			}
		}
		//电压斜率不变
		else
		{
			ptCh->vSlopeCount = 0;
			return;
		}
    }
}
/*-----------------------------------------------------------------------------
Function: LithiumIronBatteryDetectTask()
Description: 检测电压斜率
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void LithiumIronBatteryDetectTask(unsigned int voltage, struct strChannel *ptCh)
{
    return;
}
/*-----------------------------------------------------------------------------
Function: MosFailTask()
Description: 检测MOS管是否故障
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void MosFailTask(struct strChannel *ptCh)
{
    if((ptCh->cellCCV < ptCh->cellOCV) ||( (ptCh->cellCCV - ptCh->cellOCV) < MOS_FAIL_THRESHOLD))
    {
    	ptCh->mosFailCount++;
        if(ptCh->mosFailCount > 10)
        {
        	channelControl = ERROR;
            ferror = 1;
			ptCh->fbad = 1;
        }
    }
    else
    {
        ptCh->mosFailCount = 0;
    }
    return;
}

/*-----------------------------------------------------------------------------
Function: ChargingTimerTask()
Description: 检测充电时间是否达到设定值
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void ChargingTimerTask(struct strChannel *ptCh)
{
	if(ptCh->fend == 0)
	{
		//正常充电时间判断
		ptCh->timeCount++;
		
	    if(ptCh->timeCount > SAFETY_TIMER)
	    {
	        ptCh->fend = TRUE;
			ptCh->timeCount = 0;
	    }
	}
	else
	{
		ptCh->endTimeCount++;
		if(ptCh->endTimeCount > TRICKLE_CHARGING_TIMER)
		{
			ptCh->f1hour = TRUE;
			ptCh->endTimeCount = 0;
		}
	}		
}

/*-----------------------------------------------------------------------------
Function: OverTemperatureTask(void)
Description: 检测环境温度是否超出范围
Input:
Output:
Return:
Others: 
-----------------------------------------------------------------------------*/
void OverAmbientTemperatureTask(unsigned int voltage, struct strChannel *ptCh)
{
	//voltage = GetAdcData(ADC_TEMPERATURE);
	if(ptCh->fbat == 1)
	{
		return;
	}

	if(ptCh->F_TAmbientHigh == 0)
	{
		if(voltage > OVER_AMBIENT_TEMP_VALUE)
		{
			ptCh->F_TAmbientHigh = 1;
		}
	}
	else
	{
		if(voltage < OVER_AMBIENT_TEMP_OK_VALUE)
		{
			ptCh->F_TAmbientHigh = 0;
		}
	}

	if(ptCh->F_TAmbientLow == 0)
	{
		if(voltage < UNDER_AMBIENT_TEMP_VALUE)
		{
			ptCh->F_TAmbientLow = 1;
		}
	}
	else
	{
		if(voltage > UNDER_AMBIENT_TEMP_OK_VALUE)
		{
			ptCh->F_TAmbientLow = 0;
		}
	}

}

/*-----------------------------------------------------------------------------
Function: OverTemperatureTask(void)
Description: 检测电池温度是否有超出范围，是否有恢复到正常
Input:
    overTemperatureCount: 过温防抖计数
Output:
    flagOverTemperature: TRUE, FALSE
Return:
Others: 
-----------------------------------------------------------------------------*/
void OverTemperatureTask(unsigned int voltage, struct strChannel *ptCh)
{
    if((voltage < OVER_TEMP_VALUE)&&(voltage > UNDER_TEMP_VALUE))
    {
        ptCh->overTemperatureCount = 0;
    }
    else
    {
        if (++ptCh->overTemperatureCount >= 5)
        {
            ptCh->overTemperatureCount = 0;
            ptCh->fend = TRUE;
        }
    }
}

/*-----------------------------------------------------------------------------
Function: ChangeVoltageTask(void)
Description: 一次性电池检测
Input:
    
Output:
    
Return:
Others: 
-----------------------------------------------------------------------------*/
void ChangeVoltageTask(unsigned int voltage, struct strChannel *ptCh)
{
        if(ptCh->timeCount == 15)
        {
                if(voltage - ptCh->startCellOCV > BAT_VOLTAGE_D_VALUE)
                {
                        ptCh->fbad = 1;
                }
        }
}


void LedInitTask(void)
{
	LED1_ON();
	LED2_OFF();
	LED3_OFF();
	LED4_OFF();
	LED5_OFF();
	LED6_OFF();
	LED7_OFF();
	LED8_OFF();
	DelayMs(400);
	LED1_OFF();
	LED2_ON();
	LED3_OFF();
	LED4_OFF();
	LED5_OFF();
	LED6_OFF();
	LED7_OFF();
	LED8_OFF();	
	DelayMs(400);
	LED1_OFF();
	LED2_OFF();
	LED3_ON();
	LED4_OFF();
	LED5_OFF();
	LED6_OFF();
	LED7_OFF();
	LED8_OFF();	
	DelayMs(400);
	LED1_OFF();
	LED2_OFF();
	LED3_OFF();
	LED4_ON();
	LED5_OFF();
	LED6_OFF();
	LED7_OFF();
	LED8_OFF();	
	DelayMs(400);
	LED1_OFF();
	LED2_OFF();
	LED3_OFF();
	LED4_OFF();
	LED5_ON();
	LED6_OFF();
	LED7_OFF();
	LED8_OFF();	
	DelayMs(400);
	LED1_OFF();
	LED2_OFF();
	LED3_OFF();
	LED4_OFF();
	LED5_OFF();
	LED6_ON();
	LED7_OFF();
	LED8_OFF();	
	DelayMs(400);
	LED1_OFF();
	LED2_OFF();
	LED3_OFF();
	LED4_OFF();
	LED5_OFF();
	LED6_OFF();
	LED7_ON();
	LED8_OFF();	
	DelayMs(400);	
	LED1_OFF();
	LED2_OFF();
	LED3_OFF();
	LED4_OFF();
	LED5_OFF();
	LED6_OFF();
	LED7_OFF();
	LED8_ON();	
	DelayMs(400);	
	LED1_OFF();
    LED2_OFF();
	LED3_OFF();
	LED4_OFF();
	LED5_OFF();
	LED6_OFF();
	LED7_OFF();
	LED8_OFF();		
	DelayMs(400);    
}

/*-----------------------------------------------------------------------------
Function: LedWorkingTask(void)
Description: LED red、green status set
Input:
Output:
Return:
Others: 
-----------------------------------------------------------------------------*/
void LedWorkingTask(void)
{
	if(ferror == 1)
	{
		//MOS管异常或者环境温度异常，绿灯闪烁 250ms on, 250ms off
		if(ledStatusBuf1 == 0)
		{
			ledStatusBuf1 = 1;
			LED1_ON();
			LED2_ON();
			LED3_ON();
			LED4_ON();
			LED5_ON();
			LED6_ON();
			LED7_ON();
			LED8_ON();			
		}
		else
		{
			ledStatusBuf1 = 0;
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
			LED5_OFF();
			LED6_OFF();
			LED7_OFF();
			LED8_OFF();			
		}
	}
	else if(cellNumber == 0)
	{
		if((StrChannel1.F_TAmbientHigh == 1)||(StrChannel1.F_TAmbientLow == 1)||(StrChannel2.F_TAmbientHigh == 1)||(StrChannel2.F_TAmbientLow == 1)\
			||(StrChannel3.F_TAmbientHigh == 1)||(StrChannel3.F_TAmbientLow == 1)||(StrChannel4.F_TAmbientHigh == 1)||(StrChannel4.F_TAmbientLow == 1)\
			||(StrChannel5.F_TAmbientHigh == 1)||(StrChannel5.F_TAmbientLow == 1)||(StrChannel6.F_TAmbientHigh == 1)||(StrChannel6.F_TAmbientLow == 1)\
			||(StrChannel7.F_TAmbientHigh == 1)||(StrChannel7.F_TAmbientLow == 1)||(StrChannel8.F_TAmbientHigh == 1)||(StrChannel8.F_TAmbientLow == 1))
		{
			if(ledStatusBuf1 == 0)
			{
				ledStatusBuf1 = 1;
				LED1_ON();
				LED2_ON();
				LED3_ON();
				LED4_ON();
				LED5_ON();
				LED6_ON();
				LED7_ON();
				LED8_ON();							
			}
			else
			{
				ledStatusBuf1 = 0;
				LED1_OFF();
				LED2_OFF();
				LED3_OFF();
				LED4_OFF();
				LED5_OFF();
				LED6_OFF();
				LED7_OFF();
				LED8_OFF();						
			}
		}
		else
		{
			//没有放入电池
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
			LED5_OFF();
			LED6_OFF();
			LED7_OFF();
			LED8_OFF();					
		}
	}
	else
	{
		ledBlinkingCnt++;

		if(ledStatusBuf1 == 0)
		{
			ledStatusBuf1 = 1;
		}
		else
		{
			ledStatusBuf1 = 0;
		}
		
		if(ledBlinkingCnt%4 == 0)
		{
			if(ledStatusBuf2 == 0)
			{
				ledStatusBuf2 = 1;
			}
			else
			{
				ledStatusBuf2 = 0;
			}
		}
				
		if((StrChannel1.fbad == 1)||(StrChannel1.F_TAmbientHigh == 1)||(StrChannel1.F_TAmbientLow == 1))
		{
			//异常标志,绿灯闪烁, 250ms on, 250ms off
			if(ledStatusBuf1 == 0)
			{
				LED1_ON();
			}
			else
			{
				LED1_OFF();
			}			
		}
		else if(StrChannel1.fend == 1)
		{
			//充满电,绿灯off
			LED1_ON();
		}
		else if(StrChannel1.fbat == 1)
		{
			//正在充电,led闪烁 一秒亮，一秒灭
			if(ledBlinkingCnt%4 == 0)
			{
				if(ledStatusBuf2 == 0)
				{
					LED1_ON();
				}
				else
				{
					LED1_OFF();
				}
			}			
		}
		else
		{
			//没有放入电池,green off
			LED1_OFF();
		}

		if((StrChannel2.fbad == 1)||(StrChannel2.F_TAmbientHigh == 1)||(StrChannel2.F_TAmbientLow == 1))
		{
			//异常标志,绿灯闪烁, 250ms on, 250ms off
			if(ledStatusBuf1 == 0)
			{
				LED2_ON();
			}
			else
			{
				LED2_OFF();
			}			
		}
		else if(StrChannel2.fend == 1)
		{
			//充满电,绿灯off
			LED2_ON();
		}
		else if(StrChannel2.fbat == 1)
		{
			//正在充电,led闪烁 一秒亮，一秒灭
			if(ledBlinkingCnt%4 == 0)
			{
				if(ledStatusBuf2 == 0)
				{
					LED2_ON();
				}
				else
				{
					LED2_OFF();
				}
			}			
		}
		else
		{
			//没有放入电池,green off
			LED2_OFF();
		}

		if((StrChannel3.fbad == 1)||(StrChannel3.F_TAmbientHigh == 1)||(StrChannel3.F_TAmbientLow == 1))
		{
			//异常标志,绿灯闪烁, 250ms on, 250ms off
			if(ledStatusBuf1 == 0)
			{
				LED3_ON();
			}
			else
			{
				LED3_OFF();
			}			
		}
		else if(StrChannel3.fend == 1)
		{
			//充满电,绿灯off
			LED3_ON();
		}
		else if(StrChannel3.fbat == 1)
		{
			//正在充电,led闪烁 一秒亮，一秒灭
			if(ledBlinkingCnt%4 == 0)
			{
				if(ledStatusBuf2 == 0)
				{
					LED3_ON();
				}
				else
				{
					LED3_OFF();
				}
			}			
		}
		else
		{
			//没有放入电池,green off
			LED3_OFF();
		}

		if((StrChannel4.fbad == 1)||(StrChannel4.F_TAmbientHigh == 1)||(StrChannel4.F_TAmbientLow == 1))
		{
			//异常标志,绿灯闪烁, 250ms on, 250ms off
			if(ledStatusBuf1 == 0)
			{
				LED4_ON();
			}
			else
			{
				LED4_OFF();
			}			
		}
		else if(StrChannel4.fend == 1)
		{
			//充满电,绿灯off
			LED4_ON();
		}
		else if(StrChannel4.fbat == 1)
		{
			//正在充电,led闪烁 一秒亮，一秒灭
			if(ledBlinkingCnt%4 == 0)
			{
				if(ledStatusBuf2 == 0)
				{
					LED4_ON();
				}
				else
				{
					LED4_OFF();
				}
			}			
		}
		else
		{
			//没有放入电池,green off
			LED4_OFF();
		}

		if((StrChannel5.fbad == 1)||(StrChannel5.F_TAmbientHigh == 1)||(StrChannel5.F_TAmbientLow == 1))
		{
			//异常标志,绿灯闪烁, 250ms on, 250ms off
			if(ledStatusBuf1 == 0)
			{
				LED5_ON();
			}
			else
			{
				LED5_OFF();
			}			
		}
		else if(StrChannel5.fend == 1)
		{
			//充满电,绿灯off
			LED5_ON();
		}
		else if(StrChannel5.fbat == 1)
		{
			//正在充电,led闪烁 一秒亮，一秒灭
			if(ledBlinkingCnt%4 == 0)
			{
				if(ledStatusBuf2 == 0)
				{
					LED5_ON();
				}
				else
				{
					LED5_OFF();
				}
			}			
		}
		else
		{
			//没有放入电池,green off
			LED5_OFF();
		}
		if((StrChannel6.fbad == 1)||(StrChannel6.F_TAmbientHigh == 1)||(StrChannel6.F_TAmbientLow == 1))
		{
			//异常标志,绿灯闪烁, 250ms on, 250ms off
			if(ledStatusBuf1 == 0)
			{
				LED6_ON();
			}
			else
			{
				LED6_OFF();
			}			
		}
		else if(StrChannel6.fend == 1)
		{
			//充满电,绿灯off
			LED6_ON();
		}
		else if(StrChannel6.fbat == 1)
		{
			//正在充电,led闪烁 一秒亮，一秒灭
			if(ledBlinkingCnt%4 == 0)
			{
				if(ledStatusBuf2 == 0)
				{
					LED6_ON();
				}
				else
				{
					LED6_OFF();
				}
			}			
		}
		else
		{
			//没有放入电池,green off
			LED6_OFF();
		}
		if((StrChannel7.fbad == 1)||(StrChannel7.F_TAmbientHigh == 1)||(StrChannel7.F_TAmbientLow == 1))
		{
			//异常标志,绿灯闪烁, 250ms on, 250ms off
			if(ledStatusBuf1 == 0)
			{
				LED7_ON();
			}
			else
			{
				LED7_OFF();
			}			
		}
		else if(StrChannel7.fend == 1)
		{
			//充满电,绿灯off
			LED7_ON();
		}
		else if(StrChannel7.fbat == 1)
		{
			//正在充电,led闪烁 一秒亮，一秒灭
			if(ledBlinkingCnt%4 == 0)
			{
				if(ledStatusBuf2 == 0)
				{
					LED7_ON();
				}
				else
				{
					LED7_OFF();
				}
			}			
		}
		else
		{
			//没有放入电池,green off
			LED7_OFF();
		}
		if((StrChannel8.fbad == 1)||(StrChannel8.F_TAmbientHigh == 1)||(StrChannel8.F_TAmbientLow == 1))
		{
			//异常标志,绿灯闪烁, 250ms on, 250ms off
			if(ledStatusBuf1 == 0)
			{
				LED8_ON();
			}
			else
			{
				LED8_OFF();
			}			
		}
		else if(StrChannel8.fend == 1)
		{
			//充满电,绿灯off
			LED8_ON();
		}
		else if(StrChannel8.fbat == 1)
		{
			//正在充电,led闪烁 一秒亮，一秒灭
			if(ledBlinkingCnt%4 == 0)
			{
				if(ledStatusBuf2 == 0)
				{
					LED8_ON();
				}
				else
				{
					LED8_OFF();
				}
			}			
		}
		else
		{
			//没有放入电池,green off
			LED8_OFF();
		}							
	}
}
