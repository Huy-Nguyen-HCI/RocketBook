#include "messagegui.h"
#include "ui_messagegui.h"

MessageGUI::MessageGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageGUI)
{
    ui->setupUi(this);
}

MessageGUI::~MessageGUI()
{
    delete ui;
}
