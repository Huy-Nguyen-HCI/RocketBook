#include "multimedia.h"

Multimedia::Multimedia(QString username,
                       QString title,
                       QString description,
                       QString content): Post(username, content)
{
    this->title = title;
    this->description = description;
    postType = typeMultimedia;
}

Multimedia::Multimedia(int id,
                       QString username,
                       QString title,
                       QString description,
                       QString content): Post(id, username, content)
{
    this->title = title;
    this->description = description;
    postType = typeMultimedia;
}

Multimedia::~Multimedia() {

}

QString Multimedia::getTitle() {
    return title;
}

QString Multimedia::getDescription() {
    return description;
}
