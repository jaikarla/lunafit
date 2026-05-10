#pragma once

#include "crow/app.h"

#include "../controllers/TreinoController.h"

inline void registrarTreinoRoutes(
    crow::SimpleApp& app
) {

    CROW_ROUTE(
        app,
        "/treinos/recomendar"
    )

    .methods(crow::HTTPMethod::POST)

    ([](const crow::request& req) {

        return TreinoController
            ::recomendarTreino(req);
    });
}