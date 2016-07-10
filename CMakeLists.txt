cmake_minimum_required(VERSION 3.5)
project(CLionZmqTemplate)

include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES main.cpp)
add_executable(CLionZmqTemplate ${SOURCE_FILES})

target_link_libraries(CLionZmqTemplate ${CONAN_LIBS})

