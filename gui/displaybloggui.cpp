#include "displaybloggui.h"
#include "ui_displaybloggui.h"

DisplayBlogGUI::DisplayBlogGUI(ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayBlogGUI)
{
    ui->setupUi(this);
    scrapbook = input;
}

DisplayBlogGUI::~DisplayBlogGUI()
{
    delete ui;
}

void DisplayBlogGUI::on_createBlog_clicked()
{
    scrapbook->switchBlogViews();
}
