#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include "post.h"



/**
 * @brief The Multimedia Class holds multimedia content which the user has posted.
 */

class Multimedia:public Post{


public:
    enum PrivacyType { Private, Public };

    /**
     * @brief Mulimedia constructor for new multimedia post
     * @param username Author of post
     * @return title Title of post
     * @param description Description of post
     * @param content Picture file path
     */
    Multimedia(QString username,
               QString title,
               QString description,
               QString content);
    /**
     * @brief Mulimedia constructor for existing multimedia post
     * @param id Post Id
     * @param username Author of post
     * @return title Title of post
     * @param description Description of post
     * @param content Picture file path
     */
    Multimedia(int id,
               QString username,
               QString title,
               QString description,
               QString content);
    /**
     * @brief Mulimedia destructor
     */
    ~Multimedia();
    /**
     * @brief getTitle
     * @return Title of post
     */
    QString getTitle();
    /**
     * @brief getDescription
     * @return Description of post
     */
    QString getDescription();

private:
    QString title;
    QString description;
};

#endif // MULTIMEDIA_H
