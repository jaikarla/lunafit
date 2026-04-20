#ifndef FASE_FOLICULAR_H
#define FASE_FOLICULAR_H

#include "EstrategiaTreino.h"

class FaseFolicular : public EstrategiaTreino {
public:
    string gerarTreino(
        string objetivo,
        string nivel,
        string restricoes,
        string estado
    ) override;
};

#endif // FASE_FOLICULAR_H