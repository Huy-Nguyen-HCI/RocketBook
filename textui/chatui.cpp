#include "chatui.h"

ChatUI::ChatUI(AccountController* accountControl)
{

    this->username=accountControl->getUser()->getUsername();
    this->accountControl=accountControl;
    initialize();
    options=5;
    takeCommand(select(options));

}

void ChatUI::drawScreen(int v) {

    clear();

    // print the instructions for manipulating the Value object
    mvprintw(0, 0, "Chat Menu");
    mvprintw(4, 8, "Create new Chat");
    mvprintw(3, 8, "Enter Chat Room");
    mvprintw(5, 8, "Add friend to Chat");
    mvprintw(6, 8, "Leave Chat");
    mvprintw(7, 8, "Back");

    mvprintw(v+2, 5, "->");
    //std::to_string(v).c_str()

    refresh();
}

void ChatUI::takeCommand(int selection){

    // cleanup the window and return control to bash
    endwin();

    if(selection==2){
        int chosenFriend=selectFriend();
        if(chosenFriend!=-1)
            createChat(chosenFriend);//(chosenFriend);
    }

    else if(selection==1){
        int chosenChat=selectChat();
        if(chosenChat!=-1)
            chatRoom(chosenChat);
    }

    else if(selection==3){
        int chosenChat=selectChat();
        erase();
        int chosenFriend=selectFriend();
        if(chosenFriend!=-1 && chosenChat!=-1)
            addFriend(chosenChat,chosenFriend);//(chosenFriend);

    }

    else if(selection==4){
        int chosenChat=selectChat();
        if(chosenChat!=-1)
            leaveChat(chosenChat);
    }

    else if(selection==5)
        return;

    initialize();
    takeCommand(select(options));
}

void ChatUI::createChat(int id){
    QStringList friendNames= accountControl->getUser()->controlFriend()->getFriendNames();
    accountControl->getUser()->getChatController()->createChat(friendNames.at(id));
    mvprintw(LINES-2, 5, "New Chat Created");
    getch();
    erase();
}


void ChatUI::chatRoom(int index){


    std::vector<int>* chatList=accountControl->getUser()->getChatController()->getChatIdList();
    int chatId=chatList->at(index);

    std::vector<int>* senderIds;//=accountControl->getUser()->getChatController()->getSenderList(chatId);
    std::vector<QString>* messages;//=accountControl->getUser()->getChatController()->getMessageList(chatId);

    bool chating=true;
    int offset=0;
    int row, max, displayNumber=18;

    while(chating){
        senderIds=accountControl->getUser()->getChatController()->getSenderList(chatId);
        messages=accountControl->getUser()->getChatController()->getMessageList(chatId);

        erase();
        mvprintw(0,0, "Chat Room: ");
        printw(std::to_string(chatId).c_str());
        printw(". Press up or down to scroll or Enter to send message.");

        row=2;


        if(messages->size() < displayNumber)
            max = messages->size();
        else
            max = offset+displayNumber;

        for(int i=offset;i<max;i++){
            mvprintw(row,0,accountControl->getUserName(senderIds->at(i)).c_str());
            printw(": ");
            printw(messages->at(i).toStdString().c_str());
            row++;

        }

        int ch= getch();
        if(ch==KEY_DOWN && !((messages->size())==(max)))//ch==258 || KEY_DOWN || !((wholeScrapbook.size()-5)>offset)) //259 and 259 enables scrolling
            offset++;
        else if(ch==KEY_UP && offset>0)//ch==259 || KEY_UP || offset>0)
            offset--;
        else if(ch==KEY_UP);
        else if(ch==KEY_DOWN);
        else if(ch==10){//enter key
            sendMessage(chatId);
            if(messages->size() > displayNumber)
                offset=messages->size()-displayNumber+1;
        }
        else
            chating=false;

    }




}

void ChatUI::sendMessage(int chatId){
    char message[500];
    mvprintw(LINES-3, 5, "Enter Message: ");
    echo();
    getstr(message);
    accountControl->getUser()->getChatController()->sendMessage(chatId,QString::fromStdString(message));
    noecho();

}

void ChatUI::addFriend(int chatIndex, int friendIndex){
    std::vector<int>* chatList=accountControl->getUser()->getChatController()->getChatIdList();
    int chatId=chatList->at(chatIndex);
    QStringList friendNames= accountControl->getUser()->controlFriend()->getFriendNames();
    QString friendName=friendNames.at(friendIndex);

    if(accountControl->getUser()->getChatController()->addMemberToChat(chatId,friendName)){
        mvprintw(LINES-2, 5, "Friend added to Chat");
    }
    getch();

}


void ChatUI::leaveChat(int index){
    std::vector<int>* chatList=accountControl->getUser()->getChatController()->getChatIdList();
    int chatId=chatList->at(index);

    accountControl->getUser()->getChatController()->removeUserFromChat(chatId, username);
    mvprintw(LINES-2, 5, "You've left the chat");

    getch();
}

int ChatUI::selectFriend(){

    bool scrolling=true;
    int offset=0;
    int row, max;

    while(scrolling){
        erase();
        mvprintw(0,0, "Friends: Press enter to select friend");

        row=3;
        mvprintw(row, 5, "->");

        QStringList friendNames= accountControl->getUser()->controlFriend()->getFriendNames();

        max=offset+15;
        if(friendNames.size()<offset+15)
            max=friendNames.size();


        for (unsigned int i = offset; i < max; i++) {
            mvprintw(row,8,friendNames.at(i).toStdString().c_str());
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

int ChatUI::selectChat(){

    bool scrolling=true;
    int offset=0;
    int row, max;

    while(scrolling){
        erase();
        mvprintw(0,0, "Friends: Press enter to select chat or any other key to go back");

        row=3;
        mvprintw(row, 5, "->");

        std::vector<int>* chatList=accountControl->getUser()->getChatController()->getChatIdList();

        max=offset+15;
        if(chatList->size()<offset+15)
            max=chatList->size();

        for(unsigned int i=offset;i<max; i++){
            mvprintw(row,8,std::to_string(chatList->at(i)).c_str());
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

int ChatUI::scrollMessages(){

    bool scrolling=true;
    int offset=0;
    int row, max;

    while(scrolling){
        erase();
        mvprintw(0,0, "Friends: Press enter to select chat");

        row=3;
        mvprintw(row, 5, "->");

        std::vector<int>* chatList=accountControl->getUser()->getChatController()->getChatIdList();

        max=offset+15;
        if(chatList->size()<offset+15)
            max=chatList->size();

        for(unsigned int i=offset;i<max; i++){
            mvprintw(row,8,std::to_string(chatList->at(i)).c_str());
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
