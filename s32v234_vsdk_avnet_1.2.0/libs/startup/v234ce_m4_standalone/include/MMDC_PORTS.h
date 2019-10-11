/*****************************************************************************
* 
* NXP Confidential Proprietary
*
* Copyright (c) 2014-2016 Freescale Semiconductor
* Copyright 2017 NXP 
* All Rights Reserved
*
******************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************/

#ifndef MMDCPORTS_H
#define MMDCPORTS_H

/* List of SDRAM MSCR offsets */
#define _DDR0_RESET	168
#define _DDR0_CLK0	169
#define _DDR0_CAS	170
#define _DDR0_RAS	171
#define _DDR0_WE_B	172
#define _DDR0_CKE0	173
#define _DDR0_CKE1	174
#define _DDR0_CS_B0	175
#define _DDR0_CS_B1	176
#define _DDR0_BA0	177
#define _DDR0_BA1	178
#define _DDR0_BA2	179
#define _DDR0_A0	180
#define _DDR0_A1	181
#define _DDR0_A2	182
#define _DDR0_A3	183
#define _DDR0_A4	184
#define _DDR0_A5	185
#define _DDR0_A6	186
#define _DDR0_A7	187
#define _DDR0_A8	188
#define _DDR0_A9	189
#define _DDR0_A10	190
#define _DDR0_A11	191
#define _DDR0_A12	192
#define _DDR0_A13	193
#define _DDR0_A14	194
#define _DDR0_A15	195
#define _DDR0_DM0	196
#define _DDR0_DM1	197
#define _DDR0_DM2	198
#define _DDR0_DM3	199
#define _DDR0_DQS0	200
#define _DDR0_DQS1	201
#define _DDR0_DQS2	202
#define _DDR0_DQS3	203
#define _DDR0_D0	204
#define _DDR0_D1	205
#define _DDR0_D2	206
#define _DDR0_D3	207
#define _DDR0_D4	208
#define _DDR0_D5	209
#define _DDR0_D6	210
#define _DDR0_D7	211
#define _DDR0_D8	212
#define _DDR0_D9	213
#define _DDR0_D10	214
#define _DDR0_D11	215
#define _DDR0_D12	216
#define _DDR0_D13	217
#define _DDR0_D14	218
#define _DDR0_D15	219
#define _DDR0_D16	220
#define _DDR0_D17	221
#define _DDR0_D18	222
#define _DDR0_D19	223
#define _DDR0_D20	224
#define _DDR0_D21	225
#define _DDR0_D22	226
#define _DDR0_D23	227
#define _DDR0_D24	228
#define _DDR0_D25	229
#define _DDR0_D26	230
#define _DDR0_D27	231
#define _DDR0_D28	232
#define _DDR0_D29	233
#define _DDR0_D30	234
#define _DDR0_D31	235
#define _DDR0_ODT0	236
#define _DDR0_ODT1	237
#define _DDR0_ZQ	238
#define _DDR1_RESET	239
#define _DDR1_CLK0	240
#define _DDR1_CAS	241
#define _DDR1_RAS	242
#define _DDR1_WE_B	243
#define _DDR1_CKE0	244
#define _DDR1_CKE1	245
#define _DDR1_CS_B0	246
#define _DDR1_CS_B1	247
#define _DDR1_BA0	248
#define _DDR1_BA1	249
#define _DDR1_BA2	250
#define _DDR1_A0	251
#define _DDR1_A1	252
#define _DDR1_A2	253
#define _DDR1_A3	254
#define _DDR1_A4	255
#define _DDR1_A5	256
#define _DDR1_A6	257
#define _DDR1_A7	258
#define _DDR1_A8	259
#define _DDR1_A9	260
#define _DDR1_A10	261
#define _DDR1_A11	262
#define _DDR1_A12	263
#define _DDR1_A13	264
#define _DDR1_A14	265
#define _DDR1_A15	266
#define _DDR1_DM0	267
#define _DDR1_DM1	268
#define _DDR1_DM2	269
#define _DDR1_DM3	270
#define _DDR1_DQS0	271
#define _DDR1_DQS1	272
#define _DDR1_DQS2	273
#define _DDR1_DQS3	274
#define _DDR1_D0	275
#define _DDR1_D1	276
#define _DDR1_D2	277
#define _DDR1_D3	278
#define _DDR1_D4	279
#define _DDR1_D5	280
#define _DDR1_D6	281
#define _DDR1_D7	282
#define _DDR1_D8	283
#define _DDR1_D9	284
#define _DDR1_D10	285
#define _DDR1_D11	286
#define _DDR1_D12	287
#define _DDR1_D13	288
#define _DDR1_D14	289
#define _DDR1_D15	290
#define _DDR1_D16	291
#define _DDR1_D17	292
#define _DDR1_D18	293
#define _DDR1_D19	294
#define _DDR1_D20	295
#define _DDR1_D21	296
#define _DDR1_D22	297
#define _DDR1_D23	298
#define _DDR1_D24	299
#define _DDR1_D25	300
#define _DDR1_D26	301
#define _DDR1_D27	302
#define _DDR1_D28	303
#define _DDR1_D29	304
#define _DDR1_D30	305
#define _DDR1_D31	306
#define _DDR1_ODT0	307
#define _DDR1_ODT1	308
#define _DDR1_ZQ	309

#endif /* MMDCPORTS_H */
