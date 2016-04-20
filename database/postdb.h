#ifndef POSTDB_H
#define POSTDB_H
#include <QString>
#include <QtSql>
#include <QDebug>

/**
 * @brief The PostDB class
 */
class PostDB
{
public:

    /**
     * @brief isOpen
     * Check whether Blog database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;

    /**
     * @brief getMaxPostID
     * Get the max post ID
     * @return the max post ID
     */
    int getMaxPostID();
protected:
    QString connectionName;

};

#endif // POSTDB_H
