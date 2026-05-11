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

        const restricoes = [];

        document
            .querySelectorAll(
                'input[name="restricao"]:checked'
            )
            .forEach((item) => {

                restricoes.push(item.value);
            });

        dados.restricoesFisicas =
            restricoes;

        localStorage.setItem(
            "cadastroLunafit",
            JSON.stringify(dados)
        );

        window.location.href =
            "CarrosselCAD5.html";
    });