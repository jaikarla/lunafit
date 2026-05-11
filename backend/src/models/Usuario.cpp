#include "Usuario.h"

Usuario::Usuario(
    int id,
    int idade,
    std::string nome,
    std::string email,
    std::string senha,
    double peso,
    double altura,
    PerfilFisico perfilFisico,
    CicloMenstrual cicloMenstrual
)
    : id(id),
      idade(idade),
      nome(nome),
      email(email),
     senha(senha),
      peso(peso),
      altura(altura),
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

std::string Usuario::getNome() const {
    return nome;
}

std::string Usuario::getEmail() const {
    return email;
}

std::string Usuario::getSenha() const {
    return senha;
}

double Usuario::getPeso() const {
    return peso;
}

double Usuario::getAltura() const {
    return altura;
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