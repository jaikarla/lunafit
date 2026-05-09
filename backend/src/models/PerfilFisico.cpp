#include "PerfilFisico.h"

//classe que representa o perfil físico de um usuário, incluindo seus objetivos, nível de experiência e restrições físicas
//construtor para inicializar o perfil físico com objetivo e nível de experiência
PerfilFisico::PerfilFisico(std::string objetivo, std::string nivelExperiencia)
    : objetivo(objetivo), nivelExperiencia(nivelExperiencia) {}

//método para adicionar uma restrição física ao perfil
void PerfilFisico::adicionarRestricao(const std::string& restricao) {
    restricoesFisicas.push_back(restricao);
}

//método para remover uma restrição física do perfil
void PerfilFisico::removerRestricao(const std::string& restricao) {
    for (auto it = restricoesFisicas.begin(); it != restricoesFisicas.end(); ++it) {
        if (*it == restricao) {
            restricoesFisicas.erase(it);
            break;
        }
    }
}

//método para obter o objetivo do perfil físico
std::string PerfilFisico::getObjetivo() const {
    return objetivo;
}

//método para obter o nível de experiência do perfil físico
std::string PerfilFisico::getNivelExperiencia() const {
    return nivelExperiencia;
}

//método para obter as restrições físicas do perfil físico
std::vector<std::string> PerfilFisico::getRestricoes() const {
    return restricoesFisicas;
}