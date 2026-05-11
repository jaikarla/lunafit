#pragma once

#include <string>
#include "PerfilFisico.h"
#include "CicloMenstrual.h"
#include "HistoricoTreinoDiario.h"

//usuária do sistema, com informações pessoais, perfil físico, ciclo menstrual e histórico de treinos
class Usuario {
private:
    int id;
    int idade;
    std::string email;
    std::string nome;

    PerfilFisico perfilFisico;
    CicloMenstrual cicloMenstrual;
    HistoricoTreinoDiario historico;

public:
    Usuario(
        int id,
        int idade,
        std::string email,
        std::string nome,
        PerfilFisico perfilFisico,
        CicloMenstrual cicloMenstrual
    );

    void atualizarPerfil(
        const PerfilFisico& novoPerfil
    );

    int getId() const;

    int getIdade() const;

    std::string getEmail() const;

    std::string getNome() const;

    PerfilFisico getPerfilFisico() const;

    CicloMenstrual getCicloMenstrual() const;

    HistoricoTreinoDiario& getHistorico();

};