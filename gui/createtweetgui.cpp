#include "createtweetgui.h"
#include "ui_createtweetgui.h"

CreateTweetGUI::CreateTweetGUI(AccountController* currentAccount,
                               Scrapbook *inputScrapbook,
                               ScrapbookGUI *input,
                               QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateTweetGUI)
{
    ui->setupUi(this);
    scrapbookGUI = input;
    accountController = currentAccount;
    scrapbook = inputScrapbook;

}

CreateTweetGUI::~CreateTweetGUI()
{
    delete ui;
}

void CreateTweetGUI::on_returnButton_clicked()
{
    // switch to display tweet view
    scrapbookGUI->switchTweetViews();
}

void CreateTweetGUI::on_publishButton_clicked()
{
    QString content = ui->contentBox->toPlainText();
    QString username = accountController->getUser()->getUsername();


    bool privacy = ui->privateCheckbox->isChecked();
    scrapbook->addTweet(username, content, privacy);

    scrapbookGUI->switchTweetViews();

}

void CreateTweetGUI::clearViews() {

    ui->contentBox->clear();
    ui->privateCheckbox->setChecked(false);
}
