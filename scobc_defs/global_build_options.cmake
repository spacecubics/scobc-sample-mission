# Build options of every CPU, included by the cFE mission and arch builds
# and by the cFE Zephyr module.
#
# The tables of an application may refer to the message IDs of other
# applications: sch_lab schedules their housekeeping requests and to_lab
# subscribes to their telemetry. A table is compiled with the include
# directories of its own application only, so make the public headers of
# all applications of the mission available. The mission build reads the
# application directories later, so it skips them here.
foreach(APP ${MISSION_APPS})
  if(DEFINED ${APP}_MISSION_DIR AND IS_DIRECTORY ${${APP}_MISSION_DIR}/fsw/inc)
    include_directories(${${APP}_MISSION_DIR}/fsw/inc)
  endif()
endforeach()
