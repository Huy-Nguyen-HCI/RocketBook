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
   else if(selection==4);
    //   makeHTML();
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

    int *max;
    if(wholeScrapbook.size() < 5){
        *max = wholeScrapbook.size();
    }else{
        *max = offset+5;
    }
    for (unsigned int i = offset; i < *max; i++) {
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
                mvprintw(row, 1, "multimedia content!");
                row = row+2;
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
    QString htmlText;

    // set up html code
    htmlText += "<!DOCTYPE html><html>";

    // set title
    htmlText += "<head> <title> My Scrapbook </title> </head>";

    // set header
    htmlText = htmlText + "<h1 style='text-align:center'>" + accountControl->getUser()->getUsername() + "'s Scrapbook" + "</h1>";

    // begin body
    htmlText += "<body>";

    // add profile
    htmlText += profileToHTML();

    // add friend list
    htmlText += friendsToHTML();

    // add content
    htmlText += buildContentHTML();

    // end body
    htmlText += "</body>";

    // end html code
    htmlText += "</html>";

    writeToHTMLFile(htmlText);

}


QString ScrapbookUI::profileToHTML() {

    QString html;
    QString imageStyle = " style='width:200px; height:200pxl; '";
    Profile *profile = accountControl->getUser()->getProfile();

    // add profile image
    html =
            html + "<p style='text-align:center'>" +
            "<img src=" + "'" + profile->getPicturePath() + "'" + imageStyle + ">" +
            "</p>";

    // add description
    html = html + "<h3>" + "<u>My description:</u>" + "</h3>";
    html += profile->getDescription().toHtmlEscaped();
    html += "<br>";
    return html;
}

QString ScrapbookUI::friendsToHTML() {

    QString html;
    QStringList friendList = accountControl->getUser()->controlFriend()->getFriendNames();

    html += "<h3><u>My friends:</u></h3>";

    html += "<ul>";

    for (QString friendName : friendList) {
        html = html + "<li>" + friendName + "</li>";
    }

    html += "</ul>";

    return html;
}

QString ScrapbookUI::buildContentHTML() {

    QString html;
    std::vector<Post*> wholeScrapbook = scrapbook->getAllPosts();

    html += "<h3><u>My posts:</u></h3>";
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

QString ScrapbookUI::blogToHTML(Blog *blog) {

    QString html;

    // add post type
    html += "<b>Blog</b> <br>";

    // add blog title
    html = html + "<u>Title:</u> " + blog->getTitle().toHtmlEscaped() + "<br>";

    // add content
    html = html + "<u>Content:</u> " + blog->getContent().toHtmlEscaped();

    return html;
}

QString ScrapbookUI::tweetToHTML(Tweet *tweet) {

    QString html;

    // add post type
    html += "<b>Tweet</b> <br>";

    // add content
    html = html + "<u>Content:</u> " + tweet->getContent().toHtmlEscaped();

    return html;
}

QString ScrapbookUI::multimediaToHTML(Multimedia *media) {

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

void ScrapbookUI::writeToHTMLFile(QString htmlText) {
    char path[500];

    mvprintw(LINES-2, 5, "Enter file path");

    getstr(path);
    std::string p(path);

    QString fileName = QString::fromStdString(p);
    if (fileName.isNull()) return;

    QFile file(fileName);
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << htmlText << endl;
    }
}
