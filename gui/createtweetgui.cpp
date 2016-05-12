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
    // get user input
    QString content = ui->contentBox->toPlainText();
    QString username = accountController->getUser()->getUsername();
    bool privacy = ui->privateCheckbox->isChecked();

    // add new tweet to the database
    scrapbook->addTweet(username, content, privacy);

    // segue to main view
    scrapbookGUI->switchTweetViews();

}

void CreateTweetGUI::clearViews() {
    ui->contentBox->clear();
    ui->privateCheckbox->setChecked(false);
}
