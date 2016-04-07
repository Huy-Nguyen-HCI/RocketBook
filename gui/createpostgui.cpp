#include "createpostgui.h"
#include "ui_createpostgui.h"

CreatePostGUI::CreatePostGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreatePostGUI)
{
    ui->setupUi(this);
}

CreatePostGUI::~CreatePostGUI()
{
    delete ui;
}
