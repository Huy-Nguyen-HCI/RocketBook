#include "createbloggui.h"
#include "ui_createbloggui.h"

CreateBlogGUI::CreateBlogGUI(ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateBlogGUI)
{
    ui->setupUi(this);
    scrapbook = input;
}

CreateBlogGUI::~CreateBlogGUI()
{
    delete ui;
}

void CreateBlogGUI::on_returnButton_clicked()
{
    scrapbook->switchBlogViews();
}
