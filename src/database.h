#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

class Database
{
public:
    Database(const std::string &db_name);
    ~Database();

    bool execute_query(const std::string &query);
    sqlite3 *get_db();

private:
    sqlite3 *db;
};

#endif