#include "PlaygroundView.h"

PlaygroundView::PlaygroundView(QWidget* parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);
    setTransform(QTransform().scale(1.0, -1.0));
}

void PlaygroundView::draw(const Playground& playground) {
    scene->clear();
    for(auto& line_segemnts: playground.line_segemnts) {
        scene->addRect(line_segemnts.rect);
    }
    SimulatedRobot& robot = *playground.robot;
    scene->addPolygon(robot.robot_to_world.map(QPolygonF(QRectF(-robot.length_back, -robot.width / 2.0, robot.length_back + robot.length_front, robot.width))));
    scene->addPolygon(robot.robot_to_world.map(QPolygonF(QRectF(0, -2, robot.length_front + 20, 4))));
    scene->addPolygon(robot.robot_to_world.map(QPolygonF(QRectF(-10, robot.wheel_dist / 2.0 - 2, 20, 4))));
    scene->addPolygon(robot.robot_to_world.map(QPolygonF(QRectF(-10, -robot.wheel_dist / 2.0 - 2, 20, 4))));
}
