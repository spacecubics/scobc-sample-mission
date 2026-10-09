/**
 * @file
 *
 * SCH_LAB schedule of every CPU: requests the housekeeping telemetry of the
 * cFE services and of the applications. The message IDs are those of the CPU
 * the table is built for.
 */

#include "cfe_tbl_filedef.h"
#include "cfe_sb_api_typedefs.h"
#include "sch_lab_tbl.h"
#include "cfe_msgids.h"
#include "ci_lab_msgids.h"
#include "sample_app_msgids.h"
#include "to_lab_msgids.h"

/* Each entry is a message ID, its period in ticks (TickRate per second) and
 * an optional payload. */
SCH_LAB_ScheduleTable_t Schedule = {
    .TickRate = 100,
    .Config   = {
        {CFE_SB_MSGID_WRAP_VALUE(CFE_ES_SEND_HK_MID), 100, 0},
        {CFE_SB_MSGID_WRAP_VALUE(CFE_EVS_SEND_HK_MID), 100, 0},
        {CFE_SB_MSGID_WRAP_VALUE(CFE_SB_SEND_HK_MID), 100, 0},
        {CFE_SB_MSGID_WRAP_VALUE(CFE_TBL_SEND_HK_MID), 100, 0},
        {CFE_SB_MSGID_WRAP_VALUE(CFE_TIME_SEND_HK_MID), 100, 0},
        {CFE_SB_MSGID_WRAP_VALUE(CI_LAB_SEND_HK_MID), 100, 0},
        {CFE_SB_MSGID_WRAP_VALUE(TO_LAB_SEND_HK_MID), 100, 0},
        {CFE_SB_MSGID_WRAP_VALUE(SAMPLE_APP_SEND_HK_MID), 100, 0},
        {CFE_SB_MSGID_RESERVED, 0, 0},
    }
};

CFE_TBL_FILEDEF(Schedule, SCH_LAB.Schedule, Schedule Lab MsgID Table, sch_lab_table.tbl)
