// LÓGICA DO MAIN.CPP BASE (TESTE SIMPLES) 
// pode ser alterado depois, isso é só pra teste

#include <iostream>
#include <string>
#include <vector>

// aqui vai os arquivos de logica
#include "services/RecomendadorTreino.h"
#include "services/FaseMenstrual.h"
#include "services/FaseFolicular.h"
#include "services/FaseLutea.h"
#include "services/FaseOvulatoria.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    // inicialização do Sistema
    RecomendadorTreino motor;
    
    FaseMenstrual faseMenstrual;
    FaseFolicular faseFolicular;
    FaseLutea faseLutea;
    FaseOvulatoria faseOvulatoria;

    cout << "==============================" << endl;
    cout << "            LUNAFIT           " << endl;
    cout << "==============================" << endl;

    // pegar a entrada do usuario
    string objetivo, nivel, restricoes, estado;
    int escolhaFase;

    // Menu simples pra teste
    cout << "Selecione a fase atual (1-Menstrual, 2-Folicular): "; // tudo pode ser alterado depois, isso é só pra teste
    cin >> escolhaFase;
    cin.ignore(); // Limpa o buffer do teclado

    if (escolhaFase == 1) {
        motor.definirEstrategia(&faseMenstrual);
    } else {
        motor.definirEstrategia(&faseFolicular);
    }

    cout << "Como voce se sente hoje? (ex: Cansada, Disposta): ";
    getline(cin, estado);

    cout << "Qual seu objetivo? (ex: Fortalecimento, Cardio): ";
    getline(cin, objetivo);

    // Gerar a recomendação de treino
    string recomendacao = motor.gerarPlanoDiario(objetivo, "Iniciante", "Nenhuma", estado);

    cout << "\n--- RESULTADO ---" << endl;
    cout << recomendacao << endl;
    cout << "-----------------" << endl;

    return 0;
}