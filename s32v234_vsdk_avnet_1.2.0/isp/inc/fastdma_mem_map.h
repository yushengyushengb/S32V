/*
 * Copyright (c) 2005-2016 Freescale Semiconductor
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FASTDMAMEMMAP_H
#define FASTDMAMEMMAP_H

/*****************************************************************
*
* FDMA Registers
*
******************************************************************/




/* Instance FDMA */

#define FDMA_BASEADDRESS               0x40020000

/* Register definitions */

/* 0 */
#define FDMA_XFR_REC_LIST_PTR_OFF 0x00000000
#define FDMA_XFR_REC_LIST_PTR          (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_XFR_REC_LIST_PTR_OFF))
#define FDMA_X_XFR_REC_LIST_PTR(x)     (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_XFR_REC_LIST_PTR_OFF + ((x)*0x0)))

#define FDMA_XFR_REC_LIST_PTR_RESET_VALUE 0x00000000
#define FDMA_XFR_REC_LIST_PTR_VOLATILE 0x0
#define FDMA_XFR_REC_LIST_PTR_BITFIELD_MASK 0xFFFFFFFF
#define FDMA_XFR_REC_LIST_PTR_RWMASK   0xFFFFFFFF
#define FDMA_XFR_REC_LIST_PTR_ROMASK   0x00000000
#define FDMA_XFR_REC_LIST_PTR_WOMASK   0x00000000
#define FDMA_XFR_REC_LIST_PTR_UNUSED_MASK 0x00000000

/* 0 */
#define FDMA_CALC_CRC_VAL_OFF 0x0000001C
#define FDMA_CALC_CRC_VAL              (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_CALC_CRC_VAL_OFF))
#define FDMA_X_CALC_CRC_VAL(x)         (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_CALC_CRC_VAL_OFF + ((x)*0x0)))

#define FDMA_CALC_CRC_VAL_RESET_VALUE  0x00000000
#define FDMA_CALC_CRC_VAL_VOLATILE     0x0
#define FDMA_CALC_CRC_VAL_BITFIELD_MASK 0xFFFFFFFF
#define FDMA_CALC_CRC_VAL_RWMASK       0x00000000
#define FDMA_CALC_CRC_VAL_ROMASK       0xFFFFFFFF
#define FDMA_CALC_CRC_VAL_WOMASK       0x00000000
#define FDMA_CALC_CRC_VAL_UNUSED_MASK  0x00000000

/* 0 */
#define FDMA_XFR_REC_CNT_OFF 0x00000004
#define FDMA_XFR_REC_CNT               (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_XFR_REC_CNT_OFF))
#define FDMA_X_XFR_REC_CNT(x)          (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_XFR_REC_CNT_OFF + ((x)*0x0)))

#define FDMA_XFR_REC_CNT_RESET_VALUE   0x00000000
#define FDMA_XFR_REC_CNT_VOLATILE      0x0
#define FDMA_XFR_REC_CNT_BITFIELD_MASK 0x0000007F
#define FDMA_XFR_REC_CNT_RWMASK        0x0000007F
#define FDMA_XFR_REC_CNT_ROMASK        0x00000000
#define FDMA_XFR_REC_CNT_WOMASK        0x00000000
#define FDMA_XFR_REC_CNT_UNUSED_MASK   0xFFFFFF80

/* 0 */
#define FDMA_XFR_LINE_NUM_OFF 0x0000000C
#define FDMA_XFR_LINE_NUM              (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_XFR_LINE_NUM_OFF))
#define FDMA_X_XFR_LINE_NUM(x)         (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_XFR_LINE_NUM_OFF + ((x)*0x0)))

#define FDMA_XFR_LINE_NUM_RESET_VALUE  0x00000000
#define FDMA_XFR_LINE_NUM_VOLATILE     0x0
#define FDMA_XFR_LINE_NUM_BITFIELD_MASK 0xFFFFFFFF
#define FDMA_XFR_LINE_NUM_RWMASK       0xFFFFFFFF
#define FDMA_XFR_LINE_NUM_ROMASK       0x00000000
#define FDMA_XFR_LINE_NUM_WOMASK       0x00000000
#define FDMA_XFR_LINE_NUM_UNUSED_MASK  0x00000000

/* 0 */
#define FDMA_LINE_INCR_OFF 0x00000010
#define FDMA_LINE_INCR                 (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_LINE_INCR_OFF))
#define FDMA_X_LINE_INCR(x)            (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_LINE_INCR_OFF + ((x)*0x0)))

#define FDMA_LINE_INCR_RESET_VALUE     0x00000000
#define FDMA_LINE_INCR_VOLATILE        0x0
#define FDMA_LINE_INCR_BITFIELD_MASK   0x00FF00FF
#define FDMA_LINE_INCR_RWMASK          0x00FF00FF
#define FDMA_LINE_INCR_ROMASK          0x00000000
#define FDMA_LINE_INCR_WOMASK          0x00000000
#define FDMA_LINE_INCR_UNUSED_MASK     0xFF00FF00

/* 0 */
#define FDMA_XFR_STAT_OFF 0x00000018
#define FDMA_XFR_STAT                  (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_XFR_STAT_OFF))
#define FDMA_X_XFR_STAT(x)             (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_XFR_STAT_OFF + ((x)*0x0)))

#define FDMA_XFR_STAT_RESET_VALUE      0x00000001
#define FDMA_XFR_STAT_VOLATILE         0x0
#define FDMA_XFR_STAT_BITFIELD_MASK    0xFF0101FF
#define FDMA_XFR_STAT_RWMASK           0x00000000
#define FDMA_XFR_STAT_ROMASK           0xFF0101FF
#define FDMA_XFR_STAT_WOMASK           0x00000000
#define FDMA_XFR_STAT_UNUSED_MASK      0x00FEFE00

/* 0 */
#define FDMA_CURR_SRAM_PTR_OFF 0x00000024
#define FDMA_CURR_SRAM_PTR             (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_CURR_SRAM_PTR_OFF))
#define FDMA_X_CURR_SRAM_PTR(x)        (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_CURR_SRAM_PTR_OFF + ((x)*0x0)))

#define FDMA_CURR_SRAM_PTR_RESET_VALUE 0x00000000
#define FDMA_CURR_SRAM_PTR_VOLATILE    0x0
#define FDMA_CURR_SRAM_PTR_BITFIELD_MASK 0xFFFFFFFF
#define FDMA_CURR_SRAM_PTR_RWMASK      0x00000000
#define FDMA_CURR_SRAM_PTR_ROMASK      0xFFFFFFFF
#define FDMA_CURR_SRAM_PTR_WOMASK      0x00000000
#define FDMA_CURR_SRAM_PTR_UNUSED_MASK 0x00000000

/* 0 */
#define FDMA_XFR_QUEUE_DEPTH_OFF 0x00000014
#define FDMA_XFR_QUEUE_DEPTH           (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_XFR_QUEUE_DEPTH_OFF))
#define FDMA_X_XFR_QUEUE_DEPTH(x)      (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_XFR_QUEUE_DEPTH_OFF + ((x)*0x0)))

#define FDMA_XFR_QUEUE_DEPTH_RESET_VALUE 0x00000010
#define FDMA_XFR_QUEUE_DEPTH_VOLATILE  0x0
#define FDMA_XFR_QUEUE_DEPTH_BITFIELD_MASK 0x0000001F
#define FDMA_XFR_QUEUE_DEPTH_RWMASK    0x0000001F
#define FDMA_XFR_QUEUE_DEPTH_ROMASK    0x00000000
#define FDMA_XFR_QUEUE_DEPTH_WOMASK    0x00000000
#define FDMA_XFR_QUEUE_DEPTH_UNUSED_MASK 0xFFFFFFE0

/* 0 */
#define FDMA_CURR_DDR_PTR_OFF 0x00000020
#define FDMA_CURR_DDR_PTR              (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_CURR_DDR_PTR_OFF))
#define FDMA_X_CURR_DDR_PTR(x)         (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_CURR_DDR_PTR_OFF + ((x)*0x0)))

#define FDMA_CURR_DDR_PTR_RESET_VALUE  0x00000000
#define FDMA_CURR_DDR_PTR_VOLATILE     0x0
#define FDMA_CURR_DDR_PTR_BITFIELD_MASK 0xFFFFFFFF
#define FDMA_CURR_DDR_PTR_RWMASK       0x00000000
#define FDMA_CURR_DDR_PTR_ROMASK       0xFFFFFFFF
#define FDMA_CURR_DDR_PTR_WOMASK       0x00000000
#define FDMA_CURR_DDR_PTR_UNUSED_MASK  0x00000000

/* 0 */
#define FDMA_XFR_REC_NUM_DONE_OFF 0x00000028
#define FDMA_XFR_REC_NUM_DONE          (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_XFR_REC_NUM_DONE_OFF))
#define FDMA_X_XFR_REC_NUM_DONE(x)     (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_XFR_REC_NUM_DONE_OFF + ((x)*0x0)))

#define FDMA_XFR_REC_NUM_DONE_RESET_VALUE 0x00000000
#define FDMA_XFR_REC_NUM_DONE_VOLATILE 0x0
#define FDMA_XFR_REC_NUM_DONE_BITFIELD_MASK 0x0000007F
#define FDMA_XFR_REC_NUM_DONE_RWMASK   0x00000000
#define FDMA_XFR_REC_NUM_DONE_ROMASK   0x0000007F
#define FDMA_XFR_REC_NUM_DONE_WOMASK   0x00000000
#define FDMA_XFR_REC_NUM_DONE_UNUSED_MASK 0xFFFFFF80

/* 0 */
#define FDMA_XFR_REC_NUM_OFF 0x00000008
#define FDMA_XFR_REC_NUM               (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_XFR_REC_NUM_OFF))
#define FDMA_X_XFR_REC_NUM(x)          (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_XFR_REC_NUM_OFF + ((x)*0x0)))

#define FDMA_XFR_REC_NUM_RESET_VALUE   0x00000000
#define FDMA_XFR_REC_NUM_VOLATILE      0x0
#define FDMA_XFR_REC_NUM_BITFIELD_MASK 0x0000007F
#define FDMA_XFR_REC_NUM_RWMASK        0x0000007F
#define FDMA_XFR_REC_NUM_ROMASK        0x00000000
#define FDMA_XFR_REC_NUM_WOMASK        0x00000000
#define FDMA_XFR_REC_NUM_UNUSED_MASK   0xFFFFFF80

/* 0 */
#define FDMA_SRAM_NEXT_LINE_OFF 0x00000030
#define FDMA_SRAM_NEXT_LINE            (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_SRAM_NEXT_LINE_OFF))
#define FDMA_X_SRAM_NEXT_LINE(x)       (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_SRAM_NEXT_LINE_OFF + ((x)*0x0)))

#define FDMA_SRAM_NEXT_LINE_RESET_VALUE 0x00000000
#define FDMA_SRAM_NEXT_LINE_VOLATILE   0x0
#define FDMA_SRAM_NEXT_LINE_BITFIELD_MASK 0x0000FFFF
#define FDMA_SRAM_NEXT_LINE_RWMASK     0x00000000
#define FDMA_SRAM_NEXT_LINE_ROMASK     0x0000FFFF
#define FDMA_SRAM_NEXT_LINE_WOMASK     0x00000000
#define FDMA_SRAM_NEXT_LINE_UNUSED_MASK 0xFFFF0000

/* 0 */
#define FDMA_ERR_XFR_REC_NUM_OFF 0x00000028
#define FDMA_ERR_XFR_REC_NUM           (*(vuint32_t *) (FDMA_BASEADDRESS+FDMA_ERR_XFR_REC_NUM_OFF))
#define FDMA_X_ERR_XFR_REC_NUM(x)      (*(vuint32_t *) (FDMA_BASEADDRESS  + FDMA_ERR_XFR_REC_NUM_OFF + ((x)*0x0)))

#define FDMA_ERR_XFR_REC_NUM_RESET_VALUE 0x00000000
#define FDMA_ERR_XFR_REC_NUM_VOLATILE  0x0
#define FDMA_ERR_XFR_REC_NUM_BITFIELD_MASK 0x0000007F
#define FDMA_ERR_XFR_REC_NUM_RWMASK    0x00000000
#define FDMA_ERR_XFR_REC_NUM_ROMASK    0x0000007F
#define FDMA_ERR_XFR_REC_NUM_WOMASK    0x00000000
#define FDMA_ERR_XFR_REC_NUM_UNUSED_MASK 0xFFFFFF80


/* Field definitions for XFR_REC_LIST_PTR */

#define FDMA_XFR_REC_LIST_PTR_XFR_REC_LIST_PTR_VALUE(x) (((x)&0xFFFFFFFF)<<0)
#define FDMA_XFR_REC_LIST_PTR_XFR_REC_LIST_PTR_MSB (31)
#define FDMA_XFR_REC_LIST_PTR_XFR_REC_LIST_PTR_LSB (0)
#define FDMA_XFR_REC_LIST_PTR_XFR_REC_LIST_PTR_MASK (0xFFFFFFFF)
#define FDMA_XFR_REC_LIST_PTR_XFR_REC_LIST_PTR ((FDMA_XFR_REC_LIST_PTR_XFR_REC_LIST_PTR_MASK) << (FDMA_XFR_REC_LIST_PTR_XFR_REC_LIST_PTR_LSB))



/* Field definitions for CALC_CRC_VAL */

#define FDMA_CALC_CRC_VAL_CALC_CRC_VAL_VALUE(x) (((x)&0xFFFFFFFF)<<0)
#define FDMA_CALC_CRC_VAL_CALC_CRC_VAL_MSB (31)
#define FDMA_CALC_CRC_VAL_CALC_CRC_VAL_LSB (0)
#define FDMA_CALC_CRC_VAL_CALC_CRC_VAL_MASK (0xFFFFFFFF)
#define FDMA_CALC_CRC_VAL_CALC_CRC_VAL ((FDMA_CALC_CRC_VAL_CALC_CRC_VAL_MASK) << (FDMA_CALC_CRC_VAL_CALC_CRC_VAL_LSB))



/* Field definitions for XFR_REC_CNT */

#define FDMA_XFR_REC_CNT_XFR_REC_CNT_VALUE(x) (((x)&0x0000007F)<<0)
#define FDMA_XFR_REC_CNT_XFR_REC_CNT_MSB (6)
#define FDMA_XFR_REC_CNT_XFR_REC_CNT_LSB (0)
#define FDMA_XFR_REC_CNT_XFR_REC_CNT_MASK (0x0000007F)
#define FDMA_XFR_REC_CNT_XFR_REC_CNT   ((FDMA_XFR_REC_CNT_XFR_REC_CNT_MASK) << (FDMA_XFR_REC_CNT_XFR_REC_CNT_LSB))



/* Field definitions for XFR_LINE_NUM */

#define FDMA_XFR_LINE_NUM_DDR_IMG_LINE_NUM_VALUE(x) (((x)&0x0000FFFF)<<0)
#define FDMA_XFR_LINE_NUM_DDR_IMG_LINE_NUM_MSB (15)
#define FDMA_XFR_LINE_NUM_DDR_IMG_LINE_NUM_LSB (0)
#define FDMA_XFR_LINE_NUM_DDR_IMG_LINE_NUM_MASK (0x0000FFFF)
#define FDMA_XFR_LINE_NUM_DDR_IMG_LINE_NUM ((FDMA_XFR_LINE_NUM_DDR_IMG_LINE_NUM_MASK) << (FDMA_XFR_LINE_NUM_DDR_IMG_LINE_NUM_LSB))

#define FDMA_XFR_LINE_NUM_SRAM_LINE_NUM_VALUE(x) (((x)&0x0000FFFF)<<16)
#define FDMA_XFR_LINE_NUM_SRAM_LINE_NUM_MSB (31)
#define FDMA_XFR_LINE_NUM_SRAM_LINE_NUM_LSB (16)
#define FDMA_XFR_LINE_NUM_SRAM_LINE_NUM_MASK (0x0000FFFF)
#define FDMA_XFR_LINE_NUM_SRAM_LINE_NUM ((FDMA_XFR_LINE_NUM_SRAM_LINE_NUM_MASK) << (FDMA_XFR_LINE_NUM_SRAM_LINE_NUM_LSB))



/* Field definitions for LINE_INCR */

#define FDMA_LINE_INCR_SRAM_LINE_INCR_VALUE(x) (((x)&0x000000FF)<<16)
#define FDMA_LINE_INCR_SRAM_LINE_INCR_MSB (23)
#define FDMA_LINE_INCR_SRAM_LINE_INCR_LSB (16)
#define FDMA_LINE_INCR_SRAM_LINE_INCR_MASK (0x000000FF)
#define FDMA_LINE_INCR_SRAM_LINE_INCR  ((FDMA_LINE_INCR_SRAM_LINE_INCR_MASK) << (FDMA_LINE_INCR_SRAM_LINE_INCR_LSB))

#define FDMA_LINE_INCR_DDR_LINE_INCR_VALUE(x) (((x)&0x000000FF)<<0)
#define FDMA_LINE_INCR_DDR_LINE_INCR_MSB (7)
#define FDMA_LINE_INCR_DDR_LINE_INCR_LSB (0)
#define FDMA_LINE_INCR_DDR_LINE_INCR_MASK (0x000000FF)
#define FDMA_LINE_INCR_DDR_LINE_INCR   ((FDMA_LINE_INCR_DDR_LINE_INCR_MASK) << (FDMA_LINE_INCR_DDR_LINE_INCR_LSB))



/* Field definitions for XFR_STAT */

#define FDMA_XFR_STAT_XFR_QUEUE_EMPTY_VALUE(x) (((x)&0x00000001)<<0)
#define FDMA_XFR_STAT_XFR_QUEUE_EMPTY_BIT (0)
#define FDMA_XFR_STAT_XFR_QUEUE_EMPTY  ((1) << (FDMA_XFR_STAT_XFR_QUEUE_EMPTY_BIT))

#define FDMA_XFR_STAT_XFR_CMD_QUEUE_FULL_VALUE(x) (((x)&0x00000001)<<1)
#define FDMA_XFR_STAT_XFR_CMD_QUEUE_FULL_BIT (1)
#define FDMA_XFR_STAT_XFR_CMD_QUEUE_FULL ((1) << (FDMA_XFR_STAT_XFR_CMD_QUEUE_FULL_BIT))

#define FDMA_XFR_STAT_CMD_CFG_ERR_VALUE(x) (((x)&0x00000001)<<3)
#define FDMA_XFR_STAT_CMD_CFG_ERR_BIT  (3)
#define FDMA_XFR_STAT_CMD_CFG_ERR      ((1) << (FDMA_XFR_STAT_CMD_CFG_ERR_BIT))

#define FDMA_XFR_STAT_XFR_STP_ERR_TR_VALUE(x) (((x)&0x00000001)<<4)
#define FDMA_XFR_STAT_XFR_STP_ERR_TR_BIT (4)
#define FDMA_XFR_STAT_XFR_STP_ERR_TR   ((1) << (FDMA_XFR_STAT_XFR_STP_ERR_TR_BIT))

#define FDMA_XFR_STAT_CRC_ERR_VALUE(x) (((x)&0x00000001)<<2)
#define FDMA_XFR_STAT_CRC_ERR_BIT      (2)
#define FDMA_XFR_STAT_CRC_ERR          ((1) << (FDMA_XFR_STAT_CRC_ERR_BIT))

#define FDMA_XFR_STAT_DONE_CNT_VALUE(x) (((x)&0x000000FF)<<24)
#define FDMA_XFR_STAT_DONE_CNT_MSB     (31)
#define FDMA_XFR_STAT_DONE_CNT_LSB     (24)
#define FDMA_XFR_STAT_DONE_CNT_MASK    (0x000000FF)
#define FDMA_XFR_STAT_DONE_CNT         ((FDMA_XFR_STAT_DONE_CNT_MASK) << (FDMA_XFR_STAT_DONE_CNT_LSB))

#define FDMA_XFR_STAT_XFR_DONE_VALUE(x) (((x)&0x00000001)<<16)
#define FDMA_XFR_STAT_XFR_DONE_BIT     (16)
#define FDMA_XFR_STAT_XFR_DONE         ((1) << (FDMA_XFR_STAT_XFR_DONE_BIT))

#define FDMA_XFR_STAT_XFR_STP_ERR_CT_VALUE(x) (((x)&0x00000001)<<5)
#define FDMA_XFR_STAT_XFR_STP_ERR_CT_BIT (5)
#define FDMA_XFR_STAT_XFR_STP_ERR_CT   ((1) << (FDMA_XFR_STAT_XFR_STP_ERR_CT_BIT))

#define FDMA_XFR_STAT_XFR_CFG_ERR_VALUE(x) (((x)&0x00000001)<<6)
#define FDMA_XFR_STAT_XFR_CFG_ERR_BIT  (6)
#define FDMA_XFR_STAT_XFR_CFG_ERR      ((1) << (FDMA_XFR_STAT_XFR_CFG_ERR_BIT))

#define FDMA_XFR_STAT_XFR_ERR_DDR_VALUE(x) (((x)&0x00000001)<<7)
#define FDMA_XFR_STAT_XFR_ERR_DDR_BIT  (7)
#define FDMA_XFR_STAT_XFR_ERR_DDR      ((1) << (FDMA_XFR_STAT_XFR_ERR_DDR_BIT))

#define FDMA_XFR_STAT_XFR_ERR_SRAM_VALUE(x) (((x)&0x00000001)<<8)
#define FDMA_XFR_STAT_XFR_ERR_SRAM_BIT (8)
#define FDMA_XFR_STAT_XFR_ERR_SRAM     ((1) << (FDMA_XFR_STAT_XFR_ERR_SRAM_BIT))



/* Field definitions for CURR_SRAM_PTR */

#define FDMA_CURR_SRAM_PTR_CURR_SRAM_PTR_VALUE(x) (((x)&0xFFFFFFFF)<<0)
#define FDMA_CURR_SRAM_PTR_CURR_SRAM_PTR_MSB (31)
#define FDMA_CURR_SRAM_PTR_CURR_SRAM_PTR_LSB (0)
#define FDMA_CURR_SRAM_PTR_CURR_SRAM_PTR_MASK (0xFFFFFFFF)
#define FDMA_CURR_SRAM_PTR_CURR_SRAM_PTR ((FDMA_CURR_SRAM_PTR_CURR_SRAM_PTR_MASK) << (FDMA_CURR_SRAM_PTR_CURR_SRAM_PTR_LSB))



/* Field definitions for XFR_QUEUE_DEPTH */

#define FDMA_XFR_QUEUE_DEPTH_XFR_QUEUE_DEPTH_VALUE(x) (((x)&0x0000001F)<<0)
#define FDMA_XFR_QUEUE_DEPTH_XFR_QUEUE_DEPTH_MSB (4)
#define FDMA_XFR_QUEUE_DEPTH_XFR_QUEUE_DEPTH_LSB (0)
#define FDMA_XFR_QUEUE_DEPTH_XFR_QUEUE_DEPTH_MASK (0x0000001F)
#define FDMA_XFR_QUEUE_DEPTH_XFR_QUEUE_DEPTH ((FDMA_XFR_QUEUE_DEPTH_XFR_QUEUE_DEPTH_MASK) << (FDMA_XFR_QUEUE_DEPTH_XFR_QUEUE_DEPTH_LSB))



/* Field definitions for CURR_DDR_PTR */

#define FDMA_CURR_DDR_PTR_CURR_DDR_PTR_VALUE(x) (((x)&0xFFFFFFFF)<<0)
#define FDMA_CURR_DDR_PTR_CURR_DDR_PTR_MSB (31)
#define FDMA_CURR_DDR_PTR_CURR_DDR_PTR_LSB (0)
#define FDMA_CURR_DDR_PTR_CURR_DDR_PTR_MASK (0xFFFFFFFF)
#define FDMA_CURR_DDR_PTR_CURR_DDR_PTR ((FDMA_CURR_DDR_PTR_CURR_DDR_PTR_MASK) << (FDMA_CURR_DDR_PTR_CURR_DDR_PTR_LSB))



/* Field definitions for XFR_REC_NUM_DONE */

#define FDMA_XFR_REC_NUM_DONE_XFR_REC_NUM_DONE_VALUE(x) (((x)&0x0000007F)<<0)
#define FDMA_XFR_REC_NUM_DONE_XFR_REC_NUM_DONE_MSB (6)
#define FDMA_XFR_REC_NUM_DONE_XFR_REC_NUM_DONE_LSB (0)
#define FDMA_XFR_REC_NUM_DONE_XFR_REC_NUM_DONE_MASK (0x0000007F)
#define FDMA_XFR_REC_NUM_DONE_XFR_REC_NUM_DONE ((FDMA_XFR_REC_NUM_DONE_XFR_REC_NUM_DONE_MASK) << (FDMA_XFR_REC_NUM_DONE_XFR_REC_NUM_DONE_LSB))



/* Field definitions for XFR_REC_NUM */

#define FDMA_XFR_REC_NUM_XFR_REC_NUM_VALUE(x) (((x)&0x0000007F)<<0)
#define FDMA_XFR_REC_NUM_XFR_REC_NUM_MSB (6)
#define FDMA_XFR_REC_NUM_XFR_REC_NUM_LSB (0)
#define FDMA_XFR_REC_NUM_XFR_REC_NUM_MASK (0x0000007F)
#define FDMA_XFR_REC_NUM_XFR_REC_NUM   ((FDMA_XFR_REC_NUM_XFR_REC_NUM_MASK) << (FDMA_XFR_REC_NUM_XFR_REC_NUM_LSB))



/* Field definitions for SRAM_NEXT_LINE */

#define FDMA_SRAM_NEXT_LINE_SRAM_NEXT_LINE_NUM_VALUE(x) (((x)&0x0000FFFF)<<0)
#define FDMA_SRAM_NEXT_LINE_SRAM_NEXT_LINE_NUM_MSB (15)
#define FDMA_SRAM_NEXT_LINE_SRAM_NEXT_LINE_NUM_LSB (0)
#define FDMA_SRAM_NEXT_LINE_SRAM_NEXT_LINE_NUM_MASK (0x0000FFFF)
#define FDMA_SRAM_NEXT_LINE_SRAM_NEXT_LINE_NUM ((FDMA_SRAM_NEXT_LINE_SRAM_NEXT_LINE_NUM_MASK) << (FDMA_SRAM_NEXT_LINE_SRAM_NEXT_LINE_NUM_LSB))



/* Field definitions for ERR_XFR_REC_NUM */

#define FDMA_ERR_XFR_REC_NUM_ERR_XFR_REC_NUM_VALUE(x) (((x)&0x0000007F)<<0)
#define FDMA_ERR_XFR_REC_NUM_ERR_XFR_REC_NUM_MSB (6)
#define FDMA_ERR_XFR_REC_NUM_ERR_XFR_REC_NUM_LSB (0)
#define FDMA_ERR_XFR_REC_NUM_ERR_XFR_REC_NUM_MASK (0x0000007F)
#define FDMA_ERR_XFR_REC_NUM_ERR_XFR_REC_NUM ((FDMA_ERR_XFR_REC_NUM_ERR_XFR_REC_NUM_MASK) << (FDMA_ERR_XFR_REC_NUM_ERR_XFR_REC_NUM_LSB))

#endif /* FASTDMAMEMMAP_H */