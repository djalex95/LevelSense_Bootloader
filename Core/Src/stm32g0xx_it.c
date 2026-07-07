/*
 * stm32g0xx_it.c – Bootloader (minimal).
 *
 * Der Bootloader liest die UART per Polling und nutzt keine Peripherie-
 * Interrupts. Daher nur die Kern-Exceptions plus SysTick (für HAL_Delay/Tick).
 * Ersetzt beim Duplizieren des App-Projekts die App-Version (die auf
 * hfdcan1/hi2c1/htim6/… verweist, welche es hier nicht gibt).
 */

#include "main.h"
#include "stm32g0xx_it.h"

void NMI_Handler(void)
{
	while (1) { }
}

void HardFault_Handler(void)
{
	while (1) { }
}

void SVC_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}
