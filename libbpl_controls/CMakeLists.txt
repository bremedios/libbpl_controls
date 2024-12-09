cmake_minimum_required(VERSION 3.25)

project(bpl_controls)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2_ttf REQUIRED CONFIG REQUIRED COMPONENTS SDL2_TTF)
find_package(SDL2_IMAGE REQUIRED CONFIG COMPONENTS SDL2_image)

include_directories(include ../../libbpl_sys/libbpl_sys/include ../../libbpl_storage/libbpl_storage/include)

set(PUBLIC_HEADER include/bpl/controls/Input.h
        include/bpl/controls/InputMap.h
        include/bpl/controls/Joystick.h
        include/bpl/controls/JoystickSdlFactory.h
        include/bpl/controls/JoystickLinux.h
        include/bpl/controls/JoystickSdl.h
        include/bpl/controls/Map.h
        include/bpl/controls/Keycode.h)
set(SOURCE_FILES src/Input.cpp
        src/InputMap.cpp
        src/Joystick.cpp
        src/JoystickSdlFactory.cpp
        src/JoystickLinux.cpp
        src/JoystickSdl.cpp
        src/JoystickLinuxFactory.cpp
        src/Map.cpp)

add_library(bpl_controls SHARED ${SOURCE_FILES} ${PUBLIC_HEADER} )
target_link_libraries(bpl_controls PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf SDL2_image::SDL2_image bpl_sys bpl_storage)

install(TARGETS bpl_controls DESTINATION usr/lib)
install(FILES include/bpl/controls/Input.h DESTINATION usr/local/include/bpl/controls)
install(FILES include/bpl/controls/InputMap.h DESTINATION usr/local/include/bpl/controls)
install(FILES include/bpl/controls/Joystick.h DESTINATION usr/local/include/bpl/controls)
install(FILES include/bpl/controls/JoystickSdlFactory.h DESTINATION usr/local/include/bpl/controls)
install(FILES include/bpl/controls/JoystickLinux.h DESTINATION usr/local/include/bpl/controls)
install(FILES include/bpl/controls/JoystickSdl.h DESTINATION usr/local/include/bpl/controls)
install(FILES include/bpl/controls/Map.h DESTINATION usr/local/include/bpl/controls)
install(FILES include/bpl/controls/Keycode.h DESTINATION usr/local/include/bpl/controls)
install(DIRECTORY maps DESTINATION usr/share/bpl_controls)