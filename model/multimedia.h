#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include "post.h"



/**
 * @brief The Multimedia Class holds multimedia content which the user has posted.
 */

class Multimedia:public Post{


public:
    Multimedia(QString username,
               QString title,
               QString description,
               QString content);
    Multimedia(int id,
               QString username,
               QString title,
               QString description,
               QString content);

    ~Multimedia();
    QString getTitle();
    QString getDescription();

private:
    QString title;
    QString description;
};

#endif // MULTIMEDIA_H
