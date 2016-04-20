#ifndef GROUPDB_H
#define GROUPDB_H

#include <QString>
#include <QtSql>
#include <QDebug>
#include <vector>

/**
 * @brief The GroupDB class
 * Maintain a sqlite3 table "Groups" to store information on groups
 * Column 1: GroupID INTEGER PRIMARY KEY
 * Column 2: ProfileID INTEGER UNIQUE NOT NULL
 */
class GroupDB
{
public:
    /**
     * @brief GroupDB
     *
     * Construct a group database connection at ../database/RocketDB.sqlite
     */
    GroupDB();

    /**
     * @brief GroupDB
     * Construct a group database connection, given the path and the name of the database
     * @param path full path name of the Groupdb
     */
    GroupDB(const QString& path);

    /**
     * @brief ~GroupDB
     *
     * Default destructor for Group database
     */
    ~GroupDB();

    /**
     * @brief isOpen
     *
     * Check whether Group database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;

    /**
     * @brief addGroup
     * Add a group into database
     *
     * @param groupID GroupID of the group
     * @param profileID ProfileID of the profile of the group
     * @return true if added successfully, false otherwise
     */
    bool addGroup(int groupID, int profileID);

    /**
     * @brief getMaxGroupId
     * Get the maximum ID for groups
     *
     * @return the maximum used for groups
     */
    int getMaxGroupID();

    /**
     * @brief getProfileID
     * Retrieve the profile ID from the group ID
     * @param groupID The ID of the group
     * @return The ID of the profile
     */
    int getProfileID(int groupID);

    /**
     * @brief removeAllGroups
     * Remove all groups existing in the database
     * @return true if succeeded, false if failed
     */
    bool removeAllGroups();

private:

    QString connectionName;

};

#endif // GROUPDB_H
