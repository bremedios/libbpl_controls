project(test_controls)

add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} googletest/googletest/include ${SDL_INCLUDE_DIRS})

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

include_directories(../libbpl_controls/include)

add_executable(test_controls test_controls.cpp test_controls_axis.cpp test_controls_buttons.cpp
        test_controls_axis_buttons.cpp)

target_link_libraries(test_controls PRIVATE SDL2::SDL2 gtest gtest_main bpl_controls)