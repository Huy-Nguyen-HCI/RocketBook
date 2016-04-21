#include "createtweetgui.h"
#include "ui_createtweetgui.h"

CreateTweetGUI::CreateTweetGUI(AccountController *inputAccountController, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateTweetGUI)
{
    ui->setupUi(this);
    scrapbook = input;
    accountController = inputAccountController;
}

CreateTweetGUI::~CreateTweetGUI()
{
    delete ui;
}

void CreateTweetGUI::on_returnButton_clicked()
{
    // switch to display tweet view
    scrapbook->switchTweetViews();
}

void CreateTweetGUI::on_publishButton_clicked()
{
    QString newContent = ui->contentBox->toPlainText();
    QString userName = accountController->getUser()->getUsername();

    Profile *currentProfile = accountController->getUser()->getProfile();
    Scrapbook *myScrapbook = currentProfile->getScrapbook();

    Tweet *newTweet = new Tweet(userName, newContent);

    myScrapbook->addTweet(newTweet);

    scrapbook->switchTweetViews();

}
