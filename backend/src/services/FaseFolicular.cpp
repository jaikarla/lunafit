#include "FaseFolicular.h"

std::string FaseFolicular::gerarTreino(const DadosUsuario& dados, sqlite3* db) {
    std::string tipo = normalizarObjetivo(dados.getObjetivo());
    std::string intensidade = validarIntensidade(dados.getIntensidadeRequerida());

    std::string treino = "=== fase folicular ===\n";
    treino += "foco: aproveitar a energia crescente para construir força e resistência.\n";

    if (tipo == "fortalecimento") {
        treino += "objetivo: fortalecimento. Esta fase permite mais carga e intensidade progressiva.\n";
    } else {
        treino += "objetivo: bem-estar. Priorizando exercícios que aumentem energia e movimento fluido.\n";
    }

    auto exercicios = buscarExercicios(db, "folicular", tipo, intensidade, dados.getRestricaoFisica());
    treino += formatarPlano(exercicios);
    return treino;
} 