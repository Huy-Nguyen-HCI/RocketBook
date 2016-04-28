#include "groupsui.h"

GroupsUI::GroupsUI(AccountController* accountControl)
{
    this->accountControl=accountControl;
    initialize();

    int chosenGroup=selectGroup();
    if(chosenGroup!=-1)
        enterGroup(chosenGroup);


}

int GroupsUI::selectGroup(){

    bool scrolling=true;
    int offset=0;
    int row, max;  
    //Instantiates groups when entering screen
    std::vector<std::string> groupNames;
    std::vector<Group*> allGroups = accountControl->getUser()->controlGroup()->getAllGroups();
    for (int i=0;i<allGroups.size();i++){
        std::string groupName=allGroups.at(i)->getProfile()->getFullName().toStdString();
        groupNames.push_back(groupName);
    }

    while(scrolling){



     erase();
    refresh();
    mvprintw(0,0, "Friends: Press enter to select friend");


    row=3;
    mvprintw(row, 5, "->");




    max=offset+15;
    if(allGroups.size()<offset+15)
        max=allGroups.size();

    //Write group naems using this loop
    for (unsigned int i = offset; i < max; i++) {
        std::string groupName=groupNames.at(i);
        mvprintw(row,8,groupName.c_str());//.toStdString().c_str());
        row++;
    }

    int ch= getch();
        if(ch==KEY_DOWN && (max!=(offset+1)))//ch==258 || KEY_DOWN || !((wholeScrapbook.size()-5)>offset)) //259 and 259 enables scrolling
            offset++;
        else if(ch==KEY_UP && offset>0)//ch==259 || KEY_UP || offset>0)
            offset--;
        else if(ch==KEY_UP);
        else if(ch==KEY_DOWN);
        else if(ch==10)//enter key
            scrolling=false;
        else
            return -1;

    }
    return offset;


}

void GroupsUI::enterGroup(int index){




}
