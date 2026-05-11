#include "HistoricoTreinoDiario.h"

//Atualmente o histórico de treinos é armazenado em memória, deve ser adaptado para usar um banco de dados

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