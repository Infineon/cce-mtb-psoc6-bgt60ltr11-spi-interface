/**
 * @file        bgt60-ino.cpp
 * @author      Infineon Technologies AG
 * @brief       Radar BGT60 Arduino API
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "bgt60-ino.hpp"
#include "xensiv_bgt60.h"

using namespace bgt60ino;

/**
 * @brief       Constructor of the Arduino Bgt60 object
 *
 * @param[in]   targetDet Pin number of the target detect pin
 * @param[in]   phaseDet Pin number of the phase detect pin
 */
Bgt60Ino::Bgt60Ino(uint8_t targetDet, uint8_t phaseDet)
{
    dev_ino.t_det_pin = targetDet;
    dev_ino.p_det_pin = phaseDet;
    dev.spi_transfer = NULL;       
    dev.pd_read = &ino_bgt60_pd_read;
    dev.td_read = &ino_bgt60_td_read;
    dev.delay   = &ino_bgt60_delay;
    dev.ctx = &dev_ino;
}

/**
 * @brief       Destructor of the Arduino Bgt60 object
 */
Bgt60Ino::~Bgt60Ino()
{

}

/**
 * @brief           Initialize the Bgt60 class object
 * @return          Bgt60 error code
 * @retval          OK always
 */
Error_t Bgt60Ino::init()
{
    pinMode(dev_ino.t_det_pin, INPUT);
    pinMode(dev_ino.p_det_pin, INPUT);

    return OK;
}

/**
 * @brief           De-Initialize the Bgt60 class object
 * @return          Bgt60 error code
 * @retval          OK always
 */
Error_t Bgt60Ino::deinit()
{
    return OK;
}

/**
 * @brief           Read out target-detect-pin
 * 
 * @param[in,out]   motion This variable stores the actual state of the target-detect-pin
 *                  Possible Values:
 *                      - NO_MOTION
 *                      - MOTION
 *
 * @return          Bgt60 error code
 * @retval          OK always
 */
Error_t Bgt60Ino::getMotion(Motion_t &motion)
{
    motion = xensiv_bgt60_get_motion(&dev);

    return OK;
}

/**
 * @brief           Read out phase-detect-pin
 *
 * @param[in,out]   direction This variable stores the actual state of the phase-detect-pin
 *                  Possible Values:
 *                      - NO_DIR
 *                      - APPROACHING
 *                      - DEPARTING
 * @return          Bgt60 error code
 * @retval          OK always
 */
Error_t Bgt60Ino::getDirection(Direction_t &direction)
{
    direction = xensiv_bgt60_get_direction(&dev);

    return OK;
}

/**
 * @brief       Enables the hardware interrupt
 * 
 * @param[in]   *cback  Pointer to the interrupt callback function 
 * @return      Bgt60 error code
 * @retval      OK always
 */
Error_t Bgt60Ino::enableInterrupt(void (*cback) (void))
{
    attachInterrupt(digitalPinToInterrupt(dev_ino.p_det_pin), (void (*)())cback, CHANGE);
    attachInterrupt(digitalPinToInterrupt(dev_ino.t_det_pin), (void (*)())cback, CHANGE);

    return OK;
}

/**
 * @brief       Disables the hardware interrupt
 * 
 * @return      Bgt60 error code
 * @retval      OK always
 */
Error_t Bgt60Ino::disableInterrupt(void)
{
    detachInterrupt(digitalPinToInterrupt(dev_ino.p_det_pin));
    detachInterrupt(digitalPinToInterrupt(dev_ino.t_det_pin));

    return OK;
}   