// define o comportamento que todas as fases seguem
#ifndef ESTRATEGIA_TREINO_H
#define ESTRATEGIA_TREINO_H

#include <string>
using std::string;

class EstrategiaTreino {
public:
    virtual ~EstrategiaTreino() {} // destrutor virtual para garantir a limpeza correta

    virtual string gerarTreino(
        string objetivo,
        string nivel,
        string restrincoes, 
        string estado
    ) = 0; // método virtual puro, a ser implementado pelas subclasses
};

#endif