#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "usart.h"
#define USART1_RX_LEN 200

    extern UART_HandleTypeDef huart1;
    extern uint8_t USART1_RX_BUF[USART1_RX_LEN]; // 串口接收缓冲,最大USART1_RX_LEN个字节.
    extern uint16_t USART1_RX_STA;               // 接收状态标记
    extern uint8_t USART1_NewData;               // 最新接收到的数据

    void BLUETOOTH_Init();
    void BLUETOOTH_Send(uint8_t *data, uint16_t size);
    void BLUETOOTH_Receive(uint8_t *data, uint16_t size);
    void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}

#endif
#endif /*__ BLUETOOTH_H__ */