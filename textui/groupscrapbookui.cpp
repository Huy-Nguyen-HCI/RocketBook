#include "groupscrapbookui.h"

GroupScrapbookUI::GroupScrapbookUI(QString username, int groupId,Group* group, Scrapbook* groupScrapbook, QStringList friendNames)
{
    this->groupId=groupId;
    this->group=group;
    this->groupScrapbook=groupScrapbook;
    this->username=username;
    this->friendNames=friendNames;

    options=5;
    takeCommand(select(options));

}



void GroupScrapbookUI::drawScreen(int v){
    clear();


    mvprintw(0, 0, group->getProfile()->getFullName().toStdString().c_str());
    mvprintw(3, 8, "View Scrapbook");
    mvprintw(4, 8, "Post blog");
    mvprintw(5, 8, "Post tweet");
    mvprintw(6, 8, "Add friend to group");
    mvprintw(7, 8, "Back");

    mvprintw(v+2, 5, "->");

    refresh();


}

void GroupScrapbookUI::takeCommand(int selection){

    endwin();

    if(selection==1){
        viewScrapbook();

    }
    else if(selection==2){
        postBlog();
    }

    else if(selection==3){
        postTweet();

    }
    else if(selection==4){
        int chosenFriend=selectFriend();
        if(chosenFriend!=-1)
            addFriend(chosenFriend);
    }

    else if(selection==5)
        return;

    initialize();
    takeCommand(select(options));

}

int GroupScrapbookUI::viewScrapbook(){

    bool booking=true;
    int offset=0;
    int row, max;


    while(booking){

        std::vector<Post*> wholeScrapbook = groupScrapbook->getAllPosts();
        erase();
        mvprintw(0,0, "Group Scrapbook: Select a blog to comment using enter or press any other key to go back");
        refresh();
        row=3;
        mvprintw(row, 5, "->");
        refresh();

        int *max;
        if(wholeScrapbook.size() < offset+5){
            *max = wholeScrapbook.size();
        }else{
            *max = offset+5;
        }
        for (unsigned int i = offset; i < *max; i++) {
            Post* currentPost = wholeScrapbook[i];
            Post::PostType pType = currentPost->type();

            switch (pType) {
            case Post::typeBlog:
                displayBlog((Blog*)currentPost, row);
                row = row+5;
                break;
            case Post::typeTweet:
                displayTweet((Tweet*)currentPost, row);
                row = row+5;
                break;
            case Post::typeMultimedia:
                mvprintw(row, 8, "multimedia content!");
                row = row+5;
                break;
            case Post::typeComment:
                break;
            case Post::typePost:
                break;
            }
        }

        //scrl(number of lines)

        int ch= getch();
        if(ch==KEY_DOWN && (*max!=(offset+1)))
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

void GroupScrapbookUI::postBlog(){
    char text[2000], title[200];
    erase();
    mvprintw(0,0, "New Blog");
    mvprintw(1,0, "Enter Title: ");
    echo();
    getstr(title);


    mvprintw(2,0, "Enter Text: ");
    getstr(text);

    mvprintw(LINES-1,0, "Enter p to make private: ");
    bool priv=false;
    cbreak();
    noecho();
    int ch= getch();
    if(ch==112 || ch==10){//enter key or p)

        if(ch==112) //p button
            priv=true;

        groupScrapbook->addBlog(username, title, text, priv);

    }


}

void GroupScrapbookUI::postTweet(){
    char text[2000];
    erase();
    mvprintw(0,0,"New Tweet");
    mvprintw(0,0, "Enter Text: ");
    echo();
    getstr(text);

    mvprintw(LINES-1,0, "Enter p post private, pressed enter to post public, or hit another key to cancel");
    bool priv=false;
    cbreak();
    noecho();
    int ch= getch();
    if(ch==112 || ch==10){//enter key or p)

        if(ch==112) //p button
            priv=true;
        groupScrapbook->addTweet(username,text,priv);

    }

}

void GroupScrapbookUI::addFriend(int friendIndex){
    QString friendName=friendNames.at(friendIndex);
    group->addMember(friendName);
}


void GroupScrapbookUI::displayBlog(Blog *blog, int row)
{
    QString currentTitle = "Title: "+blog->getTitle();
    QString currentContent = blog->getContent();
    mvprintw(row, 8,"Blog");
    mvprintw(row+1, 8, currentTitle.toStdString().c_str());
    mvprintw(row+2, 8, currentContent.toStdString().c_str());


}

void GroupScrapbookUI::displayTweet(Tweet *tweet, int row)
{
    QString currentContent = tweet->getContent();
    mvprintw(row,8,"Tweet");
    mvprintw(row+1, 8, currentContent.toStdString().c_str());

}

void GroupScrapbookUI::viewBlog(int index)
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

        std::vector<Post*> wholeScrapbook = groupScrapbook->getAllPosts();
        erase();
        refresh();
        Blog* currentBlog;
        currentBlog = (Blog*) wholeScrapbook[index];
        QString *currentContent = new QString(currentBlog->getContent());
        std::vector<Comment*> allComments = currentBlog->getAllComments();
        erase();
        endwin();
        erase();
        mvprintw(0, 0, "Press up or down to scroll or Enter to post comment.");
        mvprintw(2,0, "Blog Title: ");
        printw(currentBlog->getTitle().toStdString().c_str());

        mvprintw(3,0, "Content: ");
        printw(currentContent->toStdString().c_str());

        mvprintw(12, 0, "Comments:");
        refresh();


        row=13;


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

bool GroupScrapbookUI::checkType(int scrapbookIndex)
{
    std::vector<Post*> wholeScrapbook = groupScrapbook->getAllPosts();
    erase();
    refresh();
    Post* currentPost = wholeScrapbook[scrapbookIndex];
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

void GroupScrapbookUI::postComment(int blogIndex)
{
    char comment[500];
    mvprintw(LINES-3, 5, "Enter New Comment: ");
    echo();
    getstr(comment);

    std::vector<Post*> myBook = groupScrapbook->getAllPosts();
    erase();
    refresh();
    Blog* currentBlog;
    currentBlog = (Blog*) myBook[blogIndex];

    currentBlog->addComment(username, QString::fromStdString(comment));

    noecho();
}

int GroupScrapbookUI::selectFriend(){

    bool scrolling=true;
    int offset=0;
    int row, max;

    while(scrolling){
        erase();
        mvprintw(0,0, "Friends: Press enter to select friend");

        row=3;
        mvprintw(row, 5, "->");

        max=offset+15;
        if(friendNames.size()<offset+15)
            max=friendNames.size();


        for (unsigned int i = offset; i < max; i++) {
            mvprintw(row,8,friendNames.at(i).toStdString().c_str());
            row++;
        }

        int ch= getch();
        if(ch==KEY_DOWN && (max!=(offset+1)))
            offset++;
        else if(ch==KEY_UP && offset>0)
            offset--;
        else if(ch==KEY_UP);
        else if(ch==KEY_DOWN);
        else if(ch==10)//enter key
            scrolling=false;
        else
            return -1;

    }
    return offset;

}
