#include "scrapbookui.h"

ScrapbookUI::ScrapbookUI(AccountController* accountControl)
{
    this->accountControl=accountControl;
    initialize();
    options=5;
    takeCommand(select(options));

}

void ScrapbookUI::drawScreen(int v) {

clear();

// print the instructions for manipulating the Value object
mvprintw(0, 0, "Select type of content to post:");
mvprintw(3, 8, "View Scrapbook");
mvprintw(4, 8, "Post Blog");
mvprintw(5, 8, "Post Tweet");
mvprintw(6, 8, "Export Scrapbook to HTML");
mvprintw(7, 8, "Back");

mvprintw(v+2, 5, "->");

refresh();
}

void ScrapbookUI::takeCommand(int selection){

    // cleanup the window and return control to bash
    endwin();

    if(selection==1)
        displayScrapbook();

   else if(selection==2)
       postBlog();
   else if(selection==3)
       postTweet();
   else if(selection==4)
       makeHTML();
   else if(selection==5)
       return;

   initialize();
   takeCommand(select(options));

}

void ScrapbookUI::postBlog(){
    char text[2000], title[200];
    erase();
    mvprintw(0,0, "New Blog");
    mvprintw(1,0, "Enter Title: ");
    echo();
    getstr(title);


    mvprintw(2,0, "Enter Text: ");
    getstr(text);

    mvprintw(LINES-1,0, "Enter p post private, pressed enter to post public, or hit another key to cancel");
    bool priv=false;
    cbreak();
    noecho();
    int ch= getch();
    if(ch==112 || ch==10){//enter key or p)

    if(ch==112) //p button
        priv=true;

    //make new blog. Set text and path
    accountControl->getUser()->getProfile()->getScrapbook()->addBlog(
                accountControl->getUser()->getUsername(),QString::fromStdString(title),
                QString::fromStdString(text),priv);

    }
}

void ScrapbookUI::postTweet(){
    char text[2000];
    erase();
    mvprintw(0,0,"New Tweet");
    mvprintw(0,0, "Enter Text: ");
    echo();
    getstr(text);
    //Make new tweet. Set text

    mvprintw(LINES-1,0, "Enter p post private, pressed enter to post public, or hit another key to cancel");
    bool priv=false;
    cbreak();
    noecho();
    int ch= getch();
    if(ch==112 || ch==10){//enter key or p)

    if(ch==112) //p button
        priv=true;
    accountControl->getUser()->getProfile()->getScrapbook()->addTweet(
                accountControl->getUser()->getUsername(),
                QString::fromStdString(text),priv);

    }
}

int ScrapbookUI::displayScrapbook(){

    bool booking=true;
    int offset=0;
    int row, max;

    scrapbook = accountControl->getUser()->getProfile()->getScrapbook();

    while(booking){


    std::vector<Post*> wholeScrapbook = scrapbook->getAllPosts();
    erase();
    mvprintw(0,0, "Scrapbook: Select a blog to comment with enter, or hit another key to go back");
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
            if(ch==KEY_DOWN && (*max!=(offset+1)))//ch==258 || KEY_DOWN || !((wholeScrapbook.size()-5)>offset)) //259 and 259 enables scrolling
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



void ScrapbookUI::viewBlog(int index)
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

        std::vector<Post*> wholeScrapbook = scrapbook->getAllPosts();
        erase();
        refresh();
        Blog* currentBlog;
        currentBlog = (Blog*) wholeScrapbook[index];
        //QString *author = new QString(currentBlog->getAuthorUsername() + "'s blog:");
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

void ScrapbookUI::postComment(int blogIndex)
{
    char comment[500];
    mvprintw(LINES-3, 5, "Enter New Comment: ");
    echo();
    getstr(comment);


    //Feed *allFeed = accountControl->getUser()->getFeed();
    //allFeed->updatePostList();
    std::vector<Post*> myBook = scrapbook->getAllPosts();
    erase();
    refresh();
    Blog* currentBlog;
    currentBlog = (Blog*) myBook[blogIndex];

    currentBlog->addComment(accountControl->getUser()->getUsername(), QString::fromStdString(comment));

    noecho();
}

bool ScrapbookUI::checkType(int scrapbookIndex)
{
    std::vector<Post*> wholeScrapbook = scrapbook->getAllPosts();
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

void ScrapbookUI::displayBlog(Blog *blog, int row)
{
    QString currentTitle = "Title: "+blog->getTitle();
    QString currentContent = blog->getContent();
    mvprintw(row, 8,"Blog");
    mvprintw(row+1, 8, currentTitle.toStdString().c_str());
    mvprintw(row+2, 8, currentContent.toStdString().c_str());


}

void ScrapbookUI::displayTweet(Tweet *tweet, int row)
{
    QString currentContent = tweet->getContent();
    mvprintw(row,8,"Tweet");
    mvprintw(row+1, 8, currentContent.toStdString().c_str());

}

void ScrapbookUI::makeHTML(){
    char path[2000];
    erase();
    mvprintw(0,0, "Export to html");
    mvprintw(1,0, "Enter the full path: ");
    echo();
    getstr(path);

    QString pathName(path);
    QString htmlText = accountControl->getUser()->exportToHtml();

    // if user cancels file selection
    if (pathName.isNull()) return;

    QFile file(pathName);
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << htmlText << endl;
    }



}
