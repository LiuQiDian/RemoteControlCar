#ifndef __CONTROL_H
#define __CONTROL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "motor.h"

    void CONTROL_Init();
    void CONTROL_Stop();
    void MOTOR_Run(int dutycycle);
    void MOTOR_SetSpeed(int dutycycle);

#ifdef __cplusplus
}
#endif
#endif /*__ CONTROL_H */