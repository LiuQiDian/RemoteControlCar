#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "usart.h"

    void BLUETOOTH_Init();
    void BLUETOOTH_Send(uint8_t *data, uint16_t size);
    void BLUETOOTH_Receive(uint8_t *data, uint16_t size);

#ifdef __cplusplus
}

#endif
#endif /*__ BLUETOOTH_H__ */