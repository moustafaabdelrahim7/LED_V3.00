

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO.h"
typedef enum {
	VALID_BUTTON,
	INVALID_BUTTON_PORT,
	INVALID_BUTTON_PIN_NUMBER
}BUTTON_ERROR_TYPE;

extern BUTTON_ERROR_TYPE Button_INIT(uint8_t PIN);
extern BUTTON_ERROR_TYPE Button_read(uint8_t PIN,DIO_VOLTAGE_TYPE*VOLT);




#endif /* BUTTON_H_ */