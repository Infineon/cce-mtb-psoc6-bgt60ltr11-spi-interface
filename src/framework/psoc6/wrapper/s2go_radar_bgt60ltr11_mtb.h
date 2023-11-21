/**
 * @file        s2go_radar_bgt60ltr11_mtb.h
 * @author      Infineon Technologies AG
 * @brief       Radar S2GO_RADAR_BGT60LTR11 PSoC 6 API
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef S2GO_RADAR_BGT60LTR11_MTB_H_
#define S2GO_RADAR_BGT60LTR11_MTB_H_

#include <stdint.h>

#include "../../../corelib/xensiv_s2go_radar_bgt60ltr11_types.h"
#include "s2go_radar_bgt60ltr11_pal_mtb.h"

typedef  xensiv_s2go_radar_bgt60ltr11_motion_t    motion_t;
typedef  xensiv_s2go_radar_bgt60ltr11_direction_t direction_t;
typedef  xensiv_s2go_radar_bgt60ltr11_error_t     error_t;

#define S2GO_RADAR_BGT60LTR11_NUMBER_REGISTERS 						57
#define BIT_READ 											0
#define BIT_WRITE 											1

#define S2GO_RADAR_BGT60LTR11_REG_REG00								0u
#define S2GO_RADAR_BGT60LTR11_REG_REG01								1u
#define S2GO_RADAR_BGT60LTR11_REG_REG02								2u
#define S2GO_RADAR_BGT60LTR11_REG_REG03								3u	/* Reserved */
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1						4u
#define S2GO_RADAR_BGT60LTR11_REG_REG05_PLL_CFG2						5u
#define S2GO_RADAR_BGT60LTR11_REG_REG06_PLL_CFG3						6u
#define S2GO_RADAR_BGT60LTR11_REG_REG07								7u
#define S2GO_RADAR_BGT60LTR11_REG_REG08_DIV							8u
#define S2GO_RADAR_BGT60LTR11_REG_REG09_BB								9u
#define S2GO_RADAR_BGT60LTR11_REG_REG10_HOLDTIME						10u
#define S2GO_RADAR_BGT60LTR11_REG_REG11								11u  /* Reserved */
#define S2GO_RADAR_BGT60LTR11_REG_REG12								12u
#define S2GO_RADAR_BGT60LTR11_REG_REG13_ALGO1							13u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2							14u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL						15u
#define S2GO_RADAR_BGT60LTR11_REG_REG34_ADC0							34u
#define S2GO_RADAR_BGT60LTR11_REG_REG35_ADC1							35u
#define S2GO_RADAR_BGT60LTR11_REG_REG36_ADC_STAT						36u
#define S2GO_RADAR_BGT60LTR11_REG_REG38_ADC_RESULT						38u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES						55u
#define S2GO_RADAR_BGT60LTR11_REG_REG56_CHIP_STAT						56u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG0 */
#define S2GO_RADAR_BGT60LTR11_REG_REG00_RXBUF_EN_pos					0u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_RXBUF_EN_msk					0x0001u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_LNA_EN_pos						1u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_LNA_EN_msk						0x0002u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_MIXI_EN_pos					2u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_MIXI_EN_msk					0x0004u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_MIXQ_EN_pos					3u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_MIXQ_EN_msk					0x0008u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_TXBUF_EN_pos					4u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_TXBUF_EN_msk					0x0010u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_MPA_EN_pos						5u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_MPA_EN_msk						0x0020u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_PLL_EN_pos						8u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_PLL_EN_msk						0x0100u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_PLL_ACTIVE_pos					9u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_PLL_ACTIVE_msk					0x0200u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_PLL_CLK_GATE_EN_pos			10u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_PLL_CLK_GATE_EN_msk			0x0400u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_PLL_OPEN_LOOP_pos				11u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_PLL_OPEN_LOOP_msk				0x0800u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_VCO_EN_pos						12u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_VCO_EN_msk						0x1000u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_VCOBUF_EN_pos					13u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_VCOBUF_EN_msk					0x2000u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_CLEAR_ALL_pos					0u
#define S2GO_RADAR_BGT60LTR11_REG_REG00_CLEAR_ALL_msk					0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG01 */
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_SAMPLE_EN_pos				0u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_SAMPLE_EN_msk				0x0001u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_AMP_EN_pos					1u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_AMP_EN_msk					0x0002u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_STRUP_HP_pos				2u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_STRUP_HP_msk				0x0004u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_CLK_CHOP_EN_pos				4u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_CLK_CHOP_EN_msk				0x0010u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_BOOST_DIS_pos				5u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_BOOST_DIS_msk				0x0020u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_DIG_DET_EN_pos				7u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_BB_DIG_DET_EN_msk				0x0080u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_QS_RD_EN_pos					8u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_QS_RD_EN_msk					0x0100u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_DIV_BIAS_EN_pos				12u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_DIV_BIAS_EN_msk				0x1000u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_CLEAR_ALL_pos					0u
#define S2GO_RADAR_BGT60LTR11_REG_REG01_CLEAR_ALL_msk					0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG02 */
#define S2GO_RADAR_BGT60LTR11_REG_REG02_THRS_pos 						0u
#define S2GO_RADAR_BGT60LTR11_REG_REG02_THRS_msk 						0x1fffu
#define S2GO_RADAR_BGT60LTR11_REG_REG02_DIR_MODE_pos 					13u
#define S2GO_RADAR_BGT60LTR11_REG_REG02_DIR_MODE_msk 					0x2000u
#define S2GO_RADAR_BGT60LTR11_REG_REG02_APRT_pos						14u
#define S2GO_RADAR_BGT60LTR11_REG_REG02_APRT_msk 						0x4000u
#define S2GO_RADAR_BGT60LTR11_REG_REG02_HPRT_pos 						15u
#define S2GO_RADAR_BGT60LTR11_REG_REG02_HPRT_msk 						0x8000u
#define S2GO_RADAR_BGT60LTR11_REG_REG02_CLEAR_ALL_pos 					0u
#define S2GO_RADAR_BGT60LTR11_REG_REG02_CLEAR_ALL_msk 					0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG03 */
#define S2GO_RADAR_BGT60LTR11_REG_REG03_RESERVED_pos					0u
#define S2GO_RADAR_BGT60LTR11_REG_REG03_RESERVED_msk					0xffffu
#define S2GO_RADAR_BGT60LTR11_REG_REG03_CLEAR_ALL_pos					0u
#define S2GO_RADAR_BGT60LTR11_REG_REG03_CLEAR_ALL_msk					0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1 */
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_PFD_RDT_SEL_pos		0u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_PFD_RDT_SEL_msk		0x0003u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_CP_MODE_pos			2u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_CP_MODE_msk			0x0004u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_CP_ICP_SEL_pos		3u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_CP_ICP_SEL_msk		0x0038u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_FBDIV_CNT_pos			6u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_FBDIV_CNT_msk			0x0040u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_XOSC_MODE_pos			7u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_XOSC_MODE_msk			0x0080u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_LF_R2_SEL_pos			8u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_LF_R2_SEL_msk			0x0100u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_CL_LOOP_PMODE_pos		9u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_CL_LOOP_PMODE_msk		0x0200u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_LF_R4_SEL_pos			10u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_LF_R4_SEL_msk			0x0400u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_LF_ISO_pos			11u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_LF_ISO_msk			0x0800u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_BIAS_DIS_pos			12u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_BIAS_DIS_msk			0x1000u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_RESERVED_pos			13u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_RESERVED_msk			0x2000u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_DFT_DMUX_pos			14u
#define S2GO_RADAR_BGT60LTR11_REG_REG04_PLL_CFG1_DFT_DMUX_msk			0xc000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG05_PLL_CFG2 */
#define S2GO_RADAR_BGT60LTR11_REG_REG05_PLL_CFG2_FCW_pos				0u
#define S2GO_RADAR_BGT60LTR11_REG_REG05_PLL_CFG2_FCW_msk				0x0fffu

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG06_PLL_CFG3 */
#define S2GO_RADAR_BGT60LTR11_REG_REG06_PLL_CFG3_LD_EN_pos				11u
#define S2GO_RADAR_BGT60LTR11_REG_REG06_PLL_CFG3_LD_EN_msk				0x0800u
#define S2GO_RADAR_BGT60LTR11_REG_REG06_PLL_CFG3_LD_LEN_pos			12u
#define S2GO_RADAR_BGT60LTR11_REG_REG06_PLL_CFG3_LD_LEN_msk			0x1000u
#define S2GO_RADAR_BGT60LTR11_REG_REG06_PLL_CFG3_LD_TW_SEL_pos			13u
#define S2GO_RADAR_BGT60LTR11_REG_REG06_PLL_CFG3_LD_TW_SEL_msk			0xe000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG07 */
#define S2GO_RADAR_BGT60LTR11_REG_REG07_MPA_CTRL_pos					0u
#define S2GO_RADAR_BGT60LTR11_REG_REG07_MPA_CTRL_msk					0x0007u
#define S2GO_RADAR_BGT60LTR11_REG_REG07_PD_EN_pos						3u
#define S2GO_RADAR_BGT60LTR11_REG_REG07_PD_EN_msk						0x0008u
#define S2GO_RADAR_BGT60LTR11_REG_REG07_MPA2SH_DLY_pos					4u
#define S2GO_RADAR_BGT60LTR11_REG_REG07_MPA2SH_DLY_msk					0x0030u
#define S2GO_RADAR_BGT60LTR11_REG_REG07_VCO2PLL_DLY_pos				6u
#define S2GO_RADAR_BGT60LTR11_REG_REG07_VCO2PLL_DLY_msk				0x0040u
#define S2GO_RADAR_BGT60LTR11_REG_REG07_DC_ON_PULSE_LEN_pos			8u
#define S2GO_RADAR_BGT60LTR11_REG_REG07_DC_ON_PULSE_LEN_msk			0x0300u
#define S2GO_RADAR_BGT60LTR11_REG_REG07_DC_REP_RATE_pos				10u
#define S2GO_RADAR_BGT60LTR11_REG_REG07_DC_REP_RATE_msk				0x0c00u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG08_DIV */
#define S2GO_RADAR_BGT60LTR11_REG_REG08_DIV_TESTMODE_EN_pos			0u
#define S2GO_RADAR_BGT60LTR11_REG_REG08_DIV_TESTMODE_EN_msk			0x0001u
#define S2GO_RADAR_BGT60LTR11_REG_REG08_DIV_OUT_EN_pos					1u
#define S2GO_RADAR_BGT60LTR11_REG_REG08_DIV_OUT_EN_msk					0x0002u
#define S2GO_RADAR_BGT60LTR11_REG_REG08_DIV_SEL_pos					2u
#define S2GO_RADAR_BGT60LTR11_REG_REG08_DIV_SEL_msk					0x000cu
#define S2GO_RADAR_BGT60LTR11_REG_REG08_DIV_CLEAR_ALL_pos				0u
#define S2GO_RADAR_BGT60LTR11_REG_REG08_DIV_CLEAR_ALL_msk				0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG09_BB */
#define S2GO_RADAR_BGT60LTR11_REG_REG09_BB_CTRL_GAIN_pos				0u
#define S2GO_RADAR_BGT60LTR11_REG_REG09_BB_CTRL_GAIN_msk				0x000fu
#define S2GO_RADAR_BGT60LTR11_REG_REG09_BB_LPF_BW_pos					4u
#define S2GO_RADAR_BGT60LTR11_REG_REG09_BB_LPF_BW_msk					0x0010u
#define S2GO_RADAR_BGT60LTR11_REG_REG09_BB_CLK_CHOP_SEL_pos			5u
#define S2GO_RADAR_BGT60LTR11_REG_REG09_BB_CLK_CHOP_SEL_msk			0x0020u
#define S2GO_RADAR_BGT60LTR11_REG_REG09_BB_HP_RES_pos					6u
#define S2GO_RADAR_BGT60LTR11_REG_REG09_BB_HP_RES_msk					0x00c0u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG10_HOLDTIME */
#define S2GO_RADAR_BGT60LTR11_REG_REG10_HOLDTIME_HOLD_pos				0u
#define S2GO_RADAR_BGT60LTR11_REG_REG10_HOLDTIME_HOLD_msk				0xffffu
#define S2GO_RADAR_BGT60LTR11_REG_REG10_HOLDTIME_CLEAR_ALL_pos			0u
#define S2GO_RADAR_BGT60LTR11_REG_REG10_HOLDTIME_CLEAR_ALL_msk			0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG12_BB_BITE */
#define S2GO_RADAR_BGT60LTR11_REG_REG12_BB_BITE_BITE_EN_pos			0u
#define S2GO_RADAR_BGT60LTR11_REG_REG12_BB_BITE_BITE_EN_msk			0x0001u
#define S2GO_RADAR_BGT60LTR11_REG_REG12_BB_BITE_BITE_CTRL_pos			1u
#define S2GO_RADAR_BGT60LTR11_REG_REG12_BB_BITE_BITE_CTRL_msk			0x000eu
#define S2GO_RADAR_BGT60LTR11_REG_REG12_BB_BITE_BITE_PD_EN_pos			4u
#define S2GO_RADAR_BGT60LTR11_REG_REG12_BB_BITE_BITE_PD_EN_msk			0x0010u
#define S2GO_RADAR_BGT60LTR11_REG_REG12_BB_BITE_BB_AMUX_EN_pos			5u
#define S2GO_RADAR_BGT60LTR11_REG_REG12_BB_BITE_BB_AMUX_EN_msk			0x0020u
#define S2GO_RADAR_BGT60LTR11_REG_REG12_BB_BITE_BB_AMUX_CTRL_pos		6u
#define S2GO_RADAR_BGT60LTR11_REG_REG12_BB_BITE_BB_AMUX_CTRL_msk		0x00c0u
#define S2GO_RADAR_BGT60LTR11_REG_REG12_CLEAR_ALL_pos					0u
#define S2GO_RADAR_BGT60LTR11_REG_REG12_CLEAR_ALL_msk					0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG13_ALGO1 */
#define S2GO_RADAR_BGT60LTR11_REG_REG13_ALGO1_PRT_MULT_pos				0u
#define S2GO_RADAR_BGT60LTR11_REG_REG13_ALGO1_PRT_MULT_msk				0x0003u
#define S2GO_RADAR_BGT60LTR11_REG_REG13_ALGO1_MEAN_WIN_LEN_pos			2u
#define S2GO_RADAR_BGT60LTR11_REG_REG13_ALGO1_MEAN_WIN_LEN_msk			0x001cu
#define S2GO_RADAR_BGT60LTR11_REG_REG13_ALGO1_PHASE_WIN_LEN_pos		5u
#define S2GO_RADAR_BGT60LTR11_REG_REG13_ALGO1_PHASE_WIN_LEN_msk		0x00e0u
#define S2GO_RADAR_BGT60LTR11_REG_REG13_ALGO1_CLEAR_ALL_pos			0u
#define S2GO_RADAR_BGT60LTR11_REG_REG13_ALGO1_CLEAR_ALL_msk			0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2 */
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_PHASE_THRS_pos			0u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_PHASE_THRS_msk			0x0003u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_PULSE_MON_pos			2u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_PULSE_MON_msk			0x0004u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_AUTOBLIND_pos			3u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_AUTOBLIND_msk			0x0008u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_SWAP_IQ_pos				4u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_SWAP_IQ_msk				0x0010u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_HOLD_X32_pos				5u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_HOLD_X32_msk				0x0020u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_DIR_KEEP_pos				6u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_DIR_KEEP_msk				0x0040u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_DIR_HYST_DIS_pos			7u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_DIR_HYST_DIS_msk			0x0080u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_THRS_OFFSET_pos			8u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_THRS_OFFSET_msk			0xff00u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_CLEAR_ALL_pos			0u
#define S2GO_RADAR_BGT60LTR11_REG_REG14_ALGO2_CLEAR_ALL_msk			0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL */
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_STAT_MUX_pos			0u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_STAT_MUX_msk			0x000fu
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_DIR_POL_pos			4u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_DIR_POL_msk			0x0010u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_MOT_POL_pos			5u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_MOT_POL_msk			0x0020u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_MISO_DRV_pos			6u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_MISO_DRV_msk			0x0040u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_ADC_MOM_pos			7u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_ADC_MOM_msk			0x0080u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_FASTMODE_pos			8u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_FASTMODE_msk			0x0100u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_DIR_C2_1_pos			9u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_DIR_C2_1_msk			0x0600u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_FAST_PHASE_pos			11u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_FAST_PHASE_msk			0x0800u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_START_CW_pos			12u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_START_CW_msk			0x1000u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_CLK_EXT_DIS_pos		13u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_CLK_EXT_DIS_msk		0x2000u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_START_PM_pos			14u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_START_PM_msk			0x4000u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_SOFT_RESET_pos			15u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_SOFT_RESET_msk			0x8000u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_CLEAR_ALL_pos			0u
#define S2GO_RADAR_BGT60LTR11_REG_REG15_DIGCTRL_CLEAR_ALL_msk			0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG34_ADC0 */
#define S2GO_RADAR_BGT60LTR11_REG_REG34_ADC0_CLK_EN_pos				0u
#define S2GO_RADAR_BGT60LTR11_REG_REG34_ADC0_CLK_EN_msk				0x0001u
#define S2GO_RADAR_BGT60LTR11_REG_REG34_ADC0_BANDGAP_EN_pos			1u
#define S2GO_RADAR_BGT60LTR11_REG_REG34_ADC0_BANDGAP_EN_msk			0x0002u
#define S2GO_RADAR_BGT60LTR11_REG_REG34_ADC0_ADC_EN_pos				2u
#define S2GO_RADAR_BGT60LTR11_REG_REG34_ADC0_ADC_EN_msk				0x0004u
#define S2GO_RADAR_BGT60LTR11_REG_REG34_ADC0_CLEAR_ALL_pos				0u
#define S2GO_RADAR_BGT60LTR11_REG_REG34_ADC0_CLEAR_ALL_msk				0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG35_ADC1 */
#define S2GO_RADAR_BGT60LTR11_REG_REG35_ADC1_CH_NUM_pos				0u
#define S2GO_RADAR_BGT60LTR11_REG_REG35_ADC1_CH_NUM_msk				0x000fu
#define S2GO_RADAR_BGT60LTR11_REG_REG35_ADC1_CH_NUM_ALL_pos			4u
#define S2GO_RADAR_BGT60LTR11_REG_REG35_ADC1_CH_NUM_ALL_msk			0x0010u
#define S2GO_RADAR_BGT60LTR11_REG_REG35_ADC1_LV_GAIN_pos				7u
#define S2GO_RADAR_BGT60LTR11_REG_REG35_ADC1_LV_GAIN_msk				0x0080u
#define S2GO_RADAR_BGT60LTR11_REG_REG35_ADC1_CLEAR_ALL_pos				0u
#define S2GO_RADAR_BGT60LTR11_REG_REG35_ADC1_CLEAR_ALL_msk				0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG36_ADC_STAT */
#define S2GO_RADAR_BGT60LTR11_REG_REG36_ADC_STAT_BG_UP_pos				0u
#define S2GO_RADAR_BGT60LTR11_REG_REG36_ADC_STAT_BG_UP_msk				0x0001u
#define S2GO_RADAR_BGT60LTR11_REG_REG36_ADC_STAT_ADC_READY_pos			1u
#define S2GO_RADAR_BGT60LTR11_REG_REG36_ADC_STAT_ADC_READY_msk			0x0002u
#define S2GO_RADAR_BGT60LTR11_REG_REG36_ADC_STAT_CLEAR_ALL_pos			0u
#define S2GO_RADAR_BGT60LTR11_REG_REG36_ADC_STAT_CLEAR_ALL_msk			0x0000u

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG38_ADC_RESULT */
#define S2GO_RADAR_BGT60LTR11_REG_REG38_ADC_RESULT_pos					0u
#define S2GO_RADAR_BGT60LTR11_REG_REG38_ADC_RESULT_msk					0x03ffu

/* Fields of register S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES */
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_DIRECTION_OUTPUT_pos	0u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_DIRECTION_OUTPUT_msk	0x0001u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_ADAPTIVE_PRT_pos		1u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_ADAPTIVE_PRT_msk		0x0002u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_BB_HP_RES_pos			2u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_BB_HP_RES_msk			0x0004u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_BB_CTRL_GAIN_pos		3u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_BB_CTRL_GAIN_msk		0x0018u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_DC_REP_RATE_pos		5u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_DC_REP_RATE_msk		0x0020u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_DC_ON_PULSE_LEN_pos	6u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_DC_ON_PULSE_LEN_msk	0x0040u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_MPA_CTRL_pos			7u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_MPA_CTRL_msk			0x0180u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_LD_TW_SEL_pos		9u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_LD_TW_SEL_msk		0x0600u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_LD_LEN_pos			11u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_LD_LEN_msk			0x0800u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_LF_R4_SEL_pos		12u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_LF_R4_SEL_msk		0x1000u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_CP_ICP_SEL_pos		13u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_CP_ICP_SEL_msk		0x2000u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_CP_MODE_pos		14u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_CP_MODE_msk		0x4000u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_JAPAN_MODE_pos		15u
#define S2GO_RADAR_BGT60LTR11_REG_REG55_E_FUSES_PLL_JAPAN_MODE_msk		0x8000u

#define S2GO_RADAR_BGT60LTR11_SET(REGISTER, FIELD, X) \
    ((((unsigned short)(X) << S2GO_RADAR_BGT60LTR11_REG_##REGISTER##_##FIELD##_pos) \
      & S2GO_RADAR_BGT60LTR11_REG_##REGISTER##_##FIELD##_msk))


typedef enum
{
	det_thrs_66		= 66,
	det_thrs_80		= 80,
	det_thrs_90		= 90,
	det_thrs_112	= 112,
	det_thrs_136	= 136,
	det_thrs_192	= 192,
	det_thrs_248	= 248,
	det_thrs_320	= 320,
	det_thrs_384	= 384,
	det_thrs_480	= 480,
	det_thrs_640	= 640,
	det_thrs_896	= 896,
	det_thrs_1344	= 1344,
	det_thrs_1920	= 1920,
	det_thrs_2560	= 2560
} Reg02_detector_threshold_level_t;

typedef enum
{
	dir_mode_1	= 0,
	dir_mode_2	= 1
} Reg02_direction_detection_mode_t;

typedef enum
{
	aprt_off	= 0,
	aprt_on		= 1
} Reg02_adaptive_pulse_repetition_time_t;

typedef enum
{
	hprt_off	= 0,
	hprt_on		= 1
} Reg02_high_pulse_repetition_time_t;

typedef enum
{
	pfd_rst_dly_175ps	= 0,
	pfd_rst_dly_275ps	= 1,
	pfd_rst_dly_375ps	= 2,
	pfd_rst_dly_470ps	= 3
} Reg04_pfd_rst_dly_select_t;

typedef enum
{
	bias_regulation_loop_active	= 0,
	bias_regulation_loop_off	= 1
} Reg04_pll_cp_mode_t;

typedef enum
{
	charge_pump_current_20uA	= 0,
	charge_pump_current_25uA	= 1,
	charge_pump_current_30uA	= 2,
	charge_pump_current_35uA	= 3,
	charge_pump_current_40uA	= 4,
	charge_pump_current_45uA	= 5,
	charge_pump_current_50uA	= 6,
	charge_pump_current_55uA	= 7
} Reg04_charge_pump_current_t;

typedef enum
{
	feedback_divider_counter_21dec	= 0,	/* 38.4 MHz */
	feedback_divider_counter_20dec	= 1		/* 40 MHz */
} Reg04_pll_feedback_divider_counter_t;

typedef enum
{
	xosc_mode_amplitude_1	= 0,
	xosc_mode_amplitude_2	= 1
} Reg04_pll_xosc_mode_t;

typedef enum
{
	loopfilter_R2_21_6Kohm	= 0,
	loopfilter_R2_18_7Kohm	= 1
} Reg04_pll_loopfilter_R2_t;

typedef enum
{
	loopfilter_R4_12_4Kohm	= 0,
	loopfilter_R4_0_1Kohm	= 1
} Reg04_pll_loopfilter_R4_t;

typedef enum
{
	open_loop_pusled_mode	= 0,
	closed_loop_pusled_mode	= 1
} Reg04_pll_close_loop_pusled_mode_t;

typedef enum
{
	loopfilter_isolation_with_charge_keeping_buffer_enabled	= 0,
	loopfilter_isolation_with_switches_only					= 1
} Reg04_pll_loopfilter_isolation_t;

typedef enum
{
	biassing_on = 0,
	biassing_off = 1
} Reg04_pll_bias_dis_t;

typedef enum
{
	mux_functional_mode				= 0,
	pll_lock						= 1,
	reference_clock_divided_by_4	= 2,
	divider_clock_divided_by_4		= 3
} Reg04_pll_dft_dmux_t;

typedef enum
{
	frequency_60_6Ghz	= 0xea2,
	frequency_60_7Ghz	= 0xecc,
	frequency_60_8Ghz	= 0xef5,
	frequency_60_9Ghz	= 0xf1f,
	frequency_61_1Ghz	= 0xf72,
	frequency_61_2Ghz	= 0xf9c,
	frequency_61_25Ghz	= 0xfb0,
	frequency_61_3Ghz	= 0xfc6,
	frequency_61_4Ghz	= 0xfef
} Reg05_pll_frequency_word_t;


typedef enum
{
	lock_detection_off	= 0,
	lock_detection_on	= 1
} Reg06_pll_lock_detect_en_t;

typedef enum
{
	lock_detection_24_clock	= 0,
	lock_detection_16_clock	= 1
} Reg06_pll_lock_detect_len_t;

typedef enum
{
	lock_detection_time_window_0_26ns	= 0,
	lock_detection_time_window_0_5ns	= 1,
	lock_detection_time_window_1ns		= 2,
	lock_detection_time_window_1_5ns	= 3,
	lock_detection_time_window_2ns		= 4,
	lock_detection_time_window_2_8ns	= 5,
	lock_detection_time_window_3_8ns	= 6,
	lock_detection_time_window_4_6ns	= 7
} Reg06_pll_lock_detect_time_window_t;

typedef enum
{
	mpa_minus_34dBm		= 0,
	mpa_minus_31_5dBm	= 1,
	mpa_minus_25dBm		= 2,
	mpa_minus_18dBm		= 3,
	mpa_minus_11dBm		= 4,
	mpa_minus_5dBm		= 5,
	mpa_0dBm			= 6,
	mpa_4_5dBm			= 7
} Reg07_mpa_ctrl_t;

typedef enum
{
	pd_off	= 0,
	pd_on	= 1
} Reg07_pd_en_t;

typedef enum
{
	map_enable_to_sample_hold_delay_500ns	= 0,
	map_enable_to_sample_hold_delay_1000ns	= 1,
	map_enable_to_sample_hold_delay_2000ns	= 2,
	map_enable_to_sample_hold_delay_4000ns	= 3
} Reg07_mpa_2sh_dly_t;

typedef enum
{
	vco_to_pll_delay_500ns	= 0,
	vco_to_pll_delay_1000ns	= 1
} Reg07_vco_to_pll_delay_t;

typedef enum
{
	duty_cycle_on_pulse_5us		= 0,
	duty_cycle_on_pulse_10us	= 1,
	duty_cycle_on_pulse_20us	= 2,
	duty_cycle_on_pulse_40us	= 3
} Reg07_duty_cycle_on_pulse_length_t;

typedef enum
{
	duty_cycle_rep_250us	= 0,
	duty_cycle_rep_500us	= 1,
	duty_cycle_rep_1000us	= 2,
	duty_cycle_rep_2000us	= 3
} Reg07_duty_cycle_repetition_rate_t;

typedef enum
{
	internal_9_6Mhz_clock_out	= 0,
	divider_select_2_power_13	= 1,
	divider_select_2_power_16	= 2,
	divider_select_2_power_20	= 3
} Reg08_divider_select_t;

typedef enum
{
	baseband_PGA_gain_10dB	= 0,
	baseband_PGA_gain_15dB	= 1,
	baseband_PGA_gain_20dB	= 2,
	baseband_PGA_gain_25dB	= 3,
	baseband_PGA_gain_30dB	= 4,
	baseband_PGA_gain_35dB	= 5,
	baseband_PGA_gain_40dB	= 6,
	baseband_PGA_gain_45dB	= 7,
	baseband_PGA_gain_50dB	= 8,
} Reg09_baseband_ctrl_t;

typedef enum
{
	low_pass_filter_10kHz	= 0,
	low_pass_filter_60kHz	= 1
} Reg09_low_pass_filter_t;

typedef enum
{
	clock_chop_freq_100kHz	= 0,
	clock_chop_freq_200kHz	= 1
} Reg09_bb_clock_chop_freq_t;

typedef enum
{
	high_pass_filter_resistor_8Mohm	= 0,
	high_pass_filter_resistor_4Mohm	= 1,
	high_pass_filter_resistor_2Mohm	= 2,
	high_pass_filter_resistor_1Mohm	= 3
} Reg09_high_pass_filter_resistor_t;

typedef enum
{
	hold_time_minimum	= 0,
	hold_time_512msec	= 4,
	hold_time_1_024sec	= 8,
	hold_time_2_048sec 	= 16,
	hold_time_3_072sec	= 24,
	hold_time_5_1sec 	= 40,
	hold_time_10_11sec 	= 79,
	hold_time_20_08sec 	= 235,
	hold_time_40_05sec 	= 352,
	hold_time_60_032sec = 469,
	hold_time_90_112sec = 704,
	hold_time_2min 		= 938,
	hold_time_5min 		= 2345,
	hold_time_10min 	= 4690,
	hold_time_15min 	= 7035,
	hold_time_30_016min = 14070
} Reg10_hold_time_t;

typedef enum
{
	detector_hit_counter_10		= 0,
	detector_hit_counter_20		= 1,
	detector_hit_counter_40		= 2,
	detector_hit_counter_80		= 3
} Reg11_detector_hit_counter_t;

typedef enum
{
	detector_hit_counter_reset_10ms		= 0,
	detector_hit_counter_reset_50ms		= 1,
	detector_hit_counter_reset_100ms	= 2,
	detector_hit_counter_reset_200ms	= 3
} Reg11_detector_hit_counter_reset_t;

typedef enum
{
	detector_direction_as_same_as_detector_hit_counter			= 0,
	detector_direction_as_same_as_half_of_detector_hit_counter	= 1
} Reg11_detector_direction_hit_counter_t;


typedef enum
{
	dir_pol_tdet_low_when_departing		= 0,
	dir_pol_tdet_low_when_approaching	= 1
} Reg15_direction_polarity_t;

typedef enum
{
	mot_pol_tdet_active_low		= 0,
	mot_pol_tdet_active_high	= 1
} Reg15_motion_polarity_t;

typedef enum
{
	miso_drv_high_z		= 0,
	miso_drv_some_level	= 1
} Reg15_spi_force_miso_driver_t;

typedef enum
{
	fast_phase_start_when_target_detected	= 0,
	fast_phase_start_before_target_detected	= 1
} Reg15_spi_fast_mode_t;

typedef enum
{
	fastmode_spi_miso_changes_rising_edge	= 0,
	fastmode_spi_miso_changes_falling_edge	= 1
} Reg15_faster_phase_evaluation_t;

typedef enum
{
	start_cw_inactive	= 0,
	start_cw_active		= 1
} Reg15_start_cw_mode_t;

typedef enum
{
	clk_ext_not_disabled	= 0,
	clk_ext_disabled		= 1
} Reg15_start_pulsed_mode_t;

typedef enum
{
	start_pm_inactive	= 0,
	start_pm_active		= 1
} Reg15_disable_external_clock_t;

typedef enum
{
	soft_reset_inactive	= 0,
	soft_reset_active	= 1
} Reg15_soft_reset_t;

typedef struct
{
	Reg05_pll_frequency_word_t			output_frequency;
	Reg07_mpa_ctrl_t 					output_power;
	Reg07_pd_en_t 						pd;
	Reg07_mpa_2sh_dly_t 				map_enable_to_sample_hold_delay;
	Reg07_vco_to_pll_delay_t 			vco_to_pll_delay;
	Reg07_duty_cycle_on_pulse_length_t 	pulse_on_time;
	Reg07_duty_cycle_repetition_rate_t 	pulse_repetition_time;
	Reg09_baseband_ctrl_t 				baseband_gain;
	Reg09_low_pass_filter_t 			low_pass_filter;
	Reg09_bb_clock_chop_freq_t 			clock_chop_freq;
	Reg09_high_pass_filter_resistor_t 	high_pass_filter_resistor;
} S2GO_RADAR_BGT60LTR11_Config_t;

/**
 * @brief S2GO_RADAR_BGT60LTR11 radar object including PSoC6 HAL specialization
 */
typedef struct
{
    xensiv_s2go_radar_bgt60ltr11_t radar;
    mtb_s2go_radar_bgt60ltr11_gpio_t pal_gpio;
}mtb_s2go_radar_bgt60ltr11_t;

/**
 * @brief           Initialize the PSoC 6 GPIO for target and phase detection
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @param[in]       target_det Pin number of the target detect pin
 * @param[in]       phase_det Pin number of the phase detect pin
 * @return          S2GO_RADAR_BGT60LTR11 error code
 * @retval          OK always
 */
error_t     mtb_s2go_radar_bgt60ltr11_init(mtb_s2go_radar_bgt60ltr11_t* obj, cyhal_gpio_t phase_det, cyhal_gpio_t target_det, cyhal_gpio_t spi_miso, cyhal_gpio_t spi_mosi, cyhal_gpio_t spi_clk, cyhal_gpio_t spi_ss);


/**
 * @brief           De-Initialize the PSoC 6 GPIO for target and phase detection
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @retval          OK always
 */
error_t     mtb_s2go_radar_bgt60ltr11_deinit(mtb_s2go_radar_bgt60ltr11_t* obj);

/**
 * @brief           Read out target-detect-pin
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @param[in,out]   motion This variable stores the actual state of the target-detect-pin
 *                  Possible Values:
 *                      - NO_MOTION
 *                      - MOTION
 *
 * @return          S2GO_RADAR_BGT60LTR11 error code
 * @retval          OK always
 */
error_t     mtb_s2go_radar_bgt60ltr11_get_motion(mtb_s2go_radar_bgt60ltr11_t* obj, motion_t* motion);


/**
 * @brief           Read out target-detect-pin
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @param[in,out]   direction This variable stores the actual state of the phase-detect-pin
 *                  Possible Values:
 *                      - NO_DIR
 *                      - APPROACHING
 *                      - DEPARTING
 * @return          S2GO_RADAR_BGT60LTR11 error code
 * @retval          OK always
 */
error_t     mtb_s2go_radar_bgt60ltr11_get_direction(mtb_s2go_radar_bgt60ltr11_t* obj, direction_t* direction);


/**
 * @brief           Read out from register
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @param[in]   	reg_addr The register address of which the value needs to be read
 * @param[in,out]   data
 * @return          S2GO_RADAR_BGT60LTR11 error code
 * @retval			OK if success
 * @retval			Error if read failure
 */
error_t    	mtb_s2go_radar_bgt60ltr11_spi_read(mtb_s2go_radar_bgt60ltr11_t* obj, uint8_t reg_addr, uint16_t *data);


/**
 * @brief           Write register
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @param[in]   	reg_addr The register address of which the value needs to be written into
 * @param[in]		data data to be written into the register
 */
error_t    	mtb_s2go_radar_bgt60ltr11_spi_write(mtb_s2go_radar_bgt60ltr11_t* obj, uint8_t reg_addr, uint16_t data);


/**
 * @brief           Soft reset the radar MMIC
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @return          error code
 * @retval          ERROR if soft reset fails
 * @retval			OK if soft reset is successful
 */
error_t 	mtb_s2go_radar_bgt60ltr11_enable_soft_reset(mtb_s2go_radar_bgt60ltr11_t *obj);


//To be tested
/**
 * @brief           Set Radar Threshold value
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @param[in]		threshold Radar Threshold value (13 bit)
 * @return          error code
 * @retval          ERROR if the operation fails
 * @retval          OK if successful
 */
error_t 	mtb_s2go_radar_bgt60ltr11_threshold(mtb_s2go_radar_bgt60ltr11_t* obj, uint16_t threshold);


/**
 * @brief           Set Radar Frequency
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @param[in]		frequency Radar frequency value (12 bit)
 * @return          error code
 * @retval          ERROR if the operation fails
 * @retval          OK if successful
 */
error_t     mtb_s2go_radar_bgt60ltr11_frequency(mtb_s2go_radar_bgt60ltr11_t* obj, uint16_t frequency);


/**
 * @brief           Set Radar pulse repetition rate
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @param[in]		pulse_rep_rate Radar pulse repetition rate (2 bit)
 * @return          error code
 * @retval          ERROR if the operation fails
 * @retval          OK if successful
 */
error_t 	mtb_s2go_radar_bgt60ltr11_pulse_rep_rate(mtb_s2go_radar_bgt60ltr11_t* obj, uint8_t pulse_rep_rate);


/**
 * @brief           Set Radar pulse width
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @param[in]		pulse_width Pulse width (2 bit)
 * @return          error code
 * @retval          ERROR if the operation fails
 * @retval          OK if successful
 */
error_t 	mtb_s2go_radar_bgt60ltr11_pulse_width(mtb_s2go_radar_bgt60ltr11_t* obj, uint8_t pulse_width);


/**
 * @brief           Set Radar PGA gain
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @param[in]		PGA_gain Radar PGA gain (4 bit)
 * @return          error code
 * @retval          ERROR if the operation fails
 * @retval          OK if successful
 */
error_t 	mtb_s2go_radar_bgt60ltr11_PGA_gain(mtb_s2go_radar_bgt60ltr11_t* obj, uint8_t PGA_gain);


/**
 * @brief           Set Radar hold time
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @param[in]		hold_time Radar hold time (16 bit)
 * @return          error code
 * @retval          ERROR if the operation fails
 * @retval          OK if successful
 */
error_t 	mtb_s2go_radar_bgt60ltr11_hold_time(mtb_s2go_radar_bgt60ltr11_t* obj, uint16_t hold_time);


/**
 * @brief           gives whether target detected or not
 * @return          no return value
 */
void mtb_s2go_radar_bgt60ltr11_motion_detect();


/**
 * @brief           gives whether target is approaching or departing
 * @return          no return value
 */
void mtb_s2go_radar_bgt60ltr11_phase_detect();


/**
 * @brief           gives raw ADC values
 * @return          no return value
 */
void mtb_s2go_radar_bgt60ltr11_get_adc();


/**
 * @brief           gives status(ready/not ready) of ADC
 * @param[in]       obj Pointer to radar S2GO_RADAR_BGT60LTR11 object
 * @return          S2GO_RADAR_BGT60LTR11 error code
 * @retval          OK always
 */
error_t 	mtb_s2go_radar_bgt60ltr11_adc_status(mtb_s2go_radar_bgt60ltr11_t* obj);


#endif /** S2GO_RADAR_BGT60LTR11_MTB_H_ **/
