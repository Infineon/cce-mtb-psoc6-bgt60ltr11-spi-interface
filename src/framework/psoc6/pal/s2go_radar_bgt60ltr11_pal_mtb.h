/**
 * @file        s2go_radar_bgt60ltr11_pal_mtb.h
 * @author      Infineon Technologies AG
 * @brief       Radar S2GO_RADAR_BGT60LTR11 PSoC 6 PAL Implementation
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef S2GO_RADAR_BGT60LTR11_PAL_MTB_H_
#define S2GO_RADAR_BGT60LTR11_PAL_MTB_H_

#include <stdint.h>

#include "../../../corelib/xensiv_s2go_radar_bgt60ltr11_types.h"
#include "cyhal.h"
#include "cybsp.h"


/**
 * @brief Structure for GPIO pins
 */
typedef struct 
{
    cyhal_gpio_t pin_target;                                         /**< reads the target */
    cyhal_gpio_t pin_phase;                                          /**< reads the phase  */
    cyhal_spi_t spi_obj;
}mtb_s2go_radar_bgt60ltr11_gpio_t;


/**
 * @brief       Initialize the PSoC6 GPIO
 * @return      GPIO error code
 * @retval      OK if success
 * @retval      ERROR if Initialization error
 */
xensiv_s2go_radar_bgt60ltr11_error_t mtb_s2go_radar_bgt60ltr11_gpio_init(mtb_s2go_radar_bgt60ltr11_gpio_t *obj, cyhal_gpio_t pin_phase, cyhal_gpio_t pin_target);


/**
 * @brief       Initialize the PSoC6 SPI
 * @return      SPI init error code
 * @retval      OK if success
 * @retval      ERROR if Initialization error
 */
xensiv_s2go_radar_bgt60ltr11_error_t mtb_s2go_radar_bgt60ltr11_spi_init(mtb_s2go_radar_bgt60ltr11_gpio_t *obj, cyhal_gpio_t spi_miso, cyhal_gpio_t spi_mosi, cyhal_gpio_t spi_clk, cyhal_gpio_t spi_ss);


/**
 * @brief       Deinitializes the PSoC6 GPIO
 * @return      GPIO Deinint error code [EDITED]
 * @retval      OK if success
 * @retval      ERROR if Deinitialization error [IS THIS REQUIRED]
 */
xensiv_s2go_radar_bgt60ltr11_error_t mtb_s2go_radar_bgt60ltr11_gpio_deinit(mtb_s2go_radar_bgt60ltr11_gpio_t *obj);


/**
 * @brief       Deinitializes the PSoC6 SPI
 * @return      SPI Deinit error code
 * @retval      OK if success
 */
xensiv_s2go_radar_bgt60ltr11_error_t mtb_s2go_radar_bgt60ltr11_spi_deinit(mtb_s2go_radar_bgt60ltr11_gpio_t *obj);


/** [ADDED]
 * @brief       Reads the PSoC6 GPIO voltage level corresponding the phase
 * @return      GPIO voltage level
 * @retval      GPIO_LOW if voltage low
 * @retval      GPIO_HIGH if voltage high
 */
xensiv_gpio_level_t mtb_s2go_radar_bgt60ltr11_phase_read(const void *ctx);


/**
 * @brief       Reads the PS0C6 GPIO voltage level corresponding to target
 * @return      GPIO voltage level
 * @retval      GPIO_LOW if voltage low
 * @retval      GPIO_HIGH if voltage high
 */
xensiv_gpio_level_t mtb_s2go_radar_bgt60ltr11_target_read(const void *ctx);


/**
 * @brief       Performs SPI transfer between PSOC6 and Radar
 * @return      SPI transfer error code
 * @retval      OK if success
 * @retval      ERROR if SPI Transfer fails
 */
xensiv_s2go_radar_bgt60ltr11_error_t mtb_s2go_radar_bgt60ltr11_spi_transfer(const void * ctx, const uint8_t * tx_data, uint8_t * rx_data, uint32_t bytes);


/**
 * @brief       Delay in milliseconds
 * @param[in]   ms - Delay time in milliseconds
 * @return      void
 */
void mtb_s2go_radar_bgt60ltr11_delay(uint32_t ms);

#endif /*S2GO_RADAR_BGT60LTR11_PAL_MTB_H_*/
