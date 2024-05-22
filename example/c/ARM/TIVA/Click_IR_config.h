#include "Click_IR_types.h"


const uint32_t _IR_UART_CFG[ 6 ] = 
{
        9600, 
        0,                        // CPU FQ Parameter will be replaced during init call
        _UART_8_BIT_DATA, 
        _UART_NOPARITY,
    _UART_ONE_STOPBIT, 
    _UART_HIGH_SPEED
};