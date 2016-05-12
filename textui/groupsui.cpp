#include "groupsui.h"



GroupsUI::GroupsUI(AccountController* accountControl)
{
    this->accountControl=accountControl;
    initialize();
    options=3;
    takeCommand(select(options));



}




void GroupsUI::drawScreen(int v) {

    clear();

    mvprintw(0, 0, "Groups");
    mvprintw(3, 8, "Enter group");
    mvprintw(4, 8, "Create new group");
    mvprintw(5, 8, "Back");

    mvprintw(v+2, 5, "->");

    refresh();
}




void GroupsUI::takeCommand(int selection){

    endwin();

    if(selection==1){

        int chosenGroup=selectGroup();
        if(chosenGroup!=-1)
            viewProfile(chosenGroup);
    }
    else if(selection==2)
        createGroup();
    else if(selection==3)
        return;

    initialize();
    takeCommand(select(options));

}


void GroupsUI::createGroup(){
    erase();

    char name[80], description[500];
    QString serverPath;
    echo();

    mvprintw(0,0,"Create Group");

    mvprintw(1,0,"Enter Group Name: ");
    getstr(name);

    mvprintw(2,0,"Enter Description: ");
    getstr(description);

    noecho();

    Group* currentGroup = accountControl->getUser()->controlGroup()->createNewGroup(QString::fromStdString(name), serverPath, QString::fromStdString(description));

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
        mvprintw(0,0, "Groups: Press ENTER to enter a group");

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

void GroupsUI::viewProfile(int index){
    int groupID = std::get<0>(groupIDNames.at(index));
    Group* group = accountControl->getUser()->controlGroup()->getGroup(groupID);
    Scrapbook* groupScrapbook = group->getProfile()->getScrapbook();
    std::vector<std::string> members= QtoStd(group->getMemberNameList());


    erase();


    mvprintw(0,0, "Group info: ");
    printw(group->getProfile()->getFullName().toStdString().c_str());

    mvprintw(1,0, "Description: ");
    printw(group->getProfile()->getDescription().toStdString().c_str());

    mvprintw(12,0, "Members: ");



    for(unsigned int i=0;i<members.size();i++){
        printw(members.at(i).c_str());
        if(i!=members.size()-1)
            printw(" , ");
    }
    mvprintw(LINES-1, 0, "Press any key to continue");
    getch();

    scrapbook=new GroupScrapbookUI(accountControl->getUser()->getUsername(),groupID, group, groupScrapbook, accountControl->getUser()->controlFriend()->getFriendNames());

}
