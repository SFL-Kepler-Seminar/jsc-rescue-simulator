#include <iostream>
#include <QApplication>

#include "PlaygroundView.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    PlaygroundView* pv = new PlaygroundView(nullptr);
    pv->show();
    app.exec();
    return 0;
}
