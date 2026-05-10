#pragma once

#include "../models/Usuario.h"

#include <vector>

class UsuarioService {
private:
    static std::vector<Usuario> usuarios;

public:
    static void criarUsuario(const Usuario& usuario);

    static int gerarNovoId();

    static std::vector<Usuario> listarUsuarios();

    static Usuario* buscarUsuarioPorId(int id);

    static bool atualizarUsuario(
    int id,
    const Usuario& usuarioAtualizado
    );

    static bool deletarUsuario(int id);
};