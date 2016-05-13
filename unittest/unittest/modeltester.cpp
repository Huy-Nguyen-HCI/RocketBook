#include "modeltester.h"
using namespace std;

TEST(RocketUserTest, testGetID)
{

    const QString dbPath("../unittest/testdirec");
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

TEST(RocketUserTest, testDescription)
{

    const QString dbPath("../unittest/testdirec");
    int id1 = 0;
    const QString un1("username1");
    const QString fn1("fullName1");
    const QString ph1("photo1");
    QString dscr1("description1");
    int id2 = 1;
    const QString un2("username2");
    const QString fn2("fullName2");
    const QString ph2("photo2");
    QString dscr2("description2");

    RocketUser user1(dbPath, id1, un1, fn1, ph1, dscr1);
    ASSERT_EQ(dscr1, user1.getProfile()->getDescription());
    user1.changeProfileDescription(dscr2);
    ASSERT_EQ(dscr2, user1.getProfile()->getDescription());


}

TEST(RocketUserTest, testPhoto)
{

    const QString dbPath("../unittest/testdirec");
    int id1 = 0;
    const QString un1("username1");
    const QString fn1("fullName1");
    const QString ph1("photo1");
    QString dscr1("description1");
    int id2 = 1;
    const QString un2("username2");
    const QString fn2("fullName2");
    const QString ph2("photo2");
    QString dscr2("description2");

    RocketUser user1(dbPath, id1, un1, fn1, ph1, dscr1);
    ASSERT_EQ(ph1, user1.getProfile()->getPicturePath());
    user1.changePhoto(ph2);
    ASSERT_EQ(ph2, user1.getProfile()->getPicturePath());


}

//Profile Tests:

TEST(ProfileTest, testGetProfileID)
{

    const QString dbPath("../unittest/testdirec");
    int id1 = 0;
    const QString fn1("fullName1");
    const QString ph1("photo1");
    const QString dscr1("description1");
    int sid1 = 5;

    Profile prof(dbPath, id1, fn1, ph1, dscr1, sid1);
    ASSERT_EQ(id1, prof.getID());


}

TEST(ProfileTest, testDescription)
{

    const QString dbPath("../unittest/testdirec");
    int id1 = 0;
    const QString fn1("fullName1");
    const QString ph1("photo1");
    const QString dscr1("description1");
    QString dscr2("description2");
    int sid1 = 5;

    Profile prof(dbPath, id1, fn1, ph1, dscr1, sid1);
    ASSERT_EQ(dscr1, prof.getDescription());
    prof.setDescription(dscr2);
    ASSERT_EQ(dscr2, prof.getDescription());
    ASSERT_NE(dscr1, prof.getDescription());


}

TEST(ProfileTest, testFullName)
{


    const QString dbPath("../unittest/testdirec");
    int id1 = 0;
    const QString fn1("fullName1");
    const QString ph1("photo1");
    const QString dscr1("description1");
    QString fn2("full name 2");
    int sid1 = 5;

    Profile prof(dbPath, id1, fn1, ph1, dscr1, sid1);
    ASSERT_EQ(fn1, prof.getFullName());
    prof.setFullName(fn2);
    ASSERT_EQ(fn2, prof.getFullName());
    ASSERT_NE(fn1, prof.getFullName());

}

TEST(ProfileTest, testPicturePath)
{

    const QString dbPath("../unittest/testdirec");
    int id1 = 0;
    const QString fn1("fullName1");
    const QString ph1("photo1");
    const QString dscr1("description1");
    QString ph2("photo 2");
    int sid1 = 5;

    Profile prof(dbPath, id1, fn1, ph1, dscr1, sid1);
    ASSERT_EQ(ph1, prof.getPicturePath());
    prof.setPicturePath(ph2);
    ASSERT_EQ(ph2, prof.getPicturePath());
    ASSERT_NE(ph1, prof.getPicturePath());

}

