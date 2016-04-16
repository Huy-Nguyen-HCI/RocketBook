#include "createtweetgui.h"
#include "ui_createtweetgui.h"

CreateTweetGUI::CreateTweetGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateTweetGUI)
{
    ui->setupUi(this);
}

CreateTweetGUI::~CreateTweetGUI()
{
    delete ui;
}
