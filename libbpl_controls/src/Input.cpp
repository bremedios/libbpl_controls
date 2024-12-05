//
// Created by Bradley Remedios on 11/9/24.
//

#include <ranges>
#include <string>
#include <iostream>
#include <filesystem>

#include <bpl/sys/Path.h>

#include <bpl/controls/Input.h>

#include "Debug.h"

namespace bpl::controls {
    Input::Input() = default;
    Input::~Input() = default;

    Input* Input::getInstance() {
        static Input* _inputPtr = nullptr;

        if (nullptr == _inputPtr) {
          _inputPtr = new Input();

          _inputPtr->Create();
        }

        return _inputPtr;
    } // getInstance
/*
    bool Input::Load8BitdoSN30Pro_() {
        //  8Bitdo SN30 Pro keymap
        m_inputMap.MapButton("8Bitdo SN30 Pro", 0, KeyCode::INPUT_ENTER);
        m_inputMap.MapButton("8Bitdo SN30 Pro", 0, KeyCode::INPUT_BUTTON_B);
        m_inputMap.MapButton("8Bitdo SN30 Pro", 1, KeyCode::INPUT_ESCAPE);
        m_inputMap.MapButton("8Bitdo SN30 Pro", 1, KeyCode::INPUT_BUTTON_A);
        m_inputMap.MapButton("8Bitdo SN30 Pro", 2, KeyCode::INPUT_BUTTON_Y);
        m_inputMap.MapButton("8Bitdo SN30 Pro", 3, KeyCode::INPUT_BUTTON_X);
        m_inputMap.MapButton("8Bitdo SN30 Pro", 4, KeyCode::INPUT_BUTTON_L1);
        m_inputMap.MapButton("8Bitdo SN30 Pro", 5, KeyCode::INPUT_BUTTON_R1);
        m_inputMap.MapButton("8Bitdo SN30 Pro", 6, KeyCode::INPUT_SELECT);
        m_inputMap.MapButton("8Bitdo SN30 Pro", 7, KeyCode::INPUT_START);
        m_inputMap.MapButton("8Bitdo SN30 Pro", 8, KeyCode::INPUT_BUTTON_LEFT_STICK);
        m_inputMap.MapButton("8Bitdo SN30 Pro", 9, KeyCode::INPUT_BUTTON_RIGHT_STICK);

        m_inputMap.MapAxis("8Bitdo SN30 Pro", 0, AXIS_LEFT_X);
        m_inputMap.MapAxis("8Bitdo SN30 Pro", 1, AXIS_LEFT_Y);
        m_inputMap.MapAxis("8Bitdo SN30 Pro", 3, AXIS_RIGHT_X);
        m_inputMap.MapAxis("8Bitdo SN30 Pro", 4, AXIS_RIGHT_Y);

        m_inputMap.MapAxisToButton("8Bitdo SN30 Pro", 6, -16000, KeyCode::INPUT_LEFT);
        m_inputMap.MapAxisToButton("8Bitdo SN30 Pro", 6, 16000, KeyCode::INPUT_RIGHT);
        m_inputMap.MapAxisToButton("8Bitdo SN30 Pro", 7, -16000, KeyCode::INPUT_UP);
        m_inputMap.MapAxisToButton("8Bitdo SN30 Pro", 7, 16000, KeyCode::INPUT_DOWN);
        m_inputMap.MapAxisToButton("8Bitdo SN30 Pro", 5, 16000, KeyCode::INPUT_BUTTON_R2);
        m_inputMap.MapAxisToButton("8Bitdo SN30 Pro", 2, 16000, KeyCode::INPUT_BUTTON_L2);

        return true;
    } //Load8BitdoSN30Pro

    bool Input::Load8BitdoPro2WiredController_() {
        //  8Bitdo SN30 Pro keymap
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 0, KeyCode::INPUT_ENTER);
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 0, KeyCode::INPUT_BUTTON_B);
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 1, KeyCode::INPUT_ESCAPE);
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 1, KeyCode::INPUT_BUTTON_A);
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 2, KeyCode::INPUT_BUTTON_Y);
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 3, KeyCode::INPUT_BUTTON_X);
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 4, KeyCode::INPUT_BUTTON_L1);
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 5, KeyCode::INPUT_BUTTON_R1);
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 6, KeyCode::INPUT_SELECT);
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 7, KeyCode::INPUT_START);
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 8, KeyCode::INPUT_BUTTON_LEFT_STICK);
        m_inputMap.MapButton("8BitDo Pro 2 Wired Controller", 9, KeyCode::INPUT_BUTTON_RIGHT_STICK);

        m_inputMap.MapAxis("8BitDo Pro 2 Wired Controller", 0, AXIS_LEFT_X);
        m_inputMap.MapAxis("8BitDo Pro 2 Wired Controller", 1, AXIS_LEFT_Y);
        m_inputMap.MapAxis("8BitDo Pro 2 Wired Controller", 3, AXIS_RIGHT_X);
        m_inputMap.MapAxis("8BitDo Pro 2 Wired Controller", 4, AXIS_RIGHT_Y);

        m_inputMap.MapAxisToButton("8BitDo Pro 2 Wired Controller", 6, -16000, KeyCode::INPUT_LEFT);
        m_inputMap.MapAxisToButton("8BitDo Pro 2 Wired Controller", 6, 16000, KeyCode::INPUT_RIGHT);
        m_inputMap.MapAxisToButton("8BitDo Pro 2 Wired Controller", 7, -16000, KeyCode::INPUT_UP);
        m_inputMap.MapAxisToButton("8BitDo Pro 2 Wired Controller", 7, 16000, KeyCode::INPUT_DOWN);
        m_inputMap.MapAxisToButton("8BitDo Pro 2 Wired Controller", 5, 16000, KeyCode::INPUT_BUTTON_R2);
        m_inputMap.MapAxisToButton("8BitDo Pro 2 Wired Controller", 2, 16000, KeyCode::INPUT_BUTTON_L2);

        return true;
    } //Load8BitdoPro2WiredController_

    bool Input::LoadKeyboardArrowKeys_() {
        m_inputMap.MapKey(SDLK_DOWN, controls::KeyCode::INPUT_DOWN);
        m_inputMap.MapKey(SDLK_UP, controls::KeyCode::INPUT_UP);
        m_inputMap.MapKey(SDLK_LEFT, controls::KeyCode::INPUT_LEFT);
        m_inputMap.MapKey(SDLK_RIGHT, controls::KeyCode::INPUT_RIGHT);
        return true;
    } //  LoadKeyboardArrowKeys_

    bool Input::LoadKeyboardLetterKeys_() {
        m_inputMap.MapKey(SDLK_a, controls::KeyCode::INPUT_KEY_A);
        m_inputMap.MapKey(SDLK_b, controls::KeyCode::INPUT_KEY_B);
        m_inputMap.MapKey(SDLK_c, controls::KeyCode::INPUT_KEY_C);
        m_inputMap.MapKey(SDLK_d, controls::KeyCode::INPUT_KEY_D);
        m_inputMap.MapKey(SDLK_e, controls::KeyCode::INPUT_KEY_E);
        m_inputMap.MapKey(SDLK_f, controls::KeyCode::INPUT_KEY_F);
        m_inputMap.MapKey(SDLK_g, controls::KeyCode::INPUT_KEY_G);
        m_inputMap.MapKey(SDLK_h, controls::KeyCode::INPUT_KEY_H);
        m_inputMap.MapKey(SDLK_i, controls::KeyCode::INPUT_KEY_I);
        m_inputMap.MapKey(SDLK_j, controls::KeyCode::INPUT_KEY_J);
        m_inputMap.MapKey(SDLK_k, controls::KeyCode::INPUT_KEY_K);
        m_inputMap.MapKey(SDLK_l, controls::KeyCode::INPUT_KEY_L);
        m_inputMap.MapKey(SDLK_m, controls::KeyCode::INPUT_KEY_M);
        m_inputMap.MapKey(SDLK_n, controls::KeyCode::INPUT_KEY_N);
        m_inputMap.MapKey(SDLK_o, controls::KeyCode::INPUT_KEY_O);
        m_inputMap.MapKey(SDLK_p, controls::KeyCode::INPUT_KEY_P);
        m_inputMap.MapKey(SDLK_q, controls::KeyCode::INPUT_KEY_Q);
        m_inputMap.MapKey(SDLK_r, controls::KeyCode::INPUT_KEY_R);
        m_inputMap.MapKey(SDLK_s, controls::KeyCode::INPUT_KEY_S);
        m_inputMap.MapKey(SDLK_t, controls::KeyCode::INPUT_KEY_T);
        m_inputMap.MapKey(SDLK_u, controls::KeyCode::INPUT_KEY_U);
        m_inputMap.MapKey(SDLK_v, controls::KeyCode::INPUT_KEY_V);
        m_inputMap.MapKey(SDLK_w, controls::KeyCode::INPUT_KEY_W);
        m_inputMap.MapKey(SDLK_x, controls::KeyCode::INPUT_KEY_X);
        m_inputMap.MapKey(SDLK_y, controls::KeyCode::INPUT_KEY_Y);
        m_inputMap.MapKey(SDLK_z, controls::KeyCode::INPUT_KEY_Z);

        return true;
    } //  LoadKeyboardLetterKeys_

    bool Input::LoadKeyboardStandardKeys_() {
        m_inputMap.MapKey(SDLK_ESCAPE, controls::KeyCode::INPUT_ESCAPE);
        m_inputMap.MapKey(SDLK_RETURN, controls::KeyCode::INPUT_ENTER);
        return true;
    } //  LoadKeyboardStandardKeys_

    bool Input::LoadDevice(const std::string& device) {
        if ("8Bitdo SN30 Pro" == device) {
              return Load8BitdoSN30Pro_();
        } else if ("8BitDo Pro 2 Wired Controller" == device) {
            return Load8BitdoPro2WiredController_();
        } else if ("Keyboard Arrow Keys" == device) {
            return LoadKeyboardArrowKeys_();
        } else if ("Keyboard Standard Keys" == device) {
            return LoadKeyboardArrowKeys_();
        } else if ("Keyboard Letter Keys" == device) {
            return LoadKeyboardLetterKeys_();
        } else if ("Keyboard" == device) {
            LoadKeyboardArrowKeys_();
            LoadKeyboardArrowKeys_();
            LoadKeyboardLetterKeys_();
        }

        return false;
    } // LoadDevice
*/
    bool Input::LoadKeyMap_() {
        // find our controls folder.
        auto path = bpl::sys::Path::getResourceFilename("controls");

        if (path.empty()) {
            ERROR_MSG("Failed to find controls map location");

            return false;
        }

        // Load our maps from disk, this does not map the inputs.
        for (const auto & entry: std::filesystem::directory_iterator(path)) {
            MapPtr mapPtr = std::make_shared<Map>();

            if (!mapPtr->Load(entry.path().string())) {
                ERROR_MSG("Failed to load map at path: " + entry.path().string());
                continue;
            }

            DEBUG_MSG("Adding '" << mapPtr->getName() << "' to control map");
            m_controlMaps.emplace(mapPtr->getName(), mapPtr);
        }

        return true;
    } // LoadKeyMap_

    bool Input::ScanJoysticks() {
        m_joystickFactory->UpdateDeviceList();

        auto joysticks = m_joystickFactory->getJoystickNames();

        for (auto& joystick: joysticks) {
            // if we do not have a mapping for the joystick we skip it
            if (!m_controlMaps.contains(joystick)) {
                DEBUG_MSG("No control map for '" << joystick << "' Skipping ...");

                continue;
            }

            // this will be called repeatedly, we do not want to double add joysticks
            if (m_joysticks.contains(joystick)) {
                DEBUG_MSG("Joystick '" << joystick << "' already exists, Skipping ...");

                continue;
            }

            if (!m_controlMaps[joystick]->MapControls(m_inputMap)) {
                ERROR_MSG("Failed to add control mapping for '" << joystick << "'");

                return false;
            }

            // Add and register joystick
            auto js = m_joystickFactory->getJoystickByName(joystick);

            m_joysticks.emplace(js->getName(), js);

            js->RegisterCallback(this);
        }

        return true;
    } // ScanJoysticks

    bool Input::Create() {
        LoadKeyMap_();

        m_joystickFactory = std::make_shared<bpl::controls::JoystickLinuxFactory>();

        if (!ScanJoysticks()) {
            ERROR_MSG("Failed to scan joysticks");

            return false;
        }

        return true;
    } // Create

    void Input::Destroy() {
        m_inputMap.Clear();
    } //  Destroy

    void Input::Process(const SDL_Event& event) {
        m_inputMap.InputSdl(event);
    } // Process

    bool Input::KeyDown(KeyCode key) {
        return m_inputMap.KeyDown(key);
    } // KeyDown

    bool Input::KeyPressed(KeyCode key) {
        return m_inputMap.KeyPressed(key);
    } // KeyPressed

    void Input::ClearPressedKeys() {
        return m_inputMap.ClearPressedKeys();
    } // ClearPressedKeys

    void Input::CallbackButtonPress(Joystick* joystick, int button, int state) {
        m_inputMap.InputButton(joystick->getName(), button, state);;
    }

    void Input::CallbackAxisState(Joystick* joystick, int axis, int16_t state) {
        m_inputMap.InputAxis(joystick->getName(), axis, state);;
    }

    void Input::Update() {
        for (auto & it : std::views::values(m_joysticks)) {
            it->Update();
        }
    }

}; // bpl::controls