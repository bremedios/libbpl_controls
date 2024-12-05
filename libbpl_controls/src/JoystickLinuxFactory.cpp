//
// Created by Bradley Remedios on 12/4/24.
//
#include <list>
#include <string>
#include <map>
#include <ranges>
#include <filesystem>

#include <bpl/controls/JoystickLinuxFactory.h>

#include "Debug.h"

namespace bpl::controls {

    std::list<std::string> JoystickLinuxFactory::getJoystickNames() {
        std::list<std::string> names;

        for (auto & it :std::views::keys(m_joystickNameMap)) {
            names.emplace_back(it);
        }

        return names;
    } // getJoystickNames()

    std::list<std::string> JoystickLinuxFactory::getJoystickDevices() {
        std::list<std::string> names;

        for (auto & it :std::views::values(m_joystickNameMap)) {
            names.emplace_back(it);
        }

        return names;
    } // getJoystickDevices()

    bpl::controls::JoystickLinuxPtr JoystickLinuxFactory::getJoystickByName(const std::string& name) {
        // Check to see if the joystick exists
        if (!m_joystickNameMap.contains(name)) {
            DEBUG_MSG("\"" << name << "\" does not exist" << std::endl);

            return JoystickLinuxPtr();
        }

        auto joystickDevice = m_joystickNameMap[name];

        DEBUG_MSG("Joystick Device: " << joystickDevice);

        if (!m_joystickMap.contains(joystickDevice)) {
            DEBUG_MSG("\"" << joystickDevice << "\" does not exist" << std::endl);
        }

        auto joystickPtr = m_joystickMap[m_joystickNameMap[name]];

        if (nullptr == joystickPtr) {
            DEBUG_MSG("Joystick not found");

            return joystickPtr;
        }

        return joystickPtr;
    } // getJoystickByName

    void JoystickLinuxFactory::UpdateDeviceList() {
        std::list<std::string> joysticks;
        std::list<std::string> existingJoysticks;

        //
        // get the list of already probed joysticks
        //
        for (auto& it : std::views::keys(m_joystickMap)) {
            existingJoysticks.emplace_back(it);
        }

        //
        // get the list of current devices
        //
        for (const auto &inputIt : std::filesystem::directory_iterator("/dev/input")) {
            //  Skip any input devices that are not a joystick
            if (0 != static_cast<std::string>(inputIt.path()).find("/dev/input/js", 0)) {
                continue;
            }

            joysticks.emplace_back(inputIt.path().string());
        }

        // remove any joysticks that have been removed from the system
        for (auto& it : existingJoysticks) {
            // joystick was removed, so we remove it from our map
            if (!std::binary_search(joysticks.begin(), joysticks.end(), it)) {
                m_joystickMap.erase(it);
            }
        }

        for (auto& it : joysticks) {
            // if we already have the joystick, no need to add it again
            if (m_joystickMap.contains(it)) {
                continue;
            }

            bpl::controls::JoystickLinuxPtr joystick = std::make_shared<JoystickLinux>();

            if (!joystick->Open(it)) {
                ERROR_MSG("JoystickLinux::Open(" << it << ") failed");
                continue;
            }

            m_joystickMap.emplace(it, joystick);
            m_joystickNameMap.emplace(joystick->getName(), it);
        }

        DEBUG_MSG("Found " << m_joystickMap.size() << " joysticks");
        for (auto &it : m_joystickNameMap) {
            DEBUG_MSG("    " << it.first << " : " << it.second);
        }

    } // UpdateDeviceList
};// bpl::controls