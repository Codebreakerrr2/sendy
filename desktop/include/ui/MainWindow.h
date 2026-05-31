#pragma once

#include <QMainWindow>
#include <QString>

class MainWindow : public QMainWindow {
public:
    MainWindow(int width, int height, const QString& title);
};