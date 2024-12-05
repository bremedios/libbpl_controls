//
// Created by Bradley Remedios 11/8/24.
//
#include <bpl/controls/Joystick.h>

namespace bpl::controls {
    const std::string& Joystick::getName() const {
        return m_name;
    } // getName

    int Joystick::getAxesCount() const {
        return m_numAxes;
    } // getAxesCount

    int Joystick::getButtonCount() const {
        return m_numButtons;
    } // getButtonCount

    int Joystick::getBallsCount() const {
        return m_numBalls;
    } // getBallsCount

    int Joystick::getHatCount() const {
        return m_numHats;
    } // getHatCount
}; // bpl::controls