# scobc-mission

cFS mission definitions for the SC-OBC Module V1, shared by its cFS
instances:

- Linux on the APU, built by the `cfs-scobc` recipe in
  `meta-scobc-cfs` through the cFE mission build
- Zephyr on the RPU, built with west through the cFE Zephyr module

`scobc_defs/` follows the cFE `<mission>_defs` conventions (see
`cfe/cmake/sample_defs`). Mission-scope files, such as `cfe_perfids.h`,
apply to every CPU. Files prefixed with a CPU name, such as
`apu_cfe_es_startup.scr`, apply to that CPU only.

Each CPU has its own block of message IDs, so that the software buses of
both instances can be joined and the ground (Yamcs) can tell their packets
apart: `scobc_msgid_bases.h` lists the blocks (RPU 0x18xx/0x08xx, the cFE
defaults; APU 0x19xx/0x09xx) and `<cpu>_cfe_core_api_base_msgid_values.h`
selects the block of a CPU.

The RPU runs the ground link (ci_lab and to_lab over UDP). Its to_lab table,
`tables/rpu_to_lab_sub.c`, subscribes to the telemetry of both CPUs; the
APU's arrives through the link between the CPUs. `tables/sch_lab_table.c`
requests the housekeeping telemetry on every CPU. `global_build_options.cmake`
makes the headers of all applications available to the tables.
