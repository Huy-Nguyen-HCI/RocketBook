#ifndef PROFILEDB_H
#define PROFILEDB_H
#include <QString>
#include <QtSql>
#include <QDebug>

typedef std::tuple<int, QString, QString, QString, int> ProfileInfoType;
/**
 * @brief The ProfileDB class
 *
 * Create an sqlite3 table in a database file.
 * The database structure:
 * Column 1: ProfileID INTEGER PRIMARY KEY
 * Column 2: FullName TEXT
 * Column 3: Photo TEXT
 * Column 4: Description TEXT
 * Column 5: ScrapbookID INTEGER UNIQUE
 */
class ProfileDB
{
public:
    /**
     * @brief ProfileDB
     * Construct a profile database at ../database/profileDB.sqlite
     */
    ProfileDB();

    /**
     * @brief ProfileDB
     * Construct a profile database, given the path and the name of the database
     * @param path full path name of the ProfileDB
     */
    ProfileDB(const QString& path);

    ProfileDB(const QString &path, QString connectionName);

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
     * @param scrapbookID
     * @return true if added, false if not added
     */
    bool addProfile(int profileID, const QString &fullName, const QString &photo, const QString &description, int scrapbookID);

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
    ProfileInfoType retrieveProfileInfo(int profileID);

    /**
     * @brief retrieveFullname
     * Return the full name stored in the profile
     *
     * @param profileID the ID of the profile retrieved
     * @return a string representing the full name of the profile; return "" if the profile does not exist.
     */
    QString retrieveFullname (int profileID);

    /**
     * @brief retrievePhoto
     * Return the photo stored in the profile
     *
     * @param profileID the ID of the profile retrieved
     * @return a string representing the photo of the profile; return "" if the profile does not exist.
     */
    QString retrievePhoto (int profileID);

    /**
     * @brief retrieveDescription
     * Return the description stored in the profile
     *
     * @param profileID the ID of the profile retrieved
     * @return a string representing the description of the profile; return "" if the profile does not exist.
     */
    QString retrieveDescription (int profileID);

    int retrieveScrapbookID(int profileID);

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

    /**
     * @brief getMaxProfileID
     * Get the maximum ID used for profile
     * @return the maximum ID used for profile
     */
    int getMaxProfileID();

    /**
     * @brief getMaxScrapbookID
     * Get the maximum ID used for scrapbook
     * @return the maximum ID used for scrapbook
     */
    int getMaxScrapbookID();

    /**
     * @brief changePhoto
     * Changes profile photo
     * @param profileID Id of profile
     * @param path Picture path
     * @return the maximum ID used for scrapbook
     */
    bool changePhoto(int profileID, QString path);

    /**
     * @brief changeDescription
     * Changes profile description
     * @param profileID Id of profile
     * @param description New description
     * @return the maximum ID used for scrapbook
     */
    bool changeDescription(int profileID, QString description);

private:
    QString connectionName;
};

#endif // PROFILEDB_H
