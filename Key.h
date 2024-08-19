#ifndef _Key_h_
#define _Key_h_

#include "header.h"


uint8 KeyCheakDIM_PMLearn(void);
uint8 KeyCheakPowerOn(void);
uint8 KeyCheakPowerOff(void);
uint8 KeyCheakDIMM(void);
uint8 KeyCheakDIMP(void);


#define KEY_DIMP_SHORT			1
#define KEY_DIMP_LONG			    2	//按住松开
#define KEY_DIMM_SHORT			3
#define KEY_DIMM_LONG			    4	//按住松开

#define KEY_DIM_BOTH_LONG		5

#define KEY_DIMPOWER_SHORT		8
#define KEY_DIMPOWER_LONG		    9	//长按

#define KEY_POWERON_SHORT		10
#define KEY_POWERON_LONG		    11	//长按

#define KEY_POWEROFF_SHORT		12
#define KEY_POWEROFF_LONG		    13	//长按

#define KEY_POWERON_DOUBLE		14
#define KEY_POWEROFF_DOUBLE		    15

#define KEY_DIMP_DOUBLE		    16
#define KEY_DIMM_DOUBLE		        17

#define DEV_TYPE_GRADUAL		0		// 灯光渐变Dimmer
#define DEV_TYPE_INSTANT		1		// 灯光无渐变Dimmer
#define DEV_TYPE_SWITCH 		2		// 无调光Dimmer,只有ON,OFF,类似SWITCH

//extern uint8 DeviceType;
#endif

