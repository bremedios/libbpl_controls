//
// Created by Bradley Remedios 11/8/24.
//
#include <bpl/controls/Joystick.h>

namespace bpl::controls {
    const std::string& Joystick::GetName() const {
        return m_name;
    } // GetName

    int Joystick::AxesCount() const {
        return m_numAxes;
    } // AxesCount

    int Joystick::ButtonCount() const {
        return m_numButtons;
    } // ButtonCount

    int Joystick::BallsCount() const {
        return m_numBalls;
    } // BallsCount

    int Joystick::HatCount() const {
        return m_numHats;
    } // HatCount
}; // bpl::controls