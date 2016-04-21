#include "createbloggui.h"
#include "ui_createbloggui.h"


CreateBlogGUI::CreateBlogGUI(AccountController *inputAccountController, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateBlogGUI)
{
    ui->setupUi(this);
    scrapbook = input;
    accountController = inputAccountController;
}

CreateBlogGUI::~CreateBlogGUI()
{
    delete ui;
}

void CreateBlogGUI::on_returnButton_clicked()
{
    scrapbook->refreshBlogs();
    scrapbook->switchBlogViews();
}

void CreateBlogGUI::on_publishButton_clicked()
{
    QString newTitle = ui->lineEdit->text();
    QString newContent = ui->textEdit->toPlainText();
    QString userName = accountController->getUser()->getUsername();

    Profile *currentProfile = accountController->getUser()->getProfile();
    Scrapbook *myScrapbook = currentProfile->getScrapbook();

    Blog *newBlog = new Blog(userName, newTitle, newContent);

    myScrapbook->addBlog(newBlog);

    scrapbook->refreshBlogs();
    scrapbook->switchBlogViews();

}
