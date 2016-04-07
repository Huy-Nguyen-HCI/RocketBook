#include "blog.h"

Blog::Blog(int accountID, std::string title, std::string content): Post::Post(accountID, content)
{
    this->title = title;
}

Blog::~Blog() {

}

std::string Blog::getTitle()
{
    return title;
}

void Blog::addComment(Comment* newComment){
    commentList.push_back(newComment);
}

std::vector<Comment*> Blog::getAllComments(){
    return commentList;
}

void Blog::editBlog(std::string newContent) {
    content = newContent;
}
