//
// Created by Bradley Remedios on 11/8/24.
//

#ifndef BPL_CONTROLS_JOYSTICK_H
#define BPL_CONTROLS_JOYSTICK_H

#include <string>
#include <memory>

namespace bpl::controls {
    class Joystick {
    public:
        Joystick() = default;
        virtual ~Joystick() = default;

        virtual bool Close()=0;

        [[nodiscard]] virtual const std::string& GetName() const;
        [[nodiscard]] virtual int HatCount() const;
        [[nodiscard]] virtual int ButtonCount() const;
        [[nodiscard]] virtual int AxesCount() const;
        [[nodiscard]] virtual int BallsCount() const;

        [[nodiscard]] virtual int16_t AxisValue(int index) const=0;
        [[nodiscard]] virtual bool ButtonPressed(int button) const=0;
        [[nodiscard]] virtual uint8_t HatPressed(int button) const=0;
        virtual void Update()=0;
    protected:
        std::string m_name;

        int m_numHats=0;
        int m_numButtons=0;
        int m_numAxes=0;
        int m_numBalls=0;
    };

    typedef std::shared_ptr<Joystick> JoystickPtr;
}; // namespace bpl::controls
#endif //BPL_CONTROLS_JOYSTICK_H