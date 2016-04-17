#ifndef DISPLAYTWEETGUI_H
#define DISPLAYTWEETGUI_H

#include <QWidget>
#include "scrapbookgui.h"

class ScrapbookGUI;

namespace Ui {
class DisplayTweetGUI;
}

class DisplayTweetGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayTweetGUI(ScrapbookGUI *input, QWidget *parent = 0);
    ~DisplayTweetGUI();

private slots:
    void on_createTweet_clicked();

private:
    Ui::DisplayTweetGUI *ui;
    ScrapbookGUI *scrapbook;
};

#endif // DISPLAYTWEETGUI_H
