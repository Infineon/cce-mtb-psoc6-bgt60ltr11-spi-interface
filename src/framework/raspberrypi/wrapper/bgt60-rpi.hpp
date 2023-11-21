/**
 * @file        bgt60-rpi.hpp
 * @author      Infineon Technologies AG
 * @brief       Radar BGT60 Raspberry Pi API
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef BGT60_RPI_HPP_
#define BGT60_RPI_HPP_

#include <functional>
#include <stdint.h>

#include "../../../corelib/xensiv_s2go_radar_bgt60ltr11_types.h"
#include "bgt60-pal-rpi.hpp"



namespace bgt60rpi
{
    typedef  xensiv_bgt60_motion_t    Motion_t;
    typedef  xensiv_bgt60_direction_t Direction_t;
    typedef  xensiv_bgt60_error_t     Error_t;
};

using namespace bgt60rpi;

/**
 * \addtogroup rpiApi
 * @{
 */

class Bgt60Rpi
{
    public:
                    Bgt60Rpi(uint8_t targetDet, uint8_t phaseDet);
                    ~Bgt60Rpi();
        Error_t     init();
        Error_t     deinit();
        Error_t     getMotion(Motion_t &motion);
        Error_t     getDirection(Direction_t &direction);
        Error_t     enableInterrupt(void (*cback) (void));
        Error_t     enableInterrupt(std::function<void(void)> & cback);
        Error_t     disableInterrupt(void);

    private: 
        
        xensiv_rpi_dev_ctx_t dev_rpi;   /**< RPi PAL context */
        xensiv_bgt60_t dev;             /**< Bgt60 corelib object */

        /**
         * Adapter of lambda functions to C pointers
         */

        typedef std::function<void(void)> StdFnCBack_t;
        
        static           uint8_t        idxNext;                   /**< Callback array allocation index*/
        static constexpr uint8_t        maxCBacks = 5;             /**< Maximum number of callbacks (thus class instances) that can register an interrupt */
        static           StdFnCBack_t   lambdaFnVector[maxCBacks]; /**< Lambda function vector */
        static           void         * fnPtrVector [maxCBacks];   /**< Callbacks function handlers vector */

        static void   wrappedCBackLambda0();
        static void   wrappedCBackLambda1();
        static void   wrappedCBackLambda2();
        static void   wrappedCBackLambda3();
        static void   wrappedCBackLambda4();

        static void * registerCBack(StdFnCBack_t cback);
};

/** @} */

#endif /**BGT60_RPI_HPP_*/
