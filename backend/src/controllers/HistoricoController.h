#pragma once

#include "crow/app.h"

class HistoricoController {

public:

    static crow::response registrarTreino(
        int usuarioId,
        const crow::request& req
    );

    static crow::response listarHistorico(
        int usuarioId
    );
};