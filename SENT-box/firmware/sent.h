/*
 * sent.h
 *
 *  Created on: 16 May 2022
 *      Author: alexv
 */

#ifndef SENT_H_
#define SENT_H_

#define SENT_MODE_ICU 1
#define SENT_MODE_PAL 0

#define SENT_MODE SENT_MODE_ICU//SENT_MODE_PAL

#define SENT_SILABS_SENS    0   // Silabs Si7215, tick 5 us
#define SENT_GM_ETB         1   // GM ETB throttle, tick 3.25 us

#define SENT_DEV  SENT_GM_ETB

#if SENT_DEV == SENT_GM_ETB
#define SENT_CHANNELS_NUM 2 // Number of sent channels
#elif SENT_DEV == SENT_SILABS_SENS
#define SENT_CHANNELS_NUM 4 // Number of sent channels
#endif

#define SENT_SYNC_INTERVAL  44 // 56 ticks - 12
#define SENT_OFFSET_INTERVAL 12

#define SENT_MIN_INTERVAL 12
#define SENT_MAX_INTERVAL 15

#define SENT_CRC_SEED 0x05

#define SENT_MSG_PAYLOAD_SIZE 8  // Size of payload

#define SENT_ERR_PERCENT 1

#define SENT_THROTTLE_OPEN_VAL   435     // Sensor position of fully open throttle
#define SENT_THROTTLE_CLOSE_VAL  3665    // Sensor position of fully closed throttle

enum
{
    SENT_CH1 = 0,
    SENT_CH2,
#if SENT_DEV == SENT_SILABS_SENS
    SENT_CH3,
    SENT_CH4,
#endif
};

typedef enum
{
        SM_SENT_INIT_STATE = 0,
        SM_SENT_SYNC_STATE,
        SM_SENT_STATUS_STATE,
        SM_SENT_SIG1_DATA1_STATE,
        SM_SENT_SIG1_DATA2_STATE,
        SM_SENT_SIG1_DATA3_STATE,
        SM_SENT_SIG2_DATA1_STATE,
        SM_SENT_SIG2_DATA2_STATE,
        SM_SENT_SIG2_DATA3_STATE,
        SM_SENT_CRC_STATE,
}SM_SENT_enum;

void InitSent();

void SENT_ISR_Handler(uint8_t ch, uint16_t val_res);

uint16_t SENT_GetData(uint8_t ch);
uint32_t SENT_GetRollErrCnt(void);
uint32_t SENT_GetCrcErrCnt(void);
uint32_t SENT_GetMinIntervalErrCnt(void);
uint32_t SENT_GetMaxIntervalErrCnt(void);
uint32_t SENT_GetSyncErrCnt(void);
uint32_t SENT_GetSyncCnt(void);

uint8_t SENT_IsRawData(void);
uint16_t SENT_GetOpenThrottleVal(void);
uint16_t SENT_GetClosedThrottleVal(void);
uint32_t SENT_GetIntervalErr(void);
void SENT_GetRawData(uint8_t * buf);
void SENT_SetRawDataProp(void);
void SENT_ResetRawDataProp(void);
uint8_t SENT_GetThrottleValPrec(void);

#endif /* SENT_H_ */
