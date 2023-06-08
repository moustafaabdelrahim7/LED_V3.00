#include "INTERRUPT.h"
/*
 void  static (*Fptr_INT0) (void) = NULL;
 void  static (*Fptr_INT1) (void) = NULL;
 void  static (*Fptr_INT2) (void) = NULL;*/
 
 /*this function enables the interrupt pin*/
uint8_t  blink_mode=0;
uint8_t   FLAG=0;
uint8_t   counter=0;
INTERRUPT_ERROR_TYPE EXI_Enable(EXInterruptSource_type interrupt)
{

		switch(interrupt)
	{
		case EX_INT0:
		{
			set_bit(GICR,INT0);
		}
		break;
		
		case EX_INT1:
		{
			set_bit(GICR,INT1);
		}
		break;
		
		case EX_INT2:
		{
			set_bit(GICR,INT2);
		}
		break;
		
		default:
		{
			//do nothing
		}
		break;
	}
	
}

/*it disable interrupt pin*/

INTERRUPT_ERROR_TYPE EXI_Disable (EXInterruptSource_type interrupt)
{
	
	switch(interrupt)
	{
		case EX_INT0:
		{
			clear_bit(GICR,INT0);
		}
		 break;
		 
		case EX_INT1:
		{
			clear_bit(GICR,INT1);
		}
		 break;
		 
		case EX_INT2:
		{
			clear_bit(GICR,INT2);
		}
		 break;
		 
		default:
		{
			//do nothing
		}
		break;
	}
	
}

/*it defines the trigger state of the interrupt*/
INTERRUPT_ERROR_TYPE EXI_TriggerEdge (EXInterruptSource_type interrupt, TriggerEdge_type edge )
{

	switch(interrupt)
	{
		case EX_INT0:
			switch(edge)
			{
				case LOW_LEVEL:
				{
					clear_bit(MCUCR,ISC00);
					clear_bit(MCUCR,ISC01);
				}
				break;
				
				case ANY_LOGIC_CHANGE:
				{
					set_bit(MCUCR,ISC00);
					clear_bit(MCUCR,ISC01);
				}
				break;
				
				case FALLING_EDGE:
				{
					clear_bit(MCUCR,ISC00);
					set_bit(MCUCR,ISC01);
				}
				break;
				
				case RISING_EDGE:
				{
				set_bit(MCUCR,ISC00);
				set_bit(MCUCR,ISC01);
				}
				break;
			}
			break;
			
		case EX_INT1:
			switch(edge)
			{
				case LOW_LEVEL:
				{
					clear_bit(MCUCR,ISC10);
					clear_bit(MCUCR,ISC11);
				}
				 break;
				 
				case ANY_LOGIC_CHANGE:
				{
					set_bit(MCUCR,ISC10);
					clear_bit(MCUCR,ISC11);
				}
				 break;
				 
				case FALLING_EDGE:
				{
					clear_bit(MCUCR,ISC10);
					set_bit(MCUCR,ISC11);
				}
				 break;
				 
				case RISING_EDGE:
				{
					set_bit(MCUCR,ISC10);
					set_bit(MCUCR,ISC11);
				}
				 break;
			}
			break;
			
		case EX_INT2:
			switch(edge)
			{
				case LOW_LEVEL:
				 /*DO nothing OR set default */
				break;
				
				case  ANY_LOGIC_CHANGE:
			 /*DO nothing OR set default */
				break;
				
				case FALLING_EDGE:
				{
					clear_bit(MCUCSR,ISC2);
				}
				 break;
				 
				case RISING_EDGE:
				{
					set_bit(MCUCSR,ISC2);
				}		 
				break;
			}
			break;
	}
	
}

/*
INTERRUPT_ERROR_TYPE EXI_SetCallBack(EXInterruptSource_type interrupt, void (*pf_local)(void))
{
	switch(interrupt)
	{
		case EX_INT0:
		Fptr_INT0=pf_local; 
		break;
		case EX_INT1:
		Fptr_INT1=pf_local; 
		break;
		case EX_INT2:
		Fptr_INT2=pf_local;
	    break;
	}
}
*/



ISR(INT0_VECTOR)
{    
	FLAG++;                 
	 if(FLAG==8)
	{
		FLAG=0;
	}
	
}

ISR(INT1_VECTOR)
{
	blink_mode++;
	if(blink_mode==5)
	{
		blink_mode=0;
	}
}

ISR(TIMER0_OVF_VECTOR)
{
	
	if(blink_mode==0)
	{
			counter++;
			if(FLAG==1)
			{
				if( counter==5)
				  {
					DIO_WRITEPIN(pina0,LOW);	
					timer0_SetCounter(6);
					}
			else if(counter==60)
				   {
				DIO_TogglePin(pina0);
				counter=0;
				timer0_SetCounter(6);
				 }
			}
			if(FLAG==2)
			{
				if( counter==5)
				{
					DIO_WRITEPIN(pina1,LOW);
					DIO_WRITEPIN(pina0,LOW);
					timer0_SetCounter(6);
				}
				else if(counter==60)
				{
					DIO_TogglePin(pina1);
					DIO_TogglePin(pina0);
					counter=0;
					timer0_SetCounter(6);
				}
			}
			if(FLAG==3)
			{
				if( counter==5)
				{
					DIO_WRITEPIN(pina2,LOW);
					DIO_WRITEPIN(pina1,LOW);
					DIO_WRITEPIN(pina0,LOW);
					timer0_SetCounter(6);
				}
				else if(counter==60)
				{
					DIO_TogglePin(pina2);
					DIO_TogglePin(pina1);
					DIO_TogglePin(pina0);
					counter=0;
					timer0_SetCounter(6);
				}
			}
			if(FLAG==4)
			{
				if( counter==5)
				{
					DIO_WRITEPIN(pina3,LOW);
					DIO_WRITEPIN(pina2,LOW);
					DIO_WRITEPIN(pina1,LOW);
					DIO_WRITEPIN(pina0,LOW);
					timer0_SetCounter(6);
				}
				else if(counter==60)
				{
					DIO_TogglePin(pina3);
					DIO_TogglePin(pina2);
					DIO_TogglePin(pina1);
					DIO_TogglePin(pina0);
					counter=0;
					timer0_SetCounter(6);
				}
			}
			if(FLAG==5)
			{
				if( counter==5)
				{
					DIO_WRITEPIN(pina3,LOW);
					DIO_WRITEPIN(pina2,LOW);
					DIO_WRITEPIN(pina1,LOW);
					DIO_WRITEPIN(pina0,LOW);
					timer0_SetCounter(6);
				}
				else if(counter==60)
				{
					DIO_TogglePin(pina3);
					DIO_TogglePin(pina2);
					DIO_TogglePin(pina1);
					counter=0;
					timer0_SetCounter(6);
				}
			}
			if(FLAG==6)
			{
				if( counter==5)
				{
					DIO_WRITEPIN(pina3,LOW);
					DIO_WRITEPIN(pina2,LOW);
					DIO_WRITEPIN(pina1,LOW);
					DIO_WRITEPIN(pina0,LOW);
					timer0_SetCounter(6);
				}
				else if(counter==60)
				{
					DIO_TogglePin(pina3);
					DIO_TogglePin(pina2);
					counter=0;
					timer0_SetCounter(6);
				}
			}
			if(FLAG==7)
			{
				if( counter==5)
				{
					DIO_WRITEPIN(pina3,LOW);
					DIO_WRITEPIN(pina2,LOW);
					DIO_WRITEPIN(pina1,LOW);
					DIO_WRITEPIN(pina0,LOW);
					timer0_SetCounter(6);
				}
				else if(counter==60)
				{
					DIO_TogglePin(pina3);
					counter=0;
					timer0_SetCounter(6);
				}
			}
	}
/******************************************************************/

	if(blink_mode==1)
	{
		counter++;
		if(FLAG==1)
		{
			if( counter==12)
			{
				DIO_WRITEPIN(pina0,LOW);
				timer0_SetCounter(6);
			}
			else if(counter==60)
			{
				DIO_TogglePin(pina0);
				counter=0;
				timer0_SetCounter(6);
			}
		}
		if(FLAG==2)
		{
			if( counter==12)
			{
				DIO_WRITEPIN(pina1,LOW);
				DIO_WRITEPIN(pina0,LOW);
				timer0_SetCounter(6);
			}
			else if(counter==60)
			{
				DIO_TogglePin(pina1);
				DIO_TogglePin(pina0);
				counter=0;
				timer0_SetCounter(6);
			}
		}
		if(FLAG==3)
		{
			if( counter==12)
			{
				DIO_WRITEPIN(pina2,LOW);
				DIO_WRITEPIN(pina1,LOW);
				DIO_WRITEPIN(pina0,LOW);
				timer0_SetCounter(6);
			}
			else if(counter==60)
			{
				DIO_TogglePin(pina2);
				DIO_TogglePin(pina1);
				DIO_TogglePin(pina0);
				counter=0;
				timer0_SetCounter(6);
			}
		}
		if(FLAG==4)
		{
			if( counter==12)
			{
				DIO_WRITEPIN(pina3,LOW);
				DIO_WRITEPIN(pina2,LOW);
				DIO_WRITEPIN(pina1,LOW);
				DIO_WRITEPIN(pina0,LOW);
				timer0_SetCounter(6);
			}
			else if(counter==60)
			{
				DIO_TogglePin(pina3);
				DIO_TogglePin(pina2);
				DIO_TogglePin(pina1);
				DIO_TogglePin(pina0);
				counter=0;
				timer0_SetCounter(6);
			}
		}
		if(FLAG==5)
		{
			if( counter==12)
			{
				DIO_WRITEPIN(pina3,LOW);
				DIO_WRITEPIN(pina2,LOW);
				DIO_WRITEPIN(pina1,LOW);
				DIO_WRITEPIN(pina0,LOW);
				timer0_SetCounter(6);
			}
			else if(counter==60)
			{
				DIO_TogglePin(pina3);
				DIO_TogglePin(pina2);
				DIO_TogglePin(pina1);
				counter=0;
				timer0_SetCounter(6);
			}
		}
		if(FLAG==6)
		{
			if( counter==12)
			{
				DIO_WRITEPIN(pina3,LOW);
				DIO_WRITEPIN(pina2,LOW);
				DIO_WRITEPIN(pina1,LOW);
				DIO_WRITEPIN(pina0,LOW);
				timer0_SetCounter(6);
			}
			else if(counter==60)
			{
				DIO_TogglePin(pina3);
				DIO_TogglePin(pina2);
				counter=0;
				timer0_SetCounter(6);
			}
		}
		if(FLAG==7)
		{
			if( counter==12)
			{
				DIO_WRITEPIN(pina3,LOW);
				DIO_WRITEPIN(pina2,LOW);
				DIO_WRITEPIN(pina1,LOW);
				DIO_WRITEPIN(pina0,LOW);
			    timer0_SetCounter(6);
			}
			else if(counter==60)
			{
				DIO_TogglePin(pina3);
				counter=0;
				timer0_SetCounter(6);
			}
		}
	}
/****************************************************************************************/
if(blink_mode==2)
{
	counter++;
	if(FLAG==1)
	{
		if( counter==17)
		{
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==2)
	{
		if( counter==17)
		{
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina1);
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==3)
	{
		if( counter==17)
		{
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina2);
			DIO_TogglePin(pina1);
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==4)
	{
		if( counter==17)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			DIO_TogglePin(pina2);
			DIO_TogglePin(pina1);
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==5)
	{
		if( counter==17)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			DIO_TogglePin(pina2);
			DIO_TogglePin(pina1);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==6)
	{
		if( counter==17)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			DIO_TogglePin(pina2);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==7)
	{
		if( counter==17)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			counter=0;
			timer0_SetCounter(6);
		}
	}
}
/**********************************************************************************/
if(blink_mode==3)
{
	counter++;
	if(FLAG==1)
	{
		if( counter==30)
		{
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==2)
	{
		if( counter==30)
		{
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina1);
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==3)
	{
		if( counter==30)
		{
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina2);
			DIO_TogglePin(pina1);
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==4)
	{
		if( counter==30)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			DIO_TogglePin(pina2);
			DIO_TogglePin(pina1);
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==5)
	{
		if( counter==30)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			DIO_TogglePin(pina2);
			DIO_TogglePin(pina1);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==6)
	{
		if( counter==30)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			DIO_TogglePin(pina2);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==7)
	{
		if( counter==30)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			counter=0;
			timer0_SetCounter(6);
		}
	}
}
/********************************************************************************************/
if(blink_mode==4)
{
	counter++;
	if(FLAG==1)
	{
		if( counter==50)
		{
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==2)
	{
		if( counter==50)
		{
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina1);
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==3)
	{
		if( counter==50)
		{
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina2);
			DIO_TogglePin(pina1);
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==4)
	{
		if( counter==50)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			DIO_TogglePin(pina2);
			DIO_TogglePin(pina1);
			DIO_TogglePin(pina0);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==5)
	{
		if( counter==50)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			DIO_TogglePin(pina2);
			DIO_TogglePin(pina1);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==6)
	{
		if( counter==50)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			DIO_TogglePin(pina2);
			counter=0;
			timer0_SetCounter(6);
		}
	}
	if(FLAG==7)
	{
		if( counter==50)
		{
			DIO_WRITEPIN(pina3,LOW);
			DIO_WRITEPIN(pina2,LOW);
			DIO_WRITEPIN(pina1,LOW);
			DIO_WRITEPIN(pina0,LOW);
			timer0_SetCounter(6);
		}
		else if(counter==60)
		{
			DIO_TogglePin(pina3);
			counter=0;
			timer0_SetCounter(6);
		}
	}
}
}
