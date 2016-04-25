create table Blogs (BlogID integer primary key, AccountID integer not null, ScrapbookID integer not null, BlogTitle text, BlogContent text, Privacy integer not null);
create table Tweets (TweetID integer primary key, AccountID integer not null, ScrapbookID integer not null, TweetContent text, Privacy integer not null);
create table Multimedias (MultimediaID integer primary key, AccountID integer not null, ScrapbookID integer not null, MultimediaTitle text, MultimediaDescription text, MultimediaContent text, Privacy integer not null);
create table Comments(CommentID integer primary key, AccountID integer not null, BlogID integer not null, CommentContent text not null);
