#include "TIMER.h"

/*this function give the HAL layer the appilty to choose the timer mode, it's scaller,
  and if it want a compare match feature or not*/
void Timer0_Init(Timer0Mode_type mode, Timer0SCALER_type scaler,OC0Mode_type oc_mode )
{
	switch(mode)
	{
		case TIMER0_NORMAL_MODE:
		{
			clear_bit(TCCR0,WGM00);
			clear_bit(TCCR0,WGM01);
		}
		break;
		
		case TIMER0_PHASE_CORRECT_MODE:
		{
			set_bit(TCCR0,WGM00);
			clear_bit(TCCR0,WGM01);
		}
		break;
		
		case TIMER0_CTC_MODE:
		{
			clear_bit(TCCR0,WGM00);
			set_bit(TCCR0,WGM01);
		}
		break;
		
		case TIMER0_FASTPWM_MODE:
		{
			set_bit(TCCR0,WGM00);
			set_bit(TCCR0,WGM01);
		}
		break;
		
		default:
		{
			//do nothing
		}
		break;
	}
	
	switch(scaler)
	{
		case TIMER0_STOP:
		{
			clear_bit(TCCR0,CS00);
			clear_bit(TCCR0,CS01);
			clear_bit(TCCR0,CS02);
		}
		break;
		
		case TIMER0_SCALER_1:
		{
			set_bit(TCCR0,CS00);
			clear_bit(TCCR0,CS01);
			clear_bit(TCCR0,CS02);
		}
		break;
		
		case TIMER0_SCALER_8:
		{
			clear_bit(TCCR0,CS00);
			set_bit(TCCR0,CS01);
			clear_bit(TCCR0,CS02);
		}
		break;
		
		case TIMER0_SCALER_64:
		{
			set_bit(TCCR0,CS00);
			set_bit(TCCR0,CS01);
			clear_bit(TCCR0,CS02);
		}
		break;
		
		case TIMER0_SCALER_256:
		{
			clear_bit(TCCR0,CS00);
			clear_bit(TCCR0,CS01);
			set_bit(TCCR0,CS02);
		}
		break;
		
		case TIMER0_SCALER_1024:
		{
			set_bit(TCCR0,CS00);
			clear_bit(TCCR0,CS01);
			set_bit(TCCR0,CS02);
		}
		break;
		
		case TIMER0_EXTERNAL_FALLING:
		{
			clear_bit(TCCR0,CS00);
			set_bit(TCCR0,CS01);
			set_bit(TCCR0,CS02);
		}
		break;
		
		case TIMER0_EXTERNAL_RISING:
		{
			set_bit(TCCR0,CS00);
			set_bit(TCCR0,CS01);
			set_bit(TCCR0,CS02);
		}
		break;
		
		default:
		{
			//do nothing
		}
		break;
	}
	
	switch(oc_mode)
	{
		case OC0_DISCONNECTED:
		{
			clear_bit(TCCR0,COM00);
			clear_bit(TCCR0,COM01);
		}
		break;
		
		case  OC0_TOGGLE:
		{
			set_bit(TCCR0,COM00);
			clear_bit(TCCR0,COM01);
		}
		break;
		
		case OC0_NON_INVERTING:
		{
			clear_bit(TCCR0,COM00);
			set_bit(TCCR0,COM01);
		}
		break;
		case  OC0_INVERTING:
		{
			set_bit(TCCR0,COM00);
			set_bit(TCCR0,COM01);
		}
		break;
		
		default:
		{
			//do nothing
		}
		break;
	}
}
/*******************************************************************************************/
/* this function sets the offset of the timer for easier tick time and ovf calculations */
void timer0_SetCounter(uint8_t offset)
{
	TCNT0=offset;
}
/****************************************************************************************/
/*it enables the over flow interrupt*/
void Timer0_OVF_InterrupEnable(void)
{
	set_bit(TIMSK,TOIE0);
}
/*it disable the over flow interrupt*/
void Timer0_OVF_InterrupDisable(void)
{
	clear_bit(TIMSK,TOIE0);
}
/**************************************************************************************/
/*this function sets the offset of the compare unit */
void Timer0_SetCompare(uint8_t limit)
{
	OCR0=limit;
}
/************************************************************************************/
/*it enables the output compare interrupt*/
void Timer0_OC_InterruptEnable(void)
{
	set_bit(TIMSK,OCIE0);
}
/***********************************************************************************/
/*it disable the output compare interrupt*/
void Timer0_OC_InterruptDisable(void)
{
	clear_bit(TIMSK,OCIE0);
}
