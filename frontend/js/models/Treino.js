export class Exercicio {
  constructor({ nome, descricao, duracao }) {
    this.nome = nome;
    this.descricao = descricao;
    this.duracao = duracao;
    this.concluido = false;
  }

  alternarConclusao() {
    this.concluido = !this.concluido;
  }
}

export class Treino {
  constructor({
  titulo,
  foco,
  duracao,
  intensidade,
  frase,
  exercicios = []
}) {

  this.titulo = titulo;
  this.foco = foco;
  this.duracao = duracao;
  this.intensidade = intensidade;
  this.frase = frase;

  this.exercicios =
    (exercicios || [])
      .map(
        (exercicio) =>
          new Exercicio(exercicio)
  );
}

  get totalExercicios() {
    return this.exercicios.length;
  }

  get concluidos() {
    return this.exercicios.filter((exercicio) => exercicio.concluido).length;
  }
}
