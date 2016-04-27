#ifndef CREATEBLOGGUI_H
#define CREATEBLOGGUI_H

#include <QWidget>
#include "scrapbookgui.h"
#include "../model/scrapbook.h"

class ScrapbookGUI;

namespace Ui {
class CreateBlogGUI;
}

class CreateBlogGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateBlogGUI(AccountController* currentAccount, Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent = 0);
    ~CreateBlogGUI();

private slots:
    void on_returnButton_clicked();

    void on_publishButton_clicked();

private:
    Ui::CreateBlogGUI *ui;
    ScrapbookGUI *scrapbookGUI;
    Scrapbook *scrapbook;
    AccountController* accountController;
};

#endif // CREATEBLOGGUI_H
