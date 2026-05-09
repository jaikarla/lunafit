#include "TreinoRealizado.h"

//histórico de treinos realizados pela usuária, com data e nível de disposição
TreinoRealizado::TreinoRealizado(
    std::string data,
    int nivelDisposicao
)
    : data(data),
      nivelDisposicao(nivelDisposicao) {}

std::string TreinoRealizado::getData() const {
    return data;
}

int TreinoRealizado::getNivelDisposicao() const {
    return nivelDisposicao;
}