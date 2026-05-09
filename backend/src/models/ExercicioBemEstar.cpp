#include "ExercicioBemEstar.h"

//exercicio de bem-estar é adequado para todas as fases do ciclo menstrual
ExercicioBemEstar::ExercicioBemEstar(
    int id,
    std::string nome,
    int duracao,
    std::string intensidade,
    std::string categoria
)
    : Exercicio(id, nome, duracao, intensidade),
      categoria(categoria) {}

bool ExercicioBemEstar::adequadoPara(
    const std::string& fase,
    const PerfilFisico& perfil
) const {

    if (fase == "menstrual") {
        return true;
    }

    return true;
}