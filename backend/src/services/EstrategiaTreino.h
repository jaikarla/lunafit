#ifndef ESTRATEGIA_TREINO_H
#define ESTRATEGIA_TREINO_H

#include <sstream>
#include <string>
#include <vector>
#include "database/sqlite/sqlite3.h"

// Classe para encapsular os dados de estado da usuária
// usando os termos idênticos ao seed.sql para evitar erros de consulta
class DadosUsuario {
private:
    std::string faseCiclo;          // menstrual, folicular, ovulatoria, lutea
    std::string objetivo;           // bem_estar, fortalecimento
    std::string restricaoFisica;    // joelho, lombar, ombro, nenhuma, etc.
    std::string intensidadeRequerida; // leve, moderado, alta
    std::string nivelExperiencia;   // iniciante, intermediario, avancado
    std::string disposicao;         // baixa, media, alta
    std::string sentimentoHoje;     // descrição livre

public:
    // Construtores
    DadosUsuario() = default;
    
    DadosUsuario(const std::string& fase, const std::string& obj, const std::string& restricao,
                 const std::string& intensidade, const std::string& nivel, const std::string& disp,
                 const std::string& sentimento)
        : faseCiclo(fase), objetivo(obj), restricaoFisica(restricao),
          intensidadeRequerida(intensidade), nivelExperiencia(nivel),
          disposicao(disp), sentimentoHoje(sentimento) {}

    // Getters
    const std::string& getFaseCiclo() const { return faseCiclo; }
    const std::string& getObjetivo() const { return objetivo; }
    const std::string& getRestricaoFisica() const { return restricaoFisica; }
    const std::string& getIntensidadeRequerida() const { return intensidadeRequerida; }
    const std::string& getNivelExperiencia() const { return nivelExperiencia; }
    const std::string& getDisposicao() const { return disposicao; }
    const std::string& getSentimentoHoje() const { return sentimentoHoje; }

    // Setters
    void setFaseCiclo(const std::string& fase) { faseCiclo = fase; }
    void setObjetivo(const std::string& obj) { objetivo = obj; }
    void setRestricaoFisica(const std::string& restricao) { restricaoFisica = restricao; }
    void setIntensidadeRequerida(const std::string& intensidade) { intensidadeRequerida = intensidade; }
    void setNivelExperiencia(const std::string& nivel) { nivelExperiencia = nivel; }
    void setDisposicao(const std::string& disp) { disposicao = disp; }
    void setSentimentoHoje(const std::string& sentimento) { sentimentoHoje = sentimento; }
};

// Classe para encapsular um exercício do plano de treino
class ExercicioPlano {
private:
    std::string nome;
    std::string duracao;
    std::string descricao;

public:
    // Construtores
    ExercicioPlano() = default;
    
    ExercicioPlano(const std::string& n, const std::string& d, const std::string& desc)
        : nome(n), duracao(d), descricao(desc) {}

    // Getters
    const std::string& getNome() const { return nome; }
    const std::string& getDuracao() const { return duracao; }
    const std::string& getDescricao() const { return descricao; }

    // Setters
    void setNome(const std::string& n) { nome = n; }
    void setDuracao(const std::string& d) { duracao = d; }
    void setDescricao(const std::string& desc) { descricao = desc; }
};

// Classe utilitária para validações e normalizações de estratégia
class ValidadoresEstrategia {
public:
    // Normaliza o objetivo para formato padrão
    static std::string normalizarObjetivo(const std::string& objetivo);
    
    // Valida e normaliza a intensidade
    static std::string validarIntensidade(const std::string& intensidade);
    
    // Normaliza a restrição física
    static std::string normalizarRestricao(const std::string& restricao);
    
    // Busca exercícios no banco usando filtros
    static std::vector<ExercicioPlano> buscarExercicios(sqlite3* db,
                                                        const std::string& fase,
                                                        const std::string& tipo,
                                                        const std::string& intensidade,
                                                        const std::string& restricaoFisica);
    
    // Formata o plano de treino em string
    static std::string formatarPlano(const std::vector<ExercicioPlano>& exercicios);

private:
    ValidadoresEstrategia() = default; // Classe puramente estática
};

inline std::string ValidadoresEstrategia::normalizarObjetivo(const std::string& objetivo) {
    if (objetivo == "fortalecimento" || objetivo == "Fortalecimento")
        return "fortalecimento";
    if (objetivo == "bem_estar" || objetivo == "bem-estar" || objetivo == "bemestar" || objetivo == "Bem_Estar" || objetivo == "Bem Estar")
        return "bem_estar";
    return "bem_estar";
}

inline std::string ValidadoresEstrategia::validarIntensidade(const std::string& intensidade) {
    if (intensidade == "leve")
        return "leve";
    if (intensidade == "moderado" || intensidade == "moderada")
        return "moderado";
    if (intensidade == "alta" || intensidade == "intenso" || intensidade == "intensa")
        return "alta";
    return "moderado";
}

inline std::string ValidadoresEstrategia::normalizarRestricao(const std::string& restricao) {
    if (restricao.empty())
        return "nenhuma";
    return restricao;
}

inline std::vector<ExercicioPlano> ValidadoresEstrategia::buscarExercicios(sqlite3* db,
                                                                           const std::string& fase,
                                                                           const std::string& tipo,
                                                                           const std::string& intensidade,
                                                                           const std::string& restricaoFisica) {
    std::vector<ExercicioPlano> exercicios;
    if (!db)
        return exercicios;

    // A query prioriza exercícios da fase/tipo/intensidade pedida e aplica
    // filtro de restrição: permite apenas exercícios sem restrição ou que não contenham a restrição da usuária.
    const char* sql =
        "SELECT DISTINCT nome, duracao, descricao " // o distinct é para evitar duplicatas caso haja exercícios com múltiplas restrições
        "FROM exercicios "
        "WHERE fase = ? "
        "  AND tipo = ? "
        "  AND intensidade = ? "
        "  AND (? = 'nenhuma' OR restricao_fisica = 'nenhuma' OR instr(restricao_fisica, ?)=0) "
        "ORDER BY id " // ordena por id para garantir uma ordem consistente (pode ser aleatória ou por popularidade, etc.)
        "LIMIT 6;";

    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return exercicios;
    }

    std::string restricao = normalizarRestricao(restricaoFisica);
    sqlite3_bind_text(stmt, 1, fase.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, tipo.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, intensidade.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, restricao.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, restricao.c_str(), -1, SQLITE_TRANSIENT);

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        ExercicioPlano item(
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))
        );
        exercicios.push_back(std::move(item));
    }

    sqlite3_finalize(stmt);
    return exercicios;
}

inline std::string ValidadoresEstrategia::formatarPlano(const std::vector<ExercicioPlano>& exercicios) {
    if (exercicios.empty()) {
        return "Nenhum exercício disponível com esses filtros. Tente reduzir a intensidade ou remover restrições.\n";
    }

    std::stringstream resultado;
    resultado << "exercicios recomendados:\n";
    for (const auto& item : exercicios) {
        resultado << "- " << item.getNome() << " (" << item.getDuracao() << "): " << item.getDescricao() << "\n";
    }
    return resultado.str();
}

// Classe abstrata que define a estratégia de treino
class EstrategiaTreino {
public:
    virtual ~EstrategiaTreino() = default;
    
    // Cada fase cria um plano de treino baseado nos dados da usuária e no banco SQLite
    virtual std::string gerarTreino(const DadosUsuario& dados, sqlite3* db) = 0;

protected:
    // Métodos auxiliares que delegam para a classe ValidadoresEstrategia
    static std::vector<ExercicioPlano> buscarExercicios(sqlite3* db,
                                                        const std::string& fase,
                                                        const std::string& tipo,
                                                        const std::string& intensidade,
                                                        const std::string& restricaoFisica) {
        return ValidadoresEstrategia::buscarExercicios(db, fase, tipo, intensidade, restricaoFisica);
    }

    static std::string formatarPlano(const std::vector<ExercicioPlano>& exercicios) {
        return ValidadoresEstrategia::formatarPlano(exercicios);
    }

    static std::string normalizarObjetivo(const std::string& objetivo) {
        return ValidadoresEstrategia::normalizarObjetivo(objetivo);
    }

    static std::string validarIntensidade(const std::string& intensidade) {
        return ValidadoresEstrategia::validarIntensidade(intensidade);
    }

    static std::string normalizarRestricao(const std::string& restricao) {
        return ValidadoresEstrategia::normalizarRestricao(restricao);
    }
};

#endif