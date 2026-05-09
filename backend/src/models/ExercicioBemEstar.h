#pragma once
#include "Exercicio.h"

//exercicio de bem-estar é adequado para todas as fases do ciclo menstrual
class ExercicioBemEstar : public Exercicio {
private:
    std::string categoria;

public:
    ExercicioBemEstar(
        int id,
        std::string nome,
        int duracao,
        std::string intensidade,
        std::string categoria
    );

    bool adequadoPara(
        const std::string& fase,
        const PerfilFisico& perfil
    ) const override;
};