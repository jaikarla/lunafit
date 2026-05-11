export class FaseCiclo {
  constructor({ nome, dias, cor, emoji, descricao }) {
    this.nome = nome;
    this.dias = dias;
    this.cor = cor;
    this.emoji = emoji;
    this.descricao = descricao;
  }
}

export class CicloMenstrual {
  constructor({ faseAtual, diaAtual, proximaMenstruacao, ultimaMenstruacao, mediaDias, fases }) {
    this.faseAtual = faseAtual;
    this.diaAtual = diaAtual;
    this.proximaMenstruacao = proximaMenstruacao;
    this.ultimaMenstruacao = ultimaMenstruacao;
    this.mediaDias = mediaDias;
    this.fases = fases.map((fase) => new FaseCiclo(fase));
  }

  get fase() {
    return this.fases.find((fase) => fase.nome === this.faseAtual);
  }

  corrigirFase(nome) {
    if (this.fases.some((fase) => fase.nome === nome)) {
      this.faseAtual = nome;
    }
  }
}
