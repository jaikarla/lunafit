#pragma once

#include "crow/app.h"
#include "crow/middlewares/cors.h"
#include "../controllers/UsuarioController.h"
#include "../database/database.h"

inline void registrarUsuarioRoutes(
    crow::App<crow::CORSHandler>& app,
    Database& db
) {

    CROW_ROUTE(app, "/usuarios")
    .methods(crow::HTTPMethod::POST)
    ([&db](const crow::request& req) {
        return UsuarioController::criarUsuario(db, req);
    });

    CROW_ROUTE(app, "/usuarios")
    .methods(crow::HTTPMethod::GET)
    ([&db]() {
        return UsuarioController::listarUsuarios(db);
    });

    CROW_ROUTE(app, "/usuarios/<int>")
    .methods(crow::HTTPMethod::GET)
    ([&db](int id) {
        return UsuarioController::buscarUsuario(db, id);
    });

    CROW_ROUTE(app, "/usuarios/<int>")
    .methods(crow::HTTPMethod::PUT)
    ([&db](const crow::request& req, int id) {
        return UsuarioController::atualizarUsuario(db, id, req);
    });

    CROW_ROUTE(app, "/usuarios/<int>")
    .methods(crow::HTTPMethod::Delete)
    ([&db](int id) {
        return UsuarioController::deletarUsuario(db, id);
    });
}