/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the PSoC 6: S2GO_RADAR_BGT60LTR11 Radar Application
*              for ModusToolbox.
* Link to S2GO RADAR S2GO_RADAR_BGT60LTR11: https://www.infineon.com/cms/en/product/evaluation-boards/s2go-radar-s2go_radar_bgt60ltr11/
*
* Related Document: See README.md
*
*
*******************************************************************************
* (c) 2023, Infineon Technologies. All rights reserved.
*******************************************************************************/

#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "s2go_radar_bgt60ltr11_mtb.h"

/*******************************************************************************
* Macros
********************************************************************************/
#define DIRECTION_DETECT    0
#define MOTION_DETECT       1
#define CURRENT_EXAMPLE     MOTION_DETECT
//#define CURRENT_EXAMPLE     ADC

#define phase_detect_pin    P9_0                /* Phase detect pin on PSoC 6 */
#define target_detect_pin   P9_1                /* Target detect pin on PSoC 6 */
#define spi_mosi_pin		P10_0				/* MOSI pin on PSoC 6 */
#define spi_miso_pin		P10_1				/* MISO pin on PSoC 6 */
#define spi_clk_pin			P10_2				/* CLK pin on PSoC 6 */
#define spi_cs_pin			P10_3				/* CS pin on PSoC 6 */

/********************************************************************************
* Function Name: main
*********************************************************************************
* Summary:
* The main function performs the following actions:
*  1. Initializes the BSP
*  2. Calls the functions to configure and initialize retarget IO
*  3. Initializes the S2GO_RADAR_BGT60LTR11 Radar Library
*  4. Demonstrates the procedure to detect motion and direction of the target
*     based on the example selected
*
*********************************************************************************/
int main(void)
{
    cy_rslt_t result;

    error_t error_status;

    mtb_s2go_radar_bgt60ltr11_t s2go_radar_bgt60ltr11_obj;

    uint16_t rddata;

    motion_t motion = NO_MOTION;

    direction_t direction = NO_DIR;

    /* Initialize the device and board peripherals */
    result = cybsp_init() ;
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    __enable_irq();

    /* Initialize retarget-io to use the debug UART port */
    result = cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX,
                                 CY_RETARGET_IO_BAUDRATE);

    /* retarget-io initialization failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* \x1b[2J\x1b[;H - ANSI ESC sequence to clear screen */
    printf("\x1b[2J\x1b[;H");
    printf("***************************************************************\r\n");
    printf("S2GO RADAR BGT60LTR11 SPI mode using PSoC 6 MCU\r\n");
    printf("***************************************************************\r\n\n");

    error_status = mtb_s2go_radar_bgt60ltr11_init(&s2go_radar_bgt60ltr11_obj, phase_detect_pin, target_detect_pin,
    		spi_miso_pin, spi_mosi_pin, spi_clk_pin, spi_cs_pin);

    if(error_status != OK)
    {
        printf("ERROR: Initialization failed\r\n");
        CY_ASSERT(0);
    }
    else
    {
    	printf("Initialization successful\r\n");
    }
    mtb_s2go_radar_bgt60ltr11_delay(10);

    /* Reading the Chip ID register */
    for (int i=0; i<=20;i++)
    {
	error_status = mtb_s2go_radar_bgt60ltr11_spi_read(&s2go_radar_bgt60ltr11_obj, 0x38, &rddata);
    if(error_status == OK)
    {
    	printf("Register 56 Read value = %x\r\n", rddata);
    }
    else
    {
    	printf("SPI Register Read Failed\r\n");
    }
    mtb_s2go_radar_bgt60ltr11_delay(10);
    }

    /* API testing(configuring various parameters) */
    error_status = mtb_s2go_radar_bgt60ltr11_threshold(&s2go_radar_bgt60ltr11_obj, 2560);
    if(error_status == OK)
    {
       	printf("Threshold set successfully \r\n");
    }
    else
    {
        printf("Failed\r\n");
    }

    error_status = mtb_s2go_radar_bgt60ltr11_hold_time(&s2go_radar_bgt60ltr11_obj, 4);
    if(error_status == OK)
    {
        printf("Hold time set successfully \r\n");
    }
    else
    {
      	printf("Failed\r\n");
    }

    error_status = mtb_s2go_radar_bgt60ltr11_frequency(&s2go_radar_bgt60ltr11_obj, frequency_61_25Ghz);
	if(error_status == OK)
	{
		printf("Frequency set successfully \r\n");
	}
	else
	{
	 	printf("Failed\r\n");
    }

	error_status = mtb_s2go_radar_bgt60ltr11_PGA_gain(&s2go_radar_bgt60ltr11_obj, baseband_PGA_gain_50dB);
	if(error_status == OK)
    {
	  	printf("PGA gain set successfully \r\n");
    }
	else
	{
		printf("Failed\r\n");
	}

/********************************************************************************
* Application Specific Functions
*********************************************************************************
*
* The following function performs the following actions:
* 01. mtb_s2go_radar_bgt60ltr11_motion_detect() -> detects the Presence/absence state of target.
* 02. mtb_s2go_radar_bgt60ltr11_phase_detect()  -> detects the relative direction of motion of
*     target w.r.t. each other. i.e static, approaching, Departing.
* 03. mtb_s2go_radar_bgt60ltr11_get_adc()       -> to get raw data (ADC) values.
*
*********************************************************************************/
	//Phase(direction) detection function
	void mtb_s2go_radar_bgt60ltr11_phase_detect()
	{
		while(1)
		{
			error_status = mtb_s2go_radar_bgt60ltr11_get_direction(&s2go_radar_bgt60ltr11_obj, &direction);

			if(error_status == OK)
			{
				switch (direction)
				{
					case NO_DIR:
					printf("No direction due to no motion!\r\n");
					break;

					case APPROACHING:
					printf("Target approaching!\r\n");
					break;

						case DEPARTING:
						printf("Target Departing!\r\n");
						break;
				}
			}
			else
			{
					printf("Error occurred in determining the direction.\r\n");
			}
		}
	}

	//Motion detection function
	void mtb_s2go_radar_bgt60ltr11_motion_detect()
	{
		while(1)
		{
			error_status = mtb_s2go_radar_bgt60ltr11_get_motion(&s2go_radar_bgt60ltr11_obj, &motion);

			if(error_status == OK)
			{
				switch (motion)
				{
			   		case MOTION:
			   		printf("Target in motion detected!\r\n");
			   		mtb_s2go_radar_bgt60ltr11_phase_detect();
			   		break;

			   		case NO_MOTION:
			   		printf("No target in motion detected!\r\n");
			   		break;
				}
			}
			else
			{
				printf("Error occurred in detecting the motion of the target.\r\n");
			}
		}
	}

	//Raw-data(internal ADC) values
	//Function below gives internal ADC raw data values
	void mtb_s2go_radar_bgt60ltr11_get_adc()
	{
		error_status = mtb_s2go_radar_bgt60ltr11_adc_status(&s2go_radar_bgt60ltr11_obj);

		if(error_status == OK)
		{
			printf("ADC is ready\r\n");

			while(1)
			{
				uint16_t if_i;
				uint16_t if_q;

				mtb_s2go_radar_bgt60ltr11_spi_read(&s2go_radar_bgt60ltr11_obj, 0x28, &if_i);
				printf("ADC value in Reg 40 is %d \r\n", if_i);

				mtb_s2go_radar_bgt60ltr11_spi_read(&s2go_radar_bgt60ltr11_obj, 0x29, &if_q);
				printf("ADC value in Reg 41 is %d \r\n", if_q);

				CyDelay(1);   //delay in milli-seconds
			}
		}
		else
		{
			printf("ADC is not ready\r\n");
		}
	}

/********************************************************************************
 * Based on the input to macro CURRENT EXAMPLE (MOTION_DETECT or else), get
 * corresponding output on the console window.
 * 01. if, CURRENT EXAMPLE MOTION_DETECT - Gives the state of object whether it is
 * 	  stationary or in motion and the direction (Approaching or departing).
 * 02. else, Provide internal ADC raw data values.
 *
 * NOTE: Reset the MCU every-time to change the output mode.
*********************************************************************************/
	for(;;)
		{
			#if CURRENT_EXAMPLE == MOTION_DETECT
				mtb_s2go_radar_bgt60ltr11_motion_detect();
			#else
				mtb_s2go_radar_bgt60ltr11_get_adc();
			#endif
		}

}
/* End of file */
