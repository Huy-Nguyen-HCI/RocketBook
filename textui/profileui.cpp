#include "profileui.h"

ProfileUI::ProfileUI(AccountController* accountControl)
{

    this->accountControl=accountControl;
    initialize();
    echo();
    mvprintw(0,0,"Create new Account");
    run();

}

void ProfileUI::run(){




}
