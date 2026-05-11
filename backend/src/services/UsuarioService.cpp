#include "UsuarioService.h"

//definindo do vetor estático para armazenar os usuários cadastrados
std::vector<Usuario> UsuarioService::usuarios;

void UsuarioService::criarUsuario(const Usuario& usuario) {
    usuarios.push_back(usuario);
}

//método para gerar um novo ID único para cada usuário criado
int UsuarioService::gerarNovoId() {

    return usuarios.size() + 1;
}

//método para listar todos os usuários cadastrados
std::vector<Usuario> UsuarioService::listarUsuarios() {
    return usuarios;
}

//método para buscar um usuário por ID, retornando um ponteiro para o usuário encontrado ou nullptr se não encontrado
Usuario* UsuarioService::buscarUsuarioPorId(int id) {

    for (auto& usuario : usuarios) {

        if (usuario.getId() == id) {
            return &usuario;
        }
    }

    return nullptr;
}

//método para atualizar um usuário existente
bool UsuarioService::atualizarUsuario(
    int id,
    const Usuario& usuarioAtualizado
) {

    for (auto& usuario : usuarios) {

        if (usuario.getId() == id) {

            usuario = usuarioAtualizado;

            return true;
        }
    }

    return false;
}

//método para deletar um usuário por ID
bool UsuarioService::deletarUsuario(int id) {

    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {

        if (it->getId() == id) {
            usuarios.erase(it);
            return true;
        }
    }

    return false;
}