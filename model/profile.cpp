#include "profile.h"

int Profile::idCnt = 0;


Profile::Profile(QString dbPath, QString fullName, QString photo, QString description)
{
    //Find the ID of the profile
    profileDB = new ProfileDB(dbPath, "Scrapbook");
    id = profileDB->getMaxProfileID() + 1;
    idCnt = id;
    idCnt++;

    //input other fields
    this->fullName = fullName;
    this->picturePath = photo;
    this->description = description;

    //Create a new scrapbook that does not possess the same ID
    scrapBook = new Scrapbook(dbPath, profileDB->getMaxScrapbookID() + 1);
}

Profile::Profile(QString dbPath,
                 int id,
                 QString fullName,
                 QString photo,
                 QString description,
                 int scrapbookID)
{
    //Set the ID
    this->id = id;
    idCnt = id;
    idCnt++;

    this->fullName = fullName;
    this->picturePath = photo;
    this->description = description;
    scrapBook = new Scrapbook(dbPath, scrapbookID);
    profileDB = new ProfileDB(dbPath, "Scrapbook");
}

Profile::~Profile()
{
    delete profileDB;
    delete scrapBook;
}


