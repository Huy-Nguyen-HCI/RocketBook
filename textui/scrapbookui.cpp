#include "scrapbookui.h"

ScrapbookUI::ScrapbookUI(AccountController* accountControl)
{
    this->accountControl=accountControl;
    initialize();
    options=5;
    takeCommand(select(options));
/**
    int i = 0;

       initscr();

       scrollok(stdscr,TRUE);

       while(1)
       {
           printw("%d - lots and lots of lines flowing down the terminal\n", i);
           ++i;
           refresh();
       }

       endwin();
       getch();
       **/

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

    mvprintw(LINES-1,0, "Enter p to make private: ");
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
    char text[2000], path[500];
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

void ScrapbookUI::postMedia(){
    /**
    char path[500];
    erase();
    mvprintw(0,0, "Enter File Path: ");
    echo();
    getstr(path);
    //Make new multimedia. set path
    **/
}

void ScrapbookUI::displayScrapbook(){

    bool booking=true;
    int offset=0;
     int row;

    scrapbook = accountControl->getUser()->getProfile()->getScrapbook();

    while(booking){
    erase();
    mvprintw(0,0, "Scrapbook");
    row=2;

    std::vector<Post*> wholeScrapbook = scrapbook->getAllPosts();

    for (unsigned int i = offset; i < offset+5; i++) {
        Post* currentPost = wholeScrapbook[i];
        Post::PostType pType = currentPost->type();
    //    scrl(1);
     //   scroll(stdscr);
     //   getch();
        switch (pType) {
            case Post::typeBlog:
                displayBlog((Blog*)currentPost, row);
                row = row+4;
                break;
            case Post::typeTweet:
                displayTweet((Tweet*)currentPost, row);
                row = row+3;
                break;
            case Post::typeMultimedia:
                break;
            case Post::typeComment:
                break;
            case Post::typePost:
                break;
        }
    }

//scrl(number of lines)


    int ch= getch();
        if(ch==KEY_DOWN && !((wholeScrapbook.size())==(5+offset)))//ch==258 || KEY_DOWN || !((wholeScrapbook.size()-5)>offset)) //259 and 259 enables scrolling
            offset++;
        else if(ch==KEY_UP && offset>0)//ch==259 || KEY_UP || offset>0)
            offset--;
        else if(ch==KEY_UP);
        else if(ch==KEY_DOWN);


        else
            booking=false;

    }
}

void ScrapbookUI::displayBlog(Blog *blog, int row)
{
    QString currentTitle = "Title: "+blog->getTitle();
    QString currentContent = blog->getContent();
    mvprintw(row, 1,"Blog");
    mvprintw(row+1, 1, currentTitle.toStdString().c_str());
    mvprintw(row+2, 1, currentContent.toStdString().c_str());


}

void ScrapbookUI::displayTweet(Tweet *tweet, int row)
{
    QString currentContent = tweet->getContent();
    mvprintw(row,1,"Tweet");
    mvprintw(row+1, 1, currentContent.toStdString().c_str());

}

void ScrapbookUI::makeHTML(){

}
