#ifndef FASE_LUTEA_H
#define FASE_LUTEA_H

#include "EstrategiaTreino.h"

class FaseLutea : public EstrategiaTreino {
public:
    std::string gerarTreino(const DadosUsuario& dados, sqlite3* db) override;
};

#endif