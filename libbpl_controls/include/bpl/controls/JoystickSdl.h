//
// Created by Bradley Remedios on 11/8/24.
//

#ifndef JOYSTICKSDL_H
#define JOYSTICKSDL_H

#include <memory>
#include <SDL2/SDL.h>

#include <bpl/controls/Joystick.h>

namespace bpl::controls {

    class JoystickSdl : public Joystick {
    public:

        JoystickSdl();
        ~JoystickSdl() override;

        bool Close() override;
        bool Open(int index);

        [[nodiscard]] bool ButtonPressed(int button) const override;
        [[nodiscard]]  uint8_t HatPressed(int button) const override;
        void Update() override;
        [[nodiscard]] int16_t AxisValue(int index) const override;
    private:
        SDL_Joystick* m_joystick=nullptr;
    };

    typedef std::shared_ptr<bpl::controls::JoystickSdl> JoystickSdlPtr;

} // controls

#endif //JOYSTICKSDL_H