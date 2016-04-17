#ifndef CREATETWEETGUI_H
#define CREATETWEETGUI_H

#include <QWidget>
#include "scrapbookgui.h"

class ScrapbookGUI;

namespace Ui {
class CreateTweetGUI;
}

class CreateTweetGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateTweetGUI(ScrapbookGUI *input, QWidget *parent = 0);
    ~CreateTweetGUI();

private slots:
    void on_returnButton_clicked();

    void on_publishButton_clicked();

private:
    Ui::CreateTweetGUI *ui;
    ScrapbookGUI *scrapbook;
};

#endif // CREATETWEETGUI_H
