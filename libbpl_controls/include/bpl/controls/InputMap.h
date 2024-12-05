//
// Created by Bradley Remedios on 11/8/24.
//

#ifndef BPL_CONTROLS_INPUTMAP_H
#define BPL_CONTROLS_INPUTMAP_H

#include <map>
#include <list>
#include <string>

#include <SDL2/SDL.h>

#include <bpl/controls/Keycode.h>

namespace bpl::controls {

    class InputMap {
    public:
        InputMap();
        virtual ~InputMap();

        //
        //  Input map management
        //
        bool Clear();
        bool MapButton(const std::string& name, int button, KeyCode code);
        bool MapAxis(const std::string& name, int axis, AxisCode code);
        bool MapAxisToButton(const std::string& deviceName, int axis, int16_t directionThreshold, KeyCode code);
        bool MapKey(SDL_Keycode keySym, KeyCode keyCode);

        //
        //  Key state
        //
        bool KeyDown(KeyCode key);
        bool KeyPressed(KeyCode key);
        void ClearPressedKeys();


        int16_t Axis(AxisCode axis);

        bool InputSdl(const SDL_Event& event);;
        bool InputButton(const std::string& device, int button, int state);
        bool InputAxis(const std::string& device, int axis, int16_t state);
    private:
        // Axis to Button Thresholds
        typedef std::pair<int16_t, KeyCode>                     AxisThresholdKeyCodePair;
        typedef std::list<AxisThresholdKeyCodePair>             AxisThresholdKeyCodeList;
        typedef std::map<int, AxisThresholdKeyCodeList>         AxisToButtonThresholdMap;
        typedef std::map<std::string, AxisToButtonThresholdMap> DeviceAxisToAxisThresholdMap;

        // Storage of current controls state.
        typedef std::map<KeyCode, bool>                     KeyStateMap;
        typedef std::map<AxisCode, int16_t>                 AxisStateMap;

        // System to KeyCode/AxisCode map
        typedef std::map<int, std::list<KeyCode>>           SystemKeyCodeMap;
        typedef std::map<int, AxisCode>                     SystemAxisCodeMap;
        typedef std::map<SDL_Keycode, std::list<KeyCode>>   SdlKeyCodeMap;

        // Map from device name to device state.
        typedef std::map<std::string, SystemKeyCodeMap>     DeviceSystemKeyCodeMap;
        typedef std::map<std::string, SystemAxisCodeMap>    DeviceSystemAxisCodeMap;

        typedef std::map<std::string, KeyStateMap>          DeviceKeyStateMap;
        typedef std::map<std::string, AxisStateMap>         DeviceAxisStateMap;

        DeviceAxisToAxisThresholdMap    m_deviceAxisThresholdMap;
        DeviceKeyStateMap                m_deviceKeyStateMap;
        DeviceAxisStateMap               m_deviceAxisStateMap;

        // Device -> SystemKey -> Key/Axis Maps
        DeviceSystemKeyCodeMap           m_deviceSystemKeyCodeMap;
        DeviceSystemAxisCodeMap          m_deviceSystemAxisCodeMap;
        SdlKeyCodeMap                   m_sdlKeyCodeMap;

        // State maps
        KeyStateMap                      m_keyStateMap;
        KeyStateMap                      m_keyPressed;
        AxisStateMap                     m_axisStateMap;

        const int m_maxAxis = 100;

        void Update_(KeyCode code);
        void Update_(AxisCode code);
    };

} // bpl::controls

#endif //BPL_CONTROLS_INPUTMAP_H