#include "bloggui.h"
#include "ui_bloggui.h"

BlogGUI::BlogGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlogGUI)
{
    ui->setupUi(this);
}

BlogGUI::~BlogGUI()
{
    delete ui;
}
