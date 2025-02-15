#include "database.h"
#include <iostream>

Database::Database(const std::string& db_name) {
    if(sqlite3_open(db_name.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
    } else {
        execute_query("DROP TABLE IF EXISTS logs;");
        execute_query("CREATE TABLE IF NOT EXISTS logs (id INTEGER PRIMARY KEY AUTOINCREMENT, timestamp TEXT, log_level TEXT, message TEXT);");
    }
}


Database::~Database() {
    if(db) {
        sqlite3_close(db);
    }
}

bool Database::execute_query(const std::string& query) {
    char* err_msg = nullptr;
    if(sqlite3_exec(db, query.c_str(), 0, 0, &err_msg) != SQLITE_OK) {
        std::cerr << "SQL Error: " << err_msg << std::endl;
        sqlite3_free(err_msg);
        return false;
    }
    return true;
}


sqlite3* Database::get_db() {
    return db;
}