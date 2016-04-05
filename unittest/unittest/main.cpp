#include <iostream>

#include "../gtest/gtest.h"
#include "../../database/accountdb.h"
#include "../../model/blog.h"
#include "../../model/comment.h"

using namespace std;


TEST(AccntDatabase, testAccntDB)
{
    //const QString path("/usr23/townleym/wc20160405/unittest/unittest/testdirec/testAccntDB");
    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");
    const QString un3("username3");
    const QString pw3("password3");

    bool added;
    added = newDB.addAccount(12346, un, pw, 54322);
    newDB.addAccount(12345, un2, pw2, 54321);

    ASSERT_TRUE(added);

    //ASSERT_TRUE(newDB.accountExists(un));
    //ASSERT_TRUE(newDB.accountExists(un2));
    ASSERT_FALSE(newDB.accountExists(un3));






    //newDB.addaccount();


}

//TEST(Modelfunc, testBlog)
//{
//    //Blog b;
//    //Comment c;



//}


int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);

     return RUN_ALL_TESTS();

}
