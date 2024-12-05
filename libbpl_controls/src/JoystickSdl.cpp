//
// Created by Bradley Remedios on 11/8/24.
//

#include <iostream>
#include <ostream>

#include <bpl/controls/JoystickSdl.h>

namespace bpl::controls {
    JoystickSdl::JoystickSdl() = default;

    JoystickSdl::~JoystickSdl()
    {
        if (nullptr != m_joystick) {
            SDL_JoystickClose(m_joystick);
        }
    }

    bool JoystickSdl::Close() {
        if (nullptr != m_joystick) {
            SDL_JoystickClose(m_joystick);
        }

        m_joystick = nullptr;

        return true;
    } // Close

    bool JoystickSdl::Open(int index) {
        //
        //  Close any opened joysticks
        //
        Close();

        m_joystick = SDL_JoystickOpen(index);

        if (nullptr == m_joystick) {
            std::cerr << "Failed to open Joystick " << index << ": " << SDL_GetError() << std::endl;

            return false;
        }

        m_name = SDL_JoystickName(m_joystick);
        m_numHats = SDL_JoystickNumHats(m_joystick);
        m_numButtons = SDL_JoystickNumButtons(m_joystick);
        m_numBalls = SDL_JoystickNumBalls(m_joystick);
        m_numAxes = SDL_JoystickNumAxes(m_joystick);

        return true;
    } // Open

    void JoystickSdl::Update() {
        // not needed if we have a SDL event loop
        SDL_JoystickUpdate();
    } // Update

    int16_t JoystickSdl::getAxisValue(int index) const {
        return 0;
    } // getAxisValue

    bool JoystickSdl::isButtonPressed(int button) const {
        return SDL_JoystickGetButton(m_joystick, button) != 0;
    } // isButtonPressed

    bool JoystickSdl::isHatPressed(int button) const {
        return SDL_JoystickGetHat(m_joystick, button) != 0;
    } // isHatPressed

} // bpl::controls