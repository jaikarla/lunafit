class CheckinDiario {
  constructor() {
    this.humor = null;
    this.disposicao = null;
    this.intensidade = null;
  }

  atualizar(campo, valor) {
    this[campo] = valor;
  }
}
