// Gerencia dinamicamente as estratégias de treino
#include "RecomendadorTreino.h"

void RecomendadorTreino::definirEstrategia(EstrategiaTreino* novaEstrategia) {
    this->estrategia = novaEstrategia;
}

string RecomendadorTreino::gerarPlanoDiario(
    string objetivo,
    string nivel,
    string restricoes,
    string estado
) {
    // Verifica se uma estratégia foi definida antes de gerar o plano
    if (estrategia) {
        return estrategia->gerarTreino(objetivo, nivel, restricoes, estado);
    }
    // Retorna erro se nenhuma fase foi selecionada
    return "Erro: Fase não selecionada.";
}