//import { lunaFitData } from "./data/appData.js";
//removido para poder enviar os dados reais
import { HomeView } from "./views/HomeView.js";
import { CycleView } from "./views/CycleView.js";
import { WorkoutView } from "./views/WorkoutView.js";
import { ProfileView } from "./views/ProfileView.js";
import { CheckinView } from "./views/CheckinView.js";
import { Treino } from "./models/Treino.js";

class LunaFitApp {
  constructor(root, state) {
    this.root = root;
    this.state = state;
    this.currentView = "home";
    this.dataFormatada = new Intl.DateTimeFormat("pt-BR", {
      weekday: "long",
      day: "numeric",
      month: "long",
    }).format(new Date());
  }

  navigate(view) {
    this.currentView = view;
    this.render();
    window.scrollTo({ top: 0, behavior: "smooth" });
  }

  getView() {
    const views = {
      home: new HomeView(this),
      cycle: new CycleView(this),
      workout: new WorkoutView(this),
      profile: new ProfileView(this),
      "checkin-1": new CheckinView(this, 1),
      "checkin-2": new CheckinView(this, 2),
      "checkin-3": new CheckinView(this, 3),
    };

    return views[this.currentView] || views.home;
  }


  //para carregar o usuario e não dar erro em usuario undefined
  //carrega os dados reais da usuária vindos do backend
  async carregarUsuario(usuarioId) {

  const response = await fetch(
    `http://127.0.0.1:18080/usuarios/${usuarioId}`
  );

  //converte resposta para JSON
  const usuario = await response.json();

  return usuario;
  }

  render() {
    const view = this.getView();
    this.root.innerHTML = view.html();
    view.afterRender();
  }

}

//enviando dados reais do backend para o app
document.addEventListener("DOMContentLoaded",

  async () => {
    const root = document.getElementById("app");

    if (!root) {
      return;
    }

    // pega ID salvo após cadastro
    const usuarioId = localStorage.getItem("usuario_id");

    if (!usuarioId) {
      alert("Usuária não encontrada.");

      window.location.href = "../cadastro_1/cadastro.html";

      return;
    }

    try {

      //cria instância temporária do app
      const appTemp = new LunaFitApp(root, {});

      //busca dados reais da usuária
      const usuarioBackend = 
        await appTemp.carregarUsuario(
          usuarioId
        );

      //converte dados backend para formato esperado pelo app
      const estadoApp = {

        usuario: {

          nome: usuarioBackend.nome,
          primeiroNome: usuarioBackend.nome.split(" ")[0],
          inicial: usuarioBackend.nome.charAt(0),
          idade: usuarioBackend.idade,
          peso: usuarioBackend.peso,
          altura: usuarioBackend.altura,
          objetivo: usuarioBackend.perfilFisico.objetivo,
          nivel: usuarioBackend
              .perfilFisico
              .nivelExperiencia,
          //considera que restrições podem também não existir
          restricoes: usuarioBackend
              .perfilFisico
              .restricoesFisicas?.length

              ? usuarioBackend
                  .perfilFisico
                  .restricoesFisicas
                  .join(", ")

              : "Nenhuma"
        },

        ciclo: {

          faseAtual:
            usuarioBackend
              .cicloMenstrual
              .faseAtual || "Folicular",

          diaAtual:
            usuarioBackend
              .cicloMenstrual
              .diaCiclo || 1,

          mediaDias:
            usuarioBackend
              .cicloMenstrual
              .duracaoMediaCiclo,

          ultimaMenstruacao:
            usuarioBackend
              .cicloMenstrual
              .dataUltimaMenstruacao,

          proximaMenstruacao:
            usuarioBackend
              .cicloMenstrual
              .proximaMenstruacao || "Em breve",

          fase: {
            emoji: "🌙",
            descricao:
              "Seu corpo está se preparando."
          },

          fases: []
        },

        treino: new Treino({

          titulo:
            "Treino Personalizado",

          foco:
            usuarioBackend
              .cicloMenstrual
              .faseAtual,

          duracao:
            "30 min",

          intensidade:
            usuarioBackend
              .perfilFisico
              .nivelExperiencia,

          frase:
            "Seu treino será gerado.",

          exercicios: []
        }),

        checkin: {

          humor: "",
          disposicao: "",
          intensidade: "",

          atualizar(campo, valor) {
            this[campo] = valor;
          }
        }
      };

      const app =
        new LunaFitApp(
          root,
          estadoApp
        );

      app.render();

    } catch (erro) {

      console.error(erro);

      alert(
        "Erro ao carregar dados da usuária."
      );
    }


});