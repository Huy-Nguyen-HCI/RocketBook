#include "blog.h"

Blog::Blog(){

}

void Blog::addComment(Comment* newComment){
    commentList->push_back(newComment);
}

Comment* Blog::getComment(int num){
    return commentList->at(num);
}
