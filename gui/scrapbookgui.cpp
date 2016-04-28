#include "scrapbookgui.h"
#include "ui_scrapbookgui.h"

ScrapbookGUI::ScrapbookGUI(AccountController *currentAccount,
                           QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrapbookGUI)
{
    ui->setupUi(this);
    accountController = currentAccount;
    scrapbook = accountController->getUser()->getProfile()->getScrapbook();

    ui->viewButton->hide();
    ui->scrapbookArea->setSelectionMode(QAbstractItemView::SingleSelection);

    createBlogView = new CreateBlogGUI(accountController, scrapbook, this);
    displayBlogView = new DisplayBlogGUI(scrapbook, this);
    createTweetView = new CreateTweetGUI(accountController, scrapbook, this);
    displayTweetView = new DisplayTweetGUI(scrapbook, this);
    createMultimediaView = new CreateMultimediaGUI(accountController, scrapbook, this);
    displayMultimediaView = new DisplayMultimediaGUI(scrapbook, this);

    // add display and edit view for blog
    ui->blogStackedWidget->addWidget(displayBlogView);
    ui->blogStackedWidget->addWidget(createBlogView);

    // add display and edit view for tweet
    ui->tweetStackedWidget->addWidget(displayTweetView);
    ui->tweetStackedWidget->addWidget(createTweetView);

    // add display and edit view for multimedia
    ui->multimediaStackedWidget->addWidget(displayMultimediaView);
    ui->multimediaStackedWidget->addWidget(createMultimediaView);

    // show display view as default
    ui->blogStackedWidget->setCurrentWidget(displayBlogView);
    ui->tweetStackedWidget->setCurrentWidget(displayTweetView);
    ui->multimediaStackedWidget->setCurrentWidget(displayMultimediaView);

    refreshBook();

    connect(ui->scrapbookArea, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(on_scrapbookAreaItem_clicked(QListWidgetItem*)));

}


ScrapbookGUI::ScrapbookGUI(AccountController *currentAccount,
                           Scrapbook *displayScrapbook,
                           QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrapbookGUI)
{
    ui->setupUi(this);
    accountController = currentAccount;
    scrapbook = displayScrapbook;

    createBlogView = new CreateBlogGUI(accountController, scrapbook, this);
    displayBlogView = new DisplayBlogGUI(scrapbook, this);
    createTweetView = new CreateTweetGUI(accountController, scrapbook, this);
    displayTweetView = new DisplayTweetGUI(scrapbook, this);
    createMultimediaView = new CreateMultimediaGUI(accountController, scrapbook, this);
    displayMultimediaView = new DisplayMultimediaGUI(scrapbook, this);

    // add display and edit view for blog
    ui->blogStackedWidget->addWidget(displayBlogView);
    ui->blogStackedWidget->addWidget(createBlogView);

    // add display and edit view for tweet
    ui->tweetStackedWidget->addWidget(displayTweetView);
    ui->tweetStackedWidget->addWidget(createTweetView);

    // add display and edit view for multimedia
    ui->multimediaStackedWidget->addWidget(displayMultimediaView);
    ui->multimediaStackedWidget->addWidget(createMultimediaView);

    // show display view as default
    ui->blogStackedWidget->setCurrentWidget(displayBlogView);
    ui->tweetStackedWidget->setCurrentWidget(displayTweetView);
    ui->multimediaStackedWidget->setCurrentWidget(displayMultimediaView);

    refreshBook();

}

ScrapbookGUI::~ScrapbookGUI()
{
    delete ui;
}

void ScrapbookGUI::switchTweetViews() {
    if (ui->tweetStackedWidget->currentWidget() == displayTweetView)
        ui->tweetStackedWidget->setCurrentWidget(createTweetView);
    else
        //displayTweetView->refreshTweets();
        ui->tweetStackedWidget->setCurrentWidget(displayTweetView);
        displayTweetView->refreshTweets();
}

void ScrapbookGUI::switchBlogViews() {
    if (ui->blogStackedWidget->currentWidget() == displayBlogView){
        ui->blogStackedWidget->setCurrentWidget(createBlogView);
    }
    else {
        displayBlogView->refreshBlogs();
        ui->blogStackedWidget->setCurrentWidget(displayBlogView);
    }
}


void ScrapbookGUI::switchMultimediaViews() {
    if (ui->multimediaStackedWidget->currentWidget() == displayMultimediaView){
        ui->multimediaStackedWidget->setCurrentWidget(createMultimediaView);
    }
    else {
        displayMultimediaView->refreshMultimedia();
        ui->multimediaStackedWidget->setCurrentWidget(displayMultimediaView);
    }
}

void ScrapbookGUI::refreshBook()
{

    ui->scrapbookArea->clear();
    ui->scrapbookArea->addItem(QString("Your posts: \n"));
    std::vector<Post*> wholeScrapbook = scrapbook->getAllPosts();
    for (unsigned int i = 0; i < wholeScrapbook.size(); i++) {
        Post* currentPost = wholeScrapbook[i];
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

void ScrapbookGUI::displayBlog(Blog* blog) {

    QString currentTitle = blog->getTitle();
    QString currentContent = blog->getContent();

    QString content =
            "Blog: \nTitle:    " + currentTitle + "\n" +
            "Content:    " + currentContent + "\n";
    ui->scrapbookArea->addItem(content);
}

void ScrapbookGUI::displayTweet(Tweet* tweet) {

    QString currentContent = tweet->getContent();
    QString content("Tweet: \nContent: " + currentContent +"\n");
    ui->scrapbookArea->addItem(content);

}


void ScrapbookGUI::displayMultimedia(Multimedia* multimedia) {

    QString title = multimedia->getTitle();
    QString description = multimedia->getDescription();
    QString content = multimedia->getContent();
    QString newLabel("Title: "+title + "\n" + "Description: " + description);
    QListWidgetItem *newMedia = new QListWidgetItem(QIcon(content), newLabel, ui->scrapbookArea);
    ui->scrapbookArea->addItem(newMedia);
    ui->scrapbookArea->setIconSize(QSize(125,125));


}

void ScrapbookGUI::on_editButton_clicked()
{

}

void ScrapbookGUI::on_deleteButton_clicked()
{

}

void ScrapbookGUI::on_viewButton_clicked()
{

}

void ScrapbookGUI::on_scrapbookAreaItem_clicked(QListWidgetItem* listItem) {
//    if(listItem->t)
//    ui->viewButton->show();

}
