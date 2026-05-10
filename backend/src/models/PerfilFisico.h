#pragma once
#include <string>
#include <vector>

//classe que representa o perfil físico de um usuário, incluindo seus objetivos, nível de experiência e restrições físicas.
class PerfilFisico {
private:
    std::string objetivo;
    std::string nivelExperiencia;
    std::vector<std::string> restricoesFisicas;

public:
    //construtor padrão para teste e criação de objetos temporários
    //PerfilFisico();

    //construtor completo para criação de perfis físicos reais
    PerfilFisico(std::string objetivo, std::string nivelExperiencia);

    void adicionarRestricao(const std::string& restricao);
    void removerRestricao(const std::string& restricao);

    std::string getObjetivo() const;
    std::string getNivelExperiencia() const;
    std::vector<std::string> getRestricoes() const;
};