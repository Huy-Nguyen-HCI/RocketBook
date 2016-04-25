create table Groups (GroupID integer primary key, ProfileID integer unique not null);
create table GroupMembers (GroupID integer not null, AccountID integer not null, GroupAdminRights integer not null);
