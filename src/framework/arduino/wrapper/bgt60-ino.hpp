/**
 * @file        bgt60-ino.hpp
 * @author      Infineon Technologies AG
 * @brief       Radar BGT60 Arduino API
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef BGT60_INO_HPP_
#define BGT60_INO_HPP_

#include <Arduino.h>
#include <stdint.h>

#include "../../../corelib/xensiv_s2go_radar_bgt60ltr11_types.h"
#include "bgt60-pal-ino.hpp"

namespace bgt60ino
{
    typedef  xensiv_bgt60_motion_t    Motion_t;
    typedef  xensiv_bgt60_direction_t Direction_t;
    typedef  xensiv_bgt60_error_t     Error_t;
};

using namespace bgt60ino;

/**
 * \addtogroup inoApi
 * @{
 */

class Bgt60Ino
{
    public:

                    Bgt60Ino(uint8_t targetDet, uint8_t phaseDet);
                    ~Bgt60Ino();
        Error_t     init();
        Error_t     deinit();
        Error_t     begin() { return init(); };
        Error_t     end()   { return deinit();};
        Error_t     getMotion(Motion_t &motion);
        Error_t     getDirection(Direction_t &direction);
        Error_t     enableInterrupt(void (*cback) (void));
        Error_t     disableInterrupt(void);

    private:
        
        xensiv_ino_dev_ctx_t dev_ino;   /**< Arduino PAL context */
        xensiv_bgt60_t dev;             /**< Bgt60 corelib object */
};

/** @} */

#endif /** BGT60_INO_HPP_ */