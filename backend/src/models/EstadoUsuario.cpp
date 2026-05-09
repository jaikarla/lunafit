#include "EstadoUsuario.h"

//classe que representa o estado atual de um usuário, incluindo seu nível de disposição e humor
//construtor para inicializar o estado do usuário com nível de disposição e humor
EstadoUsuario::EstadoUsuario(int nivelDisposicao, std::string humor)
    : nivelDisposicao(nivelDisposicao), humor(humor) {}

//método para obter o nível de disposição do usuário
int EstadoUsuario::getNivelDisposicao() const {
    return nivelDisposicao;
}

//método para obter o humor do usuário
std::string EstadoUsuario::getHumor() const {
    return humor;
}