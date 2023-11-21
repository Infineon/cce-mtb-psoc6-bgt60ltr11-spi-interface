/**
 * @file        bgt60-pal-rpi.hpp
 * @brief       Radar BGT60 Raspberry Pi PAL Implementation
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef BGT60_PAL_RPI_HPP_
#define BGT60_PAL_RPI_HPP_

/**
 * \addtogroup rpiPal
 * @{
 */

#include "../../../corelib/xensiv_s2go_radar_bgt60ltr11_types.h"

/**
 * @brief Raspberry Pi PAL context
 */
typedef struct 
{
    uint8_t t_det_pin;  /**< Target detection pin */
    uint8_t p_det_pin;  /**< Phase detection pin */      
}xensiv_rpi_dev_ctx_t;   
        
xensiv_gpio_level_t rpi_bgt60_pd_read(const void * ctx);

xensiv_gpio_level_t rpi_bgt60_td_read(const void * ctx);

void rpi_bgt60_delay(uint32_t ms);

/** @} */

#endif /** BGT60_PAL_RPI_HPP_ **/