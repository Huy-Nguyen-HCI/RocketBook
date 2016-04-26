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
                displayBlog((Blog*)currentPost, ui->latestInfoListWidget);
                break;
            case Post::typeTweet:
                displayTweet((Tweet*)currentPost, ui->latestInfoListWidget);
                break;
            case Post::typeMultimedia:
                displayMultimedia((Multimedia*)currentPost, ui->latestInfoListWidget);
                break;
            case Post::typeComment:
                break;
            case Post::typePost:
                break;
        }
    }
}

void DashboardGUI::displayBlog(Blog* blog, QListWidget* theList) {

    QString currentTitle = blog->getTitle();
    QString currentContent = blog->getContent();

    QString content =
            "Blog: \nTitle:    " + currentTitle + "\n" +
            "Content:    " + currentContent + "\n";
    theList->addItem(content);
}

void DashboardGUI::displayTweet(Tweet* tweet, QListWidget* theList) {

    QString currentContent = tweet->getContent();

    QString content("Tweet: \nContent: " + currentContent +"\n");

    theList->addItem(content);

}


void DashboardGUI::displayMultimedia(Multimedia* multimedia, QListWidget* theList) {

    QString title = multimedia->getTitle();
    QString description = multimedia->getDescription();
    QString content = multimedia->getContent();
    QString newLabel("Title: "+title + "\n" + "Descrption: " + description);
    QListWidgetItem *newMedia = new QListWidgetItem(QIcon(content), newLabel, theList);
    theList->addItem(newMedia);

    theList->setIconSize(QSize(125,125));


}



void DashboardGUI::on_latestMultimediaButton_clicked()
{
    ui->latestInfoListWidget->clear();
    ui->latestInfoListWidget->addItem(QString("Your latest multimedia: \n"));
    Profile *currentProfile = accountController->getUser()->getProfile();
    Scrapbook *myScrapbook = currentProfile->getScrapbook();
    std::vector<Multimedia*> allMulti = myScrapbook->getAllMedia();
    for(int i = 0; i < 5; i++){
        if(i == allMulti.size()){
            return;
        }
        Multimedia *media = allMulti.at(i);
        QString title = media->getTitle();
        QString description = media->getDescription();
        QString content = media->getContent();
        QString newLabel("Title: "+title + "\n" + "Descrption: " + description);
        QListWidgetItem *newMedia = new QListWidgetItem(QIcon(content), newLabel, ui->latestInfoListWidget);
        ui->latestInfoListWidget->addItem(newMedia);
        ui->latestInfoListWidget->setIconSize(QSize(125,125));
    }

}

void DashboardGUI::refreshAllPosts()
{

    ui->wholeFeed->clear();
    ui->wholeFeed->addItem(QString("Your friends' rocket lauching adventures: \n"));
    Feed *allFeed = accountController->getUser()->getFeed();
    allFeed->updatePostList();
    std::vector<Post*> friendFeed = allFeed->getFeed();

    for (unsigned int i = 0; i < friendFeed.size(); i++) {
        Post* currentPost = friendFeed[i];
        Post::PostType pType = currentPost->type();
        switch (pType) {
            case Post::typeBlog:
                ui->wholeFeed->addItem(QString(currentPost->getAuthorUsername() + ": \n"));
                displayBlog((Blog*)currentPost, ui->wholeFeed);
                break;
            case Post::typeTweet:
                ui->wholeFeed->addItem(QString(currentPost->getAuthorUsername() + ": \n"));
                displayTweet((Tweet*)currentPost, ui->wholeFeed);
                break;
            case Post::typeMultimedia:
                ui->wholeFeed->addItem(QString(currentPost->getAuthorUsername() + ": \n"));
                displayMultimedia((Multimedia*)currentPost, ui->wholeFeed);
                break;
            case Post::typeComment:
                break;
            case Post::typePost:
                break;
        }
    }







}
