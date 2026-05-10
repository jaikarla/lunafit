#include "crow/app.h"
#include "routes/UsuarioRoutes.h"
#include "routes/TreinoRoutes.h"
#include "routes/HistoricoRoutes.h"

#include <iostream>

int main() {
    crow::SimpleApp app;

    registrarUsuarioRoutes(app);
    registrarTreinoRoutes(app);
    registrarHistoricoRoutes(app);

    std::cout << "Servidor iniciando na porta 18080..." << std::endl;

    app.port(18080).multithreaded().run();

    return 0;
}