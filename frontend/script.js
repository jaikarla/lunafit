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
        this.btnLogin.addEventListener('click', (event) => this.handleLogin(event));
    }

    handleCreateAccount() {
        
        console.log("Navegando para: pages/cadastro_1/");
        window.location.href = './pages/cadastro_1/cadastro.html';
    }

    handleLogin(event) {
        event.preventDefault();
        console.log("Navegando para: pages/Login/");
        window.location.href = './pages/Login/login.html';
    }
}

// Inicializa o controlador da página
const home = new HomeViewController();
