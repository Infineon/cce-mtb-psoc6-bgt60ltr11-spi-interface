/**
 * @file        bgt60-pal-ino.hpp
 * @brief       Radar BGT60 Arduino PAL Implementation
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef BGT60_PAL_INO_HPP_
#define BGT60_PAL_INO_HPP_

/**
 * \addtogroup inoPal
 * @{
 */

#include "../../../corelib/xensiv_s2go_radar_bgt60ltr11_types.h"

/**
 * @brief Arduino PAL context
 */
typedef struct 
{
    uint8_t t_det_pin;  /**< Target detection pin */
    uint8_t p_det_pin;  /**< Phase detection pin */      
}xensiv_ino_dev_ctx_t;   
        
xensiv_gpio_level_t ino_bgt60_pd_read(void * ctx);

xensiv_gpio_level_t ino_bgt60_td_read(void * ctx);

void ino_bgt60_delay(uint32_t ms);

/** @} */

#endif /** BGT60_PAL_INO_HPP_ **/