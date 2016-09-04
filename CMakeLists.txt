cmake_minimum_required(VERSION 3.5)
project(CLionConanTemplate)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_STRIP FALSE)

set(CMAKE_VERBOSE_MAKEFILE TRUE)

include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES main.cpp ZMessage.cpp PollItems.cpp)
add_executable(CLionConanTemplate ${SOURCE_FILES})

target_link_libraries(CLionConanTemplate ${CONAN_LIBS})

