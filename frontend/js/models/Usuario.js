//entidade usuário 

export class Usuario {
    constructor({ nome, email = "", idade = "", peso = "", altura = "", objetivo = "", nivel = "", restricoes = "" }) {
        this.nome = nome;
        this.email = email;
        this.idade = idade;
        this.peso = peso;
        this.altura = altura;
        this.objetivo = objetivo;
        this.nivel = nivel;
        this.restricoes = restricoes;
    }

    get primeiroNome() {
        return this.nome?.split(" ")[0] || "Luna";
    }

    get inicial() {
        return this.primeiroNome.charAt(0).toUpperCase();
    }

    autenticar() {
        console.log(`${this.nome} está tentando logar...`);
    }
}
