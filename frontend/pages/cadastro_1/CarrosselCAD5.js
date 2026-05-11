import { criarUsuario }
from "../../js/api.js";

document
    .querySelector(".btn-finish")
    .addEventListener("click", async (event) => {

        event.preventDefault();

        const dados =
            JSON.parse(
                localStorage.getItem(
                    "cadastroLunafit"
                )
            );

        const inputs =
            document.querySelectorAll(
                ".full-input"
            );

        const dataMenstruacao =
            inputs[0].value;

        const duracaoCiclo =
            parseInt(inputs[1].value);

        const dia =
            new Date(
                dataMenstruacao
            ).getDate();

        const usuario = {

            nome: dados.nome,
            email: "teste@email.com",
            senha: "123456",

            idade: dados.idade,

            peso: dados.peso,

            altura: dados.altura,

            perfilFisico: {

                objetivo:
                    dados.objetivo,

                nivelExperiencia:
                    dados.nivelExperiencia,

                restricoesFisicas:
                    dados.restricoesFisicas
            },

            cicloMenstrual: {

                diaUltimaMenstruacao:
                    dia,

                duracaoMediaCiclo:
                    duracaoCiclo
            }
        };

        try {

            const resposta =
                await criarUsuario(usuario);

            console.log(resposta);

            alert(
                "Cadastro realizado com sucesso!"
            );

            localStorage.removeItem(
                "cadastroLunafit"
            );

            window.location.href =
                "../../index.html";

        } catch (erro) {

            console.error(erro);

            alert(
                "Erro ao cadastrar usuária."
            );
        }
    });