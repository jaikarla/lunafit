#include "HistoricoController.h"

#include "../services/UsuarioService.h"

#include "../models/TreinoRealizado.h"
#include "../models/Usuario.h"

//Controlador para lidar com as requisições relacionadas ao histórico de treinos diários da usuária
crow::response HistoricoController::registrarTreino(
    int usuarioId,
    const crow::request& req
) {

    auto body = crow::json::load(req.body);

    if (!body) {

        return crow::response(
            400,
            "JSON inválido"
        );
    }

    try {

        std::string data =
            body["data"].s();

        int nivelDisposicao =
            body["nivelDisposicao"].i();

        Usuario* usuario =
            UsuarioService
                ::buscarUsuarioPorId(
                    usuarioId
                );

        if (!usuario) {

            return crow::response(
                404,
                "Usuária não encontrada"
            );
        }

        TreinoRealizado treino(
            data,
            nivelDisposicao
        );

        usuario
            ->getHistorico()
            .registrarTreino(treino);

        return crow::response(
            201,
            "Treino registrado com sucesso"
        );

    } catch (...) {

        return crow::response(
            500,
            "Erro ao registrar treino"
        );
    }
}

//Controlador para lidar com as requisições relacionadas à listagem do histórico de treinos diários da usuária
crow::response HistoricoController::listarHistorico(
    int usuarioId
) {

    Usuario* usuario =
        UsuarioService
            ::buscarUsuarioPorId(
                usuarioId
            );

    if (!usuario) {

        return crow::response(
            404,
            "Usuária não encontrada"
        );
    }

    auto historico =
        usuario
            ->getHistorico()
            .listarTreinos();

    crow::json::wvalue resposta;

    int i = 0;

    for (const auto& treino : historico) {

        resposta[i]["data"] =
            treino.getData();

        resposta[i]["nivelDisposicao"] =
            treino.getNivelDisposicao();

        i++;
    }

    return crow::response(
        200,
        resposta
    );
}