//
// Created by Bradley Remedios on 12/4/24.
//

#include <chrono>
#include <iostream>
#include <list>

#include <ostream>

#include <bpl/sys/Tick.h>
#include <bpl/controls/Joystick.h>
#include <bpl/controls/JoystickLinuxFactory.h>

void ListControls_(bpl::controls::JoystickLinuxFactory& factory) {
    std::list joystickNames = factory.getJoystickNames();

    std::cout << "Joysticks" << std::endl;

    for (auto it : joystickNames) {
        std::cout << "    " << it << std::endl;
    }
}  // ListControls_

void Open_(bpl::controls::JoystickLinuxFactory& factory, const std::string& name) {
    auto joystick = factory.getJoystickByName(name);

    if (nullptr == joystick) {
        std::cout << "    ERROR: Joystick " << name << " not found" << std::endl;

        return;
    }

    std::cout << joystick->getName() << std::endl;
    std::cout << "    Hats: " << joystick->getHatCount() << std::endl;
    std::cout << "    Buttons: " << joystick->getButtonCount() << std::endl;
    std::cout << "    Axes: " << joystick->getAxesCount() << std::endl;
    std::cout << "    Balls: " << joystick->getBallsCount() << std::endl;

    bpl::sys::Tick tick(std::chrono::milliseconds(1000/120));

    std::vector<int16_t> axes;

    axes.resize(joystick->getAxesCount());

    for ( int i = 0; i < joystick->getAxesCount(); i++ ) {
        axes[i] = joystick->getAxisValue(i);
    }

    while (true) {
        joystick->Update();

        for (int i = 0; i < joystick->getHatCount(); i++) {
            if (joystick->isHatPressed(i)) {
                std::cout <<"    Hat " << i << " Pressed" << std::endl;
            }
        }

        for (int i = 0; i < joystick->getButtonCount(); i++) {
            if (joystick->isButtonPressed(i)) {
                std::cout << "    Button " << i <<  "Pressed" << std::endl;
            }
        }

        for (int i = 0; i < joystick->getAxesCount(); i++) {
            if (axes[i] != joystick->getAxisValue(i)) {
                std::cout << "    Axis " << i << ": " << axes[i] << std::endl;
                axes[i] = joystick->getAxisValue(i);
            }
        }

        tick.Wait();
    }

} // Open_

int main(int argc, char **argv) {
    std::cout << "Controls" << std::endl;

    bpl::controls::JoystickLinuxFactory factory;

    factory.UpdateDeviceList();

    Open_(factory, "8BitDo Pro 2 Wired Controller");

    if ((argc < 2) || (std::string(argv[1]) == "--list")) {
        ListControls_(factory);
    }
    else if ((argc == 3) && (std::string(argv[1]) == "--open")) {
        Open_(factory, argv[2]);
    }
    else {
        std::cout << "Usage: " << argv[1] << " [--list|--open]" << std::endl;
    }

    return 0;
} // main