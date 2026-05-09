#ifndef RECOMENDADOR_TREINO_H
#define RECOMENDADOR_TREINO_H

#include "EstrategiaTreino.h"
#include <memory>

class Database;

class RecomendadorTreino {
private:
    std::unique_ptr<EstrategiaTreino> estrategiaAtual;

public:
    RecomendadorTreino();

    void definirFaseDoCiclo(std::unique_ptr<EstrategiaTreino> novaEstrategia);
    std::string obterRecomendacaoDiaria(const DadosUsuario& dados, Database& db);
};

#endif