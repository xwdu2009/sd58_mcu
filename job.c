/*-----------------------------------------------------------------------------
Copyright 2019-2022 INNOTECH Technology Co.,Ltd All Rights Reserved.
FileName: job.c
Author: Dean Zhang
Version:V1.0.2
Date:2021-10-19
Description: CK0351ÿ������״̬�µ���������
History:<author> <time> <version > <desc>
-----------------------------------------------------------------------------*/
#include "header.h"
/*-----------------------------------------------------------------------------
Function: ChannelInit(void)
Description: ���ͨ����ʼ��
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void ChannelInit(void)
{
    StrChannel1.channel = 1;
    StrChannel2.channel = 2;
	StrChannel3.channel = 3;
    StrChannel4.channel = 4;
    StrChannel5.channel = 5;
    StrChannel6.channel = 6;
    StrChannel7.channel = 7;
    StrChannel8.channel = 8;  
    
}
/*-----------------------------------------------------------------------------
Function: CheckChannelJob(void)
Description: �رճ����������ͨ����ط��롢ȡ��
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void CheckChannelJob(void)
{
	unsigned char fullchargecnt = 0;
    
	if (0 == cellNumber) { TURN_OFF_CURRENT(); }//�رճ�����

    TURN_OFF_CHANNEL1(); //�ر�ͨ��Mos
    TURN_OFF_CHANNEL2();
	TURN_OFF_CHANNEL3();
    TURN_OFF_CHANNEL4();
    TURN_OFF_CHANNEL5();
    TURN_OFF_CHANNEL6();
    TURN_OFF_CHANNEL7();
    TURN_OFF_CHANNEL8();

	//TURN_OFF_CHANNEL_ALL();
    
	CHANNEL_PULL_HIGH();  
	
	voltage = GetAdcData(GetChannelnTempADCCanel(StrChannel1.channel));
	OverAmbientTemperatureTask(voltage, &StrChannel1);
	OverAmbientTemperatureTask(voltage, &StrChannel2);
	voltage = GetAdcData(GetChannelnTempADCCanel(StrChannel3.channel));
	OverAmbientTemperatureTask(voltage, &StrChannel3);
	OverAmbientTemperatureTask(voltage, &StrChannel4);
	voltage = GetAdcData(GetChannelnTempADCCanel(StrChannel5.channel));
	OverAmbientTemperatureTask(voltage, &StrChannel5);
	OverAmbientTemperatureTask(voltage, &StrChannel6);
	voltage = GetAdcData(GetChannelnTempADCCanel(StrChannel7.channel));
	OverAmbientTemperatureTask(voltage, &StrChannel7);
	OverAmbientTemperatureTask(voltage, &StrChannel8);       
	
	if((StrChannel1.F_TAmbientHigh == 0)&&(StrChannel1.F_TAmbientLow == 0))
	{
		voltage = GetAdcData(ADC_BATTERY1);
		CheckChannelTask(voltage, &StrChannel1);	
	}
	if((StrChannel2.F_TAmbientHigh == 0)&&(StrChannel2.F_TAmbientLow == 0))
	{
		voltage = GetAdcData(ADC_BATTERY2);
		CheckChannelTask(voltage, &StrChannel2);	
	}
	if((StrChannel3.F_TAmbientHigh == 0)&&(StrChannel3.F_TAmbientLow == 0))
	{
		voltage = GetAdcData(ADC_BATTERY3);
		CheckChannelTask(voltage, &StrChannel3);	
	}
	if((StrChannel4.F_TAmbientHigh == 0)&&(StrChannel4.F_TAmbientLow == 0))
	{
		voltage = GetAdcData(ADC_BATTERY4);
		CheckChannelTask(voltage, &StrChannel4);	
	}
	if((StrChannel5.F_TAmbientHigh == 0)&&(StrChannel5.F_TAmbientLow == 0))
	{
		voltage = GetAdcData(ADC_BATTERY5);
		CheckChannelTask(voltage, &StrChannel5);	
	}
	if((StrChannel6.F_TAmbientHigh == 0)&&(StrChannel6.F_TAmbientLow == 0))
	{
		voltage = GetAdcData(ADC_BATTERY6);
		CheckChannelTask(voltage, &StrChannel6);	
	}
	if((StrChannel7.F_TAmbientHigh == 0)&&(StrChannel7.F_TAmbientLow == 0))
	{
		voltage = GetAdcData(ADC_BATTERY7);
		CheckChannelTask(voltage, &StrChannel7);	
	}
	if((StrChannel8.F_TAmbientHigh == 0)&&(StrChannel8.F_TAmbientLow == 0))
	{
		voltage = GetAdcData(ADC_BATTERY8);
		CheckChannelTask(voltage, &StrChannel8);	
	}        

	CHANNEL_NOT_PULL_HIGH();

    if (0 != cellNumber) 
    { 
 		if((StrChannel1.fbad == 1) || (StrChannel1.f1hour == 1))
			fullchargecnt++;
 		if((StrChannel2.fbad == 1) || (StrChannel2.f1hour == 1))
			fullchargecnt++;            
 		if((StrChannel3.fbad == 1) || (StrChannel3.f1hour == 1))
			fullchargecnt++; 
  		if((StrChannel4.fbad == 1) || (StrChannel4.f1hour == 1))
			fullchargecnt++;
 		if((StrChannel5.fbad == 1) || (StrChannel5.f1hour == 1))
			fullchargecnt++;
 		if((StrChannel6.fbad == 1) || (StrChannel6.f1hour == 1))
			fullchargecnt++;            
  		if((StrChannel7.fbad == 1) || (StrChannel7.f1hour == 1))
			fullchargecnt++;           
  		if((StrChannel8.fbad == 1) || (StrChannel8.f1hour == 1))
			fullchargecnt++;   
            
        if(fullchargecnt == cellNumber)    
        { 
			TURN_OFF_CURRENT();  //�رճ�����
        }
        else   	
        {		         
			TURN_ON_CURRENT();  //�򿪳�����
        }
    }	    
    
	channelControl = DUTYADJUST;
}

/*-----------------------------------------------------------------------------
Function: DutyAdjustmentJob(void)
Description: �رճ����������ͨ����ط��롢ȡ��
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void DutyAdjustmentJob(void)
{
    //������������1�ڻ�3�ڵ�أ��򲹳�һ��1��Ŀ��У���֤1-2����1/2 Duty��3-4����1/4 Duty
    if(cellNumber == 0)
    {
        if(++dutyCounter >= 203) // 200->203
        {
            dutyCounter = 0;
            channelControl = CHECKCHANNEL;
            ChargingChannel = 0;
        }
    }
	else if((cellNumber == 1)||(cellNumber == 3)||(cellNumber == 5)||(cellNumber == 7)) //1�ڻ���3�ڵ��ʱ����Ҫ�ֿ�һ������
	{
		if (0 == ChargingChannel || ChargingChannel >= CHANNEL8)
        {
        	if(++dutyCounter >= 203)	// 200->203
	        {
	            dutyCounter = 0;
	            channelControl = CHECKCHANNEL;
	            ChargingChannel = CHANNEL1;
				channelControl = ChargingChannel;
	        }
        } 
        else
        {
            ChargingChannel++;
			channelControl = ChargingChannel;
        }
        
	}
    else
    {
        if (0 == ChargingChannel || ChargingChannel >= CHANNEL8)	// 8 Channel
        {
            ChargingChannel = CHANNEL1;
        } 
        else
        {
            ChargingChannel++;
        }
        channelControl = ChargingChannel;
    }    
}



void TurnOnChannel(unsigned char channel)
{
    switch (channel)
    {
    case 1:
        TURN_ON_CHANNEL1();
        break;
    case 2:
        TURN_ON_CHANNEL2();
        break;
	case 3:
        TURN_ON_CHANNEL3();
        break;
    case 4:
        TURN_ON_CHANNEL4();
        break;
    case 5:
        TURN_ON_CHANNEL5();
        break;        
    case 6:
        TURN_ON_CHANNEL6();
        break;
	case 7:
        TURN_ON_CHANNEL7();
        break;
    case 8:
        TURN_ON_CHANNEL8();
        break;               
    default:
        break;
    }
}

void TurnOffChannel(unsigned char channel)
{
    switch (channel)
    {
    case 1:
        TURN_OFF_CHANNEL1();
        break;
    case 2:
        TURN_OFF_CHANNEL2();
		break;
	case 3:
		TURN_OFF_CHANNEL3();
		break;
	case 4:
		TURN_OFF_CHANNEL4();
        break;
	case 5:
		TURN_OFF_CHANNEL5();
        break;
	case 6:
		TURN_OFF_CHANNEL6();
        break;
	case 7:
		TURN_OFF_CHANNEL7();
        break;
	case 8:
		TURN_OFF_CHANNEL8();
        break;                            
    default:
        break;
    }
}

unsigned int GetChannelnVcdADCCanel(unsigned char channel)
{
    unsigned int ret = 0;
    switch (channel)
    {
    case 1:
        ret = ADC_BATTERY1;
        break;
    case 2:
        ret = ADC_BATTERY2;
        break;
	case 3:
		ret = ADC_BATTERY3;
		break;
	case 4:
		ret = ADC_BATTERY4;
		break;
	case 5:
		ret = ADC_BATTERY5;
		break;
	case 6:
		ret = ADC_BATTERY6;
		break;
 	case 7:
		ret = ADC_BATTERY7;
		break;
	case 8:
		ret = ADC_BATTERY8;
		break;                             
    default:
        break;
    }

    return ret;
}


unsigned int GetChannelnTempADCCanel(unsigned char channel)
{
    unsigned int ret = 0;
    switch (channel)
    {
	    case 1:
	        ret = ADC_TEMPERATURE1;
	        break;
	    case 2:
	        ret = ADC_TEMPERATURE1;
	        break;
		case 3:
	        ret = ADC_TEMPERATURE2;
	        break;
	    case 4:
	        ret = ADC_TEMPERATURE2;
	        break;
		case 5:
	        ret = ADC_TEMPERATURE3;
	        break;
	    case 6:
	        ret = ADC_TEMPERATURE3;
	        break;
		case 7:
	        ret = ADC_TEMPERATURE4;
	        break;
	    case 8:
	        ret = ADC_TEMPERATURE4;
	        break;                        

	    default:
	        break;
    }

    return ret;
}

/*-----------------------------------------------------------------------------
Function: ChannelnJob(void)
Description: ͨ��n������
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void ChannelnJob(struct strChannel* ptCh)
{
	dutyCounter++;

    //�޵�أ�ֱ��������ͨ��
    if (ptCh->fbat == 0)
    {
    	dutyCounter = 0;
        channelControl = CHECKCHANNEL;
        return;
    }
    //����أ��������رգ�ֻ��ʱ1��
    else if (ptCh->fbad == 1)
    {
		TurnOffChannel(ptCh->channel);
		if (dutyCounter >= 203)	// 200->203
		{
			dutyCounter = 0;
			channelControl = CHECKCHANNEL; 
		}
    }
	//�������
	else if(ptCh->f1hour == 1)
	{
		TurnOffChannel(ptCh->channel);
		if (dutyCounter >= 203)	// 200->203
		{
			dutyCounter = 0;
			channelControl = CHECKCHANNEL; 
		}
	}
    //������������׶�
    else if (ptCh->fend == 1)
    {
        //ǰ0.05�������,ʣ��0.95������ر�
        if (dutyCounter <= 10)
        {
            TurnOnChannel(ptCh->channel);
        }
        else
        {
            TurnOffChannel(ptCh->channel);
            //1��Dutyʱ�䵽
            if (dutyCounter >= 203)	// 200->203
            {
            	dutyCounter = 0;
				channelControl = CHECKCHANNEL;
				ChargingTimerTask(ptCh); //����OK			
            }
        }
    }
	else if(ptCh->flow == 1)
	{
		//��ѹ��س��
		if(dutyCounter <= 20)
		{
			TurnOnChannel(ptCh->channel);			
		}
		else
		{
			TurnOffChannel(ptCh->channel);
			
			if(dutyCounter == 50)
			{
				ChargingTimerTask(ptCh); //����OK		
				voltage = GetAdcData(GetChannelnVcdADCCanel(ptCh->channel));
				if(voltage > 1365)
				{
					ptCh->flow = 0;
				}
				if(ptCh->timeCount > 30)
				{
					ptCh->fbad = 1;
				}
			}
			
			if (dutyCounter >= 203)	// 200->203
            {
            	dutyCounter = 0;
				channelControl = CHECKCHANNEL;	
            }
		}
	}
    //������������
    else
    {
        //DutyΪ1�룬ǰ0.98��Ϊ�������򿪽׶�
        if (dutyCounter <= 196)		// 194->190
        {
	        TurnOnChannel(ptCh->channel);
            //0.97���ʱ����е��CCV��ѹ���
            if (dutyCounter == 194)	//192->186
            {
                voltage = GetAdcData(GetChannelnVcdADCCanel(ptCh->channel));
                ptCh->cellCCV = voltage;
                OverVoltageTask(voltage, ptCh);
                ChangeVoltageTask(voltage, ptCh);
            }
        }

        //0.97-1.0��رճ���������OCV��صļ��
        else
        {
			TurnOffChannel(ptCh->channel);
			//0.99��ʱ���-dv��0dv��vslop����ѹ���
			if (dutyCounter == 200)	// 198->200
			{
				voltage = GetAdcData(GetChannelnVcdADCCanel(ptCh->channel));				
				ptCh->cellOCV = voltage;

				PrimaryBatteryTask(voltage, ptCh); //һ�ε�ز���
				LowVoltageTask(voltage, ptCh); //����OK
				DvTask(voltage, ptCh); //����OK
				VSlopeTask(voltage, ptCh);
				//LithiumIronBatteryDetectTask(voltage, &StrChannel1);
				MosFailTask(ptCh); //����OK
				ChargingTimerTask(ptCh); //����OK
				voltage = GetAdcData(GetChannelnTempADCCanel(ptCh->channel));
				OverTemperatureTask(voltage, ptCh); //����OK
			}
			//Duty��1��
			else if (dutyCounter == 203)	// 200->203
			{
				dutyCounter = 0;
				channelControl = CHECKCHANNEL;
			}
        }
    }
}

/*-----------------------------------------------------------------------------
Function: ErrorJob(void)
Description: ������쳣��MOS����·��NTC����·
Input:
Output:
Return:
Others:
-----------------------------------------------------------------------------*/
void ErrorJob(void)
{
	TURN_OFF_CURRENT(); 	//�رճ�����
    
    TURN_OFF_CHANNEL1(); 	//�ر�����ͨ��Mos
    TURN_OFF_CHANNEL2();
	TURN_OFF_CHANNEL3(); 
    TURN_OFF_CHANNEL4();
    TURN_OFF_CHANNEL5(); 	
    TURN_OFF_CHANNEL6();
	TURN_OFF_CHANNEL7(); 
    TURN_OFF_CHANNEL8();    

//	TURN_OFF_CHANNEL_ALL();
}
