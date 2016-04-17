#include "scrapbookgui.h"
#include "ui_scrapbookgui.h"

ScrapbookGUI::ScrapbookGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrapbookGUI)
{
    ui->setupUi(this);

    createBlogView = new CreateBlogGUI(this);
    displayBlogView = new DisplayBlogGUI(this);
    createTweetView = new CreateTweetGUI(this);
    displayTweetView = new DisplayTweetGUI(this);
    createMultimediaView = new CreateMultimediaGUI(this);
    displayMultimediaView = new DisplayMultimediaGUI(this);

    // add display and edit view for blog
    ui->blogStackedWidget->addWidget(displayBlogView);
    ui->blogStackedWidget->addWidget(createBlogView);

    // add display and edit view for tweet
    ui->tweetStackedWidget->addWidget(displayTweetView);
    ui->tweetStackedWidget->addWidget(createTweetView);

    // add display and edit view for
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
        ui->tweetStackedWidget->setCurrentWidget(displayTweetView);
}

void ScrapbookGUI::switchBlogViews() {
    if (ui->blogStackedWidget->currentWidget() == displayBlogView)
        ui->blogStackedWidget->setCurrentWidget(createBlogView);
    else
        ui->blogStackedWidget->setCurrentWidget(displayBlogView);
}

void ScrapbookGUI::switchMultimediaViews() {
    if (ui->multimediaStackedWidget->currentWidget() == displayMultimediaView)
        ui->multimediaStackedWidget->setCurrentWidget(createMultimediaView);
    else
        ui->multimediaStackedWidget->setCurrentWidget(displayMultimediaView);
}
