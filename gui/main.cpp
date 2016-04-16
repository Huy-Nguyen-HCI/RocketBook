#include "mainwindow.h"
#include <QApplication>
#include "logingui.h"

/**
    IMAGE SOURCES:
    rocket.png: https://thenounproject.com/term/rocket/1758/

  */


/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    AccountController *acc = new AccountController();
    LoginGUI *loginView = new LoginGUI(acc);

    MainWindow w;
    w.setLoginView(loginView);
    w.show();

    return a.exec();
}
