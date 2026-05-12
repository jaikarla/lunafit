// cadastro.js 

const form = document.getElementById("register-form"); // Ajustado para o ID do seu HTML

form.addEventListener("submit", (event) => {
    event.preventDefault();

    // Pega os valores dos campos
    const email = document.getElementById("email").value;
    const password = document.getElementById("password").value;
    const confirmPassword = document.getElementById("confirm-password").value;

    // 1. Validação de senha
    if (password !== confirmPassword) {
        alert("As senhas não coincidem!");
        return;
    }

    if (password.length < 6) {
        alert("A senha deve ter no mínimo 6 caracteres.");
        return;
    }

    // 2. Guardamos o email (localStorage)
    // O backend vai precisar desse email no JSON final lá na Tela 5.____________________
    localStorage.setItem('cad_email', email);
    
    //guardamos a senha (localStorage) para o backend pegar depois.____________________
    localStorage.setItem('cad_senha', password);

    console.log("Email guardado:", email);

    // 3. Redireciona para o início do carrossel de personalização
    window.location.href = "carrosselCadastro/CarrosselCAD1.html";
});