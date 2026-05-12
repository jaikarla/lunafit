#include "EstrategiaTreino.h"
#include "models/Usuario.h"
#include "models/PerfilFisico.h"
#include "models/CicloMenstrual.h"
#include "models/EstadoUsuario.h"
#include <algorithm>

std::string DadosUsuario::obterPrimeiraRestricao(const PerfilFisico& perfil) {
    const auto& restricoes = perfil.getRestricoes();
    if (restricoes.empty()) {
        return "nenhuma";
    }
    return restricoes[0];
}

DadosUsuario DadosUsuario::criarDe(const Usuario& usuario, const CicloMenstrual& ciclo,
                                    const EstadoUsuario& estado, const std::string& intensidade,
                                    int diaAtual) {
    // Obtém o perfil físico do usuário
    const PerfilFisico& perfil = usuario.getPerfilFisico();
    
    // Calcula a fase atual do ciclo menstrual
    std::string faseAtual = ciclo.calcularFaseAtual();
    
    // Converte nível de disposição numérico para string (0-10 -> "baixa", "media", "alta")
    std::string disposicao;
    int nivelDisposicao = estado.getNivelDisposicao();
    if (nivelDisposicao <= 3) {
        disposicao = "baixa";
    } else if (nivelDisposicao <= 6) {
        disposicao = "media";
    } else {
        disposicao = "alta";
    }
    
    // Obtém a primeira restrição física (se houver múltiplas)
    std::string restricao = obterPrimeiraRestricao(perfil);
    
    // Cria um DadosUsuario com as informações convertidas dos Models
    return DadosUsuario(
        faseAtual,                          // fase do ciclo
        perfil.getObjetivo(),               // objetivo
        restricao,                          // restrição física (primeira, se houver)
        intensidade,                        // intensidade requerida (parâmetro)
        perfil.getNivelExperiencia(),       // nível de experiência
        disposicao,                         // disposição (convertida de numérica)
        estado.getHumor()                   // sentimento (humor do estado)
    );
}
