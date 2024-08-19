#include "header.h"
#include "Key.h"

uint8 KeyState = 0;
uint16 KeyNumer = 0;
uint8 KeyState1 = 0;
uint8 KeyNumer1 = 0;

extern uint8_t UartTxBuf[6]; 

uint8 KeyCheakDIM_PMLearn(void)//+-study mode
{
	switch(KeyState)
	{
		case 0:
			if((IO_DIMP==0)&&(IO_DIMM==0))
			{
				KeyState1 = 0;
				KeyNumer1 = 0;
				if(++KeyNumer>=500)//5s
				{
					KeyNumer = 0;
					KeyState = 1;
					return KEY_DIM_BOTH_LONG;
				}
			}
			else
			{
				KeyNumer = 0;
				switch(KeyState1)//单独按键
				{
					case 0:
						KeyNumer1++;
						if(IO_DIMP==0)
						{
							if(KeyNumer1 >= 3)
							{
								KeyNumer1 = 0;
								KeyState1 = 1;
							}
						}
						else if(IO_DIMM==0)
						{
							if(KeyNumer1 >= 3)
							{
								KeyNumer1 = 0;
								KeyState1 = 4;
							}
						}
						else
							KeyNumer1 = 0;
						break;
					case 1:
						if(IO_DIMP)
						{
							KeyState1 = 0;
							return KEY_DIMP_SHORT;
						}
						if(++KeyNumer1 >= 100)//1s内单击才有效
						{
							KeyNumer1 = 0;
							KeyState1 = 2;
						}
						break;
					case 2:
						if(++KeyNumer1 >= 3)//加上上面的1s共2s 100->50->10 2.0->1.5s->1.1s
						{
							KeyNumer1 = 0;
							KeyState1 = 3;
						}
						if(IO_DIMP)//退出
						{
							KeyState1 = 0;
						}
						break;
					case 3:
						if(IO_DIMP)//退出
						{
							KeyState1 = 0;
						}
						return KEY_DIMP_LONG;
						break;
					case 4:
						if(IO_DIMM)
						{
							KeyState1 = 0;
							return KEY_DIMM_SHORT;
						}
						if(++KeyNumer1 >= 100)//1s内单击才有效
						{
							KeyNumer1 = 0;
							KeyState1 = 5;
						}
						break;
					case 5:
						if(++KeyNumer1 >= 3)//加上上面的1s共2s 100->50->10 2.0->1.5s->1.1s
						{
							KeyNumer1 = 0;
							KeyState1 = 6;
						}
						if(IO_DIMM)//退出
						{
							KeyState1 = 0;
						}
						break;
					case 6:
						if(IO_DIMM)//退出
						{
							KeyState1 = 0;
						}
						return KEY_DIMM_LONG;
						break;
					default:
						break;
				}
			}
			break;
		case 1:
			if((IO_DIMP)||(IO_DIMM))
			{
				KeyState = 0;
				KeyNumer = 0;
				KeyNumer1 = 0;
			}
			break;
		default:
			break;
	}
	return 0;
}

#if 0
uint8 KeyState3 = 0;
uint16 KeyNumer3 = 0;
uint8 KeyCheakPowerOn(void)
{
	switch(KeyState3)
	{
		case 0:
			if(IO_POWER_ON==0)
			{
				if(++KeyNumer3 >= 3)
				{
					KeyNumer3 = 0;
					KeyState3 = 1;
				}
			}
			else
				KeyNumer3 = 0;
			break;
		case 1:
			if(IO_POWER_ON)
			{
				KeyState3 = 0;
				//return KEY_DIMPOWER_SHORT;
                return KEY_POWERON_SHORT;
			}
			if(++KeyNumer3 >= 100)//1s内单击才有效
			{
				KeyNumer3 = 0;
				KeyState3 = 2;
			}
			break;
		case 2:		
			if(++KeyNumer3 >= 900)//5s内单击才有效 400->900 5S->10S
			{
				KeyNumer3 = 0;
				KeyState3 = 3;
				//return KEY_DIMPOWER_LONG;
                return KEY_POWERON_LONG;
			}			
			//退出
			if(IO_POWER_ON)
			{
				KeyState3 = 0;
			}
			break;
		case 3:
			//退出
			if(IO_POWER_ON)
			{
				KeyState3 = 0;
                
				UartTxBuf[0] = 0x55;
				UartTxBuf[1] = 0xaa;
				UartTxBuf[2] = UART_CMD_RESET;
				UartTxBuf[3] = 0x0;
				UartSendData();     
                
                innotech_network_state_reset();                       
			}
			break;
		default:
			break;
	}
	return 0;
}
#endif

#if 0
uint8 KeyState3 = 0;
uint16 KeyNumer3 = 0;
uint8_t KeyPressFlag = 0;
uint16_t KeyIntervalCnt = 0;
// uint16_t KeyRelesaseCnt = 0;
// uint16_t KeyPressCnt = 0;
uint8 KeyCheakPowerOn(void)
{
	uint16_t KeyRelesaseCnt = 0;
	uint16_t KeyPressCnt = 0;

	KeyIntervalCnt++;
    if(IO_POWER_ON == 0)
	{
		KeyPressCnt = KeyIntervalCnt;
		while(IO_POWER_ON == 0);
		KeyRelesaseCnt = KeyIntervalCnt;
	}	

	if(KeyRelesaseCnt - KeyPressCnt < 50 && KeyRelesaseCnt - KeyPressCnt > 0)
	{
		DelayMs(200);
		if(IO_POWER_ON == 0)
			return KEY_POWERON_DOUBLE;
		else if(IO_POWER_ON == 1)	
			return KEY_POWERON_SHORT;
	}
	else if(KeyRelesaseCnt - KeyPressCnt > 50)
	{
		return KEY_POWERON_LONG;
	}

	return 0;
}
#endif


#if 1
uint8 KeyCheakPowerOn(void)
{
    static unsigned char key1_state = 0;
    static unsigned short int key1_count = 0;

    const static unsigned char Time_sensitivity = 30;//300mS
	const static unsigned short int  Time_long = 300;//3S upload log
	const static unsigned short int  Time_vlong = 1000;//10S factory reset

    unsigned char key_value = 0;

    if(IO_POWER_ON == 0) 
	{
        if (key1_state == 0) 
		{
            key1_state = 1;
        } 
		else if ((key1_state == 2) && (key1_count < Time_sensitivity))
		{
            key1_state = 3;
        }
		else if((key1_state == 1) && (key1_count > Time_vlong))
		{
			key1_count = 0;
			key1_state = 5;
			key_value = KEY_POWERON_LONG;
		}
    }
	else 
	{
        if (key1_state == 1) 
		{
            key1_state = 2;
        } 
		else if (key1_state == 3) 
		{
            key1_state = 4;
            key1_count = 0;
            if (key1_count < Time_sensitivity) 
			{
                key_value = KEY_POWERON_DOUBLE;//3;
                key1_state = 0;
                key1_count = 0;
            }
        }
		else if (key1_state == 5) 
		{		
			key_value = 0;
			key1_state = 0;
			key1_count = 0;

			UartTxBuf[0] = 0x55;
			UartTxBuf[1] = 0xaa;
			UartTxBuf[2] = UART_CMD_RESET;
			UartTxBuf[3] = 0x0;
			UartSendData();     
							
			innotech_network_state_reset();
		}
    }

    if (key1_state) 
	{
        key1_count++;
    }

    if ((key1_state == 2) && (key1_count > Time_sensitivity)) 
	{
        key_value = KEY_POWERON_SHORT;//1;
        key1_state = 0;
        key1_count = 0;
    }

	return key_value;
}
#endif


uint8 KeyState4 = 0;
uint16 KeyNumer4 = 0;
uint8 KeyCheakPowerOff(void)
{
	switch(KeyState4)
	{
		case 0:
			if(IO_POWER_OFF==0)
			{
				if(++KeyNumer4 >= 3)
				{
					KeyNumer4 = 0;
					KeyState4 = 1;
				}
			}
			else
				KeyNumer4 = 0;
			break;
		case 1:
			if(IO_POWER_OFF)
			{
				KeyState4 = 0;
				return KEY_POWEROFF_SHORT;
			}
			if(++KeyNumer4 >= 100)//1s内单击才有效
			{
				KeyNumer4 = 0;
				KeyState4 = 2;
			}
			break;
		case 2:		
			if(++KeyNumer4 >= 900)//5s内单击才有效  400->900 5S->10S
			{
				KeyNumer4 = 0;
				KeyState4 = 3;
				return KEY_POWEROFF_LONG;
			}			
			//退出
			if(IO_POWER_OFF)
			{
				KeyState4 = 0;
			}
			break;
		case 3:
			//退出
			if(IO_POWER_OFF)
			{
				KeyState4 = 0;
                
 				UartTxBuf[0] = 0x55;
				UartTxBuf[1] = 0xaa;
				UartTxBuf[2] = UART_CMD_RESET;
				UartTxBuf[3] = 0x0;
				UartSendData();     
                               
                innotech_network_state_reset();
			}
			break;
		default:
			break;
	}
	return 0;
}


