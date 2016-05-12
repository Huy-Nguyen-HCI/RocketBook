#include "feedui.h"

FeedUI::FeedUI(AccountController* accountControl)
{
    this->accountControl=accountControl;
    initialize();
    int chosenBlog=displayFeed();
    if(chosenBlog!=-1)
        viewBlog(chosenBlog);
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

    endwin();

    if(selection==1)
        displayFeed();
    else if(selection==2)
        return;

    initialize();
    takeCommand(select(options));

}

int FeedUI::displayFeed()
{

    bool scrolling=true;
    int offset=0;
    int row, max;

    while(scrolling){
        Feed *allFeed = accountControl->getUser()->getFeed();
        allFeed->updatePostList();
        std::vector<Post*> friendFeed = allFeed->getFeed();
        erase();
        refresh();
        mvprintw(0,0, "Feed: Select a blog to comment with enter or press any other key to go back");
        refresh();

        row=4;
        mvprintw(row, 5, "->");
        refresh();



        max=offset+4;
        if(friendFeed.size()<offset+4)
            max=friendFeed.size();

        for(unsigned int i=offset;i<max; i++){

            Post* currentPost = friendFeed[i];
            QString *author = new QString(currentPost->getAuthorUsername());
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
                row = row+5;
                break;
            case Post::typeMultimedia:
                mvprintw(row, 8, "multimedia content!");
                refresh();
                row = row+5;
                break;
            case Post::typeComment:
                break;
            case Post::typePost:
                break;
            }
        }


        int ch= getch();
        if(ch==KEY_DOWN && (max!=(offset+1)))
            offset++;
        else if(ch==KEY_UP && offset>0)
            offset--;
        else if(ch==KEY_UP);
        else if(ch==KEY_DOWN);
        else if(ch==10)//enter key
            viewBlog(offset);
        else
            return -1;

    }
    return offset;






}

void FeedUI::viewBlog(int index)
{
    erase();
    bool isBlog = checkType(index);
    if( !isBlog){
        endwin();
        return;
    }

    bool commenting = true;
    int offset=0;
    int row = 2;
    int max, displayNumber=7;


    while(commenting){
        Feed *allFeed = accountControl->getUser()->getFeed();
        allFeed->updatePostList();
        std::vector<Post*> friendFeed = allFeed->getFeed();
        erase();
        refresh();
        Blog* currentBlog;
        currentBlog = (Blog*) friendFeed[index];
        QString *author = new QString(currentBlog->getAuthorUsername());
        QString *currentContent = new QString(currentBlog->getContent());
        std::vector<Comment*> allComments = currentBlog->getAllComments();
        erase();
        endwin();
        erase();

        mvprintw(0, 0, "Enter to post comment or any other key to go back");


        mvprintw(2,0, "Blog Title: ");
        printw(currentBlog->getTitle().toStdString().c_str());

        mvprintw(3,0, "Author: ");

        printw(author->toStdString().c_str());

        mvprintw(4,0, "Content: ");
        printw(currentContent->toStdString().c_str());

        mvprintw(13, 0, "Comments:");
        mvprintw(12, 0, "Press up or down to scroll through comments");
        refresh();

        row=14;


        if(allComments.size() < displayNumber)
            max = allComments.size();
        else
            max = offset+displayNumber;

        for(int i=offset;i<max;i++){
            Comment *currentComment = allComments.at(i);
            QString currentContent = currentComment->getAuthorUsername() + ": " + currentComment->getContent();
            mvprintw(row, 0, currentContent.toStdString().c_str());
            refresh();
            row++;

        }

        int ch= getch();
        if(ch==KEY_DOWN && !((allComments.size())==(max)))
            offset++;
        else if(ch==KEY_UP && offset>0)
            offset--;
        else if(ch==KEY_UP);
        else if(ch==KEY_DOWN);
        else if(ch==10){//enter key
            postComment(index);

            if(allComments.size() > displayNumber)
                offset=allComments.size()-displayNumber - 1;
        }
        else
            commenting=false;

    }


}

void FeedUI::postComment(int blogIndex)
{

    char comment[500];
    mvprintw(LINES-3, 5, "Enter New Comment: ");
    echo();
    getstr(comment);


    Feed *allFeed = accountControl->getUser()->getFeed();
    allFeed->updatePostList();
    std::vector<Post*> friendFeed = allFeed->getFeed();
    erase();
    refresh();
    Blog* currentBlog;
    currentBlog = (Blog*) friendFeed[blogIndex];

    currentBlog->addComment(accountControl->getUser()->getUsername(), QString::fromStdString(comment));

    noecho();

}


bool FeedUI::checkType(int postIndex)
{
    Feed *allFeed = accountControl->getUser()->getFeed();
    allFeed->updatePostList();
    std::vector<Post*> friendFeed = allFeed->getFeed();
    erase();
    refresh();
    Post* currentPost = friendFeed[postIndex];
    Post::PostType pType = currentPost->type();
    switch (pType) {
    case Post::typeBlog:
        return true;
        break;
    case Post::typeTweet:
        return false;
        break;
    case Post::typeMultimedia:
        return false;
        break;
    case Post::typeComment:
        return false;
        break;
    case Post::typePost:
        return false;
        break;
    }

}


void FeedUI::displayBlog(Blog *blog, int row, QString *author)
{

    QString currentTitle = "Title: "+blog->getTitle();
    QString currentContent = blog->getContent();
    QString line1;
    line1 = *author + "'s blog:";
    mvprintw(row,8, line1.toStdString().c_str());
    mvprintw(row+1, 8, currentTitle.toStdString().c_str());
    mvprintw(row+2, 8, currentContent.toStdString().c_str());
    refresh();

}



void FeedUI::displayTweet(Tweet *tweet, int row, QString *author)
{
    QString currentContent = tweet->getContent();
    QString line1;
    line1 = *author + "'s tweet:";
    mvprintw(row,8, line1.toStdString().c_str());
    mvprintw(row+1, 8, currentContent.toStdString().c_str());
    refresh();

}


