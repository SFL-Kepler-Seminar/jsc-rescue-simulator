#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>

class PlaygroundView : public QGraphicsView {
public:
    PlaygroundView(QWidget* parent);
private:
    QGraphicsScene* scene;
};
