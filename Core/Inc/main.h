/*
 * main.h – Bootloader (minimal). Nur HAL-Include und die BLE-Steuerpins.
 * Ersetzt beim Duplizieren des App-Projekts die App-main.h.
 */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g0xx_hal.h"

void Error_Handler(void);

/* BLE-Steuerpins (identisch zum App-Projekt) */
#define BLE_MODE_Pin        GPIO_PIN_9
#define BLE_MODE_GPIO_Port  GPIOB
#define BLE_RESET_Pin       GPIO_PIN_5
#define BLE_RESET_GPIO_Port GPIOA
#define BLE_BUSY_Pin        GPIO_PIN_1
#define BLE_BUSY_GPIO_Port  GPIOB
#define BLE_LED_Pin         GPIO_PIN_15
#define BLE_LED_GPIO_Port   GPIOB

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
