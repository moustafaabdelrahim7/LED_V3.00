#include "BUTTON.h"
BUTTON_ERROR_TYPE Button_INIT(uint8_t PIN)
{
	BUTTON_ERROR_TYPE status=VALID_BUTTON;
	uint8_t PIN_NUM;
	DIO_PORT_TYPE PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	if(PORT>4)
	{
		status= INVALID_BUTTON_PORT;
	}
	else if(PIN_NUM>32)
	{
		status= INVALID_BUTTON_PIN_NUMBER;
	}
	else
	{
		DIO_INITPIN(PIN,INPLUP);
		status= VALID_BUTTON;
	}
	return status;
}
BUTTON_ERROR_TYPE Button_read(uint8_t PIN,DIO_VOLTAGE_TYPE*VOLT)
{
	BUTTON_ERROR_TYPE status=VALID_BUTTON;
	uint8_t PIN_NUM;
	DIO_PORT_TYPE PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	if(PORT>4)
	{
		status= INVALID_BUTTON_PORT;
	}
	else if(PIN_NUM>32)
	{
		status= INVALID_BUTTON_PIN_NUMBER;
	}
	else
	{
		DIO_READPIN(PIN,VOLT);
		status= VALID_BUTTON;
	}
	return status;
}
