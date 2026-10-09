/**
 * @file
 *
 * Message ID base values of all cFS instances of the SC-OBC mission.
 *
 * The message ID of a topic is its base value ORed with the topic ID
 * (cfe_core_api_msgid_mapping.h). Topic IDs are 0x00 to 0xFF, so each
 * instance gets its own 0x100 block of command and of telemetry message IDs.
 * The ground (Yamcs) tells the instances apart by these blocks, whose APIDs
 * are 0x000 to 0x0FF on the RPU and 0x100 to 0x1FF on the APU. The
 * <cpu>_cfe_core_api_base_msgid_values.h header of each CPU selects its
 * block.
 *
 * The RPU runs the ground link (ci_lab, to_lab) and keeps the cFE default
 * blocks. Global messages, such as the TIME data and send commands, are
 * meant for every instance, so all instances use the same global blocks,
 * the cFE defaults. They lie in the topic range 0x60 to 0x6F of the RPU
 * block, which cFE reserves for them.
 */

#ifndef SCOBC_MSGID_BASES_H
#define SCOBC_MSGID_BASES_H

#define SCOBC_RPU_CMD_MID_BASE 0x1800
#define SCOBC_RPU_TLM_MID_BASE 0x0800

#define SCOBC_APU_CMD_MID_BASE 0x1900
#define SCOBC_APU_TLM_MID_BASE 0x0900

#define SCOBC_GLOBAL_CMD_MID_BASE 0x1860
#define SCOBC_GLOBAL_TLM_MID_BASE 0x0860

/**
 * Message ID value of a topic on another CPU, from its message ID value on
 * this CPU: SCOBC_MIDV(APU, TLM, CFE_ES_HK_TLM_MID) is the ES housekeeping
 * telemetry of the APU. type is CMD or TLM, as the message ID.
 */
#define SCOBC_MIDV(cpu, type, midv) (SCOBC_##cpu##_##type##_MID_BASE | ((midv)&0xFF))

#endif /* SCOBC_MSGID_BASES_H */
