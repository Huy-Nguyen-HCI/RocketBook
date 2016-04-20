#include <iostream>
#include "loginui.h"
#include "mainmenu.h"
#define timeout(QPrivateSignal)   timeout2(QPrivateSignal);//       <----- Don't as why this is here
#include "../model/accountcontroller.h"
#include "../model/chatcontroller.h"


using namespace std;

int main(int argc, char *argv[])
{
    ChatController* chatControl= new ChatController();
    AccountController* accountControl= new AccountController();
    LoginUI* a=new LoginUI(accountControl, chatControl);
    return 0;
}
