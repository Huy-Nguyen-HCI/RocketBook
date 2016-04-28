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
    std::vector<Group*> allGroups = accountControl->getUser()->controlGroup()->getAllGroups();
    for (int i=0;i<allGroups.size();i++){
        int groupID = allGroups.at(i)->getID();
        std::string groupName=allGroups.at(i)->getProfile()->getFullName().toStdString();
        GroupIDNameType groupInfo = std::make_tuple(groupID, groupName);
        groupIDNames.push_back(groupInfo);
    }

    while(scrolling){

        erase();
        refresh();
        mvprintw(0,0, "Groups: Press hit ENTER to enter a group");

        //set positioning for the arrow
        row=3;
        mvprintw(row, 5, "->");

        //
        max=offset+15;
        if(allGroups.size()<offset+15)
            max=allGroups.size();

        //Write group names using this loop
        for (unsigned int i = offset; i < max; i++) {
            std::string groupName=std::get<1>(groupIDNames.at(i));
            mvprintw(row,8,groupName.c_str());
            row++;
        }

        //handling the control
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
    int groupID = std::get<0>(groupIDNames.at(index));
    Group* group = accountControl->getUser()->controlGroup()->getGroup(groupID);
    Scrapbook* groupScrapbook = group->getProfile()->getScrapbook();
}
