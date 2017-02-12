#include <iostream>
#include <QApplication>
#include <QTimer>
#include <chrono>

#include "PlaygroundView.h"
#include "simulation.h"

class Main : public QObject {
    Q_OBJECT
public:
    Playground pl;
    PlaygroundView* pv;
    void main() {
        pv = new PlaygroundView(nullptr);
        pl.line_segemnts.push_back(LineSegment(QRectF(-10, -10, 20, 20)));
        pl.robot = new SimulatedRobot();
        pl.robot->motor_l = new SimulatedMotor();
        pl.robot->motor_r = new SimulatedMotor();
        pl.robot->motor_l->drive(20);
        pl.robot->motor_r->drive(10);

        QTimer* timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(tickSim()));
        timer->start(10);

        pv->show();
    }
private slots:
    void tickSim() {
        pl.tick(&pl, 0.01);
        pv->draw(pl);
    }
};
#include "main.moc"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    Main main;
    main.main();
    app.exec();
    return 0;
}
