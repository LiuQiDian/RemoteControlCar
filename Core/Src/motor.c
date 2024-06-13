#include "motor.h"

// 电机初始化
void MOTOR_Init()
{
    HAL_GPIO_WritePin(MOTOR_GPIO_Port, MOTOR_Pin, MOTOR_ON);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}

// 显示电机正常上电的LED显示灯
void LED()
{
    if (HAL_GPIO_ReadPin(MOTOR_GPIO_Port, MOTOR_Pin) == MOTOR_ON)
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, LED_ON);
    else
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, LED_OFF);
}

// 电机停止
void MOTOR_Stop()
{
    HAL_GPIO_WritePin(MOTOR_GPIO_Port, MOTOR_Pin, MOTOR_OFF);
}

// 左电机正转
void MotorLeftForward()
{
    HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_RESET);
}

// 左电机反转
void MotorLeftBackward()
{
    HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_SET);
}

// 右电机正转
void MotorRightForward()
{
    HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_RESET);
}

// 右电机反转
void MotorRightBackward()
{
    HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_SET);
}
