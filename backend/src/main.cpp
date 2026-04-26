#include <iostream>
#include "database/Database.h"

int main() {
    Database db;

    // Abre o arquivo que possui o executável do banco de dados 
    // Se não existir o arquivo, cria-se automaticamente
    if (!db.connect("../backend/src/database/lunafit.db"))
        return 1;

    // leitura e criação das tabelas (schema)
    if (!db.executeFile("../backend/src/database/schema.sql")) {
        std::cerr << "Aviso: algum item do schema retornou erro (ver acima)" << std::endl;
    } else {
        std::cout << "Tabelas criadas com sucesso!" << std::endl;
    }

    // Teste simples de inserção de dados
    bool inseriu = db.execute(
        "INSERT OR IGNORE INTO users (nome, email, idade) "
        "VALUES ('Samara', 'samara@gmail.com', 19);"
    );

    if (inseriu) {
        std::cout << "Teste de insercao OK." << std::endl;
    } else {
        std::cerr << "Teste de insercao falhou." << std::endl;
    }

    // leitura e execução do catalogo (seed)
    db.executeFile("../backend/src/database/seed.sql");

    db.close();
    return 0;
}