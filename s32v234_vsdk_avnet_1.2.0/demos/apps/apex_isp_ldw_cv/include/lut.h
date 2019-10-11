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
/**
* \file 		lut.h
* \brief 		look up table
* \author 		
* \version 		0.1
* \date 		03-February-2015
****************************************************************************/

#ifndef LUT_H
#define LUT_H

// Gamma 0.7; Samples 2048 Scale 65535
uint16_t lut[]= {
0,
315,
512,
680,
832,
972,
1105,
1231,
1351,
1467,
1580,
1689,
1795,
1898,
1999,
2098,
2195,
2290,
2384,
2476,
2566,
2656,
2744,
2830,
2916,
3000,
3084,
3166,
3248,
3329,
3409,
3488,
3566,
3644,
3721,
3797,
3873,
3948,
4022,
4096,
4169,
4242,
4314,
4386,
4457,
4528,
4598,
4668,
4737,
4806,
4874,
4942,
5010,
5077,
5144,
5211,
5277,
5343,
5408,
5473,
5538,
5603,
5667,
5730,
5794,
5857,
5920,
5983,
6045,
6107,
6169,
6231,
6292,
6353,
6414,
6474,
6535,
6595,
6655,
6714,
6774,
6833,
6892,
6950,
7009,
7067,
7125,
7183,
7241,
7299,
7356,
7413,
7470,
7527,
7583,
7640,
7696,
7752,
7808,
7863,
7919,
7974,
8029,
8084,
8139,
8194,
8249,
8303,
8357,
8411,
8465,
8519,
8573,
8626,
8680,
8733,
8786,
8839,
8892,
8944,
8997,
9049,
9102,
9154,
9206,
9258,
9310,
9361,
9413,
9464,
9515,
9567,
9618,
9669,
9719,
9770,
9821,
9871,
9922,
9972,
10022,
10072,
10122,
10172,
10222,
10271,
10321,
10370,
10420,
10469,
10518,
10567,
10616,
10665,
10714,
10762,
10811,
10859,
10908,
10956,
11004,
11052,
11100,
11148,
11196,
11244,
11291,
11339,
11386,
11434,
11481,
11528,
11576,
11623,
11670,
11717,
11763,
11810,
11857,
11903,
11950,
11996,
12043,
12089,
12135,
12181,
12227,
12273,
12319,
12365,
12411,
12457,
12502,
12548,
12593,
12639,
12684,
12729,
12774,
12819,
12865,
12910,
12954,
12999,
13044,
13089,
13134,
13178,
13223,
13267,
13312,
13356,
13400,
13444,
13489,
13533,
13577,
13621,
13665,
13708,
13752,
13796,
13840,
13883,
13927,
13970,
14014,
14057,
14100,
14144,
14187,
14230,
14273,
14316,
14359,
14402,
14445,
14488,
14530,
14573,
14616,
14658,
14701,
14743,
14786,
14828,
14871,
14913,
14955,
14997,
15040,
15082,
15124,
15166,
15208,
15249,
15291,
15333,
15375,
15417,
15458,
15500,
15541,
15583,
15624,
15666,
15707,
15748,
15790,
15831,
15872,
15913,
15954,
15995,
16036,
16077,
16118,
16159,
16200,
16241,
16281,
16322,
16363,
16403,
16444,
16484,
16525,
16565,
16606,
16646,
16686,
16726,
16767,
16807,
16847,
16887,
16927,
16967,
17007,
17047,
17087,
17127,
17167,
17206,
17246,
17286,
17325,
17365,
17405,
17444,
17484,
17523,
17563,
17602,
17641,
17681,
17720,
17759,
17798,
17837,
17877,
17916,
17955,
17994,
18033,
18072,
18111,
18149,
18188,
18227,
18266,
18305,
18343,
18382,
18421,
18459,
18498,
18536,
18575,
18613,
18652,
18690,
18728,
18767,
18805,
18843,
18881,
18920,
18958,
18996,
19034,
19072,
19110,
19148,
19186,
19224,
19262,
19300,
19337,
19375,
19413,
19451,
19488,
19526,
19564,
19601,
19639,
19676,
19714,
19751,
19789,
19826,
19864,
19901,
19938,
19976,
20013,
20050,
20087,
20125,
20162,
20199,
20236,
20273,
20310,
20347,
20384,
20421,
20458,
20495,
20532,
20569,
20605,
20642,
20679,
20716,
20752,
20789,
20826,
20862,
20899,
20935,
20972,
21008,
21045,
21081,
21118,
21154,
21191,
21227,
21263,
21300,
21336,
21372,
21408,
21444,
21481,
21517,
21553,
21589,
21625,
21661,
21697,
21733,
21769,
21805,
21841,
21877,
21912,
21948,
21984,
22020,
22056,
22091,
22127,
22163,
22198,
22234,
22270,
22305,
22341,
22376,
22412,
22447,
22483,
22518,
22554,
22589,
22624,
22660,
22695,
22730,
22766,
22801,
22836,
22871,
22906,
22942,
22977,
23012,
23047,
23082,
23117,
23152,
23187,
23222,
23257,
23292,
23327,
23362,
23396,
23431,
23466,
23501,
23536,
23570,
23605,
23640,
23675,
23709,
23744,
23778,
23813,
23848,
23882,
23917,
23951,
23986,
24020,
24055,
24089,
24123,
24158,
24192,
24227,
24261,
24295,
24329,
24364,
24398,
24432,
24466,
24500,
24535,
24569,
24603,
24637,
24671,
24705,
24739,
24773,
24807,
24841,
24875,
24909,
24943,
24977,
25011,
25045,
25078,
25112,
25146,
25180,
25214,
25247,
25281,
25315,
25348,
25382,
25416,
25449,
25483,
25516,
25550,
25584,
25617,
25651,
25684,
25718,
25751,
25784,
25818,
25851,
25885,
25918,
25951,
25985,
26018,
26051,
26085,
26118,
26151,
26184,
26217,
26251,
26284,
26317,
26350,
26383,
26416,
26449,
26482,
26515,
26548,
26581,
26614,
26647,
26680,
26713,
26746,
26779,
26812,
26845,
26878,
26910,
26943,
26976,
27009,
27042,
27074,
27107,
27140,
27172,
27205,
27238,
27270,
27303,
27336,
27368,
27401,
27433,
27466,
27498,
27531,
27563,
27596,
27628,
27661,
27693,
27726,
27758,
27790,
27823,
27855,
27887,
27920,
27952,
27984,
28017,
28049,
28081,
28113,
28146,
28178,
28210,
28242,
28274,
28306,
28338,
28370,
28403,
28435,
28467,
28499,
28531,
28563,
28595,
28627,
28659,
28691,
28722,
28754,
28786,
28818,
28850,
28882,
28914,
28945,
28977,
29009,
29041,
29073,
29104,
29136,
29168,
29199,
29231,
29263,
29294,
29326,
29358,
29389,
29421,
29453,
29484,
29516,
29547,
29579,
29610,
29642,
29673,
29705,
29736,
29768,
29799,
29830,
29862,
29893,
29925,
29956,
29987,
30019,
30050,
30081,
30112,
30144,
30175,
30206,
30237,
30269,
30300,
30331,
30362,
30393,
30424,
30456,
30487,
30518,
30549,
30580,
30611,
30642,
30673,
30704,
30735,
30766,
30797,
30828,
30859,
30890,
30921,
30952,
30983,
31014,
31045,
31075,
31106,
31137,
31168,
31199,
31229,
31260,
31291,
31322,
31353,
31383,
31414,
31445,
31475,
31506,
31537,
31567,
31598,
31629,
31659,
31690,
31720,
31751,
31782,
31812,
31843,
31873,
31904,
31934,
31965,
31995,
32026,
32056,
32087,
32117,
32147,
32178,
32208,
32239,
32269,
32299,
32330,
32360,
32390,
32421,
32451,
32481,
32511,
32542,
32572,
32602,
32632,
32663,
32693,
32723,
32753,
32783,
32814,
32844,
32874,
32904,
32934,
32964,
32994,
33024,
33054,
33084,
33114,
33144,
33174,
33204,
33234,
33264,
33294,
33324,
33354,
33384,
33414,
33444,
33474,
33504,
33534,
33563,
33593,
33623,
33653,
33683,
33713,
33742,
33772,
33802,
33832,
33861,
33891,
33921,
33951,
33980,
34010,
34040,
34069,
34099,
34129,
34158,
34188,
34218,
34247,
34277,
34306,
34336,
34365,
34395,
34424,
34454,
34484,
34513,
34543,
34572,
34601,
34631,
34660,
34690,
34719,
34749,
34778,
34807,
34837,
34866,
34896,
34925,
34954,
34984,
35013,
35042,
35072,
35101,
35130,
35159,
35189,
35218,
35247,
35276,
35306,
35335,
35364,
35393,
35422,
35452,
35481,
35510,
35539,
35568,
35597,
35626,
35655,
35685,
35714,
35743,
35772,
35801,
35830,
35859,
35888,
35917,
35946,
35975,
36004,
36033,
36062,
36091,
36120,
36149,
36177,
36206,
36235,
36264,
36293,
36322,
36351,
36380,
36408,
36437,
36466,
36495,
36524,
36552,
36581,
36610,
36639,
36667,
36696,
36725,
36754,
36782,
36811,
36840,
36868,
36897,
36926,
36954,
36983,
37012,
37040,
37069,
37098,
37126,
37155,
37183,
37212,
37240,
37269,
37298,
37326,
37355,
37383,
37412,
37440,
37469,
37497,
37525,
37554,
37582,
37611,
37639,
37668,
37696,
37724,
37753,
37781,
37810,
37838,
37866,
37895,
37923,
37951,
37980,
38008,
38036,
38065,
38093,
38121,
38149,
38178,
38206,
38234,
38262,
38291,
38319,
38347,
38375,
38403,
38432,
38460,
38488,
38516,
38544,
38572,
38600,
38628,
38657,
38685,
38713,
38741,
38769,
38797,
38825,
38853,
38881,
38909,
38937,
38965,
38993,
39021,
39049,
39077,
39105,
39133,
39161,
39189,
39217,
39245,
39273,
39301,
39328,
39356,
39384,
39412,
39440,
39468,
39496,
39524,
39551,
39579,
39607,
39635,
39663,
39690,
39718,
39746,
39774,
39801,
39829,
39857,
39885,
39912,
39940,
39968,
39996,
40023,
40051,
40079,
40106,
40134,
40162,
40189,
40217,
40244,
40272,
40300,
40327,
40355,
40382,
40410,
40438,
40465,
40493,
40520,
40548,
40575,
40603,
40630,
40658,
40685,
40713,
40740,
40768,
40795,
40823,
40850,
40878,
40905,
40932,
40960,
40987,
41015,
41042,
41069,
41097,
41124,
41151,
41179,
41206,
41234,
41261,
41288,
41315,
41343,
41370,
41397,
41425,
41452,
41479,
41506,
41534,
41561,
41588,
41615,
41643,
41670,
41697,
41724,
41751,
41779,
41806,
41833,
41860,
41887,
41914,
41942,
41969,
41996,
42023,
42050,
42077,
42104,
42131,
42158,
42185,
42213,
42240,
42267,
42294,
42321,
42348,
42375,
42402,
42429,
42456,
42483,
42510,
42537,
42564,
42591,
42618,
42645,
42671,
42698,
42725,
42752,
42779,
42806,
42833,
42860,
42887,
42914,
42940,
42967,
42994,
43021,
43048,
43075,
43102,
43128,
43155,
43182,
43209,
43236,
43262,
43289,
43316,
43343,
43369,
43396,
43423,
43450,
43476,
43503,
43530,
43556,
43583,
43610,
43636,
43663,
43690,
43716,
43743,
43770,
43796,
43823,
43850,
43876,
43903,
43930,
43956,
43983,
44009,
44036,
44062,
44089,
44116,
44142,
44169,
44195,
44222,
44248,
44275,
44301,
44328,
44354,
44381,
44407,
44434,
44460,
44487,
44513,
44540,
44566,
44592,
44619,
44645,
44672,
44698,
44724,
44751,
44777,
44804,
44830,
44856,
44883,
44909,
44935,
44962,
44988,
45014,
45041,
45067,
45093,
45120,
45146,
45172,
45199,
45225,
45251,
45277,
45304,
45330,
45356,
45382,
45409,
45435,
45461,
45487,
45513,
45540,
45566,
45592,
45618,
45644,
45671,
45697,
45723,
45749,
45775,
45801,
45827,
45853,
45880,
45906,
45932,
45958,
45984,
46010,
46036,
46062,
46088,
46114,
46140,
46166,
46192,
46219,
46245,
46271,
46297,
46323,
46349,
46375,
46401,
46427,
46453,
46478,
46504,
46530,
46556,
46582,
46608,
46634,
46660,
46686,
46712,
46738,
46764,
46790,
46816,
46841,
46867,
46893,
46919,
46945,
46971,
46997,
47022,
47048,
47074,
47100,
47126,
47152,
47177,
47203,
47229,
47255,
47280,
47306,
47332,
47358,
47384,
47409,
47435,
47461,
47486,
47512,
47538,
47564,
47589,
47615,
47641,
47666,
47692,
47718,
47743,
47769,
47795,
47820,
47846,
47872,
47897,
47923,
47949,
47974,
48000,
48025,
48051,
48077,
48102,
48128,
48153,
48179,
48205,
48230,
48256,
48281,
48307,
48332,
48358,
48383,
48409,
48434,
48460,
48485,
48511,
48536,
48562,
48587,
48613,
48638,
48664,
48689,
48715,
48740,
48766,
48791,
48816,
48842,
48867,
48893,
48918,
48943,
48969,
48994,
49020,
49045,
49070,
49096,
49121,
49146,
49172,
49197,
49222,
49248,
49273,
49298,
49324,
49349,
49374,
49400,
49425,
49450,
49476,
49501,
49526,
49551,
49577,
49602,
49627,
49652,
49678,
49703,
49728,
49753,
49779,
49804,
49829,
49854,
49879,
49905,
49930,
49955,
49980,
50005,
50030,
50056,
50081,
50106,
50131,
50156,
50181,
50206,
50231,
50257,
50282,
50307,
50332,
50357,
50382,
50407,
50432,
50457,
50482,
50507,
50533,
50558,
50583,
50608,
50633,
50658,
50683,
50708,
50733,
50758,
50783,
50808,
50833,
50858,
50883,
50908,
50933,
50958,
50983,
51008,
51032,
51057,
51082,
51107,
51132,
51157,
51182,
51207,
51232,
51257,
51282,
51307,
51331,
51356,
51381,
51406,
51431,
51456,
51481,
51506,
51530,
51555,
51580,
51605,
51630,
51655,
51679,
51704,
51729,
51754,
51779,
51803,
51828,
51853,
51878,
51902,
51927,
51952,
51977,
52001,
52026,
52051,
52076,
52100,
52125,
52150,
52175,
52199,
52224,
52249,
52273,
52298,
52323,
52347,
52372,
52397,
52421,
52446,
52471,
52495,
52520,
52545,
52569,
52594,
52619,
52643,
52668,
52692,
52717,
52742,
52766,
52791,
52815,
52840,
52865,
52889,
52914,
52938,
52963,
52987,
53012,
53036,
53061,
53085,
53110,
53135,
53159,
53184,
53208,
53233,
53257,
53282,
53306,
53330,
53355,
53379,
53404,
53428,
53453,
53477,
53502,
53526,
53551,
53575,
53599,
53624,
53648,
53673,
53697,
53722,
53746,
53770,
53795,
53819,
53844,
53868,
53892,
53917,
53941,
53965,
53990,
54014,
54038,
54063,
54087,
54111,
54136,
54160,
54184,
54209,
54233,
54257,
54282,
54306,
54330,
54354,
54379,
54403,
54427,
54452,
54476,
54500,
54524,
54549,
54573,
54597,
54621,
54645,
54670,
54694,
54718,
54742,
54767,
54791,
54815,
54839,
54863,
54888,
54912,
54936,
54960,
54984,
55008,
55033,
55057,
55081,
55105,
55129,
55153,
55177,
55201,
55226,
55250,
55274,
55298,
55322,
55346,
55370,
55394,
55418,
55442,
55467,
55491,
55515,
55539,
55563,
55587,
55611,
55635,
55659,
55683,
55707,
55731,
55755,
55779,
55803,
55827,
55851,
55875,
55899,
55923,
55947,
55971,
55995,
56019,
56043,
56067,
56091,
56115,
56139,
56163,
56187,
56211,
56235,
56258,
56282,
56306,
56330,
56354,
56378,
56402,
56426,
56450,
56474,
56497,
56521,
56545,
56569,
56593,
56617,
56641,
56665,
56688,
56712,
56736,
56760,
56784,
56808,
56831,
56855,
56879,
56903,
56927,
56950,
56974,
56998,
57022,
57046,
57069,
57093,
57117,
57141,
57165,
57188,
57212,
57236,
57260,
57283,
57307,
57331,
57354,
57378,
57402,
57426,
57449,
57473,
57497,
57520,
57544,
57568,
57592,
57615,
57639,
57663,
57686,
57710,
57734,
57757,
57781,
57805,
57828,
57852,
57875,
57899,
57923,
57946,
57970,
57994,
58017,
58041,
58064,
58088,
58112,
58135,
58159,
58182,
58206,
58230,
58253,
58277,
58300,
58324,
58347,
58371,
58394,
58418,
58442,
58465,
58489,
58512,
58536,
58559,
58583,
58606,
58630,
58653,
58677,
58700,
58724,
58747,
58771,
58794,
58818,
58841,
58865,
58888,
58912,
58935,
58958,
58982,
59005,
59029,
59052,
59076,
59099,
59122,
59146,
59169,
59193,
59216,
59240,
59263,
59286,
59310,
59333,
59357,
59380,
59403,
59427,
59450,
59473,
59497,
59520,
59543,
59567,
59590,
59613,
59637,
59660,
59683,
59707,
59730,
59753,
59777,
59800,
59823,
59847,
59870,
59893,
59917,
59940,
59963,
59986,
60010,
60033,
60056,
60079,
60103,
60126,
60149,
60172,
60196,
60219,
60242,
60265,
60289,
60312,
60335,
60358,
60382,
60405,
60428,
60451,
60474,
60498,
60521,
60544,
60567,
60590,
60613,
60637,
60660,
60683,
60706,
60729,
60752,
60776,
60799,
60822,
60845,
60868,
60891,
60914,
60938,
60961,
60984,
61007,
61030,
61053,
61076,
61099,
61122,
61145,
61169,
61192,
61215,
61238,
61261,
61284,
61307,
61330,
61353,
61376,
61399,
61422,
61445,
61468,
61491,
61514,
61537,
61560,
61583,
61606,
61629,
61652,
61675,
61698,
61721,
61744,
61767,
61790,
61813,
61836,
61859,
61882,
61905,
61928,
61951,
61974,
61997,
62020,
62043,
62066,
62089,
62112,
62135,
62158,
62181,
62204,
62226,
62249,
62272,
62295,
62318,
62341,
62364,
62387,
62410,
62432,
62455,
62478,
62501,
62524,
62547,
62570,
62593,
62615,
62638,
62661,
62684,
62707,
62730,
62752,
62775,
62798,
62821,
62844,
62867,
62889,
62912,
62935,
62958,
62981,
63003,
63026,
63049,
63072,
63095,
63117,
63140,
63163,
63186,
63208,
63231,
63254,
63277,
63299,
63322,
63345,
63368,
63390,
63413,
63436,
63459,
63481,
63504,
63527,
63549,
63572,
63595,
63618,
63640,
63663,
63686,
63708,
63731,
63754,
63776,
63799,
63822,
63844,
63867,
63890,
63912,
63935,
63958,
63980,
64003,
64026,
64048,
64071,
64093,
64116,
64139,
64161,
64184,
64206,
64229,
64252,
64274,
64297,
64319,
64342,
64365,
64387,
64410,
64432,
64455,
64478,
64500,
64523,
64545,
64568,
64590,
64613,
64635,
64658,
64681,
64703,
64726,
64748,
64771,
64793,
64816,
64838,
64861,
64883,
64906,
64928,
64951,
64973,
64996,
65018,
65041,
65063,
65086,
65108,
65131,
65153,
65176,
65198,
65220,
65243,
65265,
65288,
65310,
65333,
65355,
65378,
65400,
65422,
65445,
65467,
65490,
65512,
65535
};

#endif /* LUT_H */

