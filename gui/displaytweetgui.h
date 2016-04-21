#ifndef DISPLAYTWEETGUI_H
#define DISPLAYTWEETGUI_H

#include <QWidget>
#include "scrapbookgui.h"
#include "../model/accountcontroller.h"

class ScrapbookGUI;

namespace Ui {
class DisplayTweetGUI;
}

class DisplayTweetGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayTweetGUI(AccountController *inputAccountController, ScrapbookGUI *input, QWidget *parent = 0);
    ~DisplayTweetGUI();
    void refreshTweets();

private slots:
    void on_createTweet_clicked();

    void on_refreshMyTweets_clicked();

private:
    Ui::DisplayTweetGUI *ui;
    ScrapbookGUI *scrapbook;
    AccountController *accountController;
};

#endif // DISPLAYTWEETGUI_H
