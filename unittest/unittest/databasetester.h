#ifndef DATABASETESTER_H
#define DATABASETESTER_H

#include <iostream>
#include <random>
#include <string>

#include "../gtest/gtest.h"
#include "../../database/accountdb.h"
#include "../../database/profiledb.h"
#include "../../database/frienddb.h"
#include "../../database/commentdb.h"
#include "../../database/tweetdb.h"
#include "../../database/multimediadb.h"
#include "../../database/blogdb.h"
#include "../../database/chatdb.h"
#include "../../database/groupdb.h"



class DatabaseTester
{
public:
    DatabaseTester();
};

#endif // DATABASETESTER_H
