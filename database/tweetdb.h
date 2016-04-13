#ifndef TWEETDB_H
#define TWEETDB_H
#include "postdb.h"
#include <vector>

typedef std::tuple<int, int, int, QString, int> TweetInfoType;
/**
 * @brief The TweetDB class
 *
 * Create an sqlite3 table named "Tweets" in a database file.
 * The database structure:
 * Column 1: TweetID INTEGER PRIMARY KEY
 * Column 2: AccountID INTEGER NOT NULL
 * Column 3: ScrapbookID INTEGER NOT NULL
 * Column 4: TweetContent TEXT
 * Column 5: Privacy INTEGER NOT NULL
 */
class TweetDB: public PostDB
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
     * @brief addTweet
     * Add a new Tweet to the database table
     *
     * @param tweetID Tweet ID
     * @param accountID ID of the author
     * @param scrapbookID the ID of the scrapbook that contains the tweet
     * @param tweetContent the content of the tweet.
     * @param privacy The privacy setting of the tweet
     * @return true if added, false if not added
     */
    bool addTweet(int tweetID, int accountID, int scrapbookID, const QString &tweetContent, int privacy);

    /**
     * @brief removeTweet
     * Remove the tweet from database
     *
     * @param id of the removed tweet
     * @return true if succeeded, false if failed
     */
    bool removeTweet(int tweetID);

    /**
     * @brief retrieveTweetInfo get information about the tweet.
     *
     * @param id the id of the tweet
     * @return Return a tuple containing information about the tweet (tweetID, scrapbookID, tweetContent)
     */
    TweetInfoType retrieveTweetInfo(int tweetID);

    /**
     * @brief retrieveAllTweetInfo
     * Retrieve all tweets from a scrapbooik
     * @param scrapbookID The ID of the scrapbook
     * @return A vector of all TweetInfoType tuples containing the data of the Tweet
     */
    std::vector<TweetInfoType> retrieveAllTweetInfo(int scrapbookID);

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

};
#endif // TWEETDB_H
