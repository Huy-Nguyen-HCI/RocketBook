#include "modeltester.h"
using namespace std;

TEST(RocketUserTest, testGetID)
{

    const QString dbPath("../unittest/testdirec/Profiles");
    int id1 = 0;
    const QString un1("username1");
    const QString fn1("fullName1");
    const QString ph1("photo1");
    const QString dscr1("description1");
    int id2 = 1;
    const QString un2("username2");
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");

    RocketUser user1(dbPath, id1, un1, fn1, ph1, dscr1);
    RocketUser user2(dbPath, id2, un2, fn2, ph2, dscr2);

    ASSERT_EQ(id1, user1.getID());
    ASSERT_EQ(id2, user2.getID());
    ASSERT_NE(id2, user1.getID());
    ASSERT_NE(id1, user2.getID());


}
