#include "control.h"
#include "motor.h"

uint16_t speed = 0;
int dutycycle = 0;

int SpeedToDutyCycle(uint16_t speed)
{
    dutycycle = speed * 100 / 1000;
    return dutycycle;
}
SpeedToDutyCycle(speed);

// 控制初始化
void CONTROL_Init()
{
    MOTOR_Init();
    LED();
}

// 控制停止
void CONTROL_Stop()
{
    MOTOR_Stop();
    LED();
}

// 控制电机运行
void MOTOR_Run(int dutycycle)
{
}

// 控制电机速度
void MOTOR_SetSpeed(int dutycycle)
{
    // 左电机速度控制
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, dutycycle);
    // 右电机速度控制
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, dutycycle);
}