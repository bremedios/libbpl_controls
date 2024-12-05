//
// Created by Bradley Remedios on 12/4/24.
//

#include <iostream>
#include <string>

#include <bpl/controls/Input.h>

int main(int argc, char** argv) {
    bpl::controls::Input input;
    auto nextScan = std::chrono::steady_clock::now();
    auto scanPeriod = std::chrono::seconds(2);

    if ((argc == 2) && std::string("--list") == argv[1]) {
        std::cout << "--list not implemented" << std::endl;
    }
    else if ((argc == 2) && std::string("--open") == argv[1]) {
        if (!input.Create()) {
            std::cerr << "Input::Create() failed" << std::endl;

            return -1;
        }

        for (;;) {
            // this will re-scan for joysticks, we don't do it every update though
            if (std::chrono::steady_clock::now() > nextScan) {

                input.ScanJoysticks();
                nextScan = std::chrono::steady_clock::now() + scanPeriod;
            }

            input.Update();

            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_LEFT)) {
                std::cout << "INPUT_LEFT" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_RIGHT)) {
                std::cout << "INPUT_RIGHT" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_UP)) {
                std::cout << "INPUT_UP" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_DOWN)) {
                std::cout << "INPUT_DOWN" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_ESCAPE)) {
                std::cout << "INPUT_ESCAPE" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_ENTER)) {
                std::cout << "INPUT_ENTER" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_START)) {
                std::cout << "INPUT_START" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_SELECT)) {
                std::cout << "INPUT_SELECT" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_A)) {
                std::cout << "INPUT_BUTTON_A" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_B)) {
                std::cout << "INPUT_BUTTON_B" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_X)) {
                std::cout << "INPUT_BUTTON_X" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_Y)) {
                std::cout << "INPUT_BUTTON_Y" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_L1)) {
                std::cout << "INPUT_BUTTON_L1" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_L2)) {
                std::cout << "INPUT_BUTTON_L2" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_L3)) {
                std::cout << "INPUT_BUTTON_L3" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_L4)) {
                std::cout << "INPUT_BUTTON_L4" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_L5)) {
                std::cout << "INPUT_BUTTON_L5" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_R1)) {
                std::cout << "INPUT_BUTTON_R1" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_R2)) {
                std::cout << "INPUT_BUTTON_R2" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_R3)) {
                std::cout << "INPUT_BUTTON_R3" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_R4)) {
                std::cout << "INPUT_BUTTON_R4" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_R5)) {
                std::cout << "INPUT_BUTTON_R5" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_LEFT_STICK)) {
                std::cout << "INPUT_BUTTON_LEFT_STICK" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_BUTTON_RIGHT_STICK)) {
                std::cout << "INPUT_BUTTON_RIGHT_STICK" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_A)) {
                std::cout << "INPUT_KEY_A" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_B)) {
                std::cout << "INPUT_KEY_B" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_C)) {
                std::cout << "INPUT_KEY_C" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_D)) {
                std::cout << "INPUT_KEY_D" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_E)) {
                std::cout << "INPUT_KEY_E" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_F)) {
                std::cout << "INPUT_KEY_F" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_G)) {
                std::cout << "INPUT_KEY_G" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_H)) {
                std::cout << "INPUT_KEY_H" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_I)) {
                std::cout << "INPUT_KEY_I" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_J)) {
                std::cout << "INPUT_KEY_J" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_K)) {
                std::cout << "INPUT_KEY_K" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_L)) {
                std::cout << "INPUT_KEY_L" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_M)) {
                std::cout << "INPUT_KEY_M" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_N)) {
                std::cout << "INPUT_KEY_N" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_O)) {
                std::cout << "INPUT_KEY_O" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_P)) {
                std::cout << "INPUT_KEY_P" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_Q)) {
                std::cout << "INPUT_KEY_Q" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_R)) {
                std::cout << "INPUT_KEY_R" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_S)) {
                std::cout << "INPUT_KEY_S" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_T)) {
                std::cout << "INPUT_KEY_T" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_U)) {
                std::cout << "INPUT_KEY_U" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_V)) {
                std::cout << "INPUT_KEY_V" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_W)) {
                std::cout << "INPUT_KEY_W" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_X)) {
                std::cout << "INPUT_KEY_X" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_Y)) {
                std::cout << "INPUT_KEY_Y" << std::endl;
            }
            if (input.KeyPressed(bpl::controls::KeyCode::INPUT_KEY_Z)) {
                std::cout << "INPUT_KEY_Z" << std::endl;
            }
        }
    }
    else {
        std::cout << "Usage: " << argv[0] << "[--list|--open]" << std::endl;
    }
} // main