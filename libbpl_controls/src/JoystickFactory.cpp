//
// Created by Bradley Remedios on 11/8/24.
//

#include <iostream>
#include <bpl/controls/JoystickFactory.h>

namespace bpl::controls {

    JoystickFactory* JoystickFactory::getInstance() {
        static JoystickFactory instance;

        return &instance;
    } // getInstance

    JoystickPtr JoystickFactory::Get(int index) {

        if (m_joysticks.contains(index)) {
            return m_joysticks[index];
        }

        JoystickSdlPtr joystick = std::make_shared<JoystickSdl>();

        if (!joystick->Open(index)) {
            std::cerr << "Failed to open Joystick(" << index << ")" << std::endl;

            return {};
        }

        //
        //  Add created joystick
        //
        m_joysticks.insert(std::pair<int, JoystickSdlPtr>(index, joystick));

        return joystick;
    } // getJoystick

    void JoystickFactory::Clear() {
        m_joysticks.clear();
    }
} // bpl::controls