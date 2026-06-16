#include "TreinoController.h"

#include "../services/RecomendadorTreino.h"

#include "../services/FaseMenstrual.h"
#include "../services/FaseFolicular.h"
#include "../services/FaseOvulatoria.h"
#include "../services/FaseLutea.h"

#include "../services/UsuarioService.h"
#include "../models/Usuario.h"
#include "../models/PerfilFisico.h"
#include "../models/CicloMenstrual.h"

#include "../models/EstadoUsuario.h"

#include "../database/database.h"

#include <algorithm>
#include <cctype>

#include <iostream> //para debug

//controlador para recomendar um plano de treino diário personalizado com base na fase do ciclo menstrual, perfil físico, estado do usuário
crow::response TreinoController::recomendarTreino(
    Database& db,
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

        int usuarioId =
            body["usuarioId"].i();

        int disposicao =
            body["disposicao"].i();

        std::string humor =
            body["humor"].s();

        Usuario* usuario =
            UsuarioService::buscarUsuarioPorId(
                db,
                usuarioId
            );

        if (usuario == nullptr) {

            return crow::response(
                404,
                "Usuária não encontrada"
            );
        }

        auto perfil =
            usuario->getPerfilFisico();

        auto ciclo =
            usuario->getCicloMenstrual();

        EstadoUsuario estado(
            disposicao,
            humor
        );

        //cria dados automaticamente
        DadosUsuario dados =
            DadosUsuario::criarDe(

                *usuario,

                ciclo,

                estado,

                "leve",

                0
            );

        std::string faseCiclo =
            dados.getFaseCiclo();

        std::transform(
            faseCiclo.begin(),
            faseCiclo.end(),
            faseCiclo.begin(),
            ::tolower
        );

        RecomendadorTreino recomendador;

        if (faseCiclo == "menstrual") {

            recomendador
                .definirFaseDoCiclo(
                    std::make_unique<FaseMenstrual>()
                );
        }

        else if (faseCiclo == "folicular") {

            recomendador
                .definirFaseDoCiclo(
                    std::make_unique<FaseFolicular>()
                );
        }

        else if (faseCiclo == "ovulatoria") {

            recomendador
                .definirFaseDoCiclo(
                    std::make_unique<FaseOvulatoria>()
                );
        }

        else {

            recomendador
                .definirFaseDoCiclo(
                    std::make_unique<FaseLutea>()
                );
        }

        //gera recomendação de treino
            std::string treino =
                recomendador
                    .obterRecomendacaoDiaria(
                        dados,
                        db
                    );

        crow::json::wvalue resposta;

        resposta["faseCiclo"] =
            faseCiclo;

        resposta["treino"] =
            treino;

        return crow::response(
            200,
            resposta
        );

    } catch (const std::exception& e) {

        std::cerr
            << "Erro ao gerar treino: "
            << e.what()
            << std::endl;

        return crow::response(
            500,
            e.what()
        );
}
}