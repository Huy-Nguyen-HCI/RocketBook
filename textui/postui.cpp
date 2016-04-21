#include "postui.h"

PostUI::PostUI()
{

    initialize();
    takeCommand(select(4));


}

void PostUI::drawScreen(int v) {

clear();

// print the instructions for manipulating the Value object
mvprintw(0, 0, "Select type of content to post:");
mvprintw(3, 8, "Blog");
mvprintw(4, 8, "Tweet");
mvprintw(5, 8, "Multimedia");
mvprintw(6, 8, "Back");

mvprintw(v+2, 5, "->");

refresh();
}

void PostUI::takeCommand(int selection){

    // cleanup the window and return control to bash
    endwin();

   if(selection==1)
       postBlog();
   else if(selection==2)
       postTweet();
   else if(selection==3)
       postMedia();
   else if(selection==4)
       return;

   initialize();
   takeCommand(select(4));

}

void PostUI::postBlog(){
    char text[2000], path[500];
    erase();
    mvprintw(0,0, "Enter Text: ");
    echo();
    getstr(text);

    erase();
    mvprintw(0,0, "Enter Picture Path: ");
    getstr(path);
    //make new blog. Set text and path

}

void PostUI::postTweet(){
    char text[2000], path[500];
    erase();
    mvprintw(0,0, "Enter Text: ");
    echo();
    getstr(text);
    //Make new tweet. Set text

}

void PostUI::postMedia(){
    char path[500];
    erase();
    mvprintw(0,0, "Enter File Path: ");
    echo();
    getstr(path);
    //Make new multimedia. set path
}
