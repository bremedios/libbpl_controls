//
// Created by Bradley Remedios on 11/8/24.
//

#ifndef BPL_CONTROLS_JOYSTICKSDLFACTORY_H
#define BPL_CONTROLS_JOYSTICKSDLFACTORY_H

#include <map>

#include <bpl/controls/JoystickSdl.h>

namespace bpl::controls {

    class JoystickSdlFactory {
    public:
        static JoystickSdlFactory* getInstance();
        bpl::controls::JoystickPtr Get(int index);
        void Clear();
    private:
        std::map<int, std::shared_ptr<bpl::controls::JoystickSdl>> m_joysticks;
    }; // JoystickSdlFactory

} // bpl::controls

#endif //BPL_CONTROLS_JOYSTICKSDLFACTORY_H