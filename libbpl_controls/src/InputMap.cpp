//
// Created by Bradley Remedios on 11/8/24.
//

#include <functional>
#include <iostream>
#include <ostream>
#include <ranges>

#include <bpl/controls/InputMap.h>

namespace bpl::controls {
    InputMap::InputMap() = default;

    InputMap::~InputMap() = default;

    bool InputMap::Clear() {
        m_deviceKeyStateMap.clear();
        m_deviceAxisStateMap.clear();
        m_deviceSystemKeyCodeMap.clear();
        m_deviceSystemAxisCodeMap.clear();
        m_keyStateMap.clear();
        m_axisStateMap.clear();

        return true;
    } // Clear

    bool InputMap::MapKey(SDL_Keycode keySym, KeyCode keyCode) {
        return MapButton("sdl-keyboard", static_cast<int>(keySym), keyCode);
    } // MapKey

    bool InputMap::MapButton(const std::string& deviceName, int button, KeyCode code) {
        //
        //  New device, add it to the map.
        //
        if (!m_deviceSystemKeyCodeMap.contains(deviceName)) {
            m_deviceSystemKeyCodeMap.insert(std::pair<std::string, SystemKeyCodeMap>(deviceName, SystemKeyCodeMap()));
        }

        m_deviceSystemKeyCodeMap[deviceName][button].push_back(code);

        //
        //  Insert the key code into our keymap if it does not exist.
        //
        if (!m_keyStateMap.contains(code)) {
            m_keyStateMap.insert(std::pair<KeyCode, int>(code, false));
        }

        return true;
    } // MapButton

    bool InputMap::MapAxisToButton(const std::string& deviceName, int axis, int16_t directionThreshold, KeyCode code) {
        // save the thresholds
        if (!m_deviceAxisThresholdMap.contains(deviceName)) {
            m_deviceAxisThresholdMap.insert(std::pair<std::string,  AxisToButtonThresholdMap>(deviceName, AxisToButtonThresholdMap()));
        }

        if (!m_deviceAxisThresholdMap[deviceName].contains(axis)) {
            m_deviceAxisThresholdMap[deviceName].insert(std::pair<int, AxisThresholdKeyCodeList>(axis, AxisThresholdKeyCodeList()));
        }

        m_deviceAxisThresholdMap[deviceName][axis].push_back(AxisThresholdKeyCodePair(directionThreshold, code));

        // Add the mapping as a button made up of the axis and the keycode.
        return MapButton(deviceName + ":a2b", axis + static_cast<int>(code) * m_maxAxis, code);
    } // MapAxisToButton

    bool InputMap::MapAxis(const std::string& deviceName, int axis, AxisCode code) {
        //  We do not allow an axis to be mapped multiple times, we'll remap the axis to none so
        //  that it will be dropped.
        if (m_axisStateMap.contains(code)) {
            code = AXIS_NONE;
        }

        //
        //  New device, add it to the map.
        //
        if (!m_deviceSystemAxisCodeMap.contains(deviceName)) {
            m_deviceSystemAxisCodeMap.insert(std::pair<std::string, SystemAxisCodeMap>(deviceName, SystemAxisCodeMap()));
        }

        m_deviceSystemAxisCodeMap[deviceName][axis] = code;

        //
        //  Insert the key code into our keymap if it does not exist.
        //
        if (!m_axisStateMap.contains(code)) {
            m_axisStateMap.insert(std::pair<AxisCode, int>(code, 0));
        }

        return true;
    } // MapAxis

    bool InputMap::KeyDown(KeyCode key) {
        if (!m_keyStateMap.contains(key)) {
            return false;
        }

        return m_keyStateMap[key];
    } // KeyDown

    bool InputMap::KeyPressed(KeyCode key) {
        if (!m_keyPressed.contains(key)) {
            return false;
        }

        bool keyPressed = m_keyPressed[key];

        if (keyPressed) {
            m_keyPressed[key] = false;
        }
        return keyPressed;
    } // KeyPressed

    void InputMap::ClearPressedKeys() {
      for (auto& it : std::views::values(m_keyPressed)) {
          it = false;
      }
    } // ClearPressedKeys

    int16_t InputMap::Axis(AxisCode axis) {
        if (!m_axisStateMap.contains(axis)) {
            return 0;
        }

        return m_axisStateMap[axis];
    } // Axis

    bool InputMap::InputButton(const std::string& device, int button, int state) {
        for (auto & it : m_deviceSystemKeyCodeMap[device][button]) {
            //  Store our state
            m_deviceKeyStateMap[device][it] = state != 0;

            Update_(it);
        }

        return true;
    } // InputButton

    bool InputMap::InputAxis(const std::string& device, int axis, int16_t state) {

        // Normal axis handling
        if (m_deviceSystemAxisCodeMap.contains(device)) {
            // device does not have the axis mapped.
            if (m_deviceSystemAxisCodeMap[device].contains(axis)) {
                m_axisStateMap[m_deviceSystemAxisCodeMap[device][axis]] = state;
            }
        }

        // axis to button handling
        if (m_deviceAxisThresholdMap.contains(device) && m_deviceAxisThresholdMap[device].contains(axis))
        {
            for (auto it : m_deviceAxisThresholdMap[device][axis]) {
                int16_t threshold = it.first;
                KeyCode keyCode = it.second;

                if (threshold < 0) {
                    InputButton(device + ":a2b", axis + static_cast<int>(keyCode) * m_maxAxis, state <= threshold);
                } else if (threshold > 0) {
                    InputButton(device + ":a2b", axis + static_cast<int>(keyCode) * m_maxAxis, state >= threshold);
                }
            }
        }

        return true;
    } // InputAxis

    bool InputMap::InputSdl(const SDL_Event &event) {
        //
        //  We ignore anything that is not a keyboard event.
        //
        if ((event.type != SDL_KEYDOWN) && (event.type != SDL_KEYUP)) {
            return false;
        }

        return InputButton("sdl-keyboard", static_cast<int>(event.key.keysym.sym), event.type == SDL_KEYDOWN);
    } // InputSdl

    void InputMap::Update_(KeyCode code) {
        //
        //  If any of the keys are pressed, we set the state to pressed.
        //
        bool pressed = false;

        for (auto & device : std::views::values(m_deviceKeyStateMap)) {
            if (device[code]) {
                pressed = true;
            }
        }

        if (pressed && !m_keyStateMap[code]) {
            m_keyPressed[code] = true;
        }

        m_keyStateMap[code] = pressed;
    } // Update_

} // bpl::controls