#include "accountcontroller.h"

using namespace std;


AccountController::AccountController()
{

}

void AccountController::createAccount(){

    //QCoreApplication a(argc,argv);

    accountDB=new AccountDB("../database/accountDB.sqlite");


    if (accountDB->isOpen()){
        // variables for handling user input
        int user_input;
        std::string username, password;

        while (true) {

            cout << "\nEnter 0 to quit, 1 to create account, 2 to log in \n";
            cin >> user_input;

            if (user_input == 0) break;

            // create account
            if (user_input == 1) {

                cout << "Enter user name: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                if (accountDB->accountExists(QString::fromStdString(username)))
                    cerr << "Username already exists." << endl;
                else {
                    RocketUser* currentUser= new RocketUser();
                    accountDB->addAccount(currentUser->getPlayerId(),QString::fromStdString(username),QString::fromStdString(password),currentUser->getProfile()->getID());

                    //(int accountID, const QString &userName, const QString &password, int profileid)
                    cout << "Successfully created account for " << username << endl;
                }
            }

            // log in

            if (user_input == 2) {

                std::cout << "Enter user name: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;


                std::string storedPassword=getPassword((accountDB->retrieveAccountInfo(QString::fromStdString(username),QString::fromStdString(password))).toStdString());

                if (storedPassword != password)
                    std::cerr << "Wrong username or password" << std::endl;
                else
                    std::cout << "Log in successful. Welcome " << username << "!" << std::endl;
            }

        }





    }

}

void AccountController::addFriend(){





}

std::string AccountController::getPassword(std::string accountinfo){
     std::cout << "info is " << accountinfo << std::endl;

    std::string arr[4];
    int i = 0;
    stringstream ssin(accountinfo);
    while (ssin.good() && i < 4){
        ssin >> arr[i];
        ++i;
    }
    std::cout << "password is " << arr[3] << std::endl;
    return arr[3];
}

/**
string Player::lastName(string m_full_name){
    return m_full_name.substr(0,m_full_name.find(", "));
}
**/
