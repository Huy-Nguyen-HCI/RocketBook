
#include "rocketuser.h"



int RocketUser::idCnt = 0;



RocketUser::RocketUser(QString dbPath,
                       int id,
                       QString username,
                       QString fullName,
                       QString photo,
                       QString description,
                       int adminRights)
{
    this->id = id;
    idCnt = id;
    idCnt++;
    this->username = username;
    this->adminRights = adminRights;

    profileDB = new ProfileDB (dbPath);
    accountDB = new AccountDB(dbPath);
    profile = new Profile(dbPath, fullName, photo, description);
    profileDB->addProfile(profile->getID(),
                          profile->getFullName(),
                          profile->getPicturePath(),
                          profile->getDescription(),
                          profile->getScrapbook()->getID());
    groupController = new GroupController(dbPath, id);
    friendController = new FriendController(dbPath, id);
    chatController= new ChatController(dbPath, id);
    feed = new Feed(dbPath, friendController, groupController);

}

RocketUser::RocketUser(QString dbPath,
                       int id,
                       QString username,
                       int profileID,
                       int adminRights = 0)
{
    this->id = id;
    idCnt = id;
    idCnt++;
    this->username = username;
    this->adminRights = adminRights;
    profileDB = new ProfileDB (dbPath);
    accountDB = new AccountDB(dbPath);


    if (profileDB->profileExists(profileID)) {
        ProfileInfoType profileInfo = profileDB->retrieveProfileInfo(profileID);

        QString fullName = std::get<1>(profileInfo);
        QString photo = std::get<2>(profileInfo);
        QString description = std::get<3>(profileInfo);
        int scrapbookID = std::get<4>(profileInfo);
        profile = new Profile(dbPath, profileID, fullName, photo, description, scrapbookID);
    } else {
        //qDebug() << "Profile does not exists.";
    }

    groupController = new GroupController(dbPath, id);
    friendController = new FriendController(dbPath, id);
    chatController= new ChatController(dbPath, id);
    feed = new Feed(dbPath, friendController, groupController);
}

RocketUser::~RocketUser() {
    delete profile;
    delete friendController;
    delete groupController;
    delete chatController;
    delete feed;
    delete profileDB;
    delete accountDB;
}

Profile* RocketUser::getProfile(){
    return profile;
}

bool RocketUser::changeProfileDescription(QString description){
    profile->setDescription(description);
    return profileDB->changeDescription(profile->getID(), description);
}

bool RocketUser::changePhoto(QString path) {
    profile->setPicturePath(path);
    return profileDB->changePhoto(profile->getID(), path);
}

ChatController* RocketUser::getChatController(){
    return chatController;
}


QString RocketUser::exportToHtml()
{
    QString htmlText;
    QString backgroundImagePath =  QDir::currentPath() + "/rocketbackground.gif";

    // set up html code
    htmlText += "<!DOCTYPE html><html>";

    // set title
    htmlText += "<head> <title> My RocketUser </title> </head>";

    // set header
    htmlText = htmlText + "<h1 style='text-align:center'>" + username + "'s RocketUser" + "</h1>";

    // begin body
    htmlText = htmlText + "<body text='orange'" + " background='" + backgroundImagePath + "'>";

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

    return htmlText;
}

QString RocketUser::buildContentHTML() {

    QString html;
    std::vector<Post*> wholeRocketUser = profile->getScrapbook()->getAllPublicPosts();

    html += "<h3><u><font color='white'>My posts:</font></u></h3>";
    // begin list
    html += "<ol>";

    // build list
    for (unsigned int i = 0; i < wholeRocketUser.size(); i++) {
        Post* currentPost = wholeRocketUser[i];
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

QString RocketUser::blogToHTML(Blog *blog) {

    QString html;

    // add post type
    html += "<b>Blog</b> <br>";

    // add blog title
    html = html + "<u>Title:</u> " + blog->getTitle().toHtmlEscaped() + "<br>";

    // add content
    html = html + "<u>Content:</u> " + blog->getContent().toHtmlEscaped();

    return html;
}

QString RocketUser::tweetToHTML(Tweet *tweet) {

    QString html;

    // add post type
    html += "<b>Tweet</b> <br>";

    // add content
    html = html + "<u>Content:</u> " + tweet->getContent().toHtmlEscaped();

    return html;
}

QString RocketUser::multimediaToHTML(Multimedia *media) {

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

QString RocketUser::profileToHTML() {

    QString html;
    QString imageStyle = " style='width:300px; height:300pxl; '";

    // add profile image
    html =
            html + "<p style='text-align:center'>" +
            "<img border='5' src=" + "'" + profile->getPicturePath() + "'" + imageStyle + ">" +
            "</p>";

    // add description
    html = html + "<h3>" + "<u><font color='white'>My description:</font></u>" + "</h3>";
    html += profile->getDescription().toHtmlEscaped();
    html += "<br>";
    return html;
}


QString RocketUser::friendsToHTML() {

    QString html;
    QStringList friendList = friendController->getFriendNames();

    html += "<h3><u><font color='white'>My friends:</font></u></h3>";

    html += "<ul>";

    for (QString friendName : friendList) {
        html = html + "<li>" + friendName + "</li>";
    }

    html += "</ul>";

    return html;
}
