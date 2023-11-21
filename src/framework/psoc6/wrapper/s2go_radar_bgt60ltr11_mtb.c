/**
 * @file        s2go_radar_bgt60ltr11_mtb.c
 * @author      Infineon Technologies AG
 * @brief       Radar S2GO_RADAR_BGT60LTR11 PSoC 6 API
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#include <xensiv_s2go_radar_bgt60ltr11.h>
#include "s2go_radar_bgt60ltr11_mtb.h"
#include "stdio.h"

error_t mtb_s2go_radar_bgt60ltr11_pulsed_mode_init(mtb_s2go_radar_bgt60ltr11_t* obj);

error_t  mtb_s2go_radar_bgt60ltr11_init(mtb_s2go_radar_bgt60ltr11_t* obj, cyhal_gpio_t phase_det,
		cyhal_gpio_t target_det, cyhal_gpio_t spi_miso, cyhal_gpio_t spi_mosi,
		cyhal_gpio_t spi_clk, cyhal_gpio_t spi_ss)
{
    error_t error;

    obj->radar.spi_transfer = NULL; 
    obj->radar.pd_read = &mtb_s2go_radar_bgt60ltr11_phase_read;
    obj->radar.td_read = &mtb_s2go_radar_bgt60ltr11_target_read;
    obj->radar.delay   = &mtb_s2go_radar_bgt60ltr11_delay;
    obj->radar.ctx    = &(obj->pal_gpio);

    error = mtb_s2go_radar_bgt60ltr11_gpio_init(&(obj->pal_gpio), phase_det, target_det);
    if(error != OK)
    {
        return INTF_ERROR;
    }

    if((spi_miso != NC) && (spi_mosi != NC) && (spi_clk != NC) && (spi_ss != NC))
    {

        obj->radar.spi_transfer = &mtb_s2go_radar_bgt60ltr11_spi_transfer;

        error = mtb_s2go_radar_bgt60ltr11_spi_init(&(obj->pal_gpio), spi_miso, spi_mosi, spi_clk, spi_ss);
        if(error != OK)
        {
            return INTF_ERROR;
        }

        error = mtb_s2go_radar_bgt60ltr11_pulsed_mode_init(obj);
        if(error != OK)
        {
            return INTF_ERROR;
        }
    }

    return OK;
}

error_t  mtb_s2go_radar_bgt60ltr11_get_motion(mtb_s2go_radar_bgt60ltr11_t* obj, motion_t* motion)
{
    *motion = xensiv_s2go_radar_bgt60ltr11_get_motion(&(obj->radar));
    return OK;
}

error_t  mtb_s2go_radar_bgt60ltr11_get_direction(mtb_s2go_radar_bgt60ltr11_t* obj, direction_t* direction)
{
    *direction = xensiv_s2go_radar_bgt60ltr11_get_direction(&(obj->radar));
    return OK;
}

error_t mtb_s2go_radar_bgt60ltr11_spi_read(mtb_s2go_radar_bgt60ltr11_t* obj, uint8_t reg_addr, uint16_t *data)
{
    
    return xensiv_s2go_radar_bgt60ltr11_spi_read(&(obj->radar), reg_addr, data);
    
}

error_t mtb_s2go_radar_bgt60ltr11_spi_write(mtb_s2go_radar_bgt60ltr11_t* obj, uint8_t reg_addr, uint16_t data)
{
    
    return xensiv_s2go_radar_bgt60ltr11_spi_write(&(obj->radar), reg_addr, data);
    
}

error_t mtb_s2go_radar_bgt60ltr11_enable_soft_reset(mtb_s2go_radar_bgt60ltr11_t* obj)
{

	error_t error;
	uint16_t data;
	uint16_t reg56;
	uint16_t reg0;

	error = mtb_s2go_radar_bgt60ltr11_spi_read(obj, 0x0F, &data);
	if(error != OK){
		return error;
	}
	data = data | 0x8000;
	CyDelay(1);

	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x0F, data);
	if(error != OK){
		return error;
	}

		for (volatile unsigned short i = 0; i<2048; i++)
		{
			error = mtb_s2go_radar_bgt60ltr11_spi_read(obj, 0x38, &reg56);
			if(error != OK){
				return error;
			}

			CyDelay(1);

			error = mtb_s2go_radar_bgt60ltr11_spi_read(obj, 0x00, &reg0);
			if(error != OK){
				return error;
			}

			if((reg0 == 0) && (reg56 & (1 << 13)))
			{
				break;
			}
		}

	return OK;
}

error_t mtb_s2go_radar_bgt60ltr11_threshold(mtb_s2go_radar_bgt60ltr11_t* obj, Reg02_detector_threshold_level_t threshold)
{
	error_t error;
	unsigned short spi_word;

	spi_word = 	S2GO_RADAR_BGT60LTR11_SET(REG02, THRS, threshold);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x02, spi_word);
	if(error != OK){
		return error;
	}
	return OK;
}

error_t mtb_s2go_radar_bgt60ltr11_frequency(mtb_s2go_radar_bgt60ltr11_t* obj, Reg05_pll_frequency_word_t frequency)
{
	error_t error;
	unsigned short spi_word;

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG05_PLL_CFG2, FCW, frequency);
		
		error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x05, spi_word);
		if(error != OK){
			return error;
		}
		return OK;
}

error_t mtb_s2go_radar_bgt60ltr11_pulse_rep_rate(mtb_s2go_radar_bgt60ltr11_t* obj, Reg07_duty_cycle_repetition_rate_t pulse_rep_rate)
{
	error_t error;
	unsigned short spi_word;

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG07, DC_REP_RATE, pulse_rep_rate);
			printf("Read value register 7 = %x\r\n", spi_word);
			error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x07, spi_word);

	if(error != OK){
		return error;
	}
	return OK;
}

error_t mtb_s2go_radar_bgt60ltr11_pulse_width(mtb_s2go_radar_bgt60ltr11_t* obj, Reg07_duty_cycle_on_pulse_length_t pulse_width)
{
	error_t error;
	unsigned short spi_word;
	
	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG07, DC_ON_PULSE_LEN, pulse_width);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x07, spi_word);
	if(error != OK){
		return error;
	}
	return OK;
}

error_t mtb_s2go_radar_bgt60ltr11_PGA_gain(mtb_s2go_radar_bgt60ltr11_t* obj, Reg09_baseband_ctrl_t PGA_gain)
{
	error_t error;
	unsigned short spi_word;
	
	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG09_BB, CTRL_GAIN, PGA_gain);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x09, spi_word);
	if(error != OK){
		return error;
	}
	return OK;
}

error_t mtb_s2go_radar_bgt60ltr11_hold_time(mtb_s2go_radar_bgt60ltr11_t* obj, Reg10_hold_time_t hold_time)
{
	error_t error;
	unsigned short spi_word;
	
	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG10_HOLDTIME, HOLD, hold_time);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x0A, spi_word);
	if(error != OK){
		return error;
	}
	return OK;
}

error_t mtb_s2go_radar_bgt60ltr11_pulsed_mode_init(mtb_s2go_radar_bgt60ltr11_t* obj)
{

	error_t error;
	unsigned short spi_word;
	uint16_t data;

	error =  mtb_s2go_radar_bgt60ltr11_enable_soft_reset(obj);
	if(error != OK){
		return error;
	}

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG00, CLEAR_ALL, 0);
	printf("Read value register 0 = %x\r\n", spi_word);
	error =  mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x00, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG01, CLEAR_ALL, 0);
	printf("Read value register 1 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x01, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);
	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG02, CLEAR_ALL, 0);
	spi_word = 	S2GO_RADAR_BGT60LTR11_SET(REG02, HPRT, hprt_off) |
			S2GO_RADAR_BGT60LTR11_SET(REG02, APRT, aprt_off) |
			S2GO_RADAR_BGT60LTR11_SET(REG02, DIR_MODE, dir_mode_2)|
			S2GO_RADAR_BGT60LTR11_SET(REG02, THRS, det_thrs_2560);
	printf("Read value register 2 = %x\r\n", spi_word);
	error =  mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x02, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG03, RESERVED, 0);
	printf("Read value register 3 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x03, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG04_PLL_CFG1, PFD_RDT_SEL, pfd_rst_dly_375ps) |
			   S2GO_RADAR_BGT60LTR11_SET(REG04_PLL_CFG1, CP_MODE, bias_regulation_loop_active) |
			   S2GO_RADAR_BGT60LTR11_SET(REG04_PLL_CFG1, CP_ICP_SEL, charge_pump_current_55uA) |
			   S2GO_RADAR_BGT60LTR11_SET(REG04_PLL_CFG1, FBDIV_CNT, feedback_divider_counter_21dec) |
			   S2GO_RADAR_BGT60LTR11_SET(REG04_PLL_CFG1, XOSC_MODE, xosc_mode_amplitude_1) |
			   S2GO_RADAR_BGT60LTR11_SET(REG04_PLL_CFG1, LF_R2_SEL, loopfilter_R2_18_7Kohm) |
			   S2GO_RADAR_BGT60LTR11_SET(REG04_PLL_CFG1, CL_LOOP_PMODE, closed_loop_pusled_mode) |
			   S2GO_RADAR_BGT60LTR11_SET(REG04_PLL_CFG1, LF_R4_SEL, loopfilter_R4_0_1Kohm) |
			   S2GO_RADAR_BGT60LTR11_SET(REG04_PLL_CFG1, LF_ISO, loopfilter_isolation_with_switches_only) |
			   S2GO_RADAR_BGT60LTR11_SET(REG04_PLL_CFG1, BIAS_DIS, biassing_on) |
			   S2GO_RADAR_BGT60LTR11_SET(REG04_PLL_CFG1, DFT_DMUX, mux_functional_mode);
	printf("Read value register 4 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x04, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG05_PLL_CFG2, FCW, frequency_61_25Ghz);
	printf("Read value register 5 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x05, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG06_PLL_CFG3, LD_EN, lock_detection_on) |
			   S2GO_RADAR_BGT60LTR11_SET(REG06_PLL_CFG3, LD_LEN, lock_detection_24_clock) |
			   S2GO_RADAR_BGT60LTR11_SET(REG06_PLL_CFG3, LD_TW_SEL, lock_detection_time_window_1_5ns);
	printf("Read value register 6 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x06, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG07, MPA_CTRL, mpa_4_5dBm) |
			   S2GO_RADAR_BGT60LTR11_SET(REG07, PD_EN, pd_off) |
			   S2GO_RADAR_BGT60LTR11_SET(REG07, MPA2SH_DLY, map_enable_to_sample_hold_delay_1000ns) |
			   S2GO_RADAR_BGT60LTR11_SET(REG07, VCO2PLL_DLY, vco_to_pll_delay_1000ns) |
			   S2GO_RADAR_BGT60LTR11_SET(REG07, DC_ON_PULSE_LEN, duty_cycle_on_pulse_10us) |
			   S2GO_RADAR_BGT60LTR11_SET(REG07, DC_REP_RATE, duty_cycle_rep_500us);
	printf("Read value register 7 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x07, spi_word);

	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG08_DIV, OUT_EN, 1) |
			   S2GO_RADAR_BGT60LTR11_SET(REG08_DIV, SEL, divider_select_2_power_20);
	printf("Read value register 8 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x08, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG09_BB, CTRL_GAIN, baseband_PGA_gain_50dB) |
			   S2GO_RADAR_BGT60LTR11_SET(REG09_BB, LPF_BW, low_pass_filter_10kHz) |
			   S2GO_RADAR_BGT60LTR11_SET(REG09_BB, CLK_CHOP_SEL, clock_chop_freq_200kHz) |
			   S2GO_RADAR_BGT60LTR11_SET(REG09_BB, HP_RES, high_pass_filter_resistor_1Mohm);
	printf("Read value register 9 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x09, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG10_HOLDTIME, HOLD, hold_time_10_11sec);
	printf("Read value register 10 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x0A, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG12, CLEAR_ALL, 0);
	printf("Read value register 12 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x0C, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG13_ALGO1, CLEAR_ALL, 0);
	printf("Read value register 13 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x0D, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG14_ALGO2, CLEAR_ALL, 0);
	printf("Read value register 14 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x0E, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG15_DIGCTRL, START_PM, start_pm_inactive);
	printf("Read value register 15 = %x\r\n", spi_word);
	error =  mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x0F, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG34_ADC0, CLEAR_ALL, 0);
	printf("Read value register 34 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x22, 0x0000);
	if(error != OK){
		return error;
	}
	CyDelay(1);


	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG35_ADC1, CLEAR_ALL, 0);
	printf("Read value register 35 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x23, 0x0000);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG36_ADC_STAT, CLEAR_ALL, 0);
	printf("Read value register 36 = %x\r\n", spi_word);
	error = mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x24, 0x0000);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	spi_word = S2GO_RADAR_BGT60LTR11_SET(REG15_DIGCTRL, START_PM, start_pm_active);
	printf("Read value register 15 = %x\r\n", spi_word);
	error =  mtb_s2go_radar_bgt60ltr11_spi_write(obj, 0x0F, spi_word);
	if(error != OK){
		return error;
	}
	CyDelay(1);

	return OK;
}

/* ADC status */
error_t mtb_s2go_radar_bgt60ltr11_adc_status(mtb_s2go_radar_bgt60ltr11_t* obj)
{
	error_t error;

	unsigned short spi_word;

	error= mtb_s2go_radar_bgt60ltr11_spi_read(obj, 0x24, &spi_word);
	printf("Read value register 36= %x\r\n", spi_word);

	if(error != OK){
		return error;
	}
	return OK;
}


error_t  mtb_s2go_radar_bgt60ltr11_deinit(mtb_s2go_radar_bgt60ltr11_t* obj)
{
    return mtb_s2go_radar_bgt60ltr11_gpio_deinit(&(obj->pal_gpio));
}
