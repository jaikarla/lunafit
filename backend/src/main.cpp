#include <iostream>

#include "crow/app.h" //inclui a biblioteca Crow para criar o servidor web

#include "database/Database.h" //inclui a classe Database para gerenciar a conexão com o banco de dados

//inclui os arquivos de rotas para cada entidade do sistema
#include "routes/UsuarioRoutes.h"
#include "routes/TreinoRoutes.h"
#include "routes/HistoricoRoutes.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    Database db;

    if (!db.connect("lunafit.db")) {

        std::cerr
            << "Nao foi possivel conectar ao banco."
            << std::endl;

        return 1;
    }

    if (!db.executeFile("schema.sql")) {

        std::cerr
            << "Erro ao criar tabelas."
            << std::endl;
    }

    if (!db.executeFile("seed.sql")) {

        std::cerr
            << "Erro ao carregar seed."
            << std::endl;
    }

    std::cout
        << "Banco conectado com sucesso."
        << std::endl;

    crow::SimpleApp app;

    registrarUsuarioRoutes(app);

    registrarTreinoRoutes(app);

    registrarHistoricoRoutes(app);

    std::cout
        << "Servidor iniciado em:"
        << std::endl;

    std::cout
        << "http://localhost:18080"
        << std::endl;

    app.port(18080)
       .multithreaded()
       .run();

    db.close();

    return 0;
}