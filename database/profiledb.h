#ifndef PROFILEDB_H
#define PROFILEDB_H
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>

/**
 * @brief The ProfileDB class
 *
 * Create an sqlite3 table in a database file.
 * The database structure:
 * Column 1: profileid INTEGER PRIMARY KEY
 * Column 2: fullname TEXT
 * Column 3: photo TEXT
 * Column 4: description TEXT
 */
class ProfileDB
{
public:
    /**
     * @brief ProfileDB
     *
     * Construct a profile database at ../database/profiledb.sqlite
     */
    ProfileDB();

    /**
     * @brief ProfileDB
     * Construct a profile database, given the path and the name of the database
     * @param path full path name of the ProfileDB
     */
    ProfileDB(const QString& path);

    /**
     * @brief ~ProfileDB
     *
     * Default destructor for profile database
     */
    ~ProfileDB();

    /**
     * @brief isOpen
     *
     * Check whether profile database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;

    /**
     * @brief addProfile
     * Add a new profile to the database table
     *
     * @param profileID profile ID
     * @param fullName
     * @param photo
     * @param description
     * @return true if added, false if not added
     */
    bool addProfile(int profileID, const QString &fullName, const QString &photo, const QString &description);

    /**
     * @brief removeProfile
     * Remove an entire profile from the database, knowing the profileID
     *
     * @param profileID the ID of the profile removed
     * @return true if succeeded, false if failed
     */
    bool removeProfile(int profileID);

    /**
     * @brief retrieveProfileInfo
     * Return a string including details of the profile, knowing the profile ID, separated by a comma
     * For example, a possible return is "1, Ha Vu, havu.jpg, I am a student"
     *
     * @param profileID the ID of the profile retrieved
     * @return a string with profileid, fullname, photo, description; return "" if the profile does not exist.
     */
    QString retrieveProfileInfo(int profileID);

    /**
     * @brief profileExists
     * Check if profile exists, knowing the profile ID
     *
     * @param profileID the profile ID
     * @return true if yes, false if no
     */
    bool profileExists(int profileID) const;

    /**
     * @brief removeAllProfiles
     * Remove all profiles existed in the database
     * @return true if succeeded, false if failed
     */
    bool removeAllProfiles();


private:
    QSqlDatabase profileDB;
};

#endif // PROFILEDB_H
