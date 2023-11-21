/**
 * @file        bgt60-pal-ino.cpp
 * @brief       Radar BGT60 Arduino PAL Implementation
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include <Arduino.h>
#include "bgt60-pal-ino.hpp"

/**
 * @brief       Reads phase detect output HAL function pointer
 * @param[in]   ctx PAL context
 * @return      gpio_level_t 
 */
xensiv_gpio_level_t ino_bgt60_pd_read(void * ctx)
{
    xensiv_ino_dev_ctx_t * ino_cxt = (xensiv_ino_dev_ctx_t*)ctx;

    return (xensiv_gpio_level_t)digitalRead(ino_cxt->p_det_pin);
}

/**
 * @brief       Reads target detect output HAL function pointer
 * @param[in]   ctx PAL context
 * @return      gpio_level_t 
 */
xensiv_gpio_level_t ino_bgt60_td_read(void * ctx)
{
   xensiv_ino_dev_ctx_t * ino_cxt = (xensiv_ino_dev_ctx_t*)ctx;

    return (xensiv_gpio_level_t)digitalRead(ino_cxt->t_det_pin);
}

/**
 * @brief       Delay in milliseconds HAL function pointer
 * @param[in]   ms  Delay time in milliseconds 
 * @return      void 
 */ 
void ino_bgt60_delay(uint32_t ms)
{
    delay(ms);
}