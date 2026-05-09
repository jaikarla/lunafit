#include "Usuario.h"

Usuario::Usuario(
    int id,
    int idade,
    std::string email,
    std::string nome,
    PerfilFisico perfilFisico,
    CicloMenstrual cicloMenstrual
)
    : id(id),
      idade(idade),
      email(email),
      nome(nome),
      perfilFisico(perfilFisico),
      cicloMenstrual(cicloMenstrual) {}

void Usuario::atualizarPerfil(
    const PerfilFisico& novoPerfil
) {
    perfilFisico = novoPerfil;
}

std::string Usuario::getNome() const {
    return nome;
}

PerfilFisico Usuario::getPerfilFisico() const {
    return perfilFisico;
}

CicloMenstrual Usuario::getCicloMenstrual() const {
    return cicloMenstrual;
}

HistoricoTreinoDiario&
Usuario::getHistorico() {
    return historico;
}