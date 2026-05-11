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