#include "HistoricoTreinoDiario.h"

//histórico de treinos realizados pela usuária, com data e nível de disposição
void HistoricoTreinoDiario::registrarTreino(
    const TreinoRealizado& treino
) {
    historico.push_back(treino);
}

std::vector<TreinoRealizado>
HistoricoTreinoDiario::listarTreinos() const {
    return historico;
}