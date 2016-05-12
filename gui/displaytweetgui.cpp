#include "displaytweetgui.h"
#include "ui_displaytweetgui.h"

DisplayTweetGUI::DisplayTweetGUI(Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayTweetGUI)
{
    ui->setupUi(this);
    scrapbookGUI = input;
    scrapbook = inputScrapbook;
    ui->refreshMyTweets->hide();
    refreshTweets();
}

DisplayTweetGUI::~DisplayTweetGUI()
{
    delete ui;
}

void DisplayTweetGUI::on_createTweet_clicked()
{
    // switch to create tweet view
    refreshTweets();
    scrapbookGUI->switchTweetViews();
}

void DisplayTweetGUI::refreshTweets()
{
    // get all the tweets
    std::vector<Tweet*> allTweets = scrapbook->getAllTweets();

    // clear the views
    ui->listWidget->clear();

    // add all the tweets to the view again
    for(unsigned int i = 0; i < allTweets.size(); i++){

        Tweet *currentTweet = allTweets.at(i);
        QString content = scrapbookGUI->printPost(currentTweet);
        ui->listWidget->addItem(content);
    }
}

void DisplayTweetGUI::on_refreshMyTweets_clicked()
{
    refreshTweets();
}
