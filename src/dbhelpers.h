// dbhelpers.h
#ifndef DBHELPERS_H
#define DBHELPERS_H

#include <filesystem>
#include <sqlite3.h>

namespace fs = std::filesystem;

extern "C"{
int create_table(sqlite3* db);
int insert_path(sqlite3* db, const char* path);
}

#endif // DBHELPERS_H
