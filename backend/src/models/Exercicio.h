#pragma once
#include <string>
#include "PerfilFisico.h"

//classe que representa um exercício físico, incluindo seu nome, duração e intensidade. A classe é abstrata e deve ser estendida por tipos específicos de exercícios
class Exercicio {
protected:
    int id;
    std::string nome;
    int duracao;
    std::string intensidade;

public:
    Exercicio(int id, std::string nome, int duracao, std::string intensidade);

    virtual ~Exercicio() = default;

    virtual bool adequadoPara(const std::string& fase, const PerfilFisico& perfil) const = 0;

    std::string getNome() const;
};