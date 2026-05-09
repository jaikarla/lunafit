#pragma once
#include <vector>
#include "Exercicio.h"

//classe que representa um treino, que é composto por uma lista de exercícios e tem uma duração total calculada com base na soma das durações dos exercícios
class Treino {
private:
    std::vector<Exercicio*> exercicios;
    int duracaoTotal;

public:
    Treino();

    void adicionarExercicio(Exercicio* exercicio);
    int calcularDuracaoTotal();
};