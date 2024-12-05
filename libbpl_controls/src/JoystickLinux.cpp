//
// Created by Bradley Remedios on 11/8/24.
//

#include <iostream>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>

#include <bpl/controls/JoystickLinux.h>

namespace bpl::controls {
    JoystickLinux::JoystickLinux() = default;

    JoystickLinux::~JoystickLinux() {
        Close();
    }

    bool JoystickLinux::Close() {
        m_callback = nullptr;

        if (m_fd >= 0) {
            close(m_fd);
            m_fd = -1;
        }

        if (nullptr != m_axisState) {
            delete [] m_axisState;

            m_axisState = nullptr;
        }

        if (nullptr != m_buttonState) {
            delete [] m_buttonState;

            m_buttonState = nullptr;
        }

        return true;
    } // Close

    bool JoystickLinux::Open(const std::string& filename) {
        Close();

        m_fd = open(filename.c_str(), O_RDONLY | O_NONBLOCK);

        if (m_fd < 0) {
            std::cerr << "Failed to open joystick device: " << filename << std::endl;
            return false;
        }

        char data8 = 0;

        if (ioctl(m_fd, JSIOCGAXES, &data8) < 0) {
            std::cerr << "Failed to get number of axes: " << filename << std::endl;
            data8 = 0;
        }

        m_numAxes = data8;

        if (ioctl(m_fd, JSIOCGBUTTONS, &data8) < 0) {
            std::cerr << "Failed to get number of buttons: " << filename << std::endl;
            data8 = 0;
        }

        m_numButtons = data8;

        char joystickName[512];

        if (ioctl(m_fd, JSIOCGNAME(sizeof(joystickName)), joystickName) < 0) {
            std::cerr << "Failed to get number of buttons: " << filename << std::endl;
            joystickName[0] = '\0';
        }

        m_name = joystickName;
        m_buttonState = new int16_t[m_numButtons];
        m_axisState = new int16_t[m_numAxes];

        for (int i = 0; i < m_numAxes; i++) {
            m_axisState[i] = 0;
        }

        for (int i = 0; i < m_numButtons; i++) {
            m_buttonState[i] = 0;
        }

        return true;
    } // Open

    void JoystickLinux::RegisterCallback(JoystickCallback* callback) {
        m_callback = callback;
    } // RegisterCallback

    int16_t JoystickLinux::getAxisValue(int index) const {
        if (index >= m_numAxes) {
            std::cerr << "AxisValue: Invalid Axis(" << index << ")" << std::endl;
            return false;
        }

        return m_axisState[index];
    } // getAxisValue

    bool JoystickLinux::isButtonPressed(int button) const {
        if (button >= m_numButtons) {
            std::cerr << "ButtonPressed: Invalid Button(" << button << ")" << std::endl;
            return false;
        }
        if (m_buttonState[button] == 0) {
            return false;
        }
        else {
            return true;
        }
    } // isButtonPressed

    bool JoystickLinux::isHatPressed(int button) const {
        return false;
    } // isHatPressed

    void JoystickLinux::ProcessEvent_(
        const js_event& event) {

        //
        //  We do not need to differentiate if an event is being reported on open or not.
        //
        switch (event.type & ~JS_EVENT_INIT) {
            case JS_EVENT_AXIS:
                if (event.number >= m_numAxes) {
                    std::cerr << "Invalid Axis received" << std::endl;
                    break;
                }
                m_axisState[event.number] = event.value;

#if 0
                if (event.number == 6) {
                    std::cout << "Axis 6: " << event.value << std::endl;
                } else {
                    std::cout << "Axis (" << std::to_string(event.number) << "): " << event.value << std::endl;
                }
#endif

                if (nullptr != m_callback) {
                    m_callback->CallbackAxisState(this, event.number, event.value);

                }
                break;
            case JS_EVENT_BUTTON:
                if (event.number >= m_numButtons) {
                    std::cerr << "Invalid Button received" << std::endl;
                    break;
                }
                m_buttonState[event.number] = event.value;

                if (nullptr != m_callback) {
                    m_callback->CallbackButtonPress(this, event.number, event.value);
                }
                break;
            default:
                std::cout << "Unhandled event type: " << std::to_string(event.type) << std::endl;
            break;
        }
    } // ProcessEvent_

    void JoystickLinux::Update() {
        js_event event={0};
        while (read(m_fd, &event, sizeof(event)) > 0) {
            ProcessEvent_(event);
        }
    } // Update

} // bpl::controls