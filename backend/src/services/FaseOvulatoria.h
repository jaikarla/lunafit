#ifndef FASE_OVULATORIA_H
#define FASE_OVULATORIA_H

#include "EstrategiaTreino.h"

class FaseOvulatoria : public EstrategiaTreino {
public:
    string gerarTreino(
        string objetivo,
        string nivel,
        string restricoes,
        string estado
    ) override;
};

#endif // FASE_OVULATORIA_H