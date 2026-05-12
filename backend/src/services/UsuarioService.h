#pragma once

#include "../models/Usuario.h"
#include "../database/database.h"
#include <vector>

class UsuarioService {
public:
    static void criarUsuario(
        Database& db,
        const Usuario& usuario
    );

    static int gerarNovoId(Database& db);

    static std::vector<Usuario> listarUsuarios(
        Database& db
    );

    static Usuario* buscarUsuarioPorId(
        Database& db,
        int id
    );

    static bool atualizarUsuario(
        Database& db,
        int id,
        const Usuario& usuarioAtualizado
    );

    static bool deletarUsuario(
        Database& db,
        int id
    );

private:
    static std::vector<Usuario> usuarios;
    static Usuario usuarioCache;
};