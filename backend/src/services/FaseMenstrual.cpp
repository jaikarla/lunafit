#include "FaseMenstrual.h"

std::string FaseMenstrual::gerarTreino(const DadosUsuario& dados, sqlite3* db) {
    std::string tipo = normalizarObjetivo(dados.getObjetivo());
    std::string intensidade = validarIntensidade(dados.getIntensidadeRequerida());

    // na fase menstrual, não usamos intensidade alta para evitar treinos muito agressivos
    if (intensidade == "alta") {
        intensidade = "moderado";
    }

    std::string treino = "=== fase menstrual ===\n";
    treino += "foco: respeitar o corpo, priorizar conforto e recuperação.\n";
    treino += "esta fase responde melhor a movimentos suaves e bem-estar.\n";

    if (tipo == "bem_estar") {
        treino += "objetivo: bem-estar. Recomenda-se ênfase em relaxamento e mobilidade leve.\n";
    } else {
        treino += "objetivo: fortalecimento leve. Priorize exercícios sem impacto excessivo.\n";
    }

    auto exercicios = buscarExercicios(db, "menstrual", tipo, intensidade, dados.getRestricaoFisica());
    treino += formatarPlano(exercicios);
    return treino;
} 