#ifndef __MOTOR_H__
#define __MOTOR_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "tim.h"

    void MOTOR_Init();
    void MOTOR_Stop();

#ifdef __cplusplus
}

#endif
#endif /*__ MOTOR_H__ */