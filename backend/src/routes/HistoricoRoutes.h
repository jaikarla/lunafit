#pragma once

#include "crow/app.h"
#include "crow/middlewares/cors.h"
#include "../controllers/HistoricoController.h"
#include "../database/database.h"

inline void registrarHistoricoRoutes(
    crow::App<crow::CORSHandler>& app, 
    Database& db
) {

    CROW_ROUTE(app, "/historico/<int>")
    .methods(crow::HTTPMethod::POST)
    ([&db](const crow::request& req, int usuarioId) {
        return HistoricoController::registrarTreino(db, usuarioId, req);
    });

    CROW_ROUTE(app, "/historico/<int>")
    .methods(crow::HTTPMethod::GET)
    ([&db](int usuarioId) {
        return HistoricoController::listarHistorico(db, usuarioId);
    });
}