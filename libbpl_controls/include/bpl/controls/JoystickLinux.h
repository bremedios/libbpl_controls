//
// Created by Bradley Remedios on 11/8/24.
//

#ifndef BPL_CONTROLS_JOYSTICKLINUX_H
#define BPL_CONTROLS_JOYSTICKLINUX_H

#include <linux/joystick.h>

#include <bpl/controls/Joystick.h>

namespace bpl::controls {

    class JoystickCallback {
    public:
        virtual void CallbackButtonPress(bpl::controls::Joystick* joystick, int button, int state)=0;
        virtual void CallbackAxisState(bpl::controls::Joystick* joystick, int axis, int16_t state)=0;

    private:

    }; // JoystickCallback

    class JoystickLinux : public Joystick{
    public:
        JoystickLinux();
        ~JoystickLinux() override;

        void RegisterCallback(bpl::controls::JoystickCallback* callback);
        bool Close() override;
        [[nodiscard]] bool Open(const std::string& filename);

        [[nodiscard]] bool ButtonPressed(int button) const override;
        [[nodiscard]] uint8_t HatPressed(int button) const override;
        [[nodiscard]] int16_t AxisValue(int index) const override;
        void Update() override;
    protected:
        void ProcessEvent_(const js_event& event);
    private:
        bpl::controls::JoystickCallback* m_callback;
        int m_fd = -1;
        int16_t* m_axisState=nullptr;
        int16_t* m_buttonState=nullptr;
    };
    typedef std::shared_ptr<bpl::controls::JoystickLinux> JoystickLinuxPtr;

} // bpl::controls

#endif //BPL_CONTROLS_JOYSTICKLINUX_H