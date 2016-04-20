#ifndef GROUP_H
#define GROUP_H
#include "../database/groupdb.h"
#include "../database/groupmemberdb.h"
#include "profile.h"
#include <vector>
#include<QString>

class Group
{
public:
    Group();
    Group(int groupID);

private:
    int id;
    static int idCnt;
    Profile* profile;
    std::vector<QString> memberList;
    std::vector<QString> adminList;
};

#endif // GROUP_H
