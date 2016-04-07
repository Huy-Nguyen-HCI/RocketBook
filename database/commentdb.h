#ifndef COMMENTDB_H
#define COMMENTDB_H

#include <QString>
#include <QtSql>
#include <QDebug>

/**
 * @brief The CommentDB class
 *
 * Create an sqlite3 table named "Accounts" in a database file.
 * The database structure:
 * Column 1: AccountID INTEGER PRIMARY KEY
 * Column 2: Username TEXT UNIQUE
 * Column 3: Password TEXT
 * Column 4: ProfileID INTEGER
 */
class CommentDB
{
public:
    /**
     * @brief CommentDB
     *
     * Construct a comment database at CommentDB.sqlite
     */
    CommentDB();

    /**
     * @brief CommentDB
     * Construct a comment database, given the path
     * @param path full path name of the CommentDB
     */
    CommentDB(const QString& path);

    /**
     * @brief ~CommentDB
     *
     * Default destructor for comment database
     */
    ~CommentDB();

    /**
     * @brief isOpen
     *
     * Check whether account database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;

    /**
     * @brief addComment
     * Add a new account to the database table
     *
     * @param accountID Account ID
     * @param username
     * @param password
     * @param profileID
     * @return true if added, false if not added
     */
    bool addComment(int commentID, int accountID, int blogID, QString content);

    /**
     * @brief removeComment
     * Remove a comment from the database, given the id
     *
     * @param id the comment's id
     * @return true if succeeded, false if failed
     */
    bool removeComment(int id);

    /**
     * @brief retrieveComment
     * Return a string containing information about the comment with the format
     *      "[id] [username] [content]"
     * For example, a possible return is "1 vuh Hello World!"
     *
     * @param id the comment's id.
     * @return a string with the id, username and content, or an empty string if id does not exist.
     */
    QString retrieveCommentInfo(int id);

    /**
     * @brief commentExists
     * Check if comment exists given the id.
     *
     * @param id the input id.
     * @return true if yes, false if no
     */
    bool commentExists(int id) const;

    /**
     * @brief removeAllComments
     * Remove all comments in the database
     * @return true if succeeded, false if failed
     */
    bool removeAllComments();


private:
    QSqlDatabase commentDB;
};


#endif // COMMENTDB_H
