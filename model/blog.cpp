#include "blog.h"

Blog::Blog(QString username, QString title, QString content, QString dbPath): Post::Post(username, content)
{
    this->title = title;
    this->username = username;
    postType = typeBlog;
    this->dbPath = dbPath;
    commentDB = new CommentDB(dbPath);
    accountDB = new AccountDB(dbPath);
}

Blog::Blog(int id, QString username, QString title, QString content, QString dbPath): Post::Post(id, username, content)
{
    this->title = title;
    postType = typeBlog;
    this->dbPath = dbPath;
    commentDB = new CommentDB(dbPath);
    accountDB = new AccountDB(dbPath);
}

Blog::~Blog() {

}

QString Blog::getTitle()
{
    return title;
}

Comment *Blog::addComment(Comment* newComment){
    commentList.push_back(newComment);
    int accountID = accountDB->retrieveAccountID(newComment->getAuthorUsername());
    commentDB->addComment(newComment->getID(),accountID, this->id, newComment->getContent());
    return newComment;
}

Comment* Blog::addComment(QString username, QString content) {
    int commentID = commentDB->getMaxPostID() + 1;
    Comment* newComment = new Comment(commentID, username, content);
    commentList.push_back(newComment);
    commentDB->addComment(commentID,
                          accountDB->retrieveAccountID(username),
                          this->id,
                          content);
    return newComment;
}

std::vector<Comment*> Blog::getAllComments(){
    return commentList;
}

void Blog::editBlog(QString newContent) {
    content = newContent;
}
