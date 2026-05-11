#pragma once

#include "crow/app.h"

class UsuarioController {
public:
    static crow::response criarUsuario(const crow::request& req);

    static crow::response listarUsuarios();

    static crow::response buscarUsuario(int id);

    static crow::response atualizarUsuario(
    int id,
    const crow::request& req
    );

    static crow::response deletarUsuario(int id);
};