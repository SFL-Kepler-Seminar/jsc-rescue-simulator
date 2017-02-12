#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>

#include "simulation.h"

class PlaygroundView : public QGraphicsView {
public:
    PlaygroundView(QWidget* parent);
    void draw(const Playground& playground);
private:
    QGraphicsScene* scene;
};
