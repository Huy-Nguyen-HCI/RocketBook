#ifndef MULTIMEDIADB_H
#define MULTIMEDIADB_H
#include <QString>
#include <QtSql>
#include <QDebug>


typedef std::tuple<int, int, QString, QString, QString> MultimediaInfoType;
/**
 * @brief The MultimediaDB class
 *
 * Create an sqlite3 table named "Multimedia" in a database file.
 * The database structure:
 * Column 1: MultimediaID INTEGER PRIMARY KEY
 * Column 2: ScrapbookID INTEGER
 * Column 3: MultimediaTitle TEXT
 * Column 4: MultimediaDescription TEXT
 * Column 5: MultimediaContent TEXT
 */
class MultimediaDB
{
public:
    /**
     * @brief MultimediaDB
     *
     * Construct a Multimedia database at MultimediaDB.sqlite
     */
    MultimediaDB();

    /**
     * @brief MultimediaDB
     * Construct a Multimedia database, given the path
     * @param path full path name of the MultimediaDB
     */
    MultimediaDB(const QString& path);

    /**
     * @brief ~MultimediaDB
     *
     * Default destructor for Multimedia database
     */
    ~MultimediaDB();

    /**
     * @brief isOpen
     *
     * Check whether multimedia database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;

    /**
     * @brief addMultimedia
     * Add a new account to the database table
     *
     * @param accountID Account ID
     * @param username
     * @param password
     * @param profileID
     * @return true if added, false if not added
     */
    bool addMultimedia(int multimediaID, int scrapbookID, const QString &multimediaTitle, const QString &multimediaDescription, const QString &multimediaContent);

    /**
     * @brief removeMultimedia
     * Remove a Multimedia from the database, given the id
     *
     * @param id the Multimedia's id
     * @return true if succeeded, false if failed
     */
    bool removeMultimedia(int id);

    /**
     * @brief retrieveMultimedia
     * Return a tuple containing information about the multimedia content
     *      (multimediaID, scrapbookID, multimediaTitle, multimediaDescription, multimediaContent)
     * For example, a possible return is "1 vuh Hello World!"
     *
     * @param id the Multimedia's id.
     * @return a string with the id, username and content, or an empty string if id does not exist.
     */
    MultimediaInfoType retrieveMultimediaInfo(int id);

    /**
     * @brief MultimediaExists
     * Check if Multimedia exists given the id.
     *
     * @param id the input id.
     * @return true if yes, false if no
     */
    bool multimediaExists(int id) const;

    /**
     * @brief removeAllMultimedias
     * Remove all Multimedias in the database
     * @return true if succeeded, false if failed
     */
    bool removeAllMultimedias();


private:
    QSqlDatabase multimediaDB;
};

#endif // MULTIMEDIADB_H
