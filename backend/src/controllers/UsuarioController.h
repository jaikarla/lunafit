#pragma once

#include "crow/app.h"
#include "../database/database.h"

class UsuarioController {
public:
    static crow::response criarUsuario(
        Database& db,
        const crow::request& req
    );

    static crow::response listarUsuarios(
        Database& db
    );

    static crow::response buscarUsuario(
        Database& db,
        int id
    );

    static crow::response atualizarUsuario(
        Database& db,
        int id,                        
        const crow::request& req
    );

    static crow::response deletarUsuario(
        Database& db,
        int id
    );
};