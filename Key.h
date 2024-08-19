#ifndef _Key_h_
#define _Key_h_

#include "header.h"


uint8 KeyCheakDIM_PMLearn(void);
uint8 KeyCheakPowerOn(void);
uint8 KeyCheakPowerOff(void);
uint8 KeyCheakDIMM(void);
uint8 KeyCheakDIMP(void);


#define KEY_DIMP_SHORT			1
#define KEY_DIMP_LONG			    2	//��ס�ɿ�
#define KEY_DIMM_SHORT			3
#define KEY_DIMM_LONG			    4	//��ס�ɿ�

#define KEY_DIM_BOTH_LONG		5

#define KEY_DIMPOWER_SHORT		8
#define KEY_DIMPOWER_LONG		    9	//����

#define KEY_POWERON_SHORT		10
#define KEY_POWERON_LONG		    11	//����

#define KEY_POWEROFF_SHORT		12
#define KEY_POWEROFF_LONG		    13	//����

#define KEY_POWERON_DOUBLE		14
#define KEY_POWEROFF_DOUBLE		    15

#define KEY_DIMP_DOUBLE		    16
#define KEY_DIMM_DOUBLE		        17

#define DEV_TYPE_GRADUAL		0		// �ƹ⽥��Dimmer
#define DEV_TYPE_INSTANT		1		// �ƹ��޽���Dimmer
#define DEV_TYPE_SWITCH 		2		// �޵���Dimmer,ֻ��ON,OFF,����SWITCH

//extern uint8 DeviceType;
#endif

