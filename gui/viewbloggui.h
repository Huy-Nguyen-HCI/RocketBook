#ifndef VIEWBLOGGUI_H
#define VIEWBLOGGUI_H

#include <QDialog>
#include "../model/accountcontroller.h"
#include <QTableWidget>
#include <QAbstractButton>

namespace Ui {
class ViewBlogGUI;
}

class ViewBlogGUI : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief ViewBlogGUI
     * Construct a dialog to view a blog and comment on it.
     * @param accountController The account controller of the current user
     * @param blog The blog that is opened, not necessarily belonging to the current user
     * @param parent The parent widget
     */
    explicit ViewBlogGUI(AccountController *accountController, Blog* blog,
                         QWidget *parent = 0);
    ~ViewBlogGUI();

private slots:
//    void on_buttonBox_accepted();

//    void on_buttonBox_rejected();

    void on_buttonBox_clicked(QAbstractButton *button);

//    void on_buttonBox_accepted();


private:
    Ui::ViewBlogGUI *ui;
    Blog* blog;
    AccountController* accountController;

    /**
     * @brief refreshBlog
     * Refresh the current blog
     */
    void refreshBlog();

    /**
     * @brief refreshComments
     * Reload all the comments on the blog
     */
    void refreshComments();
};

#endif // VIEWBLOGGUI_H
