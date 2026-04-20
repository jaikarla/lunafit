#ifndef RECOMENDADOR_TREINO_H
#define RECOMENDADOR_TREINO_H

#include "EstrategiaTreino.h"
#include <string>

class RecomendadorTreino {
private:
    EstrategiaTreino* estrategia; // Variável para guardar a fase

public:
   void definirEstrategia(EstrategiaTreino* novaEstrategia); 
    std::string gerarPlanoDiario(std::string objetivo, std::string nivel, std::string restricoes, std::string estado);
};

#endif