#include "blog.h"

Blog::Blog(QString username, QString title, QString content): Post::Post(username, content)
{
    this->title = title;
    this->username = username;
    postType = typeBlog;
}

Blog::Blog(int id, QString username, QString title, QString content): Post::Post(id, username, content)
{
    this->title = title;
    postType = typeBlog;
}

Blog::~Blog() {

}

QString Blog::getTitle()
{
    return title;
}

Comment *Blog::addComment(Comment* newComment){
    commentList.push_back(newComment);
    return newComment;
}

std::vector<Comment*> Blog::getAllComments(){
    return commentList;
}

void Blog::editBlog(QString newContent) {
    content = newContent;
}
