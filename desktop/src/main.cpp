#include <QApplication>
#include "ui/MainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MainWindow window(900, 600, "Sendy");
    window.show();

    return app.exec();
}