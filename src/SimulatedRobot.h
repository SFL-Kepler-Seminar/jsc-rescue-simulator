//
// Created by janis on 2/12/17.
//

#pragma once

#include "robot.h"
#include "Playground.h"

class SimulatedMotor : public Motor {
public:
    SimulatedMotor();

    void drive(int16_t speed) override;
};

class SimulatedRobot : public Robot {
public:
    SimulatedRobot();
};

class SimulatedSensor {
protected:
    Playground *playground;
public:
    virtual ~SimulatedSensor() = 0;
};

class SimulatedColorLineSensor : public LineSensor, SimulatedSensor {
public:
    SimulatedColorLineSensor();

    virtual bool isLine() override;
};

class SimulatedDigitalLineSensor : public LineSensor, SimulatedSensor {
public:
    SimulatedDigitalLineSensor();

    bool isLine() override;

};