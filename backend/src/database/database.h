#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "sqlite/sqlite3.h"

class Database {
private:
    sqlite3* db;

public:
    // Construor e Destrutor
    Database(); 
    ~Database();

    // Abre o arquivo de banco de dados
    bool connect(const std::string& dbPath);
    void close();

    // Executa um comando SQL recebido como texto
    bool execute(const std::string& sql);

    // Lê um arquivo .sql e executa
    bool executeFile(const std:: string& filePath);

    sqlite3* getDb() { return db; }
};

#endif