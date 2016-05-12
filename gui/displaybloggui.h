#ifndef DISPLAYBLOGGUI_H
#define DISPLAYBLOGGUI_H

#include <QWidget>
#include <QTextBrowser>
#include "scrapbookgui.h"
#include "../model/scrapbook.h"
#include "viewbloggui.h"

class ScrapbookGUI;

namespace Ui {
class DisplayBlogGUI;
}

/**
 * @brief The DisplayBlogGUI class displays all the blogs posted by the user.
 */
class DisplayBlogGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief DisplayBlogGUI the class constructor.
     * @param inputScrapbook a pointer to the scrapbook which contains all the blogs.
     * @param input the pointer to the corresponding scrapbook GUI.
     * @param parent the parent QListWidget.
     */
    explicit DisplayBlogGUI(Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent = 0);

    /**
      * @brief ~DisplayBlogGUI the class destructor. Delete the pointer to ui.
      */
    ~DisplayBlogGUI();

    /**
     * @brief refreshBlogs laod and display all the blogs again.
     */
    void refreshBlogs();

private slots:
    /**
     * @brief on_createBlog_clicked segue to the create blog view.
     */

    void on_createBlog_clicked();
    /**
     * @brief on_refreshBlogs_clicked refresh all the blogs.
     */

    void on_refreshBlogs_clicked();
    /**
     * @brief on_viewBlogButton_clicked segue to the view blog view.
     */
    void on_viewBlogButton_clicked();

    void listWidgetItem_clicked();

private:
    Ui::DisplayBlogGUI *ui;
    ScrapbookGUI *scrapbookGUI;
    Scrapbook *scrapbook;
};

#endif // DISPLAYBLOGGUI_H
