//
// Created by janis on 2/12/17.
//

#pragma once

#include "robot.h"

class SimulatedMotor : public Motor {
public:
    SimulatedMotor();
    void drive(int16_t speed) override;
};

class SimulatedRobot : public Robot {
public:
    SimulatedRobot();
};

class SimulatedColorLineSensor:public SimulatedDigitalLineSensor {
public:
    SimulatedColorLineSensor();
    virtual bool isLine() override;
};

class SimulatedDigitalLineSensor:public LineSensor {
public:
    SimulatedDigitalLineSensor();
    bool isLine() override ;

};