#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "sqlite/sqlite3.h"

class Database {
private:
    sqlite3* db;

public:
    Database();
    ~Database();

    bool connect(const std::string& dbPath);
    void close();

    bool execute(const std::string& sql);
};

#endif