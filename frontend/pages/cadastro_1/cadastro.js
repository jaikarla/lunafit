import { criarUsuario } from "../../js/api.js";

const form =
    document.getElementById("cadastro-form");

form.addEventListener(
    "submit",
    async (event) => {

        event.preventDefault();

        const usuario = {

            nome:
                document.getElementById("nome").value,

            email:
                document.getElementById("email").value,

            idade:
                parseInt(
                    document.getElementById("idade").value
                ),

            perfilFisico: {

                objetivo:
                    document.getElementById("objetivo").value,

                nivelExperiencia:
                    document.getElementById("nivel").value,

                restricoesFisicas: []
            },

            cicloMenstrual: {

                diaUltimaMenstruacao:
                    parseInt(
                        document.getElementById("dia").value
                    ),

                duracaoMediaCiclo:
                    parseInt(
                        document.getElementById("duracao").value
                    )
                
            }
        };

        try {

            const resposta =
                await criarUsuario(usuario);

            alert("Usuária cadastrada!");

            console.log(resposta);

        } catch (erro) {

            console.error(erro);

            alert("Erro ao cadastrar.");
        }
    }
);