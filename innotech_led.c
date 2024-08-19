/******************** (C) COPYRIGHT 2021 INNOTECH **************************
* COMPANY:			INNOTECH
* DATE:				
* AUTHOR:			
* IC:				
* DESCRIPTION:	    Led Control.
*____________________________________________________________________________
* REVISION  Date		    User            Description
* 1.0		2021/11/24	    qiang.zhang		First release
*
*____________________________________________________________________________

*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "header.h"

//#define LED_GPIO_NUM_RAD 18
//#define LED_GPIO_NUM_GREEN 19

typedef enum INNOTECH_PLUG_LED_STATE
{
    LED_INITIAL,
    LED_SETUP_READY,
    LED_CONNECT_WIFI,
    LED_COMMISSIONED,
    LED_FACTORY_RESET,
    LED_RELAY_ONOFF,
} INNOTECH_PLUG_LED_STATE_T;

static uint16_t led_cnt = 0; 
static uint8_t led_play_done = 0;
static uint8_t last_led_state = 0;
static uint8_t led_state = 0;
static uint8_t relay_temp = 0xAA;
static uint8_t wifi_state = 0;
static uint8_t commission_state = 0;
static uint8_t factory_state = 0;

extern uint8_t PowerFlag;
extern uint8_t ConnectState;
extern uint8_t ack_setup_mode_state;

void innotech_factroy_led_state_set(uint8_t state)
{
    if(factory_state != state)
    {
        factory_state = state;
    }
}

uint8_t innotech_network_state_get(void)
{
    //aceWifiMgr_networkState_t state = aceWifiMgr_getNetworkState();
    return ConnectState;
}

uint8_t innotech_setup_mode_get(void)
{
    return ack_setup_mode_state;
}

void innotech_setup_mode_reset(void)
{
    ack_setup_mode_state = 0;
}

void innotech_network_state_reset(void)
{
	LED_GREEN_OFF();
	LED_RED_OFF();
    LED_WHITE_OFF();
 
    wifi_state = 0;
    led_state = LED_INITIAL;
    last_led_state = 0;
    ConnectState = 0;
    factory_state = 0;
}

uint8_t innotech_led_state_get(void)
{
    //if(wifi_state != innotech_network_state_get() || commission_state != innotech_setup_mode_get())
    if(wifi_state != innotech_network_state_get())
    {
        wifi_state = innotech_network_state_get();
 
        if (wifi_state == 1)
        {
            led_state = LED_SETUP_READY;
        }
        else if(wifi_state == 2)
        {
            led_state = LED_CONNECT_WIFI;
        }        
        else if(wifi_state == 3)
        {
            led_state = LED_COMMISSIONED;
        }
    }

    if(factory_state == 1)
    {
        led_state = LED_FACTORY_RESET;
    }

    if (led_play_done == 1 && led_state != LED_RELAY_ONOFF)
    {
        led_state = LED_RELAY_ONOFF;        
    }
    
    if (last_led_state != led_state)
    {
        last_led_state = led_state;
        led_play_done = 0;
        led_cnt = 0;
    }
    else if (led_cnt < 45000)	// 45000->30000->45000
    {
        led_cnt++;
    }

    return led_state;
}

void innotech_led_process(void)
{
    switch (innotech_led_state_get())
    {
    case LED_SETUP_READY:
        if (led_cnt % 50 == 26)
        {
            LED_GREEN_ON();
            LED_RED_OFF();
        }
        else if (led_cnt % 50 == 1)
        {
            LED_GREEN_OFF();
            LED_RED_OFF();
        }
        if (led_cnt == 45000)	// 45000->30000->45000
        {
            LED_GREEN_OFF();
            LED_RED_OFF();
            led_play_done = 1;
            innotech_network_state_reset();
        }
        break;

    case LED_CONNECT_WIFI:
        if (led_cnt == 1)
        {
            LED_GREEN_ON();
            LED_RED_OFF();
        }
        else if (led_cnt == 150)
        {
            LED_GREEN_OFF();
            LED_RED_OFF();
            led_play_done = 1;
            innotech_network_state_reset();
        }
        break;

    case LED_COMMISSIONED:
        if (led_cnt == 1)
        {
            LED_GREEN_ON();
            LED_RED_ON();
        }
        else if (led_cnt == 150)
        {
            LED_GREEN_OFF();
            LED_RED_OFF();
            led_play_done = 1;
            innotech_network_state_reset();
        }
        break;

    case LED_FACTORY_RESET:

        if (led_cnt % 50 == 26)
        {
            LED_GREEN_ON();
            LED_RED_OFF();
        }
        else if (led_cnt % 50 == 1)
        {
            LED_GREEN_OFF();
            LED_RED_ON();
        }

        break;

    case LED_RELAY_ONOFF:

        if (relay_temp != PowerFlag)
        {
            relay_temp = PowerFlag;
            if (relay_temp)
            {
				// LED_GREEN_OFF();
				// LED_RED_OFF();
                //LED_WHITE_OFF();
            }
            else
            {
				// LED_GREEN_ON();
				// LED_RED_OFF();
                //LED_WHITE_ON();
            }
        }
        break;
    
    default:
        break;
    }
}

/*
void innotech_led_init(void)
{
    gpio_mode_init(LED_GPIO_NUM_RAD, 3, 0, 1);
    gpio_mode_init(LED_GPIO_NUM_GREEN, 3, 0, 1);

    set_gpio_level_pin(LED_GPIO_NUM_RAD, 1);
    set_gpio_level_pin(LED_GPIO_NUM_GREEN, 1);
}
*/