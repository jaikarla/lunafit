#pragma once
#include "Exercicio.h"

// Exercicio de fortalecimento é adequado para todas as fases do ciclo menstrual, exceto para a fase menstrual
class ExercicioFortalecimento : public Exercicio {
private:
    std::string grupoMuscular;

public:
    ExercicioFortalecimento(
        int id,
        std::string nome,
        int duracao,
        std::string intensidade,
        std::string grupoMuscular
    );

    bool adequadoPara(
        const std::string& fase,
        const PerfilFisico& perfil
    ) const override;
};