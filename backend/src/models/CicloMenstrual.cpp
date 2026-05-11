#include "CicloMenstrual.h"

//CicloMenstrual::CicloMenstrual() {} //para fins de teste e criação de objetos temporários sem parâmetros

//classe que representa o ciclo menstrual de uma usuária, incluindo informações sobre a data da última menstruação e a duração média do ciclo
//construtor para inicializar o ciclo menstrual com a data da última menstruação e a duração média do ciclo
CicloMenstrual::CicloMenstrual(int diaUltimaMenstruacao, int duracaoMediaCiclo)
    : diaUltimaMenstruacao(diaUltimaMenstruacao),
      duracaoMediaCiclo(duracaoMediaCiclo) {}

//método para calcular a fase atual do ciclo menstrual com base no dia atual
std::string CicloMenstrual::calcularFaseAtual(int diaAtual) const {
    int diaCiclo = (diaAtual - diaUltimaMenstruacao) % duracaoMediaCiclo;

    if (diaCiclo < 5) return "menstrual";
    else if (diaCiclo < 14) return "folicular";
    else if (diaCiclo < 17) return "ovulatoria";
    else return "lutea";
}

//getters para acessar os atributos do ciclo menstrual
int CicloMenstrual::getDiaUltimaMenstruacao() const {
    return diaUltimaMenstruacao;
}

int CicloMenstrual::getDuracaoMediaCiclo() const {
    return duracaoMediaCiclo;
}