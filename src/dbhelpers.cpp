#include "dbhelpers.h"
#include <iostream>

int create_table(sqlite3* db) {
    const char* create_table_sql = 
        "CREATE TABLE IF NOT EXISTS paths ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "path TEXT NOT NULL);";

    char* err_msg = nullptr;
    int rc = sqlite3_exec(db, create_table_sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << err_msg << std::endl;
        sqlite3_free(err_msg);
        return rc;
    }

    return SQLITE_OK;
}

int insert_path(sqlite3* db, const char* path) {
    const char* insert_sql = "INSERT INTO paths (path) VALUES (?);";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, insert_sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    sqlite3_bind_text(stmt, 1, path, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Failed to insert path: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    return rc;
}
