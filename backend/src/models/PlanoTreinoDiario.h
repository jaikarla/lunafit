#pragma once
#include <vector>
#include <string>
#include "Treino.h"

//plano de treino diário gerado para a usuária, com data de geração e lista de treinos
class PlanoTreinoDiario {
private:
    int id;
    std::string dataGeracao;
    std::vector<Treino> treinos;

public:
    PlanoTreinoDiario(
        int id,
        std::string dataGeracao
    );

    void adicionarTreino(const Treino& treino);

    std::vector<Treino> getTreinos() const;

    std::string getDataGeracao() const;
};