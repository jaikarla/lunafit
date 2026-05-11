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

        dados.objetivo =
            document.querySelector(
                'input[name="objetivo"]:checked'
            ).value;

        localStorage.setItem(
            "cadastroLunafit",
            JSON.stringify(dados)
        );

        window.location.href =
            "CarrosselCAD4.html";
    });