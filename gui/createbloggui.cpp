#include "createbloggui.h"
#include "ui_createbloggui.h"


CreateBlogGUI::CreateBlogGUI(AccountController* currentAccount, Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateBlogGUI)
{
    ui->setupUi(this);
    accountController = currentAccount;
    scrapbookGUI = input;
    scrapbook = inputScrapbook;
}

CreateBlogGUI::~CreateBlogGUI()
{
    delete ui;
}

void CreateBlogGUI::on_returnButton_clicked()
{
    scrapbookGUI->switchBlogViews();
}

void CreateBlogGUI::on_publishButton_clicked()
{
    // get information from user
    QString username = accountController->getUser()->getUsername();
    QString newTitle = ui->lineEdit->text();
    QString newContent = ui->textEdit->toPlainText();
    bool privacy = ui->privateCheckbox->isChecked();

    // update the model and database
    scrapbook->addBlog(username, newTitle, newContent, privacy);
    scrapbookGUI->switchBlogViews();

}

void CreateBlogGUI::clearFields() {
    ui->lineEdit->clear();
    ui->textEdit->clear();
    ui->privateCheckbox->setChecked(false);
}
