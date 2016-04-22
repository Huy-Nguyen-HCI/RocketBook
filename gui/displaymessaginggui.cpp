#include "displaymessaginggui.h"
#include "ui_displaymessaginggui.h"

displayMessagingGUI::displayMessagingGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displayMessagingGUI)
{
    ui->setupUi(this);
}

displayMessagingGUI::~displayMessagingGUI()
{
    delete ui;
}
