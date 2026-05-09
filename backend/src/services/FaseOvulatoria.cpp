#include "FaseOvulatoria.h"

std::string FaseOvulatoria::gerarTreino(const DadosUsuario& dados, sqlite3* db) {
    std::string tipo = normalizarObjetivo(dados.getObjetivo());
    std::string intensidade = validarIntensidade(dados.getIntensidadeRequerida());

    if (intensidade == "moderado" && dados.getNivelExperiencia() == "avancado") {
        intensidade = "alta";
    }

    std::string treino = "=== fase ovulatoria ===\n";
    treino += "foco: aproveitar o pico de energia e força para desempenho máximo.\n";
    treino += "execute treinos que desafiem a capacidade sem perder a técnica.\n";

    if (tipo == "fortalecimento") {
        treino += "objetivo: fortalecimento. Priorize força, potência e excesso de carga dentro do seguro.\n";
    } else {
        treino += "objetivo: bem-estar. Escolha exercícios que mantenham a energia alta e o corpo ativo.\n";
    }

    auto exercicios = buscarExercicios(db, "ovulatoria", tipo, intensidade, dados.getRestricaoFisica());
    treino += formatarPlano(exercicios);
    return treino;
} 