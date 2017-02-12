//
// Created by janis on 2/12/17.
//

#pragma once

#include <QTransform>

#include "robot.h"

class Playground;

class SimulatedEntity {
public:
    virtual void tick(Playground* playground, double interval_sec) {};
};

class LineSegment {
public:
    LineSegment(QRectF rect) : rect(rect) {}
    QRectF rect;
    bool isInside(QPointF point) {
        return rect.contains(point);
    }
};

class SimulatedRobot;

class Playground : public SimulatedEntity {
public:
    SimulatedRobot* robot;
    std::vector<LineSegment> line_segemnts;

    void tick(Playground* playground, double interval_sec);
};

class SimulatedMotor : public Motor, SimulatedEntity {
public:
    void drive(int16_t speed) override;
    double getSpeed();
private:
    double speed;
};

class SimulatedRobot : public Robot, SimulatedEntity {
public:
    QTransform robot_to_world;
    double wheel_dist = 70.0;
    double length_front = 50.0;
    double length_back = 50.0;
    double width = 100.0;

    void tick(Playground* playground, double interval_sec);
};

class SimulatedSensor : public SimulatedEntity {
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
