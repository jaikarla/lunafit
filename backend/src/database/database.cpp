#include "Database.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Construor
Database::Database() {
    db = nullptr; 
}

// Destrutor - fechar quando terminar
Database::~Database() {
    close();
}

// Abre o arquivo no caminho informado
bool Database::connect(const std::string& dbPath) {
    int rc = sqlite3_open(dbPath.c_str(), &db);

    if (rc) {
        std::cerr << "Erro ao abrir banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // verificação de chaves estrangeiras
    execute("PRAGMA foreign_keys = ON;");

    std::cout << "Banco de dados aberto" << std::endl;
    return true;
}

// Fechar conexão com o banco de dados
void Database::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

// executa comando sql
bool Database::execute(const std::string& sql) {
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro SQL (codigo " << rc << "): " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}

// leitura e execução de arquivo sql
bool Database::executeFile(const std::string& filePath) {
    std::ifstream arquivo(filePath);

    if (!arquivo.is_open()) {
        std::cerr << "Erro: nao foi possivel abrir o arquivo: " << filePath << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << arquivo.rdbuf();
    std::string sql = buffer.str();

    if (sql.empty()) {
        std::cerr << "Arquivo vazio: " << filePath << std::endl;
        return false;
    }

    std::cout << "Executando: " << filePath << std::endl;
    return execute(sql);
}