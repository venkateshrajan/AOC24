# CMakeList.txt : CMake project for AOCD2P1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (AOCD2P2 "AOCD2P2.cpp" "AOCD2P2.h")
configure_file(input.txt input.txt COPYONLY)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AOCD2P2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
