#include "ui/MainWindow.h"

MainWindow::MainWindow(int width, int height, const QString& title) {
    resize(width, height);
    setWindowTitle(title);
}