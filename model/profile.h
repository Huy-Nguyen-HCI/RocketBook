#ifndef PROFILE_H
#define PROFILE_H
#include <string>
#include "scrapbook.h"

/**
 * @brief The Profile class stores information about a user's profile:
 *      Picture
 *      Description
 *      Name
 *      Scrapbook
 */

class Profile
{
public:
    Profile();
    int getID() { return id; }
    std::string getDescription() { return description; }
    std::string getName() { return name; }
    std::string getPicturePath() { return picturePath; }

private:
    int id;
    static int id_cnt;
    std::string description;
    std::string name;
    std::string picturePath;
    ScrapBook scrapBook;

};

#endif // PROFILE_H
