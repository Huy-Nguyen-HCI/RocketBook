#ifndef CREATEBLOGGUI_H
#define CREATEBLOGGUI_H

#include <QWidget>
#include "scrapbookgui.h"
#include "../model/blog.h"
#include "../model/accountcontroller.h"

class ScrapbookGUI;

namespace Ui {
class CreateBlogGUI;
}

class CreateBlogGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateBlogGUI(AccountController *inputAccountController, ScrapbookGUI *input, QWidget *parent = 0);
    ~CreateBlogGUI();

private slots:
    void on_returnButton_clicked();

    void on_publishButton_clicked();

private:
    Ui::CreateBlogGUI *ui;
    ScrapbookGUI *scrapbook;
    AccountController *accountController;
};

#endif // CREATEBLOGGUI_H
