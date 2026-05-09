#pragma once
#include <vector>
#include "TreinoRealizado.h"

//histórico de treinos realizados pela usuária, com data e nível de disposição
class HistoricoTreinoDiario {
private:
    std::vector<TreinoRealizado> historico;

public:
    void registrarTreino(const TreinoRealizado& treino);

    std::vector<TreinoRealizado> listarTreinos() const;
};