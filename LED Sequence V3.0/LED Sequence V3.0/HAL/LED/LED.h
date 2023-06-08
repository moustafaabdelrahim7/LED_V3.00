

#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"

typedef enum {
	VALID_LED,
	INVALID_LED_PORT,
	INVLAID_LED_PIN_NUMBER
}LED_ERROR_TYPE;
extern LED_ERROR_TYPE LED_INIT(uint8_t PIN);
extern LED_ERROR_TYPE LED_ON(uint8_t PIN);
extern LED_ERROR_TYPE LED_OFF(uint8_t PIN);






#endif /* LED_H_ */