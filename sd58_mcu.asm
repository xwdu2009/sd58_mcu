//Deviec:FT62F08X
//-----------------------Variable---------------------------------
		_BufDimPercentData		EQU		6BH
		_TempDimPercentData		EQU		7AH
		_FadeFlag		EQU		4FH
		_delaynumer		EQU		30H
		_LedNum		EQU		2FH
		_PowerLedFlag		EQU		6AH
		_cheakh		EQU		2EH
		_cheakl		EQU		2DH
		_RecLearnFlag		EQU		2CH
		_DimPercentData		EQU		6DH
		_DimPercentDataPre		EQU		69H
		_DimPercentDataPre1		EQU		68H
		_DimPercentDataNumer		EQU		2BH
		_AngleMin		EQU		6EH
		_DimPercentMin		EQU		67H
		_DimPercentMinPre		EQU		66H
		_DimMin		EQU		65H
		_PowerFirstFlag		EQU		4EH
		_FactoryFlag		EQU		43H
		_FactoryState		EQU		42H
		_FactoryNumer		EQU		B8H
		_FactoryFirstFlag		EQU		41H
		_KeyPowerOffFlag		EQU		3EH
		_MsgSendFlag		EQU		3DH
		_dataBuffer		EQU		CEH
		_FlashDataBuffer		EQU		C8H
		_led_cnt		EQU		20H
		_led_play_done		EQU		2AH
		_last_led_state		EQU		29H
		_led_state		EQU		28H
		_relay_temp		EQU		64H
		_wifi_state		EQU		27H
		_factory_state		EQU		26H
		_KeyState		EQU		34H
		_KeyNumer		EQU		B4H
		_KeyState1		EQU		33H
		_KeyNumer1		EQU		78H
		_KeyState4		EQU		31H
		_KeyNumer4		EQU		22H
		_Timer1Cnt		EQU		C4H
		_Timer20msFlag		EQU		4DH
		_Timer20msCnt		EQU		C2H
		_Timer1000msFlag		EQU		4CH
		_Timer1000msCnt		EQU		C0H
		_Timer10msFlag		EQU		4BH
		_PowerFlag		EQU		79H
		_PowerFlag_last		EQU		4AH
		_KeyDIMLearnval		EQU		49H
		_KeyPowerOnVal		EQU		48H
		_KeyPowerOffVal		EQU		47H
		_DimPercentDataOppose		EQU		46H
		_DelayTimer		EQU		BEH
		_DelayTimerPre		EQU		BCH
		_SiOpenTimer		EQU		BAH
		_PowerFirstNumer		EQU		45H
		_UpdatingFlag		EQU		44H
		_SiCtlState		EQU		3FH
		_UartRxStep		EQU		3CH
		_UartRxLen		EQU		3BH
		_UartRxBuf		EQU		AAH
		_ReceiveFinishFlag		EQU		40H
		_UartRecvData2		EQU		3AH
		_UartRecvData3		EQU		39H
		_UartTxBuf		EQU		A0H
		_ConnectState		EQU		38H
		_sample_cnt		EQU		37H
		_sample_data_ch0		EQU		120H
		_sample_data_load		EQU		C6H
		_travell_flag_ch0		EQU		36H
		_travell_flag_load		EQU		35H
		_Dimmer_Init_Flag		EQU		6CH
		_LoadDetCnt		EQU		B6H
//		___lwmod@counter		EQU		54H
//		___lwmod@divisor		EQU		50H
//		___lwmod@dividend		EQU		52H
//		___wmul@product		EQU		54H
//		___wmul@multiplier		EQU		50H
//		___wmul@multiplicand		EQU		52H
//		___lmul@product		EQU		5EH
//		___lmul@multiplier		EQU		56H
//		___lmul@multiplicand		EQU		5AH
//		___lldiv@quotient		EQU		DDH
//		___lldiv@counter		EQU		DCH
//		___lldiv@divisor		EQU		D4H
//		___lldiv@dividend		EQU		D8H
//		innotech_factroy_led_state_set@state		EQU		50H
//		innotech_factroy_led_state_set@state		EQU		50H
//		innotech_factroy_led_state_set@state		EQU		50H
//		KeyCheakPowerOn@key_value		EQU		51H
//		KeyCheakPowerOn@key1_state		EQU		32H
//		KeyCheakPowerOn@key1_count		EQU		24H
//		Isp_Read@i		EQU		56H
//		Isp_Read@ReadAddr		EQU		52H
//		Isp_Read@pBuffer		EQU		54H
//		EEPROMread@EEAddr		EQU		50H
//		EEPROMread@ReEEPROMread		EQU		51H
//		EEPROMread@EEAddr		EQU		50H
//		EEPROMread@EEAddr		EQU		50H
//		mcu_dp_value_update@sync_cmd		EQU		52H
//		mcu_dp_value_update@sync_cmd		EQU		52H
//		mcu_dp_value_update@sync_data		EQU		51H
//		mcu_dp_value_update@sync_cmd		EQU		52H
//		UartSendData@i		EQU		50H
//		GetAdcData@adcChannel		EQU		55H
//		GetAdcData@adcChannel		EQU		55H
//		GetAdcData@adcChannel		EQU		55H
//		DelayMs@b		EQU		57H
//		DelayMs@a		EQU		56H
//		DelayMs@Time		EQU		52H
//		DelayUs@Time		EQU		50H
//		DelayUs@a		EQU		51H
//		DelayUs@Time		EQU		50H
//		DelayUs@Time		EQU		50H
//		UartReceiveData@RcvData		EQU		70H
//		UartReceiveData@RcvData		EQU		70H
//		UartReceiveData@RcvData		EQU		70H
//		TIM2_ResetPeriod@Period		EQU		70H
//		TIM2_ResetPeriod@NewState		EQU		72H
//		Isp_Write@i		EQU		76H
//		Isp_Write@WriteAddr		EQU		72H
//		Isp_Write@pBuffer		EQU		74H
//		EEPROMwrite@EEAddr		EQU		71H
//		EEPROMwrite@EEAddr		EQU		71H
//		EEPROMwrite@Data		EQU		70H
//		EEPROMwrite@EEAddr		EQU		71H
//-----------------------Variable END---------------------------------

		MOVLP 	0H 			//0000 	0180
		LJUMP 	A2H 			//0001 	38A2
		ORG		0003H
		NOP 					//0003 	1000
		BSR 	7EH, 0H 			//0004 	247E
		MOVLP 	0H 			//0005 	0180

		//;main.c: 132: if(LVDIF)
		BTSS 	BH, 1H 			//0006 	2C8B
		LJUMP 	10H 			//0007 	3810

		//;main.c: 133: {
		//;main.c: 134: LVDIF = 1;
		BSR 	BH, 1H 			//0008 	248B
		LDWI 	CEH 			//0009 	00CE

		//;main.c: 136: Isp_Write(0x0,dataBuffer);
		CLRF 	72H 			//000A 	11F2
		CLRF 	73H 			//000B 	11F3
		STR 	74H 			//000C 	10F4
		MOVLP 	6H 			//000D 	0186
		LCALL 	6EAH 			//000E 	36EA
		MOVLP 	0H 			//000F 	0180

		//;main.c: 137: }
		//;main.c: 138: if(EPIF0 & 0x02)
		MOVLB 	0H 			//0010 	1020
		BTSS 	14H, 1H 		//0011 	2C94
		LJUMP 	3BH 			//0012 	383B

		//;main.c: 143: ZCDIntFlag = 1;
		BSR 	14H, 1H 			//0013 	2494

		//;main.c: 145: DelayTimer = DelayTimerPre;
		MOVLB 	1H 			//0014 	1021
		LDR 	3DH, 0H 			//0015 	183D
		STR 	3FH 			//0016 	10BF
		LDR 	3CH, 0H 			//0017 	183C
		STR 	3EH 			//0018 	10BE

		//;main.c: 146: SiOpenTimer = 28532 - DelayTimer;
		LDWI 	74H 			//0019 	0074
		STR 	3AH 			//001A 	10BA
		LDWI 	6FH 			//001B 	006F
		STR 	3BH 			//001C 	10BB
		LDR 	3EH, 0H 			//001D 	183E
		SUBWR 	3AH, 1H 		//001E 	12BA
		LDR 	3FH, 0H 			//001F 	183F
		SUBWFB 	3BH, 1H 		//0020 	0BBB

		//;main.c: 148: TIM2_ResetPeriod(DelayTimer,0);
		STR 	71H 			//0021 	10F1
		LDR 	3EH, 0H 			//0022 	183E
		STR 	70H 			//0023 	10F0
		CLRF 	72H 			//0024 	11F2
		MOVLP 	EH 			//0025 	018E
		LCALL 	6C1H 			//0026 	36C1
		MOVLP 	0H 			//0027 	0180

		//;main.c: 149: if((PowerFlag||FadeFlag)&&(PowerFirstFlag)&&(!UpdatingFlag))
		LDR 	79H, 0H 			//0028 	1879
		BTSS 	3H, 2H 			//0029 	2D03
		LJUMP 	2FH 			//002A 	382F
		MOVLB 	0H 			//002B 	1020
		LDR 	4FH, 0H 			//002C 	184F
		BTSC 	3H, 2H 			//002D 	2903
		LJUMP 	3BH 			//002E 	383B
		MOVLB 	0H 			//002F 	1020
		LDR 	4EH, 0H 			//0030 	184E
		BTSC 	3H, 2H 			//0031 	2903
		LJUMP 	3BH 			//0032 	383B
		LDR 	44H, 0H 			//0033 	1844
		BTSS 	3H, 2H 			//0034 	2D03
		LJUMP 	3BH 			//0035 	383B

		//;main.c: 150: {
		//;main.c: 152: TIM2CR1 |= 0x1;
		MOVLB 	6H 			//0036 	1026
		BSR 	CH, 0H 			//0037 	240C

		//;main.c: 157: SiCtlState = 1;
		MOVLB 	0H 			//0038 	1020
		CLRF 	3FH 			//0039 	11BF
		INCR 	3FH, 1H 		//003A 	1ABF

		//;main.c: 158: }
		//;main.c: 160: }
		//;main.c: 161: if(EPIF0 & 0x01)
		BTSS 	14H, 0H 		//003B 	2C14
		LJUMP 	42H 			//003C 	3842

		//;main.c: 162: {
		//;main.c: 163: EPIF0 |= 0x01;
		BSR 	14H, 0H 			//003D 	2414

		//;main.c: 164: sample_data_load++;
		MOVLB 	1H 			//003E 	1021
		INCR 	46H, 1H 		//003F 	1AC6
		BTSC 	3H, 2H 			//0040 	2903
		INCR 	47H, 1H 		//0041 	1AC7

		//;main.c: 166: }
		//;main.c: 168: if(T1UIE && T1UIF)
		MOVLB 	4H 			//0042 	1024
		BTSC 	15H, 0H 		//0043 	2815
		BTSS 	16H, 0H 		//0044 	2C16
		LJUMP 	77H 			//0045 	3877

		//;main.c: 169: {
		//;main.c: 170: T1UIF = 1;
		BSR 	16H, 0H 			//0046 	2416

		//;main.c: 172: Timer1Cnt++;
		MOVLB 	1H 			//0047 	1021
		INCR 	44H, 1H 		//0048 	1AC4
		BTSC 	3H, 2H 			//0049 	2903
		INCR 	45H, 1H 		//004A 	1AC5

		//;main.c: 175: if(Timer1Cnt >= 10)
		LDWI 	0H 			//004B 	0000
		SUBWR 	45H, 0H 		//004C 	1245
		LDWI 	AH 			//004D 	000A
		BTSC 	3H, 2H 			//004E 	2903
		SUBWR 	44H, 0H 		//004F 	1244
		BTSS 	3H, 0H 			//0050 	2C03
		LJUMP 	57H 			//0051 	3857

		//;main.c: 176: {
		//;main.c: 177: Timer1Cnt = 0;
		CLRF 	44H 			//0052 	11C4
		CLRF 	45H 			//0053 	11C5

		//;main.c: 178: Timer10msFlag = 1;
		MOVLB 	0H 			//0054 	1020
		CLRF 	4BH 			//0055 	11CB
		INCR 	4BH, 1H 		//0056 	1ACB

		//;main.c: 179: }
		//;main.c: 180: Timer20msCnt++;
		MOVLB 	1H 			//0057 	1021
		INCR 	42H, 1H 		//0058 	1AC2
		BTSC 	3H, 2H 			//0059 	2903
		INCR 	43H, 1H 		//005A 	1AC3

		//;main.c: 181: if(Timer20msCnt >= 20)
		LDWI 	0H 			//005B 	0000
		SUBWR 	43H, 0H 		//005C 	1243
		LDWI 	14H 			//005D 	0014
		BTSC 	3H, 2H 			//005E 	2903
		SUBWR 	42H, 0H 		//005F 	1242
		BTSS 	3H, 0H 			//0060 	2C03
		LJUMP 	67H 			//0061 	3867

		//;main.c: 182: {
		//;main.c: 183: Timer20msCnt = 0;
		CLRF 	42H 			//0062 	11C2
		CLRF 	43H 			//0063 	11C3

		//;main.c: 184: Timer20msFlag = 1;
		MOVLB 	0H 			//0064 	1020
		CLRF 	4DH 			//0065 	11CD
		INCR 	4DH, 1H 		//0066 	1ACD

		//;main.c: 185: }
		//;main.c: 187: Timer1000msCnt++;
		MOVLB 	1H 			//0067 	1021
		INCR 	40H, 1H 		//0068 	1AC0
		BTSC 	3H, 2H 			//0069 	2903
		INCR 	41H, 1H 		//006A 	1AC1

		//;main.c: 188: if(Timer1000msCnt >= 1000)
		LDWI 	3H 			//006B 	0003
		SUBWR 	41H, 0H 		//006C 	1241
		LDWI 	E8H 			//006D 	00E8
		BTSC 	3H, 2H 			//006E 	2903
		SUBWR 	40H, 0H 		//006F 	1240
		BTSS 	3H, 0H 			//0070 	2C03
		LJUMP 	77H 			//0071 	3877

		//;main.c: 189: {
		//;main.c: 190: Timer1000msCnt = 0;
		CLRF 	40H 			//0072 	11C0
		CLRF 	41H 			//0073 	11C1

		//;main.c: 191: Timer1000msFlag = 1;
		MOVLB 	0H 			//0074 	1020
		CLRF 	4CH 			//0075 	11CC
		INCR 	4CH, 1H 		//0076 	1ACC

		//;main.c: 192: }
		//;main.c: 194: }
		//;main.c: 195: if(T2UIE && T2UIF)
		MOVLB 	6H 			//0077 	1026
		BTSC 	DH, 0H 			//0078 	280D
		BTSS 	EH, 0H 			//0079 	2C0E
		LJUMP 	90H 			//007A 	3890

		//;main.c: 196: {
		//;main.c: 197: T2UIF = 1;
		BSR 	EH, 0H 			//007B 	240E

		//;main.c: 199: if(SiCtlState == 1)
		MOVLB 	0H 			//007C 	1020
		DECRSZ 	3FH, 0H 		//007D 	1B3F
		LJUMP 	8DH 			//007E 	388D

		//;main.c: 200: {
		//;main.c: 202: PB0 = 1;;
		BSR 	DH, 0H 			//007F 	240D

		//;main.c: 204: TIM2_ResetPeriod(SiOpenTimer,1);
		MOVLB 	1H 			//0080 	1021
		LDR 	3BH, 0H 			//0081 	183B
		STR 	71H 			//0082 	10F1
		LDR 	3AH, 0H 			//0083 	183A
		STR 	70H 			//0084 	10F0
		CLRF 	72H 			//0085 	11F2
		INCR 	72H, 1H 		//0086 	1AF2
		MOVLP 	EH 			//0087 	018E
		LCALL 	6C1H 			//0088 	36C1
		MOVLP 	0H 			//0089 	0180

		//;main.c: 205: SiCtlState = 0;
		MOVLB 	0H 			//008A 	1020
		CLRF 	3FH 			//008B 	11BF

		//;main.c: 206: }
		LJUMP 	90H 			//008C 	3890

		//;main.c: 207: else
		//;main.c: 208: {
		//;main.c: 210: PB0 = 0;;
		BCR 	DH, 0H 			//008D 	200D

		//;main.c: 212: TIM2CR1 &= ~(0x1);
		MOVLB 	6H 			//008E 	1026
		BCR 	CH, 0H 			//008F 	200C

		//;main.c: 216: }
		//;main.c: 217: }
		//;main.c: 218: if(T4UIE && T4UIF)
		MOVLB 	2H 			//0090 	1022
		BTSC 	12H, 0H 		//0091 	2812
		BTSS 	13H, 0H 		//0092 	2C13
		LJUMP 	98H 			//0093 	3898

		//;main.c: 219: {
		//;main.c: 220: T4UIF = 1;
		BSR 	13H, 0H 			//0094 	2413

		//;main.c: 221: Load_Scan();
		MOVLP 	EH 			//0095 	018E
		LCALL 	6F9H 			//0096 	36F9
		MOVLP 	0H 			//0097 	0180

		//;main.c: 222: }
		//;main.c: 224: if(URRXNE && RXNEF)
		MOVLB 	9H 			//0098 	1029
		BTSC 	EH, 0H 			//0099 	280E
		BTSS 	12H, 0H 		//009A 	2C12
		LJUMP 	A0H 			//009B 	38A0

		//;main.c: 225: {
		//;main.c: 226: UartReceiveData(URDATAL);
		LDR 	CH, 0H 			//009C 	180C
		MOVLP 	FH 			//009D 	018F
		LCALL 	756H 			//009E 	3756

		//;main.c: 227: __nop();
		NOP 					//009F 	1000
		BCR 	7EH, 0H 			//00A0 	207E
		RETI 					//00A1 	1009
		MOVLP 	0H 			//00A2 	0180
		LJUMP 	A4H 			//00A3 	38A4
		LDWI 	1H 			//00A4 	0001
		STR 	7AH 			//00A5 	10FA
		LDWI 	AAH 			//00A6 	00AA
		STR 	64H 			//00A7 	10E4
		LDWI 	1H 			//00A8 	0001
		STR 	65H 			//00A9 	10E5
		STR 	66H 			//00AA 	10E6
		STR 	67H 			//00AB 	10E7
		LDWI 	64H 			//00AC 	0064
		STR 	68H 			//00AD 	10E8
		STR 	69H 			//00AE 	10E9
		LDWI 	1H 			//00AF 	0001
		STR 	6AH 			//00B0 	10EA
		STR 	6BH 			//00B1 	10EB
		STR 	6CH 			//00B2 	10EC
		LDWI 	64H 			//00B3 	0064
		STR 	6DH 			//00B4 	10ED
		LDWI 	8EH 			//00B5 	008E
		STR 	6EH 			//00B6 	10EE
		LDWI 	20H 			//00B7 	0020
		CLRF 	78H 			//00B8 	11F8
		CLRF 	79H 			//00B9 	11F9
		STR 	4H 			//00BA 	1084
		LDWI 	0H 			//00BB 	0000
		STR 	5H 			//00BC 	1085
		LDWI 	30H 			//00BD 	0030
		MOVLP 	EH 			//00BE 	018E
		LCALL 	6B4H 			//00BF 	36B4
		MOVLP 	0H 			//00C0 	0180
		LDWI 	A0H 			//00C1 	00A0
		STR 	4H 			//00C2 	1084
		LDWI 	0H 			//00C3 	0000
		STR 	5H 			//00C4 	1085
		LDWI 	34H 			//00C5 	0034
		MOVLP 	EH 			//00C6 	018E
		LCALL 	6B4H 			//00C7 	36B4
		MOVLP 	0H 			//00C8 	0180
		LDWI 	20H 			//00C9 	0020
		STR 	4H 			//00CA 	1084
		LDWI 	1H 			//00CB 	0001
		STR 	5H 			//00CC 	1085
		LDWI 	3CH 			//00CD 	003C
		MOVLP 	EH 			//00CE 	018E
		LCALL 	6B4H 			//00CF 	36B4
		MOVLP 	0H 			//00D0 	0180
		BCR 	7EH, 0H 			//00D1 	207E
		MOVLB 	0H 			//00D2 	1020
		LJUMP 	D4H 			//00D3 	38D4
		LDWI 	C8H 			//00D4 	00C8

		//;main.c: 241: Isp_Read(0x0,FlashDataBuffer);
		CLRF 	52H 			//00D5 	11D2
		CLRF 	53H 			//00D6 	11D3
		STR 	54H 			//00D7 	10D4
		LCALL 	3B0H 			//00D8 	33B0

		//;main.c: 242: SysInitial();
		MOVLP 	FH 			//00D9 	018F
		LCALL 	78AH 			//00DA 	378A
		MOVLP 	0H 			//00DB 	0180

		//;main.c: 243: IoIntInitial();
		LCALL 	3A0H 			//00DC 	33A0

		//;main.c: 244: Time1Initial();
		MOVLP 	7H 			//00DD 	0187
		LCALL 	7E7H 			//00DE 	37E7
		MOVLP 	0H 			//00DF 	0180

		//;main.c: 245: Time2Initial();
		LCALL 	475H 			//00E0 	3475
		MOVLP 	0H 			//00E1 	0180

		//;main.c: 246: Time4Initial();
		LCALL 	490H 			//00E2 	3490

		//;main.c: 247: UartInitial();
		MOVLP 	EH 			//00E3 	018E
		LCALL 	6D1H 			//00E4 	36D1
		MOVLP 	0H 			//00E5 	0180

		//;main.c: 248: WdtInitial();
		MOVLP 	EH 			//00E6 	018E
		LCALL 	6BAH 			//00E7 	36BA
		MOVLP 	0H 			//00E8 	0180

		//;main.c: 249: AdcInitial();
		LCALL 	335H 			//00E9 	3335

		//;main.c: 254: while(1)
		CLRWDT 			//00EA 	1064

		//;main.c: 257: DelayTimerPre = ((unsigned long)((unsigned long)((AngleMin-42)*DimPercentD
		//+                          ataOppose+(42*100))*31578)/18000);
		MOVLB 	1H 			//00EB 	1021
		LDWI 	46H 			//00EC 	0046
		CLRF 	57H 			//00ED 	11D7
		CLRF 	56H 			//00EE 	11D6
		STR 	55H 			//00EF 	10D5
		LDWI 	50H 			//00F0 	0050
		STR 	54H 			//00F1 	10D4
		MOVLB 	0H 			//00F2 	1020
		LDR 	6EH, 0H 			//00F3 	186E
		STR 	50H 			//00F4 	10D0
		LDWI 	D6H 			//00F5 	00D6
		CLRF 	51H 			//00F6 	11D1
		ADDWR 	50H, 1H 		//00F7 	17D0
		BTSS 	3H, 0H 			//00F8 	2C03
		DECR 	51H, 1H 		//00F9 	13D1
		LDR 	46H, 0H 			//00FA 	1846
		STR 	52H 			//00FB 	10D2
		CLRF 	53H 			//00FC 	11D3
		MOVLP 	EH 			//00FD 	018E
		LCALL 	6E4H 			//00FE 	36E4
		MOVLP 	0H 			//00FF 	0180
		LDR 	50H, 0H 			//0100 	1850
		ADDWI 	68H 			//0101 	0E68
		STR 	62H 			//0102 	10E2
		LDWI 	10H 			//0103 	0010
		ADDWFC 	51H, 0H 		//0104 	0D51
		STR 	63H 			//0105 	10E3
		LDR 	62H, 0H 			//0106 	1862
		STR 	56H 			//0107 	10D6
		LDR 	63H, 0H 			//0108 	1863
		STR 	57H 			//0109 	10D7
		RLR 	9H, 1H 			//010A 	1D89
		SUBWFB 	9H, 1H 		//010B 	0B89
		COMR 	9H, 1H 			//010C 	1989
		STR 	58H 			//010D 	10D8
		STR 	59H 			//010E 	10D9
		LDWI 	7BH 			//010F 	007B
		CLRF 	5DH 			//0110 	11DD
		CLRF 	5CH 			//0111 	11DC
		STR 	5BH 			//0112 	10DB
		LDWI 	5AH 			//0113 	005A
		STR 	5AH 			//0114 	10DA
		MOVLP 	FH 			//0115 	018F
		LCALL 	731H 			//0116 	3731
		MOVLP 	0H 			//0117 	0180
		LDR 	59H, 0H 			//0118 	1859
		MOVLB 	1H 			//0119 	1021
		STR 	5BH 			//011A 	10DB
		MOVLB 	0H 			//011B 	1020
		LDR 	58H, 0H 			//011C 	1858
		MOVLB 	1H 			//011D 	1021
		STR 	5AH 			//011E 	10DA
		MOVLB 	0H 			//011F 	1020
		LDR 	57H, 0H 			//0120 	1857
		MOVLB 	1H 			//0121 	1021
		STR 	59H 			//0122 	10D9
		MOVLB 	0H 			//0123 	1020
		LDR 	56H, 0H 			//0124 	1856
		MOVLB 	1H 			//0125 	1021
		STR 	58H 			//0126 	10D8
		MOVLP 	FH 			//0127 	018F
		LCALL 	7C1H 			//0128 	37C1
		MOVLP 	0H 			//0129 	0180
		LDR 	55H, 0H 			//012A 	1855
		STR 	3DH 			//012B 	10BD
		LDR 	54H, 0H 			//012C 	1854
		STR 	3CH 			//012D 	10BC

		//;main.c: 259: if(Timer10msFlag)
		MOVLB 	0H 			//012E 	1020
		LDR 	4BH, 0H 			//012F 	184B
		BTSC 	3H, 2H 			//0130 	2903
		LJUMP 	159H 			//0131 	3959
		LDWI 	32H 			//0132 	0032

		//;main.c: 260: {
		//;main.c: 261: Timer10msFlag = 0;
		CLRF 	4BH 			//0133 	11CB

		//;main.c: 262: if(++PowerFirstNumer >= 50)
		INCR 	45H, 1H 		//0134 	1AC5
		SUBWR 	45H, 0H 		//0135 	1245
		BTSS 	3H, 0H 			//0136 	2C03
		LJUMP 	13BH 			//0137 	393B

		//;main.c: 263: {
		//;main.c: 264: PowerFirstNumer = 0;
		CLRF 	45H 			//0138 	11C5

		//;main.c: 265: PowerFirstFlag = 1;
		CLRF 	4EH 			//0139 	11CE
		INCR 	4EH, 1H 		//013A 	1ACE

		//;main.c: 266: }
		//;main.c: 267: Factory_Test_Mode();
		LCALL 	358H 			//013B 	3358
		MOVLP 	0H 			//013C 	0180

		//;main.c: 268: if(PowerFirstFlag == 1)
		DECRSZ 	4EH, 0H 		//013D 	1B4E
		LJUMP 	142H 			//013E 	3942

		//;main.c: 269: {
		//;main.c: 270: Led7Run();
		MOVLP 	6H 			//013F 	0186
		LCALL 	643H 			//0140 	3643
		MOVLP 	0H 			//0141 	0180

		//;main.c: 271: }
		//;main.c: 272: if(FactoryFlag == 0)
		LDR 	43H, 0H 			//0142 	1843
		BTSS 	3H, 2H 			//0143 	2D03
		LJUMP 	159H 			//0144 	3959

		//;main.c: 273: {
		//;main.c: 274: KeyDIMLearnval = KeyCheakDIM_PMLearn();
		LCALL 	3F1H 			//0145 	33F1
		MOVLB 	0H 			//0146 	1020
		STR 	49H 			//0147 	10C9

		//;main.c: 275: KeyPowerOnVal = KeyCheakPowerOn();
		MOVLP 	5H 			//0148 	0185
		LCALL 	5AFH 			//0149 	35AF
		MOVLP 	0H 			//014A 	0180
		STR 	48H 			//014B 	10C8

		//;main.c: 276: KeyPowerOffVal = KeyCheakPowerOff();
		MOVLP 	5H 			//014C 	0185
		LCALL 	560H 			//014D 	3560
		MOVLP 	0H 			//014E 	0180
		STR 	47H 			//014F 	10C7

		//;main.c: 278: Connect_With_Switch();
		LCALL 	23DH 			//0150 	323D
		MOVLP 	0H 			//0151 	0180

		//;main.c: 279: DimData_Deal();
		LCALL 	16DH 			//0152 	316D

		//;main.c: 280: SynDataReset_Deal();
		MOVLP 	7H 			//0153 	0187
		LCALL 	7A7H 			//0154 	37A7
		MOVLP 	0H 			//0155 	0180

		//;main.c: 281: UartB_Process();
		MOVLP 	7H 			//0156 	0187
		LCALL 	756H 			//0157 	3756
		MOVLP 	0H 			//0158 	0180

		//;main.c: 283: }
		//;main.c: 284: }
		//;main.c: 285: if(Timer20msFlag)
		LDR 	4DH, 0H 			//0159 	184D
		BTSC 	3H, 2H 			//015A 	2903
		LJUMP 	168H 			//015B 	3968

		//;main.c: 286: {
		//;main.c: 287: Timer20msFlag = 0;
		CLRF 	4DH 			//015C 	11CD

		//;main.c: 288: innotech_led_process();
		MOVLP 	4H 			//015D 	0184
		LCALL 	4A1H 			//015E 	34A1
		MOVLP 	0H 			//015F 	0180

		//;main.c: 289: if(0x1 == PowerFlag)
		DECRSZ 	79H, 0H 		//0160 	1B79
		LJUMP 	164H 			//0161 	3964

		//;main.c: 290: {
		//;main.c: 291: PB6 = 1;;
		BSR 	DH, 6H 			//0162 	270D

		//;main.c: 292: }
		LJUMP 	168H 			//0163 	3968

		//;main.c: 293: else if(0x0 == PowerFlag)
		LDR 	79H, 0H 			//0164 	1879
		BTSS 	3H, 2H 			//0165 	2D03
		LJUMP 	168H 			//0166 	3968

		//;main.c: 294: {
		//;main.c: 295: PB6 = 0;;
		BCR 	DH, 6H 			//0167 	230D

		//;main.c: 296: }
		//;main.c: 297: }
		//;main.c: 300: if(Timer1000msFlag)
		LDR 	4CH, 0H 			//0168 	184C
		BTSC 	3H, 2H 			//0169 	2903
		LJUMP 	EAH 			//016A 	38EA

		//;main.c: 301: {
		//;main.c: 302: Timer1000msFlag = 0;
		CLRF 	4CH 			//016B 	11CC
		LJUMP 	EAH 			//016C 	38EA

		//;Dim.c: 138: if((KeyPowerOnVal == 10) || (KeyPowerOnVal == 14) || (KeyPowerOffVal == 12)
		//+                          )
		LDWI 	AH 			//016D 	000A
		XORWR 	48H, 0H 		//016E 	1648
		BTSC 	3H, 2H 			//016F 	2903
		LJUMP 	179H 			//0170 	3979
		LDWI 	EH 			//0171 	000E
		XORWR 	48H, 0H 		//0172 	1648
		BTSC 	3H, 2H 			//0173 	2903
		LJUMP 	179H 			//0174 	3979
		LDWI 	CH 			//0175 	000C
		XORWR 	47H, 0H 		//0176 	1647
		BTSS 	3H, 2H 			//0177 	2D03
		LJUMP 	1B1H 			//0178 	39B1

		//;Dim.c: 139: {
		//;Dim.c: 143: if(KeyPowerOnVal == 10)
		LDWI 	AH 			//0179 	000A
		XORWR 	48H, 0H 		//017A 	1648
		BTSS 	3H, 2H 			//017B 	2D03
		LJUMP 	18AH 			//017C 	398A

		//;Dim.c: 144: {
		//;Dim.c: 145: if((PowerFlag == 0) && (KeyPowerOffFlag == 0))
		LDR 	79H, 0H 			//017D 	1879
		BTSS 	3H, 2H 			//017E 	2D03
		LJUMP 	1B1H 			//017F 	39B1
		LDR 	3EH, 0H 			//0180 	183E
		BTSS 	3H, 2H 			//0181 	2D03
		LJUMP 	1B1H 			//0182 	39B1

		//;Dim.c: 146: {
		//;Dim.c: 147: PowerFlag = 1;
		//;Dim.c: 148: mcu_dp_value_update(0x01,PowerFlag);
		LCALL 	487H 			//0183 	3487
		MOVLP 	0H 			//0184 	0180
		LCALL 	30EH 			//0185 	330E
		MOVLP 	0H 			//0186 	0180

		//;Dim.c: 149: PA0 ^= 1;;
		LDWI 	1H 			//0187 	0001
		XORWR 	CH, 1H 		//0188 	168C
		LJUMP 	1B1H 			//0189 	39B1

		//;Dim.c: 152: else if(KeyPowerOffVal == 12)
		LDWI 	CH 			//018A 	000C
		XORWR 	47H, 0H 		//018B 	1647
		BTSS 	3H, 2H 			//018C 	2D03
		LJUMP 	197H 			//018D 	3997

		//;Dim.c: 153: {
		//;Dim.c: 154: if(PowerFlag == 1)
		DECRSZ 	79H, 0H 		//018E 	1B79
		LJUMP 	1B1H 			//018F 	39B1

		//;Dim.c: 155: {
		//;Dim.c: 156: PowerFlag = 0;
		//;Dim.c: 158: mcu_dp_value_update(0x01,PowerFlag);
		LCALL 	48CH 			//0190 	348C
		MOVLP 	0H 			//0191 	0180
		LCALL 	30EH 			//0192 	330E
		MOVLP 	0H 			//0193 	0180

		//;Dim.c: 159: KeyPowerOffFlag = 1;
		CLRF 	3EH 			//0194 	11BE
		INCR 	3EH, 1H 		//0195 	1ABE
		LJUMP 	1B1H 			//0196 	39B1

		//;Dim.c: 162: else if(KeyPowerOnVal == 14)
		LDWI 	EH 			//0197 	000E
		XORWR 	48H, 0H 		//0198 	1648
		BTSS 	3H, 2H 			//0199 	2D03
		LJUMP 	1B1H 			//019A 	39B1

		//;Dim.c: 163: {
		//;Dim.c: 164: if((PowerFlag == 0) && (KeyPowerOffFlag == 0))
		LDR 	79H, 0H 			//019B 	1879
		BTSS 	3H, 2H 			//019C 	2D03
		LJUMP 	1ADH 			//019D 	39AD
		LDR 	3EH, 0H 			//019E 	183E
		BTSS 	3H, 2H 			//019F 	2D03
		LJUMP 	1ADH 			//01A0 	39AD

		//;Dim.c: 165: {
		//;Dim.c: 166: PowerFlag = 1;
		//;Dim.c: 167: mcu_dp_value_update(0x01,PowerFlag);
		LCALL 	487H 			//01A1 	3487
		MOVLP 	0H 			//01A2 	0180
		LCALL 	30EH 			//01A3 	330E
		MOVLP 	0H 			//01A4 	0180

		//;Dim.c: 168: PA0 ^= 1;;
		LDWI 	1H 			//01A5 	0001
		XORWR 	CH, 1H 		//01A6 	168C

		//;Dim.c: 169: DelayMs(100);
		LDWI 	64H 			//01A7 	0064
		STR 	52H 			//01A8 	10D2
		CLRF 	53H 			//01A9 	11D3
		LCALL 	31EH 			//01AA 	331E
		MOVLP 	0H 			//01AB 	0180

		//;Dim.c: 171: }
		LJUMP 	1AFH 			//01AC 	39AF

		//;Dim.c: 172: else if(PowerFlag == 1)
		DECRSZ 	79H, 0H 		//01AD 	1B79
		LJUMP 	1B1H 			//01AE 	39B1

		//;Dim.c: 170: DimPercentData = 100;
		LDWI 	64H 			//01AF 	0064
		STR 	6DH 			//01B0 	10ED

		//;Dim.c: 175: }
		//;Dim.c: 176: }
		//;Dim.c: 187: }
		//;Dim.c: 188: DimPercentDataPre = DimPercentData;
		LDR 	6DH, 0H 			//01B1 	186D
		STR 	69H 			//01B2 	10E9

		//;Dim.c: 263: if((KeyDIMLearnval)&&(KeyDIMLearnval != 5)&&(!RecLearnFlag))
		LDR 	49H, 0H 			//01B3 	1849
		BTSC 	3H, 2H 			//01B4 	2903
		LJUMP 	23BH 			//01B5 	3A3B
		LDWI 	5H 			//01B6 	0005
		XORWR 	49H, 0H 		//01B7 	1649
		BTSC 	3H, 2H 			//01B8 	2903
		LJUMP 	23BH 			//01B9 	3A3B
		LDR 	2CH, 0H 			//01BA 	182C
		BTSS 	3H, 2H 			//01BB 	2D03
		LJUMP 	23BH 			//01BC 	3A3B

		//;Dim.c: 264: {
		//;Dim.c: 266: if(PowerFlag == 0)
		LDR 	79H, 0H 			//01BD 	1879
		BTSS 	3H, 2H 			//01BE 	2D03
		LJUMP 	1C6H 			//01BF 	39C6

		//;Dim.c: 267: {
		//;Dim.c: 268: PowerFlag = 1;
		//;Dim.c: 269: mcu_dp_value_update(0x01,PowerFlag);
		LCALL 	487H 			//01C0 	3487
		MOVLP 	0H 			//01C1 	0180
		LCALL 	30EH 			//01C2 	330E
		MOVLP 	0H 			//01C3 	0180

		//;Dim.c: 270: PA0 ^= 1;;
		LDWI 	1H 			//01C4 	0001
		XORWR 	CH, 1H 		//01C5 	168C

		//;Dim.c: 273: }
		//;Dim.c: 274: if(KeyDIMLearnval == 1)
		DECRSZ 	49H, 0H 		//01C6 	1B49
		LJUMP 	1F4H 			//01C7 	39F4

		//;Dim.c: 275: {
		//;Dim.c: 277: if(DimPercentData < 1)DimPercentData = 1;
		LDR 	6DH, 0H 			//01C8 	186D
		BTSS 	3H, 2H 			//01C9 	2D03
		LJUMP 	1CDH 			//01CA 	39CD
		CLRF 	6DH 			//01CB 	11ED
		LJUMP 	202H 			//01CC 	3A02

		//;Dim.c: 278: else if(DimPercentData < 5) DimPercentData = 5;
		LDWI 	5H 			//01CD 	0005
		SUBWR 	6DH, 0H 		//01CE 	126D
		BTSC 	3H, 0H 			//01CF 	2803
		LJUMP 	1D3H 			//01D0 	39D3
		LDWI 	5H 			//01D1 	0005
		LJUMP 	1F2H 			//01D2 	39F2

		//;Dim.c: 279: else if(DimPercentData < 20) DimPercentData = 20;
		LDWI 	14H 			//01D3 	0014
		SUBWR 	6DH, 0H 		//01D4 	126D
		BTSC 	3H, 0H 			//01D5 	2803
		LJUMP 	1D9H 			//01D6 	39D9
		LDWI 	14H 			//01D7 	0014
		LJUMP 	1F2H 			//01D8 	39F2

		//;Dim.c: 280: else if(DimPercentData < 35) DimPercentData = 35;
		LDWI 	23H 			//01D9 	0023
		SUBWR 	6DH, 0H 		//01DA 	126D
		BTSC 	3H, 0H 			//01DB 	2803
		LJUMP 	1DFH 			//01DC 	39DF
		LDWI 	23H 			//01DD 	0023
		LJUMP 	1F2H 			//01DE 	39F2

		//;Dim.c: 281: else if(DimPercentData < 50) DimPercentData = 50;
		LDWI 	32H 			//01DF 	0032
		SUBWR 	6DH, 0H 		//01E0 	126D
		BTSC 	3H, 0H 			//01E1 	2803
		LJUMP 	1E5H 			//01E2 	39E5
		LDWI 	32H 			//01E3 	0032
		LJUMP 	1F2H 			//01E4 	39F2

		//;Dim.c: 282: else if(DimPercentData < 65) DimPercentData = 65;
		LDWI 	41H 			//01E5 	0041
		SUBWR 	6DH, 0H 		//01E6 	126D
		BTSC 	3H, 0H 			//01E7 	2803
		LJUMP 	1EBH 			//01E8 	39EB
		LDWI 	41H 			//01E9 	0041
		LJUMP 	1F2H 			//01EA 	39F2

		//;Dim.c: 283: else if(DimPercentData < 80) DimPercentData = 80;
		LDWI 	50H 			//01EB 	0050
		SUBWR 	6DH, 0H 		//01EC 	126D
		BTSC 	3H, 0H 			//01ED 	2803
		LJUMP 	1F1H 			//01EE 	39F1
		LDWI 	50H 			//01EF 	0050
		LJUMP 	1F2H 			//01F0 	39F2
		LDWI 	64H 			//01F1 	0064
		STR 	6DH 			//01F2 	10ED
		LJUMP 	22EH 			//01F3 	3A2E

		//;Dim.c: 293: else if(KeyDIMLearnval == 2)
		LDWI 	2H 			//01F4 	0002
		XORWR 	49H, 0H 		//01F5 	1649

		//;Dim.c: 294: {
		//;Dim.c: 296: if(++delaynumer >= 3)
		LDWI 	3H 			//01F6 	0003
		BTSS 	3H, 2H 			//01F7 	2D03
		LJUMP 	204H 			//01F8 	3A04
		INCR 	30H, 1H 		//01F9 	1AB0
		SUBWR 	30H, 0H 		//01FA 	1230
		BTSS 	3H, 0H 			//01FB 	2C03
		LJUMP 	22EH 			//01FC 	3A2E
		LDWI 	64H 			//01FD 	0064

		//;Dim.c: 297: {
		//;Dim.c: 298: delaynumer = 0;
		CLRF 	30H 			//01FE 	11B0

		//;Dim.c: 299: if(DimPercentData < 100)
		SUBWR 	6DH, 0H 		//01FF 	126D
		BTSC 	3H, 0H 			//0200 	2803
		LJUMP 	22EH 			//0201 	3A2E

		//;Dim.c: 300: {
		//;Dim.c: 301: DimPercentData++;
		INCR 	6DH, 1H 		//0202 	1AED
		LJUMP 	22EH 			//0203 	3A2E

		//;Dim.c: 305: else if(KeyDIMLearnval == 3)
		XORWR 	49H, 0H 		//0204 	1649
		BTSS 	3H, 2H 			//0205 	2D03
		LJUMP 	220H 			//0206 	3A20

		//;Dim.c: 306: {
		//;Dim.c: 308: if(DimPercentData > 80) DimPercentData = 80;
		LDWI 	51H 			//0207 	0051
		SUBWR 	6DH, 0H 		//0208 	126D
		BTSC 	3H, 0H 			//0209 	2803
		LJUMP 	1EFH 			//020A 	39EF

		//;Dim.c: 309: else if(DimPercentData > 65) DimPercentData = 65;
		LDWI 	42H 			//020B 	0042
		SUBWR 	6DH, 0H 		//020C 	126D
		BTSC 	3H, 0H 			//020D 	2803
		LJUMP 	1E9H 			//020E 	39E9

		//;Dim.c: 310: else if(DimPercentData > 50) DimPercentData = 50;
		LDWI 	33H 			//020F 	0033
		SUBWR 	6DH, 0H 		//0210 	126D
		BTSC 	3H, 0H 			//0211 	2803
		LJUMP 	1E3H 			//0212 	39E3

		//;Dim.c: 311: else if(DimPercentData > 35) DimPercentData = 35;
		LDWI 	24H 			//0213 	0024
		SUBWR 	6DH, 0H 		//0214 	126D
		BTSC 	3H, 0H 			//0215 	2803
		LJUMP 	1DDH 			//0216 	39DD

		//;Dim.c: 312: else if(DimPercentData > 20) DimPercentData = 20;
		LDWI 	15H 			//0217 	0015
		SUBWR 	6DH, 0H 		//0218 	126D
		BTSC 	3H, 0H 			//0219 	2803
		LJUMP 	1D7H 			//021A 	39D7

		//;Dim.c: 313: else if(DimPercentData > 5) DimPercentData = 5;
		LDWI 	6H 			//021B 	0006
		SUBWR 	6DH, 0H 		//021C 	126D
		BTSC 	3H, 0H 			//021D 	2803
		LJUMP 	1D1H 			//021E 	39D1
		LJUMP 	1CBH 			//021F 	39CB

		//;Dim.c: 323: else if(KeyDIMLearnval == 4)
		LDWI 	4H 			//0220 	0004
		XORWR 	49H, 0H 		//0221 	1649
		BTSS 	3H, 2H 			//0222 	2D03
		LJUMP 	22EH 			//0223 	3A2E

		//;Dim.c: 324: {
		//;Dim.c: 326: if(++delaynumer >= 3)
		LDWI 	3H 			//0224 	0003
		INCR 	30H, 1H 		//0225 	1AB0
		SUBWR 	30H, 0H 		//0226 	1230
		BTSS 	3H, 0H 			//0227 	2C03
		LJUMP 	22EH 			//0228 	3A2E
		LDWI 	2H 			//0229 	0002

		//;Dim.c: 327: {
		//;Dim.c: 328: delaynumer = 0;
		CLRF 	30H 			//022A 	11B0

		//;Dim.c: 329: if(DimPercentData > 1)
		SUBWR 	6DH, 0H 		//022B 	126D
		BTSC 	3H, 0H 			//022C 	2803

		//;Dim.c: 330: {
		//;Dim.c: 331: DimPercentData--;
		DECR 	6DH, 1H 		//022D 	13ED

		//;Dim.c: 332: }
		//;Dim.c: 333: }
		//;Dim.c: 334: }
		//;Dim.c: 335: if(DimPercentData <= DimMin)
		LDR 	6DH, 0H 			//022E 	186D
		SUBWR 	65H, 0H 		//022F 	1265
		BTSS 	3H, 0H 			//0230 	2C03
		LJUMP 	234H 			//0231 	3A34

		//;Dim.c: 336: DimPercentData = DimMin;
		LDR 	65H, 0H 			//0232 	1865
		STR 	6DH 			//0233 	10ED

		//;Dim.c: 340: if(DimPercentDataPre != DimPercentData)
		LDR 	69H, 0H 			//0234 	1869
		XORWR 	6DH, 0H 		//0235 	166D
		BTSC 	3H, 2H 			//0236 	2903
		RET 					//0237 	1008

		//;Dim.c: 343: Dim1SendPercentDataFlag = 1;
		LDR 	6DH, 0H 			//0238 	186D
		STR 	69H 			//0239 	10E9
		RET 					//023A 	1008

		//;Dim.c: 346: else
		//;Dim.c: 347: delaynumer = 0;
		CLRF 	30H 			//023B 	11B0
		RET 					//023C 	1008

		//;public.c: 1391: switch(sample_cnt)
		LJUMP 	303H 			//023D 	3B03

		//;public.c: 1394: case 1:
		//;public.c: 1395: case 2:
		//;public.c: 1396: case 3:
		//;public.c: 1397: case 4:
		//;public.c: 1398: case 5:
		//;public.c: 1399: case 6:
		//;public.c: 1400: case 7:
		//;public.c: 1401: case 8:
		//;public.c: 1402: case 9:
		//;public.c: 1404: sample_data_ch0[sample_cnt] = GetAdcData(5);
		LDWI 	5H 			//023E 	0005
		MOVLP 	FH 			//023F 	018F
		LCALL 	714H 			//0240 	3714
		LSLF 	37H, 0H 		//0241 	0537
		ADDWI 	20H 			//0242 	0E20
		STR 	6H 			//0243 	1086
		LDWI 	1H 			//0244 	0001
		STR 	7H 			//0245 	1087
		LDR 	52H, 0H 			//0246 	1852
		MOVWI 	0H[1] 			//0247 	0FC0
		LDR 	53H, 0H 			//0248 	1853
		MOVWI 	1H[1] 			//0249 	0FC1

		//;public.c: 1405: sample_cnt++;
		INCR 	37H, 1H 		//024A 	1AB7

		//;public.c: 1407: break;
		RET 					//024B 	1008

		//;public.c: 1409: if((sample_data_ch0[0] < 2860) &&
		//;public.c: 1410: (sample_data_ch0[1] < 2860) &&
		//;public.c: 1411: (sample_data_ch0[2] < 2860) &&
		//;public.c: 1412: (sample_data_ch0[3] < 2860) &&
		//;public.c: 1413: (sample_data_ch0[4] < 2860) &&
		//;public.c: 1414: (sample_data_ch0[5] < 2860) &&
		//;public.c: 1415: (sample_data_ch0[6] < 2860) &&
		//;public.c: 1416: (sample_data_ch0[7] < 2860) &&
		//;public.c: 1417: (sample_data_ch0[8] < 2860) &&
		//;public.c: 1418: (sample_data_ch0[9] < 2860))
		LDWI 	BH 			//024C 	000B
		MOVLB 	2H 			//024D 	1022
		SUBWR 	21H, 0H 		//024E 	1221
		LDWI 	2CH 			//024F 	002C
		BTSC 	3H, 2H 			//0250 	2903
		SUBWR 	20H, 0H 		//0251 	1220
		BTSC 	3H, 0H 			//0252 	2803
		LJUMP 	296H 			//0253 	3A96
		LDWI 	BH 			//0254 	000B
		SUBWR 	23H, 0H 		//0255 	1223
		LDWI 	2CH 			//0256 	002C
		BTSC 	3H, 2H 			//0257 	2903
		SUBWR 	22H, 0H 		//0258 	1222
		BTSC 	3H, 0H 			//0259 	2803
		LJUMP 	296H 			//025A 	3A96
		LDWI 	BH 			//025B 	000B
		SUBWR 	25H, 0H 		//025C 	1225
		LDWI 	2CH 			//025D 	002C
		BTSC 	3H, 2H 			//025E 	2903
		SUBWR 	24H, 0H 		//025F 	1224
		BTSC 	3H, 0H 			//0260 	2803
		LJUMP 	296H 			//0261 	3A96
		LDWI 	BH 			//0262 	000B
		SUBWR 	27H, 0H 		//0263 	1227
		LDWI 	2CH 			//0264 	002C
		BTSC 	3H, 2H 			//0265 	2903
		SUBWR 	26H, 0H 		//0266 	1226
		BTSC 	3H, 0H 			//0267 	2803
		LJUMP 	296H 			//0268 	3A96
		LDWI 	BH 			//0269 	000B
		SUBWR 	29H, 0H 		//026A 	1229
		LDWI 	2CH 			//026B 	002C
		BTSC 	3H, 2H 			//026C 	2903
		SUBWR 	28H, 0H 		//026D 	1228
		BTSC 	3H, 0H 			//026E 	2803
		LJUMP 	296H 			//026F 	3A96
		LDWI 	BH 			//0270 	000B
		SUBWR 	2BH, 0H 		//0271 	122B
		LDWI 	2CH 			//0272 	002C
		BTSC 	3H, 2H 			//0273 	2903
		SUBWR 	2AH, 0H 		//0274 	122A
		BTSC 	3H, 0H 			//0275 	2803
		LJUMP 	296H 			//0276 	3A96
		LDWI 	BH 			//0277 	000B
		SUBWR 	2DH, 0H 		//0278 	122D
		LDWI 	2CH 			//0279 	002C
		BTSC 	3H, 2H 			//027A 	2903
		SUBWR 	2CH, 0H 		//027B 	122C
		BTSC 	3H, 0H 			//027C 	2803
		LJUMP 	296H 			//027D 	3A96
		LDWI 	BH 			//027E 	000B
		SUBWR 	2FH, 0H 		//027F 	122F
		LDWI 	2CH 			//0280 	002C
		BTSC 	3H, 2H 			//0281 	2903
		SUBWR 	2EH, 0H 		//0282 	122E
		BTSC 	3H, 0H 			//0283 	2803
		LJUMP 	296H 			//0284 	3A96
		LDWI 	BH 			//0285 	000B
		SUBWR 	31H, 0H 		//0286 	1231
		LDWI 	2CH 			//0287 	002C
		BTSC 	3H, 2H 			//0288 	2903
		SUBWR 	30H, 0H 		//0289 	1230
		BTSC 	3H, 0H 			//028A 	2803
		LJUMP 	296H 			//028B 	3A96
		LDWI 	BH 			//028C 	000B
		SUBWR 	33H, 0H 		//028D 	1233
		LDWI 	2CH 			//028E 	002C
		BTSC 	3H, 2H 			//028F 	2903
		SUBWR 	32H, 0H 		//0290 	1232
		BTSC 	3H, 0H 			//0291 	2803
		LJUMP 	296H 			//0292 	3A96

		//;public.c: 1419: {
		//;public.c: 1420: travell_flag_ch0 = 0;
		MOVLB 	0H 			//0293 	1020
		CLRF 	36H 			//0294 	11B6

		//;public.c: 1421: }
		LJUMP 	299H 			//0295 	3A99

		//;public.c: 1422: else
		//;public.c: 1423: {
		//;public.c: 1424: travell_flag_ch0 = 1;
		MOVLB 	0H 			//0296 	1020
		CLRF 	36H 			//0297 	11B6
		INCR 	36H, 1H 		//0298 	1AB6

		//;public.c: 1425: }
		//;public.c: 1450: if(Dimmer_Init_Flag == 1)
		DECRSZ 	6CH, 0H 		//0299 	1B6C
		LJUMP 	2C1H 			//029A 	3AC1

		//;public.c: 1451: {
		//;public.c: 1452: Dimmer_Init_Flag = 0;
		CLRF 	6CH 			//029B 	11EC

		//;public.c: 1455: {
		//;public.c: 1456: travell_flag_ch0_last = travell_flag_ch0;
		LDR 	36H, 0H 			//029C 	1836
		BTSS 	3H, 2H 			//029D 	2D03
		LJUMP 	2ABH 			//029E 	3AAB

		//;public.c: 1458: if(PowerFlag == 1)
		DECRSZ 	79H, 0H 		//029F 	1B79
		LJUMP 	2A6H 			//02A0 	3AA6

		//;public.c: 1459: {
		//;public.c: 1460: PowerFlag = 1;
		//;public.c: 1462: mcu_dp_value_update(0x01,PowerFlag);
		LCALL 	487H 			//02A1 	3487
		MOVLP 	0H 			//02A2 	0180
		LCALL 	30EH 			//02A3 	330E
		MOVLP 	0H 			//02A4 	0180

		//;public.c: 1464: }
		LJUMP 	2BFH 			//02A5 	3ABF

		//;public.c: 1466: {
		//;public.c: 1467: travell_flag_ch0_last = 1;
		LDR 	79H, 0H 			//02A6 	1879
		BTSS 	3H, 2H 			//02A7 	2D03
		LJUMP 	2BFH 			//02A8 	3ABF

		//;public.c: 1470: PowerFlag = 0;
		CLRF 	79H 			//02A9 	11F9
		LJUMP 	2B9H 			//02AA 	3AB9

		//;public.c: 1475: }
		//;public.c: 1477: }
		//;public.c: 1471: mcu_dp_value_update(0x01,PowerFlag);
		//;public.c: 1480: {
		//;public.c: 1481: travell_flag_ch0_last = travell_flag_ch0;
		DECRSZ 	36H, 0H 		//02AB 	1B36
		LJUMP 	2BFH 			//02AC 	3ABF

		//;public.c: 1483: if(PowerFlag == 0)
		LDR 	79H, 0H 			//02AD 	1879
		BTSS 	3H, 2H 			//02AE 	2D03
		LJUMP 	2B5H 			//02AF 	3AB5

		//;public.c: 1484: {
		//;public.c: 1485: PowerFlag = 0;
		//;public.c: 1486: mcu_dp_value_update(0x01,PowerFlag);
		LCALL 	48CH 			//02B0 	348C
		MOVLP 	0H 			//02B1 	0180
		LCALL 	30EH 			//02B2 	330E
		MOVLP 	0H 			//02B3 	0180

		//;public.c: 1487: }
		LJUMP 	2BFH 			//02B4 	3ABF

		//;public.c: 1489: {
		//;public.c: 1490: travell_flag_ch0_last = 0;
		DECRSZ 	79H, 0H 		//02B5 	1B79
		LJUMP 	2BFH 			//02B6 	3ABF

		//;public.c: 1493: PowerFlag = 1;
		CLRF 	79H 			//02B7 	11F9
		INCR 	79H, 1H 		//02B8 	1AF9

		//;public.c: 1494: mcu_dp_value_update(0x01,PowerFlag);
		LDR 	79H, 0H 			//02B9 	1879
		STR 	51H 			//02BA 	10D1
		LDWI 	1H 			//02BB 	0001
		LCALL 	30EH 			//02BC 	330E

		//;public.c: 1473: PA0 ^= 1;;
		LDWI 	1H 			//02BD 	0001
		XORWR 	CH, 1H 		//02BE 	168C

		//;public.c: 1498: }
		//;public.c: 1500: }
		//;public.c: 1501: sample_cnt = 0;
		CLRF 	37H 			//02BF 	11B7

		//;public.c: 1502: }
		RET 					//02C0 	1008

		//;public.c: 1504: else
		//;public.c: 1505: {
		//;public.c: 1507: if(PowerFlag == 1)
		DECRSZ 	79H, 0H 		//02C1 	1B79
		LJUMP 	2E1H 			//02C2 	3AE1

		//;public.c: 1508: {
		//;public.c: 1509: if(PowerFlag_last == 1)
		DECRSZ 	4AH, 0H 		//02C3 	1B4A
		LJUMP 	2DAH 			//02C4 	3ADA

		//;public.c: 1510: {
		//;public.c: 1512: if((travell_flag_ch0 == 1) && (travell_flag_load == 0))
		DECRSZ 	36H, 0H 		//02C5 	1B36
		LJUMP 	2CFH 			//02C6 	3ACF
		LDR 	35H, 0H 			//02C7 	1835
		BTSS 	3H, 2H 			//02C8 	2D03
		LJUMP 	2CFH 			//02C9 	3ACF

		//;public.c: 1513: {
		//;public.c: 1514: PowerFlag = 0;
		//;public.c: 1516: Switch_Ctrl_Flag = 11;
		LCALL 	48CH 			//02CA 	348C
		MOVLP 	0H 			//02CB 	0180
		LCALL 	30EH 			//02CC 	330E
		MOVLP 	0H 			//02CD 	0180

		//;public.c: 1517: }
		LJUMP 	2BFH 			//02CE 	3ABF

		//;public.c: 1518: else if((travell_flag_ch0 == 0) && (travell_flag_load == 0))
		LDR 	36H, 0H 			//02CF 	1836
		BTSS 	3H, 2H 			//02D0 	2D03
		LJUMP 	2BFH 			//02D1 	3ABF
		LDR 	35H, 0H 			//02D2 	1835
		BTSS 	3H, 2H 			//02D3 	2D03
		LJUMP 	2BFH 			//02D4 	3ABF

		//;public.c: 1519: {
		//;public.c: 1521: PowerFlag = 0;
		//;public.c: 1524: Switch_Ctrl_Flag = 12;
		LCALL 	48CH 			//02D5 	348C
		MOVLP 	0H 			//02D6 	0180
		LCALL 	30EH 			//02D7 	330E
		MOVLP 	0H 			//02D8 	0180
		LJUMP 	2BFH 			//02D9 	3ABF

		//;public.c: 1527: else if(travell_flag_load == 1)
		DECRSZ 	35H, 0H 		//02DA 	1B35
		LJUMP 	2DDH 			//02DB 	3ADD
		LJUMP 	2DEH 			//02DC 	3ADE
		LJUMP 	2BFH 			//02DD 	3ABF

		//;public.c: 1528: {
		//;public.c: 1529: PowerFlag_last = 1;
		CLRF 	4AH 			//02DE 	11CA
		INCR 	4AH, 1H 		//02DF 	1ACA
		LJUMP 	2BFH 			//02E0 	3ABF

		//;public.c: 1532: else if(PowerFlag == 0)
		LDR 	79H, 0H 			//02E1 	1879
		BTSS 	3H, 2H 			//02E2 	2D03
		LJUMP 	2BFH 			//02E3 	3ABF

		//;public.c: 1533: {
		//;public.c: 1534: if(PowerFlag_last == 0)
		LDR 	4AH, 0H 			//02E4 	184A
		BTSS 	3H, 2H 			//02E5 	2D03
		LJUMP 	2FEH 			//02E6 	3AFE

		//;public.c: 1535: {
		//;public.c: 1537: if(travell_flag_ch0 == 0)
		LDR 	36H, 0H 			//02E7 	1836
		BTSS 	3H, 2H 			//02E8 	2D03
		LJUMP 	2BFH 			//02E9 	3ABF
		LDWI 	32H 			//02EA 	0032

		//;public.c: 1540: Switch_Ctrl_Flag = 21;
		CLRF 	79H 			//02EB 	11F9
		INCR 	79H, 1H 		//02EC 	1AF9

		//;public.c: 1542: DelayMs(50);
		STR 	52H 			//02ED 	10D2
		CLRF 	53H 			//02EE 	11D3
		LCALL 	31EH 			//02EF 	331E
		MOVLP 	0H 			//02F0 	0180

		//;public.c: 1543: if(travell_flag_load == 1)
		DECRSZ 	35H, 0H 		//02F1 	1B35
		LJUMP 	2F9H 			//02F2 	3AF9

		//;public.c: 1546: Switch_Ctrl_Flag = 22;
		LDR 	79H, 0H 			//02F3 	1879
		STR 	51H 			//02F4 	10D1
		LDWI 	1H 			//02F5 	0001
		LCALL 	30EH 			//02F6 	330E
		MOVLP 	0H 			//02F7 	0180

		//;public.c: 1547: }
		LJUMP 	2BFH 			//02F8 	3ABF

		//;public.c: 1548: else if(travell_flag_load == 0)
		LDR 	35H, 0H 			//02F9 	1835
		BTSS 	3H, 2H 			//02FA 	2D03
		LJUMP 	2BFH 			//02FB 	3ABF

		//;public.c: 1551: Switch_Ctrl_Flag = 23;
		CLRF 	79H 			//02FC 	11F9
		LJUMP 	2BFH 			//02FD 	3ABF

		//;public.c: 1567: else if(travell_flag_load == 0)
		LDR 	35H, 0H 			//02FE 	1835
		BTSS 	3H, 2H 			//02FF 	2D03
		LJUMP 	2BFH 			//0300 	3ABF

		//;public.c: 1568: {
		//;public.c: 1569: PowerFlag_last = 0;
		CLRF 	4AH 			//0301 	11CA
		LJUMP 	2BFH 			//0302 	3ABF
		LDR 	37H, 0H 			//0303 	1837
		STR 	4H 			//0304 	1084
		LDWI 	BH 			//0305 	000B
		SUBWR 	4H, 0H 		//0306 	1204
		BTSC 	3H, 0H 			//0307 	2803
		RET 					//0308 	1008
		MOVLP 	8H 			//0309 	0188
		LSLF 	4H, 0H 			//030A 	0504
		ADDWI 	0H 			//030B 	0E00
		STR 	2H 			//030C 	1082
		RET 					//030D 	1008
		STR 	52H 			//030E 	10D2

		//;public.c: 957: {
		//;public.c: 958: UartTxBuf[0] = 0x55;
		LDWI 	55H 			//030F 	0055
		MOVLB 	1H 			//0310 	1021
		STR 	20H 			//0311 	10A0

		//;public.c: 959: UartTxBuf[1] = 0xAA;
		LDWI 	AAH 			//0312 	00AA
		STR 	21H 			//0313 	10A1

		//;public.c: 960: UartTxBuf[2] = sync_cmd;
		MOVLB 	0H 			//0314 	1020
		LDR 	52H, 0H 			//0315 	1852
		MOVLB 	1H 			//0316 	1021
		STR 	22H 			//0317 	10A2

		//;public.c: 961: UartTxBuf[3] = sync_data;
		MOVLB 	0H 			//0318 	1020
		LDR 	51H, 0H 			//0319 	1851
		MOVLB 	1H 			//031A 	1021
		STR 	23H 			//031B 	10A3

		//;public.c: 963: UartSendData();
		MOVLP 	6H 			//031C 	0186
		LJUMP 	60AH 			//031D 	3E0A

		//;public.c: 133: unsigned char a,b;
		//;public.c: 134: for(a=0;a<Time;a++)
		CLRF 	56H 			//031E 	11D6
		LDR 	56H, 0H 			//031F 	1856
		STR 	54H 			//0320 	10D4
		CLRF 	55H 			//0321 	11D5
		LDR 	53H, 0H 			//0322 	1853
		SUBWR 	55H, 0H 		//0323 	1255
		BTSS 	3H, 2H 			//0324 	2D03
		LJUMP 	328H 			//0325 	3B28
		LDR 	52H, 0H 			//0326 	1852
		SUBWR 	54H, 0H 		//0327 	1254
		BTSC 	3H, 0H 			//0328 	2803
		RET 					//0329 	1008

		//;public.c: 135: {
		//;public.c: 136: for(b=0;b<5;b++)
		CLRF 	57H 			//032A 	11D7

		//;public.c: 137: {
		//;public.c: 138: DelayUs(197);
		LDWI 	C5H 			//032B 	00C5
		LCALL 	34DH 			//032C 	334D
		MOVLP 	0H 			//032D 	0180
		LDWI 	5H 			//032E 	0005
		INCR 	57H, 1H 		//032F 	1AD7
		SUBWR 	57H, 0H 		//0330 	1257
		BTSS 	3H, 0H 			//0331 	2C03
		LJUMP 	32BH 			//0332 	3B2B
		INCR 	56H, 1H 		//0333 	1AD6
		LJUMP 	31FH 			//0334 	3B1F

		//;public.c: 1093: PCKEN |=0B00000001;
		BSR 	1AH, 0H 			//0335 	241A

		//;public.c: 1095: ANSELA = 0B00100000;
		LDWI 	20H 			//0336 	0020
		MOVLB 	3H 			//0337 	1023
		STR 	17H 			//0338 	1097

		//;public.c: 1098: ADCON1 = 0B11100100;
		LDWI 	E4H 			//0339 	00E4
		MOVLB 	1H 			//033A 	1021
		STR 	1EH 			//033B 	109E

		//;public.c: 1125: ADCON0 = 0B00000000;
		CLRF 	1DH 			//033C 	119D

		//;public.c: 1157: ADCON2 = 0B10000000;
		LDWI 	80H 			//033D 	0080
		STR 	1FH 			//033E 	109F

		//;public.c: 1185: ADCON3 = 0B00000000;
		MOVLB 	8H 			//033F 	1028
		CLRF 	1AH 			//0340 	119A

		//;public.c: 1212: ADDLY = 0B00000000;
		MOVLB 	0H 			//0341 	1020
		CLRF 	1FH 			//0342 	119F

		//;public.c: 1217: ADCMPH = 0B00000000;
		MOVLB 	8H 			//0343 	1028
		CLRF 	1BH 			//0344 	119B

		//;public.c: 1220: ADCAL=1;
		MOVLB 	1H 			//0345 	1021
		BSR 	1DH, 3H 			//0346 	259D

		//;public.c: 1221: __nop();
		NOP 					//0347 	1000

		//;public.c: 1222: while(ADCAL);
		MOVLB 	1H 			//0348 	1021
		BTSC 	1DH, 3H 		//0349 	299D
		LJUMP 	348H 			//034A 	3B48

		//;public.c: 1224: ADON=1;
		BSR 	1DH, 0H 			//034B 	241D
		RET 					//034C 	1008
		MOVLB 	0H 			//034D 	1020
		STR 	50H 			//034E 	10D0

		//;public.c: 118: unsigned char a;
		//;public.c: 119: for(a=0;a<Time;a++)
		CLRF 	51H 			//034F 	11D1
		LDR 	50H, 0H 			//0350 	1850
		SUBWR 	51H, 0H 		//0351 	1251
		BTSC 	3H, 0H 			//0352 	2803
		RET 					//0353 	1008

		//;public.c: 120: {
		//;public.c: 121: __nop();
		NOP 					//0354 	1000
		MOVLB 	0H 			//0355 	1020
		INCR 	51H, 1H 		//0356 	1AD1
		LJUMP 	350H 			//0357 	3B50

		//;Dim.c: 561: switch(FactoryFlag)
		LJUMP 	397H 			//0358 	3B97

		//;Dim.c: 564: FactoryState = 0;
		CLRF 	42H 			//0359 	11C2

		//;Dim.c: 565: FactoryNumer = 0;
		MOVLB 	1H 			//035A 	1021
		CLRF 	38H 			//035B 	11B8
		CLRF 	39H 			//035C 	11B9

		//;Dim.c: 566: if(0 == FactoryFirstFlag)
		MOVLB 	0H 			//035D 	1020
		LDR 	41H, 0H 			//035E 	1841
		BTSS 	3H, 2H 			//035F 	2D03
		RET 					//0360 	1008

		//;Dim.c: 567: {
		//;Dim.c: 568: FactoryFirstFlag = 1;
		CLRF 	41H 			//0361 	11C1
		INCR 	41H, 1H 		//0362 	1AC1

		//;Dim.c: 569: if((PD2 == 0)&&(PD1 == 0))
		BTSS 	FH, 2H 			//0363 	2D0F
		BTSC 	FH, 1H 			//0364 	288F
		RET 					//0365 	1008

		//;Dim.c: 570: {
		//;Dim.c: 578: PC1 = 0;;
		BCR 	EH, 1H 			//0366 	208E

		//;Dim.c: 579: PB7 = 0;;
		BCR 	DH, 7H 			//0367 	238D

		//;Dim.c: 580: FactoryFlag = 1;
		CLRF 	43H 			//0368 	11C3
		INCR 	43H, 1H 		//0369 	1AC3

		//;Dim.c: 582: }
		//;Dim.c: 583: }
		//;Dim.c: 584: break;
		RET 					//036A 	1008

		//;Dim.c: 586: if(++FactoryNumer >= 250)
		MOVLB 	1H 			//036B 	1021
		INCR 	38H, 1H 		//036C 	1AB8
		BTSC 	3H, 2H 			//036D 	2903
		INCR 	39H, 1H 		//036E 	1AB9
		LDWI 	0H 			//036F 	0000
		SUBWR 	39H, 0H 		//0370 	1239
		LDWI 	FAH 			//0371 	00FA
		BTSC 	3H, 2H 			//0372 	2903
		SUBWR 	38H, 0H 		//0373 	1238
		BTSS 	3H, 0H 			//0374 	2C03
		LJUMP 	380H 			//0375 	3B80

		//;Dim.c: 587: {
		//;Dim.c: 588: FactoryNumer = 0;
		CLRF 	38H 			//0376 	11B8
		CLRF 	39H 			//0377 	11B9

		//;Dim.c: 589: FactoryState ++;
		MOVLB 	0H 			//0378 	1020
		LDWI 	4H 			//0379 	0004
		INCR 	42H, 1H 		//037A 	1AC2

		//;Dim.c: 590: if(FactoryState > 3)
		SUBWR 	42H, 0H 		//037B 	1242
		BTSS 	3H, 0H 			//037C 	2C03
		LJUMP 	380H 			//037D 	3B80

		//;Dim.c: 591: FactoryState = 3;
		LDWI 	3H 			//037E 	0003
		STR 	42H 			//037F 	10C2

		//;Dim.c: 593: {
		//;Dim.c: 595: }
		//;Dim.c: 596: }
		//;Dim.c: 597: if(FactoryState == 0)
		MOVLB 	0H 			//0380 	1020
		LDR 	42H, 0H 			//0381 	1842
		BTSS 	3H, 2H 			//0382 	2D03
		LJUMP 	38BH 			//0383 	3B8B

		//;Dim.c: 598: {
		//;Dim.c: 600: AngleMin = 142;
		LDWI 	8EH 			//0384 	008E
		STR 	6EH 			//0385 	10EE

		//;Dim.c: 601: DimPercentData = 1;
		CLRF 	6DH 			//0386 	11ED
		INCR 	6DH, 1H 		//0387 	1AED

		//;Dim.c: 602: PowerFlag = 1;
		CLRF 	79H 			//0388 	11F9
		INCR 	79H, 1H 		//0389 	1AF9

		//;Dim.c: 603: }
		RET 					//038A 	1008

		//;Dim.c: 604: else if(FactoryState == 1)
		DECRSZ 	42H, 0H 		//038B 	1B42
		LJUMP 	390H 			//038C 	3B90

		//;Dim.c: 605: {
		//;Dim.c: 606: DimPercentData = 100;
		LDWI 	64H 			//038D 	0064
		STR 	6DH 			//038E 	10ED

		//;Dim.c: 607: }
		RET 					//038F 	1008

		//;Dim.c: 608: else if(FactoryState == 2)
		LDWI 	2H 			//0390 	0002
		XORWR 	42H, 0H 		//0391 	1642
		BTSS 	3H, 2H 			//0392 	2D03
		RET 					//0393 	1008

		//;Dim.c: 609: {
		//;Dim.c: 610: PowerFlag = 0;
		CLRF 	79H 			//0394 	11F9

		//;Dim.c: 611: PA0 = 1;;
		BSR 	CH, 0H 			//0395 	240C

		//;Dim.c: 612: }
		RET 					//0396 	1008
		LDR 	43H, 0H 			//0397 	1843
		XORWI 	0H 			//0398 	0A00
		BTSC 	3H, 2H 			//0399 	2903
		LJUMP 	359H 			//039A 	3B59
		XORWI 	1H 			//039B 	0A01
		BTSC 	3H, 2H 			//039C 	2903
		LJUMP 	36BH 			//039D 	3B6B
		LJUMP 	39FH 			//039E 	3B9F
		RET 					//039F 	1008

		//;public.c: 184: EPS0 = 0B00000010;
		LDWI 	2H 			//03A0 	0002
		MOVLB 	2H 			//03A1 	1022
		STR 	18H 			//03A2 	1098

		//;public.c: 188: EPS1 = 0B00000000;
		CLRF 	19H 			//03A3 	1199

		//;public.c: 191: ITYPE0 = 0B00001101;
		LDWI 	DH 			//03A4 	000D
		STR 	1EH 			//03A5 	109E

		//;public.c: 193: ITYPE1 = 0B00000000;
		CLRF 	1FH 			//03A6 	119F

		//;public.c: 195: EPIE0 = 0B00000011;
		LDWI 	3H 			//03A7 	0003
		MOVLB 	1H 			//03A8 	1021
		STR 	14H 			//03A9 	1094

		//;public.c: 197: EPIF0 = 0xFF;
		LDWI 	FFH 			//03AA 	00FF
		MOVLB 	0H 			//03AB 	1020
		STR 	14H 			//03AC 	1094

		//;public.c: 199: PEIE = 1;
		BSR 	BH, 6H 			//03AD 	270B

		//;public.c: 200: GIE = 1;
		BSR 	BH, 7H 			//03AE 	278B
		RET 					//03AF 	1008

		//;Dim.c: 493: u16 i;
		//;Dim.c: 511: for(i=0;i<6;i++)
		CLRF 	56H 			//03B0 	11D6
		CLRF 	57H 			//03B1 	11D7

		//;Dim.c: 512: {
		//;Dim.c: 513: pBuffer[i] = EEPROMread(i); ;
		LDR 	56H, 0H 			//03B2 	1856
		ADDWR 	54H, 0H 		//03B3 	1754
		STR 	55H 			//03B4 	10D5
		STR 	6H 			//03B5 	1086
		CLRF 	7H 			//03B6 	1187
		LDR 	56H, 0H 			//03B7 	1856
		LCALL 	3DDH 			//03B8 	33DD
		MOVLP 	0H 			//03B9 	0180
		STR 	1H 			//03BA 	1081
		INCR 	56H, 1H 		//03BB 	1AD6
		BTSC 	3H, 2H 			//03BC 	2903
		INCR 	57H, 1H 		//03BD 	1AD7
		LDWI 	0H 			//03BE 	0000
		SUBWR 	57H, 0H 		//03BF 	1257
		LDWI 	6H 			//03C0 	0006
		BTSC 	3H, 2H 			//03C1 	2903
		SUBWR 	56H, 0H 		//03C2 	1256
		BTSS 	3H, 0H 			//03C3 	2C03
		LJUMP 	3B2H 			//03C4 	3BB2

		//;Dim.c: 514: }
		//;Dim.c: 515: PowerFlag = 0;
		CLRF 	79H 			//03C5 	11F9

		//;Dim.c: 516: if(pBuffer[0]==0xaa)
		LDR 	54H, 0H 			//03C6 	1854
		STR 	6H 			//03C7 	1086
		LDWI 	AAH 			//03C8 	00AA
		CLRF 	7H 			//03C9 	1187
		XORWR 	1H, 0H 		//03CA 	1601
		BTSS 	3H, 2H 			//03CB 	2D03
		RET 					//03CC 	1008

		//;Dim.c: 517: {
		//;Dim.c: 520: DimPercentMin = pBuffer[3];
		LDR 	54H, 0H 			//03CD 	1854
		STR 	6H 			//03CE 	1086
		MOVIW 	3H[1] 			//03CF 	0F43
		STR 	67H 			//03D0 	10E7

		//;Dim.c: 521: DimMin = pBuffer[4];
		LDR 	54H, 0H 			//03D1 	1854
		STR 	6H 			//03D2 	1086
		MOVIW 	4H[1] 			//03D3 	0F44
		STR 	65H 			//03D4 	10E5

		//;Dim.c: 522: PowerLedFlag = pBuffer[5];
		LDR 	54H, 0H 			//03D5 	1854
		STR 	6H 			//03D6 	1086
		MOVIW 	5H[1] 			//03D7 	0F45
		STR 	6AH 			//03D8 	10EA

		//;Dim.c: 523: DimPercentDataOppose = 100 - DimPercentData;
		LDR 	6DH, 0H 			//03D9 	186D
		SUBWI 	64H 			//03DA 	0C64
		STR 	46H 			//03DB 	10C6
		RET 					//03DC 	1008
		STR 	50H 			//03DD 	10D0

		//;public.c: 1263: unsigned char ReEEPROMread;
		//;public.c: 1265: DRDEN=1;
		MOVLB 	3H 			//03DE 	1023
		BSR 	18H, 0H 			//03DF 	2418

		//;public.c: 1266: __nop();
		NOP 					//03E0 	1000

		//;public.c: 1267: __nop();
		NOP 					//03E1 	1000

		//;public.c: 1268: EEADRL = EEAddr;
		MOVLB 	0H 			//03E2 	1020
		LDR 	50H, 0H 			//03E3 	1850
		MOVLB 	3H 			//03E4 	1023
		STR 	11H 			//03E5 	1091

		//;public.c: 1270: CFGS =0;
		BCR 	15H, 6H 			//03E6 	2315

		//;public.c: 1271: EEPGD=0;
		BCR 	15H, 7H 			//03E7 	2395

		//;public.c: 1272: RD = 1;
		BSR 	15H, 0H 			//03E8 	2415

		//;public.c: 1274: ReEEPROMread = EEDATL;
		LDR 	13H, 0H 			//03E9 	1813
		MOVLB 	0H 			//03EA 	1020
		STR 	51H 			//03EB 	10D1

		//;public.c: 1275: DRDEN=0;
		MOVLB 	3H 			//03EC 	1023
		BCR 	18H, 0H 			//03ED 	2018

		//;public.c: 1276: return ReEEPROMread;
		MOVLB 	0H 			//03EE 	1020
		LDR 	51H, 0H 			//03EF 	1851
		RET 					//03F0 	1008

		//;Key.c: 13: switch(KeyState)
		LJUMP 	46CH 			//03F1 	3C6C

		//;Key.c: 14: {
		//;Key.c: 15: case 0:
		//;Key.c: 16: if((PD1==0)&&(PD2==0))
		BTSS 	FH, 1H 			//03F2 	2C8F
		BTSC 	FH, 2H 			//03F3 	290F
		LJUMP 	409H 			//03F4 	3C09

		//;Key.c: 17: {
		//;Key.c: 18: KeyState1 = 0;
		CLRF 	33H 			//03F5 	11B3

		//;Key.c: 19: KeyNumer1 = 0;
		CLRF 	78H 			//03F6 	11F8

		//;Key.c: 20: if(++KeyNumer>=500)
		MOVLB 	1H 			//03F7 	1021
		INCR 	34H, 1H 		//03F8 	1AB4
		BTSC 	3H, 2H 			//03F9 	2903
		INCR 	35H, 1H 		//03FA 	1AB5
		LDWI 	1H 			//03FB 	0001
		SUBWR 	35H, 0H 		//03FC 	1235
		LDWI 	F4H 			//03FD 	00F4
		BTSC 	3H, 2H 			//03FE 	2903
		SUBWR 	34H, 0H 		//03FF 	1234
		BTSS 	3H, 0H 			//0400 	2C03
		RETW 	0H 			//0401 	0400

		//;Key.c: 21: {
		//;Key.c: 22: KeyNumer = 0;
		CLRF 	34H 			//0402 	11B4
		CLRF 	35H 			//0403 	11B5

		//;Key.c: 23: KeyState = 1;
		MOVLB 	0H 			//0404 	1020
		LDWI 	5H 			//0405 	0005
		CLRF 	34H 			//0406 	11B4
		INCR 	34H, 1H 		//0407 	1AB4

		//;Key.c: 24: return 5;
		RET 					//0408 	1008

		//;Key.c: 25: }
		//;Key.c: 26: }
		//;Key.c: 27: else
		//;Key.c: 28: {
		//;Key.c: 29: KeyNumer = 0;
		MOVLB 	1H 			//0409 	1021
		CLRF 	34H 			//040A 	11B4
		CLRF 	35H 			//040B 	11B5

		//;Key.c: 30: switch(KeyState1)
		LJUMP 	457H 			//040C 	3C57

		//;Key.c: 33: KeyNumer1++;
		INCR 	78H, 1H 		//040D 	1AF8

		//;Key.c: 34: if(PD1==0)
		BTSC 	FH, 1H 			//040E 	288F
		LJUMP 	418H 			//040F 	3C18

		//;Key.c: 35: {
		//;Key.c: 36: if(KeyNumer1 >= 3)
		LDWI 	3H 			//0410 	0003
		SUBWR 	78H, 0H 		//0411 	1278
		BTSS 	3H, 0H 			//0412 	2C03
		RETW 	0H 			//0413 	0400

		//;Key.c: 37: {
		//;Key.c: 38: KeyNumer1 = 0;
		CLRF 	78H 			//0414 	11F8

		//;Key.c: 39: KeyState1 = 1;
		CLRF 	33H 			//0415 	11B3
		INCR 	33H, 1H 		//0416 	1AB3
		RETW 	0H 			//0417 	0400

		//;Key.c: 42: else if(PD2==0)
		BTSC 	FH, 2H 			//0418 	290F
		LJUMP 	46AH 			//0419 	3C6A

		//;Key.c: 43: {
		//;Key.c: 44: if(KeyNumer1 >= 3)
		LDWI 	3H 			//041A 	0003
		SUBWR 	78H, 0H 		//041B 	1278
		BTSS 	3H, 0H 			//041C 	2C03
		RETW 	0H 			//041D 	0400
		LDWI 	4H 			//041E 	0004
		LJUMP 	446H 			//041F 	3C46

		//;Key.c: 53: case 1:
		//;Key.c: 50: else
		//;Key.c: 51: KeyNumer1 = 0;
		//;Key.c: 47: KeyState1 = 4;
		//;Key.c: 45: {
		//;Key.c: 46: KeyNumer1 = 0;
		//;Key.c: 54: if(PD1)
		BTSS 	FH, 1H 			//0420 	2C8F
		LJUMP 	425H 			//0421 	3C25
		LDWI 	1H 			//0422 	0001

		//;Key.c: 55: {
		//;Key.c: 56: KeyState1 = 0;
		CLRF 	33H 			//0423 	11B3

		//;Key.c: 57: return 1;
		RET 					//0424 	1008

		//;Key.c: 58: }
		//;Key.c: 59: if(++KeyNumer1 >= 100)
		LDWI 	64H 			//0425 	0064
		INCR 	78H, 1H 		//0426 	1AF8
		SUBWR 	78H, 0H 		//0427 	1278
		BTSS 	3H, 0H 			//0428 	2C03
		RETW 	0H 			//0429 	0400
		LDWI 	2H 			//042A 	0002
		LJUMP 	446H 			//042B 	3C46

		//;Key.c: 62: KeyState1 = 2;
		//;Key.c: 60: {
		//;Key.c: 61: KeyNumer1 = 0;
		//;Key.c: 66: if(++KeyNumer1 >= 3)
		LDWI 	3H 			//042C 	0003
		INCR 	78H, 1H 		//042D 	1AF8
		SUBWR 	78H, 0H 		//042E 	1278
		BTSS 	3H, 0H 			//042F 	2C03
		LJUMP 	434H 			//0430 	3C34
		LDWI 	3H 			//0431 	0003

		//;Key.c: 67: {
		//;Key.c: 68: KeyNumer1 = 0;
		CLRF 	78H 			//0432 	11F8

		//;Key.c: 69: KeyState1 = 3;
		STR 	33H 			//0433 	10B3

		//;Key.c: 70: }
		//;Key.c: 71: if(PD1)
		BTSS 	FH, 1H 			//0434 	2C8F
		RETW 	0H 			//0435 	0400

		//;Key.c: 72: {
		//;Key.c: 73: KeyState1 = 0;
		CLRF 	33H 			//0436 	11B3
		RETW 	0H 			//0437 	0400

		//;Key.c: 76: case 3:
		//;Key.c: 77: if(PD1)
		BTSC 	FH, 1H 			//0438 	288F

		//;Key.c: 78: {
		//;Key.c: 79: KeyState1 = 0;
		CLRF 	33H 			//0439 	11B3

		//;Key.c: 80: }
		//;Key.c: 81: return 2;
		RETW 	2H 			//043A 	0402

		//;Key.c: 83: case 4:
		//;Key.c: 84: if(PD2)
		BTSS 	FH, 2H 			//043B 	2D0F
		LJUMP 	440H 			//043C 	3C40
		LDWI 	3H 			//043D 	0003

		//;Key.c: 85: {
		//;Key.c: 86: KeyState1 = 0;
		CLRF 	33H 			//043E 	11B3

		//;Key.c: 87: return 3;
		RET 					//043F 	1008

		//;Key.c: 88: }
		//;Key.c: 89: if(++KeyNumer1 >= 100)
		LDWI 	64H 			//0440 	0064
		INCR 	78H, 1H 		//0441 	1AF8
		SUBWR 	78H, 0H 		//0442 	1278
		BTSS 	3H, 0H 			//0443 	2C03
		RETW 	0H 			//0444 	0400
		LDWI 	5H 			//0445 	0005

		//;Key.c: 90: {
		//;Key.c: 91: KeyNumer1 = 0;
		CLRF 	78H 			//0446 	11F8

		//;Key.c: 92: KeyState1 = 5;
		STR 	33H 			//0447 	10B3
		RETW 	0H 			//0448 	0400

		//;Key.c: 96: if(++KeyNumer1 >= 3)
		LDWI 	3H 			//0449 	0003
		INCR 	78H, 1H 		//044A 	1AF8
		SUBWR 	78H, 0H 		//044B 	1278
		BTSS 	3H, 0H 			//044C 	2C03
		LJUMP 	451H 			//044D 	3C51
		LDWI 	6H 			//044E 	0006

		//;Key.c: 97: {
		//;Key.c: 98: KeyNumer1 = 0;
		CLRF 	78H 			//044F 	11F8

		//;Key.c: 99: KeyState1 = 6;
		STR 	33H 			//0450 	10B3

		//;Key.c: 100: }
		//;Key.c: 101: if(PD2)
		BTSS 	FH, 2H 			//0451 	2D0F
		RETW 	0H 			//0452 	0400
		LJUMP 	436H 			//0453 	3C36

		//;Key.c: 106: case 6:
		//;Key.c: 107: if(PD2)
		BTSC 	FH, 2H 			//0454 	290F

		//;Key.c: 108: {
		//;Key.c: 109: KeyState1 = 0;
		CLRF 	33H 			//0455 	11B3

		//;Key.c: 110: }
		//;Key.c: 111: return 4;
		RETW 	4H 			//0456 	0404
		MOVLB 	0H 			//0457 	1020
		LDR 	33H, 0H 			//0458 	1833
		STR 	4H 			//0459 	1084
		LDWI 	7H 			//045A 	0007
		SUBWR 	4H, 0H 		//045B 	1204
		BTSC 	3H, 0H 			//045C 	2803
		RETW 	0H 			//045D 	0400
		MOVLP 	8H 			//045E 	0188
		LSLF 	4H, 0H 			//045F 	0504
		ADDWI 	16H 			//0460 	0E16
		STR 	2H 			//0461 	1082

		//;Key.c: 118: case 1:
		//;Key.c: 119: if((PD1)||(PD2))
		BTSC 	FH, 1H 			//0462 	288F
		LJUMP 	466H 			//0463 	3C66
		BTSS 	FH, 2H 			//0464 	2D0F
		RETW 	0H 			//0465 	0400

		//;Key.c: 120: {
		//;Key.c: 121: KeyState = 0;
		CLRF 	34H 			//0466 	11B4

		//;Key.c: 122: KeyNumer = 0;
		MOVLB 	1H 			//0467 	1021
		CLRF 	34H 			//0468 	11B4
		CLRF 	35H 			//0469 	11B5

		//;Key.c: 123: KeyNumer1 = 0;
		CLRF 	78H 			//046A 	11F8
		RETW 	0H 			//046B 	0400
		LDR 	34H, 0H 			//046C 	1834
		XORWI 	0H 			//046D 	0A00
		BTSC 	3H, 2H 			//046E 	2903
		LJUMP 	3F2H 			//046F 	3BF2
		XORWI 	1H 			//0470 	0A01
		BTSC 	3H, 2H 			//0471 	2903
		LJUMP 	462H 			//0472 	3C62
		LJUMP 	474H 			//0473 	3C74

		//;Key.c: 129: return 0;
		RETW 	0H 			//0474 	0400

		//;public.c: 546: PCKEN |=0B00000100;
		MOVLB 	1H 			//0475 	1021
		BSR 	1AH, 2H 			//0476 	251A

		//;public.c: 547: CKOCON=0B00100000;
		LDWI 	20H 			//0477 	0020
		STR 	15H 			//0478 	1095

		//;public.c: 548: TCKSRC=0B00110000;
		LDWI 	30H 			//0479 	0030
		MOVLB 	6H 			//047A 	1026
		STR 	1FH 			//047B 	109F

		//;public.c: 573: TIM2CR1 =0B10000101;
		LDWI 	85H 			//047C 	0085
		STR 	CH 			//047D 	108C

		//;public.c: 606: TIM2IER =0B00000001;
		LDWI 	1H 			//047E 	0001
		STR 	DH 			//047F 	108D

		//;public.c: 764: TIM2PSCR = 3;
		LDWI 	3H 			//0480 	0003
		STR 	18H 			//0481 	1098

		//;public.c: 769: TIM2ARRH =0x00;
		CLRF 	19H 			//0482 	1199

		//;public.c: 770: TIM2ARRL =0xA0;
		LDWI 	A0H 			//0483 	00A0
		STR 	1AH 			//0484 	109A

		//;public.c: 781: GIE =1;
		BSR 	BH, 7H 			//0485 	278B
		RET 					//0486 	1008
		CLRF 	79H 			//0487 	11F9
		INCR 	79H, 1H 		//0488 	1AF9
		LDR 	79H, 0H 			//0489 	1879
		STR 	51H 			//048A 	10D1
		RETW 	1H 			//048B 	0401
		CLRF 	79H 			//048C 	11F9
		LDR 	79H, 0H 			//048D 	1879
		STR 	51H 			//048E 	10D1
		RETW 	1H 			//048F 	0401

		//;public.c: 792: PCKEN |=0B00001000;
		MOVLB 	1H 			//0490 	1021
		BSR 	1AH, 3H 			//0491 	259A

		//;public.c: 796: TIM4CR1 =0B00000101;
		LDWI 	5H 			//0492 	0005
		MOVLB 	2H 			//0493 	1022
		STR 	11H 			//0494 	1091

		//;public.c: 827: TIM4IER =0B00000001;
		LDWI 	1H 			//0495 	0001
		STR 	12H 			//0496 	1092

		//;public.c: 830: TIM4SR =0B00000000;
		CLRF 	13H 			//0497 	1193

		//;public.c: 839: TIM4EGR =0B00000000;
		CLRF 	14H 			//0498 	1194

		//;public.c: 844: TIM4CNTR=0;
		CLRF 	15H 			//0499 	1195

		//;public.c: 846: TIM4PSCR=0B00000100;
		LDWI 	4H 			//049A 	0004
		STR 	16H 			//049B 	1096

		//;public.c: 851: TIM4ARR = 250;
		LDWI 	FAH 			//049C 	00FA
		STR 	17H 			//049D 	1097

		//;public.c: 855: INTCON |= 0B11000000;
		LDWI 	C0H 			//049E 	00C0
		IORWR 	BH, 1H 		//049F 	148B
		RET 					//04A0 	1008

		//;innotech_led.c: 129: switch (innotech_led_state_get())
		LJUMP 	4F0H 			//04A1 	3CF0

		//;innotech_led.c: 132: if (led_cnt % 50 == 26)
		LCALL 	628H 			//04A2 	3628
		MOVLP 	4H 			//04A3 	0184
		LCALL 	503H 			//04A4 	3503
		MOVLP 	4H 			//04A5 	0184
		LDWI 	1AH 			//04A6 	001A
		XORWR 	50H, 0H 		//04A7 	1650
		IORWR 	51H, 0H 		//04A8 	1451
		BTSS 	3H, 2H 			//04A9 	2D03
		LJUMP 	4ADH 			//04AA 	3CAD

		//;innotech_led.c: 133: {
		//;innotech_led.c: 134: PB7 = 0;;
		BCR 	DH, 7H 			//04AB 	238D
		LJUMP 	4B6H 			//04AC 	3CB6

		//;innotech_led.c: 136: }
		//;innotech_led.c: 135: PC1 = 1;;
		//;innotech_led.c: 137: else if (led_cnt % 50 == 1)
		LCALL 	628H 			//04AD 	3628
		MOVLP 	4H 			//04AE 	0184
		LCALL 	503H 			//04AF 	3503
		MOVLP 	4H 			//04B0 	0184
		DECR 	50H, 0H 		//04B1 	1350
		IORWR 	51H, 0H 		//04B2 	1451
		BTSS 	3H, 2H 			//04B3 	2D03
		LJUMP 	4B7H 			//04B4 	3CB7

		//;innotech_led.c: 138: {
		//;innotech_led.c: 139: PB7 = 1;;
		BSR 	DH, 7H 			//04B5 	278D

		//;innotech_led.c: 140: PC1 = 1;;
		BSR 	EH, 1H 			//04B6 	248E

		//;innotech_led.c: 141: }
		//;innotech_led.c: 142: if (led_cnt == 45000)
		LDWI 	C8H 			//04B7 	00C8
		XORWR 	20H, 0H 		//04B8 	1620
		LDWI 	AFH 			//04B9 	00AF
		BTSC 	3H, 2H 			//04BA 	2903
		XORWR 	21H, 0H 		//04BB 	1621
		BTSS 	3H, 2H 			//04BC 	2D03
		RET 					//04BD 	1008

		//;innotech_led.c: 143: {
		//;innotech_led.c: 144: PB7 = 1;;
		BSR 	DH, 7H 			//04BE 	278D

		//;innotech_led.c: 145: PC1 = 1;;
		BSR 	EH, 1H 			//04BF 	248E

		//;innotech_led.c: 146: led_play_done = 1;
		CLRF 	2AH 			//04C0 	11AA
		INCR 	2AH, 1H 		//04C1 	1AAA

		//;innotech_led.c: 147: innotech_network_state_reset();
		LJUMP 	61FH 			//04C2 	3E1F

		//;innotech_led.c: 152: if (led_cnt == 1)
		DECR 	20H, 0H 		//04C3 	1320
		IORWR 	21H, 0H 		//04C4 	1421
		BTSS 	3H, 2H 			//04C5 	2D03
		LJUMP 	4D1H 			//04C6 	3CD1

		//;innotech_led.c: 153: {
		//;innotech_led.c: 154: PB7 = 0;;
		BCR 	DH, 7H 			//04C7 	238D

		//;innotech_led.c: 155: PC1 = 1;;
		BSR 	EH, 1H 			//04C8 	248E
		RET 					//04C9 	1008

		//;innotech_led.c: 157: else if (led_cnt == 150)
		//;innotech_led.c: 156: }
		//;innotech_led.c: 167: if (led_cnt == 1)
		DECR 	20H, 0H 		//04CA 	1320
		IORWR 	21H, 0H 		//04CB 	1421
		BTSS 	3H, 2H 			//04CC 	2D03
		LJUMP 	4D1H 			//04CD 	3CD1

		//;innotech_led.c: 168: {
		//;innotech_led.c: 169: PB7 = 0;;
		BCR 	DH, 7H 			//04CE 	238D

		//;innotech_led.c: 170: PC1 = 0;;
		BCR 	EH, 1H 			//04CF 	208E

		//;innotech_led.c: 171: }
		RET 					//04D0 	1008

		//;innotech_led.c: 172: else if (led_cnt == 150)
		LDWI 	96H 			//04D1 	0096
		XORWR 	20H, 0H 		//04D2 	1620
		IORWR 	21H, 0H 		//04D3 	1421
		LJUMP 	4BCH 			//04D4 	3CBC

		//;innotech_led.c: 183: if (led_cnt % 50 == 26)
		LCALL 	628H 			//04D5 	3628
		MOVLP 	4H 			//04D6 	0184
		LCALL 	503H 			//04D7 	3503
		MOVLP 	4H 			//04D8 	0184
		LDWI 	1AH 			//04D9 	001A
		XORWR 	50H, 0H 		//04DA 	1650
		IORWR 	51H, 0H 		//04DB 	1451
		BTSC 	3H, 2H 			//04DC 	2903
		LJUMP 	4C7H 			//04DD 	3CC7

		//;innotech_led.c: 188: else if (led_cnt % 50 == 1)
		LCALL 	628H 			//04DE 	3628
		MOVLP 	4H 			//04DF 	0184
		LCALL 	503H 			//04E0 	3503
		MOVLP 	4H 			//04E1 	0184
		DECR 	50H, 0H 		//04E2 	1350
		IORWR 	51H, 0H 		//04E3 	1451
		BTSS 	3H, 2H 			//04E4 	2D03
		RET 					//04E5 	1008

		//;innotech_led.c: 189: {
		//;innotech_led.c: 190: PB7 = 1;;
		BSR 	DH, 7H 			//04E6 	278D

		//;innotech_led.c: 191: PC1 = 0;;
		BCR 	EH, 1H 			//04E7 	208E
		RET 					//04E8 	1008

		//;innotech_led.c: 198: if (relay_temp != PowerFlag)
		LDR 	64H, 0H 			//04E9 	1864
		XORWR 	79H, 0H 		//04EA 	1679
		BTSC 	3H, 2H 			//04EB 	2903
		RET 					//04EC 	1008

		//;innotech_led.c: 199: {
		//;innotech_led.c: 200: relay_temp = PowerFlag;
		LDR 	79H, 0H 			//04ED 	1879
		STR 	64H 			//04EE 	10E4
		RET 					//04EF 	1008
		LCALL 	523H 			//04F0 	3523
		MOVLP 	4H 			//04F1 	0184
		XORWI 	1H 			//04F2 	0A01
		BTSC 	3H, 2H 			//04F3 	2903
		LJUMP 	4A2H 			//04F4 	3CA2
		XORWI 	3H 			//04F5 	0A03
		BTSC 	3H, 2H 			//04F6 	2903
		LJUMP 	4C3H 			//04F7 	3CC3
		XORWI 	1H 			//04F8 	0A01
		BTSC 	3H, 2H 			//04F9 	2903
		LJUMP 	4CAH 			//04FA 	3CCA
		XORWI 	7H 			//04FB 	0A07
		BTSC 	3H, 2H 			//04FC 	2903
		LJUMP 	4D5H 			//04FD 	3CD5
		XORWI 	1H 			//04FE 	0A01
		BTSC 	3H, 2H 			//04FF 	2903
		LJUMP 	4E9H 			//0500 	3CE9
		LJUMP 	502H 			//0501 	3D02
		RET 					//0502 	1008
		LDR 	50H, 0H 			//0503 	1850
		IORWR 	51H, 0H 		//0504 	1451
		BTSC 	3H, 2H 			//0505 	2903
		LJUMP 	51EH 			//0506 	3D1E
		CLRF 	54H 			//0507 	11D4
		INCR 	54H, 1H 		//0508 	1AD4
		BTSC 	51H, 7H 		//0509 	2BD1
		LJUMP 	50EH 			//050A 	3D0E
		LSLF 	50H, 1H 		//050B 	05D0
		RLR 	51H, 1H 			//050C 	1DD1
		LJUMP 	508H 			//050D 	3D08
		LDR 	51H, 0H 			//050E 	1851
		SUBWR 	53H, 0H 		//050F 	1253
		BTSS 	3H, 2H 			//0510 	2D03
		LJUMP 	514H 			//0511 	3D14
		LDR 	50H, 0H 			//0512 	1850
		SUBWR 	52H, 0H 		//0513 	1252
		BTSS 	3H, 0H 			//0514 	2C03
		LJUMP 	51AH 			//0515 	3D1A
		LDR 	50H, 0H 			//0516 	1850
		SUBWR 	52H, 1H 		//0517 	12D2
		LDR 	51H, 0H 			//0518 	1851
		SUBWFB 	53H, 1H 		//0519 	0BD3
		LSRF 	51H, 1H 		//051A 	06D1
		RRR 	50H, 1H 			//051B 	1CD0
		DECRSZ 	54H, 1H 		//051C 	1BD4
		LJUMP 	50EH 			//051D 	3D0E
		LDR 	53H, 0H 			//051E 	1853
		STR 	51H 			//051F 	10D1
		LDR 	52H, 0H 			//0520 	1852
		STR 	50H 			//0521 	10D0
		RET 					//0522 	1008

		//;innotech_led.c: 85: if(wifi_state != innotech_network_state_get())
		LCALL 	55EH 			//0523 	355E
		MOVLP 	4H 			//0524 	0184
		XORWR 	27H, 0H 		//0525 	1627
		BTSC 	3H, 2H 			//0526 	2903
		LJUMP 	53CH 			//0527 	3D3C

		//;innotech_led.c: 86: {
		//;innotech_led.c: 87: wifi_state = innotech_network_state_get();
		LCALL 	55EH 			//0528 	355E
		MOVLP 	4H 			//0529 	0184
		STR 	27H 			//052A 	10A7

		//;innotech_led.c: 89: if (wifi_state == 1)
		DECRSZ 	27H, 0H 		//052B 	1B27
		LJUMP 	530H 			//052C 	3D30

		//;innotech_led.c: 90: {
		//;innotech_led.c: 91: led_state = LED_SETUP_READY;
		CLRF 	28H 			//052D 	11A8
		INCR 	28H, 1H 		//052E 	1AA8

		//;innotech_led.c: 92: }
		LJUMP 	53CH 			//052F 	3D3C

		//;innotech_led.c: 93: else if(wifi_state == 2)
		LDWI 	2H 			//0530 	0002
		XORWR 	27H, 0H 		//0531 	1627
		BTSS 	3H, 2H 			//0532 	2D03
		LJUMP 	536H 			//0533 	3D36

		//;innotech_led.c: 94: {
		//;innotech_led.c: 95: led_state = LED_CONNECT_WIFI;
		LDWI 	2H 			//0534 	0002
		LJUMP 	53BH 			//0535 	3D3B

		//;innotech_led.c: 96: }
		//;innotech_led.c: 97: else if(wifi_state == 3)
		LDWI 	3H 			//0536 	0003
		XORWR 	27H, 0H 		//0537 	1627
		BTSS 	3H, 2H 			//0538 	2D03
		LJUMP 	53CH 			//0539 	3D3C

		//;innotech_led.c: 98: {
		//;innotech_led.c: 99: led_state = LED_COMMISSIONED;
		LDWI 	3H 			//053A 	0003
		STR 	28H 			//053B 	10A8

		//;innotech_led.c: 100: }
		//;innotech_led.c: 101: }
		//;innotech_led.c: 103: if(factory_state == 1)
		DECRSZ 	26H, 0H 		//053C 	1B26
		LJUMP 	540H 			//053D 	3D40

		//;innotech_led.c: 104: {
		//;innotech_led.c: 105: led_state = LED_FACTORY_RESET;
		LDWI 	4H 			//053E 	0004
		STR 	28H 			//053F 	10A8

		//;innotech_led.c: 106: }
		//;innotech_led.c: 108: if (led_play_done == 1 && led_state != LED_RELAY_ONOFF)
		DECRSZ 	2AH, 0H 		//0540 	1B2A
		LJUMP 	548H 			//0541 	3D48
		LDWI 	5H 			//0542 	0005
		XORWR 	28H, 0H 		//0543 	1628
		BTSC 	3H, 2H 			//0544 	2903
		LJUMP 	548H 			//0545 	3D48

		//;innotech_led.c: 109: {
		//;innotech_led.c: 110: led_state = LED_RELAY_ONOFF;
		LDWI 	5H 			//0546 	0005
		STR 	28H 			//0547 	10A8

		//;innotech_led.c: 111: }
		//;innotech_led.c: 113: if (last_led_state != led_state)
		LDR 	29H, 0H 			//0548 	1829
		XORWR 	28H, 0H 		//0549 	1628
		BTSC 	3H, 2H 			//054A 	2903
		LJUMP 	552H 			//054B 	3D52

		//;innotech_led.c: 114: {
		//;innotech_led.c: 115: last_led_state = led_state;
		LDR 	28H, 0H 			//054C 	1828
		STR 	29H 			//054D 	10A9

		//;innotech_led.c: 116: led_play_done = 0;
		CLRF 	2AH 			//054E 	11AA

		//;innotech_led.c: 117: led_cnt = 0;
		CLRF 	20H 			//054F 	11A0
		CLRF 	21H 			//0550 	11A1

		//;innotech_led.c: 118: }
		LJUMP 	55CH 			//0551 	3D5C

		//;innotech_led.c: 119: else if (led_cnt < 45000)
		LDWI 	AFH 			//0552 	00AF
		SUBWR 	21H, 0H 		//0553 	1221
		LDWI 	C8H 			//0554 	00C8
		BTSC 	3H, 2H 			//0555 	2903
		SUBWR 	20H, 0H 		//0556 	1220
		BTSC 	3H, 0H 			//0557 	2803
		LJUMP 	55CH 			//0558 	3D5C

		//;innotech_led.c: 120: {
		//;innotech_led.c: 121: led_cnt++;
		INCR 	20H, 1H 		//0559 	1AA0
		BTSC 	3H, 2H 			//055A 	2903
		INCR 	21H, 1H 		//055B 	1AA1

		//;innotech_led.c: 122: }
		//;innotech_led.c: 124: return led_state;
		LDR 	28H, 0H 			//055C 	1828
		RET 					//055D 	1008

		//;innotech_led.c: 56: return ConnectState;
		LDR 	38H, 0H 			//055E 	1838
		RET 					//055F 	1008

		//;Key.c: 321: switch(KeyState4)
		LJUMP 	5A0H 			//0560 	3DA0

		//;Key.c: 322: {
		//;Key.c: 323: case 0:
		//;Key.c: 324: if(PB1==0)
		BTSC 	DH, 1H 			//0561 	288D
		LJUMP 	56FH 			//0562 	3D6F

		//;Key.c: 325: {
		//;Key.c: 326: if(++KeyNumer4 >= 3)
		LCALL 	638H 			//0563 	3638
		MOVLP 	4H 			//0564 	0184
		LDWI 	3H 			//0565 	0003
		BTSC 	3H, 2H 			//0566 	2903
		SUBWR 	22H, 0H 		//0567 	1222
		BTSS 	3H, 0H 			//0568 	2C03
		RETW 	0H 			//0569 	0400

		//;Key.c: 327: {
		//;Key.c: 328: KeyNumer4 = 0;
		CLRF 	22H 			//056A 	11A2
		CLRF 	23H 			//056B 	11A3

		//;Key.c: 329: KeyState4 = 1;
		CLRF 	31H 			//056C 	11B1
		INCR 	31H, 1H 		//056D 	1AB1
		RETW 	0H 			//056E 	0400

		//;Key.c: 332: else
		//;Key.c: 333: KeyNumer4 = 0;
		CLRF 	22H 			//056F 	11A2
		CLRF 	23H 			//0570 	11A3
		RETW 	0H 			//0571 	0400

		//;Key.c: 335: case 1:
		//;Key.c: 336: if(PB1)
		BTSS 	DH, 1H 			//0572 	2C8D
		LJUMP 	577H 			//0573 	3D77
		LDWI 	CH 			//0574 	000C

		//;Key.c: 337: {
		//;Key.c: 338: KeyState4 = 0;
		CLRF 	31H 			//0575 	11B1

		//;Key.c: 339: return 12;
		RET 					//0576 	1008

		//;Key.c: 340: }
		//;Key.c: 341: if(++KeyNumer4 >= 100)
		LCALL 	638H 			//0577 	3638
		MOVLP 	4H 			//0578 	0184
		LDWI 	64H 			//0579 	0064
		BTSC 	3H, 2H 			//057A 	2903
		SUBWR 	22H, 0H 		//057B 	1222
		BTSS 	3H, 0H 			//057C 	2C03
		RETW 	0H 			//057D 	0400
		LDWI 	2H 			//057E 	0002

		//;Key.c: 342: {
		//;Key.c: 343: KeyNumer4 = 0;
		CLRF 	22H 			//057F 	11A2
		CLRF 	23H 			//0580 	11A3

		//;Key.c: 344: KeyState4 = 2;
		STR 	31H 			//0581 	10B1
		RETW 	0H 			//0582 	0400

		//;Key.c: 348: if(++KeyNumer4 >= 900)
		INCR 	22H, 1H 		//0583 	1AA2
		BTSC 	3H, 2H 			//0584 	2903
		INCR 	23H, 1H 		//0585 	1AA3
		LDWI 	3H 			//0586 	0003
		SUBWR 	23H, 0H 		//0587 	1223
		LDWI 	84H 			//0588 	0084
		BTSC 	3H, 2H 			//0589 	2903
		SUBWR 	22H, 0H 		//058A 	1222
		BTSS 	3H, 0H 			//058B 	2C03
		LJUMP 	592H 			//058C 	3D92
		LDWI 	3H 			//058D 	0003

		//;Key.c: 349: {
		//;Key.c: 350: KeyNumer4 = 0;
		CLRF 	22H 			//058E 	11A2
		CLRF 	23H 			//058F 	11A3

		//;Key.c: 351: KeyState4 = 3;
		STR 	31H 			//0590 	10B1

		//;Key.c: 352: return 13;
		RETW 	DH 			//0591 	040D

		//;Key.c: 353: }
		//;Key.c: 355: if(PB1)
		BTSS 	DH, 1H 			//0592 	2C8D
		RETW 	0H 			//0593 	0400

		//;Key.c: 356: {
		//;Key.c: 357: KeyState4 = 0;
		CLRF 	31H 			//0594 	11B1
		RETW 	0H 			//0595 	0400

		//;Key.c: 360: case 3:
		//;Key.c: 362: if(PB1)
		BTSS 	DH, 1H 			//0596 	2C8D
		RETW 	0H 			//0597 	0400
		LDWI 	55H 			//0598 	0055

		//;Key.c: 363: {
		//;Key.c: 364: KeyState4 = 0;
		CLRF 	31H 			//0599 	11B1

		//;Key.c: 366: UartTxBuf[0] = 0x55;
		//;Key.c: 367: UartTxBuf[1] = 0xaa;
		//;Key.c: 368: UartTxBuf[2] = 0x03;
		//;Key.c: 369: UartTxBuf[3] = 0x0;
		LCALL 	630H 			//059A 	3630
		MOVLP 	4H 			//059B 	0184

		//;Key.c: 370: UartSendData();
		LCALL 	60AH 			//059C 	360A
		MOVLP 	4H 			//059D 	0184

		//;Key.c: 372: innotech_network_state_reset();
		LCALL 	61FH 			//059E 	361F
		RETW 	0H 			//059F 	0400
		LDR 	31H, 0H 			//05A0 	1831
		XORWI 	0H 			//05A1 	0A00
		BTSC 	3H, 2H 			//05A2 	2903
		LJUMP 	561H 			//05A3 	3D61
		XORWI 	1H 			//05A4 	0A01
		BTSC 	3H, 2H 			//05A5 	2903
		LJUMP 	572H 			//05A6 	3D72
		XORWI 	3H 			//05A7 	0A03
		BTSC 	3H, 2H 			//05A8 	2903
		LJUMP 	583H 			//05A9 	3D83
		XORWI 	1H 			//05AA 	0A01
		BTSC 	3H, 2H 			//05AB 	2903
		LJUMP 	596H 			//05AC 	3D96
		LJUMP 	5AEH 			//05AD 	3DAE

		//;Key.c: 378: return 0;
		RETW 	0H 			//05AE 	0400

		//;Key.c: 241: static unsigned char key1_state = 0;
		//;Key.c: 242: static unsigned short int key1_count = 0;
		//;Key.c: 244: const static unsigned char Time_sensitivity = 30;
		//;Key.c: 245: const static unsigned short int Time_long = 300;
		//;Key.c: 246: const static unsigned short int Time_vlong = 1000;
		//;Key.c: 248: unsigned char key_value = 0;
		CLRF 	51H 			//05AF 	11D1

		//;Key.c: 250: if(PD3 == 0)
		BTSC 	FH, 3H 			//05B0 	298F
		LJUMP 	5D5H 			//05B1 	3DD5

		//;Key.c: 251: {
		//;Key.c: 252: if (key1_state == 0)
		LDR 	32H, 0H 			//05B2 	1832
		BTSS 	3H, 2H 			//05B3 	2D03
		LJUMP 	5B8H 			//05B4 	3DB8

		//;Key.c: 253: {
		//;Key.c: 254: key1_state = 1;
		CLRF 	32H 			//05B5 	11B2
		INCR 	32H, 1H 		//05B6 	1AB2

		//;Key.c: 255: }
		LJUMP 	5F5H 			//05B7 	3DF5

		//;Key.c: 256: else if ((key1_state == 2) && (key1_count < Time_sensitivity))
		LDWI 	2H 			//05B8 	0002
		XORWR 	32H, 0H 		//05B9 	1632
		BTSS 	3H, 2H 			//05BA 	2D03
		LJUMP 	5C5H 			//05BB 	3DC5
		LDWI 	0H 			//05BC 	0000
		SUBWR 	25H, 0H 		//05BD 	1225
		LDWI 	1EH 			//05BE 	001E
		BTSC 	3H, 2H 			//05BF 	2903
		SUBWR 	24H, 0H 		//05C0 	1224
		BTSC 	3H, 0H 			//05C1 	2803
		LJUMP 	5C5H 			//05C2 	3DC5

		//;Key.c: 257: {
		//;Key.c: 258: key1_state = 3;
		LDWI 	3H 			//05C3 	0003
		LJUMP 	5D8H 			//05C4 	3DD8

		//;Key.c: 259: }
		//;Key.c: 260: else if((key1_state == 1) && (key1_count > Time_vlong))
		DECRSZ 	32H, 0H 		//05C5 	1B32
		LJUMP 	5F5H 			//05C6 	3DF5
		LDWI 	3H 			//05C7 	0003
		SUBWR 	25H, 0H 		//05C8 	1225
		LDWI 	E9H 			//05C9 	00E9
		BTSC 	3H, 2H 			//05CA 	2903
		SUBWR 	24H, 0H 		//05CB 	1224
		BTSS 	3H, 0H 			//05CC 	2C03
		LJUMP 	5F5H 			//05CD 	3DF5
		LDWI 	5H 			//05CE 	0005

		//;Key.c: 261: {
		//;Key.c: 262: key1_count = 0;
		CLRF 	24H 			//05CF 	11A4
		CLRF 	25H 			//05D0 	11A5

		//;Key.c: 263: key1_state = 5;
		STR 	32H 			//05D1 	10B2

		//;Key.c: 264: key_value = 11;
		LDWI 	BH 			//05D2 	000B
		STR 	51H 			//05D3 	10D1

		//;Key.c: 265: }
		//;Key.c: 266: }
		LJUMP 	5F5H 			//05D4 	3DF5

		//;Key.c: 267: else
		//;Key.c: 268: {
		//;Key.c: 269: if (key1_state == 1)
		DECRSZ 	32H, 0H 		//05D5 	1B32
		LJUMP 	5DAH 			//05D6 	3DDA

		//;Key.c: 270: {
		//;Key.c: 271: key1_state = 2;
		LDWI 	2H 			//05D7 	0002
		STR 	32H 			//05D8 	10B2

		//;Key.c: 272: }
		LJUMP 	5F5H 			//05D9 	3DF5

		//;Key.c: 273: else if (key1_state == 3)
		LDWI 	3H 			//05DA 	0003
		XORWR 	32H, 0H 		//05DB 	1632
		BTSS 	3H, 2H 			//05DC 	2D03
		LJUMP 	5E6H 			//05DD 	3DE6

		//;Key.c: 274: {
		//;Key.c: 275: key1_state = 4;
		LDWI 	4H 			//05DE 	0004
		STR 	32H 			//05DF 	10B2
		LDWI 	EH 			//05E0 	000E

		//;Key.c: 276: key1_count = 0;
		CLRF 	24H 			//05E1 	11A4
		CLRF 	25H 			//05E2 	11A5

		//;Key.c: 278: {
		//;Key.c: 279: key_value = 14;
		//;Key.c: 277: if (key1_count < Time_sensitivity)
		//;Key.c: 280: key1_state = 0;
		//;Key.c: 281: key1_count = 0;
		LCALL 	63EH 			//05E3 	363E
		MOVLP 	4H 			//05E4 	0184
		LJUMP 	5F5H 			//05E5 	3DF5

		//;Key.c: 284: else if (key1_state == 5)
		LDWI 	5H 			//05E6 	0005
		XORWR 	32H, 0H 		//05E7 	1632
		BTSS 	3H, 2H 			//05E8 	2D03
		LJUMP 	5F5H 			//05E9 	3DF5
		LDWI 	55H 			//05EA 	0055

		//;Key.c: 285: {
		//;Key.c: 286: key_value = 0;
		CLRF 	51H 			//05EB 	11D1

		//;Key.c: 287: key1_state = 0;
		CLRF 	32H 			//05EC 	11B2

		//;Key.c: 288: key1_count = 0;
		CLRF 	24H 			//05ED 	11A4
		CLRF 	25H 			//05EE 	11A5

		//;Key.c: 290: UartTxBuf[0] = 0x55;
		//;Key.c: 291: UartTxBuf[1] = 0xaa;
		//;Key.c: 292: UartTxBuf[2] = 0x03;
		//;Key.c: 293: UartTxBuf[3] = 0x0;
		LCALL 	630H 			//05EF 	3630
		MOVLP 	4H 			//05F0 	0184

		//;Key.c: 294: UartSendData();
		LCALL 	60AH 			//05F1 	360A
		MOVLP 	4H 			//05F2 	0184

		//;Key.c: 296: innotech_network_state_reset();
		LCALL 	61FH 			//05F3 	361F
		MOVLP 	4H 			//05F4 	0184

		//;Key.c: 297: }
		//;Key.c: 298: }
		//;Key.c: 300: if (key1_state)
		LDR 	32H, 0H 			//05F5 	1832
		BTSC 	3H, 2H 			//05F6 	2903
		LJUMP 	5FBH 			//05F7 	3DFB

		//;Key.c: 301: {
		//;Key.c: 302: key1_count++;
		INCR 	24H, 1H 		//05F8 	1AA4
		BTSC 	3H, 2H 			//05F9 	2903
		INCR 	25H, 1H 		//05FA 	1AA5

		//;Key.c: 303: }
		//;Key.c: 305: if ((key1_state == 2) && (key1_count > Time_sensitivity))
		LDWI 	2H 			//05FB 	0002
		XORWR 	32H, 0H 		//05FC 	1632
		BTSS 	3H, 2H 			//05FD 	2D03
		LJUMP 	608H 			//05FE 	3E08
		LDWI 	0H 			//05FF 	0000
		SUBWR 	25H, 0H 		//0600 	1225
		LDWI 	1FH 			//0601 	001F
		BTSC 	3H, 2H 			//0602 	2903
		SUBWR 	24H, 0H 		//0603 	1224
		BTSS 	3H, 0H 			//0604 	2C03
		LJUMP 	608H 			//0605 	3E08

		//;Key.c: 306: {
		//;Key.c: 307: key_value = 10;
		LDWI 	AH 			//0606 	000A

		//;Key.c: 308: key1_state = 0;
		//;Key.c: 309: key1_count = 0;
		LCALL 	63EH 			//0607 	363E

		//;Key.c: 310: }
		//;Key.c: 312: return key_value;
		LDR 	51H, 0H 			//0608 	1851
		RET 					//0609 	1008

		//;public.c: 945: unsigned char i;
		//;public.c: 947: for(i=0;i<4;i++)
		MOVLB 	0H 			//060A 	1020
		CLRF 	50H 			//060B 	11D0

		//;public.c: 948: {
		//;public.c: 949: URDATAL = UartTxBuf[i];
		LDR 	50H, 0H 			//060C 	1850
		ADDWI 	A0H 			//060D 	0EA0
		STR 	6H 			//060E 	1086
		CLRF 	7H 			//060F 	1187
		LDR 	1H, 0H 			//0610 	1801
		MOVLB 	9H 			//0611 	1029
		STR 	CH 			//0612 	108C

		//;public.c: 950: while(!TXEF) __nop();
		MOVLB 	9H 			//0613 	1029
		BTSC 	12H, 5H 		//0614 	2A92
		LJUMP 	618H 			//0615 	3E18
		NOP 					//0616 	1000
		LJUMP 	613H 			//0617 	3E13
		MOVLB 	0H 			//0618 	1020
		LDWI 	4H 			//0619 	0004
		INCR 	50H, 1H 		//061A 	1AD0
		SUBWR 	50H, 0H 		//061B 	1250
		BTSC 	3H, 0H 			//061C 	2803
		RET 					//061D 	1008
		LJUMP 	60CH 			//061E 	3E0C

		//;innotech_led.c: 71: PB7 = 1;;
		BSR 	DH, 7H 			//061F 	278D

		//;innotech_led.c: 72: PC1 = 1;;
		BSR 	EH, 1H 			//0620 	248E

		//;innotech_led.c: 73: PB6 = 1;;
		BSR 	DH, 6H 			//0621 	270D

		//;innotech_led.c: 75: wifi_state = 0;
		CLRF 	27H 			//0622 	11A7

		//;innotech_led.c: 76: led_state = LED_INITIAL;
		CLRF 	28H 			//0623 	11A8

		//;innotech_led.c: 77: last_led_state = 0;
		CLRF 	29H 			//0624 	11A9

		//;innotech_led.c: 78: ConnectState = 0;
		CLRF 	38H 			//0625 	11B8

		//;innotech_led.c: 79: factory_state = 0;
		CLRF 	26H 			//0626 	11A6
		RET 					//0627 	1008
		LDWI 	32H 			//0628 	0032
		STR 	50H 			//0629 	10D0
		CLRF 	51H 			//062A 	11D1
		LDR 	21H, 0H 			//062B 	1821
		STR 	53H 			//062C 	10D3
		LDR 	20H, 0H 			//062D 	1820
		STR 	52H 			//062E 	10D2
		RET 					//062F 	1008
		MOVLB 	1H 			//0630 	1021
		STR 	20H 			//0631 	10A0
		LDWI 	AAH 			//0632 	00AA
		STR 	21H 			//0633 	10A1
		LDWI 	3H 			//0634 	0003
		STR 	22H 			//0635 	10A2
		CLRF 	23H 			//0636 	11A3
		RET 					//0637 	1008
		INCR 	22H, 1H 		//0638 	1AA2
		BTSC 	3H, 2H 			//0639 	2903
		INCR 	23H, 1H 		//063A 	1AA3
		LDWI 	0H 			//063B 	0000
		SUBWR 	23H, 0H 		//063C 	1223
		RET 					//063D 	1008
		STR 	51H 			//063E 	10D1
		CLRF 	32H 			//063F 	11B2
		CLRF 	24H 			//0640 	11A4
		CLRF 	25H 			//0641 	11A5
		RET 					//0642 	1008

		//;Dim.c: 360: if(DimPercentData > 100)
		LDWI 	65H 			//0643 	0065
		SUBWR 	6DH, 0H 		//0644 	126D
		BTSS 	3H, 0H 			//0645 	2C03
		LJUMP 	649H 			//0646 	3E49

		//;Dim.c: 361: DimPercentData = 100;
		LDWI 	64H 			//0647 	0064
		STR 	6DH 			//0648 	10ED

		//;Dim.c: 364: if(PowerFlag)
		LDR 	79H, 0H 			//0649 	1879
		BTSC 	3H, 2H 			//064A 	2903
		LJUMP 	651H 			//064B 	3E51

		//;Dim.c: 365: {
		//;Dim.c: 366: BufDimPercentData = DimPercentData;
		LDR 	6DH, 0H 			//064C 	186D
		STR 	6BH 			//064D 	10EB

		//;Dim.c: 367: FadeFlag = 1;
		CLRF 	4FH 			//064E 	11CF
		INCR 	4FH, 1H 		//064F 	1ACF

		//;Dim.c: 368: }
		LJUMP 	653H 			//0650 	3E53

		//;Dim.c: 369: else
		//;Dim.c: 370: {
		//;Dim.c: 371: BufDimPercentData = 1;
		CLRF 	6BH 			//0651 	11EB
		INCR 	6BH, 1H 		//0652 	1AEB

		//;Dim.c: 377: if(TempDimPercentData < BufDimPercentData) TempDimPercentData ++;
		LDR 	6BH, 0H 			//0653 	186B
		SUBWR 	7AH, 0H 		//0654 	127A
		BTSC 	3H, 0H 			//0655 	2803
		LJUMP 	659H 			//0656 	3E59
		INCR 	7AH, 1H 		//0657 	1AFA
		LJUMP 	65DH 			//0658 	3E5D

		//;Dim.c: 378: else if(TempDimPercentData > BufDimPercentData) TempDimPercentData --;
		LDR 	7AH, 0H 			//0659 	187A
		SUBWR 	6BH, 0H 		//065A 	126B
		BTSS 	3H, 0H 			//065B 	2C03
		DECR 	7AH, 1H 		//065C 	13FA

		//;Dim.c: 381: if(TempDimPercentData <= 1)
		LDWI 	2H 			//065D 	0002
		SUBWR 	7AH, 0H 		//065E 	127A
		BTSC 	3H, 0H 			//065F 	2803
		LJUMP 	667H 			//0660 	3E67

		//;Dim.c: 382: {
		//;Dim.c: 383: FadeFlag = 0;
		CLRF 	4FH 			//0661 	11CF

		//;Dim.c: 384: if(1 == KeyPowerOffFlag)
		DECRSZ 	3EH, 0H 		//0662 	1B3E
		LJUMP 	667H 			//0663 	3E67

		//;Dim.c: 385: {
		//;Dim.c: 386: PA0 ^= 1;;
		LDWI 	1H 			//0664 	0001
		XORWR 	CH, 1H 		//0665 	168C

		//;Dim.c: 387: KeyPowerOffFlag = 0;
		CLRF 	3EH 			//0666 	11BE

		//;Dim.c: 388: }
		//;Dim.c: 389: }
		//;Dim.c: 391: if((TempDimPercentData > 0)&&(TempDimPercentData <= 100))
		LDR 	7AH, 0H 			//0667 	187A
		BTSC 	3H, 2H 			//0668 	2903
		LJUMP 	671H 			//0669 	3E71
		LDWI 	65H 			//066A 	0065
		SUBWR 	7AH, 0H 		//066B 	127A
		BTSC 	3H, 0H 			//066C 	2803
		LJUMP 	671H 			//066D 	3E71

		//;Dim.c: 392: DimPercentDataOppose = 100 - TempDimPercentData;
		LDR 	7AH, 0H 			//066E 	187A
		SUBWI 	64H 			//066F 	0C64
		STR 	46H 			//0670 	10C6

		//;Dim.c: 393: }
		//;Dim.c: 396: if((PowerFlag)||(FadeFlag))
		LDR 	79H, 0H 			//0671 	1879
		BTSC 	3H, 2H 			//0672 	2903
		LDR 	4FH, 0H 			//0673 	184F
		BTSC 	3H, 2H 			//0674 	2903
		LJUMP 	6B9H 			//0675 	3EB9

		//;Dim.c: 397: {
		//;Dim.c: 398: if(TempDimPercentData <= 5) LedNum = 1;
		LDWI 	6H 			//0676 	0006
		SUBWR 	7AH, 0H 		//0677 	127A
		BTSC 	3H, 0H 			//0678 	2803
		LJUMP 	694H 			//0679 	3E94
		CLRF 	2FH 			//067A 	11AF
		INCR 	2FH, 1H 		//067B 	1AAF
		LDR 	2FH, 0H 			//067C 	182F
		XORWI 	1H 			//067D 	0A01
		BTSC 	3H, 2H 			//067E 	2903
		LJUMP 	6BBH 			//067F 	3EBB
		XORWI 	3H 			//0680 	0A03
		BTSC 	3H, 2H 			//0681 	2903
		LJUMP 	6BEH 			//0682 	3EBE
		XORWI 	1H 			//0683 	0A01
		BTSC 	3H, 2H 			//0684 	2903
		LJUMP 	6C1H 			//0685 	3EC1
		XORWI 	7H 			//0686 	0A07
		BTSC 	3H, 2H 			//0687 	2903
		LJUMP 	6C6H 			//0688 	3EC6
		XORWI 	1H 			//0689 	0A01
		BTSC 	3H, 2H 			//068A 	2903
		LJUMP 	6CBH 			//068B 	3ECB
		XORWI 	3H 			//068C 	0A03
		BTSC 	3H, 2H 			//068D 	2903
		LJUMP 	6CFH 			//068E 	3ECF
		XORWI 	1H 			//068F 	0A01
		BTSC 	3H, 2H 			//0690 	2903
		LJUMP 	6D3H 			//0691 	3ED3
		LJUMP 	6D7H 			//0692 	3ED7
		RET 					//0693 	1008

		//;Dim.c: 399: else if(TempDimPercentData <= 20) LedNum = 2;
		LDWI 	15H 			//0694 	0015
		SUBWR 	7AH, 0H 		//0695 	127A
		BTSC 	3H, 0H 			//0696 	2803
		LJUMP 	69AH 			//0697 	3E9A
		LDWI 	2H 			//0698 	0002
		LJUMP 	6B7H 			//0699 	3EB7

		//;Dim.c: 400: else if(TempDimPercentData <= 35) LedNum = 3;
		LDWI 	24H 			//069A 	0024
		SUBWR 	7AH, 0H 		//069B 	127A
		BTSC 	3H, 0H 			//069C 	2803
		LJUMP 	6A0H 			//069D 	3EA0
		LDWI 	3H 			//069E 	0003
		LJUMP 	6B7H 			//069F 	3EB7

		//;Dim.c: 401: else if(TempDimPercentData <= 50) LedNum = 4;
		LDWI 	33H 			//06A0 	0033
		SUBWR 	7AH, 0H 		//06A1 	127A
		BTSC 	3H, 0H 			//06A2 	2803
		LJUMP 	6A6H 			//06A3 	3EA6
		LDWI 	4H 			//06A4 	0004
		LJUMP 	6B7H 			//06A5 	3EB7

		//;Dim.c: 402: else if(TempDimPercentData <= 65) LedNum = 5;
		LDWI 	42H 			//06A6 	0042
		SUBWR 	7AH, 0H 		//06A7 	127A
		BTSC 	3H, 0H 			//06A8 	2803
		LJUMP 	6ACH 			//06A9 	3EAC
		LDWI 	5H 			//06AA 	0005
		LJUMP 	6B7H 			//06AB 	3EB7

		//;Dim.c: 403: else if(TempDimPercentData <= 80) LedNum = 6;
		LDWI 	51H 			//06AC 	0051
		SUBWR 	7AH, 0H 		//06AD 	127A
		BTSC 	3H, 0H 			//06AE 	2803
		LJUMP 	6B2H 			//06AF 	3EB2
		LDWI 	6H 			//06B0 	0006
		LJUMP 	6B7H 			//06B1 	3EB7

		//;Dim.c: 404: else if(TempDimPercentData <= 100) LedNum = 7;
		LDWI 	65H 			//06B2 	0065
		SUBWR 	7AH, 0H 		//06B3 	127A
		BTSC 	3H, 0H 			//06B4 	2803
		LJUMP 	67CH 			//06B5 	3E7C
		LDWI 	7H 			//06B6 	0007
		STR 	2FH 			//06B7 	10AF
		LJUMP 	67CH 			//06B8 	3E7C

		//;Dim.c: 409: LedNum = 0;
		CLRF 	2FH 			//06B9 	11AF
		LJUMP 	67CH 			//06BA 	3E7C

		//;Dim.c: 412: {
		//;Dim.c: 413: case 1:
		//;Dim.c: 414: PB5 = 0;;PB4 = 1;;PB3 = 1;;PB2 = 1;;PC4 = 1;;PC5 = 1;;PC6 = 1;;
		BCR 	DH, 5H 			//06BB 	228D
		BSR 	DH, 4H 			//06BC 	260D

		//;Dim.c: 415: break;
		LJUMP 	6DAH 			//06BD 	3EDA

		//;Dim.c: 416: case 2:
		//;Dim.c: 417: PB5 = 0;;PB4 = 0;;PB3 = 1;;PB2 = 1;;PC4 = 1;;PC5 = 1;;PC6 = 1;;
		BCR 	DH, 5H 			//06BE 	228D
		BCR 	DH, 4H 			//06BF 	220D

		//;Dim.c: 418: break;
		LJUMP 	6DAH 			//06C0 	3EDA

		//;Dim.c: 419: case 3:
		//;Dim.c: 420: PB5 = 0;;PB4 = 0;;PB3 = 0;;PB2 = 1;;PC4 = 1;;PC5 = 1;;PC6 = 1;;
		BCR 	DH, 5H 			//06C1 	228D
		BCR 	DH, 4H 			//06C2 	220D
		BCR 	DH, 3H 			//06C3 	218D
		BSR 	DH, 2H 			//06C4 	250D

		//;Dim.c: 421: break;
		LJUMP 	6E6H 			//06C5 	3EE6

		//;Dim.c: 422: case 4:
		//;Dim.c: 423: PB5 = 0;;PB4 = 0;;PB3 = 0;;PB2 = 0;;PC4 = 1;;PC5 = 1;;PC6 = 1;;
		BCR 	DH, 5H 			//06C6 	228D
		BCR 	DH, 4H 			//06C7 	220D
		BCR 	DH, 3H 			//06C8 	218D
		BCR 	DH, 2H 			//06C9 	210D

		//;Dim.c: 424: break;
		LJUMP 	6E6H 			//06CA 	3EE6

		//;Dim.c: 425: case 5:
		//;Dim.c: 426: PB5 = 0;;PB4 = 0;;PB3 = 0;;PB2 = 0;;PC4 = 0;;PC5 = 1;;PC6 = 1;;
		LCALL 	6E0H 			//06CB 	36E0
		BSR 	EH, 5H 			//06CC 	268E
		BSR 	EH, 6H 			//06CD 	270E

		//;Dim.c: 427: break;
		RET 					//06CE 	1008

		//;Dim.c: 428: case 6:
		//;Dim.c: 429: PB5 = 0;;PB4 = 0;;PB3 = 0;;PB2 = 0;;PC4 = 0;;PC5 = 0;;PC6 = 1;;
		LCALL 	6E0H 			//06CF 	36E0
		BCR 	EH, 5H 			//06D0 	228E
		BSR 	EH, 6H 			//06D1 	270E

		//;Dim.c: 430: break;
		RET 					//06D2 	1008

		//;Dim.c: 431: case 7:
		//;Dim.c: 432: PB5 = 0;;PB4 = 0;;PB3 = 0;;PB2 = 0;;PC4 = 0;;PC5 = 0;;PC6 = 0;;
		LCALL 	6E0H 			//06D3 	36E0
		BCR 	EH, 5H 			//06D4 	228E
		BCR 	EH, 6H 			//06D5 	230E

		//;Dim.c: 433: break;
		RET 					//06D6 	1008

		//;Dim.c: 434: default:
		//;Dim.c: 435: PB5 = 1;;PB4 = 1;;PB3 = 1;;PB2 = 1;;PC4 = 1;;PC5 = 1;;PC6 = 1;;
		BSR 	DH, 5H 			//06D7 	268D
		BSR 	DH, 4H 			//06D8 	260D

		//;Dim.c: 436: break;
		LJUMP 	6DAH 			//06D9 	3EDA
		BSR 	DH, 3H 			//06DA 	258D
		BSR 	DH, 2H 			//06DB 	250D
		BSR 	EH, 4H 			//06DC 	260E
		BSR 	EH, 5H 			//06DD 	268E
		BSR 	EH, 6H 			//06DE 	270E
		RET 					//06DF 	1008
		BCR 	DH, 5H 			//06E0 	228D
		BCR 	DH, 4H 			//06E1 	220D
		BCR 	DH, 3H 			//06E2 	218D
		BCR 	DH, 2H 			//06E3 	210D
		BCR 	EH, 4H 			//06E4 	220E
		RET 					//06E5 	1008
		BSR 	EH, 4H 			//06E6 	260E
		BSR 	EH, 5H 			//06E7 	268E
		BSR 	EH, 6H 			//06E8 	270E
		RET 					//06E9 	1008

		//;Dim.c: 461: u16 i;
		//;Dim.c: 462: if(DimPercentData > 100)
		LDWI 	65H 			//06EA 	0065
		MOVLB 	0H 			//06EB 	1020
		SUBWR 	6DH, 0H 		//06EC 	126D
		BTSS 	3H, 0H 			//06ED 	2C03
		LJUMP 	6F1H 			//06EE 	3EF1

		//;Dim.c: 463: DimPercentData = 100;
		LDWI 	64H 			//06EF 	0064
		STR 	6DH 			//06F0 	10ED

		//;Dim.c: 465: pBuffer[0] = 0xaa;
		LDR 	74H, 0H 			//06F1 	1874
		STR 	6H 			//06F2 	1086
		LDWI 	AAH 			//06F3 	00AA
		CLRF 	7H 			//06F4 	1187
		STR 	1H 			//06F5 	1081

		//;Dim.c: 466: pBuffer[1] = PowerFlag;
		INCR 	74H, 0H 		//06F6 	1A74
		STR 	6H 			//06F7 	1086
		LDR 	79H, 0H 			//06F8 	1879
		STR 	1H 			//06F9 	1081

		//;Dim.c: 467: pBuffer[2] = DimPercentData;
		LDR 	74H, 0H 			//06FA 	1874
		ADDWI 	2H 			//06FB 	0E02
		STR 	6H 			//06FC 	1086
		LDR 	6DH, 0H 			//06FD 	186D
		STR 	1H 			//06FE 	1081

		//;Dim.c: 468: pBuffer[3] = DimPercentMin;
		LDR 	74H, 0H 			//06FF 	1874
		ADDWI 	3H 			//0700 	0E03
		STR 	6H 			//0701 	1086
		LDR 	67H, 0H 			//0702 	1867
		STR 	1H 			//0703 	1081

		//;Dim.c: 469: pBuffer[4] = DimMin;
		LDR 	74H, 0H 			//0704 	1874
		ADDWI 	4H 			//0705 	0E04
		STR 	6H 			//0706 	1086
		LDR 	65H, 0H 			//0707 	1865
		STR 	1H 			//0708 	1081

		//;Dim.c: 470: pBuffer[5] = PowerLedFlag;
		LDR 	74H, 0H 			//0709 	1874
		ADDWI 	5H 			//070A 	0E05
		STR 	6H 			//070B 	1086
		LDR 	6AH, 0H 			//070C 	186A
		STR 	1H 			//070D 	1081

		//;Dim.c: 471: pBuffer[6] = 0xff;
		LDR 	74H, 0H 			//070E 	1874
		ADDWI 	6H 			//070F 	0E06
		STR 	6H 			//0710 	1086
		LDWI 	FFH 			//0711 	00FF
		STR 	1H 			//0712 	1081

		//;Dim.c: 472: pBuffer[7] = 0xff;
		LDR 	74H, 0H 			//0713 	1874
		ADDWI 	7H 			//0714 	0E07
		STR 	6H 			//0715 	1086
		LDWI 	FFH 			//0716 	00FF
		STR 	1H 			//0717 	1081

		//;Dim.c: 473: pBuffer[8] = 0xff;
		LDR 	74H, 0H 			//0718 	1874
		ADDWI 	8H 			//0719 	0E08
		STR 	6H 			//071A 	1086
		LDWI 	FFH 			//071B 	00FF
		STR 	1H 			//071C 	1081

		//;Dim.c: 474: pBuffer[9] = 0xff;
		LDR 	74H, 0H 			//071D 	1874
		ADDWI 	9H 			//071E 	0E09
		STR 	6H 			//071F 	1086
		LDWI 	FFH 			//0720 	00FF
		STR 	1H 			//0721 	1081

		//;Dim.c: 485: for(i=0; i<6; i++)
		CLRF 	76H 			//0722 	11F6
		CLRF 	77H 			//0723 	11F7

		//;Dim.c: 486: {
		//;Dim.c: 487: EEPROMwrite(i,pBuffer[i]);
		LDR 	76H, 0H 			//0724 	1876
		ADDWR 	74H, 0H 		//0725 	1774
		STR 	75H 			//0726 	10F5
		STR 	6H 			//0727 	1086
		CLRF 	7H 			//0728 	1187
		LDR 	1H, 0H 			//0729 	1801
		STR 	70H 			//072A 	10F0
		LDR 	76H, 0H 			//072B 	1876
		LCALL 	739H 			//072C 	3739
		MOVLP 	6H 			//072D 	0186
		INCR 	76H, 1H 		//072E 	1AF6
		BTSC 	3H, 2H 			//072F 	2903
		INCR 	77H, 1H 		//0730 	1AF7
		LDWI 	0H 			//0731 	0000
		SUBWR 	77H, 0H 		//0732 	1277
		LDWI 	6H 			//0733 	0006
		BTSC 	3H, 2H 			//0734 	2903
		SUBWR 	76H, 0H 		//0735 	1276
		BTSC 	3H, 0H 			//0736 	2803
		RET 					//0737 	1008
		LJUMP 	724H 			//0738 	3F24
		STR 	71H 			//0739 	10F1

		//;public.c: 1288: while(GIE)
		BTSS 	BH, 7H 			//073A 	2F8B
		LJUMP 	73EH 			//073B 	3F3E

		//;public.c: 1289: {GIE = 0; }
		BCR 	BH, 7H 			//073C 	238B
		LJUMP 	73AH 			//073D 	3F3A

		//;public.c: 1290: EEADRL = EEAddr;
		LDR 	71H, 0H 			//073E 	1871
		MOVLB 	3H 			//073F 	1023
		STR 	11H 			//0740 	1091

		//;public.c: 1291: EEDATL = Data;
		LDR 	70H, 0H 			//0741 	1870
		STR 	13H 			//0742 	1093

		//;public.c: 1293: CFGS =0;
		BCR 	15H, 6H 			//0743 	2315

		//;public.c: 1294: EEPGD=0;
		BCR 	15H, 7H 			//0744 	2395

		//;public.c: 1296: WREN=1;
		BSR 	15H, 2H 			//0745 	2515

		//;public.c: 1298: EEIF = 0;
		BCR 	BH, 2H 			//0746 	210B

		//;public.c: 1299: EECON2=0x55;
		LDWI 	55H 			//0747 	0055
		STR 	16H 			//0748 	1096

		//;public.c: 1300: EECON2=0xAA;
		LDWI 	AAH 			//0749 	00AA
		STR 	16H 			//074A 	1096

		//;public.c: 1302: WR = 1;
		BSR 	15H, 1H 			//074B 	2495

		//;public.c: 1303: __nop();
		NOP 					//074C 	1000

		//;public.c: 1304: __nop();
		NOP 					//074D 	1000

		//;public.c: 1305: __nop();
		NOP 					//074E 	1000

		//;public.c: 1306: __nop();
		NOP 					//074F 	1000

		//;public.c: 1307: while(WR);
		MOVLB 	3H 			//0750 	1023
		BTSC 	15H, 1H 		//0751 	2895
		LJUMP 	750H 			//0752 	3F50

		//;public.c: 1308: WREN = 0;
		BCR 	15H, 2H 			//0753 	2115

		//;public.c: 1309: GIE = 1;
		BSR 	BH, 7H 			//0754 	278B
		RET 					//0755 	1008

		//;public.c: 990: if(ReceiveFinishFlag == 0)
		LDR 	40H, 0H 			//0756 	1840
		BTSC 	3H, 2H 			//0757 	2903
		RET 					//0758 	1008

		//;public.c: 996: UartRecvData1 = UartRxBuf[1];
		//;public.c: 991: return;
		CLRF 	40H 			//0759 	11C0

		//;public.c: 997: UartRecvData2 = UartRxBuf[2];
		MOVLB 	1H 			//075A 	1021
		LDR 	2CH, 0H 			//075B 	182C
		MOVLB 	0H 			//075C 	1020
		STR 	3AH 			//075D 	10BA

		//;public.c: 998: UartRecvData3 = UartRxBuf[3];
		MOVLB 	1H 			//075E 	1021
		LDR 	2DH, 0H 			//075F 	182D
		MOVLB 	0H 			//0760 	1020
		STR 	39H 			//0761 	10B9

		//;public.c: 1000: switch(UartRecvData2)
		LJUMP 	795H 			//0762 	3F95

		//;public.c: 1011: {
		//;public.c: 1014: if(UartRecvData3 == 1)
		DECRSZ 	39H, 0H 		//0763 	1B39
		LJUMP 	770H 			//0764 	3F70

		//;public.c: 1015: {
		//;public.c: 1016: if(PowerFlag == 0)
		LDR 	79H, 0H 			//0765 	1879
		BTSS 	3H, 2H 			//0766 	2D03
		RET 					//0767 	1008

		//;public.c: 1017: {
		//;public.c: 1018: PowerFlag = 1;
		//;public.c: 1019: mcu_dp_value_update(0x01,PowerFlag);
		MOVLP 	4H 			//0768 	0184
		LCALL 	487H 			//0769 	3487
		MOVLP 	7H 			//076A 	0187
		MOVLP 	3H 			//076B 	0183
		LCALL 	30EH 			//076C 	330E

		//;public.c: 1020: PA0 ^= 1;;
		LDWI 	1H 			//076D 	0001
		XORWR 	CH, 1H 		//076E 	168C
		RET 					//076F 	1008

		//;public.c: 1023: else if(UartRecvData3 == 0)
		LDR 	39H, 0H 			//0770 	1839
		BTSC 	3H, 2H 			//0771 	2903

		//;public.c: 1024: {
		//;public.c: 1025: if(PowerFlag == 1)
		DECRSZ 	79H, 0H 		//0772 	1B79
		RET 					//0773 	1008

		//;public.c: 1026: {
		//;public.c: 1027: PowerFlag = 0;
		//;public.c: 1029: mcu_dp_value_update(0x01,PowerFlag);
		MOVLP 	4H 			//0774 	0184
		LCALL 	48CH 			//0775 	348C
		MOVLP 	7H 			//0776 	0187
		MOVLP 	3H 			//0777 	0183
		LCALL 	30EH 			//0778 	330E

		//;public.c: 1030: KeyPowerOffFlag = 1;
		CLRF 	3EH 			//0779 	11BE
		INCR 	3EH, 1H 		//077A 	1ABE
		RET 					//077B 	1008

		//;public.c: 1042: if(DimPercentData == UartRecvData3)
		LDR 	6DH, 0H 			//077C 	186D
		XORWR 	39H, 0H 		//077D 	1639
		BTSC 	3H, 2H 			//077E 	2903
		RET 					//077F 	1008

		//;public.c: 1045: else
		//;public.c: 1046: {
		//;public.c: 1048: DimPercentData = UartRecvData3;
		LDR 	39H, 0H 			//0780 	1839
		STR 	6DH 			//0781 	10ED
		RET 					//0782 	1008

		//;public.c: 1055: {
		//;public.c: 1057: ConnectState = UartRecvData3;
		LDR 	39H, 0H 			//0783 	1839
		STR 	38H 			//0784 	10B8

		//;public.c: 1058: break;
		RET 					//0785 	1008

		//;public.c: 1061: {
		//;public.c: 1066: if((UartRecvData3 >= 1) && (UartRecvData3 <= 100))
		LDR 	39H, 0H 			//0786 	1839
		BTSC 	3H, 2H 			//0787 	2903
		RET 					//0788 	1008
		LDWI 	65H 			//0789 	0065
		SUBWR 	39H, 0H 		//078A 	1239
		BTSC 	3H, 0H 			//078B 	2803
		RET 					//078C 	1008

		//;public.c: 1067: {
		//;public.c: 1068: DimPercentData = UartRecvData3;
		LDR 	39H, 0H 			//078D 	1839
		STR 	6DH 			//078E 	10ED

		//;public.c: 1069: MsgSendFlag = 1;
		CLRF 	3DH 			//078F 	11BD
		INCR 	3DH, 1H 		//0790 	1ABD
		RET 					//0791 	1008

		//;public.c: 1075: {
		//;public.c: 1076: PB7 ^= 1;;
		LDWI 	80H 			//0792 	0080
		XORWR 	DH, 1H 		//0793 	168D

		//;public.c: 1077: break;
		RET 					//0794 	1008
		LDR 	3AH, 0H 			//0795 	183A
		XORWI 	1H 			//0796 	0A01
		BTSC 	3H, 2H 			//0797 	2903
		LJUMP 	763H 			//0798 	3F63
		XORWI 	3H 			//0799 	0A03
		BTSC 	3H, 2H 			//079A 	2903
		LJUMP 	77CH 			//079B 	3F7C
		XORWI 	6H 			//079C 	0A06
		BTSC 	3H, 2H 			//079D 	2903
		LJUMP 	783H 			//079E 	3F83
		XORWI 	1H 			//079F 	0A01
		BTSC 	3H, 2H 			//07A0 	2903
		LJUMP 	786H 			//07A1 	3F86
		XORWI 	3H 			//07A2 	0A03
		BTSC 	3H, 2H 			//07A3 	2903
		LJUMP 	792H 			//07A4 	3F92
		LJUMP 	7A6H 			//07A5 	3FA6
		RET 					//07A6 	1008

		//;Dim.c: 785: if(DimPercentMinPre != DimPercentMin)
		LDR 	66H, 0H 			//07A7 	1866
		XORWR 	67H, 0H 		//07A8 	1667
		BTSC 	3H, 2H 			//07A9 	2903
		LJUMP 	7B0H 			//07AA 	3FB0

		//;Dim.c: 786: {
		//;Dim.c: 787: DimPercentMinPre = DimPercentMin;
		LDR 	67H, 0H 			//07AB 	1867
		STR 	66H 			//07AC 	10E6

		//;Dim.c: 788: AngleMin = (100 - DimPercentMin)+ 42;
		LDR 	67H, 0H 			//07AD 	1867
		SUBWI 	8EH 			//07AE 	0C8E
		STR 	6EH 			//07AF 	10EE

		//;Dim.c: 789: }
		//;Dim.c: 792: if((KeyPowerOnVal == 11) || (KeyPowerOffVal == 13))
		LDWI 	BH 			//07B0 	000B
		XORWR 	48H, 0H 		//07B1 	1648
		BTSC 	3H, 2H 			//07B2 	2903
		LJUMP 	7B8H 			//07B3 	3FB8
		LDWI 	DH 			//07B4 	000D
		XORWR 	47H, 0H 		//07B5 	1647
		BTSS 	3H, 2H 			//07B6 	2D03
		LJUMP 	7C4H 			//07B7 	3FC4

		//;Dim.c: 799: Min3State = 0;
		LDWI 	1H 			//07B8 	0001
		LCALL 	7E0H 			//07B9 	37E0
		MOVLP 	7H 			//07BA 	0187
		LDWI 	64H 			//07BB 	0064

		//;Dim.c: 801: DimPower5sFlag = 1;
		CLRF 	6AH 			//07BC 	11EA
		INCR 	6AH, 1H 		//07BD 	1AEA

		//;Dim.c: 803: RecLearnFlag = 0;
		CLRF 	2CH 			//07BE 	11AC

		//;Dim.c: 805: DimPercentData = 100;
		STR 	6DH 			//07BF 	10ED

		//;Dim.c: 806: DimPercentMin = 1;
		CLRF 	67H 			//07C0 	11E7
		INCR 	67H, 1H 		//07C1 	1AE7

		//;Dim.c: 810: Dim1SendPercentDataFlag = 1;
		CLRF 	65H 			//07C2 	11E5
		INCR 	65H, 1H 		//07C3 	1AE5

		//;Dim.c: 811: }
		//;Dim.c: 813: if(++DimPercentDataNumer >= 25)
		LDWI 	19H 			//07C4 	0019
		INCR 	2BH, 1H 		//07C5 	1AAB
		SUBWR 	2BH, 0H 		//07C6 	122B
		BTSS 	3H, 0H 			//07C7 	2C03
		RET 					//07C8 	1008

		//;Dim.c: 814: {
		//;Dim.c: 823: DimPercentDataNumer = 0;
		CLRF 	2BH 			//07C9 	11AB

		//;Dim.c: 825: if(MsgSendFlag == 1)
		DECRSZ 	3DH, 0H 		//07CA 	1B3D
		LJUMP 	7D2H 			//07CB 	3FD2

		//;Dim.c: 826: {
		//;Dim.c: 827: MsgSendFlag = 0;
		CLRF 	3DH 			//07CC 	11BD

		//;Dim.c: 828: mcu_dp_value_update(0x02,DimPercentData);
		LDR 	6DH, 0H 			//07CD 	186D
		STR 	51H 			//07CE 	10D1
		LDWI 	2H 			//07CF 	0002
		MOVLP 	3H 			//07D0 	0183
		LJUMP 	30EH 			//07D1 	3B0E

		//;Dim.c: 829: }
		//;Dim.c: 830: else
		//;Dim.c: 831: {
		//;Dim.c: 832: if((DimPercentDataPre1 != DimPercentData) && ((PD1) && (PD2)))
		LDR 	68H, 0H 			//07D2 	1868
		XORWR 	6DH, 0H 		//07D3 	166D
		BTSS 	3H, 2H 			//07D4 	2D03
		BTSS 	FH, 1H 			//07D5 	2C8F
		RET 					//07D6 	1008
		BTSS 	FH, 2H 			//07D7 	2D0F
		RET 					//07D8 	1008

		//;Dim.c: 833: {
		//;Dim.c: 834: DimPercentDataPre1 = DimPercentData;
		LDR 	6DH, 0H 			//07D9 	186D
		STR 	68H 			//07DA 	10E8

		//;Dim.c: 836: mcu_dp_value_update(0x02,DimPercentData);
		LDR 	6DH, 0H 			//07DB 	186D
		STR 	51H 			//07DC 	10D1
		LDWI 	2H 			//07DD 	0002
		MOVLP 	3H 			//07DE 	0183
		LJUMP 	30EH 			//07DF 	3B0E
		STR 	50H 			//07E0 	10D0

		//;innotech_led.c: 47: if(factory_state != state)
		XORWR 	26H, 0H 		//07E1 	1626
		BTSC 	3H, 2H 			//07E2 	2903
		RET 					//07E3 	1008

		//;innotech_led.c: 48: {
		//;innotech_led.c: 49: factory_state = state;
		LDR 	50H, 0H 			//07E4 	1850
		STR 	26H 			//07E5 	10A6
		RET 					//07E6 	1008

		//;public.c: 212: PCKEN |=0B00000010;
		MOVLB 	1H 			//07E7 	1021
		BSR 	1AH, 1H 			//07E8 	249A

		//;public.c: 213: CKOCON=0B00100000;
		LDWI 	20H 			//07E9 	0020
		STR 	15H 			//07EA 	1095

		//;public.c: 214: TCKSRC=0B00000001;
		LDWI 	1H 			//07EB 	0001
		MOVLB 	6H 			//07EC 	1026
		STR 	1FH 			//07ED 	109F

		//;public.c: 239: TIM1CR1 =0B10000101;
		LDWI 	85H 			//07EE 	0085
		MOVLB 	4H 			//07EF 	1024
		STR 	11H 			//07F0 	1091

		//;public.c: 352: TIM1IER =0B00000001;
		LDWI 	1H 			//07F1 	0001
		STR 	15H 			//07F2 	1095

		//;public.c: 525: TIM1PSCRH = 0;
		MOVLB 	5H 			//07F3 	1025
		CLRF 	EH 			//07F4 	118E

		//;public.c: 526: TIM1PSCRL = 15;
		LDWI 	FH 			//07F5 	000F
		STR 	FH 			//07F6 	108F

		//;public.c: 528: TIM1ARRH =0x03;
		LDWI 	3H 			//07F7 	0003
		STR 	10H 			//07F8 	1090

		//;public.c: 529: TIM1ARRL =0xe8;
		LDWI 	E8H 			//07F9 	00E8
		STR 	11H 			//07FA 	1091

		//;public.c: 535: GIE=1;
		BSR 	BH, 7H 			//07FB 	278B
		RET 					//07FC 	1008
		ORG		0800H
		MOVLP 	2H 			//0800 	0182
		LJUMP 	23EH 			//0801 	3A3E
		MOVLP 	2H 			//0802 	0182
		LJUMP 	23EH 			//0803 	3A3E
		MOVLP 	2H 			//0804 	0182
		LJUMP 	23EH 			//0805 	3A3E
		MOVLP 	2H 			//0806 	0182
		LJUMP 	23EH 			//0807 	3A3E
		MOVLP 	2H 			//0808 	0182
		LJUMP 	23EH 			//0809 	3A3E
		MOVLP 	2H 			//080A 	0182
		LJUMP 	23EH 			//080B 	3A3E
		MOVLP 	2H 			//080C 	0182
		LJUMP 	23EH 			//080D 	3A3E
		MOVLP 	2H 			//080E 	0182
		LJUMP 	23EH 			//080F 	3A3E
		MOVLP 	2H 			//0810 	0182
		LJUMP 	23EH 			//0811 	3A3E
		MOVLP 	2H 			//0812 	0182
		LJUMP 	23EH 			//0813 	3A3E
		MOVLP 	2H 			//0814 	0182
		LJUMP 	24CH 			//0815 	3A4C
		MOVLP 	4H 			//0816 	0184
		LJUMP 	40DH 			//0817 	3C0D
		MOVLP 	4H 			//0818 	0184
		LJUMP 	420H 			//0819 	3C20
		MOVLP 	4H 			//081A 	0184
		LJUMP 	42CH 			//081B 	3C2C
		MOVLP 	4H 			//081C 	0184
		LJUMP 	438H 			//081D 	3C38
		MOVLP 	4H 			//081E 	0184
		LJUMP 	43BH 			//081F 	3C3B
		MOVLP 	4H 			//0820 	0184
		LJUMP 	449H 			//0821 	3C49
		MOVLP 	4H 			//0822 	0184
		LJUMP 	454H 			//0823 	3C54
		ORG		0EB4H
		CLRWDT 			//0EB4 	1064
		CLRF 	0H 			//0EB5 	1180
		ADDFSR 	0H, 1H 		//0EB6 	0101
		DECRSZ 	9H, 1H 		//0EB7 	1B89
		LJUMP 	6B5H 			//0EB8 	3EB5
		RETW 	0H 			//0EB9 	0400
		CLRWDT 			//0EBA 	1064

		//;public.c: 896: MISC0 = 0B00000000;
		MOVLB 	2H 			//0EBB 	1022
		CLRF 	1CH 			//0EBC 	119C

		//;public.c: 898: WDTCON = 0B00010101;
		LDWI 	15H 			//0EBD 	0015
		MOVLB 	1H 			//0EBE 	1021
		STR 	17H 			//0EBF 	1097
		RET 					//0EC0 	1008

		//;public.c: 1315: TIM2CR1 &= ~(0x1);
		MOVLB 	6H 			//0EC1 	1026
		BCR 	CH, 0H 			//0EC2 	200C

		//;public.c: 1316: TIM2ARRH = (Period >> 8) & 0xFF;
		LDR 	71H, 0H 			//0EC3 	1871
		STR 	19H 			//0EC4 	1099

		//;public.c: 1317: TIM2ARRL = Period & 0xFF;
		LDR 	70H, 0H 			//0EC5 	1870
		STR 	1AH 			//0EC6 	109A

		//;public.c: 1320: TIM2CNTRH = 0;
		CLRF 	16H 			//0EC7 	1196

		//;public.c: 1321: TIM2CNTRL = 0;
		CLRF 	17H 			//0EC8 	1197

		//;public.c: 1323: T2UIF = 1;
		BSR 	EH, 0H 			//0EC9 	240E

		//;public.c: 1325: if(NewState)
		LDR 	72H, 0H 			//0ECA 	1872
		BTSC 	3H, 2H 			//0ECB 	2903
		LJUMP 	6CFH 			//0ECC 	3ECF

		//;public.c: 1326: TIM2CR1 |= 0x1;
		BSR 	CH, 0H 			//0ECD 	240C
		RET 					//0ECE 	1008

		//;public.c: 1327: else
		//;public.c: 1328: TIM2CR1 &= ~(0x1);
		BCR 	CH, 0H 			//0ECF 	200C
		RET 					//0ED0 	1008

		//;public.c: 866: PCKEN |=0B00100000;
		MOVLB 	1H 			//0ED1 	1021
		BSR 	1AH, 5H 			//0ED2 	269A

		//;public.c: 867: TRISA7=1;
		BSR 	CH, 7H 			//0ED3 	278C

		//;public.c: 868: TRISA6=0;
		BCR 	CH, 6H 			//0ED4 	230C

		//;public.c: 870: URIER =0B00000001;
		LDWI 	1H 			//0ED5 	0001
		MOVLB 	9H 			//0ED6 	1029
		STR 	EH 			//0ED7 	108E

		//;public.c: 871: URLCR =0B00000001;
		STR 	FH 			//0ED8 	108F

		//;public.c: 872: URMCR =0B00011000;
		LDWI 	18H 			//0ED9 	0018
		STR 	11H 			//0EDA 	1091

		//;public.c: 874: URDLL =52;
		LDWI 	34H 			//0EDB 	0034
		STR 	14H 			//0EDC 	1094

		//;public.c: 877: URDLH =0;
		CLRF 	15H 			//0EDD 	1195

		//;public.c: 878: TCF=1;
		BSR 	1CH, 0H 			//0EDE 	241C

		//;public.c: 879: INTCON=0B11000000;
		LDWI 	C0H 			//0EDF 	00C0
		STR 	BH 			//0EE0 	108B

		//;public.c: 880: UROD=1;
		MOVLB 	4H 			//0EE1 	1024
		BSR 	1FH, 0H 			//0EE2 	241F
		RET 					//0EE3 	1008
		CLRF 	54H 			//0EE4 	11D4
		CLRF 	55H 			//0EE5 	11D5
		BTSS 	50H, 0H 		//0EE6 	2C50
		LJUMP 	6ECH 			//0EE7 	3EEC
		LDR 	52H, 0H 			//0EE8 	1852
		ADDWR 	54H, 1H 		//0EE9 	17D4
		LDR 	53H, 0H 			//0EEA 	1853
		ADDWFC 	55H, 1H 		//0EEB 	0DD5
		LSLF 	52H, 1H 		//0EEC 	05D2
		RLR 	53H, 1H 			//0EED 	1DD3
		LSRF 	51H, 1H 		//0EEE 	06D1
		RRR 	50H, 1H 			//0EEF 	1CD0
		LDR 	50H, 0H 			//0EF0 	1850
		IORWR 	51H, 0H 		//0EF1 	1451
		BTSS 	3H, 2H 			//0EF2 	2D03
		LJUMP 	6E6H 			//0EF3 	3EE6
		LDR 	55H, 0H 			//0EF4 	1855
		STR 	51H 			//0EF5 	10D1
		LDR 	54H, 0H 			//0EF6 	1854
		STR 	50H 			//0EF7 	10D0
		RET 					//0EF8 	1008

		//;public.c: 1361: LoadDetCnt++;
		MOVLB 	1H 			//0EF9 	1021
		INCR 	36H, 1H 		//0EFA 	1AB6
		BTSC 	3H, 2H 			//0EFB 	2903
		INCR 	37H, 1H 		//0EFC 	1AB7

		//;public.c: 1362: if(LoadDetCnt <= 200)
		LDWI 	0H 			//0EFD 	0000
		SUBWR 	37H, 0H 		//0EFE 	1237
		LDWI 	C9H 			//0EFF 	00C9
		BTSC 	3H, 2H 			//0F00 	2903
		SUBWR 	36H, 0H 		//0F01 	1236
		BTSS 	3H, 0H 			//0F02 	2C03
		RET 					//0F03 	1008

		//;public.c: 1365: else
		//;public.c: 1366: {
		//;public.c: 1367: LoadDetCnt = 0;
		CLRF 	36H 			//0F04 	11B6
		CLRF 	37H 			//0F05 	11B7

		//;public.c: 1368: if(sample_data_load > 0)
		LDR 	46H, 0H 			//0F06 	1846
		IORWR 	47H, 0H 		//0F07 	1447
		BTSC 	3H, 2H 			//0F08 	2903
		LJUMP 	70EH 			//0F09 	3F0E

		//;public.c: 1369: {
		//;public.c: 1370: travell_flag_load = 1;
		MOVLB 	0H 			//0F0A 	1020
		CLRF 	35H 			//0F0B 	11B5
		INCR 	35H, 1H 		//0F0C 	1AB5

		//;public.c: 1371: }
		LJUMP 	710H 			//0F0D 	3F10

		//;public.c: 1372: else
		//;public.c: 1373: {
		//;public.c: 1374: travell_flag_load = 0;
		MOVLB 	0H 			//0F0E 	1020
		CLRF 	35H 			//0F0F 	11B5

		//;public.c: 1375: }
		//;public.c: 1377: sample_data_load = 0;
		MOVLB 	1H 			//0F10 	1021
		CLRF 	46H 			//0F11 	11C6
		CLRF 	47H 			//0F12 	11C7
		RET 					//0F13 	1008
		STR 	55H 			//0F14 	10D5

		//;public.c: 1234: ADCON0 &= 0B00001111;
		LDWI 	FH 			//0F15 	000F
		MOVLB 	1H 			//0F16 	1021
		ANDWR 	1DH, 1H 		//0F17 	159D

		//;public.c: 1235: ADCON0 |= adcChannel<<4;
		MOVLB 	0H 			//0F18 	1020
		SWAPR 	55H, 0H 		//0F19 	1E55
		ANDWI 	F0H 			//0F1A 	09F0
		MOVLB 	1H 			//0F1B 	1021
		IORWR 	1DH, 1H 		//0F1C 	149D

		//;public.c: 1236: DelayUs(40);
		LDWI 	28H 			//0F1D 	0028
		MOVLP 	3H 			//0F1E 	0183
		LCALL 	34DH 			//0F1F 	334D
		MOVLP 	FH 			//0F20 	018F

		//;public.c: 1237: GO = 1;
		MOVLB 	1H 			//0F21 	1021
		BSR 	1DH, 1H 			//0F22 	249D

		//;public.c: 1238: __nop();
		NOP 					//0F23 	1000

		//;public.c: 1239: __nop();
		NOP 					//0F24 	1000

		//;public.c: 1240: while(GO);
		MOVLB 	1H 			//0F25 	1021
		BTSC 	1DH, 1H 		//0F26 	289D
		LJUMP 	725H 			//0F27 	3F25

		//;public.c: 1242: return (unsigned int)(ADRESH<<8|ADRESL);
		LDR 	1CH, 0H 			//0F28 	181C
		MOVLB 	0H 			//0F29 	1020
		STR 	53H 			//0F2A 	10D3
		CLRF 	52H 			//0F2B 	11D2
		MOVLB 	1H 			//0F2C 	1021
		LDR 	1BH, 0H 			//0F2D 	181B
		MOVLB 	0H 			//0F2E 	1020
		IORWR 	52H, 1H 		//0F2F 	14D2
		RET 					//0F30 	1008
		CLRF 	5EH 			//0F31 	11DE
		CLRF 	5FH 			//0F32 	11DF
		CLRF 	60H 			//0F33 	11E0
		CLRF 	61H 			//0F34 	11E1
		BTSS 	56H, 0H 		//0F35 	2C56
		LJUMP 	73FH 			//0F36 	3F3F
		LDR 	5AH, 0H 			//0F37 	185A
		ADDWR 	5EH, 1H 		//0F38 	17DE
		LDR 	5BH, 0H 			//0F39 	185B
		ADDWFC 	5FH, 1H 		//0F3A 	0DDF
		LDR 	5CH, 0H 			//0F3B 	185C
		ADDWFC 	60H, 1H 		//0F3C 	0DE0
		LDR 	5DH, 0H 			//0F3D 	185D
		ADDWFC 	61H, 1H 		//0F3E 	0DE1
		LSLF 	5AH, 1H 		//0F3F 	05DA
		RLR 	5BH, 1H 			//0F40 	1DDB
		RLR 	5CH, 1H 			//0F41 	1DDC
		RLR 	5DH, 1H 			//0F42 	1DDD
		LSRF 	59H, 1H 		//0F43 	06D9
		RRR 	58H, 1H 			//0F44 	1CD8
		RRR 	57H, 1H 			//0F45 	1CD7
		RRR 	56H, 1H 			//0F46 	1CD6
		LDR 	59H, 0H 			//0F47 	1859
		IORWR 	58H, 0H 		//0F48 	1458
		IORWR 	57H, 0H 		//0F49 	1457
		IORWR 	56H, 0H 		//0F4A 	1456
		BTSS 	3H, 2H 			//0F4B 	2D03
		LJUMP 	735H 			//0F4C 	3F35
		LDR 	61H, 0H 			//0F4D 	1861
		STR 	59H 			//0F4E 	10D9
		LDR 	60H, 0H 			//0F4F 	1860
		STR 	58H 			//0F50 	10D8
		LDR 	5FH, 0H 			//0F51 	185F
		STR 	57H 			//0F52 	10D7
		LDR 	5EH, 0H 			//0F53 	185E
		STR 	56H 			//0F54 	10D6
		RET 					//0F55 	1008
		STR 	70H 			//0F56 	10F0

		//;public.c: 904: switch(UartRxStep)
		LJUMP 	776H 			//0F57 	3F76

		//;public.c: 907: {
		//;public.c: 908: if(RcvData == 0x55)
		LDWI 	55H 			//0F58 	0055
		XORWR 	70H, 0H 		//0F59 	1670
		BTSS 	3H, 2H 			//0F5A 	2D03
		RET 					//0F5B 	1008

		//;public.c: 909: {
		//;public.c: 910: UartRxBuf[UartRxLen++] = RcvData;
		LCALL 	783H 			//0F5C 	3783
		INCR 	3BH, 1H 		//0F5D 	1ABB

		//;public.c: 911: UartRxStep = 1;
		CLRF 	3CH 			//0F5E 	11BC
		INCR 	3CH, 1H 		//0F5F 	1ABC
		RET 					//0F60 	1008

		//;public.c: 917: {
		//;public.c: 918: if(RcvData == 0xAA)
		LDWI 	AAH 			//0F61 	00AA
		XORWR 	70H, 0H 		//0F62 	1670
		BTSS 	3H, 2H 			//0F63 	2D03
		RET 					//0F64 	1008

		//;public.c: 919: {
		//;public.c: 920: UartRxBuf[UartRxLen++] = RcvData;
		LCALL 	783H 			//0F65 	3783
		LDWI 	2H 			//0F66 	0002
		INCR 	3BH, 1H 		//0F67 	1ABB

		//;public.c: 921: UartRxStep = 2;
		STR 	3CH 			//0F68 	10BC
		RET 					//0F69 	1008

		//;public.c: 927: {
		//;public.c: 928: UartRxBuf[UartRxLen++] = RcvData;
		LCALL 	783H 			//0F6A 	3783
		MOVLP 	FH 			//0F6B 	018F
		LDWI 	4H 			//0F6C 	0004
		INCR 	3BH, 1H 		//0F6D 	1ABB

		//;public.c: 929: if(UartRxLen > 3)
		SUBWR 	3BH, 0H 		//0F6E 	123B
		BTSS 	3H, 0H 			//0F6F 	2C03
		RET 					//0F70 	1008

		//;public.c: 930: {
		//;public.c: 931: UartRxStep = 0;
		CLRF 	3CH 			//0F71 	11BC

		//;public.c: 932: UartRxLen = 0;
		CLRF 	3BH 			//0F72 	11BB

		//;public.c: 933: ReceiveFinishFlag = 1;
		CLRF 	40H 			//0F73 	11C0
		INCR 	40H, 1H 		//0F74 	1AC0
		RET 					//0F75 	1008
		MOVLB 	0H 			//0F76 	1020
		LDR 	3CH, 0H 			//0F77 	183C
		XORWI 	0H 			//0F78 	0A00
		BTSC 	3H, 2H 			//0F79 	2903
		LJUMP 	758H 			//0F7A 	3F58
		XORWI 	1H 			//0F7B 	0A01
		BTSC 	3H, 2H 			//0F7C 	2903
		LJUMP 	761H 			//0F7D 	3F61
		XORWI 	3H 			//0F7E 	0A03
		BTSC 	3H, 2H 			//0F7F 	2903
		LJUMP 	76AH 			//0F80 	3F6A
		LJUMP 	782H 			//0F81 	3F82
		RET 					//0F82 	1008
		LDR 	3BH, 0H 			//0F83 	183B
		ADDWI 	AAH 			//0F84 	0EAA
		STR 	6H 			//0F85 	1086
		CLRF 	7H 			//0F86 	1187
		LDR 	70H, 0H 			//0F87 	1870
		STR 	1H 			//0F88 	1081
		RET 					//0F89 	1008

		//;public.c: 64: OSCCON = 0B01110001;
		LDWI 	71H 			//0F8A 	0071
		MOVLB 	1H 			//0F8B 	1021
		STR 	19H 			//0F8C 	1099

		//;public.c: 69: INTCON = 0B01000000;
		LDWI 	40H 			//0F8D 	0040
		STR 	BH 			//0F8E 	108B

		//;public.c: 71: PORTA = 0B00000000;
		MOVLB 	0H 			//0F8F 	1020
		CLRF 	CH 			//0F90 	118C

		//;public.c: 72: TRISA = 0B10010010;
		LDWI 	92H 			//0F91 	0092
		MOVLB 	1H 			//0F92 	1021
		STR 	CH 			//0F93 	108C

		//;public.c: 73: WPUA = 0B00000000;
		MOVLB 	3H 			//0F94 	1023
		CLRF 	CH 			//0F95 	118C

		//;public.c: 74: WPDA = 0B00000000;
		MOVLB 	4H 			//0F96 	1024
		CLRF 	CH 			//0F97 	118C

		//;public.c: 77: PORTB = 0B11111100;
		LDWI 	FCH 			//0F98 	00FC
		MOVLB 	0H 			//0F99 	1020
		STR 	DH 			//0F9A 	108D

		//;public.c: 78: TRISB = 0B00000010;
		LDWI 	2H 			//0F9B 	0002
		MOVLB 	1H 			//0F9C 	1021
		STR 	DH 			//0F9D 	108D

		//;public.c: 79: WPUB = 0B00000000;
		MOVLB 	3H 			//0F9E 	1023
		CLRF 	DH 			//0F9F 	118D

		//;public.c: 80: WPDB = 0B00000000;
		MOVLB 	4H 			//0FA0 	1024
		CLRF 	DH 			//0FA1 	118D

		//;public.c: 82: PORTC = 0B01110010;
		LDWI 	72H 			//0FA2 	0072
		MOVLB 	0H 			//0FA3 	1020
		STR 	EH 			//0FA4 	108E

		//;public.c: 84: TRISC = 0B00001001;
		LDWI 	9H 			//0FA5 	0009
		MOVLB 	1H 			//0FA6 	1021
		STR 	EH 			//0FA7 	108E

		//;public.c: 85: WPUC = 0B00001000;
		LDWI 	8H 			//0FA8 	0008
		MOVLB 	3H 			//0FA9 	1023
		STR 	EH 			//0FAA 	108E

		//;public.c: 86: WPDC = 0B00000000;
		MOVLB 	4H 			//0FAB 	1024
		CLRF 	EH 			//0FAC 	118E

		//;public.c: 88: PORTD = 0B00000000;
		MOVLB 	0H 			//0FAD 	1020
		CLRF 	FH 			//0FAE 	118F

		//;public.c: 89: TRISD = 0B00001110;
		LDWI 	EH 			//0FAF 	000E
		MOVLB 	1H 			//0FB0 	1021
		STR 	FH 			//0FB1 	108F

		//;public.c: 90: WPUD = 0B00000000;
		MOVLB 	3H 			//0FB2 	1023
		CLRF 	FH 			//0FB3 	118F

		//;public.c: 92: WPDD = 0B00000000;
		MOVLB 	4H 			//0FB4 	1024
		CLRF 	FH 			//0FB5 	118F

		//;public.c: 94: PSRC0 = 0B11111111;
		LDWI 	FFH 			//0FB6 	00FF
		MOVLB 	2H 			//0FB7 	1022
		STR 	1AH 			//0FB8 	109A

		//;public.c: 98: PSRC1 = 0B11111111;
		STR 	1BH 			//0FB9 	109B

		//;public.c: 102: PSINK0 = 0B11111111;
		MOVLB 	3H 			//0FBA 	1023
		STR 	1AH 			//0FBB 	109A

		//;public.c: 103: PSINK1 = 0B11111111;
		STR 	1BH 			//0FBC 	109B

		//;public.c: 104: PSINK2 = 0B11111111;
		STR 	1CH 			//0FBD 	109C

		//;public.c: 105: PSINK3 = 0B11111111;
		STR 	1DH 			//0FBE 	109D

		//;public.c: 107: ANSELA = 0B00000000;
		CLRF 	17H 			//0FBF 	1197
		RET 					//0FC0 	1008
		CLRF 	5DH 			//0FC1 	11DD
		CLRF 	5EH 			//0FC2 	11DE
		CLRF 	5FH 			//0FC3 	11DF
		CLRF 	60H 			//0FC4 	11E0
		LDR 	57H, 0H 			//0FC5 	1857
		IORWR 	56H, 0H 		//0FC6 	1456
		IORWR 	55H, 0H 		//0FC7 	1455
		IORWR 	54H, 0H 		//0FC8 	1454
		BTSC 	3H, 2H 			//0FC9 	2903
		LJUMP 	7F7H 			//0FCA 	3FF7
		CLRF 	5CH 			//0FCB 	11DC
		INCR 	5CH, 1H 		//0FCC 	1ADC
		BTSC 	57H, 7H 		//0FCD 	2BD7
		LJUMP 	7D4H 			//0FCE 	3FD4
		LSLF 	54H, 1H 		//0FCF 	05D4
		RLR 	55H, 1H 			//0FD0 	1DD5
		RLR 	56H, 1H 			//0FD1 	1DD6
		RLR 	57H, 1H 			//0FD2 	1DD7
		LJUMP 	7CCH 			//0FD3 	3FCC
		LSLF 	5DH, 1H 		//0FD4 	05DD
		RLR 	5EH, 1H 			//0FD5 	1DDE
		RLR 	5FH, 1H 			//0FD6 	1DDF
		RLR 	60H, 1H 			//0FD7 	1DE0
		LDR 	57H, 0H 			//0FD8 	1857
		SUBWR 	5BH, 0H 		//0FD9 	125B
		BTSS 	3H, 2H 			//0FDA 	2D03
		LJUMP 	7E6H 			//0FDB 	3FE6
		LDR 	56H, 0H 			//0FDC 	1856
		SUBWR 	5AH, 0H 		//0FDD 	125A
		BTSS 	3H, 2H 			//0FDE 	2D03
		LJUMP 	7E6H 			//0FDF 	3FE6
		LDR 	55H, 0H 			//0FE0 	1855
		SUBWR 	59H, 0H 		//0FE1 	1259
		BTSS 	3H, 2H 			//0FE2 	2D03
		LJUMP 	7E6H 			//0FE3 	3FE6
		LDR 	54H, 0H 			//0FE4 	1854
		SUBWR 	58H, 0H 		//0FE5 	1258
		BTSS 	3H, 0H 			//0FE6 	2C03
		LJUMP 	7F1H 			//0FE7 	3FF1
		LDR 	54H, 0H 			//0FE8 	1854
		SUBWR 	58H, 1H 		//0FE9 	12D8
		LDR 	55H, 0H 			//0FEA 	1855
		SUBWFB 	59H, 1H 		//0FEB 	0BD9
		LDR 	56H, 0H 			//0FEC 	1856
		SUBWFB 	5AH, 1H 		//0FED 	0BDA
		LDR 	57H, 0H 			//0FEE 	1857
		SUBWFB 	5BH, 1H 		//0FEF 	0BDB
		BSR 	5DH, 0H 			//0FF0 	245D
		LSRF 	57H, 1H 		//0FF1 	06D7
		RRR 	56H, 1H 			//0FF2 	1CD6
		RRR 	55H, 1H 			//0FF3 	1CD5
		RRR 	54H, 1H 			//0FF4 	1CD4
		DECRSZ 	5CH, 1H 		//0FF5 	1BDC
		LJUMP 	7D4H 			//0FF6 	3FD4
		LDR 	60H, 0H 			//0FF7 	1860
		STR 	57H 			//0FF8 	10D7
		LDR 	5FH, 0H 			//0FF9 	185F
		STR 	56H 			//0FFA 	10D6
		LDR 	5EH, 0H 			//0FFB 	185E
		STR 	55H 			//0FFC 	10D5
		LDR 	5DH, 0H 			//0FFD 	185D
		STR 	54H 			//0FFE 	10D4
		RET 					//0FFF 	1008
			END
