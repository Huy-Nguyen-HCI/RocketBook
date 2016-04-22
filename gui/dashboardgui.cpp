#include "dashboardgui.h"
#include "ui_dashboardgui.h"

DashboardGUI::DashboardGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardGUI)
{
    ui->setupUi(this);
    this->accountController = inputAccountController;
}

DashboardGUI::~DashboardGUI()
{
    delete ui;
}

void DashboardGUI::on_latestScrapbookButton_clicked()
{
    ui->latestInfoListWidget->clear();
    ui->latestInfoListWidget->addItem(QString("Your latest posts: \n"));
    std::vector<Post*> latestScrapbook = accountController->getUser()->getProfile()->getScrapbook()->getLatestPosts(5);
    for (unsigned int i = 0; i < latestScrapbook.size(); i++) {
        Post* currentPost = latestScrapbook[i];
        Post::PostType pType = currentPost->type();
        switch (pType) {
            case Post::typeBlog:
                displayBlog((Blog*)currentPost);
                break;
            case Post::typeTweet:
                displayTweet((Tweet*)currentPost);
                break;
            case Post::typeMultimedia:
                displayMultimedia((Multimedia*)currentPost);
                break;
            case Post::typeComment:
                break;
            case Post::typePost:
                break;
        }
    }
}

void DashboardGUI::displayBlog(Blog* blog) {


    QString currentTitle = blog->getTitle();
    QString currentContent = blog->getContent();

    QString content =
            "Blog: \n Title:    " + currentTitle + "\n" +
            "Content:    " + currentContent + "\n";
    ui->latestInfoListWidget->addItem(content);
}

void DashboardGUI::displayTweet(Tweet* tweet) {

    QString currentContent = tweet->getContent();

    QString content("Tweet: \n Content: " + currentContent + "\n");


    ui->latestInfoListWidget->addItem(content);

}

void DashboardGUI::displayMultimedia(Multimedia* multimedia) {

    QString title = multimedia->getTitle();
    QString description = multimedia->getDescription();
    QString content = multimedia->getContent();
    QString newLabel("Title: "+title + "\n" + "Descrption: " + description);
    QListWidgetItem *newMedia = new QListWidgetItem(QIcon(content), newLabel, ui->latestInfoListWidget);
    ui->latestInfoListWidget->addItem(newMedia);

    ui->latestInfoListWidget->setIconSize(QSize(125,125));


}

