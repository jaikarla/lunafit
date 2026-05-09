#pragma once
#include <string>

//histórico de treinos realizados pela usuária, com data e nível de disposição
class TreinoRealizado {
private:
    std::string data;
    int nivelDisposicao;

public:
    TreinoRealizado(
        std::string data,
        int nivelDisposicao
    );

    std::string getData() const;
    int getNivelDisposicao() const;
};