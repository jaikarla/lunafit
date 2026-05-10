#pragma once

#include "crow/app.h"
#include "crow/middlewares/cors.h"

#include "../controllers/TreinoController.h"

inline void registrarTreinoRoutes(
    crow::App<crow::CORSHandler>& app
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