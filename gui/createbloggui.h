#ifndef CREATEBLOGGUI_H
#define CREATEBLOGGUI_H

#include <QWidget>
#include "scrapbookgui.h"
#include "../model/scrapbook.h"

class ScrapbookGUI;

namespace Ui {
class CreateBlogGUI;
}

/**
 * @brief The CreateBlogGUI class is a controller to help user input details about a new blog and post it.
 */
class CreateBlogGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CreateBlogGUI default constructor
     * @param currentAccount the current account handling the writing
     * @param inputScrapbook the scrapbook for the blog to be stored
     * @param input the scrapbookGUI that is linked to this GUI
     * @param parent the parent class of CreateBlogGUI
     */
    explicit CreateBlogGUI(AccountController* currentAccount, Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent = 0);

    ~CreateBlogGUI();

    /**
     * @brief clearViews
     * Clear all the current fields
     */
    void clearFields();

private slots:
    /**
     * @brief on_returnButton_clicked
     * Go back to previous window
     */
    void on_returnButton_clicked();

    /**
     * @brief on_publishButton_clicked
     * Publish a new blog
     */
    void on_publishButton_clicked();

private:
    Ui::CreateBlogGUI *ui;
    ScrapbookGUI *scrapbookGUI;
    Scrapbook *scrapbook;
    AccountController* accountController;
};

#endif // CREATEBLOGGUI_H
