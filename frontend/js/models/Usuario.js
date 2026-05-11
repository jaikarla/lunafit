//entidade usuário 

export class Usuario {
    constructor(nome, email) {
        this.nome = nome;
        this.email = email;
    }

    autenticar() {
        console.log(`${this.nome} está tentando logar...`);
    }
}
