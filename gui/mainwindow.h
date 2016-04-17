#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include "logingui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setUsername(QString input) { username = input; }
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString username;
};

#endif // MAINWINDOW_H
