﻿# CMakeList.txt : CMake project for PLAYGROUND, include source and define
# project specific logic here.
#

# Add source to this project's executable.
find_package(CURL REQUIRED)
add_executable (PLAYGROUND "main.cpp")
target_link_libraries(PLAYGROUND PRIVATE CURL::libcurl)
target_include_directories(PLAYGROUND PRIVATE ${CURL_INCLUDE_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PLAYGROUND PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
