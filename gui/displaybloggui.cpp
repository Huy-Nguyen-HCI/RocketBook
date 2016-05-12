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
    ui->viewBlogButton->hide();
    ui->refreshBlogs->hide();
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(listWidgetItem_clicked()));
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
    // get the blog to display
    QList<QListWidgetItem*> blogList = ui->listWidget->selectedItems();
    int blogID = blogList[0]->data(5).toInt();
    Blog* blog = scrapbook->getBlog(blogID);

    // create a new view to display blog
    ViewBlogGUI* viewBlogGUI = new ViewBlogGUI(scrapbookGUI->getAccountController(), blog);
    viewBlogGUI->show();
    /// TODO: delete viewBlogGUI;
}

void DisplayBlogGUI::refreshBlogs()
{
    // get the list of all blogs
    std::vector<Blog*> allBlogs = scrapbook->getAllBlogs();

    // clear the current view
    ui->listWidget->clear();

    // add all the blogs to the view again
    for(unsigned int i = 0; i < allBlogs.size(); i++){
        Blog *currentBlog = allBlogs.at(i);
        QString content = scrapbookGUI->printPost(currentBlog);
        QListWidgetItem* listItem = new QListWidgetItem(content);
        listItem->setData(5, currentBlog->getID());
        ui->listWidget->addItem(listItem);
    }
}

void DisplayBlogGUI::listWidgetItem_clicked() {
    ui->viewBlogButton->show();
}


