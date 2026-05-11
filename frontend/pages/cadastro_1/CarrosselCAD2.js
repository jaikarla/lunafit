document
    .querySelector(".btn-next")
    .addEventListener("click", (event) => {

        event.preventDefault();

        const dados =
            JSON.parse(
                localStorage.getItem(
                    "cadastroLunafit"
                )
            );

        dados.nivelExperiencia =
            document.querySelector(
                'input[name="nivel"]:checked'
            ).value;

        localStorage.setItem(
            "cadastroLunafit",
            JSON.stringify(dados)
        );

        window.location.href =
            "CarrosselCAD3.html";
    });