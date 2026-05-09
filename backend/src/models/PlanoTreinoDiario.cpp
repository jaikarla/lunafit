#include "PlanoTreinoDiario.h"

//plano de treino diário gerado para a usuária, com data de geração e lista de treinos
PlanoTreinoDiario::PlanoTreinoDiario(
    int id,
    std::string dataGeracao
)
    : id(id),
      dataGeracao(dataGeracao) {}

void PlanoTreinoDiario::adicionarTreino(
    const Treino& treino
) {
    treinos.push_back(treino);
}

std::vector<Treino>
PlanoTreinoDiario::getTreinos() const {
    return treinos;
}

std::string PlanoTreinoDiario::getDataGeracao() const {
    return dataGeracao;
}