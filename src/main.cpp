#include <iostream>
#include <QApplication>

int main(int argc, char** argv) {
    std::cout << "Hello World" << std::endl;
    QApplication app(argc, argv);
    app.exec();
    return 0;
}
