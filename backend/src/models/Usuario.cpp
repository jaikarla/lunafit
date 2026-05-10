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

int Usuario::getId() const {
    return id;
}

int Usuario::getIdade() const {
    return idade;
}

std::string Usuario::getEmail() const {
    return email;
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