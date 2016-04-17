#include "mainwindow.h"
#include <QApplication>
#include "logingui.h"

/**
    IMAGE SOURCES:
    rocket.png:         https://thenounproject.com/term/rocket/1758/
    message.png:        http://icons.iconarchive.com/icons/osullivanluke/orb-os-x/512/Messages-icon.png
    post.png:           https://cdn1.iconfinder.com/data/icons/social-media-3/512/615556-Pencil_Document-512.png
    group.png:          http://icons.iconarchive.com/icons/hopstarter/sleek-xp-basic/256/User-Group-icon.png
    logout.png:         https://cdn1.iconfinder.com/data/icons/web-ui/30/power-01-128.png
    feed.png:           https://icons8.com/
    scrapbook.png:      https://icons8.com/
    friends.png:        https://icons8.com/
    notification.png:   https://icons8.com/
    user.png:           https://icons8.com/
    settings.png:       https://icons8.com/
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
