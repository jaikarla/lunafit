#include "TreinoController.h"

#include "../services/RecomendadorTreino.h"

#include "../services/FaseMenstrual.h"
#include "../services/FaseFolicular.h"
#include "../services/FaseOvulatoria.h"
#include "../services/FaseLutea.h"

#include "../models/EstadoUsuario.h"

#include "../database/database.h"

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

        std::string faseCiclo =
            body["faseCiclo"].s();

        std::string objetivo =
            body["objetivo"].s();

        std::string restricaoFisica =
            body["restricaoFisica"].s();

        std::string intensidade =
            body["intensidade"].s();

        std::string nivelExperiencia =
            body["nivelExperiencia"].s();

        int disposicao =
            body["disposicao"].i();

        std::string humor =
            body["humor"].s();

        EstadoUsuario estado(
            disposicao,
            humor
        );

        DadosUsuario dados(
            faseCiclo,
            objetivo,
            restricaoFisica,
            intensidade,
            nivelExperiencia,
            disposicao <= 3 ? "baixa"
            : disposicao <= 6 ? "media"
            : "alta",
            humor
        );
        
        //definir a estratégia de treino com base na fase do ciclo menstrual e gerar o plano de treino recomendado usando o RecomendadorTreino
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

    } catch (...) {

        return crow::response(
            500,
            "Erro ao gerar treino"
        );
    }
}