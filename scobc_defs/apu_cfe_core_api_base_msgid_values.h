/**
 * @file
 *
 * Message ID base values of the APU, see scobc_msgid_bases.h.
 */

#ifndef APU_CFE_CORE_API_BASE_MSGID_VALUES_H
#define APU_CFE_CORE_API_BASE_MSGID_VALUES_H

#include "scobc_msgid_bases.h"

#define CFE_PLATFORM_BASE_MIDVAL(x) SCOBC_APU_##x##_MID_BASE
#define CFE_GLOBAL_BASE_MIDVAL(x)   SCOBC_GLOBAL_##x##_MID_BASE

#endif /* APU_CFE_CORE_API_BASE_MSGID_VALUES_H */
