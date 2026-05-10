#pragma once

#include "crow/app.h"

#include "../controllers/UsuarioController.h"

void registrarUsuarioRoutes(
    crow::SimpleApp& app
) {
    
    CROW_ROUTE(app, "/usuarios")
    .methods(crow::HTTPMethod::POST)
    ([](const crow::request& req) {

        return UsuarioController
            ::criarUsuario(req);
    });

    CROW_ROUTE(app, "/usuarios")
    .methods(crow::HTTPMethod::GET)
    ([]() {

        return UsuarioController
            ::listarUsuarios();
    });

    CROW_ROUTE(app, "/usuarios/<int>")
    .methods(crow::HTTPMethod::GET)
    ([](int id) {

        return UsuarioController
            ::buscarUsuario(id);
    });

    CROW_ROUTE(app, "/usuarios/<int>")
    .methods(crow::HTTPMethod::PUT)
    ([](const crow::request& req, int id) {

    return UsuarioController
        ::atualizarUsuario(id, req);
});

    CROW_ROUTE(app, "/usuarios/<int>")
    .methods(crow::HTTPMethod::Delete) //DELETE é uma palavra reservada em C++, então usa Delete apenas com D maiúsculo
    ([](int id) {

        return UsuarioController
            ::deletarUsuario(id);
    });
}