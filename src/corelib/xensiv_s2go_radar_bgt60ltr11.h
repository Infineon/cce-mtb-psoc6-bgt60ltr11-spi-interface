/**
 * @file        xensiv_s2go_radar_bgt60ltr11.h
 * @author      Infineon Technologies AG
 * @brief       Radar S2GO_RADAR_BGT60LTR11 API
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef XENSIV_S2GO_RADAR_BGT60LTR11_H_
#define XENSIV_S2GO_RADAR_BGT60LTR11_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "xensiv_s2go_radar_bgt60ltr11_types.h"

/**
 * \addtogroup s2go_radar_bgt60ltr11api
 * @{
 */

xensiv_s2go_radar_bgt60ltr11_motion_t    xensiv_s2go_radar_bgt60ltr11_get_motion     (xensiv_s2go_radar_bgt60ltr11_t * dev);

xensiv_s2go_radar_bgt60ltr11_direction_t xensiv_s2go_radar_bgt60ltr11_get_direction  (xensiv_s2go_radar_bgt60ltr11_t * dev);

xensiv_s2go_radar_bgt60ltr11_error_t    xensiv_s2go_radar_bgt60ltr11_spi_read (xensiv_s2go_radar_bgt60ltr11_t * dev, uint8_t reg_addr, uint16_t *data);

xensiv_s2go_radar_bgt60ltr11_error_t    xensiv_s2go_radar_bgt60ltr11_spi_write (xensiv_s2go_radar_bgt60ltr11_t *dev, uint8_t reg_addr, uint16_t data);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /** XENSIV_S2GO_RADAR_BGT60LTR11_H_ **/
