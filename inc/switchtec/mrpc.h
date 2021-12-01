/*
 * Microsemi Switchtec(tm) PCIe Management Library
 * Copyright (c) 2017, Microsemi Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef LIBSWITCHTEC_MRPC_H
#define LIBSWITCHTEC_MRPC_H

#define MRPC_MAX_DATA_LEN   1024

enum mrpc_cmd {
	MRPC_DIAG_PMC_START = 0x0,
	MRPC_TWI = 0x1,
	MRPC_VGPIO = 0x2,
	MRPC_PWM = 0x3,
	MRPC_DIETEMP = 0x4,
	MRPC_FWDNLD = 0x5,
	MRPC_FWLOGRD = 0x6,
	MRPC_PMON = 0x7,
	MRPC_PORTLN = 0x8,
	MRPC_PORTARB = 0x9,
	MRPC_MCOVRLY = 0xA,
	MRPC_STACKBIF = 0xB,
	MRPC_PORTPARTP2P = 0xC,
	MRPC_DIAG_TLP_INJECT = 0xD,
	MRPC_RESERVED1 = 0xE,
	MRPC_DIAG_PORT_EYE = 0xF,
	MRPC_DIAG_POT_VHIST = 0x10,
	MRPC_DIAG_PORT_LTSSM_LOG = 0x11,
	MRPC_DIAG_PORT_TLP_ANL = 0x12,
	MRPC_DIAG_PORT_LN_ADPT = 0x13,
	MRPC_SRDS_PCIE_PEAK = 0x14,
	MRPC_SRDS_EQ_CTRL = 0x15,
	MRPC_SRDS_LN_TUNING_MODE = 0x16,
	MRPC_NT_MCG_CAPABLE_CONFIG = 0x17,
	MRPC_TCH = 0x18,
	MRPC_ARB = 0x19,
	MRPC_SMBUS = 0x1A,
	MRPC_RESET = 0x1B,
	MRPC_LNKSTAT = 0x1C,
	MRPC_MULTI_CFG = 0x1D,
	MRPC_SES = 0x1E,
	MRPC_RD_FLASH = 0x1F,
	MRPC_SPI_ECC = 0x20,
	MRPC_PAT_GEN = 0x21,
	MRPC_INT_LOOPBACK = 0x22,
	MRPC_RESERVED2 = 0x24,
	MRPC_ROUTE_TO_SELF = 0x25,
	MRPC_REFCLK_S = 0x26,
	MRPC_SYNTH_EP = 0x27,
	MRPC_EVENTS_QUERY = 0x28,
	MRPC_GAS_READ = 0x29,
	MRPC_AER_GEN = 0x2A,
	MRPC_PART_INFO = 0x2B,
	MRPC_PCIE_GEN_1_2_DUMP = 0x2C,
	MRPC_PCIE_GEN_1_2_TUNE = 0x2D,
	MRPC_EYE_OBSERVE = 0x2F,
	MRPC_RCVR_OBJ_DUMP = 0x30,
	MRPC_RESERVED3 = 0x31,
	MRPC_PORT_EQ_STATUS = 0x32,
	MRPC_PORT_EQ_CTRL = 0x33,
	MRPC_GAS_WRITE = 0x34,
	MRPC_MRPC_ERR_INJ = 0x35,
	MRPC_DEV_INFO_GET = 0x36,
	MRPC_MRPC_PERM_TABLE_GET = 0x37,
	MRPC_CROSS_HAIR = 0x38,
	MRPC_RECV_DETECT_STATUS = 0x39,
	MRPC_EXT_RCVR_OBJ_DUMP = 0x3A,
	MRPC_LOG_DEF_GET = 0x3B,
	MRPC_SECURITY_CONFIG_GET_EXT = 0x3C,
	MRPC_ECHO = 0x41,

	MRPC_GET_PAX_ID = 0x81,
	MRPC_TOPO_INFO_DUMP = 0x82,
	MRPC_GFMS_DB_DUMP = 0x83,
	MRPC_GFMS_BIND_UNBIND = 0x84,
	MRPC_DEVICE_MANAGE_CMD = 0x85,
	MRPC_PORT_CONFIG = 0x88,
	MRPC_GFMS_EVENT = 0x89,
	MRPC_PORT_CONTROL = 0x8D,
	MRPC_EP_RESOURCE_ACCESS = 0x8E,
	MRPC_EP_TUNNEL_CFG = 0x8F,
	MRPC_NVME_ADMIN_PASSTHRU = 0x91,

	MRPC_I2C_TWI_PING = 0x100,
	MRPC_SECURITY_CONFIG_GET = 0x101,
	MRPC_SECURITY_CONFIG_SET = 0x102,
	MRPC_KMSK_ENTRY_SET = 0x103,
	MRPC_SECURE_STATE_SET = 0x104,
	MRPC_ACT_IMG_IDX_GET = 0x105,
	MRPC_ACT_IMG_IDX_SET = 0x106,
	MRPC_FW_TX = 0x107,
	MRPC_MAILBOX_GET = 0x108,
	MRPC_SN_VER_GET = 0x109,
	MRPC_DBG_UNLOCK = 0x10A,
	MRPC_BOOTUP_RESUME = 0x10B,
	MRPC_SECURITY_CONFIG_GET_GEN5 = 0x111,
	MRPC_SECURITY_CONFIG_SET_GEN5 = 0x112,
	MRPC_KMSK_ENTRY_SET_GEN5 = 0x113,
	MRPC_SECURE_STATE_SET_GEN5 = 0x114,
	MRPC_MAILBOX_GET_GEN5 = 0x118,
	MRPC_SN_VER_GET_GEN5 = 0x119,

	MRPC_MAX_ID = 0x140,
};

enum mrpc_bg_status {
	MRPC_BG_STAT_IDLE = 0,
	MRPC_BG_STAT_INPROGRESS = 1,
	MRPC_BG_STAT_DONE = 2,
	MRPC_BG_STAT_OFFSET = 3,
	MRPC_BG_STAT_ERROR = 0xFF,
};

enum mrpc_sub_cmd {
	MRPC_FWDNLD_GET_STATUS = 0,
	MRPC_FWDNLD_DOWNLOAD = 1,
	MRPC_FWDNLD_TOGGLE = 2,
	MRPC_FWDNLD_BOOT_RO = 4,
	MRPC_FWDNLD_SET_REDUNDANCY = 5,

        MRPC_PMON_SETUP_EV_COUNTER = 0,
        MRPC_PMON_GET_BW_COUNTER = 1,
	MRPC_PMON_GET_EV_COUNTER = 2,
	MRPC_PMON_GET_EV_COUNTER_SETUP = 3,
        MRPC_PMON_SETUP_LAT_COUNTER = 4,
	MRPC_PMON_GET_LAT_COUNTER_SETUP = 5,
	MRPC_PMON_GET_LAT_COUNTER = 6,
	MRPC_PMON_RULE_ERROR_TLP = 8,
	MRPC_PMON_RULE_TLP_MATCH = 9,
	MRPC_PMON_RULE_TLP_TO_USP = 10,
	MRPC_PMON_RULE_TLP_TO_DSP = 11,
	MRPC_PMON_SET_BW_COUNTER = 12,

	MRPC_FWLOGRD_RAM = 0,
	MRPC_FWLOGRD_FLASH = 1,
	MRPC_FWLOGRD_MEMLOG = 2,
	MRPC_FWLOGRD_REGS = 3,
	MRPC_FWLOGRD_SYS_STACK = 4,
	MRPC_FWLOGRD_THRD_STACK = 5,
	MRPC_FWLOGRD_THRD = 6,
	MRPC_FWLOGRD_INVAL = 7,
	MRPC_FWLOGRD_NVHDR = 10,
	MRPC_FWLOGRD_RAM_GEN5 = 11,
	MRPC_FWLOGRD_FLASH_GEN5 = 12,
	MRPC_FWLOGRD_RAM_WITH_FLAG = 13,
	MRPC_FWLOGRD_FLASH_WITH_FLAG = 14,

	MRPC_LOG_DEF_APP = 0,
	MRPC_LOG_DEF_MAILBOX = 1,

	MRPC_DIETEMP_SET_CLOCK = 0,
	MRPC_DIETEMP_SET_MEAS = 1,
	MRPC_DIETEMP_GET = 2,
	MRPC_DIETEMP_STOP = 3,
	MRPC_DIETEMP_GET_GEN4 = 2,

	MRPC_MULTI_CFG_SUPPORTED = 0,
	MRPC_MULTI_CFG_COUNT = 1,
	MRPC_MULTI_CFG_ACTIVE = 2,
	MRPC_MULTI_CFG_START_ADDR = 3,
	MRPC_MULTI_CFG_LENGTH = 4,

	MRPC_PORT_BIND = 0,
	MRPC_PORT_UNBIND = 1,
	MRPC_PORT_INFO = 2,

	MRPC_PART_INFO_GET_ALL_INFO = 0,
	MRPC_PART_INFO_GET_METADATA = 1,
	MRPC_PART_INFO_GET_SEEPROM = 2,

	MRPC_GFMS_BIND = 1,
	MRPC_GFMS_UNBIND = 2,

	MRPC_PORT_CONFIG_SET = 0,
	MRPC_PORT_CONFIG_GET = 1,

	MRPC_TOPO_INFO_DUMP_START = 1,
	MRPC_TOPO_INFO_DUMP_STATUS_GET = 2,
	MRPC_TOPO_INFO_DUMP_DATA_GET = 3,
	MRPC_TOPO_INFO_DUMP_FINISH = 4,

	MRPC_GFMS_DB_DUMP_FABRIC = 0,
	MRPC_GFMS_DB_DUMP_PAX_ALL,
	MRPC_GFMS_DB_DUMP_PAX,
	MRPC_GFMS_DB_DUMP_HVD,
	MRPC_GFMS_DB_DUMP_FAB_PORT,
	MRPC_GFMS_DB_DUMP_EP_PORT,
	MRPC_GFMS_DB_DUMP_HVD_DETAIL,

	MRPC_FW_TX_EXEC = 2,
	MRPC_FW_TX_FLASH = 3,
	MRPC_FW_TX_TOGGLE = 4,

	MRPC_DBG_UNLOCK_PKEY = 0,
	MRPC_DBG_UNLOCK_DATA = 1,
	MRPC_DBG_UNLOCK_UPDATE = 2,

	MRPC_KMSK_ENTRY_SET_PKEY = 0,
	MRPC_KMSK_ENTRY_SET_SIG = 1,
	MRPC_KMSK_ENTRY_SET_KMSK = 2,

	MRPC_EP_TUNNEL_ENABLE = 0,
	MRPC_EP_TUNNEL_DISABLE = 1,
	MRPC_EP_TUNNEL_STATUS = 2,

	MRPC_NVME_ADMIN_PASSTHRU_START = 1,
	MRPC_NVME_ADMIN_PASSTHRU_DATA = 2,
	MRPC_NVME_ADMIN_PASSTHRU_END = 3,

	MRPC_PORT_EQ_LOCAL_TX_COEFF_DUMP = 0,
	MRPC_PORT_EQ_FAR_END_TX_COEFF_DUMP = 1,
	MRPC_PORT_EQ_FAR_END_TX_EQ_TABLE_DUMP = 2,
	MRPC_PORT_EQ_LOCAL_TX_FSLF_DUMP = 3,
	MRPC_PORT_EQ_FAR_END_TX_FSLF_DUMP = 4,

	MRPC_EXT_RCVR_OBJ_DUMP_RCVR_EXT = 0,
	MRPC_EXT_RCVR_OBJ_DUMP_RCVR_EXT_PREV = 1,
	MRPC_EXT_RCVR_OBJ_DUMP_PREV = 2,
	MRPC_EXT_RCVR_OBJ_DUMP_LOCAL_TX_COEFF_PREV = 3,
	MRPC_EXT_RCVR_OBJ_DUMP_FAR_END_TX_COEFF_PREV = 4,
	MRPC_EXT_RCVR_OBJ_DUMP_EQ_TX_TABLE_PREV = 5,
	MRPC_EXT_RCVR_OBJ_DUMP_LOCAL_TX_FSLF_PREV = 6,
	MRPC_EXT_RCVR_OBJ_DUMP_FAR_END_TX_FSLF_PREV = 7,

	MRPC_REFCLK_S_DISABLE = 0,
	MRPC_REFCLK_S_ENABLE = 1,

	MRPC_LOOPBACK_GET_INT_LOOPBACK = 2,
	MRPC_LOOPBACK_SET_INT_LOOPBACK = 3,
	MRPC_LOOPBACK_SET_LTSSM_LOOPBACK = 4,
	MRPC_LOOPBACK_GET_LTSSM_LOOPBACK = 5,

	MRPC_PAT_GEN_GET_GEN = 5,
	MRPC_PAT_GEN_SET_GEN = 6,
	MRPC_PAT_GEN_GET_MON = 7,
	MRPC_PAT_GEN_SET_MON = 8,
	MRPC_PAT_GEN_INJ_ERR = 9,

	MRPC_EYE_OBSERVE_START = 0,
	MRPC_EYE_OBSERVE_FETCH = 1,
	MRPC_EYE_OBSERVE_CANCEL = 2,
	MRPC_EYE_OBSERVE_SET_DATA_MODE = 3,
	MRPC_EYE_OBSERVE_GET_DATA_MODE = 4,

	MRPC_CROSS_HAIR_ENABLE = 0,
	MRPC_CROSS_HAIR_DISABLE = 1,
	MRPC_CROSS_HAIR_GET = 2,
};

#endif
