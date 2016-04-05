#include "accountdb.h"

std::vector<std::string> AccountDB::output; /**< stores the output after each SQL execution **/


/**
 * @brief GameTable::GameTable the class constructor.
 * @param db the pointer to a container of type DBTool.
 * @param model this model's id.
 * @param name this table's name.
 */
AccountDB::AccountDB(DBTool *db, int model, std::string name) :
    DBTable(db, name)
{
    store_add_row_sql();

    store_create_sql();

    build_table();
}

/**
 * @brief AccountDB::~AccountDB the class destructor
 */
AccountDB::~AccountDB() {

}

/**
 * @brief AccountDB::store_add_row_sql construct the add row SQL command.
 */
void AccountDB::store_add_row_sql() {
    sql_template = "SELECT name ";
    sql_template += "FROM  sqlite_master ";
    sql_template += " type = \"table\"";
    sql_template += ";";
}

/**
 * @brief AccountDB::store_create_sql construct the create table SQL command.
 */
void AccountDB::store_create_sql() {

    sql_create = "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "username TEXT NOT NULL UNIQUE, ";
    sql_create += "password TEXT NOT NULL";
    sql_create += " )";
}

/**
 * @brief AccountDB::add_row add an Account entry to the database
 * @param username the account's username.
 * @param password the account's password.
 * @return the return code of SQL execution.
 */
bool AccountDB::add_row(std::string username, std::string password) {

    // initialize variables and SQL command
    int retCode = 0;
    char *zErrMsg = 0;

    sql_add_row += "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " (username, password) ";
    sql_add_row += " VALUES (";
    sql_add_row += "\"" + username + "\"";
    sql_add_row += ", ";
    sql_add_row += "\"" + password + "\"";
    sql_add_row += " );";

    // execute SQL command
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row,
                           this,
                           &zErrMsg);

    if (retCode != SQLITE_OK) {
        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }
    return retCode;
}

/**
 * @brief cb_cb_add_row specifies the callback action of add_row.
 * @param data a pointer to the table object.
 * @param argc the number of columns of an entry.
 * @param argv the pointer to the array of information.
 * @param azColName the pointer to the array of column names.
 * @return 0.
 */
int AccountDB::cb_add_row(void  *data,
                         int    argc,
                         char **argv,
                         char **azColName)
{
    return 0;
}

/**
 * @brief AccountDB::select_username look up an Account with the specified username in the database.
 * @param username the input username.
 * @return the return code of SQl execution.
 */
bool AccountDB::select_username(std::string username) {

    // initialize variables and build SQL command
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_select_all  = "SELECT * FROM ";
    sql_select_all += table_name;
    sql_select_all += " WHERE username = ";
    sql_select_all += "\"" + username + "\"";
    sql_select_all += ";";

    // clear the output string before new output is generated
    output.clear();

    // execute SQL
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all.c_str(),
                           cb_select_all,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/**
 * @brief AccountDB::select_all select all entries from the database.
 * @return the return code of SQl execution.
 */
bool AccountDB::select_all() {

    // initialize variables and build SQL command
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_select_all  = "SELECT * FROM ";
    sql_select_all += table_name;
    sql_select_all += ";";

    // clear the output string before new output is generated
    output.clear();

    // execute SQL
    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all.c_str(),
                           cb_select_all,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/**
 * @brief AccountDB::cb_select_all callback function for select all.
 *
 * Stores the output data in a container.
 * @param data a pointer to the table object.
 * @param argc the number of columns of an entry.
 * @param argv the pointer to the array of information.
 * @param azColName the pointer to the array of column names.
 * @return 0.
 */
int AccountDB::cb_select_all(void  *data,
                         int    argc,
                         char **argv,
                         char **azColName)
{

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    AccountDB *obj = (AccountDB *) data;

    // argv is the array that stores information about the entry
    for (int i = 0; i < argc; i++) {
        output.push_back(std::string(argv[i]));
    }
    return 0;
}

/**
 * @brief AccountDB::getOutput get the output container.
 * @return the static output container.
 */
std::vector<std::string> AccountDB::getOutput() {
    return output;
}
