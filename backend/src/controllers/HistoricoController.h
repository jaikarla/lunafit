#pragma once

#include "crow/app.h"

#include "../database/database.h"

class HistoricoController {

public:

    static crow::response registrarTreino(
        Database& db,
        int usuarioId,
        const crow::request& req
    );

    static crow::response listarHistorico(
        Database& db,
        int usuarioId
    );
};