#include "feedui.h"

FeedUI::FeedUI(AccountController* accountControl)
{
    this->accountControl=accountControl;
    initialize();
    options=2;
    takeCommand(select(options));
    //run();

}

void FeedUI::run()
{


}

void FeedUI::drawScreen(int v) {

clear();

// print the instructions for manipulating the Value object
mvprintw(0, 0, "Select type of content to post:");
mvprintw(3, 8, "View Feed");
mvprintw(4, 8, "Back");

mvprintw(v+2, 5, "->");

refresh();
}

void FeedUI::takeCommand(int selection){

    // cleanup the window and return control to bash
    endwin();

    if(selection==1)
        displayFeed();
   else if(selection==2)
       return;

   initialize();
   takeCommand(select(options));

}

void FeedUI::displayFeed()
{
    erase();
    mvprintw(0,0, "Your friends' rocket adventures:");

    Feed *allFeed = accountControl->getUser()->getFeed();
    allFeed->updatePostList();
    std::vector<Post*> friendFeed = allFeed->getFeed();
    int row=2;
    for (unsigned int i = 0; i < friendFeed.size(); i++) {
        Post* currentPost = friendFeed[i];
        QString *author = new QString(currentPost->getAuthorUsername());
        Post::PostType pType = currentPost->type();
        switch (pType) {
            case Post::typeBlog:
                //ui->wholeFeed->addItem(QString(currentPost->getAuthorUsername() + ": \n"));
                displayBlog((Blog*)currentPost, row, author);
                row = row+5;
                break;
            case Post::typeTweet:
                //ui->wholeFeed->addItem(QString(currentPost->getAuthorUsername() + ": \n"));
                displayTweet((Tweet*)currentPost, row, author);
                row = row+4;
                break;
            case Post::typeMultimedia:
                //ui->wholeFeed->addItem(QString(currentPost->getAuthorUsername() + ": \n"));
                //displayMultimedia((Multimedia*)currentPost, ui->wholeFeed);
                break;
            case Post::typeComment:
                break;
            case Post::typePost:
                break;
        }
    }

    getch();

}

void FeedUI::displayBlog(Blog *blog, int row, QString *author)
{

    QString currentTitle = "Title: "+blog->getTitle();
    QString currentContent = blog->getContent();
    QString line1;
    line1 = *author + "'s blog:";
    mvprintw(row, 1, line1.toStdString().c_str());
    mvprintw(row+1, 1, currentTitle.toStdString().c_str());
    mvprintw(row+2, 1, currentContent.toStdString().c_str());

}

void FeedUI::displayTweet(Tweet *tweet, int row, QString *author)
{
    QString currentContent = tweet->getContent();
    QString line1;
    line1 = *author + "'s tweet:";
    mvprintw(row,1, line1.toStdString().c_str());
    mvprintw(row+1, 1, currentContent.toStdString().c_str());

}


