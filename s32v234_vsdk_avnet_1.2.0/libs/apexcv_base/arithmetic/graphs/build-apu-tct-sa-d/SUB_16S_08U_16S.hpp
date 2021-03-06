#ifndef _ACF_PROCESS_APU_SUB_16S_08U_16S
#define _ACF_PROCESS_APU_SUB_16S_08U_16S

#include <acf_process_apu.h>
#include <SUB_16S_08U_16S_APU_LOAD.h> //APU load associated with this process
#include <stdint.h>


//SCENARIO LIST*************************************************
static acf_scenario_buffer_data gScenarioBufferData0_SUB_16S_08U_16S[] = {{2, 1, 2, 0, {0, 0, 0, 0}}, {2, 1, 2, 0, {0, 0, 0, 0}}, {2, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData1_SUB_16S_08U_16S[] = {{4, 1, 2, 0, {0, 0, 0, 0}}, {4, 1, 2, 0, {0, 0, 0, 0}}, {4, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData2_SUB_16S_08U_16S[] = {{6, 1, 2, 0, {0, 0, 0, 0}}, {6, 1, 2, 0, {0, 0, 0, 0}}, {6, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData3_SUB_16S_08U_16S[] = {{8, 1, 2, 0, {0, 0, 0, 0}}, {8, 1, 2, 0, {0, 0, 0, 0}}, {8, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData4_SUB_16S_08U_16S[] = {{10, 1, 2, 0, {0, 0, 0, 0}}, {10, 1, 2, 0, {0, 0, 0, 0}}, {10, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData5_SUB_16S_08U_16S[] = {{12, 1, 2, 0, {0, 0, 0, 0}}, {12, 1, 2, 0, {0, 0, 0, 0}}, {12, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData6_SUB_16S_08U_16S[] = {{14, 1, 2, 0, {0, 0, 0, 0}}, {14, 1, 2, 0, {0, 0, 0, 0}}, {14, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData7_SUB_16S_08U_16S[] = {{16, 1, 2, 0, {0, 0, 0, 0}}, {16, 1, 2, 0, {0, 0, 0, 0}}, {16, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData8_SUB_16S_08U_16S[] = {{18, 1, 2, 0, {0, 0, 0, 0}}, {18, 1, 2, 0, {0, 0, 0, 0}}, {18, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData9_SUB_16S_08U_16S[] = {{20, 1, 2, 0, {0, 0, 0, 0}}, {20, 1, 2, 0, {0, 0, 0, 0}}, {20, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData10_SUB_16S_08U_16S[] = {{22, 1, 2, 0, {0, 0, 0, 0}}, {22, 1, 2, 0, {0, 0, 0, 0}}, {22, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData11_SUB_16S_08U_16S[] = {{24, 1, 2, 0, {0, 0, 0, 0}}, {24, 1, 2, 0, {0, 0, 0, 0}}, {24, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData12_SUB_16S_08U_16S[] = {{26, 1, 2, 0, {0, 0, 0, 0}}, {26, 1, 2, 0, {0, 0, 0, 0}}, {26, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData13_SUB_16S_08U_16S[] = {{28, 1, 2, 0, {0, 0, 0, 0}}, {28, 1, 2, 0, {0, 0, 0, 0}}, {28, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData14_SUB_16S_08U_16S[] = {{30, 1, 2, 0, {0, 0, 0, 0}}, {30, 1, 2, 0, {0, 0, 0, 0}}, {30, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData15_SUB_16S_08U_16S[] = {{32, 1, 2, 0, {0, 0, 0, 0}}, {32, 1, 2, 0, {0, 0, 0, 0}}, {32, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData16_SUB_16S_08U_16S[] = {{36, 1, 2, 0, {0, 0, 0, 0}}, {36, 1, 2, 0, {0, 0, 0, 0}}, {36, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData17_SUB_16S_08U_16S[] = {{40, 1, 2, 0, {0, 0, 0, 0}}, {40, 1, 2, 0, {0, 0, 0, 0}}, {40, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData18_SUB_16S_08U_16S[] = {{44, 1, 2, 0, {0, 0, 0, 0}}, {44, 1, 2, 0, {0, 0, 0, 0}}, {44, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData19_SUB_16S_08U_16S[] = {{48, 1, 2, 0, {0, 0, 0, 0}}, {48, 1, 2, 0, {0, 0, 0, 0}}, {48, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData20_SUB_16S_08U_16S[] = {{52, 1, 2, 0, {0, 0, 0, 0}}, {52, 1, 2, 0, {0, 0, 0, 0}}, {52, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData21_SUB_16S_08U_16S[] = {{56, 1, 2, 0, {0, 0, 0, 0}}, {56, 1, 2, 0, {0, 0, 0, 0}}, {56, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData22_SUB_16S_08U_16S[] = {{60, 1, 2, 0, {0, 0, 0, 0}}, {60, 1, 2, 0, {0, 0, 0, 0}}, {60, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData23_SUB_16S_08U_16S[] = {{64, 1, 2, 0, {0, 0, 0, 0}}, {64, 1, 2, 0, {0, 0, 0, 0}}, {64, 1, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData24_SUB_16S_08U_16S[] = {{2, 2, 2, 0, {0, 0, 0, 0}}, {2, 2, 2, 0, {0, 0, 0, 0}}, {2, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData25_SUB_16S_08U_16S[] = {{4, 2, 2, 0, {0, 0, 0, 0}}, {4, 2, 2, 0, {0, 0, 0, 0}}, {4, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData26_SUB_16S_08U_16S[] = {{6, 2, 2, 0, {0, 0, 0, 0}}, {6, 2, 2, 0, {0, 0, 0, 0}}, {6, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData27_SUB_16S_08U_16S[] = {{8, 2, 2, 0, {0, 0, 0, 0}}, {8, 2, 2, 0, {0, 0, 0, 0}}, {8, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData28_SUB_16S_08U_16S[] = {{10, 2, 2, 0, {0, 0, 0, 0}}, {10, 2, 2, 0, {0, 0, 0, 0}}, {10, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData29_SUB_16S_08U_16S[] = {{12, 2, 2, 0, {0, 0, 0, 0}}, {12, 2, 2, 0, {0, 0, 0, 0}}, {12, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData30_SUB_16S_08U_16S[] = {{14, 2, 2, 0, {0, 0, 0, 0}}, {14, 2, 2, 0, {0, 0, 0, 0}}, {14, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData31_SUB_16S_08U_16S[] = {{16, 2, 2, 0, {0, 0, 0, 0}}, {16, 2, 2, 0, {0, 0, 0, 0}}, {16, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData32_SUB_16S_08U_16S[] = {{18, 2, 2, 0, {0, 0, 0, 0}}, {18, 2, 2, 0, {0, 0, 0, 0}}, {18, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData33_SUB_16S_08U_16S[] = {{20, 2, 2, 0, {0, 0, 0, 0}}, {20, 2, 2, 0, {0, 0, 0, 0}}, {20, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData34_SUB_16S_08U_16S[] = {{22, 2, 2, 0, {0, 0, 0, 0}}, {22, 2, 2, 0, {0, 0, 0, 0}}, {22, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData35_SUB_16S_08U_16S[] = {{24, 2, 2, 0, {0, 0, 0, 0}}, {24, 2, 2, 0, {0, 0, 0, 0}}, {24, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData36_SUB_16S_08U_16S[] = {{26, 2, 2, 0, {0, 0, 0, 0}}, {26, 2, 2, 0, {0, 0, 0, 0}}, {26, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData37_SUB_16S_08U_16S[] = {{28, 2, 2, 0, {0, 0, 0, 0}}, {28, 2, 2, 0, {0, 0, 0, 0}}, {28, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData38_SUB_16S_08U_16S[] = {{30, 2, 2, 0, {0, 0, 0, 0}}, {30, 2, 2, 0, {0, 0, 0, 0}}, {30, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData39_SUB_16S_08U_16S[] = {{32, 2, 2, 0, {0, 0, 0, 0}}, {32, 2, 2, 0, {0, 0, 0, 0}}, {32, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData40_SUB_16S_08U_16S[] = {{36, 2, 2, 0, {0, 0, 0, 0}}, {36, 2, 2, 0, {0, 0, 0, 0}}, {36, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData41_SUB_16S_08U_16S[] = {{40, 2, 2, 0, {0, 0, 0, 0}}, {40, 2, 2, 0, {0, 0, 0, 0}}, {40, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData42_SUB_16S_08U_16S[] = {{44, 2, 2, 0, {0, 0, 0, 0}}, {44, 2, 2, 0, {0, 0, 0, 0}}, {44, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData43_SUB_16S_08U_16S[] = {{48, 2, 2, 0, {0, 0, 0, 0}}, {48, 2, 2, 0, {0, 0, 0, 0}}, {48, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData44_SUB_16S_08U_16S[] = {{52, 2, 2, 0, {0, 0, 0, 0}}, {52, 2, 2, 0, {0, 0, 0, 0}}, {52, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData45_SUB_16S_08U_16S[] = {{56, 2, 2, 0, {0, 0, 0, 0}}, {56, 2, 2, 0, {0, 0, 0, 0}}, {56, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData46_SUB_16S_08U_16S[] = {{60, 2, 2, 0, {0, 0, 0, 0}}, {60, 2, 2, 0, {0, 0, 0, 0}}, {60, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData47_SUB_16S_08U_16S[] = {{64, 2, 2, 0, {0, 0, 0, 0}}, {64, 2, 2, 0, {0, 0, 0, 0}}, {64, 2, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData48_SUB_16S_08U_16S[] = {{2, 3, 2, 0, {0, 0, 0, 0}}, {2, 3, 2, 0, {0, 0, 0, 0}}, {2, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData49_SUB_16S_08U_16S[] = {{4, 3, 2, 0, {0, 0, 0, 0}}, {4, 3, 2, 0, {0, 0, 0, 0}}, {4, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData50_SUB_16S_08U_16S[] = {{6, 3, 2, 0, {0, 0, 0, 0}}, {6, 3, 2, 0, {0, 0, 0, 0}}, {6, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData51_SUB_16S_08U_16S[] = {{8, 3, 2, 0, {0, 0, 0, 0}}, {8, 3, 2, 0, {0, 0, 0, 0}}, {8, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData52_SUB_16S_08U_16S[] = {{10, 3, 2, 0, {0, 0, 0, 0}}, {10, 3, 2, 0, {0, 0, 0, 0}}, {10, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData53_SUB_16S_08U_16S[] = {{12, 3, 2, 0, {0, 0, 0, 0}}, {12, 3, 2, 0, {0, 0, 0, 0}}, {12, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData54_SUB_16S_08U_16S[] = {{14, 3, 2, 0, {0, 0, 0, 0}}, {14, 3, 2, 0, {0, 0, 0, 0}}, {14, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData55_SUB_16S_08U_16S[] = {{16, 3, 2, 0, {0, 0, 0, 0}}, {16, 3, 2, 0, {0, 0, 0, 0}}, {16, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData56_SUB_16S_08U_16S[] = {{18, 3, 2, 0, {0, 0, 0, 0}}, {18, 3, 2, 0, {0, 0, 0, 0}}, {18, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData57_SUB_16S_08U_16S[] = {{20, 3, 2, 0, {0, 0, 0, 0}}, {20, 3, 2, 0, {0, 0, 0, 0}}, {20, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData58_SUB_16S_08U_16S[] = {{22, 3, 2, 0, {0, 0, 0, 0}}, {22, 3, 2, 0, {0, 0, 0, 0}}, {22, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData59_SUB_16S_08U_16S[] = {{24, 3, 2, 0, {0, 0, 0, 0}}, {24, 3, 2, 0, {0, 0, 0, 0}}, {24, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData60_SUB_16S_08U_16S[] = {{26, 3, 2, 0, {0, 0, 0, 0}}, {26, 3, 2, 0, {0, 0, 0, 0}}, {26, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData61_SUB_16S_08U_16S[] = {{28, 3, 2, 0, {0, 0, 0, 0}}, {28, 3, 2, 0, {0, 0, 0, 0}}, {28, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData62_SUB_16S_08U_16S[] = {{30, 3, 2, 0, {0, 0, 0, 0}}, {30, 3, 2, 0, {0, 0, 0, 0}}, {30, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData63_SUB_16S_08U_16S[] = {{32, 3, 2, 0, {0, 0, 0, 0}}, {32, 3, 2, 0, {0, 0, 0, 0}}, {32, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData64_SUB_16S_08U_16S[] = {{36, 3, 2, 0, {0, 0, 0, 0}}, {36, 3, 2, 0, {0, 0, 0, 0}}, {36, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData65_SUB_16S_08U_16S[] = {{40, 3, 2, 0, {0, 0, 0, 0}}, {40, 3, 2, 0, {0, 0, 0, 0}}, {40, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData66_SUB_16S_08U_16S[] = {{44, 3, 2, 0, {0, 0, 0, 0}}, {44, 3, 2, 0, {0, 0, 0, 0}}, {44, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData67_SUB_16S_08U_16S[] = {{48, 3, 2, 0, {0, 0, 0, 0}}, {48, 3, 2, 0, {0, 0, 0, 0}}, {48, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData68_SUB_16S_08U_16S[] = {{52, 3, 2, 0, {0, 0, 0, 0}}, {52, 3, 2, 0, {0, 0, 0, 0}}, {52, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData69_SUB_16S_08U_16S[] = {{56, 3, 2, 0, {0, 0, 0, 0}}, {56, 3, 2, 0, {0, 0, 0, 0}}, {56, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData70_SUB_16S_08U_16S[] = {{60, 3, 2, 0, {0, 0, 0, 0}}, {60, 3, 2, 0, {0, 0, 0, 0}}, {60, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData71_SUB_16S_08U_16S[] = {{64, 3, 2, 0, {0, 0, 0, 0}}, {64, 3, 2, 0, {0, 0, 0, 0}}, {64, 3, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData72_SUB_16S_08U_16S[] = {{2, 4, 2, 0, {0, 0, 0, 0}}, {2, 4, 2, 0, {0, 0, 0, 0}}, {2, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData73_SUB_16S_08U_16S[] = {{4, 4, 2, 0, {0, 0, 0, 0}}, {4, 4, 2, 0, {0, 0, 0, 0}}, {4, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData74_SUB_16S_08U_16S[] = {{6, 4, 2, 0, {0, 0, 0, 0}}, {6, 4, 2, 0, {0, 0, 0, 0}}, {6, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData75_SUB_16S_08U_16S[] = {{8, 4, 2, 0, {0, 0, 0, 0}}, {8, 4, 2, 0, {0, 0, 0, 0}}, {8, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData76_SUB_16S_08U_16S[] = {{10, 4, 2, 0, {0, 0, 0, 0}}, {10, 4, 2, 0, {0, 0, 0, 0}}, {10, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData77_SUB_16S_08U_16S[] = {{12, 4, 2, 0, {0, 0, 0, 0}}, {12, 4, 2, 0, {0, 0, 0, 0}}, {12, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData78_SUB_16S_08U_16S[] = {{14, 4, 2, 0, {0, 0, 0, 0}}, {14, 4, 2, 0, {0, 0, 0, 0}}, {14, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData79_SUB_16S_08U_16S[] = {{16, 4, 2, 0, {0, 0, 0, 0}}, {16, 4, 2, 0, {0, 0, 0, 0}}, {16, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData80_SUB_16S_08U_16S[] = {{18, 4, 2, 0, {0, 0, 0, 0}}, {18, 4, 2, 0, {0, 0, 0, 0}}, {18, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData81_SUB_16S_08U_16S[] = {{20, 4, 2, 0, {0, 0, 0, 0}}, {20, 4, 2, 0, {0, 0, 0, 0}}, {20, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData82_SUB_16S_08U_16S[] = {{22, 4, 2, 0, {0, 0, 0, 0}}, {22, 4, 2, 0, {0, 0, 0, 0}}, {22, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData83_SUB_16S_08U_16S[] = {{24, 4, 2, 0, {0, 0, 0, 0}}, {24, 4, 2, 0, {0, 0, 0, 0}}, {24, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData84_SUB_16S_08U_16S[] = {{26, 4, 2, 0, {0, 0, 0, 0}}, {26, 4, 2, 0, {0, 0, 0, 0}}, {26, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData85_SUB_16S_08U_16S[] = {{28, 4, 2, 0, {0, 0, 0, 0}}, {28, 4, 2, 0, {0, 0, 0, 0}}, {28, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData86_SUB_16S_08U_16S[] = {{30, 4, 2, 0, {0, 0, 0, 0}}, {30, 4, 2, 0, {0, 0, 0, 0}}, {30, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData87_SUB_16S_08U_16S[] = {{32, 4, 2, 0, {0, 0, 0, 0}}, {32, 4, 2, 0, {0, 0, 0, 0}}, {32, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData88_SUB_16S_08U_16S[] = {{36, 4, 2, 0, {0, 0, 0, 0}}, {36, 4, 2, 0, {0, 0, 0, 0}}, {36, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData89_SUB_16S_08U_16S[] = {{40, 4, 2, 0, {0, 0, 0, 0}}, {40, 4, 2, 0, {0, 0, 0, 0}}, {40, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData90_SUB_16S_08U_16S[] = {{44, 4, 2, 0, {0, 0, 0, 0}}, {44, 4, 2, 0, {0, 0, 0, 0}}, {44, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData91_SUB_16S_08U_16S[] = {{48, 4, 2, 0, {0, 0, 0, 0}}, {48, 4, 2, 0, {0, 0, 0, 0}}, {48, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData92_SUB_16S_08U_16S[] = {{52, 4, 2, 0, {0, 0, 0, 0}}, {52, 4, 2, 0, {0, 0, 0, 0}}, {52, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData93_SUB_16S_08U_16S[] = {{56, 4, 2, 0, {0, 0, 0, 0}}, {56, 4, 2, 0, {0, 0, 0, 0}}, {56, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData94_SUB_16S_08U_16S[] = {{60, 4, 2, 0, {0, 0, 0, 0}}, {60, 4, 2, 0, {0, 0, 0, 0}}, {60, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData95_SUB_16S_08U_16S[] = {{64, 4, 2, 0, {0, 0, 0, 0}}, {64, 4, 2, 0, {0, 0, 0, 0}}, {64, 4, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData96_SUB_16S_08U_16S[] = {{2, 5, 2, 0, {0, 0, 0, 0}}, {2, 5, 2, 0, {0, 0, 0, 0}}, {2, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData97_SUB_16S_08U_16S[] = {{4, 5, 2, 0, {0, 0, 0, 0}}, {4, 5, 2, 0, {0, 0, 0, 0}}, {4, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData98_SUB_16S_08U_16S[] = {{6, 5, 2, 0, {0, 0, 0, 0}}, {6, 5, 2, 0, {0, 0, 0, 0}}, {6, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData99_SUB_16S_08U_16S[] = {{8, 5, 2, 0, {0, 0, 0, 0}}, {8, 5, 2, 0, {0, 0, 0, 0}}, {8, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData100_SUB_16S_08U_16S[] = {{10, 5, 2, 0, {0, 0, 0, 0}}, {10, 5, 2, 0, {0, 0, 0, 0}}, {10, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData101_SUB_16S_08U_16S[] = {{12, 5, 2, 0, {0, 0, 0, 0}}, {12, 5, 2, 0, {0, 0, 0, 0}}, {12, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData102_SUB_16S_08U_16S[] = {{14, 5, 2, 0, {0, 0, 0, 0}}, {14, 5, 2, 0, {0, 0, 0, 0}}, {14, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData103_SUB_16S_08U_16S[] = {{16, 5, 2, 0, {0, 0, 0, 0}}, {16, 5, 2, 0, {0, 0, 0, 0}}, {16, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData104_SUB_16S_08U_16S[] = {{18, 5, 2, 0, {0, 0, 0, 0}}, {18, 5, 2, 0, {0, 0, 0, 0}}, {18, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData105_SUB_16S_08U_16S[] = {{20, 5, 2, 0, {0, 0, 0, 0}}, {20, 5, 2, 0, {0, 0, 0, 0}}, {20, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData106_SUB_16S_08U_16S[] = {{22, 5, 2, 0, {0, 0, 0, 0}}, {22, 5, 2, 0, {0, 0, 0, 0}}, {22, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData107_SUB_16S_08U_16S[] = {{24, 5, 2, 0, {0, 0, 0, 0}}, {24, 5, 2, 0, {0, 0, 0, 0}}, {24, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData108_SUB_16S_08U_16S[] = {{26, 5, 2, 0, {0, 0, 0, 0}}, {26, 5, 2, 0, {0, 0, 0, 0}}, {26, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData109_SUB_16S_08U_16S[] = {{28, 5, 2, 0, {0, 0, 0, 0}}, {28, 5, 2, 0, {0, 0, 0, 0}}, {28, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData110_SUB_16S_08U_16S[] = {{30, 5, 2, 0, {0, 0, 0, 0}}, {30, 5, 2, 0, {0, 0, 0, 0}}, {30, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData111_SUB_16S_08U_16S[] = {{32, 5, 2, 0, {0, 0, 0, 0}}, {32, 5, 2, 0, {0, 0, 0, 0}}, {32, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData112_SUB_16S_08U_16S[] = {{36, 5, 2, 0, {0, 0, 0, 0}}, {36, 5, 2, 0, {0, 0, 0, 0}}, {36, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData113_SUB_16S_08U_16S[] = {{40, 5, 2, 0, {0, 0, 0, 0}}, {40, 5, 2, 0, {0, 0, 0, 0}}, {40, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData114_SUB_16S_08U_16S[] = {{44, 5, 2, 0, {0, 0, 0, 0}}, {44, 5, 2, 0, {0, 0, 0, 0}}, {44, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData115_SUB_16S_08U_16S[] = {{48, 5, 2, 0, {0, 0, 0, 0}}, {48, 5, 2, 0, {0, 0, 0, 0}}, {48, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData116_SUB_16S_08U_16S[] = {{52, 5, 2, 0, {0, 0, 0, 0}}, {52, 5, 2, 0, {0, 0, 0, 0}}, {52, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData117_SUB_16S_08U_16S[] = {{56, 5, 2, 0, {0, 0, 0, 0}}, {56, 5, 2, 0, {0, 0, 0, 0}}, {56, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData118_SUB_16S_08U_16S[] = {{60, 5, 2, 0, {0, 0, 0, 0}}, {60, 5, 2, 0, {0, 0, 0, 0}}, {60, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData119_SUB_16S_08U_16S[] = {{64, 5, 2, 0, {0, 0, 0, 0}}, {64, 5, 2, 0, {0, 0, 0, 0}}, {64, 5, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData120_SUB_16S_08U_16S[] = {{2, 6, 2, 0, {0, 0, 0, 0}}, {2, 6, 2, 0, {0, 0, 0, 0}}, {2, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData121_SUB_16S_08U_16S[] = {{4, 6, 2, 0, {0, 0, 0, 0}}, {4, 6, 2, 0, {0, 0, 0, 0}}, {4, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData122_SUB_16S_08U_16S[] = {{6, 6, 2, 0, {0, 0, 0, 0}}, {6, 6, 2, 0, {0, 0, 0, 0}}, {6, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData123_SUB_16S_08U_16S[] = {{8, 6, 2, 0, {0, 0, 0, 0}}, {8, 6, 2, 0, {0, 0, 0, 0}}, {8, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData124_SUB_16S_08U_16S[] = {{10, 6, 2, 0, {0, 0, 0, 0}}, {10, 6, 2, 0, {0, 0, 0, 0}}, {10, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData125_SUB_16S_08U_16S[] = {{12, 6, 2, 0, {0, 0, 0, 0}}, {12, 6, 2, 0, {0, 0, 0, 0}}, {12, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData126_SUB_16S_08U_16S[] = {{14, 6, 2, 0, {0, 0, 0, 0}}, {14, 6, 2, 0, {0, 0, 0, 0}}, {14, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData127_SUB_16S_08U_16S[] = {{16, 6, 2, 0, {0, 0, 0, 0}}, {16, 6, 2, 0, {0, 0, 0, 0}}, {16, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData128_SUB_16S_08U_16S[] = {{18, 6, 2, 0, {0, 0, 0, 0}}, {18, 6, 2, 0, {0, 0, 0, 0}}, {18, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData129_SUB_16S_08U_16S[] = {{20, 6, 2, 0, {0, 0, 0, 0}}, {20, 6, 2, 0, {0, 0, 0, 0}}, {20, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData130_SUB_16S_08U_16S[] = {{22, 6, 2, 0, {0, 0, 0, 0}}, {22, 6, 2, 0, {0, 0, 0, 0}}, {22, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData131_SUB_16S_08U_16S[] = {{24, 6, 2, 0, {0, 0, 0, 0}}, {24, 6, 2, 0, {0, 0, 0, 0}}, {24, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData132_SUB_16S_08U_16S[] = {{26, 6, 2, 0, {0, 0, 0, 0}}, {26, 6, 2, 0, {0, 0, 0, 0}}, {26, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData133_SUB_16S_08U_16S[] = {{28, 6, 2, 0, {0, 0, 0, 0}}, {28, 6, 2, 0, {0, 0, 0, 0}}, {28, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData134_SUB_16S_08U_16S[] = {{30, 6, 2, 0, {0, 0, 0, 0}}, {30, 6, 2, 0, {0, 0, 0, 0}}, {30, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData135_SUB_16S_08U_16S[] = {{32, 6, 2, 0, {0, 0, 0, 0}}, {32, 6, 2, 0, {0, 0, 0, 0}}, {32, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData136_SUB_16S_08U_16S[] = {{36, 6, 2, 0, {0, 0, 0, 0}}, {36, 6, 2, 0, {0, 0, 0, 0}}, {36, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData137_SUB_16S_08U_16S[] = {{40, 6, 2, 0, {0, 0, 0, 0}}, {40, 6, 2, 0, {0, 0, 0, 0}}, {40, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData138_SUB_16S_08U_16S[] = {{44, 6, 2, 0, {0, 0, 0, 0}}, {44, 6, 2, 0, {0, 0, 0, 0}}, {44, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData139_SUB_16S_08U_16S[] = {{48, 6, 2, 0, {0, 0, 0, 0}}, {48, 6, 2, 0, {0, 0, 0, 0}}, {48, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData140_SUB_16S_08U_16S[] = {{52, 6, 2, 0, {0, 0, 0, 0}}, {52, 6, 2, 0, {0, 0, 0, 0}}, {52, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData141_SUB_16S_08U_16S[] = {{56, 6, 2, 0, {0, 0, 0, 0}}, {56, 6, 2, 0, {0, 0, 0, 0}}, {56, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData142_SUB_16S_08U_16S[] = {{60, 6, 2, 0, {0, 0, 0, 0}}, {60, 6, 2, 0, {0, 0, 0, 0}}, {60, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData143_SUB_16S_08U_16S[] = {{64, 6, 2, 0, {0, 0, 0, 0}}, {64, 6, 2, 0, {0, 0, 0, 0}}, {64, 6, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData144_SUB_16S_08U_16S[] = {{2, 8, 2, 0, {0, 0, 0, 0}}, {2, 8, 2, 0, {0, 0, 0, 0}}, {2, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData145_SUB_16S_08U_16S[] = {{4, 8, 2, 0, {0, 0, 0, 0}}, {4, 8, 2, 0, {0, 0, 0, 0}}, {4, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData146_SUB_16S_08U_16S[] = {{6, 8, 2, 0, {0, 0, 0, 0}}, {6, 8, 2, 0, {0, 0, 0, 0}}, {6, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData147_SUB_16S_08U_16S[] = {{8, 8, 2, 0, {0, 0, 0, 0}}, {8, 8, 2, 0, {0, 0, 0, 0}}, {8, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData148_SUB_16S_08U_16S[] = {{10, 8, 2, 0, {0, 0, 0, 0}}, {10, 8, 2, 0, {0, 0, 0, 0}}, {10, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData149_SUB_16S_08U_16S[] = {{12, 8, 2, 0, {0, 0, 0, 0}}, {12, 8, 2, 0, {0, 0, 0, 0}}, {12, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData150_SUB_16S_08U_16S[] = {{14, 8, 2, 0, {0, 0, 0, 0}}, {14, 8, 2, 0, {0, 0, 0, 0}}, {14, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData151_SUB_16S_08U_16S[] = {{16, 8, 2, 0, {0, 0, 0, 0}}, {16, 8, 2, 0, {0, 0, 0, 0}}, {16, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData152_SUB_16S_08U_16S[] = {{18, 8, 2, 0, {0, 0, 0, 0}}, {18, 8, 2, 0, {0, 0, 0, 0}}, {18, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData153_SUB_16S_08U_16S[] = {{20, 8, 2, 0, {0, 0, 0, 0}}, {20, 8, 2, 0, {0, 0, 0, 0}}, {20, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData154_SUB_16S_08U_16S[] = {{22, 8, 2, 0, {0, 0, 0, 0}}, {22, 8, 2, 0, {0, 0, 0, 0}}, {22, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData155_SUB_16S_08U_16S[] = {{24, 8, 2, 0, {0, 0, 0, 0}}, {24, 8, 2, 0, {0, 0, 0, 0}}, {24, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData156_SUB_16S_08U_16S[] = {{26, 8, 2, 0, {0, 0, 0, 0}}, {26, 8, 2, 0, {0, 0, 0, 0}}, {26, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData157_SUB_16S_08U_16S[] = {{28, 8, 2, 0, {0, 0, 0, 0}}, {28, 8, 2, 0, {0, 0, 0, 0}}, {28, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData158_SUB_16S_08U_16S[] = {{30, 8, 2, 0, {0, 0, 0, 0}}, {30, 8, 2, 0, {0, 0, 0, 0}}, {30, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData159_SUB_16S_08U_16S[] = {{32, 8, 2, 0, {0, 0, 0, 0}}, {32, 8, 2, 0, {0, 0, 0, 0}}, {32, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData160_SUB_16S_08U_16S[] = {{36, 8, 2, 0, {0, 0, 0, 0}}, {36, 8, 2, 0, {0, 0, 0, 0}}, {36, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData161_SUB_16S_08U_16S[] = {{40, 8, 2, 0, {0, 0, 0, 0}}, {40, 8, 2, 0, {0, 0, 0, 0}}, {40, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData162_SUB_16S_08U_16S[] = {{44, 8, 2, 0, {0, 0, 0, 0}}, {44, 8, 2, 0, {0, 0, 0, 0}}, {44, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData163_SUB_16S_08U_16S[] = {{48, 8, 2, 0, {0, 0, 0, 0}}, {48, 8, 2, 0, {0, 0, 0, 0}}, {48, 8, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData164_SUB_16S_08U_16S[] = {{2, 10, 2, 0, {0, 0, 0, 0}}, {2, 10, 2, 0, {0, 0, 0, 0}}, {2, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData165_SUB_16S_08U_16S[] = {{4, 10, 2, 0, {0, 0, 0, 0}}, {4, 10, 2, 0, {0, 0, 0, 0}}, {4, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData166_SUB_16S_08U_16S[] = {{6, 10, 2, 0, {0, 0, 0, 0}}, {6, 10, 2, 0, {0, 0, 0, 0}}, {6, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData167_SUB_16S_08U_16S[] = {{8, 10, 2, 0, {0, 0, 0, 0}}, {8, 10, 2, 0, {0, 0, 0, 0}}, {8, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData168_SUB_16S_08U_16S[] = {{10, 10, 2, 0, {0, 0, 0, 0}}, {10, 10, 2, 0, {0, 0, 0, 0}}, {10, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData169_SUB_16S_08U_16S[] = {{12, 10, 2, 0, {0, 0, 0, 0}}, {12, 10, 2, 0, {0, 0, 0, 0}}, {12, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData170_SUB_16S_08U_16S[] = {{14, 10, 2, 0, {0, 0, 0, 0}}, {14, 10, 2, 0, {0, 0, 0, 0}}, {14, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData171_SUB_16S_08U_16S[] = {{16, 10, 2, 0, {0, 0, 0, 0}}, {16, 10, 2, 0, {0, 0, 0, 0}}, {16, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData172_SUB_16S_08U_16S[] = {{18, 10, 2, 0, {0, 0, 0, 0}}, {18, 10, 2, 0, {0, 0, 0, 0}}, {18, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData173_SUB_16S_08U_16S[] = {{20, 10, 2, 0, {0, 0, 0, 0}}, {20, 10, 2, 0, {0, 0, 0, 0}}, {20, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData174_SUB_16S_08U_16S[] = {{22, 10, 2, 0, {0, 0, 0, 0}}, {22, 10, 2, 0, {0, 0, 0, 0}}, {22, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData175_SUB_16S_08U_16S[] = {{24, 10, 2, 0, {0, 0, 0, 0}}, {24, 10, 2, 0, {0, 0, 0, 0}}, {24, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData176_SUB_16S_08U_16S[] = {{26, 10, 2, 0, {0, 0, 0, 0}}, {26, 10, 2, 0, {0, 0, 0, 0}}, {26, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData177_SUB_16S_08U_16S[] = {{28, 10, 2, 0, {0, 0, 0, 0}}, {28, 10, 2, 0, {0, 0, 0, 0}}, {28, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData178_SUB_16S_08U_16S[] = {{30, 10, 2, 0, {0, 0, 0, 0}}, {30, 10, 2, 0, {0, 0, 0, 0}}, {30, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData179_SUB_16S_08U_16S[] = {{32, 10, 2, 0, {0, 0, 0, 0}}, {32, 10, 2, 0, {0, 0, 0, 0}}, {32, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData180_SUB_16S_08U_16S[] = {{36, 10, 2, 0, {0, 0, 0, 0}}, {36, 10, 2, 0, {0, 0, 0, 0}}, {36, 10, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData181_SUB_16S_08U_16S[] = {{2, 12, 2, 0, {0, 0, 0, 0}}, {2, 12, 2, 0, {0, 0, 0, 0}}, {2, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData182_SUB_16S_08U_16S[] = {{4, 12, 2, 0, {0, 0, 0, 0}}, {4, 12, 2, 0, {0, 0, 0, 0}}, {4, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData183_SUB_16S_08U_16S[] = {{6, 12, 2, 0, {0, 0, 0, 0}}, {6, 12, 2, 0, {0, 0, 0, 0}}, {6, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData184_SUB_16S_08U_16S[] = {{8, 12, 2, 0, {0, 0, 0, 0}}, {8, 12, 2, 0, {0, 0, 0, 0}}, {8, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData185_SUB_16S_08U_16S[] = {{10, 12, 2, 0, {0, 0, 0, 0}}, {10, 12, 2, 0, {0, 0, 0, 0}}, {10, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData186_SUB_16S_08U_16S[] = {{12, 12, 2, 0, {0, 0, 0, 0}}, {12, 12, 2, 0, {0, 0, 0, 0}}, {12, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData187_SUB_16S_08U_16S[] = {{14, 12, 2, 0, {0, 0, 0, 0}}, {14, 12, 2, 0, {0, 0, 0, 0}}, {14, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData188_SUB_16S_08U_16S[] = {{16, 12, 2, 0, {0, 0, 0, 0}}, {16, 12, 2, 0, {0, 0, 0, 0}}, {16, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData189_SUB_16S_08U_16S[] = {{18, 12, 2, 0, {0, 0, 0, 0}}, {18, 12, 2, 0, {0, 0, 0, 0}}, {18, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData190_SUB_16S_08U_16S[] = {{20, 12, 2, 0, {0, 0, 0, 0}}, {20, 12, 2, 0, {0, 0, 0, 0}}, {20, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData191_SUB_16S_08U_16S[] = {{22, 12, 2, 0, {0, 0, 0, 0}}, {22, 12, 2, 0, {0, 0, 0, 0}}, {22, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData192_SUB_16S_08U_16S[] = {{24, 12, 2, 0, {0, 0, 0, 0}}, {24, 12, 2, 0, {0, 0, 0, 0}}, {24, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData193_SUB_16S_08U_16S[] = {{26, 12, 2, 0, {0, 0, 0, 0}}, {26, 12, 2, 0, {0, 0, 0, 0}}, {26, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData194_SUB_16S_08U_16S[] = {{28, 12, 2, 0, {0, 0, 0, 0}}, {28, 12, 2, 0, {0, 0, 0, 0}}, {28, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData195_SUB_16S_08U_16S[] = {{30, 12, 2, 0, {0, 0, 0, 0}}, {30, 12, 2, 0, {0, 0, 0, 0}}, {30, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData196_SUB_16S_08U_16S[] = {{32, 12, 2, 0, {0, 0, 0, 0}}, {32, 12, 2, 0, {0, 0, 0, 0}}, {32, 12, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData197_SUB_16S_08U_16S[] = {{2, 14, 2, 0, {0, 0, 0, 0}}, {2, 14, 2, 0, {0, 0, 0, 0}}, {2, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData198_SUB_16S_08U_16S[] = {{4, 14, 2, 0, {0, 0, 0, 0}}, {4, 14, 2, 0, {0, 0, 0, 0}}, {4, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData199_SUB_16S_08U_16S[] = {{6, 14, 2, 0, {0, 0, 0, 0}}, {6, 14, 2, 0, {0, 0, 0, 0}}, {6, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData200_SUB_16S_08U_16S[] = {{8, 14, 2, 0, {0, 0, 0, 0}}, {8, 14, 2, 0, {0, 0, 0, 0}}, {8, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData201_SUB_16S_08U_16S[] = {{10, 14, 2, 0, {0, 0, 0, 0}}, {10, 14, 2, 0, {0, 0, 0, 0}}, {10, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData202_SUB_16S_08U_16S[] = {{12, 14, 2, 0, {0, 0, 0, 0}}, {12, 14, 2, 0, {0, 0, 0, 0}}, {12, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData203_SUB_16S_08U_16S[] = {{14, 14, 2, 0, {0, 0, 0, 0}}, {14, 14, 2, 0, {0, 0, 0, 0}}, {14, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData204_SUB_16S_08U_16S[] = {{16, 14, 2, 0, {0, 0, 0, 0}}, {16, 14, 2, 0, {0, 0, 0, 0}}, {16, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData205_SUB_16S_08U_16S[] = {{18, 14, 2, 0, {0, 0, 0, 0}}, {18, 14, 2, 0, {0, 0, 0, 0}}, {18, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData206_SUB_16S_08U_16S[] = {{20, 14, 2, 0, {0, 0, 0, 0}}, {20, 14, 2, 0, {0, 0, 0, 0}}, {20, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData207_SUB_16S_08U_16S[] = {{22, 14, 2, 0, {0, 0, 0, 0}}, {22, 14, 2, 0, {0, 0, 0, 0}}, {22, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData208_SUB_16S_08U_16S[] = {{24, 14, 2, 0, {0, 0, 0, 0}}, {24, 14, 2, 0, {0, 0, 0, 0}}, {24, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData209_SUB_16S_08U_16S[] = {{26, 14, 2, 0, {0, 0, 0, 0}}, {26, 14, 2, 0, {0, 0, 0, 0}}, {26, 14, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData210_SUB_16S_08U_16S[] = {{2, 16, 2, 0, {0, 0, 0, 0}}, {2, 16, 2, 0, {0, 0, 0, 0}}, {2, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData211_SUB_16S_08U_16S[] = {{4, 16, 2, 0, {0, 0, 0, 0}}, {4, 16, 2, 0, {0, 0, 0, 0}}, {4, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData212_SUB_16S_08U_16S[] = {{6, 16, 2, 0, {0, 0, 0, 0}}, {6, 16, 2, 0, {0, 0, 0, 0}}, {6, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData213_SUB_16S_08U_16S[] = {{8, 16, 2, 0, {0, 0, 0, 0}}, {8, 16, 2, 0, {0, 0, 0, 0}}, {8, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData214_SUB_16S_08U_16S[] = {{10, 16, 2, 0, {0, 0, 0, 0}}, {10, 16, 2, 0, {0, 0, 0, 0}}, {10, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData215_SUB_16S_08U_16S[] = {{12, 16, 2, 0, {0, 0, 0, 0}}, {12, 16, 2, 0, {0, 0, 0, 0}}, {12, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData216_SUB_16S_08U_16S[] = {{14, 16, 2, 0, {0, 0, 0, 0}}, {14, 16, 2, 0, {0, 0, 0, 0}}, {14, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData217_SUB_16S_08U_16S[] = {{16, 16, 2, 0, {0, 0, 0, 0}}, {16, 16, 2, 0, {0, 0, 0, 0}}, {16, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData218_SUB_16S_08U_16S[] = {{18, 16, 2, 0, {0, 0, 0, 0}}, {18, 16, 2, 0, {0, 0, 0, 0}}, {18, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData219_SUB_16S_08U_16S[] = {{20, 16, 2, 0, {0, 0, 0, 0}}, {20, 16, 2, 0, {0, 0, 0, 0}}, {20, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData220_SUB_16S_08U_16S[] = {{22, 16, 2, 0, {0, 0, 0, 0}}, {22, 16, 2, 0, {0, 0, 0, 0}}, {22, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData221_SUB_16S_08U_16S[] = {{24, 16, 2, 0, {0, 0, 0, 0}}, {24, 16, 2, 0, {0, 0, 0, 0}}, {24, 16, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData222_SUB_16S_08U_16S[] = {{2, 18, 2, 0, {0, 0, 0, 0}}, {2, 18, 2, 0, {0, 0, 0, 0}}, {2, 18, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData223_SUB_16S_08U_16S[] = {{4, 18, 2, 0, {0, 0, 0, 0}}, {4, 18, 2, 0, {0, 0, 0, 0}}, {4, 18, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData224_SUB_16S_08U_16S[] = {{6, 18, 2, 0, {0, 0, 0, 0}}, {6, 18, 2, 0, {0, 0, 0, 0}}, {6, 18, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData225_SUB_16S_08U_16S[] = {{8, 18, 2, 0, {0, 0, 0, 0}}, {8, 18, 2, 0, {0, 0, 0, 0}}, {8, 18, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData226_SUB_16S_08U_16S[] = {{10, 18, 2, 0, {0, 0, 0, 0}}, {10, 18, 2, 0, {0, 0, 0, 0}}, {10, 18, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData227_SUB_16S_08U_16S[] = {{12, 18, 2, 0, {0, 0, 0, 0}}, {12, 18, 2, 0, {0, 0, 0, 0}}, {12, 18, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData228_SUB_16S_08U_16S[] = {{14, 18, 2, 0, {0, 0, 0, 0}}, {14, 18, 2, 0, {0, 0, 0, 0}}, {14, 18, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData229_SUB_16S_08U_16S[] = {{16, 18, 2, 0, {0, 0, 0, 0}}, {16, 18, 2, 0, {0, 0, 0, 0}}, {16, 18, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData230_SUB_16S_08U_16S[] = {{18, 18, 2, 0, {0, 0, 0, 0}}, {18, 18, 2, 0, {0, 0, 0, 0}}, {18, 18, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData231_SUB_16S_08U_16S[] = {{20, 18, 2, 0, {0, 0, 0, 0}}, {20, 18, 2, 0, {0, 0, 0, 0}}, {20, 18, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData232_SUB_16S_08U_16S[] = {{2, 20, 2, 0, {0, 0, 0, 0}}, {2, 20, 2, 0, {0, 0, 0, 0}}, {2, 20, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData233_SUB_16S_08U_16S[] = {{4, 20, 2, 0, {0, 0, 0, 0}}, {4, 20, 2, 0, {0, 0, 0, 0}}, {4, 20, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData234_SUB_16S_08U_16S[] = {{6, 20, 2, 0, {0, 0, 0, 0}}, {6, 20, 2, 0, {0, 0, 0, 0}}, {6, 20, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData235_SUB_16S_08U_16S[] = {{8, 20, 2, 0, {0, 0, 0, 0}}, {8, 20, 2, 0, {0, 0, 0, 0}}, {8, 20, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData236_SUB_16S_08U_16S[] = {{10, 20, 2, 0, {0, 0, 0, 0}}, {10, 20, 2, 0, {0, 0, 0, 0}}, {10, 20, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData237_SUB_16S_08U_16S[] = {{12, 20, 2, 0, {0, 0, 0, 0}}, {12, 20, 2, 0, {0, 0, 0, 0}}, {12, 20, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData238_SUB_16S_08U_16S[] = {{14, 20, 2, 0, {0, 0, 0, 0}}, {14, 20, 2, 0, {0, 0, 0, 0}}, {14, 20, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData239_SUB_16S_08U_16S[] = {{16, 20, 2, 0, {0, 0, 0, 0}}, {16, 20, 2, 0, {0, 0, 0, 0}}, {16, 20, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData240_SUB_16S_08U_16S[] = {{18, 20, 2, 0, {0, 0, 0, 0}}, {18, 20, 2, 0, {0, 0, 0, 0}}, {18, 20, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData241_SUB_16S_08U_16S[] = {{2, 22, 2, 0, {0, 0, 0, 0}}, {2, 22, 2, 0, {0, 0, 0, 0}}, {2, 22, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData242_SUB_16S_08U_16S[] = {{4, 22, 2, 0, {0, 0, 0, 0}}, {4, 22, 2, 0, {0, 0, 0, 0}}, {4, 22, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData243_SUB_16S_08U_16S[] = {{6, 22, 2, 0, {0, 0, 0, 0}}, {6, 22, 2, 0, {0, 0, 0, 0}}, {6, 22, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData244_SUB_16S_08U_16S[] = {{8, 22, 2, 0, {0, 0, 0, 0}}, {8, 22, 2, 0, {0, 0, 0, 0}}, {8, 22, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData245_SUB_16S_08U_16S[] = {{10, 22, 2, 0, {0, 0, 0, 0}}, {10, 22, 2, 0, {0, 0, 0, 0}}, {10, 22, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData246_SUB_16S_08U_16S[] = {{12, 22, 2, 0, {0, 0, 0, 0}}, {12, 22, 2, 0, {0, 0, 0, 0}}, {12, 22, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData247_SUB_16S_08U_16S[] = {{14, 22, 2, 0, {0, 0, 0, 0}}, {14, 22, 2, 0, {0, 0, 0, 0}}, {14, 22, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData248_SUB_16S_08U_16S[] = {{16, 22, 2, 0, {0, 0, 0, 0}}, {16, 22, 2, 0, {0, 0, 0, 0}}, {16, 22, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData249_SUB_16S_08U_16S[] = {{2, 24, 2, 0, {0, 0, 0, 0}}, {2, 24, 2, 0, {0, 0, 0, 0}}, {2, 24, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData250_SUB_16S_08U_16S[] = {{4, 24, 2, 0, {0, 0, 0, 0}}, {4, 24, 2, 0, {0, 0, 0, 0}}, {4, 24, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData251_SUB_16S_08U_16S[] = {{6, 24, 2, 0, {0, 0, 0, 0}}, {6, 24, 2, 0, {0, 0, 0, 0}}, {6, 24, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData252_SUB_16S_08U_16S[] = {{8, 24, 2, 0, {0, 0, 0, 0}}, {8, 24, 2, 0, {0, 0, 0, 0}}, {8, 24, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData253_SUB_16S_08U_16S[] = {{10, 24, 2, 0, {0, 0, 0, 0}}, {10, 24, 2, 0, {0, 0, 0, 0}}, {10, 24, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData254_SUB_16S_08U_16S[] = {{12, 24, 2, 0, {0, 0, 0, 0}}, {12, 24, 2, 0, {0, 0, 0, 0}}, {12, 24, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData255_SUB_16S_08U_16S[] = {{14, 24, 2, 0, {0, 0, 0, 0}}, {14, 24, 2, 0, {0, 0, 0, 0}}, {14, 24, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData256_SUB_16S_08U_16S[] = {{16, 24, 2, 0, {0, 0, 0, 0}}, {16, 24, 2, 0, {0, 0, 0, 0}}, {16, 24, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData257_SUB_16S_08U_16S[] = {{2, 26, 2, 0, {0, 0, 0, 0}}, {2, 26, 2, 0, {0, 0, 0, 0}}, {2, 26, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData258_SUB_16S_08U_16S[] = {{4, 26, 2, 0, {0, 0, 0, 0}}, {4, 26, 2, 0, {0, 0, 0, 0}}, {4, 26, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData259_SUB_16S_08U_16S[] = {{6, 26, 2, 0, {0, 0, 0, 0}}, {6, 26, 2, 0, {0, 0, 0, 0}}, {6, 26, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData260_SUB_16S_08U_16S[] = {{8, 26, 2, 0, {0, 0, 0, 0}}, {8, 26, 2, 0, {0, 0, 0, 0}}, {8, 26, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData261_SUB_16S_08U_16S[] = {{10, 26, 2, 0, {0, 0, 0, 0}}, {10, 26, 2, 0, {0, 0, 0, 0}}, {10, 26, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData262_SUB_16S_08U_16S[] = {{12, 26, 2, 0, {0, 0, 0, 0}}, {12, 26, 2, 0, {0, 0, 0, 0}}, {12, 26, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData263_SUB_16S_08U_16S[] = {{14, 26, 2, 0, {0, 0, 0, 0}}, {14, 26, 2, 0, {0, 0, 0, 0}}, {14, 26, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData264_SUB_16S_08U_16S[] = {{2, 28, 2, 0, {0, 0, 0, 0}}, {2, 28, 2, 0, {0, 0, 0, 0}}, {2, 28, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData265_SUB_16S_08U_16S[] = {{4, 28, 2, 0, {0, 0, 0, 0}}, {4, 28, 2, 0, {0, 0, 0, 0}}, {4, 28, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData266_SUB_16S_08U_16S[] = {{6, 28, 2, 0, {0, 0, 0, 0}}, {6, 28, 2, 0, {0, 0, 0, 0}}, {6, 28, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData267_SUB_16S_08U_16S[] = {{8, 28, 2, 0, {0, 0, 0, 0}}, {8, 28, 2, 0, {0, 0, 0, 0}}, {8, 28, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData268_SUB_16S_08U_16S[] = {{10, 28, 2, 0, {0, 0, 0, 0}}, {10, 28, 2, 0, {0, 0, 0, 0}}, {10, 28, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData269_SUB_16S_08U_16S[] = {{12, 28, 2, 0, {0, 0, 0, 0}}, {12, 28, 2, 0, {0, 0, 0, 0}}, {12, 28, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData270_SUB_16S_08U_16S[] = {{2, 30, 2, 0, {0, 0, 0, 0}}, {2, 30, 2, 0, {0, 0, 0, 0}}, {2, 30, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData271_SUB_16S_08U_16S[] = {{4, 30, 2, 0, {0, 0, 0, 0}}, {4, 30, 2, 0, {0, 0, 0, 0}}, {4, 30, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData272_SUB_16S_08U_16S[] = {{6, 30, 2, 0, {0, 0, 0, 0}}, {6, 30, 2, 0, {0, 0, 0, 0}}, {6, 30, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData273_SUB_16S_08U_16S[] = {{8, 30, 2, 0, {0, 0, 0, 0}}, {8, 30, 2, 0, {0, 0, 0, 0}}, {8, 30, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData274_SUB_16S_08U_16S[] = {{10, 30, 2, 0, {0, 0, 0, 0}}, {10, 30, 2, 0, {0, 0, 0, 0}}, {10, 30, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData275_SUB_16S_08U_16S[] = {{12, 30, 2, 0, {0, 0, 0, 0}}, {12, 30, 2, 0, {0, 0, 0, 0}}, {12, 30, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData276_SUB_16S_08U_16S[] = {{2, 32, 2, 0, {0, 0, 0, 0}}, {2, 32, 2, 0, {0, 0, 0, 0}}, {2, 32, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData277_SUB_16S_08U_16S[] = {{4, 32, 2, 0, {0, 0, 0, 0}}, {4, 32, 2, 0, {0, 0, 0, 0}}, {4, 32, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData278_SUB_16S_08U_16S[] = {{6, 32, 2, 0, {0, 0, 0, 0}}, {6, 32, 2, 0, {0, 0, 0, 0}}, {6, 32, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData279_SUB_16S_08U_16S[] = {{8, 32, 2, 0, {0, 0, 0, 0}}, {8, 32, 2, 0, {0, 0, 0, 0}}, {8, 32, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData280_SUB_16S_08U_16S[] = {{10, 32, 2, 0, {0, 0, 0, 0}}, {10, 32, 2, 0, {0, 0, 0, 0}}, {10, 32, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};
static acf_scenario_buffer_data gScenarioBufferData281_SUB_16S_08U_16S[] = {{12, 32, 2, 0, {0, 0, 0, 0}}, {12, 32, 2, 0, {0, 0, 0, 0}}, {12, 32, 2, 0, {0, 0, 0, 0}}, {1, 1, 1, 0, {0, 0, 0, 0}}};

static acf_scenario_kernel_data gScenarioKernelData0_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData1_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData2_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData3_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData4_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData5_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData6_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData7_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData8_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData9_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData10_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData11_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData12_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData13_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData14_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData15_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData16_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData17_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData18_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData19_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData20_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData21_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData22_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData23_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData24_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData25_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData26_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData27_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData28_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData29_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData30_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData31_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData32_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData33_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData34_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData35_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData36_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData37_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData38_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData39_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData40_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData41_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData42_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData43_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData44_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData45_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData46_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData47_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData48_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData49_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData50_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData51_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData52_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData53_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData54_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData55_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData56_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData57_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData58_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData59_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData60_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData61_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData62_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData63_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData64_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData65_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData66_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData67_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData68_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData69_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData70_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData71_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData72_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData73_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData74_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData75_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData76_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData77_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData78_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData79_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData80_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData81_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData82_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData83_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData84_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData85_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData86_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData87_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData88_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData89_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData90_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData91_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData92_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData93_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData94_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData95_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData96_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData97_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData98_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData99_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData100_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData101_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData102_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData103_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData104_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData105_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData106_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData107_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData108_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData109_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData110_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData111_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData112_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData113_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData114_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData115_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData116_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData117_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData118_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData119_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData120_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData121_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData122_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData123_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData124_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData125_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData126_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData127_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData128_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData129_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData130_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData131_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData132_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData133_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData134_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData135_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData136_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData137_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData138_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData139_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData140_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData141_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData142_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData143_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData144_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData145_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData146_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData147_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData148_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData149_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData150_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData151_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData152_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData153_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData154_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData155_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData156_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData157_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData158_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData159_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData160_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData161_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData162_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData163_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData164_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData165_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData166_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData167_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData168_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData169_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData170_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData171_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData172_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData173_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData174_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData175_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData176_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData177_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData178_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData179_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData180_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData181_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData182_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData183_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData184_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData185_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData186_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData187_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData188_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData189_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData190_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData191_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData192_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData193_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData194_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData195_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData196_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData197_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData198_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData199_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData200_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData201_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData202_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData203_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData204_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData205_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData206_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData207_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData208_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData209_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData210_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData211_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData212_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData213_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData214_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData215_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData216_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData217_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData218_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData219_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData220_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData221_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData222_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData223_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData224_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData225_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData226_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData227_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData228_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData229_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData230_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData231_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData232_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData233_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData234_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData235_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData236_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData237_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData238_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData239_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData240_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData241_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData242_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData243_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData244_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData245_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData246_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData247_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData248_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData249_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData250_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData251_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData252_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData253_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData254_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData255_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData256_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData257_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData258_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData259_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData260_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData261_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData262_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData263_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData264_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData265_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData266_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData267_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData268_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData269_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData270_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData271_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData272_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData273_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData274_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData275_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData276_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData277_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData278_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData279_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData280_SUB_16S_08U_16S[] = {{0, 0}};
static acf_scenario_kernel_data gScenarioKernelData281_SUB_16S_08U_16S[] = {{0, 0}};

static acf_scenario gScenarioArray_SUB_16S_08U_16S[] = {
{2, 1, 20, 16, 0, gScenarioBufferData0_SUB_16S_08U_16S, 64, gScenarioKernelData0_SUB_16S_08U_16S, 4},
{4, 1, 40, 16, 0, gScenarioBufferData1_SUB_16S_08U_16S, 64, gScenarioKernelData1_SUB_16S_08U_16S, 4},
{6, 1, 60, 16, 0, gScenarioBufferData2_SUB_16S_08U_16S, 64, gScenarioKernelData2_SUB_16S_08U_16S, 4},
{8, 1, 80, 16, 0, gScenarioBufferData3_SUB_16S_08U_16S, 64, gScenarioKernelData3_SUB_16S_08U_16S, 4},
{10, 1, 100, 16, 0, gScenarioBufferData4_SUB_16S_08U_16S, 64, gScenarioKernelData4_SUB_16S_08U_16S, 4},
{12, 1, 120, 16, 0, gScenarioBufferData5_SUB_16S_08U_16S, 64, gScenarioKernelData5_SUB_16S_08U_16S, 4},
{14, 1, 140, 16, 0, gScenarioBufferData6_SUB_16S_08U_16S, 64, gScenarioKernelData6_SUB_16S_08U_16S, 4},
{16, 1, 160, 16, 0, gScenarioBufferData7_SUB_16S_08U_16S, 64, gScenarioKernelData7_SUB_16S_08U_16S, 4},
{18, 1, 180, 16, 0, gScenarioBufferData8_SUB_16S_08U_16S, 64, gScenarioKernelData8_SUB_16S_08U_16S, 4},
{20, 1, 200, 16, 0, gScenarioBufferData9_SUB_16S_08U_16S, 64, gScenarioKernelData9_SUB_16S_08U_16S, 4},
{22, 1, 220, 16, 0, gScenarioBufferData10_SUB_16S_08U_16S, 64, gScenarioKernelData10_SUB_16S_08U_16S, 4},
{24, 1, 240, 16, 0, gScenarioBufferData11_SUB_16S_08U_16S, 64, gScenarioKernelData11_SUB_16S_08U_16S, 4},
{26, 1, 260, 16, 0, gScenarioBufferData12_SUB_16S_08U_16S, 64, gScenarioKernelData12_SUB_16S_08U_16S, 4},
{28, 1, 280, 16, 0, gScenarioBufferData13_SUB_16S_08U_16S, 64, gScenarioKernelData13_SUB_16S_08U_16S, 4},
{30, 1, 300, 16, 0, gScenarioBufferData14_SUB_16S_08U_16S, 64, gScenarioKernelData14_SUB_16S_08U_16S, 4},
{32, 1, 320, 16, 0, gScenarioBufferData15_SUB_16S_08U_16S, 64, gScenarioKernelData15_SUB_16S_08U_16S, 4},
{36, 1, 360, 16, 0, gScenarioBufferData16_SUB_16S_08U_16S, 64, gScenarioKernelData16_SUB_16S_08U_16S, 4},
{40, 1, 400, 16, 0, gScenarioBufferData17_SUB_16S_08U_16S, 64, gScenarioKernelData17_SUB_16S_08U_16S, 4},
{44, 1, 440, 16, 0, gScenarioBufferData18_SUB_16S_08U_16S, 64, gScenarioKernelData18_SUB_16S_08U_16S, 4},
{48, 1, 480, 16, 0, gScenarioBufferData19_SUB_16S_08U_16S, 64, gScenarioKernelData19_SUB_16S_08U_16S, 4},
{52, 1, 520, 16, 0, gScenarioBufferData20_SUB_16S_08U_16S, 64, gScenarioKernelData20_SUB_16S_08U_16S, 4},
{56, 1, 560, 16, 0, gScenarioBufferData21_SUB_16S_08U_16S, 64, gScenarioKernelData21_SUB_16S_08U_16S, 4},
{60, 1, 600, 16, 0, gScenarioBufferData22_SUB_16S_08U_16S, 64, gScenarioKernelData22_SUB_16S_08U_16S, 4},
{64, 1, 640, 16, 0, gScenarioBufferData23_SUB_16S_08U_16S, 64, gScenarioKernelData23_SUB_16S_08U_16S, 4},
{2, 2, 40, 16, 0, gScenarioBufferData24_SUB_16S_08U_16S, 64, gScenarioKernelData24_SUB_16S_08U_16S, 4},
{4, 2, 80, 16, 0, gScenarioBufferData25_SUB_16S_08U_16S, 64, gScenarioKernelData25_SUB_16S_08U_16S, 4},
{6, 2, 120, 16, 0, gScenarioBufferData26_SUB_16S_08U_16S, 64, gScenarioKernelData26_SUB_16S_08U_16S, 4},
{8, 2, 160, 16, 0, gScenarioBufferData27_SUB_16S_08U_16S, 64, gScenarioKernelData27_SUB_16S_08U_16S, 4},
{10, 2, 200, 16, 0, gScenarioBufferData28_SUB_16S_08U_16S, 64, gScenarioKernelData28_SUB_16S_08U_16S, 4},
{12, 2, 240, 16, 0, gScenarioBufferData29_SUB_16S_08U_16S, 64, gScenarioKernelData29_SUB_16S_08U_16S, 4},
{14, 2, 280, 16, 0, gScenarioBufferData30_SUB_16S_08U_16S, 64, gScenarioKernelData30_SUB_16S_08U_16S, 4},
{16, 2, 320, 16, 0, gScenarioBufferData31_SUB_16S_08U_16S, 64, gScenarioKernelData31_SUB_16S_08U_16S, 4},
{18, 2, 360, 16, 0, gScenarioBufferData32_SUB_16S_08U_16S, 64, gScenarioKernelData32_SUB_16S_08U_16S, 4},
{20, 2, 400, 16, 0, gScenarioBufferData33_SUB_16S_08U_16S, 64, gScenarioKernelData33_SUB_16S_08U_16S, 4},
{22, 2, 440, 16, 0, gScenarioBufferData34_SUB_16S_08U_16S, 64, gScenarioKernelData34_SUB_16S_08U_16S, 4},
{24, 2, 480, 16, 0, gScenarioBufferData35_SUB_16S_08U_16S, 64, gScenarioKernelData35_SUB_16S_08U_16S, 4},
{26, 2, 520, 16, 0, gScenarioBufferData36_SUB_16S_08U_16S, 64, gScenarioKernelData36_SUB_16S_08U_16S, 4},
{28, 2, 560, 16, 0, gScenarioBufferData37_SUB_16S_08U_16S, 64, gScenarioKernelData37_SUB_16S_08U_16S, 4},
{30, 2, 600, 16, 0, gScenarioBufferData38_SUB_16S_08U_16S, 64, gScenarioKernelData38_SUB_16S_08U_16S, 4},
{32, 2, 640, 16, 0, gScenarioBufferData39_SUB_16S_08U_16S, 64, gScenarioKernelData39_SUB_16S_08U_16S, 4},
{36, 2, 720, 16, 0, gScenarioBufferData40_SUB_16S_08U_16S, 64, gScenarioKernelData40_SUB_16S_08U_16S, 4},
{40, 2, 800, 16, 0, gScenarioBufferData41_SUB_16S_08U_16S, 64, gScenarioKernelData41_SUB_16S_08U_16S, 4},
{44, 2, 880, 16, 0, gScenarioBufferData42_SUB_16S_08U_16S, 64, gScenarioKernelData42_SUB_16S_08U_16S, 4},
{48, 2, 960, 16, 0, gScenarioBufferData43_SUB_16S_08U_16S, 64, gScenarioKernelData43_SUB_16S_08U_16S, 4},
{52, 2, 1040, 16, 0, gScenarioBufferData44_SUB_16S_08U_16S, 64, gScenarioKernelData44_SUB_16S_08U_16S, 4},
{56, 2, 1120, 16, 0, gScenarioBufferData45_SUB_16S_08U_16S, 64, gScenarioKernelData45_SUB_16S_08U_16S, 4},
{60, 2, 1200, 16, 0, gScenarioBufferData46_SUB_16S_08U_16S, 64, gScenarioKernelData46_SUB_16S_08U_16S, 4},
{64, 2, 1280, 16, 0, gScenarioBufferData47_SUB_16S_08U_16S, 64, gScenarioKernelData47_SUB_16S_08U_16S, 4},
{2, 3, 60, 16, 0, gScenarioBufferData48_SUB_16S_08U_16S, 64, gScenarioKernelData48_SUB_16S_08U_16S, 4},
{4, 3, 120, 16, 0, gScenarioBufferData49_SUB_16S_08U_16S, 64, gScenarioKernelData49_SUB_16S_08U_16S, 4},
{6, 3, 180, 16, 0, gScenarioBufferData50_SUB_16S_08U_16S, 64, gScenarioKernelData50_SUB_16S_08U_16S, 4},
{8, 3, 240, 16, 0, gScenarioBufferData51_SUB_16S_08U_16S, 64, gScenarioKernelData51_SUB_16S_08U_16S, 4},
{10, 3, 300, 16, 0, gScenarioBufferData52_SUB_16S_08U_16S, 64, gScenarioKernelData52_SUB_16S_08U_16S, 4},
{12, 3, 360, 16, 0, gScenarioBufferData53_SUB_16S_08U_16S, 64, gScenarioKernelData53_SUB_16S_08U_16S, 4},
{14, 3, 420, 16, 0, gScenarioBufferData54_SUB_16S_08U_16S, 64, gScenarioKernelData54_SUB_16S_08U_16S, 4},
{16, 3, 480, 16, 0, gScenarioBufferData55_SUB_16S_08U_16S, 64, gScenarioKernelData55_SUB_16S_08U_16S, 4},
{18, 3, 540, 16, 0, gScenarioBufferData56_SUB_16S_08U_16S, 64, gScenarioKernelData56_SUB_16S_08U_16S, 4},
{20, 3, 600, 16, 0, gScenarioBufferData57_SUB_16S_08U_16S, 64, gScenarioKernelData57_SUB_16S_08U_16S, 4},
{22, 3, 660, 16, 0, gScenarioBufferData58_SUB_16S_08U_16S, 64, gScenarioKernelData58_SUB_16S_08U_16S, 4},
{24, 3, 720, 16, 0, gScenarioBufferData59_SUB_16S_08U_16S, 64, gScenarioKernelData59_SUB_16S_08U_16S, 4},
{26, 3, 780, 16, 0, gScenarioBufferData60_SUB_16S_08U_16S, 64, gScenarioKernelData60_SUB_16S_08U_16S, 4},
{28, 3, 840, 16, 0, gScenarioBufferData61_SUB_16S_08U_16S, 64, gScenarioKernelData61_SUB_16S_08U_16S, 4},
{30, 3, 900, 16, 0, gScenarioBufferData62_SUB_16S_08U_16S, 64, gScenarioKernelData62_SUB_16S_08U_16S, 4},
{32, 3, 960, 16, 0, gScenarioBufferData63_SUB_16S_08U_16S, 64, gScenarioKernelData63_SUB_16S_08U_16S, 4},
{36, 3, 1080, 16, 0, gScenarioBufferData64_SUB_16S_08U_16S, 64, gScenarioKernelData64_SUB_16S_08U_16S, 4},
{40, 3, 1200, 16, 0, gScenarioBufferData65_SUB_16S_08U_16S, 64, gScenarioKernelData65_SUB_16S_08U_16S, 4},
{44, 3, 1320, 16, 0, gScenarioBufferData66_SUB_16S_08U_16S, 64, gScenarioKernelData66_SUB_16S_08U_16S, 4},
{48, 3, 1440, 16, 0, gScenarioBufferData67_SUB_16S_08U_16S, 64, gScenarioKernelData67_SUB_16S_08U_16S, 4},
{52, 3, 1560, 16, 0, gScenarioBufferData68_SUB_16S_08U_16S, 64, gScenarioKernelData68_SUB_16S_08U_16S, 4},
{56, 3, 1680, 16, 0, gScenarioBufferData69_SUB_16S_08U_16S, 64, gScenarioKernelData69_SUB_16S_08U_16S, 4},
{60, 3, 1800, 16, 0, gScenarioBufferData70_SUB_16S_08U_16S, 64, gScenarioKernelData70_SUB_16S_08U_16S, 4},
{64, 3, 1920, 16, 0, gScenarioBufferData71_SUB_16S_08U_16S, 64, gScenarioKernelData71_SUB_16S_08U_16S, 4},
{2, 4, 80, 16, 0, gScenarioBufferData72_SUB_16S_08U_16S, 64, gScenarioKernelData72_SUB_16S_08U_16S, 4},
{4, 4, 160, 16, 0, gScenarioBufferData73_SUB_16S_08U_16S, 64, gScenarioKernelData73_SUB_16S_08U_16S, 4},
{6, 4, 240, 16, 0, gScenarioBufferData74_SUB_16S_08U_16S, 64, gScenarioKernelData74_SUB_16S_08U_16S, 4},
{8, 4, 320, 16, 0, gScenarioBufferData75_SUB_16S_08U_16S, 64, gScenarioKernelData75_SUB_16S_08U_16S, 4},
{10, 4, 400, 16, 0, gScenarioBufferData76_SUB_16S_08U_16S, 64, gScenarioKernelData76_SUB_16S_08U_16S, 4},
{12, 4, 480, 16, 0, gScenarioBufferData77_SUB_16S_08U_16S, 64, gScenarioKernelData77_SUB_16S_08U_16S, 4},
{14, 4, 560, 16, 0, gScenarioBufferData78_SUB_16S_08U_16S, 64, gScenarioKernelData78_SUB_16S_08U_16S, 4},
{16, 4, 640, 16, 0, gScenarioBufferData79_SUB_16S_08U_16S, 64, gScenarioKernelData79_SUB_16S_08U_16S, 4},
{18, 4, 720, 16, 0, gScenarioBufferData80_SUB_16S_08U_16S, 64, gScenarioKernelData80_SUB_16S_08U_16S, 4},
{20, 4, 800, 16, 0, gScenarioBufferData81_SUB_16S_08U_16S, 64, gScenarioKernelData81_SUB_16S_08U_16S, 4},
{22, 4, 880, 16, 0, gScenarioBufferData82_SUB_16S_08U_16S, 64, gScenarioKernelData82_SUB_16S_08U_16S, 4},
{24, 4, 960, 16, 0, gScenarioBufferData83_SUB_16S_08U_16S, 64, gScenarioKernelData83_SUB_16S_08U_16S, 4},
{26, 4, 1040, 16, 0, gScenarioBufferData84_SUB_16S_08U_16S, 64, gScenarioKernelData84_SUB_16S_08U_16S, 4},
{28, 4, 1120, 16, 0, gScenarioBufferData85_SUB_16S_08U_16S, 64, gScenarioKernelData85_SUB_16S_08U_16S, 4},
{30, 4, 1200, 16, 0, gScenarioBufferData86_SUB_16S_08U_16S, 64, gScenarioKernelData86_SUB_16S_08U_16S, 4},
{32, 4, 1280, 16, 0, gScenarioBufferData87_SUB_16S_08U_16S, 64, gScenarioKernelData87_SUB_16S_08U_16S, 4},
{36, 4, 1440, 16, 0, gScenarioBufferData88_SUB_16S_08U_16S, 64, gScenarioKernelData88_SUB_16S_08U_16S, 4},
{40, 4, 1600, 16, 0, gScenarioBufferData89_SUB_16S_08U_16S, 64, gScenarioKernelData89_SUB_16S_08U_16S, 4},
{44, 4, 1760, 16, 0, gScenarioBufferData90_SUB_16S_08U_16S, 64, gScenarioKernelData90_SUB_16S_08U_16S, 4},
{48, 4, 1920, 16, 0, gScenarioBufferData91_SUB_16S_08U_16S, 64, gScenarioKernelData91_SUB_16S_08U_16S, 4},
{52, 4, 2080, 16, 0, gScenarioBufferData92_SUB_16S_08U_16S, 64, gScenarioKernelData92_SUB_16S_08U_16S, 4},
{56, 4, 2240, 16, 0, gScenarioBufferData93_SUB_16S_08U_16S, 64, gScenarioKernelData93_SUB_16S_08U_16S, 4},
{60, 4, 2400, 16, 0, gScenarioBufferData94_SUB_16S_08U_16S, 64, gScenarioKernelData94_SUB_16S_08U_16S, 4},
{64, 4, 2560, 16, 0, gScenarioBufferData95_SUB_16S_08U_16S, 64, gScenarioKernelData95_SUB_16S_08U_16S, 4},
{2, 5, 100, 16, 0, gScenarioBufferData96_SUB_16S_08U_16S, 64, gScenarioKernelData96_SUB_16S_08U_16S, 4},
{4, 5, 200, 16, 0, gScenarioBufferData97_SUB_16S_08U_16S, 64, gScenarioKernelData97_SUB_16S_08U_16S, 4},
{6, 5, 300, 16, 0, gScenarioBufferData98_SUB_16S_08U_16S, 64, gScenarioKernelData98_SUB_16S_08U_16S, 4},
{8, 5, 400, 16, 0, gScenarioBufferData99_SUB_16S_08U_16S, 64, gScenarioKernelData99_SUB_16S_08U_16S, 4},
{10, 5, 500, 16, 0, gScenarioBufferData100_SUB_16S_08U_16S, 64, gScenarioKernelData100_SUB_16S_08U_16S, 4},
{12, 5, 600, 16, 0, gScenarioBufferData101_SUB_16S_08U_16S, 64, gScenarioKernelData101_SUB_16S_08U_16S, 4},
{14, 5, 700, 16, 0, gScenarioBufferData102_SUB_16S_08U_16S, 64, gScenarioKernelData102_SUB_16S_08U_16S, 4},
{16, 5, 800, 16, 0, gScenarioBufferData103_SUB_16S_08U_16S, 64, gScenarioKernelData103_SUB_16S_08U_16S, 4},
{18, 5, 900, 16, 0, gScenarioBufferData104_SUB_16S_08U_16S, 64, gScenarioKernelData104_SUB_16S_08U_16S, 4},
{20, 5, 1000, 16, 0, gScenarioBufferData105_SUB_16S_08U_16S, 64, gScenarioKernelData105_SUB_16S_08U_16S, 4},
{22, 5, 1100, 16, 0, gScenarioBufferData106_SUB_16S_08U_16S, 64, gScenarioKernelData106_SUB_16S_08U_16S, 4},
{24, 5, 1200, 16, 0, gScenarioBufferData107_SUB_16S_08U_16S, 64, gScenarioKernelData107_SUB_16S_08U_16S, 4},
{26, 5, 1300, 16, 0, gScenarioBufferData108_SUB_16S_08U_16S, 64, gScenarioKernelData108_SUB_16S_08U_16S, 4},
{28, 5, 1400, 16, 0, gScenarioBufferData109_SUB_16S_08U_16S, 64, gScenarioKernelData109_SUB_16S_08U_16S, 4},
{30, 5, 1500, 16, 0, gScenarioBufferData110_SUB_16S_08U_16S, 64, gScenarioKernelData110_SUB_16S_08U_16S, 4},
{32, 5, 1600, 16, 0, gScenarioBufferData111_SUB_16S_08U_16S, 64, gScenarioKernelData111_SUB_16S_08U_16S, 4},
{36, 5, 1800, 16, 0, gScenarioBufferData112_SUB_16S_08U_16S, 64, gScenarioKernelData112_SUB_16S_08U_16S, 4},
{40, 5, 2000, 16, 0, gScenarioBufferData113_SUB_16S_08U_16S, 64, gScenarioKernelData113_SUB_16S_08U_16S, 4},
{44, 5, 2200, 16, 0, gScenarioBufferData114_SUB_16S_08U_16S, 64, gScenarioKernelData114_SUB_16S_08U_16S, 4},
{48, 5, 2400, 16, 0, gScenarioBufferData115_SUB_16S_08U_16S, 64, gScenarioKernelData115_SUB_16S_08U_16S, 4},
{52, 5, 2600, 16, 0, gScenarioBufferData116_SUB_16S_08U_16S, 64, gScenarioKernelData116_SUB_16S_08U_16S, 4},
{56, 5, 2800, 16, 0, gScenarioBufferData117_SUB_16S_08U_16S, 64, gScenarioKernelData117_SUB_16S_08U_16S, 4},
{60, 5, 3000, 16, 0, gScenarioBufferData118_SUB_16S_08U_16S, 64, gScenarioKernelData118_SUB_16S_08U_16S, 4},
{64, 5, 3200, 16, 0, gScenarioBufferData119_SUB_16S_08U_16S, 64, gScenarioKernelData119_SUB_16S_08U_16S, 4},
{2, 6, 120, 16, 0, gScenarioBufferData120_SUB_16S_08U_16S, 64, gScenarioKernelData120_SUB_16S_08U_16S, 4},
{4, 6, 240, 16, 0, gScenarioBufferData121_SUB_16S_08U_16S, 64, gScenarioKernelData121_SUB_16S_08U_16S, 4},
{6, 6, 360, 16, 0, gScenarioBufferData122_SUB_16S_08U_16S, 64, gScenarioKernelData122_SUB_16S_08U_16S, 4},
{8, 6, 480, 16, 0, gScenarioBufferData123_SUB_16S_08U_16S, 64, gScenarioKernelData123_SUB_16S_08U_16S, 4},
{10, 6, 600, 16, 0, gScenarioBufferData124_SUB_16S_08U_16S, 64, gScenarioKernelData124_SUB_16S_08U_16S, 4},
{12, 6, 720, 16, 0, gScenarioBufferData125_SUB_16S_08U_16S, 64, gScenarioKernelData125_SUB_16S_08U_16S, 4},
{14, 6, 840, 16, 0, gScenarioBufferData126_SUB_16S_08U_16S, 64, gScenarioKernelData126_SUB_16S_08U_16S, 4},
{16, 6, 960, 16, 0, gScenarioBufferData127_SUB_16S_08U_16S, 64, gScenarioKernelData127_SUB_16S_08U_16S, 4},
{18, 6, 1080, 16, 0, gScenarioBufferData128_SUB_16S_08U_16S, 64, gScenarioKernelData128_SUB_16S_08U_16S, 4},
{20, 6, 1200, 16, 0, gScenarioBufferData129_SUB_16S_08U_16S, 64, gScenarioKernelData129_SUB_16S_08U_16S, 4},
{22, 6, 1320, 16, 0, gScenarioBufferData130_SUB_16S_08U_16S, 64, gScenarioKernelData130_SUB_16S_08U_16S, 4},
{24, 6, 1440, 16, 0, gScenarioBufferData131_SUB_16S_08U_16S, 64, gScenarioKernelData131_SUB_16S_08U_16S, 4},
{26, 6, 1560, 16, 0, gScenarioBufferData132_SUB_16S_08U_16S, 64, gScenarioKernelData132_SUB_16S_08U_16S, 4},
{28, 6, 1680, 16, 0, gScenarioBufferData133_SUB_16S_08U_16S, 64, gScenarioKernelData133_SUB_16S_08U_16S, 4},
{30, 6, 1800, 16, 0, gScenarioBufferData134_SUB_16S_08U_16S, 64, gScenarioKernelData134_SUB_16S_08U_16S, 4},
{32, 6, 1920, 16, 0, gScenarioBufferData135_SUB_16S_08U_16S, 64, gScenarioKernelData135_SUB_16S_08U_16S, 4},
{36, 6, 2160, 16, 0, gScenarioBufferData136_SUB_16S_08U_16S, 64, gScenarioKernelData136_SUB_16S_08U_16S, 4},
{40, 6, 2400, 16, 0, gScenarioBufferData137_SUB_16S_08U_16S, 64, gScenarioKernelData137_SUB_16S_08U_16S, 4},
{44, 6, 2640, 16, 0, gScenarioBufferData138_SUB_16S_08U_16S, 64, gScenarioKernelData138_SUB_16S_08U_16S, 4},
{48, 6, 2880, 16, 0, gScenarioBufferData139_SUB_16S_08U_16S, 64, gScenarioKernelData139_SUB_16S_08U_16S, 4},
{52, 6, 3120, 16, 0, gScenarioBufferData140_SUB_16S_08U_16S, 64, gScenarioKernelData140_SUB_16S_08U_16S, 4},
{56, 6, 3360, 16, 0, gScenarioBufferData141_SUB_16S_08U_16S, 64, gScenarioKernelData141_SUB_16S_08U_16S, 4},
{60, 6, 3600, 16, 0, gScenarioBufferData142_SUB_16S_08U_16S, 64, gScenarioKernelData142_SUB_16S_08U_16S, 4},
{64, 6, 3840, 16, 0, gScenarioBufferData143_SUB_16S_08U_16S, 64, gScenarioKernelData143_SUB_16S_08U_16S, 4},
{2, 8, 160, 16, 0, gScenarioBufferData144_SUB_16S_08U_16S, 64, gScenarioKernelData144_SUB_16S_08U_16S, 4},
{4, 8, 320, 16, 0, gScenarioBufferData145_SUB_16S_08U_16S, 64, gScenarioKernelData145_SUB_16S_08U_16S, 4},
{6, 8, 480, 16, 0, gScenarioBufferData146_SUB_16S_08U_16S, 64, gScenarioKernelData146_SUB_16S_08U_16S, 4},
{8, 8, 640, 16, 0, gScenarioBufferData147_SUB_16S_08U_16S, 64, gScenarioKernelData147_SUB_16S_08U_16S, 4},
{10, 8, 800, 16, 0, gScenarioBufferData148_SUB_16S_08U_16S, 64, gScenarioKernelData148_SUB_16S_08U_16S, 4},
{12, 8, 960, 16, 0, gScenarioBufferData149_SUB_16S_08U_16S, 64, gScenarioKernelData149_SUB_16S_08U_16S, 4},
{14, 8, 1120, 16, 0, gScenarioBufferData150_SUB_16S_08U_16S, 64, gScenarioKernelData150_SUB_16S_08U_16S, 4},
{16, 8, 1280, 16, 0, gScenarioBufferData151_SUB_16S_08U_16S, 64, gScenarioKernelData151_SUB_16S_08U_16S, 4},
{18, 8, 1440, 16, 0, gScenarioBufferData152_SUB_16S_08U_16S, 64, gScenarioKernelData152_SUB_16S_08U_16S, 4},
{20, 8, 1600, 16, 0, gScenarioBufferData153_SUB_16S_08U_16S, 64, gScenarioKernelData153_SUB_16S_08U_16S, 4},
{22, 8, 1760, 16, 0, gScenarioBufferData154_SUB_16S_08U_16S, 64, gScenarioKernelData154_SUB_16S_08U_16S, 4},
{24, 8, 1920, 16, 0, gScenarioBufferData155_SUB_16S_08U_16S, 64, gScenarioKernelData155_SUB_16S_08U_16S, 4},
{26, 8, 2080, 16, 0, gScenarioBufferData156_SUB_16S_08U_16S, 64, gScenarioKernelData156_SUB_16S_08U_16S, 4},
{28, 8, 2240, 16, 0, gScenarioBufferData157_SUB_16S_08U_16S, 64, gScenarioKernelData157_SUB_16S_08U_16S, 4},
{30, 8, 2400, 16, 0, gScenarioBufferData158_SUB_16S_08U_16S, 64, gScenarioKernelData158_SUB_16S_08U_16S, 4},
{32, 8, 2560, 16, 0, gScenarioBufferData159_SUB_16S_08U_16S, 64, gScenarioKernelData159_SUB_16S_08U_16S, 4},
{36, 8, 2880, 16, 0, gScenarioBufferData160_SUB_16S_08U_16S, 64, gScenarioKernelData160_SUB_16S_08U_16S, 4},
{40, 8, 3200, 16, 0, gScenarioBufferData161_SUB_16S_08U_16S, 64, gScenarioKernelData161_SUB_16S_08U_16S, 4},
{44, 8, 3520, 16, 0, gScenarioBufferData162_SUB_16S_08U_16S, 64, gScenarioKernelData162_SUB_16S_08U_16S, 4},
{48, 8, 3840, 16, 0, gScenarioBufferData163_SUB_16S_08U_16S, 64, gScenarioKernelData163_SUB_16S_08U_16S, 4},
{2, 10, 200, 16, 0, gScenarioBufferData164_SUB_16S_08U_16S, 64, gScenarioKernelData164_SUB_16S_08U_16S, 4},
{4, 10, 400, 16, 0, gScenarioBufferData165_SUB_16S_08U_16S, 64, gScenarioKernelData165_SUB_16S_08U_16S, 4},
{6, 10, 600, 16, 0, gScenarioBufferData166_SUB_16S_08U_16S, 64, gScenarioKernelData166_SUB_16S_08U_16S, 4},
{8, 10, 800, 16, 0, gScenarioBufferData167_SUB_16S_08U_16S, 64, gScenarioKernelData167_SUB_16S_08U_16S, 4},
{10, 10, 1000, 16, 0, gScenarioBufferData168_SUB_16S_08U_16S, 64, gScenarioKernelData168_SUB_16S_08U_16S, 4},
{12, 10, 1200, 16, 0, gScenarioBufferData169_SUB_16S_08U_16S, 64, gScenarioKernelData169_SUB_16S_08U_16S, 4},
{14, 10, 1400, 16, 0, gScenarioBufferData170_SUB_16S_08U_16S, 64, gScenarioKernelData170_SUB_16S_08U_16S, 4},
{16, 10, 1600, 16, 0, gScenarioBufferData171_SUB_16S_08U_16S, 64, gScenarioKernelData171_SUB_16S_08U_16S, 4},
{18, 10, 1800, 16, 0, gScenarioBufferData172_SUB_16S_08U_16S, 64, gScenarioKernelData172_SUB_16S_08U_16S, 4},
{20, 10, 2000, 16, 0, gScenarioBufferData173_SUB_16S_08U_16S, 64, gScenarioKernelData173_SUB_16S_08U_16S, 4},
{22, 10, 2200, 16, 0, gScenarioBufferData174_SUB_16S_08U_16S, 64, gScenarioKernelData174_SUB_16S_08U_16S, 4},
{24, 10, 2400, 16, 0, gScenarioBufferData175_SUB_16S_08U_16S, 64, gScenarioKernelData175_SUB_16S_08U_16S, 4},
{26, 10, 2600, 16, 0, gScenarioBufferData176_SUB_16S_08U_16S, 64, gScenarioKernelData176_SUB_16S_08U_16S, 4},
{28, 10, 2800, 16, 0, gScenarioBufferData177_SUB_16S_08U_16S, 64, gScenarioKernelData177_SUB_16S_08U_16S, 4},
{30, 10, 3000, 16, 0, gScenarioBufferData178_SUB_16S_08U_16S, 64, gScenarioKernelData178_SUB_16S_08U_16S, 4},
{32, 10, 3200, 16, 0, gScenarioBufferData179_SUB_16S_08U_16S, 64, gScenarioKernelData179_SUB_16S_08U_16S, 4},
{36, 10, 3600, 16, 0, gScenarioBufferData180_SUB_16S_08U_16S, 64, gScenarioKernelData180_SUB_16S_08U_16S, 4},
{2, 12, 240, 16, 0, gScenarioBufferData181_SUB_16S_08U_16S, 64, gScenarioKernelData181_SUB_16S_08U_16S, 4},
{4, 12, 480, 16, 0, gScenarioBufferData182_SUB_16S_08U_16S, 64, gScenarioKernelData182_SUB_16S_08U_16S, 4},
{6, 12, 720, 16, 0, gScenarioBufferData183_SUB_16S_08U_16S, 64, gScenarioKernelData183_SUB_16S_08U_16S, 4},
{8, 12, 960, 16, 0, gScenarioBufferData184_SUB_16S_08U_16S, 64, gScenarioKernelData184_SUB_16S_08U_16S, 4},
{10, 12, 1200, 16, 0, gScenarioBufferData185_SUB_16S_08U_16S, 64, gScenarioKernelData185_SUB_16S_08U_16S, 4},
{12, 12, 1440, 16, 0, gScenarioBufferData186_SUB_16S_08U_16S, 64, gScenarioKernelData186_SUB_16S_08U_16S, 4},
{14, 12, 1680, 16, 0, gScenarioBufferData187_SUB_16S_08U_16S, 64, gScenarioKernelData187_SUB_16S_08U_16S, 4},
{16, 12, 1920, 16, 0, gScenarioBufferData188_SUB_16S_08U_16S, 64, gScenarioKernelData188_SUB_16S_08U_16S, 4},
{18, 12, 2160, 16, 0, gScenarioBufferData189_SUB_16S_08U_16S, 64, gScenarioKernelData189_SUB_16S_08U_16S, 4},
{20, 12, 2400, 16, 0, gScenarioBufferData190_SUB_16S_08U_16S, 64, gScenarioKernelData190_SUB_16S_08U_16S, 4},
{22, 12, 2640, 16, 0, gScenarioBufferData191_SUB_16S_08U_16S, 64, gScenarioKernelData191_SUB_16S_08U_16S, 4},
{24, 12, 2880, 16, 0, gScenarioBufferData192_SUB_16S_08U_16S, 64, gScenarioKernelData192_SUB_16S_08U_16S, 4},
{26, 12, 3120, 16, 0, gScenarioBufferData193_SUB_16S_08U_16S, 64, gScenarioKernelData193_SUB_16S_08U_16S, 4},
{28, 12, 3360, 16, 0, gScenarioBufferData194_SUB_16S_08U_16S, 64, gScenarioKernelData194_SUB_16S_08U_16S, 4},
{30, 12, 3600, 16, 0, gScenarioBufferData195_SUB_16S_08U_16S, 64, gScenarioKernelData195_SUB_16S_08U_16S, 4},
{32, 12, 3840, 16, 0, gScenarioBufferData196_SUB_16S_08U_16S, 64, gScenarioKernelData196_SUB_16S_08U_16S, 4},
{2, 14, 280, 16, 0, gScenarioBufferData197_SUB_16S_08U_16S, 64, gScenarioKernelData197_SUB_16S_08U_16S, 4},
{4, 14, 560, 16, 0, gScenarioBufferData198_SUB_16S_08U_16S, 64, gScenarioKernelData198_SUB_16S_08U_16S, 4},
{6, 14, 840, 16, 0, gScenarioBufferData199_SUB_16S_08U_16S, 64, gScenarioKernelData199_SUB_16S_08U_16S, 4},
{8, 14, 1120, 16, 0, gScenarioBufferData200_SUB_16S_08U_16S, 64, gScenarioKernelData200_SUB_16S_08U_16S, 4},
{10, 14, 1400, 16, 0, gScenarioBufferData201_SUB_16S_08U_16S, 64, gScenarioKernelData201_SUB_16S_08U_16S, 4},
{12, 14, 1680, 16, 0, gScenarioBufferData202_SUB_16S_08U_16S, 64, gScenarioKernelData202_SUB_16S_08U_16S, 4},
{14, 14, 1960, 16, 0, gScenarioBufferData203_SUB_16S_08U_16S, 64, gScenarioKernelData203_SUB_16S_08U_16S, 4},
{16, 14, 2240, 16, 0, gScenarioBufferData204_SUB_16S_08U_16S, 64, gScenarioKernelData204_SUB_16S_08U_16S, 4},
{18, 14, 2520, 16, 0, gScenarioBufferData205_SUB_16S_08U_16S, 64, gScenarioKernelData205_SUB_16S_08U_16S, 4},
{20, 14, 2800, 16, 0, gScenarioBufferData206_SUB_16S_08U_16S, 64, gScenarioKernelData206_SUB_16S_08U_16S, 4},
{22, 14, 3080, 16, 0, gScenarioBufferData207_SUB_16S_08U_16S, 64, gScenarioKernelData207_SUB_16S_08U_16S, 4},
{24, 14, 3360, 16, 0, gScenarioBufferData208_SUB_16S_08U_16S, 64, gScenarioKernelData208_SUB_16S_08U_16S, 4},
{26, 14, 3640, 16, 0, gScenarioBufferData209_SUB_16S_08U_16S, 64, gScenarioKernelData209_SUB_16S_08U_16S, 4},
{2, 16, 320, 16, 0, gScenarioBufferData210_SUB_16S_08U_16S, 64, gScenarioKernelData210_SUB_16S_08U_16S, 4},
{4, 16, 640, 16, 0, gScenarioBufferData211_SUB_16S_08U_16S, 64, gScenarioKernelData211_SUB_16S_08U_16S, 4},
{6, 16, 960, 16, 0, gScenarioBufferData212_SUB_16S_08U_16S, 64, gScenarioKernelData212_SUB_16S_08U_16S, 4},
{8, 16, 1280, 16, 0, gScenarioBufferData213_SUB_16S_08U_16S, 64, gScenarioKernelData213_SUB_16S_08U_16S, 4},
{10, 16, 1600, 16, 0, gScenarioBufferData214_SUB_16S_08U_16S, 64, gScenarioKernelData214_SUB_16S_08U_16S, 4},
{12, 16, 1920, 16, 0, gScenarioBufferData215_SUB_16S_08U_16S, 64, gScenarioKernelData215_SUB_16S_08U_16S, 4},
{14, 16, 2240, 16, 0, gScenarioBufferData216_SUB_16S_08U_16S, 64, gScenarioKernelData216_SUB_16S_08U_16S, 4},
{16, 16, 2560, 16, 0, gScenarioBufferData217_SUB_16S_08U_16S, 64, gScenarioKernelData217_SUB_16S_08U_16S, 4},
{18, 16, 2880, 16, 0, gScenarioBufferData218_SUB_16S_08U_16S, 64, gScenarioKernelData218_SUB_16S_08U_16S, 4},
{20, 16, 3200, 16, 0, gScenarioBufferData219_SUB_16S_08U_16S, 64, gScenarioKernelData219_SUB_16S_08U_16S, 4},
{22, 16, 3520, 16, 0, gScenarioBufferData220_SUB_16S_08U_16S, 64, gScenarioKernelData220_SUB_16S_08U_16S, 4},
{24, 16, 3840, 16, 0, gScenarioBufferData221_SUB_16S_08U_16S, 64, gScenarioKernelData221_SUB_16S_08U_16S, 4},
{2, 18, 360, 16, 0, gScenarioBufferData222_SUB_16S_08U_16S, 64, gScenarioKernelData222_SUB_16S_08U_16S, 4},
{4, 18, 720, 16, 0, gScenarioBufferData223_SUB_16S_08U_16S, 64, gScenarioKernelData223_SUB_16S_08U_16S, 4},
{6, 18, 1080, 16, 0, gScenarioBufferData224_SUB_16S_08U_16S, 64, gScenarioKernelData224_SUB_16S_08U_16S, 4},
{8, 18, 1440, 16, 0, gScenarioBufferData225_SUB_16S_08U_16S, 64, gScenarioKernelData225_SUB_16S_08U_16S, 4},
{10, 18, 1800, 16, 0, gScenarioBufferData226_SUB_16S_08U_16S, 64, gScenarioKernelData226_SUB_16S_08U_16S, 4},
{12, 18, 2160, 16, 0, gScenarioBufferData227_SUB_16S_08U_16S, 64, gScenarioKernelData227_SUB_16S_08U_16S, 4},
{14, 18, 2520, 16, 0, gScenarioBufferData228_SUB_16S_08U_16S, 64, gScenarioKernelData228_SUB_16S_08U_16S, 4},
{16, 18, 2880, 16, 0, gScenarioBufferData229_SUB_16S_08U_16S, 64, gScenarioKernelData229_SUB_16S_08U_16S, 4},
{18, 18, 3240, 16, 0, gScenarioBufferData230_SUB_16S_08U_16S, 64, gScenarioKernelData230_SUB_16S_08U_16S, 4},
{20, 18, 3600, 16, 0, gScenarioBufferData231_SUB_16S_08U_16S, 64, gScenarioKernelData231_SUB_16S_08U_16S, 4},
{2, 20, 400, 16, 0, gScenarioBufferData232_SUB_16S_08U_16S, 64, gScenarioKernelData232_SUB_16S_08U_16S, 4},
{4, 20, 800, 16, 0, gScenarioBufferData233_SUB_16S_08U_16S, 64, gScenarioKernelData233_SUB_16S_08U_16S, 4},
{6, 20, 1200, 16, 0, gScenarioBufferData234_SUB_16S_08U_16S, 64, gScenarioKernelData234_SUB_16S_08U_16S, 4},
{8, 20, 1600, 16, 0, gScenarioBufferData235_SUB_16S_08U_16S, 64, gScenarioKernelData235_SUB_16S_08U_16S, 4},
{10, 20, 2000, 16, 0, gScenarioBufferData236_SUB_16S_08U_16S, 64, gScenarioKernelData236_SUB_16S_08U_16S, 4},
{12, 20, 2400, 16, 0, gScenarioBufferData237_SUB_16S_08U_16S, 64, gScenarioKernelData237_SUB_16S_08U_16S, 4},
{14, 20, 2800, 16, 0, gScenarioBufferData238_SUB_16S_08U_16S, 64, gScenarioKernelData238_SUB_16S_08U_16S, 4},
{16, 20, 3200, 16, 0, gScenarioBufferData239_SUB_16S_08U_16S, 64, gScenarioKernelData239_SUB_16S_08U_16S, 4},
{18, 20, 3600, 16, 0, gScenarioBufferData240_SUB_16S_08U_16S, 64, gScenarioKernelData240_SUB_16S_08U_16S, 4},
{2, 22, 440, 16, 0, gScenarioBufferData241_SUB_16S_08U_16S, 64, gScenarioKernelData241_SUB_16S_08U_16S, 4},
{4, 22, 880, 16, 0, gScenarioBufferData242_SUB_16S_08U_16S, 64, gScenarioKernelData242_SUB_16S_08U_16S, 4},
{6, 22, 1320, 16, 0, gScenarioBufferData243_SUB_16S_08U_16S, 64, gScenarioKernelData243_SUB_16S_08U_16S, 4},
{8, 22, 1760, 16, 0, gScenarioBufferData244_SUB_16S_08U_16S, 64, gScenarioKernelData244_SUB_16S_08U_16S, 4},
{10, 22, 2200, 16, 0, gScenarioBufferData245_SUB_16S_08U_16S, 64, gScenarioKernelData245_SUB_16S_08U_16S, 4},
{12, 22, 2640, 16, 0, gScenarioBufferData246_SUB_16S_08U_16S, 64, gScenarioKernelData246_SUB_16S_08U_16S, 4},
{14, 22, 3080, 16, 0, gScenarioBufferData247_SUB_16S_08U_16S, 64, gScenarioKernelData247_SUB_16S_08U_16S, 4},
{16, 22, 3520, 16, 0, gScenarioBufferData248_SUB_16S_08U_16S, 64, gScenarioKernelData248_SUB_16S_08U_16S, 4},
{2, 24, 480, 16, 0, gScenarioBufferData249_SUB_16S_08U_16S, 64, gScenarioKernelData249_SUB_16S_08U_16S, 4},
{4, 24, 960, 16, 0, gScenarioBufferData250_SUB_16S_08U_16S, 64, gScenarioKernelData250_SUB_16S_08U_16S, 4},
{6, 24, 1440, 16, 0, gScenarioBufferData251_SUB_16S_08U_16S, 64, gScenarioKernelData251_SUB_16S_08U_16S, 4},
{8, 24, 1920, 16, 0, gScenarioBufferData252_SUB_16S_08U_16S, 64, gScenarioKernelData252_SUB_16S_08U_16S, 4},
{10, 24, 2400, 16, 0, gScenarioBufferData253_SUB_16S_08U_16S, 64, gScenarioKernelData253_SUB_16S_08U_16S, 4},
{12, 24, 2880, 16, 0, gScenarioBufferData254_SUB_16S_08U_16S, 64, gScenarioKernelData254_SUB_16S_08U_16S, 4},
{14, 24, 3360, 16, 0, gScenarioBufferData255_SUB_16S_08U_16S, 64, gScenarioKernelData255_SUB_16S_08U_16S, 4},
{16, 24, 3840, 16, 0, gScenarioBufferData256_SUB_16S_08U_16S, 64, gScenarioKernelData256_SUB_16S_08U_16S, 4},
{2, 26, 520, 16, 0, gScenarioBufferData257_SUB_16S_08U_16S, 64, gScenarioKernelData257_SUB_16S_08U_16S, 4},
{4, 26, 1040, 16, 0, gScenarioBufferData258_SUB_16S_08U_16S, 64, gScenarioKernelData258_SUB_16S_08U_16S, 4},
{6, 26, 1560, 16, 0, gScenarioBufferData259_SUB_16S_08U_16S, 64, gScenarioKernelData259_SUB_16S_08U_16S, 4},
{8, 26, 2080, 16, 0, gScenarioBufferData260_SUB_16S_08U_16S, 64, gScenarioKernelData260_SUB_16S_08U_16S, 4},
{10, 26, 2600, 16, 0, gScenarioBufferData261_SUB_16S_08U_16S, 64, gScenarioKernelData261_SUB_16S_08U_16S, 4},
{12, 26, 3120, 16, 0, gScenarioBufferData262_SUB_16S_08U_16S, 64, gScenarioKernelData262_SUB_16S_08U_16S, 4},
{14, 26, 3640, 16, 0, gScenarioBufferData263_SUB_16S_08U_16S, 64, gScenarioKernelData263_SUB_16S_08U_16S, 4},
{2, 28, 560, 16, 0, gScenarioBufferData264_SUB_16S_08U_16S, 64, gScenarioKernelData264_SUB_16S_08U_16S, 4},
{4, 28, 1120, 16, 0, gScenarioBufferData265_SUB_16S_08U_16S, 64, gScenarioKernelData265_SUB_16S_08U_16S, 4},
{6, 28, 1680, 16, 0, gScenarioBufferData266_SUB_16S_08U_16S, 64, gScenarioKernelData266_SUB_16S_08U_16S, 4},
{8, 28, 2240, 16, 0, gScenarioBufferData267_SUB_16S_08U_16S, 64, gScenarioKernelData267_SUB_16S_08U_16S, 4},
{10, 28, 2800, 16, 0, gScenarioBufferData268_SUB_16S_08U_16S, 64, gScenarioKernelData268_SUB_16S_08U_16S, 4},
{12, 28, 3360, 16, 0, gScenarioBufferData269_SUB_16S_08U_16S, 64, gScenarioKernelData269_SUB_16S_08U_16S, 4},
{2, 30, 600, 16, 0, gScenarioBufferData270_SUB_16S_08U_16S, 64, gScenarioKernelData270_SUB_16S_08U_16S, 4},
{4, 30, 1200, 16, 0, gScenarioBufferData271_SUB_16S_08U_16S, 64, gScenarioKernelData271_SUB_16S_08U_16S, 4},
{6, 30, 1800, 16, 0, gScenarioBufferData272_SUB_16S_08U_16S, 64, gScenarioKernelData272_SUB_16S_08U_16S, 4},
{8, 30, 2400, 16, 0, gScenarioBufferData273_SUB_16S_08U_16S, 64, gScenarioKernelData273_SUB_16S_08U_16S, 4},
{10, 30, 3000, 16, 0, gScenarioBufferData274_SUB_16S_08U_16S, 64, gScenarioKernelData274_SUB_16S_08U_16S, 4},
{12, 30, 3600, 16, 0, gScenarioBufferData275_SUB_16S_08U_16S, 64, gScenarioKernelData275_SUB_16S_08U_16S, 4},
{2, 32, 640, 16, 0, gScenarioBufferData276_SUB_16S_08U_16S, 64, gScenarioKernelData276_SUB_16S_08U_16S, 4},
{4, 32, 1280, 16, 0, gScenarioBufferData277_SUB_16S_08U_16S, 64, gScenarioKernelData277_SUB_16S_08U_16S, 4},
{6, 32, 1920, 16, 0, gScenarioBufferData278_SUB_16S_08U_16S, 64, gScenarioKernelData278_SUB_16S_08U_16S, 4},
{8, 32, 2560, 16, 0, gScenarioBufferData279_SUB_16S_08U_16S, 64, gScenarioKernelData279_SUB_16S_08U_16S, 4},
{10, 32, 3200, 16, 0, gScenarioBufferData280_SUB_16S_08U_16S, 64, gScenarioKernelData280_SUB_16S_08U_16S, 4},
{12, 32, 3840, 16, 0, gScenarioBufferData281_SUB_16S_08U_16S, 64, gScenarioKernelData281_SUB_16S_08U_16S, 4}
};

static acf_scenario_list gScenarioList_SUB_16S_08U_16S = {
282, //number of scenarios
gScenarioArray_SUB_16S_08U_16S};
//**************************************************************

class SUB_16S_08U_16S : public ACF_Process_APU
{

public:
   SUB_16S_08U_16S(int32_t apex_id = 0) : ACF_Process_APU(apex_id)
   {} 

   int32_t Initialize()
   {
      int32_t lRetVal = 0;

      if (!Initialized()) //initialization steps that only need to occur once
      {
         SetProcessIdentifier("SUB_16S_08U_16S");
         SetApuLoadInfo(SUB_16S_08U_16S_LOAD_SEGMENTS,
                        SUB_16S_08U_16S_LOAD_PMEM, SUB_16S_08U_16S_LOAD_PMEM_SIZE,
                        SUB_16S_08U_16S_LOAD_DMEM, SUB_16S_08U_16S_LOAD_DMEM_SIZE,
                        0, 0); //assuming _LOAD_CMEM does not exist

         lRetVal = NonParametricInitialization();
         if (lRetVal != 0) return lRetVal;

         //***NOTE: the order in which the following ports are added is meaningful; do not change!

         AddPort("INPUT_0", icp::DATATYPE_16S, 1, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
         AddPort("INPUT_1", icp::DATATYPE_08U, 1, 1, 2, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
         AddPort("INPUT_2", icp::DATATYPE_08U, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 3, 0, 0, 0, 0, 0);
         AddPort("OUTPUT_0", icp::DATATYPE_16S, 1, 1, 2, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);

         CfgScenarios(&gScenarioList_SUB_16S_08U_16S);

         FlagAsInitialized();
      }

      lRetVal = SelectApuConfiguration(mApuCfg, mApexId); //by default mApuCfg = ACF_APU_CFG__APEX0_DEFAULT and mApexId = 0

      return lRetVal;
   }
};

#endif //_ACF_PROCESS_APU_SUB_16S_08U_16S
