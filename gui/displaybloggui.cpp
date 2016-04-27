#include "displaybloggui.h"
#include "ui_displaybloggui.h"

DisplayBlogGUI::DisplayBlogGUI(Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayBlogGUI)
{
    ui->setupUi(this);
    scrapbookGUI = input;
    scrapbook = inputScrapbook;
}

DisplayBlogGUI::~DisplayBlogGUI()
{
    delete ui;
}

void DisplayBlogGUI::on_createBlog_clicked()
{
    refreshBlogs();
    scrapbookGUI->switchBlogViews();
}

void DisplayBlogGUI::on_refreshBlogs_clicked()
{
    refreshBlogs();
}

void DisplayBlogGUI::refreshBlogs()
{

    std::vector<Blog*> allBlogs = scrapbook->getAllBlogs();

    ui->listWidget->clear();

    for(int i = 0; i < allBlogs.size(); i++){

        Blog *curentBlog = allBlogs.at(i);
        QString currentTitle = curentBlog->getTitle();
        QString currentContent = curentBlog->getContent();

        QString num = QString::number(i+1);
        QString content =
                "Blog # " + num + ":" + "\n" +
                "Title:    " + currentTitle + "\n" +
                "Content:    " + currentContent + "\n";
        ui->listWidget->addItem(content);
    }
}


