class Usuario {
  constructor({ nome, idade, peso, altura, objetivo, nivel, restricoes }) {
    this.nome = nome;
    this.idade = idade;
    this.peso = peso;
    this.altura = altura;
    this.objetivo = objetivo;
    this.nivel = nivel;
    this.restricoes = restricoes;
  }

  get inicial() {
    return this.nome.charAt(0).toUpperCase();
  }

  get primeiroNome() {
    return this.nome.split(" ")[0];
  }
}
