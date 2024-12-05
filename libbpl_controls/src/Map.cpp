//
// Created by Bradley Remedios on 12/4/24.
//
#include <string>
#include <fstream>
#include <filesystem>

#include <bpl/sys/Path.h>

#include <bpl/storage/Json.h>
#include <bpl/controls/Map.h>
#include <bpl/controls/InputMap.h>

#include "Debug.h"


#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

namespace bpl::controls {
    bool Map::MapControls(bpl::controls::InputMap &inputMap) {
        for (auto& it : m_keyCodeMap) {
            if (!inputMap.MapButton(m_name, it.first, it.second)) {
                ERROR_MSG("InputMap::MapButton(" << it.first << ", " << it.second << ") failed");

                return false;
            }
        }

        for (auto& it : m_axisCodeMap) {
            if (!inputMap.MapAxis(m_name, it.first, it.second)) {
                ERROR_MSG("InputMap::MapAxis(" << it.first << ", " << it.second << ") failed");

                return false;
            }
        }

        for (auto& it : m_axisToKeyCodeList) {

            if (!inputMap.MapAxisToButton(m_name, it["axis"], it["threshold"], static_cast<bpl::controls::KeyCode>(it["button"]))) {
                ERROR_MSG("InputMap::MapAxisToButton(" << m_name << ", " << it["axis"] << ", " << it["threshold"] << ", " << it["button"] << ") failed");

                return false;
            }
        }

        DEBUG_MSG("TODO: Add Keyboard Mapping");

        return true;
    } // MapControls

    bool Map::Load(const std::string& filename) {
        auto json = bpl::storage::Json::Open(filename);

        if (nullptr == json) {
            ERROR_MSG("Failed to open controls map for " << filename);

            return false;
        }

        if (!json->IsObject()) {
            ERROR_MSG("Invalid Json Document, not an object");

            return false;
        }

        if (!bpl::storage::Json::Load(json, "name", m_name)) {
            ERROR_MSG("Failed to get name of controller");

            return false;
        }

        std::map<std::string, int> keymap;

        if (!bpl::storage::Json::Load(json, "button-map", keymap)) {
            ERROR_MSG("Failed to get button-map");

            return false;
        }

        for (auto& it : keymap) {
            m_keyCodeMap.emplace(std::stoi(it.first), static_cast<bpl::controls::KeyCode>(it.second));
        }

        if (json->GetObject().HasMember("axis-map")) {
            keymap.clear();

            if (!bpl::storage::Json::Load(json, "axis-map", keymap)) {
                ERROR_MSG("Failed to get axis-map");

                return false;
            }

            for (auto& it : keymap) {
                m_axisCodeMap.emplace(std::stoi(it.first), static_cast<bpl::controls::AxisCode>(it.second));
            }
        }
        else {
            DEBUG_MSG("No axis mapping for '" << m_name << "'");
        }

        if (json->GetObject().HasMember("axis-to-button-map")) {
            if (!json->GetObject()["axis-to-button-map"].IsArray()) {
                ERROR_MSG("axis-to-button-map is not an array");

                return false;
            }

            int size = json->GetObject()["axis-to-button-map"].Size();

            // ensure everything is an int.
            for (int i = 0; i < size; ++i) {
                keymap.clear();

                for (rapidjson::Value::ConstMemberIterator it = json->GetObject()["axis-to-button-map"][i].MemberBegin();
                    it != json->GetObject()["axis-to-button-map"][i].MemberEnd();
                    ++it) {

                    if (!it->name.IsString()) {
                        ERROR_MSG("Entry name is not a string");
                        return false;
                    }

                    if (!it->value.IsInt()) {
                        ERROR_MSG("Entry value is not an integer");
                        return false;
                    }

                    keymap.emplace(it->name.GetString(), it->value.GetInt());
                }

                std::map<std::string, int> keycode_map;

                if (!keymap.contains("axis")) {
                    ERROR_MSG("No axis in mapping");
                    return false;
                }
                if (!keymap.contains("threshold")) {
                    ERROR_MSG("No threshold in mapping");
                    return false;
                }
                if (!keymap.contains("button")) {
                    ERROR_MSG("No button in mapping");
                    return false;
                }

                keycode_map.emplace("axis", keymap["axis"]);
                keycode_map.emplace("threshold", keymap["threshold"]);
                keycode_map.emplace("button", keymap["button"]);

                m_axisToKeyCodeList.emplace_back(keycode_map);
            }
        }
        else {
            DEBUG_MSG("No axis to button mapping for '" << m_name << "'");
        }

        DEBUG_MSG("Controller name: " << m_name);

        return true;
    } // Load
}; // bpl::controls