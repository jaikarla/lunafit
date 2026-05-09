#ifndef FASE_FOLICULAR_H
#define FASE_FOLICULAR_H

#include "EstrategiaTreino.h"

class FaseFolicular : public EstrategiaTreino {
public:
    std::string gerarTreino(const DadosUsuario& dados, sqlite3* db) override;
};

#endif