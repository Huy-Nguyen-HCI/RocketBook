#include <iostream>
#include <vector>
#include <string>
#include "../database/accountdb.h"

using namespace std;

int main()
{
    /**
    // construct the database
    DBTool *dbtool = new DBTool("AccountDataBase");

    AccountDB *accountDB = new AccountDB(dbtool, 0, "AccountTable");

    // variables for handling user input
    int user_input;
    string username, password;

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

            // look for input username and store the output of lookup
            accountDB->select_username(username);
            vector<string> output = accountDB->getOutput();

            if (!output.empty())
                cerr << "Username already exists." << endl;
            else {
                accountDB->add_row(username, password);
                cout << "Successfully created account for " << username << endl;
            }

        }

        // log in
        if (user_input == 2) {

            cout << "Enter user name: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            // look for input username and store the output of lookup
            accountDB->select_username(username);
            vector<string> output = accountDB->getOutput();

            if (output.empty() || output[1] != password)
                cerr << "Wrong username or password" << endl;
            else
                cout << "Log in successful. Welcome " << username << "!" << endl;

        }

    }
**/
    return 0;
}

