#ifndef PROFILEDB_H
#define PROFILEDB_H
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>

class ProfileDB
{
public:
    ProfileDB();
    ProfileDB(const QString& path);

    ~ProfileDB();

    bool isOpen() const;

    bool addProfile(int profileID, const QString& userName, const QString& password, int scrapbookID);

    bool removeProfile(const QString& userName);

    bool profileExists(const QString& userName) const;

    bool removeAllProfiles();

private:
    QSqlDatabase profileDB;
};

#endif // PROFILEDB_H
