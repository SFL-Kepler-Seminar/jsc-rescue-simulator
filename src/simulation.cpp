#include "simulation.h"

void Playground::tick(Playground* playground, double interval_sec) {
    robot->tick(playground, interval_sec);
}

void SimulatedMotor::drive(int16_t speed) {
    this->speed = speed;
}

double SimulatedMotor::getSpeed() {
    return speed;
}


void SimulatedRobot::tick(Playground* playground, double interval_sec) {
    double speed_l = dynamic_cast<SimulatedMotor&>(*motor_l).getSpeed();
    double speed_r = dynamic_cast<SimulatedMotor&>(*motor_r).getSpeed();

    //{{v -> 1/2 (radius left_speed + radius right_speed), 
    //  omega -> -((radius left_speed - radius right_speed)/(wheel_dist))}}
    double linear_speed = (speed_l + speed_r) / 2.0;
    double angular_speed = (speed_r - speed_l) / wheel_dist;
    
    QTransform trans = QTransform().translate(linear_speed * interval_sec, 0.0).rotateRadians(angular_speed * interval_sec);
    this->robot_to_world = trans * this->robot_to_world;
}
