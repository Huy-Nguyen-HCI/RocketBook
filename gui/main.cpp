#include "mainwindow.h"
#include <QApplication>
#include "logingui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    AccountController *acc = new AccountController();
    LoginGUI w(acc);
    w.show();

    return a.exec();
}
