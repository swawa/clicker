/*
    __ir_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __ir_driver.h
@brief    IR Driver
@mainpage IR Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   IR
@brief      IR Click Driver
@{

| Global Library Prefix | **IR** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _IR_H_
#define _IR_H_

/** 
 * @macro T_IR_P
 * @brief Driver Abstract type 
 */
#define T_IR_P    const uint8_t*

/** @defgroup IR_COMPILE Compilation Config */              /** @{ */

//  #define   __IR_DRV_SPI__                            /**<     @macro __IR_DRV_SPI__  @brief SPI driver selector */
//  #define   __IR_DRV_I2C__                            /**<     @macro __IR_DRV_I2C__  @brief I2C driver selector */                                          
  #define   __IR_DRV_UART__                           /**<     @macro __IR_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup IR_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup IR_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup IR_INIT Driver Initialization */              /** @{ */

#ifdef   __IR_DRV_SPI__
void ir_spiDriverInit(T_IR_P gpioObj, T_IR_P spiObj);
#endif
#ifdef   __IR_DRV_I2C__
void ir_i2cDriverInit(T_IR_P gpioObj, T_IR_P i2cObj, uint8_t slave);
#endif
#ifdef   __IR_DRV_UART__
void ir_uartDriverInit(T_IR_P gpioObj, T_IR_P uartObj);
#endif


/** @defgroup IR_FUNC Driver Functions */                   /** @{ */



/**
 * @brief Generic write byte of data function
 *
 * @param[in] writeData          8-bit wrire data
 *
 * Function write byte of data via 
 * QEE113 IR emitting diode.
 */
void ir_writeByte( uint8_t writeData );

/**
 * @brief Generic read byte of data function
 *
 * @return 
 * 8-bit read received data
 *
 * Function read received byte of data via 
 * TSOP38338 IR receiver module.
 */
uint8_t ir_readByte();

/**
 * @brief Check for new byte received function
 *
 * @return 
 * - 0 : no new data 
 * - 1 : data ready
 *
 * Function checks is there a new byte of data received
 * to the TSOP38338 IR receiver module.
 */
uint8_t ir_checkByteReady();



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_IR_STM.c
    @example Click_IR_TIVA.c
    @example Click_IR_CEC.c
    @example Click_IR_KINETIS.c
    @example Click_IR_MSP.c
    @example Click_IR_PIC.c
    @example Click_IR_PIC32.c
    @example Click_IR_DSPIC.c
    @example Click_IR_AVR.c
    @example Click_IR_FT90x.c
    @example Click_IR_STM.mbas
    @example Click_IR_TIVA.mbas
    @example Click_IR_CEC.mbas
    @example Click_IR_KINETIS.mbas
    @example Click_IR_MSP.mbas
    @example Click_IR_PIC.mbas
    @example Click_IR_PIC32.mbas
    @example Click_IR_DSPIC.mbas
    @example Click_IR_AVR.mbas
    @example Click_IR_FT90x.mbas
    @example Click_IR_STM.mpas
    @example Click_IR_TIVA.mpas
    @example Click_IR_CEC.mpas
    @example Click_IR_KINETIS.mpas
    @example Click_IR_MSP.mpas
    @example Click_IR_PIC.mpas
    @example Click_IR_PIC32.mpas
    @example Click_IR_DSPIC.mpas
    @example Click_IR_AVR.mpas
    @example Click_IR_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __ir_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */