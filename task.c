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
Description: ���ͨ�����Ƿ��е�ط����ȡ��
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void CheckChannelTask(unsigned int voltage, struct strChannel *ptCh)
{
    //ͨ���е��
	if(voltage < NO_CELL_VALUE)
	{
		if(ptCh->fbat == 0) //ͨ�����µ�ط���
		{	
            ptCh->fbat = 1;
			cellNumber++; //��ؼ�����1       
            
            ptCh->batPeakVoltage = voltage; //��ط�ֵ��ѹ����ֵ
            ptCh->vSlopeLastVoltage = voltage; //��ѹб�ʼ�⸳��ֵ
            ptCh->startCellOCV = voltage;	// ���ǰ��ص�ѹ����ֵ	
			
			if(voltage < LOW_VOLTAGE_BAT_VALUE)
			{
				ptCh->flow = 1; 
			}
			
			if(voltage > ALKALINE_BAT_VALUE)
			{
				ptCh->fbad = 1; //һ�ε��
			}
		}
	}
    //ͨ��û�е��,��ؼĴ�������
	else
	{
		if(ptCh->fbat == 1) //ͨ��ԭ���е�أ���ȡ����
		{
			cellNumber--; //��ؼ�����1
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
Description: ����ع�ѹ
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
Description: �����Ƿѹ
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void LowVoltageTask(unsigned int voltage, struct strChannel *ptCh)
{
	if((ptCh->timeCount > 15) && (voltage < BAT_LOWVOLTAGE_VALUE)) //����30��
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
Description: ���-dV��0dV
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void DvTask(unsigned int voltage, struct strChannel *ptCh)
{
    //��ص�ѹ����
    if(voltage > ptCh->batPeakVoltage)
    {
        if(++ptCh->batVoltageRiseCount >= 5)
        {
            ptCh->batPeakVoltage+=1; //��ص�ѹ����5����������ѹ��ֵ+1
            ptCh->dvCount = 0;
            ptCh->_0dvTimer = 0;
        }
    }
    //��ص�ѹ������½�
    else
    {
        ptCh->batVoltageRiseCount = 0;
        //-dV���
        if((voltage < DV_THRESHOLD_VOLTAGE) || (ptCh->timeCount < 150)) //��ص�ѹ����������ֵ��ʱ��С��5����
        {
            ptCh->dvCount = 0;
        }
        //��ѹ�½����ȳ����趨��ֵ
        else if((ptCh->batPeakVoltage - voltage) >= DV_VALUE)
        {
            //����10������-dV�������趨��ֵ
            if(++ptCh->dvCount >= 10)
            {
                ptCh->fend = TRUE; //-dV���㣬��س���
            }
        }
        //��ѹ�½�����δ�����趨��ֵ
        else
        {
            ptCh->dvCount = 0;
        }
        //0dV���
        if(ptCh->batPeakVoltage < _0DV_THRESHOLD_VOLTAGE) //��ص�ѹ����������ֵ
        {
            ptCh->_0dvTimer = 0;
        }
        else
        {
            ptCh->_0dvTimer += 1;
            if(ptCh->_0dvTimer >= _0DV_TIME)
            {
				ptCh->fend = TRUE; //0dV���㣬��س���
            }
        }
    }
}
/*-----------------------------------------------------------------------------
Function: VSlopeTask()
Description: ����ѹб��
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void VSlopeTask(unsigned int voltage, struct strChannel *ptCh)
{
    //unsigned int voltageDifference;

    //���OCVС����ֵ
    if(voltage < VSLOPE_THRESHOLD_VOLTAGE)
    {
        ptCh->vSlopePeakValue = 0;
        ptCh->vSlopeCount = 0;
        ptCh->vSlopeLastVoltage = voltage;
        ptCh->vSlopeTimeCount = 0;
        return;
    }
    //ʱ����δ���趨ֵ��1�ڵ��300*1=5���ӣ�4�ڵ��300*4=20����
    if(++ptCh->vSlopeTimeCount == 60)
    {
        ptCh->vSlopeTimeCount = 0;

        //��ѹ������������ε�ѹ��ֵ�������ѹ��ֵΪ0
        if(voltage > ptCh->vSlopeLastVoltage)
        {
			voltageDifference = voltage - ptCh->vSlopeLastVoltage;
        }
        else
        {
            voltageDifference = 0;
        }
        //����ǰ�ε�ѹ
        ptCh->vSlopeLastVoltage = voltage;

        //Ϊ������ŵ��µ����������ѹ��ֵ���������ֵ���ѹ����ֵ�޶�Ϊ���ֵ
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
        //�����ѹ���������ѹ���ֵ��1
        else if(voltageDifference > ptCh->vSlopePeakValue)
        {
            ptCh->vSlopePeakValue += 1;
            ptCh->vSlopeCount = 0;
        }
        //�����ѹ���С�����ѹ���ֵ��1�Ա�����ţ�����3�ε�ѹ���С����ֹͣ
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
		//��ѹб�ʲ���
		else
		{
			ptCh->vSlopeCount = 0;
			return;
		}
    }
}
/*-----------------------------------------------------------------------------
Function: LithiumIronBatteryDetectTask()
Description: ����ѹб��
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
Description: ���MOS���Ƿ����
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
Description: �����ʱ���Ƿ�ﵽ�趨ֵ
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void ChargingTimerTask(struct strChannel *ptCh)
{
	if(ptCh->fend == 0)
	{
		//�������ʱ���ж�
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
Description: ��⻷���¶��Ƿ񳬳���Χ
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
Description: ������¶��Ƿ��г�����Χ���Ƿ��лָ�������
Input:
    overTemperatureCount: ���·�������
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
Description: һ���Ե�ؼ��
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
Description: LED red��green status set
Input:
Output:
Return:
Others: 
-----------------------------------------------------------------------------*/
void LedWorkingTask(void)
{
	if(ferror == 1)
	{
		//MOS���쳣���߻����¶��쳣���̵���˸ 250ms on, 250ms off
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
			//û�з�����
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
			//�쳣��־,�̵���˸, 250ms on, 250ms off
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
			//������,�̵�off
			LED1_ON();
		}
		else if(StrChannel1.fbat == 1)
		{
			//���ڳ��,led��˸ һ������һ����
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
			//û�з�����,green off
			LED1_OFF();
		}

		if((StrChannel2.fbad == 1)||(StrChannel2.F_TAmbientHigh == 1)||(StrChannel2.F_TAmbientLow == 1))
		{
			//�쳣��־,�̵���˸, 250ms on, 250ms off
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
			//������,�̵�off
			LED2_ON();
		}
		else if(StrChannel2.fbat == 1)
		{
			//���ڳ��,led��˸ һ������һ����
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
			//û�з�����,green off
			LED2_OFF();
		}

		if((StrChannel3.fbad == 1)||(StrChannel3.F_TAmbientHigh == 1)||(StrChannel3.F_TAmbientLow == 1))
		{
			//�쳣��־,�̵���˸, 250ms on, 250ms off
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
			//������,�̵�off
			LED3_ON();
		}
		else if(StrChannel3.fbat == 1)
		{
			//���ڳ��,led��˸ һ������һ����
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
			//û�з�����,green off
			LED3_OFF();
		}

		if((StrChannel4.fbad == 1)||(StrChannel4.F_TAmbientHigh == 1)||(StrChannel4.F_TAmbientLow == 1))
		{
			//�쳣��־,�̵���˸, 250ms on, 250ms off
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
			//������,�̵�off
			LED4_ON();
		}
		else if(StrChannel4.fbat == 1)
		{
			//���ڳ��,led��˸ һ������һ����
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
			//û�з�����,green off
			LED4_OFF();
		}

		if((StrChannel5.fbad == 1)||(StrChannel5.F_TAmbientHigh == 1)||(StrChannel5.F_TAmbientLow == 1))
		{
			//�쳣��־,�̵���˸, 250ms on, 250ms off
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
			//������,�̵�off
			LED5_ON();
		}
		else if(StrChannel5.fbat == 1)
		{
			//���ڳ��,led��˸ һ������һ����
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
			//û�з�����,green off
			LED5_OFF();
		}
		if((StrChannel6.fbad == 1)||(StrChannel6.F_TAmbientHigh == 1)||(StrChannel6.F_TAmbientLow == 1))
		{
			//�쳣��־,�̵���˸, 250ms on, 250ms off
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
			//������,�̵�off
			LED6_ON();
		}
		else if(StrChannel6.fbat == 1)
		{
			//���ڳ��,led��˸ һ������һ����
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
			//û�з�����,green off
			LED6_OFF();
		}
		if((StrChannel7.fbad == 1)||(StrChannel7.F_TAmbientHigh == 1)||(StrChannel7.F_TAmbientLow == 1))
		{
			//�쳣��־,�̵���˸, 250ms on, 250ms off
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
			//������,�̵�off
			LED7_ON();
		}
		else if(StrChannel7.fbat == 1)
		{
			//���ڳ��,led��˸ һ������һ����
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
			//û�з�����,green off
			LED7_OFF();
		}
		if((StrChannel8.fbad == 1)||(StrChannel8.F_TAmbientHigh == 1)||(StrChannel8.F_TAmbientLow == 1))
		{
			//�쳣��־,�̵���˸, 250ms on, 250ms off
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
			//������,�̵�off
			LED8_ON();
		}
		else if(StrChannel8.fbat == 1)
		{
			//���ڳ��,led��˸ һ������һ����
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
			//û�з�����,green off
			LED8_OFF();
		}							
	}
}
