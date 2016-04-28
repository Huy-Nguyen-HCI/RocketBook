#include "feedui.h"

FeedUI::FeedUI(AccountController* accountControl)
{
    this->accountControl=accountControl;
    initialize();
    displayFeed();
    //options=2;
    //takeCommand(select(options));
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
    bool booking=true;
    int offset=0;
    int row;
    while(booking){


    row = 2;

    Feed *allFeed = accountControl->getUser()->getFeed();
    allFeed->updatePostList();
    std::vector<Post*> friendFeed = allFeed->getFeed();
    erase();
    refresh();
    mvprintw(0,0, "Your friends' rocket adventures:");
    refresh();
    //int row=2;
    int *max;
    if(friendFeed.size() < 5){
        *max = friendFeed.size();
    }else{
        *max = offset+5;
    }
    for (unsigned int i = offset; i < *max; i++) {
        Post* currentPost = friendFeed[i];
        QString *author = new QString(currentPost->getAuthorUsername());
        //QString *author = new QString("test author");
        Post::PostType pType = currentPost->type();
        switch (pType) {
            case Post::typeBlog:
                displayBlog((Blog*)currentPost, row, author);
                refresh();
                row = row+5;
                break;
            case Post::typeTweet:
                displayTweet((Tweet*)currentPost, row, author);
                refresh();
                row = row+4;
                break;
            case Post::typeMultimedia:
                mvprintw(row, 1, "multimedia content!");
                refresh();
                row = row+2;
                break;
            case Post::typeComment:
                break;
            case Post::typePost:
                break;
        }
    }

    //getch();
    int ch= getch();
        if(ch==KEY_DOWN && !((friendFeed.size())==(5+offset)))//ch==258 || KEY_DOWN || !((wholeScrapbook.size()-5)>offset)) //259 and 259 enables scrolling
            offset++;
        else if(ch==KEY_UP && offset>0)//ch==259 || KEY_UP || offset>0)
            offset--;
        else if(ch==KEY_UP);
        else if(ch==KEY_DOWN);


        else
            booking=false;


    }
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
    refresh();

}

void FeedUI::displayTweet(Tweet *tweet, int row, QString *author)
{
    QString currentContent = tweet->getContent();
    QString line1;
    line1 = *author + "'s tweet:";
    mvprintw(row,1, line1.toStdString().c_str());
    mvprintw(row+1, 1, currentContent.toStdString().c_str());
    refresh();

}


