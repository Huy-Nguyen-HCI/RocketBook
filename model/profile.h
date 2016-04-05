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

    void setDescription(std::string input) : descrition(input) { }
    void setName(std::string input) : name(input)  { }
    void setPicturePath(std::string input) : picturePath(input) { }
private:
    int id;
    static int id_cnt;
    std::string description;
    std::string name;
    std::string picturePath;
    ScrapBook scrapBook;

};

#endif // PROFILE_H
