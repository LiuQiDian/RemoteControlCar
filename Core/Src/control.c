#include "control.h"
#include "motor.h"

uint16_t speed = 0;
int dutycycle = 0;
int AIN1 = 0, AIN2 = 0, BIN1 = 0, BIN2 = 0;

int SpeedToDutyCycle(uint16_t speed)
{
    // 此处的系数需要根据实际情况调整
    dutycycle = speed * 100;
    return dutycycle;
}
SpeedToDutyCycle(speed);

// 控制初始化
void CONTROL_Init()
{
    MOTOR_Init();
    LED();
    HAL_Delay(1000);
    MOTOR_Run(dutycycle);
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
    while (1)
    {
        MOTOR_SetSpeed(dutycycle);
        HAL_Delay(10);

        // 前进
        if (AIN1 == 1 && AIN2 == 0 && BIN1 == 1 && BIN2 == 0)
        {
            MotorLeftForward();
            MotorRightForward();
        }

        // 后退
        if (AIN1 == 0 && AIN2 == 1 && BIN1 == 0 && BIN2 == 1)
        {
            MotorLeftBackward();
            MotorRightBackward();
        }

        // 左转
        if (AIN1 == 0 && AIN2 == 1 && BIN1 == 1 && BIN2 == 0)
        {
            MotorLeftBackward();
            MotorRightForward();
        }

        // 右转
        if (AIN1 == 1 && AIN2 == 0 && BIN1 == 0 && BIN2 == 1)
        {
            MotorLeftForward();
            MotorRightBackward();
        }
    }
}

// 控制电机速度
void MOTOR_SetSpeed(int dutycycle)
{
    // 左电机速度控制
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, dutycycle);
    // 右电机速度控制
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, dutycycle);
}