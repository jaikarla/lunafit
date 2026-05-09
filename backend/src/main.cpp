// ARQUIVO MAIN COM TESTE 

#include <iostream>
#include <memory>
#include <vector>
#include "database/Database.h"
#include "services/RecomendadorTreino.h"
#include "services/FaseMenstrual.h"
#include "services/FaseFolicular.h"
#include "services/FaseLutea.h"
#include "services/FaseOvulatoria.h"
#ifdef _WIN32
    #include <windows.h>
#endif

void executarTeste(std::string cenario, const DadosUsuario& dados, std::unique_ptr<EstrategiaTreino> fase, Database& db) {
    RecomendadorTreino motor;
    motor.definirFaseDoCiclo(std::move(fase));
    
    std::cout << "\n>>> TESTE: " << cenario << std::endl;
    std::cout << "Dados: objetivo=" << dados.getObjetivo()
              << ", intensidade=" << dados.getIntensidadeRequerida()
              << ", restricao=" << dados.getRestricaoFisica() << std::endl;
    
    std::cout << "Saida do Sistema:\n";
    std::cout << motor.obterRecomendacaoDiaria(dados, db) << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8); // força o terminal a usar UTF-8
    #endif

    Database db;
    if (!db.connect("lunafit.db")) {
        std::cerr << "Nao foi possivel conectar ao banco de dados." << std::endl;
        return 1;
    }

    if (!db.executeFile("schema.sql")) {
        std::cerr << "Erro ao criar as tabelas." << std::endl;
    }

    if (!db.executeFile("seed.sql")) {
        std::cerr << "Erro ao carregar os dados iniciais." << std::endl;
    }

    //teste 1
    DadosUsuario u1;
    u1.setFaseCiclo("menstrual");
    u1.setObjetivo("bem_estar");
    u1.setIntensidadeRequerida("leve");
    u1.setRestricaoFisica("joelho");
    u1.setNivelExperiencia("iniciante");
    u1.setDisposicao("baixa");
    u1.setSentimentoHoje("cansada");
    executarTeste("Fase Menstrual + Restricao Joelho", u1, std::make_unique<FaseMenstrual>(), db);

    // teste 2
    DadosUsuario u2;
    u2.setFaseCiclo("folicular");
    u2.setObjetivo("fortalecimento");
    u2.setIntensidadeRequerida("alta");
    u2.setRestricaoFisica("nenhuma");
    u2.setNivelExperiencia("avancado");
    u2.setDisposicao("alta");
    u2.setSentimentoHoje("animada");
    executarTeste("Fase Folicular + Alta Performance", u2, std::make_unique<FaseFolicular>(), db);

    // Exemplo de uso futuro com os Models:
    // DadosUsuario dadosDoUsuario = DadosUsuario::criarDe(usuario, cicloMenstrual, estadoUsuario, "moderado", 15);
    // recomendador.obterRecomendacaoDiaria(dadosDoUsuario, db);

    db.close();
    return 0;
}