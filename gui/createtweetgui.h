#ifndef CREATETWEETGUI_H
#define CREATETWEETGUI_H

#include <QWidget>
#include "scrapbookgui.h"
#include "../model/accountcontroller.h"

class ScrapbookGUI;

namespace Ui {
class CreateTweetGUI;
}

class CreateTweetGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateTweetGUI(AccountController *inputAccountController, ScrapbookGUI *input, QWidget *parent = 0);
    ~CreateTweetGUI();

private slots:
    void on_returnButton_clicked();

    void on_publishButton_clicked();

private:
    Ui::CreateTweetGUI *ui;
    ScrapbookGUI *scrapbook;
    AccountController *accountController;
};

#endif // CREATETWEETGUI_H
