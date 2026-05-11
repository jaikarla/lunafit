document
    .querySelector(".btn-next")
    .addEventListener("click", (event) => {

        event.preventDefault();

        const dados = {

            nome:
                document.getElementById("nome").value,

            idade:
                parseInt(
                    document.getElementById("idade").value
                ),

            peso:
                parseFloat(
                    document.getElementById("peso").value
                ),

            altura:
                parseFloat(
                    document.getElementById("altura").value
                )
        };

        localStorage.setItem(
            "cadastroLunafit",
            JSON.stringify(dados)
        );

        window.location.href =
            "CarrosselCAD2.html";
    });