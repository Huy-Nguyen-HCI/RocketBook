#include "scrapbookgui.h"
#include "ui_scrapbookgui.h"

ScrapbookGUI::ScrapbookGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrapbookGUI)
{
    ui->setupUi(this);
    accountController = inputAccountController;

    createBlogView = new CreateBlogGUI(accountController, this);
    displayBlogView = new DisplayBlogGUI(accountController, this);
    createTweetView = new CreateTweetGUI(accountController, this);
    displayTweetView = new DisplayTweetGUI(accountController, this);
    createMultimediaView = new CreateMultimediaGUI(accountController, this);
    displayMultimediaView = new DisplayMultimediaGUI(accountController, this);

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
    std::vector<Post*> wholeScrapbook = accountController->getUser()->getProfile()->getScrapbook()->getAllPosts();
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
            "Blog: \n Title:    " + currentTitle + "\n" +
            "Content:    " + currentContent + "\n";
    ui->scrapbookArea->addItem(content);
}

void ScrapbookGUI::displayTweet(Tweet* tweet) {

    QString currentContent = tweet->getContent();
    QString content("Tweet: \n Content: " + currentContent +"\n");
    ui->scrapbookArea->addItem(content);

}


void ScrapbookGUI::displayMultimedia(Multimedia* multimedia) {

    QString title = multimedia->getTitle();
    QString description = multimedia->getDescription();
    QString content = multimedia->getContent();
    QString newLabel("Title: "+title + "\n" + "Descrption: " + description);
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
