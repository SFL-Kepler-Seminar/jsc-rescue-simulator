#include "PlaygroundView.h"

PlaygroundView::PlaygroundView(QWidget* parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);

    scene->addRect(0, 0, 10, 10);
}
