

#ifndef DIO_H_
#define DIO_H_




/*****************************************************************************************************************************************************************
*									Includes																				 *
******************************************************************************************************************************************************************/
#include "../../SERVICE/Std_Types.h"
#include "../../SERVICE/Utiles.h"
#include "../MEMORYMAPIING.h"




/*****************************************************************************************************************************************************************
*									Typedefs																				 *
******************************************************************************************************************************************************************/


	/*PA*/
#define pina0	0
#define	pina1	1
#define	pina2	2
#define	pina3	3
#define	pina4	4
#define	pina5	5
#define	pina6	6
#define	pina7	7
	/*PB*/
#define	pinb0	8
#define	pinb1	9
#define	pinb2	10
#define	pinb3	11
#define	pinb4	12
#define	pinb5	13
#define	pinb6	14
#define	pinb7	15

	/*PC*/
#define	pinc0	16
#define	pinc1	17
#define	pinc2	18
#define	pinc3	19
#define	pinc4	20
#define	pinc5	21
#define	pinc6	22
#define	pinc7	23
	/*PD*/
#define	pind0	24
#define	pind1	25
#define	pind2	26
#define	pind3	27
#define	pind4	28
#define	pind5	29
#define	pind6	30
#define	pind7	31
	/*Total*/
#define TOTAL_PINS	32

typedef enum{
	LOW=0,
	HIGH
} DIO_VOLTAGE_TYPE;


typedef enum{
	OUTPUT=0,
	INFREE,
	INPLUP
} DIO_PINSTATUS_TYPE;

typedef enum{
	PA=0,
	PB,
	PC,
	PD
} DIO_PORT_TYPE;

typedef enum {
	VALID_DIO=0,
	INVALID_PIN_NUMBER,
	INVALID_PORT,
	INVALID_VOLTAGE,
	INVALID_DIRECTION
}DIO_ERROR_TYPE;


typedef struct{
	uint8_t			pin;
	DIO_PINSTATUS_TYPE		status;
}dio_config;


#define  Pins_Total    19



/*****************************************************************************************************************************************************************
*									Functions declarations																				 *
******************************************************************************************************************************************************************/
extern DIO_ERROR_TYPE DIO_INITPIN(uint8_t PIN,DIO_PINSTATUS_TYPE STATUS);

extern DIO_ERROR_TYPE DIO_WRITEPIN(uint8_t PIN,DIO_VOLTAGE_TYPE VOLTAGE);

extern DIO_ERROR_TYPE DIO_READPIN(uint8_t PIN,DIO_VOLTAGE_TYPE* VOLT);

extern void DIO_WritePort(DIO_PORT_TYPE port ,uint8_t data);

extern void DIO_TogglePin(uint8_t pin);

extern void DIO_Init_MCU(void);

extern void DIO_Init(void);

extern const DIO_PINSTATUS_TYPE PinsStatusArray[TOTAL_PINS];

extern dio_config dio_arr[Pins_Total];




#endif /* DIO_H_ */