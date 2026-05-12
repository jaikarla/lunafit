#include "UsuarioController.h"

#include "../models/Usuario.h"
#include "../models/PerfilFisico.h"
#include "../models/CicloMenstrual.h"

#include "../services/UsuarioService.h"

#include "../database/database.h"

crow::response UsuarioController::criarUsuario(
    Database& db,
    const crow::request& req
) {

    std::cout << req.body << std::endl; //add para teste e conexão com frontend

    auto body = crow::json::load(req.body);

    if (!body) {
        return crow::response(400, "JSON inválido");
    }

    try {

        int id = UsuarioService::gerarNovoId(db);
        std::string nome = body["nome"].s();
        int idade = body["idade"].i();
        std::string email = body["email"].s();

        auto perfilJson = body["perfilFisico"];

        std::string objetivo = perfilJson["objetivo"].s();
        std::string nivelExperiencia =
            perfilJson["nivelExperiencia"].s();

        PerfilFisico perfilFisico(
            objetivo,
            nivelExperiencia
        );

        auto restricoes =
            perfilJson["restricoesFisicas"];

        for (const auto& r : restricoes) {
            perfilFisico.adicionarRestricao(
                r.s()
            );
        }

        auto cicloJson = body["cicloMenstrual"];

        int diaUltimaMenstruacao =
            cicloJson["diaUltimaMenstruacao"].i();

        int duracaoMediaCiclo =
            cicloJson["duracaoMediaCiclo"].i();

        CicloMenstrual cicloMenstrual(
            diaUltimaMenstruacao,
            duracaoMediaCiclo
        );

        Usuario usuario(
            id,
            idade,
            email,
            nome,
            perfilFisico,
            cicloMenstrual
        );

        UsuarioService::criarUsuario(db, usuario);

        crow::json::wvalue resposta;

        resposta["mensagem"] =
            "Usuária criada com sucesso";

        resposta["id"] = usuario.getId();
        resposta["nome"] = usuario.getNome();
        resposta["idade"] = usuario.getIdade();
        resposta["email"] = usuario.getEmail();

        return crow::response(201, resposta);

    } catch (...) {

        return crow::response(
            400,
            "Erro ao criar usuária"
        );
    }
}

//listar todos os usuários cadastrados, retornando um JSON com a lista de usuários e seus detalhes
crow::response UsuarioController::listarUsuarios(Database& db) {

    auto usuarios =
        UsuarioService::listarUsuarios(db);

    crow::json::wvalue resposta;

    resposta["usuarios"] =
        crow::json::wvalue::list();

    int index = 0;

    for (const auto& usuario : usuarios) {

        crow::json::wvalue u;

        u["id"] = usuario.getId();
        u["nome"] = usuario.getNome();
        u["idade"] = usuario.getIdade();
        u["email"] = usuario.getEmail();

        auto perfil =
            usuario.getPerfilFisico();

        u["perfilFisico"]["objetivo"] =
            perfil.getObjetivo();

        u["perfilFisico"]["nivelExperiencia"] =
            perfil.getNivelExperiencia();

        auto restricoes =
            perfil.getRestricoes();

        for (int i = 0; i < restricoes.size(); i++) {

            u["perfilFisico"]
             ["restricoesFisicas"][i] =
                restricoes[i];
        }

        auto ciclo =
            usuario.getCicloMenstrual();

        u["cicloMenstrual"]
         ["diaUltimaMenstruacao"] =
            ciclo.getDiaUltimaMenstruacao();

        u["cicloMenstrual"]
         ["duracaoMediaCiclo"] =
            ciclo.getDuracaoMediaCiclo();

        resposta["usuarios"][index++] =
            std::move(u);
    }

    return crow::response(200, resposta);
}

//buscar um usuário por ID, retornando um JSON com os detalhes do usuário encontrado ou uma mensagem de erro se não encontrado
crow::response UsuarioController::buscarUsuario(
    Database& db,
    int id
) {

    Usuario* usuario =
        UsuarioService::buscarUsuarioPorId(db, id);

    if (usuario == nullptr) {

        return crow::response(
            404,
            "Usuária não encontrada"
        );
    }

    crow::json::wvalue resposta;

    resposta["id"] = usuario->getId();
    resposta["nome"] = usuario->getNome();
    resposta["idade"] = usuario->getIdade();
    resposta["email"] = usuario->getEmail();

    return crow::response(200, resposta);
}

//atualizar um usuário existente
crow::response UsuarioController::atualizarUsuario(
    Database& db,
    int id,
    const crow::request& req
) {

    auto body = crow::json::load(req.body);

    if (!body) {
        return crow::response(400, "JSON inválido");
    }

    try {

        std::string nome = body["nome"].s();
        int idade = body["idade"].i();
        std::string email = body["email"].s();

        auto perfilJson = body["perfilFisico"];

        std::string objetivo =
            perfilJson["objetivo"].s();

        std::string nivelExperiencia =
            perfilJson["nivelExperiencia"].s();

        PerfilFisico perfilFisico(
            objetivo,
            nivelExperiencia
        );

        auto restricoes =
            perfilJson["restricoesFisicas"];

        for (const auto& r : restricoes) {

            perfilFisico.adicionarRestricao(
                r.s()
            );
        }

        auto cicloJson =
            body["cicloMenstrual"];

        int diaUltimaMenstruacao =
            cicloJson["diaUltimaMenstruacao"].i();

        int duracaoMediaCiclo =
            cicloJson["duracaoMediaCiclo"].i();

        CicloMenstrual cicloMenstrual(
            diaUltimaMenstruacao,
            duracaoMediaCiclo
        );

        Usuario usuarioAtualizado(
            id,
            idade,
            email,
            nome,
            perfilFisico,
            cicloMenstrual
        );

        bool atualizado =
            UsuarioService::atualizarUsuario(
                db,
                id,
                usuarioAtualizado
            );

        if (!atualizado) {

            return crow::response(
                404,
                "Usuária não encontrada"
            );
        }

        return crow::response(
            200,
            "Usuária atualizada com sucesso"
        );

    } catch (...) {

        return crow::response(
            400,
            "Erro ao atualizar usuária"
        );
    }
}

//deltar um usuário
crow::response UsuarioController::deletarUsuario(
    Database& db,
    int id
) {

    bool removido =
        UsuarioService::deletarUsuario(db, id);

    if (!removido) {

        return crow::response(
            404,
            "Usuária não encontrada"
        );
    }

    return crow::response(
        200,
        "Usuária removida com sucesso"
    );
}