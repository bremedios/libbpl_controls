cmake_minimum_required(VERSION 3.28)

project(controls VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
include_directories(../libbpl_controls/include ../../libbpl_sys/libbpl_sys/include)
add_executable(controls src/main.cpp)

target_link_libraries(controls PRIVATE bpl_sys bpl_controls)

install(TARGETS controls DESTINATION usr/bin)