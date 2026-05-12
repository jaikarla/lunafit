#include "CicloMenstrual.h"

#include <ctime> //para trabalhar com datas
#include <sstream>
#include <iomanip> //incluído para o get_time

//CicloMenstrual::CicloMenstrual() {} //para fins de teste e criação de objetos temporários sem parâmetros

//classe que representa o ciclo menstrual de uma usuária, incluindo informações sobre a data da última menstruação e a duração média do ciclo
//construtor para inicializar o ciclo menstrual com a data da última menstruação e a duração média do ciclo
CicloMenstrual::CicloMenstrual(std::string dataUltimaMenstruacao, int duracaoMediaCiclo)
    : dataUltimaMenstruacao(dataUltimaMenstruacao),
      duracaoMediaCiclo(duracaoMediaCiclo) {}


//método para calcular o dia atual do ciclo menstrual com base na data da última menstruação e na duração média do ciclo
int CicloMenstrual::calcularDiaCiclo() const {

    std::tm ultimaMenstruacao = {};
    std::stringstream ss(dataUltimaMenstruacao);
    ss >> std::get_time(
        &ultimaMenstruacao,
        "%Y-%m-%d"
    );

    time_t tempoUltima =
        std::mktime(&ultimaMenstruacao);

    time_t agora =
        std::time(nullptr);

    double diferencaSegundos =
        std::difftime(agora, tempoUltima);

    int diasPassados =
        diferencaSegundos / (60 * 60 * 24);

    int diaCiclo =
        diasPassados % duracaoMediaCiclo;

    if (diaCiclo < 0) {
        diaCiclo += duracaoMediaCiclo;
    }

    return diaCiclo;
}

//método para calcular a fase atual do ciclo menstrual com base no dia do ciclo
std::string CicloMenstrual::calcularFaseAtual() const {

    int diaCiclo =
        calcularDiaCiclo();

    if (diaCiclo < 5) {

        return "Menstrual";

    } else if (diaCiclo < 14) {

        return "Folicular";

    } else if (diaCiclo < 17) {

        return "Ovulatoria";

    } else {

        return "Lutea";
    }
}

std::string CicloMenstrual::calcularProximaMenstruacao() const {

    std::tm ultimaMenstruacao = {};

    std::stringstream ss(dataUltimaMenstruacao);

    ss >> std::get_time(
        &ultimaMenstruacao,
        "%Y-%m-%d"
    );

    // converte para time_t
    time_t tempoUltima =
        std::mktime(&ultimaMenstruacao);

    // soma duração média do ciclo em segundos
    tempoUltima +=
        duracaoMediaCiclo * 24 * 60 * 60;

    // converte de volta
    std::tm* proxima =
        std::localtime(&tempoUltima);

    char buffer[11];

    std::strftime(
        buffer,
        sizeof(buffer),
        "%Y-%m-%d",
        proxima
    );

    return std::string(buffer);
}

//getters para acessar os atributos do ciclo menstrual
std::string CicloMenstrual::getDataUltimaMenstruacao() const {
    return dataUltimaMenstruacao;
}

int CicloMenstrual::getDuracaoMediaCiclo() const {
    return duracaoMediaCiclo;
}