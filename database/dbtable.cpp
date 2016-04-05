/*********************************************************************

Copyright (C) 2015 Jeffrey O. Pfaffmann

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*********************************************************************/

#include "dbtable.h"

/**
 * @brief DBTable::DBTable the class default constructor.
 *
 * Exits automatically because not enough information is provided.
 */
DBTable::DBTable() {
    std::cerr << "Table name must be provided "
              << "for DBTable Class during "
              << "construction.\n"
              << "Exiting\n";
    exit(-1);
}

/**
 * @brief DBTable::DBTable the class constructor that takes DBTool and name input.
 * @param db the pointer to the database.
 * @param name the name of this table.
 */
DBTable::DBTable(DBTool *db,
                 std::string name    ) {

    // store table name and reference to db.
    curr_db     = db;
    table_name  = name;

    // register the different sql calls
    store_exist_sql();
    store_create_sql();
    store_drop_sql();
    store_size_sql();

    sql_add_row = "";
}

/**
 * @brief DBTable::build_table check if table exists and build the table if needed.
 */
void DBTable::build_table() {

    // determine if table exists
    exist();
    if (!table_exists) {

        // if it does not exist create table
        create();
    }
}

/**
 * @brief DBTable::~DBTable the class destructor.
 */
DBTable::~DBTable() {
    // std::cerr << "Deconstructing table object "
    // 	    << table_name
    // 	    << std::endl;
}

/**
 * @brief DBTable::store_template_sql build the sql template string.
 */
void DBTable::store_template_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}


/**
 * @brief DBTable::store_exist_sql build the SQL exist string.
 */
void DBTable::store_exist_sql() {

    sql_exist  =  "SELECT count(*) ";
    sql_exist += "FROM   sqlite_master ";
    sql_exist += "WHERE";
    sql_exist += "    type = \"table\" ";
    sql_exist += "and name = \"" + table_name + "\"";
    sql_exist += ";";

}

/**
 * @brief DBTable::store_create_sql build the SQL create string.
 */
void DBTable::store_create_sql() {

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  item0 TEXT NOT NULL,";
    sql_create += "  item1 INT  NOT NULL, ";
    sql_create += "  item2 CHAR(50),";
    sql_create += "  item3 REAL";
    sql_create += " );";

}

/**
 * @brief DBTable::store_drop_sql build the SQL drop table string.
 */
void DBTable::store_drop_sql() {

    sql_drop =  "DROP TABLE ";
    sql_drop += table_name;
    sql_drop += ";";

}

/**
 * @brief DBTable::store_size_sql build the SQL size string.
 */
void DBTable::store_size_sql() {

    sql_size =  "SELECT count(*) ";
    sql_size += "FROM ";
    sql_size += table_name;
    sql_size += ";";

}


/**
 * @brief DBTable::dbtemplate build the table template using the template string.
 * @return the return code of SQL's execution.
 */
int DBTable::dbtemplate() {

    int   retCode = 0;
    char *zErrMsg = 0;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_template.c_str(),
                           cb_template,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << sql_template
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/**
 * @brief cb_template the callback function for building table template.
 * @param data a pointer to the table object.
 * @param argc the number of columns of an entry.
 * @param argv the pointer to the array of information.
 * @param azColName the pointer to the array of column names.
 * @return 0.
 */
int cb_template(void  *data,
                int    argc,
                char **argv,
                char **azColName){

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    return 0;
}

/**
 * @brief DBTable::exist check if the table exists using the exist string.
 * @return the return code of SQL's execution.
 */
bool DBTable::exist() {

    int   retCode = 0;
    char *zErrMsg = 0;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_exist.c_str(),
                           cb_exist,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << sql_exist
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/**
 * @brief cb_exist the callback function for checking if the table exists
 * @param data a pointer to the table object.
 * @param argc the number of columns of an entry.
 * @param argv the pointer to the array of information.
 * @param azColName the pointer to the array of column names.
 * @return 0.
 */
int cb_exist(void  *data,
             int    argc,
             char **argv,
             char **azColName){


    if(argc != 1) {
        std::cerr << "More than one item returned "
                  << "argc = " << argc
                  << std::endl;
    }

    DBTable *obj = (DBTable *) data;

    //std::cerr << atoi(argv[0]) << "\n";

    if (atoi(argv[0])) {
        //std::cerr << "setting exists\n";
        obj->set_exists();
    } else {
        //std::cerr << "unsetting exists\n";
        obj->unset_exists();
    }

    return 0;
}

/**
 * @brief DBTable::create create the table.
 * @return the return code of SQL's execution.
 */
bool DBTable::create() {

    int   retCode = 0;
    char *zErrMsg = 0;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_create.c_str(),
                           cb_create,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << sql_create
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/**
 * @brief cb_create the callback function for creating the table.
 * @param data a pointer to the table object.
 * @param argc the number of columns of an entry.
 * @param argv the pointer to the array of information.
 * @param azColName the pointer to the array of column names.
 * @return 0.
 */
int cb_create(void  *data,
              int    argc,
              char **argv,
              char **azColName){


    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    DBTable *obj = (DBTable *) data;

    // std::cout << "------------------------------\n";
    // std::cout << obj->get_name()
    // 	    << std::endl;

    // for(i = 0; i < argc; i++){
    //   std::cout << azColName[i]
    // 	      << " = "
    // 	      <<  (argv[i] ? argv[i] : "NULL")
    // 	      << std::endl;
    // }

    return 0;
}

/**
 * @brief DBTable::drop drop the table.
 * @return the return code of SQL's execution.
 */
bool DBTable::drop() {

    int   retCode = 0;
    char *zErrMsg = 0;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_drop.c_str(),
                           cb_drop,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << sql_drop
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

/**
 * @brief cb_drop the callback function for dropping the table.
 * @param data a pointer to the table object.
 * @param argc the number of columns of an entry.
 * @param argv the pointer to the array of information.
 * @param azColName the pointer to the array of column names.
 * @return 0.
 */
int cb_drop(void  *data,
            int    argc,
            char **argv,
            char **azColName){


    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    DBTable *obj = (DBTable *) data;

    // std::cout << "------------------------------\n";
    // std::cout << obj->get_name()
    // 	    << std::endl;

    // for(i = 0; i < argc; i++){
    //   std::cout << azColName[i]
    // 	      << " = "
    // 	      <<  (argv[i] ? argv[i] : "NULL")
    // 	      << std::endl;
    // }

    return 0;
}

/**
 * @brief DBTable::size get the size of the table.
 * @return the size of the table.
 */
int DBTable::size() {

    int   retCode = 0;
    char *zErrMsg = 0;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_size.c_str(),
                           cb_size,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << sql_size
                  << std::endl;

        std::cerr << "SQL error: "
                  << zErrMsg
                  << std::endl;

        sqlite3_free(zErrMsg);
    }

    return row_cnt;
}

/**
 * @brief cb_size the callback function for getting the size of the table.
 * @param data a pointer to the table object.
 * @param argc the number of columns of an entry.
 * @param argv the pointer to the array of information.
 * @param azColName the pointer to the array of column names.
 * @return 0.
 */
int cb_size(void  *data,
            int    argc,
            char **argv,
            char **azColName){


    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    DBTable *obj = (DBTable *) data;

    obj->set_size(atoi(argv[0]));

    return 0;
}

/**
 * @brief DBTable::get_name get the name of the table.
 * @return the table's name.
 */
std::string DBTable::get_name() {
    return table_name;
}




