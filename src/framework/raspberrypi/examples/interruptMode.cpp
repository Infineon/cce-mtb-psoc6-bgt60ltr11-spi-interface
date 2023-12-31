/*!
 * \name        interruptMode
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example shows how to use the interrupt functionality
 * \details     This example demonstrates how to detect motion and the direction
 *              of a moving object with the help of interrupts while the S2GO_RADAR_BGT60LTR11AIP
 *              shield is connected to a Raspberry Pi board using interrupts.
 * 
 *              Connection details:
 *              ----------------------------------------------------
 *              Pin on shield   Connected to pin on Raspberry Pi
 *              ----------------------------------------------------
 *              TD                      WiringPi 15 (header 8)
 *              PD                      WiringPi 16 (header 10)
 *              GND                     GND         (e.g. header 6)
 *              Vin                     3.3V        (e.g. header 1)
 *              ----------------------------------------------------
 * 
 *              Decoding on-board LED output of S2GO_RADAR_BGT60LTR11AIP shield:
 * 
 *              - Red LED indicates the output of direction of motion once target is detected (PD)
 *              ---------------------------------------------
 *              LED    State    Output explanation
 *              ---------------------------------------------
 *              Red     ON       Departing target
 *                      OFF      Approaching target
 *              ---------------------------------------------
 *
 *              - Green LED indicates the output of target in motion detection (TD)
 *              ---------------------------------------------
 *              LED    State    Output explanation
 *              ---------------------------------------------
 *              Green    ON       Moving target detected
 *                       OFF      No target detected
 *              ---------------------------------------------
 * 
 * SPDX-License-Identifier: MIT
 */

// Include library header
#include "bgt60-rpi.hpp"
#include <stdio.h>
#include <stdint.h>
#include <bcm2835.h>

using namespace bgt60rpi;

//  Define GPIO pins that will be connected to shield
#define TD  15
#define PD  16

/* Create radar object with following arguments:
 *  TD : Target Detect Pin
 *  PD : Phase Detect Pin
 *  Mode  : Set mode of acquiring sensor data as MODE_INTERRUPT */
Bgt60Rpi radarShield(TD, PD);

/* Definition and initialization of the interrupt active flag */
volatile static bool intActive = false;

void cBackFunct(void)
{
    if ( ! intActive ) {

        /* Set the interrupt active flag to avoid parallel execution of this function multiple times. */
        intActive = true;

        /* Create variables to store the state of the motion as well as the direction */
        Motion_t motion = NO_MOTION;
        Direction_t direction = NO_DIR;

        /* Now check what happend, first check if a motion was detected */
        Error_t err = radarShield.getMotion(motion);

        /* Check if API execution is successful */
        if(OK == err)
        {
            /* In case motion is detected */
            if(MOTION == motion){
                printf("Target in motion was detected!\n");

                /* Check the direction of the detected motion */
                err = radarShield.getDirection(direction);
                if(OK == err)
                {
                    /* In case the target is approaching */
                    if(APPROACHING == direction){
                        printf("The target is approaching!\n");
                    }
                    /* In case the target is departing */
                    else{
                        printf("The target is departing!\n");
                    }
                }
                /* API execution returned error */
                else{
                    printf("Error has occurred during the determination of the direction!\n");
                }
            }
            /* No motion is detected */
            else{
                printf("No target in motion detected!\n");
            }
        }
        /* API execution returned error */
        else{
            printf("Error has occurred during the determination of the direction!\n");
        }

        printf("\n--------------------------------------\n\n");

        /* Release the interrupt active flag to allow a new call of this callback function. */
        intActive = false;
    }
}

int main(int argc, char const *argv[])
{
    // Configures the GPIO pins to input mode
    Error_t init_status = radarShield.init();
    
    /* Check if the initialization was successful */
    if (OK != init_status) {
        printf("Init failed.\n");
        return 1;
    }
    else {
        printf("Init successful.\n");
    }

    /* Enable the interrupts */
    init_status = radarShield.enableInterrupt(cBackFunct);

    /* Check if the interrupt init was successful */
    if (OK != init_status) {
        printf("Interrupt init failed.\n");
        return 1;
    }
    else {
        printf("Interrupt init successful.\n");
    }

    while(true)
    {
        // Here you can do something else in parallel while waiting for an interrupt.
        delay(1000);
    }
}