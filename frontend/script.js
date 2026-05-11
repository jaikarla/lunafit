// Importando as classes dos modelos
//import { Usuario } from './js/models/Usuario.js';

//import { CicloMenstrual } from './js/models/CicloMenstrual.js';
//Os imports acima estão comentados pq estão causando erro de CORS, mas eles são necessários para a integração com o backend.

class HomeViewController {
    constructor() {
        this.btnCreate = document.getElementById('btn-create');
        this.btnLogin = document.getElementById('btn-login');
        this.init();
    }

    init() {
        this.bindEvents();
        console.log("Lunafit Home Inicializada em POO.");
    }

    bindEvents() {
        this.btnCreate.addEventListener('click', () => this.handleCreateAccount());
        this.btnLogin.addEventListener('click', () => this.handleLogin());
    }

    handleCreateAccount() {
        
        console.log("Navegando para: pages/cadastro_1/");
        window.location.href =
        './pages/cadastro_1/cadastro.html';
        //window.location.href = './pages/cadastro_1/index.html'; 
        //a linha acima é a original do arquivo, mas eu preciso da outra para realizar a integração com o backend.
    }

    handleLogin() {
        console.log("Navegando para: pages/Login/");
        window.location.href = './pages/Login/login.html';
    }
}

// Inicializa o controlador da página
const home = new HomeViewController();