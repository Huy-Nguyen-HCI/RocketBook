#include "displaytweetgui.h"
#include "ui_displaytweetgui.h"

DisplayTweetGUI::DisplayTweetGUI(Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayTweetGUI)
{
    ui->setupUi(this);
    scrapbookGUI = input;
    scrapbook = inputScrapbook;
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
    std::vector<Tweet*> allTweets = scrapbook->getAllTweets();

    ui->listWidget->clear();

    for(unsigned int i = 0; i < allTweets.size(); i++){

        Tweet *currentTweet = allTweets.at(i);
        QString currentContent = currentTweet->getContent();
        QString num = QString::number(allTweets.size() - i);
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
