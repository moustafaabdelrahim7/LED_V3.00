#include "LED.h"
LED_ERROR_TYPE LED_INIT(uint8_t PIN)
{
	LED_ERROR_TYPE status=VALID_LED;
	uint8_t PIN_NUM;
	DIO_PORT_TYPE PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	if(PORT>4)
	{
		status= INVALID_LED_PORT;
	}
	else if(PIN_NUM>32)
	{
		status= INVLAID_LED_PIN_NUMBER;
	}
	else
	{
		DIO_INITPIN(PIN,OUTPUT);
		status= VALID_LED;
	}
	return status;
}
LED_ERROR_TYPE LED_ON(uint8_t PIN)
{
	LED_ERROR_TYPE status=VALID_LED;
	uint8_t PIN_NUM;
	DIO_PORT_TYPE PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	if(PORT>4)
	{
		status= INVALID_LED_PORT;
	}
	else if(PIN_NUM>32)
	{
		status= INVLAID_LED_PIN_NUMBER;
	}
	else
	{
		DIO_WRITEPIN(PIN,HIGH);
		status= VALID_LED;
	}
	return status;
}
LED_ERROR_TYPE LED_OFF(uint8_t PIN)
{
	uint8_t PIN_NUM;
	DIO_PORT_TYPE PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	LED_ERROR_TYPE status=VALID_LED;
	if(PORT>4)
	{
		status= INVALID_LED_PORT;
	}
	else if(PIN_NUM>32)
	{
		status= INVLAID_LED_PIN_NUMBER;
	}
	else
	{
		DIO_WRITEPIN(PIN,LOW);
		status= VALID_LED;
	}
	return status;
}