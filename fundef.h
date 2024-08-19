/*-----------------------------------------------------------------------------
Copyright 2019-2022 INNOTECH Technology Co.,Ltd All Rights Reserved.
FileName: fundef.h
Author: 
Version:V1.0.0
Date:
Description: 
Function List: 
History:<author> <time> <version > <desc>
-----------------------------------------------------------------------------*/
#ifndef _FUNDEF_H
#define _FUNDEF_H

#include "header.h"

//public.c
void SysInitial(void);
void DelayUs(unsigned char Time);
//void DelayMs(unsigned char Time);
void DelayMs(unsigned short Time);
void DelayS(unsigned char Time);
void IoIntInitial(void);
void Time1Initial(void);
void Time2Initial(void);
void Time4Initial(void);
void UartInitial(void);
void WdtInitial(void);
void AdcInitial(void);
void LvdInitial(void);
void UartReceiveData(uint8_t RcvData);
void UartSendData(void);
void UartB_Process(void);

unint GetAdcData(unchar adcChannel);
unchar EEPROMread(unchar EEAddr);
void EEPROMwrite(unchar EEAddr,unchar Data);
void TIM2_ResetPeriod(uint16 Period, uint8 NewState);
void Load_Scan(void);
void Connect_With_Switch(void);
void mcu_dp_value_update(uint8_t sync_cmd,uint8 sync_data);
void mcu_dp_value_update_debug(uint8_t sync_cmd);

// innotech_led.c
void innotech_led_process(void);
void innotech_factroy_led_state_set(uint8_t state);
void innotech_network_state_reset(void);

//job.c
//void ChannelInit(void);
//void ChannelnJob(struct strChannel* ptCh);
//void CheckChannelJob(void);
//void Channel1Job(void);
//void Channel2Job(void);
//void Channel3Job(void);
//void Channel4Job(void);
//void ErrorJob(void);

//task.c
//void CheckChannelTask(unsigned int voltage, struct strChannel *ptCh);
//void OverVoltageTask(unsigned int voltage, struct strChannel *ptCh);
//void PrimaryBatteryTask(unsigned int voltage, struct strChannel *ptCh);
//void LowVoltageTask(unsigned int voltage, struct strChannel *ptCh);
//void DvTask(unsigned int voltage, struct strChannel *ptCh);
//void VSlopeTask(unsigned int voltage, struct strChannel *ptCh);
//void LithiumIronBatteryDetectTask(unsigned int voltage, struct strChannel *ptCh);
//void MosFailTask(struct strChannel *ptCh);
//void ChargingTimerTask(struct strChannel *ptCh);
//void OverTemperatureTask(unsigned int voltage, struct strChannel *ptCh);
//void OverAmbientTemperatureTask(unsigned int voltage, struct strChannel *ptCh);
//unsigned int GetChannelnVcdADCCanel(unsigned char channel);
//unsigned int GetChannelnTempADCCanel(unsigned char channel);
//void LedWorkingTask(void);
//void LedInitTask(void);
//void JudgeAAATask(struct strChannel *ptCh);
//void TurnOnChannel(unsigned char channel);
//void TurnOffChannel(unsigned char channel);
//void DutyAdjustmentJob(void);
//void ChangeVoltageTask(unsigned int voltage, struct strChannel *ptCh);

#endif
