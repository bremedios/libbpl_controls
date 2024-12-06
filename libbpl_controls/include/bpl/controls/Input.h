//
// Created by Bradley Remedios on 11/9/24.
//

#ifndef BPL_CONTROLS_INPUT_H
#define BPL_CONTROLS_INPUT_H

#include <string>

#include <SDL2/SDL.h>

#include <bpl/controls/InputMap.h>
#include <bpl/controls/JoystickLinux.h>
#include <bpl/controls/JoystickLinuxFactory.h>
#include <bpl/controls/Map.h>

namespace bpl::controls {
   class Input : public bpl::controls::JoystickCallback{
    public:
        static Input* getInstance();

        Input();
        virtual ~Input();

        bool Create();
        void Destroy();

        void Process(const SDL_Event& event);

        bool KeyDown(KeyCode key);
        bool KeyPressed(KeyCode key);
        void ClearPressedKeys();

        void Update();

        bool ScanJoysticks();
        void CallbackButtonPress(bpl::controls::Joystick* joystick, int button, int state) override;

        void CallbackAxisState(bpl::controls::Joystick* joystick, int axis, int16_t state) override;
        bool LoadDevice(const std::string& device);

    private:
        bool LoadKeyMap_();
        bpl::controls::InputMap                                 m_inputMap;
        std::map<std::string, bpl::controls::JoystickLinuxPtr>  m_joysticks;
        std::map<std::string, bpl::controls::MapPtr>            m_controlMaps;
        bpl::controls::JoystickLinuxFactoryPtr                  m_joystickFactory;
    }; // Input
    typedef std::shared_ptr<Input> InputPtr;
} // bpl::controls::

#endif //BPL_CONTROLS_INPUT_H