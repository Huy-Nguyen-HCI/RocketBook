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

    bool addProfile(int profileID, const QString& name, const QString& password, int scrapbookID);

    bool removeProfile(const QString& name);

    bool profileExists(const QString& name) const;

    bool removeAllProfiles();

private:
    QSqlDatabase profileDB;
};

#endif // PROFILEDB_H
