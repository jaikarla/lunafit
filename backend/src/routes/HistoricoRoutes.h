#pragma once

#include "crow/app.h"

#include "../controllers/HistoricoController.h"

inline void registrarHistoricoRoutes(
    crow::SimpleApp& app
) {

    CROW_ROUTE(
        app,
        "/historico/<int>"
    )

    .methods(crow::HTTPMethod::POST)

    ([](
        const crow::request& req,
        int usuarioId
    ) {

        return HistoricoController
            ::registrarTreino(
                usuarioId,
                req
            );
    });

    CROW_ROUTE(
        app,
        "/historico/<int>"
    )

    .methods(crow::HTTPMethod::GET)

    ([](int usuarioId) {

        return HistoricoController
            ::listarHistorico(
                usuarioId
            );
    });
}