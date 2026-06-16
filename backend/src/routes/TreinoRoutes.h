#pragma once

#include "crow/app.h"
#include "crow/middlewares/cors.h"
#include "../controllers/TreinoController.h"
#include "../database/database.h"

inline void registrarTreinoRoutes(
    crow::App<crow::CORSHandler>& app,
    Database& db                        
) {

    CROW_ROUTE(app, "/treinos/recomendar")
    .methods(crow::HTTPMethod::POST)
    ([&db](const crow::request& req) {
        return TreinoController::recomendarTreino(db, req);
    });
}