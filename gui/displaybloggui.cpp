#include "displaybloggui.h"
#include "ui_displaybloggui.h"

DisplayBlogGUI::DisplayBlogGUI(Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayBlogGUI)
{
    ui->setupUi(this);
    scrapbookGUI = input;
    scrapbook = inputScrapbook;
    refreshBlogs();
}

DisplayBlogGUI::~DisplayBlogGUI()
{
    delete ui;
}

void DisplayBlogGUI::on_createBlog_clicked()
{
    scrapbookGUI->switchBlogViews();
}

void DisplayBlogGUI::on_refreshBlogs_clicked()
{
    refreshBlogs();
}

void DisplayBlogGUI::on_viewBlogButton_clicked()
{
    QList<QListWidgetItem*> blogList = ui->listWidget->selectedItems();
    int blogID = blogList[0]->data(5).toInt();
    ViewBlogGUI* viewBlogGUI = new ViewBlogGUI(scrapbookGUI->getAccountController(), scrapbook, blogID);
    viewBlogGUI->show();
}

void DisplayBlogGUI::refreshBlogs()
{

    std::vector<Blog*> allBlogs = scrapbook->getAllBlogs();

    ui->listWidget->clear();

    for(unsigned int i = 0; i < allBlogs.size(); i++){

        Blog *currentBlog = allBlogs.at(i);
        QString currentTitle = currentBlog->getTitle();
        QString currentContent = currentBlog->getContent();

        QString num = QString::number(i+1);
        QString content =
                "Blog # " + num + ":" + "\n" +
                "Title:    " + currentTitle + "\n" +
                "Content:    " + currentContent + "\n";
        QListWidgetItem* listItem = new QListWidgetItem(content);
        listItem->setData(5, currentBlog->getID());
        ui->listWidget->addItem(listItem);
    }
}




