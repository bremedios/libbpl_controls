//
// Created by Bradley Remedios on 12/4/24.
//

#ifndef BPL_CONTROLS_MAP_H
#define BPL_CONTROLS_MAP_H

#include <map>

#include <bpl/controls/Keycode.h>
#include <bpl/controls/InputMap.h>

namespace bpl::controls {
    class Map {
    public:
        Map() = default;
        ~Map() = default;

        const std::string& getName() const {return m_name;}
        bool Load(const std::string& filename);
        bool MapControls(bpl::controls::InputMap &input_map);

    private:
        std::string m_name;
        std::map<int, bpl::controls::KeyCode>                    m_keyCodeMap;
        std::map<int, bpl::controls::AxisCode>                   m_axisCodeMap;
        std::list<std::map<std::string, int>>                    m_axisToKeyCodeList;

    }; // Map
    typedef std::shared_ptr<Map> MapPtr;
};// bpl::controls
#endif //BPL_CONTROLS_MAP_H