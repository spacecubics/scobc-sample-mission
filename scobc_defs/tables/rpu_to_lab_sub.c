/**
 * @file
 *
 * TO_LAB subscriptions of the RPU, which sends the telemetry of both CPUs to
 * the ground. The telemetry of the APU reaches the software bus of the RPU
 * through the link between the CPUs.
 */

#include "cfe_tbl_filedef.h"
#include "cfe_sb_api_typedefs.h"
#include "to_lab_tbl.h"
#include "cfe_msgids.h"
#include "ci_lab_msgids.h"
#include "sample_app_msgids.h"
#include "to_lab_msgids.h"
#include "../scobc_msgid_bases.h"

/* Housekeeping and event telemetry of one CPU: MIDV maps the message ID
 * value of the RPU to that CPU. Each entry is a message ID, its SB QoS and
 * the number of messages its pipe buffers. */
#define SCOBC_TLM_SUBS(MIDV)                                                     \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_ES_HK_TLM_MID)), {0, 0}, 4},               \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_ES_APP_TLM_MID)), {0, 0}, 4},              \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_ES_MEMSTATS_TLM_MID)), {0, 0}, 4},         \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_EVS_HK_TLM_MID)), {0, 0}, 4},              \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_EVS_LONG_EVENT_MSG_MID)), {0, 0}, 32},     \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_EVS_SHORT_EVENT_MSG_MID)), {0, 0}, 32},    \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_SB_HK_TLM_MID)), {0, 0}, 4},               \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_SB_STATS_TLM_MID)), {0, 0}, 4},            \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_TBL_HK_TLM_MID)), {0, 0}, 4},              \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_TBL_REG_TLM_MID)), {0, 0}, 4},             \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_TIME_HK_TLM_MID)), {0, 0}, 4},             \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CFE_TIME_DIAG_TLM_MID)), {0, 0}, 4},           \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(CI_LAB_HK_TLM_MID)), {0, 0}, 4},               \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(TO_LAB_HK_TLM_MID)), {0, 0}, 4},               \
    {CFE_SB_MSGID_WRAP_VALUE(MIDV(SAMPLE_APP_HK_TLM_MID)), {0, 0}, 4}

#define RPU_MIDV(midv) (midv)
#define APU_MIDV(midv) SCOBC_MIDV(APU, TLM, midv)

TO_LAB_Subs_t Subscriptions = {.Subs = {SCOBC_TLM_SUBS(RPU_MIDV),
                                        SCOBC_TLM_SUBS(APU_MIDV),

                                        /* CFE_SB_MSGID_RESERVED entry to mark the end of valid MsgIds */
                                        {CFE_SB_MSGID_RESERVED, {0, 0}, 0}}};

CFE_TBL_FILEDEF(Subscriptions, TO_LAB.Subscriptions, TO Lab Sub Tbl, to_lab_sub.tbl)
