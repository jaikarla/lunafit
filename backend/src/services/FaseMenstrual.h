#ifndef FASE_MENSTRUAL_H
#define FASE_MENSTRUAL_H

#include "EstrategiaTreino.h"

class FaseMenstrual : public EstrategiaTreino {
public:
    std::string gerarTreino(const DadosUsuario& dados, sqlite3* db) override;
};

#endif