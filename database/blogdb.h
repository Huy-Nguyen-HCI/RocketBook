#ifndef BLOGDB_H
#define BLOGDB_H

#include <vector>
#include "postdb.h"

typedef std::tuple<int, int, int, QString, QString, int> BlogInfoType;

/**
 * @brief The BlogDB class
 *
 * Create an sqlite3 table named "Blogs" in a database file.
 * The database structure:
 * Column 1: BlogID INTEGER PRIMARY KEY
 * Column 2: AccountID INTEGER NOT NULL
 * Column 3: ScrapbookID INTEGER NOT NULL
 * Column 4: BlogTitle TEXT
 * Column 5: BlogContent TEXT
 * Column 6: Privacy INTEGER NOT NULL
 */
class BlogDB: public PostDB
{
public:
    /**
     * @brief BlogDB
     * Construct a Blog database at BlogDB.sqlite
     */
    BlogDB();

    /**
     * @brief BlogDB
     * Construct an Blog database, given the path
     * @param path full path name of the Blogdb
     */
    BlogDB(const QString& path);

    /**
     * @brief ~BlogDB
     * Default destructor for Blog database
     */
    ~BlogDB();

    /**
     * @brief addBlog
     * Add a new Blog to the database table
     *
     * @param blogID Blog ID
     * @param accountID The ID of the author
     * @param scrapbookID the ID of the scrapbook that contains the blog
     * @param blogContent the content of the blog.
     * @param privacy the privacy setting of the blog
     * @return true if added, false if not added
     */
    bool addBlog(int blogID,
                 int accountID,
                 int scrapbookID,
                 const QString &blogTitle,
                 const QString &blogContent,
                 int privacy);

    /**
     * @brief removeBlog
     * Remove the blog from database
     *
     * @param id of the removed blog
     * @return true if succeeded, false if failed
     */
    bool removeBlog(int id);

    /**
     * @brief retrieveBlogInfo
     * Get information about the blog.
     *
     * @param id the id of the blog
     * @return Return a tuple containing information about the blog (blogID, scrapbookID, blogContent)
     */
    BlogInfoType retrieveBlogInfo(int blogID);

    /**
     * @brief retrieveAllBlogInfo
     * Retrieve all blogs from a scrapbooik
     * @param scrapbookID The ID of the scrapbook
     * @return A vector of all BlogInfoType tuples containing the data of the blog
     */
    std::vector<BlogInfoType> retrieveAllBlogInfo(int scrapbookID);

    /**
     * @brief blogExists
     * Check if blog exists, given the id
     *
     * @param id the blog's id
     * @return true if yes, false if no
     */
    bool blogExists(int id) const;

    /**
     * @brief removeAllBlogs
     * Remove all blogs in the database
     * @return true if succeeded, false if failed
     */
    bool removeAllBlogs();


private:
};

#endif // BLOGDB_H
