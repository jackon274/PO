# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Kalkulator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Kalkulator_autogen.dir\\ParseCache.txt"
  "Kalkulator_autogen"
  )
endif()
