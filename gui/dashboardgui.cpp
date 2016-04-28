#include "dashboardgui.h"
#include "ui_dashboardgui.h"


int DashboardGUI::blogListItemType = 13;
int DashboardGUI::tweetListItemType = 14;
int DashboardGUI::multimediaListItemType = 15;
int DashboardGUI::listItemTypeRole = 20;
int DashboardGUI::listItemIDRole = 21;
int DashboardGUI::listItemScrapbookRole = 22;

DashboardGUI::DashboardGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardGUI)
{
    ui->setupUi(this);
    this->accountController = inputAccountController;
    ui->commentButton->hide();

    connect(ui->wholeFeed, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(wholeFeedItem_clicked(QListWidgetItem*)));
    refreshAllPosts();
}

DashboardGUI::~DashboardGUI()
{
    delete ui;
}

void DashboardGUI::on_latestScrapbookButton_clicked()
{
    ui->latestInfoListWidget->clear();
//    ui->latestInfoListWidget->addItem(QString("Your latest posts: \n"));
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
            "Blog title:    " + currentTitle + "\n" +
            "@" + blog->getAuthorUsername() + "\n" +
            currentContent + "\n";

    QListWidgetItem* listItem = new QListWidgetItem(content);
    listItem->setData(listItemTypeRole, blogListItemType);
    listItem->setData(listItemIDRole, blog->getID());

    theList->addItem(listItem);

}

void DashboardGUI::displayTweet(Tweet* tweet, QListWidget* theList) {

    QString currentContent = tweet->getContent();

    QString content("@" + tweet->getAuthorUsername() + ": " + currentContent +"\n");

    QListWidgetItem* listItem = new QListWidgetItem(content);
    listItem->setData(listItemTypeRole, tweetListItemType);
    listItem->setData(listItemIDRole, tweet->getID());
    theList->addItem(listItem);

}


void DashboardGUI::displayMultimedia(Multimedia* multimedia, QListWidget* theList) {

    QString title = multimedia->getTitle();
    QString description = multimedia->getDescription();
    QString content = multimedia->getContent();
    QString newLabel("Photo: "+title + "\n"
                     + "@" + multimedia->getAuthorUsername() + "\n"
                     + description);
    QListWidgetItem *newMedia = new QListWidgetItem(QIcon(content), newLabel, theList);

    newMedia->setData(listItemTypeRole, multimediaListItemType);
    newMedia->setData(listItemIDRole, multimedia->getID());

    theList->addItem(newMedia);

    theList->setIconSize(QSize(125,125));
}



void DashboardGUI::on_latestMultimediaButton_clicked()
{
    ui->latestInfoListWidget->clear();
//    ui->latestInfoListWidget->addItem(QString("Your latest multimedia: \n"));
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
        QString newLabel("Title: "+title + "\n" + "Description: " + description);
        QListWidgetItem *newMedia = new QListWidgetItem(QIcon(content), newLabel, ui->latestInfoListWidget);
        ui->latestInfoListWidget->addItem(newMedia);
        ui->latestInfoListWidget->setIconSize(QSize(125,125));
    }

}

void DashboardGUI::refreshAllPosts()
{

    ui->wholeFeed->clear();
//    ui->wholeFeed->addItem(QString("Your friends' rocket lauching adventures: \n"));
    Feed *allFeed = accountController->getUser()->getFeed();
    allFeed->updatePostList();
    std::vector<Post*> friendFeed = allFeed->getFeed();

    for (unsigned int i = 0; i < friendFeed.size(); i++) {
        Post* currentPost = friendFeed[i];
        Post::PostType pType = currentPost->type();
        switch (pType) {
            case Post::typeBlog:
                displayBlog((Blog*)currentPost, ui->wholeFeed);
                break;
            case Post::typeTweet:
                displayTweet((Tweet*)currentPost, ui->wholeFeed);
                break;
            case Post::typeMultimedia:
                displayMultimedia((Multimedia*)currentPost, ui->wholeFeed);
                break;
            case Post::typeComment:
                break;
            case Post::typePost:
                break;
        }
    }
}




void DashboardGUI::wholeFeedItem_clicked(QListWidgetItem *listItem)
{
    if(listItem->data(listItemTypeRole) == blogListItemType) {
        ui->commentButton->show();
    } else {
        ui->commentButton->hide();
    }
}



void DashboardGUI::on_commentButton_clicked()
{
    QList<QListWidgetItem*> blogList = ui->wholeFeed->selectedItems();
    int blogID = blogList[0]->data(listItemIDRole).toInt();
    Blog* blog = accountController->getUser()->getFeed()->getBlog(blogID);
    ViewBlogGUI* viewBlogGUI = new ViewBlogGUI(accountController, blog);
    viewBlogGUI->show();

}
