#ifndef CREATETWEETGUI_H
#define CREATETWEETGUI_H

#include <QWidget>
#include "scrapbookgui.h"
#include "../model/scrapbook.h"

class ScrapbookGUI;

namespace Ui {
class CreateTweetGUI;
}

/**
 * @brief The CreateTweetGUI class
 *
 * Allows the user to create a tweet.
 */
class CreateTweetGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CreateTweetGUI the class constructor.
     * @param currentAccount pointer to the account controller that contains information about the user.
     * @param inputScrapbook the corresponding scrapbook
     * @param input the corresponding scrapbook GUI.
     * @param parent the QWidget parent class.
     */
    explicit CreateTweetGUI(AccountController* currentAccount,
                            Scrapbook *inputScrapbook,
                            ScrapbookGUI *input,
                            QWidget *parent = 0);
    /**
      * @brief the class destructor. Delete the pointer to ui.
      */
    ~CreateTweetGUI();

    /**
     * @brief clearViews clear all the input fields.
     */
    void clearViews();

private slots:
    /**
     * @brief on_returnButton_clicked segue to the main view.
     */
    void on_returnButton_clicked();

    /**
     * @brief on_publishButton_clicked add the tweet to the database and display it in the view.
     */
    void on_publishButton_clicked();

private:
    Ui::CreateTweetGUI *ui;
    ScrapbookGUI *scrapbookGUI;
    Scrapbook* scrapbook;
    AccountController *accountController;
};

#endif // CREATETWEETGUI_H
