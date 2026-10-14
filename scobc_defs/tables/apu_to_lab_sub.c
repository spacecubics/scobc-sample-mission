/**
 * @file
 *
 * TO_LAB subscriptions of the APU, which sends its own telemetry to the
 * ground over its direct development link. The message IDs of the APU's
 * software bus already lie in the APU block (scobc_msgid_bases.h), so the
 * entries need no mapping.
 */

#include "cfe_tbl_filedef.h"
#include "cfe_sb_api_typedefs.h"
#include "to_lab_tbl.h"
#include "cfe_msgids.h"
#include "ci_lab_msgids.h"
#include "sample_app_msgids.h"
#include "to_lab_msgids.h"

/* Each entry is a message ID, its SB QoS and the number of messages its pipe
 * buffers. */
TO_LAB_Subs_t Subscriptions = {
    .Subs = {{CFE_SB_MSGID_WRAP_VALUE(CFE_ES_HK_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(CFE_ES_APP_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(CFE_ES_MEMSTATS_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(CFE_EVS_HK_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(CFE_EVS_LONG_EVENT_MSG_MID), {0, 0}, 32},
             {CFE_SB_MSGID_WRAP_VALUE(CFE_EVS_SHORT_EVENT_MSG_MID), {0, 0}, 32},
             {CFE_SB_MSGID_WRAP_VALUE(CFE_SB_HK_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(CFE_SB_STATS_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(CFE_TBL_HK_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(CFE_TBL_REG_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(CFE_TIME_HK_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(CFE_TIME_DIAG_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(CI_LAB_HK_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(TO_LAB_HK_TLM_MID), {0, 0}, 4},
             {CFE_SB_MSGID_WRAP_VALUE(SAMPLE_APP_HK_TLM_MID), {0, 0}, 4},

             /* CFE_SB_MSGID_RESERVED entry to mark the end of valid MsgIds */
             {CFE_SB_MSGID_RESERVED, {0, 0}, 0}}};

CFE_TBL_FILEDEF(Subscriptions, TO_LAB.Subscriptions, TO Lab Sub Tbl, to_lab_sub.tbl)
