// fluxo-cadastro.js
// Localizado em: carrosselCadastro/fluxo-cadastro.js

document.addEventListener('DOMContentLoaded', () => {

    // --- TELA 1: Nome, Idade, Peso, Altura ---
    const btnInicial = document.getElementById('btn-continuar-inicial');
    if (btnInicial) {
        btnInicial.addEventListener('click', () => {
            localStorage.setItem('cad_nome', document.getElementById('nome').value);
            localStorage.setItem('cad_idade', document.getElementById('idade').value);
            localStorage.setItem('cad_peso', document.getElementById('peso').value);
            localStorage.setItem('cad_altura', document.getElementById('altura').value);
        });
    }

    // --- TELA 2: Nível de Experiência ---
    const btnNivel = document.getElementById('btn-continuar-nivel');
    if (btnNivel) {
        btnNivel.addEventListener('click', () => {
            const nivel = document.querySelector('input[name="nivel"]:checked').value;
            localStorage.setItem('cad_nivelExperiencia', nivel);
        });
    }

    // --- TELA 3: Objetivo ---
    const btnObjetivo = document.getElementById('btn-continuar-objetivo');
    if (btnObjetivo) {
        btnObjetivo.addEventListener('click', () => {
            const objetivo = document.querySelector('input[name="objetivo"]:checked').value;
            localStorage.setItem('cad_objetivo', objetivo);
            
            // AGORA ELE SABE PARA ONDE IR:
            window.location.href = "CarrosselCAD4.html"; 
        });
    }

    // --- TELA 4: Restrições Físicas ---
    const btnRestricoes = document.getElementById('btn-continuar-restricoes');
    if (btnRestricoes) {
        btnRestricoes.addEventListener('click', (event) => {
            // Previne o comportamento padrão caso seja um link <a>
            // Isso garante que o JS tenha tempo de salvar no localStorage antes de mudar de página
            event.preventDefault();

            // 1. Coleta as restrições selecionadas
            const selecionados = Array.from(document.querySelectorAll('input[name="restricao"]:checked'))
                                    .map(cb => cb.value);
            
            // 2. Salva na "sacola" (localStorage) convertendo para texto (JSON)
            localStorage.setItem('cad_restricoes', JSON.stringify(selecionados));

            console.log("Restrições salvas:", selecionados);

            // 3. Redireciona manualmente para a Tela 5 (Ciclo)
            window.location.href = "CarrosselCAD5.html";
        });
    }

    // --- TELA 5: Ciclo e ENVIO FINAL ---
    const formFinal = document.getElementById('form-final');
    if (formFinal) {
        formFinal.addEventListener('submit', async (e) => {
            e.preventDefault();

            // 1. Pega o valor do calendário ("AAAA-MM-DD")
            const dataCalendario = document.getElementById('input-dia-menstruacao').value;
            

            /*
            Bloco comentado para o teste, pois esses dados não podem ser recebidos assim. Precisa calcular com dataUltimaMenstruação e não diaUltimaMenstruacao.

            // Quebramos o texto "2026-05-11" nos tracinhos e pega a última parte (o dia)
            const partesData = dataCalendario.split('-'); 
            const diaMenstruacao = parseInt(partesData[2]); // Pega apenas o "11" */

            const duracaoCiclo = parseInt(document.getElementById('input-duracao-ciclo').value);

            // 2. RECUPERAMOS O EMAIL (Da pasta cadastro.js!)
            const emailSalvo = localStorage.getItem('cad_email');

            if (!emailSalvo) {
                alert("Erro: E-mail não encontrado. Por favor, reinicie o cadastro.");
                window.location.href = "../cadastro.html";
                return;
            }

            // 3. Monta o objeto com todas as informações para enviar ao Crow
            const usuarioCompleto = {
                "nome": localStorage.getItem('cad_nome') || "Usuária",
                "email": emailSalvo,
                "senha": localStorage.getItem('cad_senha'),
                "idade": parseInt(localStorage.getItem('cad_idade')) || 0,
                "peso": parseFloat(localStorage.getItem('cad_peso')) || 0,
                "altura": parseFloat(localStorage.getItem('cad_altura')) || 0,
                "perfilFisico": {
                    "objetivo": localStorage.getItem('cad_objetivo'),
                    "nivelExperiencia": localStorage.getItem('cad_nivelExperiencia'),
                    "restricoesFisicas": JSON.parse(localStorage.getItem('cad_restricoes') || "[]")
                },
                "cicloMenstrual": {
                    "dataUltimaMenstruacao": dataCalendario, // Envia a data completa
                    "duracaoMediaCiclo": duracaoCiclo
                }
            };

            console.log("Enviando JSON final para o Crow:", usuarioCompleto);

            // 4. Disparo para o servidor C++
            try {
                const response = await fetch('http://127.0.0.1:18080/usuarios', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/json' },
                    body: JSON.stringify(usuarioCompleto)
                });

                if (response.ok) {

                    const usuarioCriado = await response.json();

                    //salva o ID do usuário criado para futuras sessões
                    localStorage.setItem('usuario_id', usuarioCriado.id);

                    alert("Sucesso! Sua jornada Lunafit começou.");

                    //limapa apenas os dados temporários
                    localStorage.removeItem('cad_nome');
                    localStorage.removeItem('cad_idade');
                    localStorage.removeItem('cad_peso');
                    localStorage.removeItem('cad_altura');
                    localStorage.removeItem('cad_objetivo');
                    localStorage.removeItem('cad_nivelExperiencia');
                    localStorage.removeItem('cad_restricoes');
                    localStorage.removeItem('cad_email');
                    //localStorage.removeItem('cad_diaMenstruacao');
                    //localStorage.removeItem('cad_duracaoCiclo');

                    //vai para o app
                    window.location.href = "../../App/app.html"; 
                } else {
                    const erroTxt = await response.text();
                    alert("Erro no servidor: " + erroTxt);
                }
            } catch (err) {
                console.error("Falha na conexão:", err);
                alert("Não foi possível conectar ao servidor C++. Certifique-se de que o backend está rodando na porta 18080.");
            }
        });
    }
});