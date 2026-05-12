const API_URL =
    "http://localhost:18080";

export async function criarUsuario(usuario) {

    const resposta = await fetch(

        `${API_URL}/usuarios`,

        {
            method: "POST",

            headers: {
                "Content-Type":
                    "application/json"
            },

            body: JSON.stringify(usuario)
        }
    );

    if (!resposta.ok) {

        throw new Error(
            "Erro ao criar usuário"
        );
    }

    return await resposta.json();
}

//função para buscar o treino do usuário
export async function gerarTreino(dados) {

    const resposta = await fetch(

        `${API_URL}/treinos/recomendar`,

        {
            method: "POST",

            headers: {
                "Content-Type":
                    "application/json"
            },

            body: JSON.stringify(dados)
        }
    );

    if (!resposta.ok) {

        throw new Error(
            "Erro ao gerar treino"
        );
    }

    return await resposta.json();
}