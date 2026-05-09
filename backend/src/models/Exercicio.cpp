#include "Exercicio.h"

//classe que representa um exercício físico, incluindo seu nome, duração e intensidade. A classe é abstrata e deve ser estendida por tipos específicos de exercícios
//construtor para inicializar o exercício com id, nome, duração e intensidade
Exercicio::Exercicio(int id, std::string nome, int duracao, std::string intensidade)
    : id(id), nome(nome), duracao(duracao), intensidade(intensidade) {}

//método para obter o nome do exercício
std::string Exercicio::getNome() const {
    return nome;
}