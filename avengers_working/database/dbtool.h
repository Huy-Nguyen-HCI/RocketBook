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

#ifndef DBTOOL_H
#define DBTOOL_H

#include <iostream>
#include <string>
#include <sqlite3.h>

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <set>
#include <map>


/**
 * @brief The DBTool class the primary container for all the parsed model.
 */
class DBTool {

private:
    /// Name of the database.
    std::string db_name;

    /// Location of the database in the file structure.
    std::string db_location;

    sqlite3 *curr_db;

public:

    // constructor that if called will cause the program to exit
    DBTool();

    // constructors providing a mechanism for naming a database
    DBTool(std::string name);
    DBTool(const char* name);

    // constructors for identifying a location and database name
    DBTool(std::string location, std::string name);
    DBTool(const char* location, const char* name);

    // destructor that will cause the database to be closed
    ~DBTool();

    int open_db();

    // prints state of database
    void print(std::ostream &sout);

    // provides a state check to determine if database is available
    bool     db_open() { return curr_db ? true : false; }

    // returns a pointer to the current database, only
    // use when absolutely necessary
    sqlite3* db_ref()  { return curr_db; }
};

#endif // DBTOOL_H

