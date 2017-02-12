#pragma once
#include <cstdint>

class Motor {
public:
    virtual void drive(int16_t speed) = 0;
};

class LineSensor {
public:
    virtual bool isLine() = 0;
};

class ColorLineSensor : public LineSensor {
public:
    virtual uint16_t getR() = 0;
    virtual uint16_t getG() = 0;
    virtual uint16_t getB() = 0;
    virtual uint16_t getW() = 0;
};

class Robot {
public:
    Motor* motor_l;
    Motor* motor_r;
    LineSensor** line_sensors;
};
