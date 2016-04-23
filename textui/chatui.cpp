#include "chatui.h"

ChatUI::ChatUI(AccountController* accountControl)
{

    this->username=accountControl->getUser()->getUsername();
    this->accountControl=accountControl;
    initialize();
    takeCommand(select(3));

}

void ChatUI::drawScreen(int v) {

clear();

// print the instructions for manipulating the Value object
mvprintw(0, 0, "Chat Menu \nPlease select one by using the arrow keys and pressing enter:");
mvprintw(3, 8, "Create new Chat");
mvprintw(4, 8, "Select Chat");
mvprintw(5, 8, "Back");

mvprintw(v+2, 5, "->");
//std::to_string(v).c_str()

refresh();
}



void ChatUI::takeCommand(int selection){

    // cleanup the window and return control to bash
    endwin();

    chatControl=new ChatController(accountControl->getPath(),accountControl->getUser()->getID());
   if(selection==1)
       createChat();
   else if(selection==2)
       selectChat();
   else if(selection==3)
       return;

   initialize();
   takeCommand(select(3));

}

void ChatUI::createChat(){
 //   chatControl->createChat();
    mvprintw(8, 6, "New Chat Created");
    getch();
    erase();
}




void ChatUI::selectChat(){
   chatList=chatControl->getChatIdList();
   //This will enter Chat at specific chat Id
   enterChat(chatList->at(chatSelection()));


}



void ChatUI::displayChats(int v) {

    erase();

    mvprintw(0, 0, "Your Chats");

    for(unsigned int i=0;i<chatList->size(); i++){
        mvprintw(i+1,3,std::to_string(chatList->at(i)).c_str());
    }

    mvprintw(v, 0, "->");

    refresh();
}




int ChatUI::chatSelection(){
    int v=1;

    // initialize the interaction loop to run
    bool continue_looping = true;

    // draw the current screen
    displayChats(v);

    do {
        // draw the new screen
        refresh();
        // obtain character from keyboard
        int ch = getch();
        // operate based on input character
        switch (ch) {
        case KEY_UP:
            if(v>0) //arrow goes up
            v--;
            if(v==0) //arrow goes to bottom
                v=chatList->size();
            break;
        case KEY_DOWN:
            if(v<chatList->size()+1) //arrows goes down
            v++;
            if(v==chatList->size()+1) //arrow goes back to top
                v=1;
            break;
        case 10: //Enter Key
            continue_looping = false;
            break;
        }

        displayChats(v);

    } while(continue_looping);

    return v-1;

}

void ChatUI::enterChat(int chatId){


    std::vector<int>* senderIds=chatControl->getSenderList(chatId);
    std::vector<QString>* messages=chatControl->getMessageList(chatId);

    erase();
    mvprintw(0,0, "Chat Id: ");
    printw(std::to_string(chatId).c_str());

    for(int i=0;i<senderIds->size();i++){
        mvprintw(i+1,0,accountControl->getUserName(senderIds->at(i)).c_str());
        printw(": ");
        printw(messages->at(i).toStdString().c_str());

        }


    getch();

}
