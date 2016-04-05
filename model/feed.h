#ifndef FEED_H
#define FEED_H

#include <vector>
#include "post.h"



class Feed{

public:
    Feed();

private:
    std::vector<Post*>* postList;

};

#endif // FEED_H
