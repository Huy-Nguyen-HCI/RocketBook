#ifndef DISPLAYBLOGGUI_H
#define DISPLAYBLOGGUI_H

#include <QWidget>
#include <QTextBrowser>
#include "scrapbookgui.h"
#include "../model/accountcontroller.h"

class ScrapbookGUI;

namespace Ui {
class DisplayBlogGUI;
}

class DisplayBlogGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayBlogGUI(AccountController *inputAccountController, ScrapbookGUI *input, QWidget *parent = 0);
    ~DisplayBlogGUI();
    void refreshBlogs();

private slots:
    void on_createBlog_clicked();

    void on_refreshBlogs_clicked();

private:
    Ui::DisplayBlogGUI *ui;
    ScrapbookGUI *scrapbook;
    AccountController *accountController;
};

#endif // DISPLAYBLOGGUI_H
