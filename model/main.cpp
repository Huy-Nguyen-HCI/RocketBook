#include <iostream>
#include <vector>
#include <string>
#include "../database/accountdb.h"
#include "accountcontroller.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    AccountController a;
    a.run();
    return 0;
}

