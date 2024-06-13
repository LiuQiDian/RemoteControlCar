/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define AIN2_Pin GPIO_PIN_3
#define AIN2_GPIO_Port GPIOA
#define AIN1_Pin GPIO_PIN_4
#define AIN1_GPIO_Port GPIOA
#define MOTOR_Pin GPIO_PIN_5
#define MOTOR_GPIO_Port GPIOA
#define BIN1_Pin GPIO_PIN_6
#define BIN1_GPIO_Port GPIOA
#define BIN2_Pin GPIO_PIN_7
#define BIN2_GPIO_Port GPIOA
#define PWMA_Pin GPIO_PIN_8
#define PWMA_GPIO_Port GPIOA
#define PWMB_Pin GPIO_PIN_11
#define PWMB_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */
#define LED_ON GPIO_PIN_RESET
#define LED_OFF GPIO_PIN_SET

#define MOTOR_ON GPIO_PIN_SET
#define MOTOR_OFF GPIO_PIN_RESET
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
