#include "bluetooth.h"

uint8_t USART1_RX_BUF[USART1_RX_LEN]; // 串口接收缓冲,最大USART1_RX_LEN个字节.
uint16_t USART1_RX_STA = 0;           // 接收状态标记
uint8_t USART1_NeData;                // 最新接收到的数据

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

// 串口接收中断
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        if ((USART1_RX_STA & 0x8000) == 0)
        {
            if (USART1_RX_STA & 0x4000)
            {
                if (USART1_NeData != 0x0a)
                    USART1_RX_STA = 0;
                else
                    USART1_RX_STA |= 0x8000;
            }
            else
            {
                if (USART1_NeData == 0x0d)
                    USART1_RX_STA |= 0x4000;
                else
                {
                    USART1_RX_BUF[USART1_RX_STA & 0X3FFF] = USART1_NeData;
                    USART1_RX_STA++;
                    if (USART1_RX_STA > (USART1_RX_LEN - 1))
                        USART1_RX_STA = 0;
                }
            }
        }
    }
}