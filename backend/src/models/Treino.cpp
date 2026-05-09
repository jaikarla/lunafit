#include "Treino.h"

//classe que representa um treino, que é composto por uma lista de exercícios e tem uma duração total calculada com base na soma das durações dos exercícios
//construtor para inicializar o treino com duração total zero
Treino::Treino() : duracaoTotal(0) {}

//método para adicionar um exercício ao treino e atualizar a duração total
void Treino::adicionarExercicio(Exercicio* exercicio) {
    exercicios.push_back(exercicio);
    duracaoTotal += exercicio->getNome().size(); // placeholder
}

//método para calcular a duração total do treino com base na soma das durações dos exercícios
int Treino::calcularDuracaoTotal() {
    return duracaoTotal;
}