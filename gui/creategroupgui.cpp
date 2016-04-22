#include "creategroupgui.h"
#include "ui_creategroupgui.h"

CreateGroupGUI::CreateGroupGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateGroupGUI)
{
    ui->setupUi(this);
}

CreateGroupGUI::~CreateGroupGUI()
{
    delete ui;
}
