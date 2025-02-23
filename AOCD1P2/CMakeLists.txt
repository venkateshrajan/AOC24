# CMakeList.txt : CMake project for AOCD1P2, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (AOCD1P2 "AOCD1P2.cpp" "AOCD1P2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AOCD1P2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
