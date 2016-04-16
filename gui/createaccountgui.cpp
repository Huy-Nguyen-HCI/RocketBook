#include "createaccountgui.h"
#include "ui_createaccountgui.h"

CreateAccountGUI::CreateAccountGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateAccountGUI)
{
    ui->setupUi(this);
}

CreateAccountGUI::~CreateAccountGUI()
{
    delete ui;
}
