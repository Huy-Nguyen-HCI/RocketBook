#include "createbloggui.h"
#include "ui_createbloggui.h"

CreateBlogGUI::CreateBlogGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateBlogGUI)
{
    ui->setupUi(this);
}

CreateBlogGUI::~CreateBlogGUI()
{
    delete ui;
}
