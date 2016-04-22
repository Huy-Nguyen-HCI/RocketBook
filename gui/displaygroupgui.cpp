#include "displaygroupgui.h"
#include "ui_displaygroupgui.h"

DisplayGroupGUI::DisplayGroupGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayGroupGUI)
{
    ui->setupUi(this);
}

DisplayGroupGUI::~DisplayGroupGUI()
{
    delete ui;
}
