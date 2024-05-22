/*
Example for IR Click

    Date          : Nov 2018.
    Author        : Nenad Filipovic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, UART and LOG structures,
     set INT pin as input and PWM pin sa output.
- Application Initialization - Initialization driver enable's - UART and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of IR Click board.
     IR Click communicates with register via UART protocol by write or read and check for new byte received.
     The example checks if new data byte have received in RF buffer ( ready for reading )
     and if ready than reads one byte from RX buffer.
     In second case aplication task writes ( send ) data via UART.
     Results are being sent to the Usart Terminal where you can track their changes.


*/

#include "Click_IR_types.h"
#include "Click_IR_config.h"


const uint8_t demoData[ 4 ] = { 0x12, 0x34, 0x56, 0x0F };

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );

    mikrobus_uartInit( _MIKROBUS1, &_IR_UART_CFG[0] );

    mikrobus_logInit( _LOG_USBUART, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
    ir_uartDriverInit( (T_IR_P)&_MIKROBUS1_GPIO, (T_IR_P)&_MIKROBUS1_UART );

    mikrobus_logWrite( "------------------", _LOG_LINE );
    mikrobus_logWrite( "     IR Click     ", _LOG_LINE );
    mikrobus_logWrite( "------------------", _LOG_LINE );
    mikrobus_logWrite( "     RECEIVER     ", _LOG_LINE );
//    mikrobus_logWrite( "    TRANSMITER    ", _LOG_LINE );
    mikrobus_logWrite( "------------------", _LOG_LINE );
}

void applicationTask()
{
    char receivedData;
    uint8_t counter;

    // UART RX - RECEIVER TSOP38338
    if ( ir_checkByteReady() )
    {
        receivedData = ir_readByte();
        mikrobus_logWrite( &receivedData, _LOG_BYTE );
    }

/*
     // UART TX - EMITTER QEE113
    for ( counter = 0; counter < 4; counter++ )
    {
        ir_writeByte( demoData[ counter ] );
        mikrobus_logWrite( "Data sent!", _LOG_LINE );
    }

    Delay_ms( 2000 );
*/
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}