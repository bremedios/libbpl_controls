//
// Created by Bradley Remedios on 11/8/24.
//

#include <bpl/controls/JoystickSdlFactory.h>
#include <iostream>

namespace bpl::controls {

    JoystickSdlFactory* JoystickSdlFactory::getInstance() {
        static JoystickSdlFactory instance;

        return &instance;
    } // getInstance

    JoystickPtr JoystickSdlFactory::Get(int index) {

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

    void JoystickSdlFactory::Clear() {
        m_joysticks.clear();
    }
} // bpl::controls