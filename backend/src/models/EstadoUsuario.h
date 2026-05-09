#pragma once
#include <string>

//classe que representa o estado atual de um usuário, incluindo seu nível de disposição e humor
class EstadoUsuario {
private:
    int nivelDisposicao;
    std::string humor;

public:
    EstadoUsuario(int nivelDisposicao, std::string humor);

    int getNivelDisposicao() const;
    std::string getHumor() const;
};