#include "FaseLutea.h"

std::string FaseLutea::gerarTreino(const DadosUsuario& dados, sqlite3* db) {
    std::string tipo = normalizarObjetivo(dados.getObjetivo());
    std::string intensidade = validarIntensidade(dados.getIntensidadeRequerida());

    if (intensidade == "alta" && (dados.getDisposicao() == "baixa" || dados.getDisposicao() == "media" ||
        dados.getSentimentoHoje() == "Ansiedade" || dados.getSentimentoHoje() == "ansiedade" ||
        dados.getSentimentoHoje() == "Estressada" || dados.getSentimentoHoje() == "estressada")) {
        intensidade = "moderado";
    }

    std::string treino = "=== fase lutea ===\n";
    treino += "foco: manutenção ativa, recuperação e preparação para o próximo ciclo.\n";
    treino += "evite sobrecarga desnecessária e valorize movimento consciente.\n";

    if (tipo == "bem_estar") {
        treino += "objetivo: bem-estar. Inclua exercícios que reduzam tensão e melhorem o humor.\n";
    } else {
        treino += "objetivo: fortalecimento leve. Continue o estímulo sem exigir máxima performance.\n";
    }

    auto exercicios = buscarExercicios(db, "lutea", tipo, intensidade, dados.getRestricaoFisica());
    treino += formatarPlano(exercicios);
    return treino;
} 