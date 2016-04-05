#ifndef ACCOUNTDB_H
#define ACCOUNTDB_H
#include "dbtable.h"
#include <string>
#include <vector>

/**
 * @brief The AccountDB class is a database that stores account information.
 */
class AccountDB : public DBTable
{
public:
    AccountDB(DBTool *db, int model, std::string name);
    ~AccountDB();

    // overloaded method, generate new create command
    virtual void store_create_sql();

    // overloaded method, generate new insert command
    virtual void store_add_row_sql();

    bool add_row(std::string username, std::string password);

    bool select_all();

    bool select_username(std::string username);

    std::vector<std::string> getOutput();

private:
    static std::vector<std::string> output;

    // static functions to be passed as callback
    static int cb_select_all(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);

    static int cb_add_row(void  *data,
                   int    argc,
                   char **argv,
                   char **azColName);
};

#endif // ACCOUNTDB_H




