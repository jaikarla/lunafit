#include "RecomendadorTreino.h"
#include "database/Database.h"

RecomendadorTreino::RecomendadorTreino() : estrategiaAtual(nullptr) {}

void RecomendadorTreino::definirFaseDoCiclo(std::unique_ptr<EstrategiaTreino> novaEstrategia) {
    estrategiaAtual = std::move(novaEstrategia);
}

std::string RecomendadorTreino::obterRecomendacaoDiaria(const DadosUsuario& dados, Database& db) {
    if (!estrategiaAtual) {
        return "Erro: fase do ciclo nao foi definida no sistema.";
    }

    // delega a geração do plano de treino para a fase atual e passa a conexão SQLite
    return estrategiaAtual->gerarTreino(dados, db.getDb());
}