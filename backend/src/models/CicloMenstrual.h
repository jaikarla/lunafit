#pragma once
#include <string>

//classe que representa o ciclo menstrual de uma usuária, incluindo informações sobre a data da última menstruação e a duração média do ciclo
class CicloMenstrual {
private:
    int diaUltimaMenstruacao;
    int duracaoMediaCiclo;

public:
    //CicloMenstrual(); //para fins de teste e criação de objetos temporários sem parâmetros

    CicloMenstrual(int diaUltimaMenstruacao, int duracaoMediaCiclo);

    std::string calcularFaseAtual(int diaAtual) const;

    int getDiaUltimaMenstruacao() const;

    int getDuracaoMediaCiclo() const;
};