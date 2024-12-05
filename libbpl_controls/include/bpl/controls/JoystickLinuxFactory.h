//
// Created by Bradley Remedios on 12/4/24.
//
#include <string>
#include <map>
#include <list>
#include <mutex>
#include <chrono>
#include <memory>

#include <bpl/controls/JoystickLinux.h>

namespace bpl::controls {
    class JoystickLinuxFactory {
    public:
        std::list<std::string> getJoystickNames();
        std::list<std::string> getJoystickDevices();

        bpl::controls::JoystickPtr getJoystickByName(const std::string& name);
        void UpdateDeviceList();
    private:
        std::chrono::time_point<std::chrono::steady_clock>     m_nextPoll = std::chrono::steady_clock::now() + std::chrono::seconds(5);
        std::map<std::string, bpl::controls::JoystickLinuxPtr> m_joystickMap;
        std::map<std::string, std::string>                     m_joystickNameMap;

        std::mutex   m_mutex;
    }; // JoystickLinuxFactory

    typedef std::shared_ptr<JoystickLinuxFactory> JoystickLinuxFactoryPtr;
}; // namespace bpl::controls