/*****************************************************************************
* 
* NXP Confidential Proprietary
*
* Copyright (c) 2016 Freescale Semiconductor
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

/**
* \file 		lut_0.8.h
* \brief 		look up table
* \author 		
* \version 		0.1
* \date 		03-February-2015
****************************************************************************/

#ifndef LUT08_H
#define LUT08_H

// Gamma 0.8; Samples 2048 Scale 32752
uint16_t lut[]= {
0,
73,
127,
177,
222,
266,
308,
348,
387,
426,
463,
500,
536,
572,
607,
641,
675,
709,
742,
775,
807,
839,
871,
903,
934,
965,
996,
1026,
1056,
1087,
1116,
1146,
1176,
1205,
1234,
1263,
1292,
1321,
1349,
1377,
1406,
1434,
1461,
1489,
1517,
1544,
1572,
1599,
1626,
1653,
1680,
1707,
1734,
1761,
1787,
1813,
1840,
1866,
1892,
1918,
1944,
1970,
1996,
2022,
2047,
2073,
2098,
2124,
2149,
2174,
2199,
2225,
2250,
2275,
2300,
2324,
2349,
2374,
2398,
2423,
2448,
2472,
2496,
2521,
2545,
2569,
2593,
2617,
2641,
2665,
2689,
2713,
2737,
2761,
2785,
2808,
2832,
2856,
2879,
2903,
2926,
2949,
2973,
2996,
3019,
3042,
3066,
3089,
3112,
3135,
3158,
3181,
3204,
3227,
3249,
3272,
3295,
3318,
3340,
3363,
3386,
3408,
3431,
3453,
3476,
3498,
3520,
3543,
3565,
3587,
3609,
3632,
3654,
3676,
3698,
3720,
3742,
3764,
3786,
3808,
3830,
3852,
3874,
3895,
3917,
3939,
3961,
3982,
4004,
4026,
4047,
4069,
4090,
4112,
4133,
4155,
4176,
4198,
4219,
4240,
4262,
4283,
4304,
4326,
4347,
4368,
4389,
4410,
4431,
4453,
4474,
4495,
4516,
4537,
4558,
4579,
4599,
4620,
4641,
4662,
4683,
4704,
4724,
4745,
4766,
4787,
4807,
4828,
4849,
4869,
4890,
4911,
4931,
4952,
4972,
4993,
5013,
5034,
5054,
5074,
5095,
5115,
5135,
5156,
5176,
5196,
5217,
5237,
5257,
5277,
5298,
5318,
5338,
5358,
5378,
5398,
5418,
5438,
5458,
5478,
5498,
5518,
5538,
5558,
5578,
5598,
5618,
5638,
5658,
5678,
5698,
5717,
5737,
5757,
5777,
5796,
5816,
5836,
5856,
5875,
5895,
5915,
5934,
5954,
5973,
5993,
6013,
6032,
6052,
6071,
6091,
6110,
6130,
6149,
6168,
6188,
6207,
6227,
6246,
6265,
6285,
6304,
6323,
6343,
6362,
6381,
6401,
6420,
6439,
6458,
6477,
6497,
6516,
6535,
6554,
6573,
6592,
6611,
6631,
6650,
6669,
6688,
6707,
6726,
6745,
6764,
6783,
6802,
6821,
6840,
6859,
6877,
6896,
6915,
6934,
6953,
6972,
6991,
7009,
7028,
7047,
7066,
7085,
7103,
7122,
7141,
7160,
7178,
7197,
7216,
7234,
7253,
7272,
7290,
7309,
7328,
7346,
7365,
7383,
7402,
7421,
7439,
7458,
7476,
7495,
7513,
7532,
7550,
7569,
7587,
7605,
7624,
7642,
7661,
7679,
7698,
7716,
7734,
7753,
7771,
7789,
7808,
7826,
7844,
7863,
7881,
7899,
7917,
7936,
7954,
7972,
7990,
8008,
8027,
8045,
8063,
8081,
8099,
8118,
8136,
8154,
8172,
8190,
8208,
8226,
8244,
8262,
8280,
8298,
8316,
8334,
8353,
8371,
8389,
8406,
8424,
8442,
8460,
8478,
8496,
8514,
8532,
8550,
8568,
8586,
8604,
8622,
8639,
8657,
8675,
8693,
8711,
8729,
8746,
8764,
8782,
8800,
8818,
8835,
8853,
8871,
8889,
8906,
8924,
8942,
8959,
8977,
8995,
9013,
9030,
9048,
9066,
9083,
9101,
9118,
9136,
9154,
9171,
9189,
9206,
9224,
9242,
9259,
9277,
9294,
9312,
9329,
9347,
9364,
9382,
9399,
9417,
9434,
9452,
9469,
9487,
9504,
9522,
9539,
9556,
9574,
9591,
9609,
9626,
9643,
9661,
9678,
9695,
9713,
9730,
9747,
9765,
9782,
9799,
9817,
9834,
9851,
9869,
9886,
9903,
9920,
9938,
9955,
9972,
9989,
10007,
10024,
10041,
10058,
10075,
10093,
10110,
10127,
10144,
10161,
10178,
10195,
10213,
10230,
10247,
10264,
10281,
10298,
10315,
10332,
10349,
10366,
10384,
10401,
10418,
10435,
10452,
10469,
10486,
10503,
10520,
10537,
10554,
10571,
10588,
10605,
10622,
10639,
10656,
10673,
10689,
10706,
10723,
10740,
10757,
10774,
10791,
10808,
10825,
10842,
10858,
10875,
10892,
10909,
10926,
10943,
10960,
10976,
10993,
11010,
11027,
11044,
11060,
11077,
11094,
11111,
11128,
11144,
11161,
11178,
11195,
11211,
11228,
11245,
11261,
11278,
11295,
11312,
11328,
11345,
11362,
11378,
11395,
11412,
11428,
11445,
11462,
11478,
11495,
11512,
11528,
11545,
11561,
11578,
11595,
11611,
11628,
11644,
11661,
11677,
11694,
11711,
11727,
11744,
11760,
11777,
11793,
11810,
11826,
11843,
11859,
11876,
11892,
11909,
11925,
11942,
11958,
11975,
11991,
12008,
12024,
12040,
12057,
12073,
12090,
12106,
12123,
12139,
12155,
12172,
12188,
12205,
12221,
12237,
12254,
12270,
12286,
12303,
12319,
12335,
12352,
12368,
12384,
12401,
12417,
12433,
12450,
12466,
12482,
12499,
12515,
12531,
12547,
12564,
12580,
12596,
12612,
12629,
12645,
12661,
12677,
12694,
12710,
12726,
12742,
12758,
12775,
12791,
12807,
12823,
12839,
12856,
12872,
12888,
12904,
12920,
12936,
12953,
12969,
12985,
13001,
13017,
13033,
13049,
13065,
13082,
13098,
13114,
13130,
13146,
13162,
13178,
13194,
13210,
13226,
13242,
13258,
13274,
13290,
13306,
13322,
13338,
13355,
13371,
13387,
13403,
13419,
13435,
13451,
13467,
13483,
13498,
13514,
13530,
13546,
13562,
13578,
13594,
13610,
13626,
13642,
13658,
13674,
13690,
13706,
13722,
13738,
13753,
13769,
13785,
13801,
13817,
13833,
13849,
13865,
13881,
13896,
13912,
13928,
13944,
13960,
13976,
13991,
14007,
14023,
14039,
14055,
14071,
14086,
14102,
14118,
14134,
14150,
14165,
14181,
14197,
14213,
14228,
14244,
14260,
14276,
14291,
14307,
14323,
14339,
14354,
14370,
14386,
14402,
14417,
14433,
14449,
14464,
14480,
14496,
14512,
14527,
14543,
14559,
14574,
14590,
14606,
14621,
14637,
14653,
14668,
14684,
14700,
14715,
14731,
14746,
14762,
14778,
14793,
14809,
14824,
14840,
14856,
14871,
14887,
14902,
14918,
14934,
14949,
14965,
14980,
14996,
15011,
15027,
15043,
15058,
15074,
15089,
15105,
15120,
15136,
15151,
15167,
15182,
15198,
15213,
15229,
15244,
15260,
15275,
15291,
15306,
15322,
15337,
15353,
15368,
15384,
15399,
15415,
15430,
15445,
15461,
15476,
15492,
15507,
15523,
15538,
15554,
15569,
15584,
15600,
15615,
15631,
15646,
15661,
15677,
15692,
15708,
15723,
15738,
15754,
15769,
15784,
15800,
15815,
15830,
15846,
15861,
15876,
15892,
15907,
15922,
15938,
15953,
15968,
15984,
15999,
16014,
16030,
16045,
16060,
16076,
16091,
16106,
16121,
16137,
16152,
16167,
16183,
16198,
16213,
16228,
16244,
16259,
16274,
16289,
16305,
16320,
16335,
16350,
16365,
16381,
16396,
16411,
16426,
16442,
16457,
16472,
16487,
16502,
16518,
16533,
16548,
16563,
16578,
16593,
16609,
16624,
16639,
16654,
16669,
16684,
16700,
16715,
16730,
16745,
16760,
16775,
16790,
16806,
16821,
16836,
16851,
16866,
16881,
16896,
16911,
16926,
16941,
16957,
16972,
16987,
17002,
17017,
17032,
17047,
17062,
17077,
17092,
17107,
17122,
17137,
17152,
17168,
17183,
17198,
17213,
17228,
17243,
17258,
17273,
17288,
17303,
17318,
17333,
17348,
17363,
17378,
17393,
17408,
17423,
17438,
17453,
17468,
17483,
17498,
17513,
17528,
17543,
17558,
17572,
17587,
17602,
17617,
17632,
17647,
17662,
17677,
17692,
17707,
17722,
17737,
17752,
17767,
17782,
17796,
17811,
17826,
17841,
17856,
17871,
17886,
17901,
17916,
17931,
17945,
17960,
17975,
17990,
18005,
18020,
18035,
18049,
18064,
18079,
18094,
18109,
18124,
18139,
18153,
18168,
18183,
18198,
18213,
18228,
18242,
18257,
18272,
18287,
18302,
18316,
18331,
18346,
18361,
18376,
18390,
18405,
18420,
18435,
18449,
18464,
18479,
18494,
18509,
18523,
18538,
18553,
18568,
18582,
18597,
18612,
18627,
18641,
18656,
18671,
18686,
18700,
18715,
18730,
18744,
18759,
18774,
18789,
18803,
18818,
18833,
18847,
18862,
18877,
18891,
18906,
18921,
18935,
18950,
18965,
18979,
18994,
19009,
19023,
19038,
19053,
19067,
19082,
19097,
19111,
19126,
19141,
19155,
19170,
19185,
19199,
19214,
19228,
19243,
19258,
19272,
19287,
19302,
19316,
19331,
19345,
19360,
19375,
19389,
19404,
19418,
19433,
19448,
19462,
19477,
19491,
19506,
19520,
19535,
19550,
19564,
19579,
19593,
19608,
19622,
19637,
19651,
19666,
19680,
19695,
19710,
19724,
19739,
19753,
19768,
19782,
19797,
19811,
19826,
19840,
19855,
19869,
19884,
19898,
19913,
19927,
19942,
19956,
19971,
19985,
20000,
20014,
20029,
20043,
20058,
20072,
20086,
20101,
20115,
20130,
20144,
20159,
20173,
20188,
20202,
20217,
20231,
20245,
20260,
20274,
20289,
20303,
20318,
20332,
20346,
20361,
20375,
20390,
20404,
20418,
20433,
20447,
20462,
20476,
20490,
20505,
20519,
20534,
20548,
20562,
20577,
20591,
20606,
20620,
20634,
20649,
20663,
20677,
20692,
20706,
20720,
20735,
20749,
20763,
20778,
20792,
20806,
20821,
20835,
20849,
20864,
20878,
20892,
20907,
20921,
20935,
20950,
20964,
20978,
20993,
21007,
21021,
21036,
21050,
21064,
21078,
21093,
21107,
21121,
21136,
21150,
21164,
21178,
21193,
21207,
21221,
21236,
21250,
21264,
21278,
21293,
21307,
21321,
21335,
21350,
21364,
21378,
21392,
21407,
21421,
21435,
21449,
21463,
21478,
21492,
21506,
21520,
21535,
21549,
21563,
21577,
21591,
21606,
21620,
21634,
21648,
21662,
21677,
21691,
21705,
21719,
21733,
21747,
21762,
21776,
21790,
21804,
21818,
21833,
21847,
21861,
21875,
21889,
21903,
21917,
21932,
21946,
21960,
21974,
21988,
22002,
22016,
22031,
22045,
22059,
22073,
22087,
22101,
22115,
22130,
22144,
22158,
22172,
22186,
22200,
22214,
22228,
22242,
22256,
22271,
22285,
22299,
22313,
22327,
22341,
22355,
22369,
22383,
22397,
22411,
22425,
22440,
22454,
22468,
22482,
22496,
22510,
22524,
22538,
22552,
22566,
22580,
22594,
22608,
22622,
22636,
22650,
22664,
22678,
22692,
22706,
22721,
22735,
22749,
22763,
22777,
22791,
22805,
22819,
22833,
22847,
22861,
22875,
22889,
22903,
22917,
22931,
22945,
22959,
22973,
22987,
23001,
23015,
23029,
23043,
23056,
23070,
23084,
23098,
23112,
23126,
23140,
23154,
23168,
23182,
23196,
23210,
23224,
23238,
23252,
23266,
23280,
23294,
23308,
23322,
23336,
23349,
23363,
23377,
23391,
23405,
23419,
23433,
23447,
23461,
23475,
23489,
23503,
23516,
23530,
23544,
23558,
23572,
23586,
23600,
23614,
23628,
23642,
23655,
23669,
23683,
23697,
23711,
23725,
23739,
23753,
23766,
23780,
23794,
23808,
23822,
23836,
23850,
23863,
23877,
23891,
23905,
23919,
23933,
23947,
23960,
23974,
23988,
24002,
24016,
24030,
24043,
24057,
24071,
24085,
24099,
24113,
24126,
24140,
24154,
24168,
24182,
24195,
24209,
24223,
24237,
24251,
24264,
24278,
24292,
24306,
24320,
24333,
24347,
24361,
24375,
24389,
24402,
24416,
24430,
24444,
24457,
24471,
24485,
24499,
24512,
24526,
24540,
24554,
24567,
24581,
24595,
24609,
24622,
24636,
24650,
24664,
24677,
24691,
24705,
24719,
24732,
24746,
24760,
24774,
24787,
24801,
24815,
24828,
24842,
24856,
24870,
24883,
24897,
24911,
24924,
24938,
24952,
24966,
24979,
24993,
25007,
25020,
25034,
25048,
25061,
25075,
25089,
25102,
25116,
25130,
25143,
25157,
25171,
25184,
25198,
25212,
25225,
25239,
25253,
25266,
25280,
25294,
25307,
25321,
25335,
25348,
25362,
25376,
25389,
25403,
25417,
25430,
25444,
25457,
25471,
25485,
25498,
25512,
25526,
25539,
25553,
25566,
25580,
25594,
25607,
25621,
25635,
25648,
25662,
25675,
25689,
25703,
25716,
25730,
25743,
25757,
25771,
25784,
25798,
25811,
25825,
25838,
25852,
25866,
25879,
25893,
25906,
25920,
25934,
25947,
25961,
25974,
25988,
26001,
26015,
26028,
26042,
26056,
26069,
26083,
26096,
26110,
26123,
26137,
26150,
26164,
26177,
26191,
26205,
26218,
26232,
26245,
26259,
26272,
26286,
26299,
26313,
26326,
26340,
26353,
26367,
26380,
26394,
26407,
26421,
26434,
26448,
26461,
26475,
26488,
26502,
26515,
26529,
26542,
26556,
26569,
26583,
26596,
26610,
26623,
26637,
26650,
26664,
26677,
26691,
26704,
26718,
26731,
26745,
26758,
26771,
26785,
26798,
26812,
26825,
26839,
26852,
26866,
26879,
26893,
26906,
26919,
26933,
26946,
26960,
26973,
26987,
27000,
27013,
27027,
27040,
27054,
27067,
27081,
27094,
27107,
27121,
27134,
27148,
27161,
27175,
27188,
27201,
27215,
27228,
27242,
27255,
27268,
27282,
27295,
27309,
27322,
27335,
27349,
27362,
27376,
27389,
27402,
27416,
27429,
27442,
27456,
27469,
27483,
27496,
27509,
27523,
27536,
27549,
27563,
27576,
27589,
27603,
27616,
27630,
27643,
27656,
27670,
27683,
27696,
27710,
27723,
27736,
27750,
27763,
27776,
27790,
27803,
27816,
27830,
27843,
27856,
27870,
27883,
27896,
27910,
27923,
27936,
27950,
27963,
27976,
27990,
28003,
28016,
28030,
28043,
28056,
28069,
28083,
28096,
28109,
28123,
28136,
28149,
28163,
28176,
28189,
28202,
28216,
28229,
28242,
28256,
28269,
28282,
28295,
28309,
28322,
28335,
28348,
28362,
28375,
28388,
28402,
28415,
28428,
28441,
28455,
28468,
28481,
28494,
28508,
28521,
28534,
28547,
28561,
28574,
28587,
28600,
28614,
28627,
28640,
28653,
28667,
28680,
28693,
28706,
28719,
28733,
28746,
28759,
28772,
28786,
28799,
28812,
28825,
28838,
28852,
28865,
28878,
28891,
28904,
28918,
28931,
28944,
28957,
28970,
28984,
28997,
29010,
29023,
29036,
29050,
29063,
29076,
29089,
29102,
29116,
29129,
29142,
29155,
29168,
29181,
29195,
29208,
29221,
29234,
29247,
29260,
29274,
29287,
29300,
29313,
29326,
29339,
29353,
29366,
29379,
29392,
29405,
29418,
29432,
29445,
29458,
29471,
29484,
29497,
29510,
29524,
29537,
29550,
29563,
29576,
29589,
29602,
29615,
29629,
29642,
29655,
29668,
29681,
29694,
29707,
29720,
29734,
29747,
29760,
29773,
29786,
29799,
29812,
29825,
29838,
29851,
29865,
29878,
29891,
29904,
29917,
29930,
29943,
29956,
29969,
29982,
29995,
30009,
30022,
30035,
30048,
30061,
30074,
30087,
30100,
30113,
30126,
30139,
30152,
30165,
30179,
30192,
30205,
30218,
30231,
30244,
30257,
30270,
30283,
30296,
30309,
30322,
30335,
30348,
30361,
30374,
30387,
30400,
30413,
30426,
30440,
30453,
30466,
30479,
30492,
30505,
30518,
30531,
30544,
30557,
30570,
30583,
30596,
30609,
30622,
30635,
30648,
30661,
30674,
30687,
30700,
30713,
30726,
30739,
30752,
30765,
30778,
30791,
30804,
30817,
30830,
30843,
30856,
30869,
30882,
30895,
30908,
30921,
30934,
30947,
30960,
30973,
30986,
30999,
31012,
31025,
31038,
31051,
31064,
31077,
31090,
31103,
31116,
31129,
31141,
31154,
31167,
31180,
31193,
31206,
31219,
31232,
31245,
31258,
31271,
31284,
31297,
31310,
31323,
31336,
31349,
31362,
31375,
31388,
31400,
31413,
31426,
31439,
31452,
31465,
31478,
31491,
31504,
31517,
31530,
31543,
31556,
31569,
31581,
31594,
31607,
31620,
31633,
31646,
31659,
31672,
31685,
31698,
31711,
31723,
31736,
31749,
31762,
31775,
31788,
31801,
31814,
31827,
31840,
31852,
31865,
31878,
31891,
31904,
31917,
31930,
31943,
31955,
31968,
31981,
31994,
32007,
32020,
32033,
32046,
32058,
32071,
32084,
32097,
32110,
32123,
32136,
32149,
32161,
32174,
32187,
32200,
32213,
32226,
32238,
32251,
32264,
32277,
32290,
32303,
32316,
32328,
32341,
32354,
32367,
32380,
32393,
32405,
32418,
32431,
32444,
32457,
32470,
32482,
32495,
32508,
32521,
32534,
32547,
32559,
32572,
32585,
32598,
32611,
32623,
32636,
32649,
32662,
32675,
32687,
32700,
32713,
32726,
32739,
32752
};

#endif /* LUT08_H */

