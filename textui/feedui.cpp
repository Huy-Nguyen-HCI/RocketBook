#include "feedui.h"

FeedUI::FeedUI(AccountController* accountControl)
{
    this->accountControl=accountControl;
    initialize();
    int chosenBlog=displayFeed();
    if(chosenBlog!=-1)
        viewBlog(chosenBlog);



    //run();
    //displayFeed();
    //options=2;
    //takeCommand(select(options));
    //run();

}

void FeedUI::run()
{
//    int chosenFriend=selectFriend();
//    if(chosenFriend!=-1)
//        viewFriendsProfile(chosenFriend);
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

int FeedUI::displayFeed()
{
//    bool booking=true;
//    int offset=0;
//    int row;
//    while(booking){


//    row = 2;


//    Feed *allFeed = accountControl->getUser()->getFeed();
//    allFeed->updatePostList();
//    std::vector<Post*> friendFeed = allFeed->getFeed();
//    erase();
//    refresh();
//    mvprintw(0,0, "Your friends' rocket adventures.  Select a blog to comment");
//    mvprintw(row, 5, "->");
//    refresh();
//    //int row=2;
//    int *max;
//    if(friendFeed.size() < 5){
//        *max = friendFeed.size();
//    }else{
//        *max = offset+5;
//    }
//    for (unsigned int i = offset; i < *max; i++) {
//        Post* currentPost = friendFeed[i];
//        QString *author = new QString(currentPost->getAuthorUsername());
//        Post::PostType pType = currentPost->type();
//        switch (pType) {
//            case Post::typeBlog:
//                displayBlog((Blog*)currentPost, row, author);
//                refresh();
//                row = row+5;
//                break;
//            case Post::typeTweet:
//                displayTweet((Tweet*)currentPost, row, author);
//                refresh();
//                row = row+5;
//                break;
//            case Post::typeMultimedia:
//                mvprintw(row, 8, "multimedia content!");
//                refresh();
//                row = row+5;
//                break;
//            case Post::typeComment:
//                break;
//            case Post::typePost:
//                break;
//        }
//    }

//    //getch();
//    int ch= getch();
//        if(ch==KEY_DOWN && /*(*max!=(offset+5)))*/  !((friendFeed.size())==(5+offset)))//ch==258 || KEY_DOWN || !((wholeScrapbook.size()-5)>offset)) //259 and 259 enables scrolling
//            offset++;
//        else if(ch==KEY_UP && offset>0)//ch==259 || KEY_UP || offset>0)
//            offset--;
//        else if(ch==KEY_UP);
//        else if(ch==KEY_DOWN);
//        else if(ch==10)//enter key
//            viewBlog(offset);


//        else
//            return -1;


//    }
//    return offset;

    bool scrolling=true;
    int offset=0;
    int row, max;

    while(scrolling){
    Feed *allFeed = accountControl->getUser()->getFeed();
    allFeed->updatePostList();
    std::vector<Post*> friendFeed = allFeed->getFeed();
    erase();
    refresh();
    mvprintw(0,0, "Your Feed.  Select a blog");
    refresh();

    row=3;
    mvprintw(row, 5, "->");
    refresh();



    max=offset+5;
    if(friendFeed.size()<offset+5)
        max=friendFeed.size();

    for(unsigned int i=offset;i<max; i++){
        //mvprintw(row,8,std::to_string(chatList->at(i)).c_str());
        //row++;
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
        if(ch==KEY_DOWN && (max!=(offset+1)))//ch==258 || KEY_DOWN || !((wholeScrapbook.size()-5)>offset)) //259 and 259 enables scrolling
            offset++;
        else if(ch==KEY_UP && offset>0)//ch==259 || KEY_UP || offset>0)
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
//    Feed *allFeed = accountControl->getUser()->getFeed();
//    allFeed->updatePostList();
//    std::vector<Post*> friendFeed = allFeed->getFeed();
//    erase();
//    refresh();
//    Blog* currentBlog;
//    currentBlog = (Blog*) friendFeed[index];
//    QString *author = new QString(currentBlog->getAuthorUsername() + "'s blog:");
//    std::vector<Comment*> allComments = currentBlog->getAllComments();
//    erase();
      bool commenting = true;
      int offset=0;
      int row = 2;
      int max, displayNumber=18;


    while(commenting){
        Feed *allFeed = accountControl->getUser()->getFeed();
        allFeed->updatePostList();
        std::vector<Post*> friendFeed = allFeed->getFeed();
        erase();
        refresh();
        Blog* currentBlog;
        currentBlog = (Blog*) friendFeed[index];
        QString *author = new QString(currentBlog->getAuthorUsername() + "'s blog:");
        std::vector<Comment*> allComments = currentBlog->getAllComments();
        erase();
        //bool commenting = true;
        //int offset=0;
        //int row = 2;
        //int max, displayNumber=18;
        endwin();
        erase();
        mvprintw(0,0, author->toStdString().c_str());
        mvprintw(1, 0, "Press up or down to scroll or Enter to post comment.");
        refresh();

        row=2;


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
        if(ch==KEY_DOWN && !((allComments.size())==(max)))//ch==258 || KEY_DOWN || !((wholeScrapbook.size()-5)>offset)) //259 and 259 enables scrolling
            offset++;
        else if(ch==KEY_UP && offset>0)//ch==259 || KEY_UP || offset>0)
            offset--;
        else if(ch==KEY_UP);
        else if(ch==KEY_DOWN);
        else if(ch==10){//enter key
            postComment(index);
            //postComment();

            if(allComments.size() > displayNumber)
            offset=allComments.size()-displayNumber - 1;
        }
        else
            commenting=false;

    }


}

void FeedUI::postComment(int blogIndex)
{
    QString username = accountControl->getUser()->getUsername();
    char comment[500];
     mvprintw(LINES-3, 5, "Enter New Comment: ");
     echo();
     getstr(comment);
     //Comment* newComment = new Comment(username, QString::fromStdString(comment));
     //blog->addComment(newComment);

     Feed *allFeed = accountControl->getUser()->getFeed();
     allFeed->updatePostList();
     std::vector<Post*> friendFeed = allFeed->getFeed();
     erase();
     refresh();
     Blog* currentBlog;
     currentBlog = (Blog*) friendFeed[blogIndex];
     //currentBlog->addComment(newComment);
     currentBlog->addComment(accountControl->getUser()->getUsername(), QString::fromStdString(comment));


     //accountControl->getUser()->getChatController()->sendMessage(chatId,QString::fromStdString(comment));
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


//int FeedUI::selectBlog(){

//    bool scrolling=true;
//    int offset=0;
//    int row, max;

//    while(scrolling){
//    erase();
//    mvprintw(0,0, "Friends: Press enter to select friend");

//    row=3;
//    mvprintw(row, 5, "->");

//    QStringList friendNames= friendControl->getFriendNames();

//    max=offset+15;
//    if(friendNames.size()<offset+15)
//        max=friendNames.size();

//    for (unsigned int i = offset; i < max; i++) {
//        mvprintw(row,8,friendNames.at(i).toStdString().c_str());
//        row++;
//    }

//    int ch= getch();
//        if(ch==KEY_DOWN && (max!=(offset+1)))//ch==258 || KEY_DOWN || !((wholeScrapbook.size()-5)>offset)) //259 and 259 enables scrolling
//            offset++;
//        else if(ch==KEY_UP && offset>0)//ch==259 || KEY_UP || offset>0)
//            offset--;
//        else if(ch==KEY_UP);
//        else if(ch==KEY_DOWN);
//        else if(ch==10)//enter key
//            scrolling=false;
//        else
//            return -1;

//    }
//    return offset;

//}

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


