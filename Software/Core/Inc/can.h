/**
  ******************************************************************************
  * File Name          : CAN.h
  * Description        : This file provides code for the configuration
  *                      of the CAN instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __can_H
#define __can_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_CAN1_Init(void);
void MX_CAN2_Init(void);

/* USER CODE BEGIN Prototypes */

//TODO How is this calculated?
uint32_t Compose_CANId(uint8_t priority, uint16_t sourceId, uint8_t autonomous, uint8_t type, uint16_t extra, uint8_t BMSId);
void Parse_CANId(uint32_t CANId, uint8_t* priority, uint16_t* sourceId, uint8_t* autonomous, uint8_t* type, uint16_t* extra, uint8_t* BMSId);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ can_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
