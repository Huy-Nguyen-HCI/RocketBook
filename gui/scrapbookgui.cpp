#include "scrapbookgui.h"
#include "ui_scrapbookgui.h"

ScrapbookGUI::ScrapbookGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrapbookGUI)
{
    ui->setupUi(this);
    accountController = inputAccountController;

    createBlogView = new CreateBlogGUI(accountController, this);
    displayBlogView = new DisplayBlogGUI(accountController, this);
    createTweetView = new CreateTweetGUI(accountController, this);
    displayTweetView = new DisplayTweetGUI(accountController, this);
    createMultimediaView = new CreateMultimediaGUI(accountController, this);
    displayMultimediaView = new DisplayMultimediaGUI(accountController, this);

    // add display and edit view for blog
    ui->blogStackedWidget->addWidget(displayBlogView);
    ui->blogStackedWidget->addWidget(createBlogView);

    // add display and edit view for tweet
    ui->tweetStackedWidget->addWidget(displayTweetView);
    ui->tweetStackedWidget->addWidget(createTweetView);

    // add display and edit view for multimedia
    ui->multimediaStackedWidget->addWidget(displayMultimediaView);
    ui->multimediaStackedWidget->addWidget(createMultimediaView);

    // show display view as default
    ui->blogStackedWidget->setCurrentWidget(displayBlogView);
    ui->tweetStackedWidget->setCurrentWidget(displayTweetView);
    ui->multimediaStackedWidget->setCurrentWidget(displayMultimediaView);

}

ScrapbookGUI::~ScrapbookGUI()
{
    delete ui;
}

void ScrapbookGUI::switchTweetViews() {
    if (ui->tweetStackedWidget->currentWidget() == displayTweetView)
        ui->tweetStackedWidget->setCurrentWidget(createTweetView);
    else
        //displayTweetView->refreshTweets();
        ui->tweetStackedWidget->setCurrentWidget(displayTweetView);
        displayTweetView->refreshTweets();
}

void ScrapbookGUI::switchBlogViews() {
    if (ui->blogStackedWidget->currentWidget() == displayBlogView){
        ui->blogStackedWidget->setCurrentWidget(createBlogView);
    }
    else {
        displayBlogView->refreshBlogs();
        ui->blogStackedWidget->setCurrentWidget(displayBlogView);
    }
}


void ScrapbookGUI::switchMultimediaViews() {
    if (ui->multimediaStackedWidget->currentWidget() == displayMultimediaView){
        ui->multimediaStackedWidget->setCurrentWidget(createMultimediaView);
    }
    else {
        displayMultimediaView->refreshMultimedia();
        ui->multimediaStackedWidget->setCurrentWidget(displayMultimediaView);
    }
}

