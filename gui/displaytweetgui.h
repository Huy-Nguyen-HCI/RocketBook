#ifndef DISPLAYTWEETGUI_H
#define DISPLAYTWEETGUI_H

#include <QWidget>
#include "scrapbookgui.h"
#include "../model/scrapbook.h"

class ScrapbookGUI;

namespace Ui {
class DisplayTweetGUI;
}

class DisplayTweetGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayTweetGUI(Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent = 0);
    ~DisplayTweetGUI();
    void refreshTweets();

private slots:
    void on_createTweet_clicked();

    void on_refreshMyTweets_clicked();

private:
    Ui::DisplayTweetGUI *ui;
    ScrapbookGUI *scrapbookGUI;
    Scrapbook *scrapbook;
};

#endif // DISPLAYTWEETGUI_H
