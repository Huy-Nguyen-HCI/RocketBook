#include <iostream>

#include "../model/accountcontroller.h"
#include "enterui.h"


using namespace std;

int main(int argc, char *argv[])
{
    AccountController* accountControl= new AccountController();
    EnterUI* a=new EnterUI(accountControl);
    return 0;
}

