#include "mainwindow.h"
#include <QApplication>
#include "logingui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    AccountDB *accountDB = new AccountDB("../database/rocketDB.sqlite");
    LoginGUI w(accountDB);
    w.show();

    return a.exec();
}
