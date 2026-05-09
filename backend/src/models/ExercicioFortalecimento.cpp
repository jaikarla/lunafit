#include "ExercicioFortalecimento.h"

//significa que o exercício de fortalecimento é adequado para todas as fases do ciclo menstrual, exceto para a fase menstrual
ExercicioFortalecimento::ExercicioFortalecimento(
    int id,
    std::string nome,
    int duracao,
    std::string intensidade,
    std::string grupoMuscular
)
    : Exercicio(id, nome, duracao, intensidade),
      grupoMuscular(grupoMuscular) {}

bool ExercicioFortalecimento::adequadoPara(
    const std::string& fase,
    const PerfilFisico& perfil
) const {

    if (fase == "menstrual" && intensidade == "alta") {
        return false;
    }

    return true;
}