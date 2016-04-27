#include "viewbloggui.h"
#include "ui_viewbloggui.h"

ViewBlogGUI::ViewBlogGUI(AccountController *accountController,
                         Scrapbook* scrapbook,
                         int blogID,
                         QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewBlogGUI)
{
    ui->setupUi(this);
    this->accountController = accountController;
    this->scrapbook = scrapbook;
    this->blog = scrapbook->getBlog(blogID);

    ui->commentTable->setColumnCount(2);
    ui->commentTable->horizontalHeader()->hide();
    ui->commentTable->verticalHeader()->hide();
    ui->commentTable->setShowGrid(false);
//    ui->commentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->commentTable->setSelectionMode(QAbstractItemView::NoSelection);

    refreshBlog();

}

ViewBlogGUI::~ViewBlogGUI()
{
    delete ui;
}



void ViewBlogGUI::on_buttonBox_accepted()
{
    QString newComment = ui->commentEdit->document()->toPlainText();
    scrapbook->addComment(blog->getID(), accountController->getUser()->getUsername(), newComment);
    refreshBlog();
}

void ViewBlogGUI::on_buttonBox_rejected()
{
    this->close();
}

void ViewBlogGUI::refreshBlog() {
    QString title = blog->getTitle();
    QString author = blog->getAuthorUsername();
    QString content = blog->getContent();

    ui->blogTitleLabel->setText(title);
    ui->authorLabel->setText("by " + author);
    ui->contentBrowser->setText(content);

    refreshComments();
}

void ViewBlogGUI::refreshComments() {
    ui->commentTable->clear();
    ui->commentEdit->clear();

    std::vector<Comment*> commentList = blog->getAllComments();


    ui->commentTable->setRowCount(commentList.size());

    //display admin list
    for (unsigned int row = 0; row < commentList.size(); row++) {
        QTableWidgetItem* username = new QTableWidgetItem(commentList[row]->getAuthorUsername());
        QTableWidgetItem* comment = new QTableWidgetItem(commentList[row]->getContent());
        ui->commentTable->setItem(row, 0, username);
        ui->commentTable->setItem(row, 1, comment);
    }
}
