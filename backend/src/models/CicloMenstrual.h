#pragma once
#include <string>

//classe que representa o ciclo menstrual de uma usuária, incluindo informações sobre a data da última menstruação e a duração média do ciclo
class CicloMenstrual {
private:
    std::string dataUltimaMenstruacao;
    int duracaoMediaCiclo;

public:
    //CicloMenstrual(); //para fins de teste e criação de objetos temporários sem parâmetros

    CicloMenstrual(std::string dataUltimaMenstruacao, int duracaoMediaCiclo);

    //para fazer o cálculo
    std::string calcularFaseAtual() const;
    int calcularDiaCiclo() const;
    std::string calcularProximaMenstruacao() const;

    std::string getDataUltimaMenstruacao() const;

    int getDuracaoMediaCiclo() const;
};