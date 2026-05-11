import { BaseComponent } from "../components/BaseComponent.js";
import { CheckinHeader } from "../components/CheckinHeader.js";

export class CheckinView extends BaseComponent {
  constructor(app, step) {
    super(app);
    this.step = step;
  }

  html() {
    const content = {
      1: this.stepOne(),
      2: this.stepTwo(),
      3: this.stepThree(),
    }[this.step];

    return `
      <section class="screen screen--centered">
        <div class="checkin-wrap">
          ${new CheckinHeader(this.app, this.step).html()}
          ${content}
        </div>
      </section>
    `;
  }

  stepOne() {
    const choices = [
      ["Triste", "😔"],
      ["Ansiosa", "🥺"],
      ["Neutra", "😌"],
      ["Feliz", "😊"],
      ["Energizada", "🤩"],
    ];

    return `
      <article class="card checkin-card">
        <h1 class="title">Como você está se sentindo hoje?</h1>
        <p class="subtitle">Não existe resposta errada.</p>
        <div class="choices-row">
          ${choices.map(([label, icon]) => this.choiceButton("humor", label, icon)).join("")}
        </div>
      </article>
    `;
  }

  stepTwo() {
    const choices = [
      ["Baixa", "🪫"],
      ["Média", "🔋"],
      ["Alta", "⚡"],
    ];

    return `
      <article class="card checkin-card">
        <h1 class="title">Qual sua disposição?</h1>
        <p class="subtitle">Vamos calibrar a intensidade.</p>
        <div class="choices-row choices-row--three">
          ${choices.map(([label, icon]) => this.choiceButton("disposicao", label, icon)).join("")}
        </div>
      </article>
    `;
  }

  stepThree() {
    const choices = [
      ["Leve", "Alongar e respirar"],
      ["Moderado", "Suar com leveza"],
      ["Intenso", "Vai com tudo"],
    ];

    return `
      <article class="card checkin-card">
        <h1 class="title">Que intensidade você quer?</h1>
        <p class="subtitle">Vamos adaptar à sua fase também.</p>
        <div class="choices-column">
          ${choices
            .map(
              ([label, subtitle]) => `
                <button class="choice-card choice-card--wide ${this.app.state.checkin.intensidade === label ? "is-selected" : ""}" type="button" data-checkin-field="intensidade" data-value="${label}">
                  <strong>${label}</strong>
                  <span class="choice-subtitle">${subtitle}</span>
                </button>
              `
            )
            .join("")}
        </div>
        <button class="gradient-button" type="button" data-finish-checkin>Ver meu treino de hoje ✨</button>
      </article>
    `;
  }

  choiceButton(field, label, icon) {
    const selected = this.app.state.checkin[field] === label ? "is-selected" : "";

    return `
      <button class="choice-card ${selected}" type="button" data-checkin-field="${field}" data-value="${label}">
        <span class="choice-icon" aria-hidden="true">${icon}</span>
        <span>${label}</span>
      </button>
    `;
  }

  afterRender() {
    document.querySelectorAll("[data-checkin-field]").forEach((button) => {
      button.addEventListener("click", () => {
        this.app.state.checkin.atualizar(button.dataset.checkinField, button.dataset.value);
        if (this.step < 3) {
          this.app.navigate(`checkin-${this.step + 1}`);
          return;
        }
        this.app.render();
      });
    });

    const finishButton = document.querySelector("[data-finish-checkin]");
    if (finishButton) {
      finishButton.addEventListener("click", () => this.app.navigate("home"));
    }
  }
}
