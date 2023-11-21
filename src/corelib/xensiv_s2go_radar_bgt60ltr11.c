/**
 * @file        xensiv_s2go_radar_bgt60ltr11.c
 * @author      Infineon Technologies AG
 * @brief       Radar S2GO_RADAR_BGT60LTR11 API
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include <stddef.h>
#include "xensiv_s2go_radar_bgt60ltr11.h"
#include <stdio.h>

#ifndef XENSIV_S2GO_RADAR_BGT60LTR11_ASSERT
#include <assert.h>
#define XENSIV_S2GO_RADAR_BGT60LTR11_ASSERT(c)             assert(c)
#endif

/**
 * @brief       Reads out target detect radar output
 * @param[in]   dev s2go_radar_bgt60ltr11 device handle
 * @return      motion_t
 * @retval      MOTION if motion detected
 * @retval      NO_MOTION if no motion detected
 */
xensiv_s2go_radar_bgt60ltr11_motion_t xensiv_s2go_radar_bgt60ltr11_get_motion(xensiv_s2go_radar_bgt60ltr11_t * dev)
{
    xensiv_s2go_radar_bgt60ltr11_motion_t m;

    XENSIV_S2GO_RADAR_BGT60LTR11_ASSERT(NULL != dev);

    xensiv_gpio_level_t level = dev->td_read(dev->ctx);

    if(GPIO_LEVEL_LOW == level)
    {
        m = MOTION;
    }
    else if(GPIO_LEVEL_HIGH == level)
    {
        m = NO_MOTION;
    }

    return m;
}

/**
 * @brief       Reads out phase detect radar output
 * @param[in]   dev s2go_radar_bgt60ltr11 device handle
 * @return      direction_t
 * @retval      APPROACHING if target is approaching to the sensor
 * @retval      DEPARTING if target is departing from the sensor
 * @retval      NO_DIR if no motion detected
 */
xensiv_s2go_radar_bgt60ltr11_direction_t xensiv_s2go_radar_bgt60ltr11_get_direction(xensiv_s2go_radar_bgt60ltr11_t * dev)
{
    xensiv_s2go_radar_bgt60ltr11_direction_t d = NO_DIR;

    XENSIV_S2GO_RADAR_BGT60LTR11_ASSERT(NULL != dev);

    xensiv_s2go_radar_bgt60ltr11_motion_t m = xensiv_s2go_radar_bgt60ltr11_get_motion(dev);

    if(MOTION == m)
    {
        xensiv_gpio_level_t level = dev->pd_read(dev->ctx);

        if(GPIO_LEVEL_LOW == level)
        {
            d = DEPARTING;
        }
        else if(GPIO_LEVEL_HIGH== level)
        {
            d = APPROACHING;
        }
    }

    return d;
}


xensiv_s2go_radar_bgt60ltr11_error_t xensiv_s2go_radar_bgt60ltr11_spi_read(xensiv_s2go_radar_bgt60ltr11_t *dev, uint8_t reg_addr, uint16_t *data)
{

    uint32_t num_bytes = 3;
    uint8_t tx_data[3];
    uint8_t rx_data[3] = {0, 0, 0};
    
    tx_data[0] = (uint8_t)((reg_addr << 1) & 0xFE);
    tx_data[1] = 0;
    tx_data[2] = 0;

    xensiv_s2go_radar_bgt60ltr11_error_t radar_status = dev->spi_transfer(dev->ctx, tx_data, rx_data, num_bytes);

    uint16_t result = ((uint16_t)(rx_data[1] << 8) | (uint16_t)(rx_data[2]));

   // printf(" result from read fun is %d \r\n", result);
    if(radar_status == OK)
        *data = result;
    else
        *data = 0;
    
    return radar_status;

}

xensiv_s2go_radar_bgt60ltr11_error_t xensiv_s2go_radar_bgt60ltr11_spi_write(xensiv_s2go_radar_bgt60ltr11_t *dev, uint8_t reg_addr, uint16_t data)
{

    uint8_t num_bytes = 3;
    uint8_t tx_data[3];
    uint8_t rx_data[3] = {0, 0, 0};
    uint16_t wrdata = data;

    tx_data[0] = (uint8_t)((reg_addr << 1) | 0x01);
    tx_data[1] = (uint8_t)((wrdata >> 8) & 0xFF);
    tx_data[2] = (uint8_t)(wrdata & 0xFF);
    
    xensiv_s2go_radar_bgt60ltr11_error_t radar_status = dev->spi_transfer(dev->ctx, tx_data, rx_data, num_bytes);

    return radar_status;
}

