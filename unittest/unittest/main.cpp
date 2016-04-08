#include <iostream>
#include <random>
#include <string>

#include "../gtest/gtest.h"
#include "../../database/accountdb.h"
#include "../../database/profiledb.h"
//#include "../../model/blog.h"
//#include "../../model/comment.h"

using namespace std;


TEST(AccntDatabase, testAddAccnt)
{
    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");
    const QString un3("username3");
    const QString pw3("password3");


    newDB.removeAllAccounts();

    bool added = false;
    int id1 = rand();
    int id2 = rand();
    added = newDB.addAccount(id1, un, pw, 54322);
    newDB.addAccount(id2, un2, pw2, 54321);

    ASSERT_TRUE(added);


    bool allRemoved;

    allRemoved = newDB.removeAllAccounts();

    ASSERT_TRUE(allRemoved);






    //newDB.addaccount();


}

TEST(AccntDatabase, testAccntExists)
{
    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");
    const QString un3("username3");
    const QString pw3("password3");

    newDB.removeAllAccounts();

    int id1 = rand();
    int id2 = rand();

    newDB.addAccount(id1, un, pw, 54322);
    newDB.addAccount(id2, un2, pw2, 54321);

    ASSERT_TRUE(newDB.accountExists(un));
    ASSERT_TRUE(newDB.accountExists(un2));
    ASSERT_FALSE(newDB.accountExists(un3));

    newDB.removeAllAccounts();


}

TEST(AccntDatabase, testRmvAccnt)
{
    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");
    const QString un3("username3");
    const QString pw3("password3");

    newDB.removeAllAccounts();

    int id1 = rand();
    int id2 = rand();

    newDB.addAccount(id1, un, pw, 54322);
    newDB.addAccount(id2, un2, pw2, 54321);
    bool removed;
    removed = newDB.removeAccount(un);
    ASSERT_TRUE(removed);
    ASSERT_FALSE(newDB.accountExists(un));

    newDB.removeAllAccounts();



}

TEST(AccntDatabase, testRmvAll)
{
    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");

    newDB.removeAllAccounts();

    int id1 = rand();
    int id2 = rand();

    newDB.addAccount(id1, un, pw, 54322);
    newDB.addAccount(id2, un2, pw2, 54321);
    bool removed;
    removed = newDB.removeAllAccounts();
    ASSERT_TRUE(removed);
    ASSERT_FALSE(newDB.accountExists(un));



}

TEST(AccntDatabase, testRetrieveInfo)
{

    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");

    newDB.removeAllAccounts();

    int id1 = rand();
    int id2 = rand();

    int pid1 = rand();
    int pid2 = rand();



    newDB.addAccount(id1, un, pw, pid1);
    newDB.addAccount(id2, un2, pw2, pid2);

    string info1 = "";
    info1 = info1 + to_string(id1) + " ";
    info1 = info1 + un.toStdString() + " ";
    info1 = info1 + pw.toStdString() + " ";
    info1 = info1 + to_string(pid1);

    string actualInfo1 = newDB.retrieveAccountInfo(un, pw).toStdString();

    ASSERT_EQ(actualInfo1, info1);

    string info2 = "";
    info2 = info2 + to_string(id2) + " ";
    info2 = info2 + un2.toStdString() + " ";
    info2 = info2 + pw2.toStdString() + " ";
    info2 = info2 + to_string(pid2);

    string actualInfo2 = newDB.retrieveAccountInfo(un2, pw2).toStdString();

    ASSERT_EQ(actualInfo2, info2);






    newDB.removeAllAccounts();



}

// PROFILE DATABASE TESTS /////////////////////////////////////////////////////////



TEST(ProfDatabase, testAddProf)
{
    const QString path("../unittest/testdirec/profiles");
    ProfileDB newPDB(path);
    int pid1 = 1231;
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");

    int pid2 = 1232;
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");


    newPDB.removeAllProfiles();

    bool added = false;
    bool added2 = false;

    added = newPDB.addProfile(pid1, fn, ph, dscr);
    added2 = newPDB.addProfile(pid2, fn2, ph2, dscr2);


    ASSERT_TRUE(added);
    ASSERT_TRUE(added2);



    bool allRemoved;

    newPDB.removeAllProfiles();





}

TEST(ProfDatabase, testProfExists)
{

    const QString path("../unittest/testdirec/profiles");
    ProfileDB newPDB(path);
    int pid1 = 1231;
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");

    int pid2 = 1232;
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");


    newPDB.removeAllProfiles();


    newPDB.addProfile(pid1, fn, ph, dscr);
    newPDB.addProfile(pid2, fn2, ph2, dscr2);


    //ASSERT_TRUE(newPDB.profileExists(pid1));
    //ASSERT_TRUE(newPDB.profileExists(pid2));

    int pid3 = 1233;
    ASSERT_FALSE(newPDB.profileExists(pid3));

    newPDB.removeAllProfiles();



}

TEST(ProfDatabase, testRmvProf)
{
    const QString path("../unittest/testdirec/profiles");
    ProfileDB newPDB(path);
    int pid1 = rand();
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");

    int pid2 = rand();
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");

    int pid3 = rand();
    const QString fn3("fullName3");
    const QString ph3("photo3");
    const QString dscr3("description3");


    newPDB.removeAllProfiles();

    newPDB.addProfile(pid1, fn, ph, dscr);
    newPDB.addProfile(pid2, fn2, ph2, dscr2);

    bool removed1 = false;
    removed1 = newPDB.removeProfile(pid1);
    //ASSERT_TRUE(removed1);
    ASSERT_FALSE(newPDB.profileExists(pid1));
    bool removed2 = false;
    removed2 = newPDB.removeProfile(pid2);
    //ASSERT_TRUE(removed2);
    ASSERT_FALSE(newPDB.profileExists(pid2));

    newPDB.removeAllProfiles();





}




int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);

     return RUN_ALL_TESTS();

}
