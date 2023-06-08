#include "MCAL/DIO/DIO.h"
#include "HAL/BUTTON/BUTTON.h"
#include "HAL/LED/LED.h"
#include "MCAL/INTERRUPT/INTERRUPT.h"
#include "MCAL/TIMER/TIMER.h"

int main(void)
{
	/**********intializing LED& DIO*************/
	LED_INIT(pina0);
	LED_INIT(pina1);
	LED_INIT(pina2);
	LED_INIT(pina3);
	DIO_INITPIN(pind2,INPLUP);
	DIO_INITPIN(pind3,INPLUP);
	/*****************INTIALIZING INTERRUPT***********/
	sei();
	EXI_TriggerEdge(EX_INT0,LOW_LEVEL);
	EXI_TriggerEdge(EX_INT1,LOW_LEVEL);
	EXI_Enable(EX_INT0);
	EXI_Enable(EX_INT1);
	Timer0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_64,OC0_DISCONNECTED);
	Timer0_OVF_InterrupEnable();
	timer0_SetCounter(6);
	
	while(1)
	{
	}

}


