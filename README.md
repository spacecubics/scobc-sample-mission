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
