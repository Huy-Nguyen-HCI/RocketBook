#ifndef TWEETDB_H
#define TWEETDB_H
#include <QString>
#include <QtSql>
#include <QDebug>


/**
 * @brief The TweetDB class
 *
 * Create an sqlite3 table named "Tweets" in a database file.
 * The database structure:
 * Column 1: TweetID INTEGER PRIMARY KEY
 * Column 2: ScrapbookID INTEGER
 * Column 3: TweetContent TEXT
 */
class TweetDB
{
public:
    /**
     * @brief TweetDB
     *
     * Construct a Tweet database at TweetDB.sqlite
     */
    TweetDB();

    /**
     * @brief TweetDB
     * Construct an Tweet database, given the path
     * @param path full path name of the Tweetdb
     */
    TweetDB(const QString& path);

    /**
     * @brief ~TweetDB
     *
     * Default destructor for Tweet database
     */
    ~TweetDB();

    /**
     * @brief isOpen
     *
     * Check whether Tweet database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;

    /**
     * @brief addTweet
     * Add a new Tweet to the database table
     *
     * @param TweetID Tweet ID
     * @param ScrapbookID the ID of the scrapbook that contains the tweet
     * @param tweetContent the content of the tweet.
     * @return true if added, false if not added
     */
    bool addTweet(int tweetID, int scrapbookID, const QString &tweetContent);

    /**
     * @brief removeTweet
     * Remove the tweet from database
     *
     * @param id of the removed tweet
     * @return true if succeeded, false if failed
     */
    bool removeTweet(int id);

    /**
     * @brief retrieveTweetInfo get information about the tweet.
     *
     * @param id the id of the tweet
     * @return Return a tuple containing information about the tweet (tweetID, scrapbookID, tweetContent)
     */
    //QString retrieveTweetInfo(const QString& username, const QString& password);

    /**
     * @brief tweetExists
     * Check if tweet exists, given the id
     *
     * @param id the tweet's id
     * @return true if yes, false if no
     */
    bool tweetExists(int id) const;

    /**
     * @brief removeAllTweets
     * Remove all tweets in the database
     * @return true if succeeded, false if failed
     */
    bool removeAllTweets();


private:
    QSqlDatabase tweetDB;
};
#endif // TWEETDB_H
