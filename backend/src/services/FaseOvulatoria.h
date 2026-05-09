#ifndef FASE_OVULATORIA_H
#define FASE_OVULATORIA_H

#include "EstrategiaTreino.h"

class FaseOvulatoria : public EstrategiaTreino {
public:
    std::string gerarTreino(const DadosUsuario& dados, sqlite3* db) override;
};

#endif