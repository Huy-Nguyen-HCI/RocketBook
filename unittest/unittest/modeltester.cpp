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

TEST(RocketUserTest, testGetProfile)
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
    ASSERT_EQ(dscr1, user1.getProfile()->getDescription());
    ASSERT_EQ(fn1, user1.getProfile()->getFullName());


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

//Blog tests

TEST(BlogTest, testTitle)
{
    QString username1("username 1");
    QString title1("title 1");
    QString content1("content 1");
    QString username2("username 2");
    QString title2("title 2");
    QString content2("content 2");
    QString dbPath("../unittest/testdirec");

    Blog newBlog1(username1, title1, content1, dbPath);
    Blog newBlog2(username2, title2, content2, dbPath);

    ASSERT_EQ(title1, newBlog1.getTitle());
    ASSERT_EQ(title2, newBlog2.getTitle());

}

TEST(BlogTest, testAuthor)
{
    QString username1("username 1");
    QString title1("title 1");
    QString content1("content 1");
    QString username2("username 2");
    QString title2("title 2");
    QString content2("content 2");
    QString dbPath("../unittest/testdirec");

    Blog newBlog1(username1, title1, content1, dbPath);
    Blog newBlog2(username2, title2, content2, dbPath);

    ASSERT_EQ(username1, newBlog1.getAuthorUsername());
    ASSERT_EQ(username2, newBlog2.getAuthorUsername());

}

TEST(BlogTest, testEditContent)
{
    QString username1("username 1");
    QString title1("title 1");
    QString content1("content 1");
    QString username2("username 2");
    QString title2("title 2");
    QString content2("content 2");
    QString dbPath("../unittest/testdirec");

    Blog newBlog1(username1, title1, content1, dbPath);
    Blog newBlog2(username2, title2, content2, dbPath);

    ASSERT_EQ(content1, newBlog1.getContent());
    ASSERT_EQ(content2, newBlog2.getContent());
    newBlog1.editBlog(content2);
    newBlog2.editBlog(content1);
    ASSERT_EQ(content2, newBlog1.getContent());
    ASSERT_EQ(content1, newBlog2.getContent());

}

TEST(BlogTest, testComments)
{
    QString username1("username 1");
    QString title1("title 1");
    QString content1("content 1");
    QString username2("username 2");
    QString title2("title 2");
    QString content2("content 2");
    QString dbPath("../unittest/testdirec");
    QString comment1("comment 1");
    QString comment2("comment 2");

    Blog newBlog1(username1, title1, content1, dbPath);
    Blog newBlog2(username2, title2, content2, dbPath);

    newBlog1.addComment(username1, comment1);
    newBlog1.addComment(username2, comment2);
    newBlog2.addComment(username2, comment2);
    newBlog2.addComment(username1, comment1);

    std::vector<Comment*> comments1 = newBlog1.getAllComments();
    std::vector<Comment*> comments2 = newBlog2.getAllComments();

    ASSERT_EQ(2, comments1.size());
    ASSERT_EQ(2, comments2.size());

    ASSERT_EQ(comment1, comments1.at(0)->getContent());
    ASSERT_EQ(comment2, comments1.at(1)->getContent());
    ASSERT_EQ(username1, comments1.at(0)->getAuthorUsername());
    ASSERT_EQ(username2, comments1.at(1)->getAuthorUsername());
    ASSERT_EQ(comment1, comments2.at(1)->getContent());
    ASSERT_EQ(comment2, comments2.at(0)->getContent());
    ASSERT_EQ(username1, comments2.at(1)->getAuthorUsername());
    ASSERT_EQ(username2, comments2.at(0)->getAuthorUsername());
}

TEST(BlogTest, testBlogType)
{
    QString username1("username 1");
    QString title1("title 1");
    QString content1("content 1");
    QString username2("username 2");
    QString title2("title 2");
    QString content2("content 2");
    QString dbPath("../unittest/testdirec");

    Blog newBlog1(username1, title1, content1, dbPath);
    Blog newBlog2(username2, title2, content2, dbPath);

    Post::PostType postType1 = newBlog1.type();
    Post::PostType postType2 = newBlog2.type();
    ASSERT_EQ(Post::typeBlog, postType1);
    ASSERT_EQ(Post::typeBlog, postType2);

}



//Comment tests

TEST(CommentTests, testContent)
{
    QString username1("username 1");
    QString content1("content 1");
    QString username2("username 2");
    QString content2("content 2");

    Comment newComment1(username1, content1);
    Comment newComment2(username2, content2);

    ASSERT_EQ(content1, newComment1.getContent());
    ASSERT_EQ(content2, newComment2.getContent());
}

TEST(CommentTests, testAuthor)
{
    QString username1("username 1");
    QString content1("content 1");
    QString username2("username 2");
    QString content2("content 2");

    Comment newComment1(username1, content1);
    Comment newComment2(username2, content2);

    ASSERT_EQ(username1, newComment1.getAuthorUsername());
    ASSERT_EQ(username2, newComment2.getAuthorUsername());
}

TEST(CommentTests, testCommentType)
{
    QString username1("username 1");
    QString content1("content 1");
    QString username2("username 2");
    QString content2("content 2");

    Comment newComment1(username1, content1);
    Comment newComment2(username2, content2);

    Post::PostType postType1 = newComment1.type();
    Post::PostType postType2 = newComment2.type();
    ASSERT_EQ(Post::typeComment, postType1);
    ASSERT_EQ(Post::typeComment, postType2);
}

//Group Test

TEST(GroupTests, testGetID)
{
    const QString dbPath("../unittest/testdirec");
    int gid = 1;
    int aid = 3;
    QString name("Full Name");
    QString photo("Photo");
    QString dscr("Description");
    Group newGroup(dbPath, gid, aid, name, photo, dscr);
    ASSERT_EQ(gid, newGroup.getID());
}

TEST(GroupTests, testProfile)
{
    const QString dbPath("../unittest/testdirec");
    int gid = 1;
    int aid = 3;
    QString name("Full Name");
    QString photo("Photo");
    QString dscr("Description");
    Group newGroup(dbPath, gid, aid, name, photo, dscr);
    ASSERT_EQ(name, newGroup.getProfile()->getFullName());
    ASSERT_EQ(photo, newGroup.getProfile()->getPicturePath());
    ASSERT_EQ(dscr, newGroup.getProfile()->getDescription());
}

// Multimeida tests

TEST(MultimediaTest, testTitle)
{
    QString username("username");
    QString title("title");
    QString description("description");
    QString content("content");
    Multimedia mm(username, title, description, content);
    ASSERT_EQ(title, mm.getTitle());
}

TEST(MultimediaTest, testAuthor)
{
    QString username("username");
    QString title("title");
    QString description("description");
    QString content("content");
    Multimedia mm(username, title, description, content);
    ASSERT_EQ(username, mm.getAuthorUsername());
}

TEST(MultimediaTest, testContent)
{
    QString username("username");
    QString title("title");
    QString description("description");
    QString content("content");
    Multimedia mm(username, title, description, content);
    ASSERT_EQ(content, mm.getContent());
}

TEST(MultimediaTest, testDescription)
{
    QString username("username");
    QString title("title");
    QString description("description");
    QString content("content");
    Multimedia mm(username, title, description, content);
    ASSERT_EQ(description, mm.getDescription());
}

TEST(MultimediaTest, testMultimediaType)
{
    QString username("username");
    QString title("title");
    QString description("description");
    QString content("content");
    Multimedia mm(username, title, description, content);
    Post::PostType postType = mm.type();
    ASSERT_EQ(Post::typeMultimedia, postType);

}

//Post tests

TEST(PostTests, testContent)
{
    QString username("username");
    QString content("content");
    Post newPost(username, content);
    ASSERT_EQ(content, newPost.getContent());
}

TEST(PostTests, testAuthor)
{
    QString username("username");
    QString content("content");
    Post newPost(username, content);
    ASSERT_EQ(username, newPost.getAuthorUsername());
}

TEST(PostTests, testPrivacy)
{
    QString username("username");
    QString content("content");
    Post newPost(username, content);
    ASSERT_FALSE(newPost.getPrivacy());
    newPost.setPrivate();
    ASSERT_TRUE(newPost.getPrivacy());
}

TEST(PostTests, testPostType)
{
    QString username("username");
    QString content("content");
    Post newPost(username, content);
    Post::PostType postType = newPost.type();
    ASSERT_EQ(Post::typePost, postType);
}

//Tweet tests

TEST(TweetTests, testContent)
{
    QString username("username");
    QString content("content");
    Tweet newTweet(username, content);
    ASSERT_EQ(content, newTweet.getContent());
}

TEST(TweetTests, testAuthor)
{
    QString username("username");
    QString content("content");
    Tweet newTweet(username, content);
    ASSERT_EQ(username, newTweet.getAuthorUsername());
}

TEST(TweetTests, testPrivacy)
{
    QString username("username");
    QString content("content");
    Tweet newTweet(username, content);
    ASSERT_FALSE(newTweet.getPrivacy());
    newTweet.setPrivate();
    ASSERT_TRUE(newTweet.getPrivacy());
}

TEST(TweetTests, testTweetType)
{
    QString username("username");
    QString content("content");
    Tweet newTweet(username, content);
    Post::PostType postType = newTweet.type();
    ASSERT_EQ(Post::typeTweet, postType);
}





