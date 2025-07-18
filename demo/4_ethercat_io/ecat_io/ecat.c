/*
 * Copyright (c) 2024 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdio.h>
#include "board.h"
#include "ecat_def.h"
#include "ecatappl.h"
#include "ecatslv.h"
#include "applInterface.h"
#include "digital_io.h"
#include "hpm_ecat_hw.h"
#include "hpm_l1c_drv.h"
#include "oled.h"

int main(void)
{
    hpm_stat_t stat;
    board_init();
    board_init_led_pins();
    OLED_Init();
    OLED_ColorTurn(0);    //0正常显示，1 反色显示
    OLED_DisplayTurn(0);  //0正常显示 1 屏幕翻转显示
    OLED_ShowString(20,0,"[EtherCAT]",16,1);
    OLED_ShowString(0,16,"InputCounter",16,1);
    OLED_Refresh();

    board_init_ethercat(HPM_ESC); /* init ESC function pins */
    printf("EtherCAT IO sample\n");

    /* hardware init */
    stat = ecat_hardware_init(HPM_ESC);
    if (stat != status_success) {
        printf("Init ESC peripheral and related devices(EEPROM/PHY) failed!\n");
        return 0;
    }

    MainInit(); /* SSC Initilize the stack */

#if defined(ESC_EEPROM_EMULATION) && ESC_EEPROM_EMULATION
    pAPPL_EEPROM_Read  = ecat_eeprom_emulation_read;
    pAPPL_EEPROM_Write = ecat_eeprom_emulation_write;
    pAPPL_EEPROM_Reload = ecat_eeprom_emulation_reload;
    pAPPL_EEPROM_Store  = ecat_eeprom_emulation_store;
#endif

    /* Create basic mapping */
    APPL_GenerateMapping(&nPdInputSize, &nPdOutputSize);

    /* Set stack run flag */
    bRunApplication = TRUE;
    /* Execute the stack */
    while (bRunApplication == TRUE) {
        MainLoop();
    }

    /* hardware deinit */

    return 0;
}
