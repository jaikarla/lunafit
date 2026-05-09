#include "crow/app.h"

int main() {
    try {
        crow::SimpleApp app;

        CROW_ROUTE(app, "/")([]() {
            return "LunaFit API funcionando!";
        });

        std::cout << "Servidor iniciando..." << std::endl;

        app.port(18080).multithreaded().run();

    } catch (const std::exception& e) {
        std::cerr << "ERRO: " << e.what() << std::endl;
    }

    std::cout << "Programa encerrado." << std::endl;

    return 0;
}