![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# IR Click

---

- **CIC Prefix**  : IR
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Nov 2018.

---

### Software Support

We provide a library for the IR Click on our [LibStock](https://libstock.mikroe.com/projects/view/540/ir-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control IR Click board.
IR click communicates with the target board via UART protocol. 
This library contains drivers for writing ( emitting ) by QEE113 IR emitting diode, 
reading ( receiving ) and check for new byte of data received by TSOP38338 IR receiver module.

Key functions :

- ``` void ir_writeByte( uint8_t writeData ) ``` - Generic write byte of data function
- ``` uint8_t ir_readByte() ``` - Generic read byte of data function
- ``` uint8_t ir_checkByteReady() ``` - Check for new byte received function

**Examples Description**

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


```.c

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

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/540/ir-click-example) page.

Other mikroE Libraries used in the example:

- UART


**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
