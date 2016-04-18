#include "../../database/accountdb.h"
#include "../../database/profiledb.h"
#include "../../database/frienddb.h"
#include "../../database/commentdb.h"
#include "../../database/tweetdb.h"
#include "../../database/multimediadb.h"
#include "../../database/blogdb.h"
#include "../gtest/gtest.h"

#include <iostream>
#include <random>
#include <string>
using namespace std;


TEST(AccntDatabase, testAddAccnt)
{
    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");




    newDB.removeAllAccounts();

    bool added = false;
    int id1 = rand();
    int id2 = rand();
    int adminrights1 = 4;
    int adminrights2 = 5;
    added = newDB.addAccount(id1, un, pw, 54322, adminrights1);
    newDB.addAccount(id2, un2, pw2, 54321, adminrights2);

    ASSERT_TRUE(added);


    bool allRemoved;

    allRemoved = newDB.removeAllAccounts();

    ASSERT_TRUE(allRemoved);



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
    int adminrights1 = 4;
    int adminrights2 = 5;

    newDB.addAccount(id1, un, pw, 54322, adminrights1);
    newDB.addAccount(id2, un2, pw2, 54321, adminrights2);

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
    int adminrights1 = 4;
    int adminrights2 = 5;

    newDB.addAccount(id1, un, pw, 54322, adminrights1);
    newDB.addAccount(id2, un2, pw2, 54321, adminrights2);
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
    int adminrights1 = 4;
    int adminrights2 = 5;

    newDB.addAccount(id1, un, pw, 54322, adminrights1);
    newDB.addAccount(id2, un2, pw2, 54321, adminrights2);
    bool removed;
    removed = newDB.removeAllAccounts();
    ASSERT_TRUE(removed);
    ASSERT_FALSE(newDB.accountExists(un));



}

TEST(AccntDatabase, testRetrieveAccntID)
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
    int adminrights1 = 4;
    int adminrights2 = 5;




    newDB.addAccount(id1, un, pw, pid1, adminrights1);
    newDB.addAccount(id2, un2, pw2, pid2, adminrights2);

    int actualID1 = newDB.retrieveAccountID(un);

    ASSERT_EQ(actualID1, id1);

    int actualID2 = newDB.retrieveAccountID(un2);

    ASSERT_EQ(actualID2, id2);


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

    int adminrights1 = 4;
    int adminrights2 = 5;



    newDB.addAccount(id1, un, pw, pid1, adminrights1);
    newDB.addAccount(id2, un2, pw2, pid2, adminrights2);

    string info1 = "";
    info1 = info1 + to_string(id1) + " ";
    info1 = info1 + un.toStdString() + " ";
    info1 = info1 + pw.toStdString() + " ";
    info1 = info1 + to_string(pid1) + " ";
    info1 = info1 + to_string(adminrights1);

    std::tuple<int,QString,QString,int, int> actualInfo1 =
            newDB.retrieveAccountInfo(un);

    ASSERT_EQ (std::get<0>(actualInfo1), id1);
    ASSERT_EQ (std::get<1>(actualInfo1), un);
    ASSERT_EQ (std::get<2>(actualInfo1), pw);
    ASSERT_EQ (std::get<3>(actualInfo1), pid1);



    std::tuple<int,QString,QString,int, int> actualInfo2 =
            newDB.retrieveAccountInfo(un2);

    ASSERT_EQ (std::get<0>(actualInfo2), id2);
    ASSERT_EQ (std::get<1>(actualInfo2), un2);
    ASSERT_EQ (std::get<2>(actualInfo2), pw2);
    ASSERT_EQ (std::get<3>(actualInfo2), pid2);

    newDB.removeAllAccounts();


}

// PROFILE DATABASE TESTS /////////////////////////////////////////////////////////



TEST(ProfDatabase, testAddProf)
{
    const QString path("../unittest/testdirec/Profiles");
    ProfileDB newPDB(path);
    int pid1 = 1231;
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");
    int sid1 = 231;

    int pid2 = 1232;
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");
    int sid2 = 232;

    newPDB.removeAllProfiles();

    bool added = false;
    bool added2 = false;

    added = newPDB.addProfile(pid1, fn, ph, dscr, sid1);
    added2 = newPDB.addProfile(pid2, fn2, ph2, dscr2, sid2);


    ASSERT_TRUE(added);
    ASSERT_TRUE(added2);


    newPDB.removeAllProfiles();
}

TEST(ProfDatabase, testProfExists)
{

    const QString path("../unittest/testdirec/Profiles");
    ProfileDB newPDB(path);
    int pid1 = 1231;
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");
    int sid1 = 231;

    int pid2 = 1232;
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");
    int sid2 = 232;


    newPDB.removeAllProfiles();


    newPDB.addProfile(pid1, fn, ph, dscr, sid1);
    newPDB.addProfile(pid2, fn2, ph2, dscr2, sid2);


    ASSERT_TRUE(newPDB.profileExists(pid1));
    ASSERT_TRUE(newPDB.profileExists(pid2));

    int pid3 = 1233;
    ASSERT_FALSE(newPDB.profileExists(pid3));

    newPDB.removeAllProfiles();
}

TEST(ProfDatabase, testRmvProf)
{
    const QString path("../unittest/testdirec/Profiles");
    ProfileDB newPDB(path);
    int pid1 = rand();
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");
    int sid1 = 231;

    int pid2 = 1232;
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");
    int sid2 = 232;

    int pid3 = rand();
    const QString fn3("fullName3");
    const QString ph3("photo3");
    const QString dscr3("description3");


    newPDB.removeAllProfiles();

    newPDB.addProfile(pid1, fn, ph, dscr, sid1);
    newPDB.addProfile(pid2, fn2, ph2, dscr2, sid2);

    bool removed1 = false;
    removed1 = newPDB.removeProfile(pid1);
    ASSERT_TRUE(removed1);
    ASSERT_FALSE(newPDB.profileExists(pid1));
    bool removed2 = false;
    removed2 = newPDB.removeProfile(pid2);
    ASSERT_TRUE(removed2);
    ASSERT_FALSE(newPDB.profileExists(pid2));

    newPDB.removeAllProfiles();
}

TEST(ProfDatabase, testRmvAllProf)
{
    const QString path("../unittest/testdirec/Profiles");
    ProfileDB newPDB(path);
    int pid1 = rand();
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");
    int sid1 = 231;

    int pid2 = 1232;
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");
    int sid2 = 232;

    int pid3 = rand();
    const QString fn3("fullName3");
    const QString ph3("photo3");
    const QString dscr3("description3");


    newPDB.removeAllProfiles();

    newPDB.addProfile(pid1, fn, ph, dscr, sid1);
    newPDB.addProfile(pid2, fn2, ph2, dscr2, sid2);

    ASSERT_TRUE(newPDB.profileExists(pid1));
    ASSERT_TRUE(newPDB.profileExists(pid2));

    bool allRmv = false;
    allRmv = newPDB.removeAllProfiles();
    ASSERT_TRUE(allRmv);
    ASSERT_FALSE(newPDB.profileExists(pid1));
    ASSERT_FALSE(newPDB.profileExists(pid2));


}

TEST(ProfDatabase, testRetrieveInfo)
{
    const QString path("../unittest/testdirec/Profiles");
    ProfileDB newPDB(path);
    int pid1 = rand();
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");
    int sid1 = 231;

    int pid2 = 1232;
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");
    int sid2 = 232;

    newPDB.removeAllProfiles();

    newPDB.addProfile(pid1, fn, ph, dscr, sid1);
    newPDB.addProfile(pid2, fn2, ph2, dscr2, sid2);

    ProfileInfoType info = newPDB.retrieveProfileInfo(pid1);
    ASSERT_EQ (std::get<0>(info), pid1);
    ASSERT_EQ (std::get<1>(info), fn);
    ASSERT_EQ (std::get<2>(info), ph);
    ASSERT_EQ (std::get<3>(info), dscr);


    ProfileInfoType info2 = newPDB.retrieveProfileInfo(pid2);
    ASSERT_EQ (std::get<0>(info2), pid2);
    ASSERT_EQ (std::get<1>(info2), fn2);
    ASSERT_EQ (std::get<2>(info2), ph2);
    ASSERT_EQ (std::get<3>(info2), dscr2);

}

TEST(ProfDatabase, testRetrieveFullName)
{
    const QString path("../unittest/testdirec/Profiles");
    ProfileDB newPDB(path);
    int pid1 = rand();
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");
    int sid1 = rand();

    int pid2 = rand();
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");
    int sid2 = rand();

    newPDB.removeAllProfiles();

    newPDB.addProfile(pid1, fn, ph, dscr, sid1);
    newPDB.addProfile(pid2, fn2, ph2, dscr2, sid2);

    string actualFN1 = newPDB.retrieveFullname(pid1).toStdString();
    string expectedFN1 = fn.toStdString();
    ASSERT_EQ(expectedFN1, actualFN1);

}

TEST(ProfDatabase, testRetrievePhoto)
{
    const QString path("../unittest/testdirec/Profiles");
    ProfileDB newPDB(path);
    int pid1 = rand();
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");
    int sid1 = rand();

    int pid2 = rand();
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");
    int sid2 = rand();

    newPDB.removeAllProfiles();

    newPDB.addProfile(pid1, fn, ph, dscr, sid1);
    newPDB.addProfile(pid2, fn2, ph2, dscr2, sid2);

    string actualPh1 = newPDB.retrievePhoto(pid1).toStdString();
    string expectedPh1 = ph.toStdString();
    ASSERT_EQ(expectedPh1, actualPh1);

    string actualPh2 = newPDB.retrievePhoto(pid2).toStdString();
    string expectedPh2 = ph2.toStdString();
    ASSERT_EQ(expectedPh2, actualPh2);

}

//Comment DB Tests:

TEST(CommentDatabase, testAddComments)
{
    const QString path("../unittest/testdirec/testContentDB");
    CommentDB newCDB(path);
    int cid1 = 4;
    int aid1 = 5;
    int bid1 = 7;
    const QString content("content");
    int cid2 = 14;
    int aid2 = 15;
    int bid2 = 17;
    const QString content2("content2");

    newCDB.removeAllComments();
    bool added = false;
    added = newCDB.addComment(cid1, aid1, bid1, content);
    ASSERT_TRUE(added);
    bool added2 = false;
    added2 = newCDB.addComment(cid2, aid2, bid2, content2);
    ASSERT_TRUE(added2);



    newCDB.removeAllComments();



}

TEST(CommentDatabase, testCommentExists)
{
    const QString path("../unittest/testdirec/testContentDB");
    CommentDB newCDB(path);
    int cid1 = 4;
    int aid1 = 5;
    int bid1 = 7;
    const QString content("content");
    int cid2 = 14;
    int aid2 = 15;
    int bid2 = 17;
    const QString content2("content2");
    newCDB.removeAllComments();

    ASSERT_FALSE(newCDB.commentExists(cid1));
    ASSERT_FALSE(newCDB.commentExists(cid2));
    newCDB.removeAllComments();
    newCDB.addComment(cid1, aid1, bid1, content);
    ASSERT_TRUE(newCDB.commentExists(cid1));
    newCDB.addComment(cid2, aid2, bid2, content2);
    ASSERT_TRUE(newCDB.commentExists(cid2));



    newCDB.removeAllComments();



}

TEST(CommentDatabase, testRmvComments)
{
    const QString path("../unittest/testdirec/testContentDB");
    CommentDB newCDB(path);
    int cid1 = 4;
    int aid1 = 5;
    int bid1 = 7;
    const QString content("content");
    int cid2 = 14;
    int aid2 = 15;
    int bid2 = 17;
    const QString content2("content2");

    newCDB.removeAllComments();
    bool added = false;
    added = newCDB.addComment(cid1, aid1, bid1, content);
    ASSERT_TRUE(added);
    bool added2 = false;
    added2 = newCDB.addComment(cid2, aid2, bid2, content2);
    ASSERT_TRUE(added2);
    newCDB.removeComment(cid1);
    ASSERT_FALSE(newCDB.commentExists(cid1));



    newCDB.removeAllComments();



}

TEST(CommentDatabase, testRmvAllComments)
{
    const QString path("../unittest/testdirec/testContentDB");
    CommentDB newCDB(path);
    int cid1 = 4;
    int aid1 = 5;
    int bid1 = 7;
    const QString content("content");
    int cid2 = 14;
    int aid2 = 15;
    int bid2 = 17;
    const QString content2("content2");

    newCDB.removeAllComments();
    bool added = false;
    added = newCDB.addComment(cid1, aid1, bid1, content);
    ASSERT_TRUE(added);
    bool added2 = false;
    added2 = newCDB.addComment(cid2, aid2, bid2, content2);
    ASSERT_TRUE(added2);
    newCDB.removeAllComments();
    ASSERT_FALSE(newCDB.commentExists(cid1));
    ASSERT_FALSE(newCDB.commentExists(cid2));

    newCDB.removeAllComments();

}

TEST(CommentDatabase, testRetrieveInfo)
{
    const QString path("../unittest/testdirec/testContentDB");
    CommentDB newCDB(path);
    int cid1 = 4;
    int aid1 = 5;
    int bid1 = 7;
    const QString content("content");
    int cid2 = 14;
    int aid2 = 15;
    int bid2 = 17;
    const QString content2("content2");

    newCDB.removeAllComments();
    newCDB.addComment(cid1, aid1, bid1, content);
    newCDB.addComment(cid2, aid2, bid2, content2);


    std::tuple<int,int,int,QString> actualInfo1 =
            newCDB.retrieveCommentInfo(cid1);

    ASSERT_EQ (std::get<0>(actualInfo1), cid1);
    //ASSERT_EQ (std::get<1>(actualInfo1), aid1);
    //ASSERT_EQ (std::get<2>(actualInfo1), bid1);
    ASSERT_EQ (std::get<3>(actualInfo1), content);

}


//FRIEND DB TESTS//

TEST(FriendDatabase, testAddFriends)
{
    const QString path("../unittest/testdirec/friends");
    FriendDB newFDB(path);
    int accntid = 1;
    int friendid = 2;
    int accntid2 = 11;
    int friendid2 = 12;

    newFDB.removeAllFriends();

    bool added = false;
    added = newFDB.addFriend(accntid, friendid);
    ASSERT_TRUE(added);
    bool added2 = false;
    added2 = newFDB.addFriend(accntid2, friendid2);
    ASSERT_TRUE(added2);

    newFDB.removeAllFriends();



}

TEST(FriendDatabase, testFriendshipExists)
{
    const QString path("../unittest/testdirec/friends");
    FriendDB newFDB(path);
    int accntid = 1;
    int friendid = 2;
    int accntid2 = 11;
    int friendid2 = 12;

    newFDB.removeAllFriends();

    ASSERT_FALSE(newFDB.friendshipExists(accntid, friendid));
    ASSERT_FALSE(newFDB.friendshipExists(accntid2, friendid2));


    newFDB.addFriend(accntid, friendid);
    newFDB.addFriend(accntid2, friendid2);
    ASSERT_TRUE(newFDB.friendshipExists(accntid, friendid));
    ASSERT_TRUE(newFDB.friendshipExists(accntid2, friendid2));

    newFDB.removeAllFriends();



}

TEST(FriendDatabase, testRmvFriends)
{
    const QString path("../unittest/testdirec/friends");
    FriendDB newFDB(path);
    int accntid = 1;
    int friendid = 2;
    int accntid2 = 11;
    int friendid2 = 12;
    newFDB.removeAllFriends();



    newFDB.addFriend(accntid, friendid);
    newFDB.addFriend(accntid2, friendid2);

    bool rmv1 = false;
    rmv1 = newFDB.removeFriend(accntid, friendid);
    ASSERT_TRUE(rmv1);
    bool rmv2 = false;
    rmv2 = newFDB.removeFriend(accntid2, friendid2);
    ASSERT_TRUE(rmv2);
    ASSERT_FALSE(newFDB.friendshipExists(accntid, friendid));
    ASSERT_FALSE(newFDB.friendshipExists(accntid2, friendid2));

    newFDB.removeAllFriends();
}

TEST(FriendDatabase, testRmvAllFriends)
{
    const QString path("../unittest/testdirec/friends");
    FriendDB newFDB(path);
    int accntid = 1;
    int friendid = 2;
    int accntid2 = 11;
    int friendid2 = 12;
    newFDB.removeAllFriends();



    newFDB.addFriend(accntid, friendid);
    newFDB.addFriend(accntid2, friendid2);

    bool rmvall = false;
    rmvall = newFDB.removeAllFriends();
    ASSERT_TRUE(rmvall);
    ASSERT_FALSE(newFDB.friendshipExists(accntid, friendid));
    ASSERT_FALSE(newFDB.friendshipExists(accntid2, friendid2));

}

TEST(FriendDatabase, testRetrieveFriendsList)
{
    const QString path("../unittest/testdirec/friends");
    FriendDB newFDB(path);
    int accntid1 = 1;
    int friendid1 = 2;
    int accntid2 = 11;
    int friendid2 = 12;
    int friendid3 = 22;
    int friendid4 = 32;
    newFDB.removeAllFriends();



    newFDB.addFriend(accntid1, friendid1);
    newFDB.addFriend(accntid1, friendid2);
    newFDB.addFriend(accntid1, friendid3);
    newFDB.addFriend(accntid1, friendid4);
    newFDB.addFriend(accntid2, friendid4);
    newFDB.addFriend(accntid2, friendid3);
    newFDB.addFriend(accntid2, friendid2);
    newFDB.addFriend(accntid2, friendid1);

//    QString expectedFriendsList1("");
//    QString expectedFriendsList2("");
//    expectedFriendsList1 += QString::number(friendid1) + " ";
//    expectedFriendsList1 += QString::number(friendid2) + " ";
//    expectedFriendsList1 += QString::number(friendid3) + " ";
//    expectedFriendsList1 += QString::number(friendid4) + " ";

//    expectedFriendsList2 += QString::number(friendid1) + " ";
//    expectedFriendsList2 += QString::number(friendid2) + " ";
//    expectedFriendsList2 += QString::number(friendid3) + " ";
//    expectedFriendsList2 += QString::number(friendid4) + " ";

    vector<int> expectedFriends1;
    expectedFriends1.push_back(friendid1);
    expectedFriends1.push_back(friendid2);
    expectedFriends1.push_back(friendid3);
    expectedFriends1.push_back(friendid4);

    vector<int> expectedFriends2;
    expectedFriends2.push_back(friendid4);
    expectedFriends2.push_back(friendid3);
    expectedFriends2.push_back(friendid2);
    expectedFriends2.push_back(friendid1);

    ASSERT_EQ(expectedFriends1, newFDB.retrieveAllFriends(accntid1));

    ASSERT_EQ(expectedFriends2, newFDB.retrieveAllFriends(accntid2));


    //ASSERT_EQ(expectedFriendsList1.toStdString(), newFDB.retrieveAllFriends(accntid1)->toStdString());
    //ASSERT_EQ(expectedFriendsList2.toStdString(), newFDB.retrieveAllFriends(accntid2)->toStdString());





}




//TWEED DB TESTS

TEST(TweetDatabase, testAddTweet)
{
    const QString path("../unittest/testdirec/testContentDB");
    TweetDB newTDB(path);
    int tid1 = 4;
    int aid1 = 5;
    int sid1 = 6;
    const QString content("content");
    int pri1 = 0;
    int tid2 = 14;
    int aid2 = 15;
    int sid2 = 16;
    const QString content2("content2");
    int pri2 = 1;

    newTDB.removeAllTweets();
    bool added = false;
    added = newTDB.addTweet(tid1, aid1, sid1, content, pri1);
    ASSERT_TRUE(added);
    bool added2 = false;
    added2 = newTDB.addTweet(tid2, aid2, sid2, content2, pri2);
    ASSERT_TRUE(added2);



    newTDB.removeAllTweets();



}

TEST(TweetDatabase, testTweetExists)
{
    const QString path("../unittest/testdirec/testContentDB");
    TweetDB newTDB(path);
    int tid1 = 4;
    int aid1 = 5;
    int sid1 = 6;
    const QString content("content");
    int pri1 = 0;
    int tid2 = 14;
    int aid2 = 15;
    int sid2 = 16;
    const QString content2("content2");
    int pri2 = 1;



    newTDB.removeAllTweets();
    ASSERT_FALSE(newTDB.tweetExists(tid1));
    ASSERT_FALSE(newTDB.tweetExists(tid2));
    newTDB.addTweet(tid1, aid1, sid1, content, pri1);
    ASSERT_TRUE(newTDB.tweetExists(tid1));
    newTDB.addTweet(tid2, aid2, sid2, content2, pri2);
    ASSERT_TRUE(newTDB.tweetExists(tid2));

    newTDB.removeAllTweets();

}

TEST(TweetDatabase, testRmvTweet)
{
    const QString path("../unittest/testdirec/testContentDB");
    TweetDB newTDB(path);
    int tid1 = 4;
    int aid1 = 5;
    int sid1 = 6;
    const QString content("content");
    int pri1 = 0;
    int tid2 = 14;
    int aid2 = 15;
    int sid2 = 16;
    const QString content2("content2");
    int pri2 = 1;


    newTDB.removeAllTweets();
    newTDB.addTweet(tid1, aid1, sid1, content, pri1);
    newTDB.addTweet(tid2, aid2, sid2, content2, pri2);
    newTDB.removeTweet(tid1);
    newTDB.removeTweet(tid2);
    ASSERT_FALSE(newTDB.tweetExists(tid1));
    ASSERT_FALSE(newTDB.tweetExists(tid2));

    newTDB.removeAllTweets();

}

TEST(TweetDatabase, testRmvAllTweets)
{
    const QString path("../unittest/testdirec/testContentDB");
    TweetDB newTDB(path);
    int tid1 = 4;
    int aid1 = 5;
    int sid1 = 6;
    const QString content("content");
    int pri1 = 0;
    int tid2 = 14;
    int aid2 = 15;
    int sid2 = 16;
    const QString content2("content2");
    int pri2 = 1;


    newTDB.removeAllTweets();
    newTDB.addTweet(tid1, aid1, sid1, content, pri1);
    newTDB.addTweet(tid2, aid2, sid2, content2, pri2);
    newTDB.removeAllTweets();
    ASSERT_FALSE(newTDB.tweetExists(tid1));
    ASSERT_FALSE(newTDB.tweetExists(tid2));

    newTDB.removeAllTweets();

}

TEST(TweetDatabase, testRetrieveTweetInfo)
{
    const QString path("../unittest/testdirec/testContentDB");
    TweetDB newTDB(path);
    int tid1 = 4;
    int aid1 = 5;
    int sid1 = 6;
    const QString content("content");
    int pri1 = 0;
    int tid2 = 14;
    int aid2 = 15;
    int sid2 = 16;
    const QString content2("content2");
    int pri2 = 1;

    newTDB.removeAllTweets();
    newTDB.addTweet(tid1, aid1, sid1, content, pri1);
    newTDB.addTweet(tid2, aid2, sid2, content2, pri2);

    TweetInfoType info = newTDB.retrieveTweetInfo(tid1);
    ASSERT_EQ (std::get<0>(info), tid1);
    ASSERT_EQ (std::get<1>(info), aid1);
    ASSERT_EQ (std::get<2>(info), sid1);
    ASSERT_EQ (std::get<3>(info), content);
    ASSERT_EQ (std::get<4>(info), pri1);
    TweetInfoType info2 = newTDB.retrieveTweetInfo(tid2);
    ASSERT_EQ (std::get<0>(info2), tid2);
    ASSERT_EQ (std::get<1>(info2), aid2);
    ASSERT_EQ (std::get<2>(info2), sid2);
    ASSERT_EQ (std::get<3>(info2), content2);
    ASSERT_EQ (std::get<4>(info2), pri2);

}

//Multimedia Tests:

TEST(MultimediaDatabase, testAddMM)
{
    const QString path("../unittest/testdirec/testContentDB");
    MultimediaDB newMDB(path);
    int mid1 = 5;
    int aid1 = 6;
    int sid1 = 7;
    const QString mmTitle1("Title 1");
    const QString mmDescription1("Description 1");
    const QString mmContent1("Content 1");
    int pri1 = 0;
    newMDB.removeAllMultimedias();
    bool added = false;
    added = newMDB.addMultimedia(mid1, aid1, sid1, mmTitle1, mmDescription1, mmContent1, pri1);
    ASSERT_TRUE(added);
    ASSERT_TRUE(newMDB.multimediaExists(mid1));


    newMDB.removeAllMultimedias();
}

TEST(MultimediaDatabase, testRmvMultimedia)
{

    const QString path("../unittest/testdirec/testContentDB");
    MultimediaDB newMDB(path);
    int mid1 = 5;
    int aid1 = 6;
    int sid1 = 7;
    const QString mmTitle1("Title 1");
    const QString mmDescription1("Description 1");
    const QString mmContent1("Content 1");
    int pri1 = 0;

    int mid2 = 15;
    int aid2 = 16;
    int sid2 = 17;
    const QString mmTitle2("Title 2");
    const QString mmDescription2("Description 2");
    const QString mmContent2("Content 2");
    int pri2 = 1;

    newMDB.removeAllMultimedias();
    newMDB.addMultimedia(mid1, aid1, sid1, mmTitle1, mmDescription1, mmContent1, pri1);
    newMDB.addMultimedia(mid2, aid2, sid2, mmTitle2, mmDescription2, mmContent2, pri2);

    bool rmv1 = false;
    rmv1 = newMDB.removeMultimedia(mid1);
    ASSERT_TRUE(rmv1);
    ASSERT_FALSE(newMDB.multimediaExists(mid1));
    bool rmv2 = false;
    rmv2 = newMDB.removeMultimedia(mid2);
    ASSERT_TRUE(rmv2);
    ASSERT_FALSE(newMDB.multimediaExists(mid2));



}

TEST(MultimediaDatabase, testRmvAllMultimedia)
{

    const QString path("../unittest/testdirec/testContentDB");
    MultimediaDB newMDB(path);
    int mid1 = 5;
    int aid1 = 6;
    int sid1 = 7;
    const QString mmTitle1("Title 1");
    const QString mmDescription1("Description 1");
    const QString mmContent1("Content 1");
    int pri1 = 0;

    int mid2 = 15;
    int aid2 = 16;
    int sid2 = 17;
    const QString mmTitle2("Title 2");
    const QString mmDescription2("Description 2");
    const QString mmContent2("Content 2");
    int pri2 = 1;

    newMDB.removeAllMultimedias();
    newMDB.addMultimedia(mid1, aid1, sid1, mmTitle1, mmDescription1, mmContent1, pri1);
    newMDB.addMultimedia(mid2, aid2, sid2, mmTitle2, mmDescription2, mmContent2, pri2);

    ASSERT_TRUE(newMDB.multimediaExists(mid1));
    ASSERT_TRUE(newMDB.multimediaExists(mid2));

    bool allRmv = false;
    allRmv = newMDB.removeAllMultimedias();
    ASSERT_TRUE(allRmv);
    ASSERT_FALSE(newMDB.multimediaExists(mid1));
    ASSERT_FALSE(newMDB.multimediaExists(mid2));





}

TEST(MultimediaDatabase, testMultimediaExists)
{

    const QString path("../unittest/testdirec/testContentDB");
    MultimediaDB newMDB(path);
    int mid1 = 5;
    int aid1 = 6;
    int sid1 = 7;
    const QString mmTitle1("Title 1");
    const QString mmDescription1("Description 1");
    const QString mmContent1("Content 1");
    int pri1 = 0;

    int mid2 = 15;
    int aid2 = 16;
    int sid2 = 17;
    const QString mmTitle2("Title 2");
    const QString mmDescription2("Description 2");
    const QString mmContent2("Content 2");
    int pri2 = 1;

    newMDB.removeAllMultimedias();
    ASSERT_FALSE(newMDB.multimediaExists(mid1));
    ASSERT_FALSE(newMDB.multimediaExists(mid2));

    newMDB.addMultimedia(mid1, aid1, sid1, mmTitle1, mmDescription1, mmContent1, pri1);
    newMDB.addMultimedia(mid2, aid2, sid2, mmTitle2, mmDescription2, mmContent2, pri2);
    ASSERT_TRUE(newMDB.multimediaExists(mid1));
    ASSERT_TRUE(newMDB.multimediaExists(mid2));

}

TEST(MultimediaDatabase, testRetrieveInfo)
{
    const QString path("../unittest/testdirec/testContentDB");
    MultimediaDB newMDB(path);
    int mid1 = 5;
    int aid1 = 6;
    int sid1 = 7;
    const QString mmTitle1("Title 1");
    const QString mmDescription1("Description 1");
    const QString mmContent1("Content 1");
    int pri1 = 0;

    int mid2 = 15;
    int aid2 = 16;
    int sid2 = 17;
    const QString mmTitle2("Title 2");
    const QString mmDescription2("Description 2");
    const QString mmContent2("Content 2");
    int pri2 = 1;

    newMDB.removeAllMultimedias();
    newMDB.addMultimedia(mid1, aid1, sid1, mmTitle1, mmDescription1, mmContent1, pri1);
    newMDB.addMultimedia(mid2, aid2, sid2, mmTitle2, mmDescription2, mmContent2, pri2);

    MultimediaInfoType info1 = newMDB.retrieveMultimediaInfo(mid1);
    ASSERT_EQ (std::get<0>(info1), mid1);
    ASSERT_EQ (std::get<1>(info1), aid1);
    ASSERT_EQ (std::get<2>(info1), sid1);
    ASSERT_EQ (std::get<3>(info1), mmTitle1);
    ASSERT_EQ (std::get<4>(info1), mmDescription1);
    ASSERT_EQ (std::get<5>(info1), mmContent1);
    ASSERT_EQ (std::get<6>(info1), pri1);

    MultimediaInfoType info2 = newMDB.retrieveMultimediaInfo(mid2);
    ASSERT_EQ (std::get<0>(info2), mid2);
    ASSERT_EQ (std::get<1>(info2), aid2);
    ASSERT_EQ (std::get<2>(info2), sid2);
    ASSERT_EQ (std::get<3>(info2), mmTitle2);
    ASSERT_EQ (std::get<4>(info2), mmDescription2);
    ASSERT_EQ (std::get<5>(info2), mmContent2);
    ASSERT_EQ (std::get<6>(info2), pri2);
}

//BLOGDB TESTS

TEST(BlogDatabase, testAddBlog)
{
    const QString path("../unittest/testdirec/Blogs");
    BlogDB newBDB(path);
    int bid1 = 5;
    int aid1 = 6;
    int sid1 = 7;
    const QString blogTitle1("Title 1");
    const QString blogContent1("Description 1");
    int priv1 = 0;
    int bid2 = 15;
    int aid2 = 16;
    int sid2 = 17;
    const QString blogTitle2("Title 2");
    const QString blogContent2("Description 2");
    int priv2 = 2;
    newBDB.removeAllBlogs();
    bool added = false;
    added = newBDB.addBlog(bid1, aid1, sid1, blogTitle1, blogContent1, priv1);
    ASSERT_TRUE(added);
    ASSERT_TRUE(newBDB.blogExists(bid1));
    bool added2 = false;
    added2 = newBDB.addBlog(bid2, aid2, sid2, blogTitle2, blogContent2, priv2);
    ASSERT_TRUE(added2);
    ASSERT_TRUE(newBDB.blogExists(bid2));


    newBDB.removeAllBlogs();
}



TEST(BlogDatabase, testBlogExists)
{
    const QString path("../unittest/testdirec/Blogs");
    BlogDB newBDB(path);
    int bid1 = 5;
    int aid1 = 6;
    int sid1 = 7;
    const QString blogTitle1("Title 1");
    const QString blogContent1("Description 1");
    int priv1 = 0;
    int bid2 = 15;
    int aid2 = 16;
    int sid2 = 17;
    const QString blogTitle2("Title 2");
    const QString blogContent2("Description 2");
    int priv2 = 2;
    newBDB.removeAllBlogs();
    ASSERT_FALSE(newBDB.blogExists(bid1));
    ASSERT_FALSE(newBDB.blogExists(bid2));
    newBDB.addBlog(bid1, aid1, sid1, blogTitle1, blogContent1, priv1);
    ASSERT_TRUE(newBDB.blogExists(bid1));
    newBDB.addBlog(bid2, aid2, sid2, blogTitle2, blogContent2, priv2);
    ASSERT_TRUE(newBDB.blogExists(bid2));


    newBDB.removeAllBlogs();
}

TEST(BlogDatabase, testRmvBlog)
{
    const QString path("../unittest/testdirec/Blogs");
    BlogDB newBDB(path);
    int bid1 = 5;
    int aid1 = 6;
    int sid1 = 7;
    const QString blogTitle1("Title 1");
    const QString blogContent1("Description 1");
    int priv1 = 0;
    int bid2 = 15;
    int aid2 = 16;
    int sid2 = 17;
    const QString blogTitle2("Title 2");
    const QString blogContent2("Description 2");
    int priv2 = 2;
    newBDB.removeAllBlogs();
    newBDB.addBlog(bid1, aid1, sid1, blogTitle1, blogContent1, priv1);
    ASSERT_TRUE(newBDB.blogExists(bid1));
    newBDB.addBlog(bid2, aid2, sid2, blogTitle2, blogContent2, priv2);
    ASSERT_TRUE(newBDB.blogExists(bid2));
    bool rmv1 = false;
    rmv1 = newBDB.removeBlog(bid1);
    bool rmv2 = false;
    rmv2 = newBDB.removeBlog(bid2);
    ASSERT_TRUE(rmv1);
    ASSERT_TRUE(rmv2);
    ASSERT_FALSE(newBDB.blogExists(bid1));
    ASSERT_FALSE(newBDB.blogExists(bid2));

}

TEST(BlogDatabase, testRetrieveBlogInfo)
{
    const QString path("../unittest/testdirec/Blogs");
    BlogDB newBDB(path);
    int bid1 = 5;
    int aid1 = 6;
    int sid1 = 7;
    const QString blogTitle1("Title 1");
    const QString blogContent1("Description 1");
    int priv1 = 0;
    int bid2 = 15;
    int aid2 = 16;
    int sid2 = 17;
    const QString blogTitle2("Title 2");
    const QString blogContent2("Description 2");
    int priv2 = 2;
    newBDB.removeAllBlogs();
    newBDB.addBlog(bid1, aid1, sid1, blogTitle1, blogContent1, priv1);
    newBDB.addBlog(bid2, aid2, sid2, blogTitle2, blogContent2, priv2);

    BlogInfoType info = newBDB.retrieveBlogInfo(bid1);
    ASSERT_EQ (std::get<0>(info), bid1);
    ASSERT_EQ (std::get<1>(info), aid1);
    ASSERT_EQ (std::get<2>(info), sid1);
    ASSERT_EQ (std::get<3>(info), blogTitle1);
    ASSERT_EQ (std::get<4>(info), blogContent1);
    ASSERT_EQ (std::get<5>(info), priv1);

    BlogInfoType info2 = newBDB.retrieveBlogInfo(bid2);
    ASSERT_EQ (std::get<0>(info2), bid2);
    ASSERT_EQ (std::get<1>(info2), aid2);
    ASSERT_EQ (std::get<2>(info2), sid2);
    ASSERT_EQ (std::get<3>(info2), blogTitle2);
    ASSERT_EQ (std::get<4>(info2), blogContent2);
    ASSERT_EQ (std::get<5>(info2), priv2);

    newBDB.removeAllBlogs();

}

TEST(BlogDatabase, testRetrieveAllBlogInfo)
{
    const QString path("../unittest/testdirec/Blogs");
    BlogDB newBDB(path);
    int bid1 = 5;
    int aid1 = 6;
    int sid1 = 7;
    const QString blogTitle1("Title 1");
    const QString blogContent1("Description 1");
    int priv1 = 0;
    int bid2 = 15;
    int aid2 = 16;
    int sid2 = 17;
    const QString blogTitle2("Title 2");
    const QString blogContent2("Description 2");
    int priv2 = 2;
    int bid3 = 35;
    int aid3 = 36;
    const QString blogTitle3("Title 3");
    const QString blogContent3("Description 3");
    int priv3 = 33;
    int bid4 = 45;
    int aid4 = 46;
    const QString blogTitle4("Title 4");
    const QString blogContent4("Description 4");
    int priv4 = 4;

    newBDB.removeAllBlogs();
    newBDB.addBlog(bid1, aid1, sid1, blogTitle1, blogContent1, priv1);
    newBDB.addBlog(bid2, aid2, sid2, blogTitle2, blogContent2, priv2);
    newBDB.addBlog(bid3, aid3, sid1, blogTitle3, blogContent3, priv3);
    newBDB.addBlog(bid4, aid4, sid2, blogTitle4, blogContent4, priv4);

    vector<BlogInfoType> info = newBDB.retrieveAllBlogInfo(sid1);
    vector<BlogInfoType> infoTwo = newBDB.retrieveAllBlogInfo(sid2);

    std::tuple<int,int,int, QString, QString, int> info1 = info.at(0);
    std::tuple<int,int,int, QString, QString, int> info3 = info.at(1);
    std::tuple<int,int,int, QString, QString, int> info2 = infoTwo.at(0);
    std::tuple<int,int,int, QString, QString, int> info4 = infoTwo.at(1);

    ASSERT_EQ (std::get<0>(info1), bid1);
    ASSERT_EQ (std::get<1>(info1), aid1);
    ASSERT_EQ (std::get<2>(info1), sid1);
    ASSERT_EQ (std::get<3>(info1), blogTitle1);
    ASSERT_EQ (std::get<4>(info1), blogContent1);
    ASSERT_EQ (std::get<5>(info1), priv1);

    ASSERT_EQ (std::get<0>(info2), bid2);
    ASSERT_EQ (std::get<1>(info2), aid2);
    ASSERT_EQ (std::get<2>(info2), sid2);
    ASSERT_EQ (std::get<3>(info2), blogTitle2);
    ASSERT_EQ (std::get<4>(info2), blogContent2);
    ASSERT_EQ (std::get<5>(info2), priv2);

    ASSERT_EQ (std::get<0>(info3), bid3);
    ASSERT_EQ (std::get<1>(info3), aid3);
    ASSERT_EQ (std::get<2>(info3), sid1);
    ASSERT_EQ (std::get<3>(info3), blogTitle3);
    ASSERT_EQ (std::get<4>(info3), blogContent3);
    ASSERT_EQ (std::get<5>(info3), priv3);

    ASSERT_EQ (std::get<0>(info4), bid4);
    ASSERT_EQ (std::get<1>(info4), aid4);
    ASSERT_EQ (std::get<2>(info4), sid2);
    ASSERT_EQ (std::get<3>(info4), blogTitle4);
    ASSERT_EQ (std::get<4>(info4), blogContent4);
    ASSERT_EQ (std::get<5>(info4), priv4);

    newBDB.removeAllBlogs();

}


