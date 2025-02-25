# CMakeList.txt : CMake project for AOCD5P1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (AOCD5P1 "AOCD5P1.cpp" "AOCD5P1.h")
configure_file(input.txt input.txt COPYONLY)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AOCD5P1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
