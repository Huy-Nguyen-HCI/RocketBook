#include "displaytweetgui.h"
#include "ui_displaytweetgui.h"

DisplayTweetGUI::DisplayTweetGUI(AccountController *inputAccountController, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayTweetGUI)
{
    ui->setupUi(this);
    scrapbook = input;
    accountController = inputAccountController;
}

DisplayTweetGUI::~DisplayTweetGUI()
{
    delete ui;
}

void DisplayTweetGUI::on_createTweet_clicked()
{
    // switch to create tweet view
    refreshTweets();
    scrapbook->switchTweetViews();
}

void DisplayTweetGUI::refreshTweets()
{
    Profile *currentProfile = accountController->getUser()->getProfile();
    Scrapbook *myScrapbook = currentProfile->getScrapbook();
    std::vector<Tweet*> allTweets = myScrapbook->getAllTweets();

    ui->listWidget->clear();

    for(int i = 0; i < allTweets.size(); i++){

        Tweet *currentTweet = allTweets.at(i);
        QString currentContent = currentTweet->getContent();
        QString num = QString::number(i+1);
        QString content =
                "Tweet # " + num + ":" + "\n" +
                currentContent + "\n";
        ui->listWidget->addItem(content);
    }
}

void DisplayTweetGUI::on_refreshMyTweets_clicked()
{
    refreshTweets();
}
