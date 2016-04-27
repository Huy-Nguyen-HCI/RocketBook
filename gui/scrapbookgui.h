#ifndef SCRAPBOOKGUI_H
#define SCRAPBOOKGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"
#include "createbloggui.h"
#include "createmultimediagui.h"
#include "createtweetgui.h"
#include "displaybloggui.h"
#include "displaymultimediagui.h"
#include "displaytweetgui.h"


class CreateTweetGUI;
class DisplayTweetGUI;
class CreateBlogGUI;
class DisplayBlogGUI;
class CreateMultimediaGUI;
class DisplayMultimediaGUI;

namespace Ui {
class ScrapbookGUI;
}

class ScrapbookGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ScrapbookGUI(AccountController *inputAccountController,
                          QWidget *parent = 0);

    explicit ScrapbookGUI(AccountController *inputAccountController,
                          Scrapbook* displayScrapbook,
                          QWidget *parent = 0);
    ~ScrapbookGUI();
    void switchTweetViews();
    void switchBlogViews();
    void switchMultimediaViews();
    void refreshBook();
    void displayBlog(Blog* blog);
    void displayTweet(Tweet* tweet);
    void displayMultimedia(Multimedia* multimedia);
    AccountController* getAccountController() { return accountController;}

private slots:
    void on_editButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::ScrapbookGUI *ui;
    CreateBlogGUI *createBlogView;
    CreateMultimediaGUI *createMultimediaView;
    CreateTweetGUI *createTweetView;
    DisplayBlogGUI *displayBlogView;
    DisplayMultimediaGUI *displayMultimediaView;
    DisplayTweetGUI *displayTweetView;
    AccountController *accountController;
    Scrapbook* scrapbook;
};

#endif // SCRAPBOOKGUI_H
