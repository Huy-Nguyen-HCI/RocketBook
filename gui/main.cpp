#include "mainwindow.h"
#include <QApplication>
#include "logingui.h"
#include "createaccountgui.h"


/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);


    while (!LoginGUI::isFinished()) {
        QString dbPath = AccountController::PATH + "rocketDB.sqlite";
        QDir dir(dbPath);
        //qDebug() << "dbPath is: " << dir.absolutePath() ;

        AccountController* acc = new AccountController(dbPath);
        LoginGUI* loginView = new LoginGUI(acc);
        CreateAccountGUI* createAccountView = new CreateAccountGUI(acc);
        MainWindow* main = new MainWindow(acc);

        // set up connections
        loginView->setMainWindow(main);
        loginView->setCreateAccountView(createAccountView);
        createAccountView->setLoginView(loginView);
        createAccountView->setMainWindow(main);

        loginView->show();

        a.exec();

        delete acc;
        delete main;
        delete loginView;
        delete createAccountView;
    }


    return 0;
}
