#include "createtweetgui.h"
#include "ui_createtweetgui.h"

CreateTweetGUI::CreateTweetGUI(ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateTweetGUI)
{
    ui->setupUi(this);
    scrapbook = input;
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

}
