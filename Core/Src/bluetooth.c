#include "bluetooth.h"

// 蓝牙初始化
void BLUETOOTH_Init()
{
    MX_USART1_UART_Init();
}

// 发送数据
void BLUETOOTH_Send(uint8_t *data, uint16_t size)
{
    HAL_UART_Transmit(&huart1, data, size, 1000);
}

// 接收数据
void BLUETOOTH_Receive(uint8_t *data, uint16_t size)
{
    HAL_UART_Receive(&huart1, data, size, 1000);
}