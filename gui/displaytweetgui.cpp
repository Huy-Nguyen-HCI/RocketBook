#include "displaytweetgui.h"
#include "ui_displaytweetgui.h"

DisplayTweetGUI::DisplayTweetGUI(ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayTweetGUI)
{
    ui->setupUi(this);
    scrapbook = input;
}

DisplayTweetGUI::~DisplayTweetGUI()
{
    delete ui;
}

void DisplayTweetGUI::on_createTweet_clicked()
{
    // switch to create tweet view
    scrapbook->switchTweetViews();
}
