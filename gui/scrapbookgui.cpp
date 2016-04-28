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
    ui->message->clear();
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

    QString currentTitle = blog->getTitle();
    QString currentContent = blog->getContent();

    QString content =
            "Blog: \nTitle:    " + currentTitle + "\n" +
            "Content:    " + currentContent + "\n";

    QListWidgetItem* listItem = new QListWidgetItem(content);
    listItem->setData(listItemTypeRole, blogListItemType);
    listItem->setData(listItemIDRole, blog->getID());
    ui->scrapbookArea->addItem(listItem);
}

void ScrapbookGUI::displayTweet(Tweet* tweet) {

    QString currentContent = tweet->getContent();
    QString content("Tweet: \nContent: " + currentContent +"\n");


    QListWidgetItem* listItem = new QListWidgetItem(content);
    listItem->setData(listItemTypeRole, tweetListItemType);
    listItem->setData(listItemIDRole, tweet->getID());
    ui->scrapbookArea->addItem(listItem);

}


void ScrapbookGUI::displayMultimedia(Multimedia* multimedia) {

    QString title = multimedia->getTitle();
    QString description = multimedia->getDescription();
    QString content = multimedia->getContent();
    QString newLabel("Title: "+title + "\n" + "Description: " + description);
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

void ScrapbookGUI::on_scrapbookAreaItem_clicked(QListWidgetItem* listItem) {
    if(listItem->data(listItemTypeRole) == blogListItemType) {
        ui->viewButton->show();
    } else {
        ui->viewButton->hide();
    }
}

void ScrapbookGUI::on_exportButton_clicked()
{
    QString htmlText;

    // set up html code
    htmlText += "<!DOCTYPE html><html>";

    // set title
    htmlText += "<head> <title> My Scrapbook </title> </head>";

    // set header
    htmlText = htmlText + "<h1 style='text-align:center'>" + accountController->getUser()->getUsername() + "'s Scrapbook" + "</h1>";

    // begin body
    htmlText += "<body>";

    // add content
    htmlText += buildContentHTML();

    // end body
    htmlText += "</body>";

    // end html code
    htmlText += "</html>";

    writeToHTMLFile(htmlText);
}

QString ScrapbookGUI::buildContentHTML() {

    QString html;
    std::vector<Post*> wholeScrapbook = scrapbook->getAllPosts();

    // begin list
    html += "<ol>";

    // build list
    for (int i = 0; i < wholeScrapbook.size(); i++) {
        Post* currentPost = wholeScrapbook[i];
        Post::PostType pType = currentPost->type();
        switch (pType) {
            case Post::typeBlog:
                html = html + "<li>" + blogToHTML((Blog*)currentPost) + "</li>";
                break;
            case Post::typeTweet:
                html = html + "<li>" + tweetToHTML((Tweet*)currentPost) + "</li>";
                break;
            case Post::typeMultimedia:
                html = html + "<li>" + multimediaToHTML((Multimedia*)currentPost) + "</li>";
                break;
            case Post::typeComment:
                break;
            case Post::typePost:
                break;
        }
    }

    // end list
    html += "</ol>";
    return html;
}

QString ScrapbookGUI::blogToHTML(Blog *blog) {

    QString html;

    // add post type
    html += "<b>Blog</b> <br>";

    // add blog title
    html = html + "<u>Title:</u> " + blog->getTitle().toHtmlEscaped() + "<br>";

    // add content
    html = html + "<u>Content:</u> " + blog->getContent().toHtmlEscaped();

    return html;
}

QString ScrapbookGUI::tweetToHTML(Tweet *tweet) {

    QString html;

    // add post type
    html += "<b>Tweet</b> <br>";

    // add content
    html = html + "<u>Content:</u> " + tweet->getContent().toHtmlEscaped();

    return html;
}

QString ScrapbookGUI::multimediaToHTML(Multimedia *media) {

    QString html;
    QString imageStyle = " style='width:125px; height:125px; '";

    // add post type
    html += "<b>Multimedia</b> <br>";

    // add title
    html = html + "<u>Title:</u> " + media->getTitle().toHtmlEscaped() + "<br>";

    // add image
    html = html + "<img src=" + "'" + media->getContent() + "'" + imageStyle + ">" + "<br>";

    // add text
    html += "<u>Description:</u> " + media->getDescription().toHtmlEscaped();

    return html;
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
    ui->message->setText("Export successful!");
}
