#include "profile.h"

int Profile::idCnt = 0;


Profile::Profile(QString fullName, QString photo, QString description)
{
    //Find the ID of the profile
    profileDB = new ProfileDB("../database/profileDB.sqlite", "Scrapbook");
    id = profileDB->getMaxProfileID() + 1;
    idCnt = id;
    idCnt++;

    //input other fields
    this->fullName = fullName;
    this->picturePath = photo;
    this->description = description;

    //Create a new scrapbook that does not possess the same ID
    scrapBook = new Scrapbook(profileDB->getMaxScrapbookID() + 1);
}

Profile::Profile(int id,
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
    scrapBook = new Scrapbook(id);
}



