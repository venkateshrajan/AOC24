# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("AOC24")

# Include sub-projects.
add_subdirectory ("AOCD1P1")
add_subdirectory ("AOCD1P2")
add_subdirectory ("AOCD2P1")
add_subdirectory ("AOCD2P2")
add_subdirectory ("AOCD3P1")
add_subdirectory ("AOCD3P2")
add_subdirectory ("AOCD4P1")
add_subdirectory ("PLAYGROUND")
