/** 
 * @file        bgt60-rpi.cpp
 * @author      Infineon Technologies AG
 * @brief       Radar BGT60 Raspberry Pi API
 * @copyright   Copyright (c) 2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "bgt60-rpi.hpp"
#include "xensiv_bgt60.h"
#include <wiringPi.h>

using namespace bgt60rpi;

/**
 * @brief       Constructor of the RaspberryPi Bgt60 object
 * @details     This function is the instance constructor. It accepts the Raspberry Pi GPIO pins utilized
 *              for target and phase detect from the user. These pins are initialized by creating instances 
 *              to GPIORpi and then mapped to main Bgt60 class.           
 * @param[in]   targetDet   Pin number of the target detect pin
 * @param[in]   phaseDet    Pin number of the phase detect pin
 * @param[in]   pinMode     Desired mode of the board, polling or interrupt driven
 */
Bgt60Rpi::Bgt60Rpi(uint8_t targetDet, uint8_t phaseDet)
{
    dev_rpi.t_det_pin = targetDet;
    dev_rpi.p_det_pin = phaseDet;
    dev.spi_transfer = NULL;       
    dev.pd_read = &rpi_bgt60_pd_read;
    dev.td_read = &rpi_bgt60_td_read;
    dev.delay   = &rpi_bgt60_delay;
    dev.ctx = &dev_rpi;
}

/**
 * @brief       Destructor of the RaspberryPi Bgt60 object
 */
Bgt60Rpi::~Bgt60Rpi()
{

}
/**
 * @brief           Initialize the Bgt60 class object
 * @return          Bgt60 error code
 * @retval          OK if succcess
 * @retval          INTF_ERROR if PAL initialization fails
 */
Error_t Bgt60Rpi::init()
{
    Error_t err = OK;
    if (wiringPiSetup() < 0)
        err = INTF_ERROR;

    pinMode(dev_rpi.t_det_pin, INPUT);    
    pinMode(dev_rpi.p_det_pin, INPUT);

    return err;

}

/**
 * @brief           De-Initialize the Bgt60 class object
 * @return          Bgt60 error code
 * @retval          OK always
 */
Error_t Bgt60Rpi::deinit()
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
Error_t Bgt60Rpi::getMotion(Motion_t &motion)
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
Error_t Bgt60Rpi::getDirection(Direction_t &direction)
{
    direction = xensiv_bgt60_get_direction(&dev);

    return OK;
}

/**
 * @brief       Enables interrupt
 * @param[in]   cback   Pointer to the interrupt callback function 
 * 
 * @note        Convenience function to ease pybind11 wrapping of void pointer
 *              argument functions
 * 
 * @return      Bgt60 error code
 * @retval      OK if success
 * @retval      INTF_ERROR if error
 * @retval      CONF_ERROR if callback resource allocation not avaiable     
 */
Error_t Bgt60Rpi::enableInterrupt(void (*cback) (void))
{   
    if (nullptr != cback)
    {
        if (0 > wiringPiISR(dev_rpi.t_det_pin, INT_EDGE_BOTH, cback))  
        {
            return INTF_ERROR;
        }

        if (0 > wiringPiISR(dev_rpi.p_det_pin, INT_EDGE_BOTH, cback))  
        {
            return INTF_ERROR;
        }
    }
    else
    {
        return CONF_ERROR;
    }
    
    return OK;
}

/**
 * @brief       Enables interrupt
 * @param[in]   cback   Pointer to the interrupt callback function 
 * 
 * @note        Convenience function to ease pybind11 wrapping of void pointer
 *              argument functions
 * 
 * @return      Bgt60 error code
 * @retval      OK if success
 * @retval      INTF_ERROR if error
 * @retval      CONF_ERROR if callback resource allocation not avaiable     
 */
Error_t Bgt60Rpi::enableInterrupt(std::function<void(void)> & cback)
{   
    typedef void (*CCBackPtr_t)(void);

    CCBackPtr_t cCback = (CCBackPtr_t)registerCBack(cback);

    if (nullptr != cCback)
    {
        if (0 > wiringPiISR(dev_rpi.t_det_pin, INT_EDGE_BOTH, (void (*)())cCback))  
        {
            return INTF_ERROR;
        }

        if (0 > wiringPiISR(dev_rpi.p_det_pin, INT_EDGE_BOTH, (void (*)())cCback))  
        {
            return INTF_ERROR;
        }
    }
    else
    {
        return CONF_ERROR;
    }
    
    return OK;
}

/**
 * @brief       Disable interrupt
 * @details     This function disables the interrupt on chosen pin.
 * @note        Not supported by low level framework.
 * @return      Bgt60 error code
 * @retval      INTF Error always
 */
Error_t Bgt60Rpi::disableInterrupt(void)
{
    return INTF_ERROR;
}

Bgt60Rpi::StdFnCBack_t Bgt60Rpi::lambdaFnVector[maxCBacks] = { nullptr };
uint8_t Bgt60Rpi::idxNext = 0;

/**
 * @brief   Callback Lambda Wrapper Handler
 */
void Bgt60Rpi::wrappedCBackLambda0() 
{
    lambdaFnVector[0]();
}

/**
 * @brief   Callback Lambda Wrapper Handler
 */
void Bgt60Rpi::wrappedCBackLambda1() 
{
    lambdaFnVector[1]();
}

/**
 * @brief   Callback Lambda Wrapper Handler
 */
void Bgt60Rpi::wrappedCBackLambda2() 
{
    lambdaFnVector[2]();
}

/**
 * @brief   Callback Lambda Wrapper Handler
 */
void Bgt60Rpi::wrappedCBackLambda3() 
{
    lambdaFnVector[3]();
}

/**
 * @brief   Callback Lambda Wrapper Handler
 */
void Bgt60Rpi::wrappedCBackLambda4() 
{
    lambdaFnVector[4]();
}

void * Bgt60Rpi::fnPtrVector[maxCBacks] = {(void *)wrappedCBackLambda0,
                                           (void *)wrappedCBackLambda1,
                                           (void *)wrappedCBackLambda2,
                                           (void *)wrappedCBackLambda3,
                                           (void *)wrappedCBackLambda4};

/**
 * @brief       Register a lambda function and allocated its to one of the 
 *              available static wrappers. Up to the maximum available.
 * @param[in]   stdFuncBack Lambda callback
 * @return      Pointer to the allocated C callback wrapper
 */
void * Bgt60Rpi::registerCBack(StdFnCBack_t   cback)
{
    void * fPtr = nullptr;

    if(idxNext < maxCBacks)
    {
        lambdaFnVector[idxNext] = cback;
        fPtr =  fnPtrVector[idxNext++];
    }

    return fPtr;
}
