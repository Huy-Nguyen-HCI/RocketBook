#include "accountcontroller.h"

using namespace std;


AccountController::AccountController(){
/*If user selection=2, add friend
 *                 =1, create account
 *
 *
 *
 * */
}

void AccountController::createAccount(){



   // QCoreApplication a(argc,argv);

    accountDB=new AccountDB("../ProfileDB.db");


    if (accountDB->isOpen()){
         // variables for handling user input
        int user_input;
        std::string username, password;

        cout << "\nEnter 0 to quit, 1 to create account, 2 to log in \n";
        cin >> user_input;

    while (true) {

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
    std::string cut=accountinfo.substr(accountinfo.find(" ")+1);
    cut=cut.substr(cut.find(" ")+1);
    return cut.substr(0,cut.find(" "));

}

/**
string Player::lastName(string m_full_name){
    return m_full_name.substr(0,m_full_name.find(", "));
}
**/
