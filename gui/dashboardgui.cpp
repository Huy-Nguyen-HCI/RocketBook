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
    // clear the previous list
    ui->latestInfoListWidget->clear();

    // pull scrapbook data from database and display in a list view
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

    // get data to display
    QString currentTitle = blog->getTitle();
    QString currentContent = blog->getContent();

    if (currentTitle.isEmpty()) {
        currentTitle = "<No Title>";
    }
    if (currentContent.isEmpty()) {
        currentContent = "<No Content>";
    }

    QString content =
            "BLOG \n" +
            currentTitle + "\n" +
            "@" + blog->getAuthorUsername() + "\n"
            + currentContent+ "\n";

    // display each blog as a QListWidgetItem
    QListWidgetItem* listItem = new QListWidgetItem(content);
    listItem->setData(listItemTypeRole, blogListItemType);
    listItem->setData(listItemIDRole, blog->getID());

    theList->addItem(listItem);

}

void DashboardGUI::displayTweet(Tweet* tweet, QListWidget* theList) {

    // get data to display
    QString currentContent = tweet->getContent();
    if (currentContent.isEmpty()) {
        currentContent = "<No Content>";
    }

    QString content("TWEET\n@" + tweet->getAuthorUsername() + ": " + currentContent+ "\n");

    // display each tweet as a QListWidgetItem
    QListWidgetItem* listItem = new QListWidgetItem(content);
    listItem->setData(listItemTypeRole, tweetListItemType);
    listItem->setData(listItemIDRole, tweet->getID());
    theList->addItem(listItem);

}


void DashboardGUI::displayMultimedia(Multimedia* multimedia, QListWidget* theList) {

    // get data to display
    QString title = multimedia->getTitle();
    QString description = multimedia->getDescription();
    QString content = multimedia->getContent();

    if (title.isEmpty()) {
        title = "<No Title>";
    }

    QString newLabel("PHOTO \n" +
                     title + "\n" +
                     "@" + multimedia->getAuthorUsername() + "\n" +
                     description + "\n");

    // display each media as a QListWidgetItem
    QListWidgetItem *newMedia = new QListWidgetItem(QIcon(content), newLabel, theList);

    newMedia->setData(listItemTypeRole, multimediaListItemType);
    newMedia->setData(listItemIDRole, multimedia->getID());

    theList->addItem(newMedia);

    theList->setIconSize(QSize(125,125));
}



void DashboardGUI::on_latestMultimediaButton_clicked()
{
    // clear the previous list
    ui->latestInfoListWidget->clear();

    // pull data from the database and display in a list
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
        QString newLabel = "PHOTO \n" +
                title + "\n" +
                "@" + media->getAuthorUsername() + "\n" +
                description + "\n";
        QListWidgetItem *newMedia = new QListWidgetItem(QIcon(content), newLabel, ui->latestInfoListWidget);
        ui->latestInfoListWidget->addItem(newMedia);
        ui->latestInfoListWidget->setIconSize(QSize(125,125));
    }

}

void DashboardGUI::refreshAllPosts()
{
    // clear the previous list
    ui->wholeFeed->clear();

    // pull feed from the database and display in a list
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
    // get the blog selected
    QList<QListWidgetItem*> blogList = ui->wholeFeed->selectedItems();
    int blogID = blogList[0]->data(listItemIDRole).toInt();
    Blog* blog = accountController->getUser()->getFeed()->getBlog(blogID);

    // display the comment view for the selected blog
    ViewBlogGUI* viewBlogGUI = new ViewBlogGUI(accountController, blog);
    viewBlogGUI->show();

}
