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

    // check valid character count
    if (content.isEmpty() || content.length() > 140) {
        ui->message->setText("Error: Tweet must be between 0 and 140 characters!");
        return;
    }

    // get user input
    QString username = accountController->getUser()->getUsername();
    bool privacy = ui->privateCheckbox->isChecked();

    // add new tweet to the database
    scrapbook->addTweet(username, content, privacy);

    // segue to main view
    scrapbookGUI->switchTweetViews();

}

void CreateTweetGUI::clearViews() {
    ui->contentBox->clear();
    ui->message->clear();
    ui->privateCheckbox->setChecked(false);
}
