/**
 * @file        s2go_radar_bgt60ltr11_pal_mtb.c
 * @author      Infineon Technologies AG
 * @brief       Radar S2GO_RADAR_BGT60LTR11 PSoC 6 PAL Implementation
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#include "s2go_radar_bgt60ltr11_pal_mtb.h"


#define spi_frequency 1000000u

void mtb_s2go_radar_bgt60ltr11_delay(uint32_t ms)
{
    cyhal_system_delay_ms(ms);
}

xensiv_s2go_radar_bgt60ltr11_error_t mtb_s2go_radar_bgt60ltr11_gpio_init(mtb_s2go_radar_bgt60ltr11_gpio_t *obj, cyhal_gpio_t pin_phase, cyhal_gpio_t pin_target)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    result = cyhal_gpio_init(pin_phase, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE, 0u);
    if (result == CY_RSLT_SUCCESS)
    {
        obj->pin_phase = pin_phase;
    }
    else
        return INTF_ERROR; /**Return Interface error**/

    result = cyhal_gpio_init(pin_target, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE, 0u);
    if (result == CY_RSLT_SUCCESS)
    {
        obj->pin_target = pin_target;
    }
    else
        return INTF_ERROR; /**Return Interface error**/

    return OK;
}

xensiv_s2go_radar_bgt60ltr11_error_t mtb_s2go_radar_bgt60ltr11_spi_init(mtb_s2go_radar_bgt60ltr11_gpio_t *obj, cyhal_gpio_t spi_miso,
		cyhal_gpio_t spi_mosi, cyhal_gpio_t spi_clk, cyhal_gpio_t spi_ss)
{

    cy_rslt_t result = CY_RSLT_SUCCESS;
    result = cyhal_spi_init(&(obj->spi_obj), spi_mosi, spi_miso, spi_clk, spi_ss, NULL ,
    		8, CYHAL_SPI_MODE_10_MSB, false);

    if (result == CY_RSLT_SUCCESS){
        result = cyhal_spi_set_frequency(&(obj->spi_obj), spi_frequency);
        if(result == CY_RSLT_SUCCESS){
            return OK;
        }
        else{
            return INTF_ERROR;
        }
    }
    else{
        return INTF_ERROR;
    }

}



xensiv_gpio_level_t mtb_s2go_radar_bgt60ltr11_phase_read(const void *ctx)
{
    mtb_s2go_radar_bgt60ltr11_gpio_t *mtb_s2go_radar_bgt60ltr11_context = (mtb_s2go_radar_bgt60ltr11_gpio_t *)ctx;
    return (xensiv_gpio_level_t)cyhal_gpio_read(mtb_s2go_radar_bgt60ltr11_context->pin_phase);
}

xensiv_gpio_level_t mtb_s2go_radar_bgt60ltr11_target_read(const void *ctx)
{
    mtb_s2go_radar_bgt60ltr11_gpio_t *mtb_s2go_radar_bgt60ltr11_context = (mtb_s2go_radar_bgt60ltr11_gpio_t *)ctx;
    return (xensiv_gpio_level_t)cyhal_gpio_read(mtb_s2go_radar_bgt60ltr11_context->pin_target);
}


xensiv_s2go_radar_bgt60ltr11_error_t mtb_s2go_radar_bgt60ltr11_spi_transfer(const void * ctx, const uint8_t * tx_data, uint8_t * rx_data, uint32_t bytes)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    mtb_s2go_radar_bgt60ltr11_gpio_t *mtb_s2go_radar_bgt60ltr11_context = (mtb_s2go_radar_bgt60ltr11_gpio_t *)ctx;

    result = cyhal_spi_transfer(&(mtb_s2go_radar_bgt60ltr11_context->spi_obj), tx_data, bytes, rx_data, bytes, 0x00);
    if(result == CY_RSLT_SUCCESS){
        return OK;
    }
    else{
        return INTF_ERROR;
    }

}

xensiv_s2go_radar_bgt60ltr11_error_t mtb_s2go_radar_bgt60ltr11_gpio_deinit(mtb_s2go_radar_bgt60ltr11_gpio_t *obj)
{
    cyhal_gpio_free(obj->pin_phase);
    cyhal_gpio_free(obj->pin_target);
    return OK;
}

xensiv_s2go_radar_bgt60ltr11_error_t mtb_s2go_radar_bgt60ltr11_spi_deinit(mtb_s2go_radar_bgt60ltr11_gpio_t *obj)
{
    cyhal_spi_free(&(obj->spi_obj));
    return OK;
}
