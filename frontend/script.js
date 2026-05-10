// Importando as classes dos modelos
import { Usuario } from './js/models/Usuario.js';

import { CicloMenstrual } from './js/models/CicloMenstrual.js';

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
        window.location.href = './pages/cadastro_1/index.html'; 
    }

    handleLogin() {
        console.log("Navegando para: pages/Login/");
        window.location.href = './pages/Login/index.html';
    }
}

// Inicializa o controlador da página
const home = new HomeViewController();