#include "blog.h"

Blog::Blog(QString username, QString title, QString content): Post::Post(username, content)
{
    this->title = title;
}

Blog::Blog(int id, QString username, QString title, QString content): Post::Post(id, username, content)
{
    this->title = title;
}

Blog::~Blog() {

}

QString Blog::getTitle()
{
    return title;
}

void Blog::addComment(Comment* newComment){
    commentList.push_back(newComment);
}

std::vector<Comment*> Blog::getAllComments(){
    return commentList;
}

void Blog::editBlog(QString newContent) {
    content = newContent;
}
