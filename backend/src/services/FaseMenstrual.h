#ifndef FASE_MENSTRUAL_H
#define FASE_MENSTRUAL_H

#include "EstrategiaTreino.h"

class FaseMenstrual : public EstrategiaTreino {
public:
    string gerarTreino(
        string objetivo,
        string nivel,
        string restricoes,
        string estado
    ) override;
};

#endif // FASE_MENSTRUAL_H