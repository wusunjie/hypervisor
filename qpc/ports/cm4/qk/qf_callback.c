#include "qpc.h"
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

void SysTick_Handler(void)
{
	QK_ISR_ENTRY();
	QF_TICK_X(0U, (void *)0);
	QK_ISR_EXIT();
}

void QF_onStartup(void)
{
	SysTick_Config(SystemCoreClock / 100U);
	NVIC_SetPriorityGrouping(0U);
	NVIC_SetPriority(SysTick_IRQn, QF_AWARE_ISR_CMSIS_PRI);
}

void QF_onCleanup(void)
{

}

void QK_onIdle(void)
{

}


