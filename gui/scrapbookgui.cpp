#include "scrapbookgui.h"
#include "ui_scrapbookgui.h"

int ScrapbookGUI::blogListItemType = 13;
int ScrapbookGUI::tweetListItemType = 14;
int ScrapbookGUI::multimediaListItemType = 15;
int ScrapbookGUI::listItemTypeRole = 20;
int ScrapbookGUI::listItemIDRole = 21;

ScrapbookGUI::ScrapbookGUI(AccountController *currentAccount,
                           QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrapbookGUI)
{
    ui->setupUi(this);
    accountController = currentAccount;
    scrapbook = accountController->getUser()->getProfile()->getScrapbook();

    setUp();

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

    setUp();

}

ScrapbookGUI::~ScrapbookGUI()
{
    delete ui;
}

void ScrapbookGUI::setUp()
{
    ui->viewButton->hide();
    ui->deleteButton->hide();
    ui->editButton->hide();
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

    ui->refreshButton->hide();

    ui->scrapbookArea->setStyleSheet( "QListWidget::item[separator=true] { border-bottom: 1px solid black; }" );

    connect(ui->scrapbookArea, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(scrapbookAreaItem_clicked(QListWidgetItem*)));
}

void ScrapbookGUI::switchTweetViews() {
    if (ui->tweetStackedWidget->currentWidget() == displayTweetView){
        createTweetView->clearViews();
        ui->tweetStackedWidget->setCurrentWidget(createTweetView);
    }
    else {
        displayTweetView->refreshTweets();
        ui->tweetStackedWidget->setCurrentWidget(displayTweetView);
    }
}

void ScrapbookGUI::switchBlogViews() {
    if (ui->blogStackedWidget->currentWidget() == displayBlogView){
        createBlogView->clearFields();
        ui->blogStackedWidget->setCurrentWidget(createBlogView);
    }
    else {
        displayBlogView->refreshBlogs();
        ui->blogStackedWidget->setCurrentWidget(displayBlogView);
    }
}


void ScrapbookGUI::switchMultimediaViews() {
    if (ui->multimediaStackedWidget->currentWidget() == displayMultimediaView){
        createMultimediaView->clearViews();
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

    QString content = printPost(blog);

    QListWidgetItem* listItem = new QListWidgetItem(content);
    listItem->setData(listItemTypeRole, blogListItemType);
    listItem->setData(listItemIDRole, blog->getID());
    ui->scrapbookArea->addItem(listItem);
}

QString ScrapbookGUI::printPost(Post* post) {
    QString currentTitle;
    QString currentContent;
    QString currentDescription;
    QString content;

    Post::PostType postType = post->type();

    switch (postType) {
        case Post::typePost:
            break;
        case Post::typeBlog:

            currentTitle = ((Blog*)post)->getTitle();
            currentContent = ((Blog*)post)->getContent();

            if (currentTitle.isEmpty()) {
                currentTitle = "<No Title>";
            }
            if (currentContent.isEmpty()) {
                currentContent = "<No Content>";
            }

            content = "BLOG \n" +
                      currentTitle + "\n" +
                      "@" + post->getAuthorUsername() + "\n"
                       + currentContent+ "\n";
            break;
        case Post::typeTweet:
            currentContent = post->getContent();
            if (currentContent.isEmpty()) {
                currentContent = "<No Content>";
            }

            content = "TWEET\n@" + ((Tweet*)post)->getAuthorUsername() + ": " + currentContent+ "\n";
            break;
        case Post::typeMultimedia:
            currentTitle = ((Multimedia*)post)->getTitle();
            currentDescription = ((Multimedia*)post)->getDescription();

            if (currentTitle.isEmpty()) {
                currentTitle = "<No Title>";
            }

            content = "PHOTO \n" +
                             currentTitle + "\n" +
                             "@" + post->getAuthorUsername() + "\n" +
                             currentDescription + "\n";
            break;
        case Post::typeComment:
            break;

    }
    return content;
}

void ScrapbookGUI::displayTweet(Tweet* tweet) {

    QString content = printPost(tweet);

    QListWidgetItem* listItem = new QListWidgetItem(content);
    listItem->setData(listItemTypeRole, tweetListItemType);
    listItem->setData(listItemIDRole, tweet->getID());
    ui->scrapbookArea->addItem(listItem);

}


void ScrapbookGUI::displayMultimedia(Multimedia* multimedia) {

    QString content = multimedia->getContent();

    QString newLabel = printPost(multimedia);

    QListWidgetItem *newMedia = new QListWidgetItem(QIcon(content), newLabel, ui->scrapbookArea);


    newMedia->setData(listItemTypeRole, multimediaListItemType);
    newMedia->setData(listItemIDRole, multimedia->getID());
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
    QList<QListWidgetItem*> blogList = ui->scrapbookArea->selectedItems();
    int blogID = blogList[0]->data(listItemIDRole).toInt();
    Blog* blog = scrapbook->getBlog(blogID);
    ViewBlogGUI* viewBlogGUI = new ViewBlogGUI(accountController, blog);
    viewBlogGUI->show();
}

void ScrapbookGUI::scrapbookAreaItem_clicked(QListWidgetItem* listItem) {
    if(listItem->data(listItemTypeRole) == blogListItemType) {
        ui->viewButton->show();
    } else {
        ui->viewButton->hide();
    }
}

void ScrapbookGUI::on_exportButton_clicked()
{
    writeToHTMLFile(accountController->getUser()->exportToHtml());
}




void ScrapbookGUI::writeToHTMLFile(QString htmlText) {

    QString fileName = QFileDialog::getSaveFileName(this,
                                 tr("Save file"),
                                 ":/index.html",
                                 tr("Web pages (*.html)"));
    // if user cancels file selection
    if (fileName.isNull()) return;
    QFile file(fileName);
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << htmlText << endl;
    }
}

void ScrapbookGUI::on_refreshButton_clicked()
{
    refreshBook();
}
