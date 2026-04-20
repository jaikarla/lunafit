#ifndef FASE_LUTEA_H
#define FASE_LUTEA_H

#include "EstrategiaTreino.h"

class FaseLutea : public EstrategiaTreino {
public:
    string gerarTreino(
        string objetivo,
        string nivel,
        string restricoes,
        string estado
    ) override;
};

#endif // FASE_LUTEA_H