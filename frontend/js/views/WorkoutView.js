import { BaseComponent } from "../components/BaseComponent.js";
import { BottomNav } from "../components/BottomNav.js";

export class WorkoutView extends BaseComponent {
  html() {
    const treino = this.app.state.treino;

    return `
      <section class="screen">
        <header class="screen-title">
          <p class="eyebrow">Treino do dia</p>
          <h1 class="title">${treino.titulo}</h1>
        </header>

        <div class="stack">
          <article class="card workout-hero">
            <p class="eyebrow">Fase folicular</p>
            <h2 class="workout-title">${treino.foco}</h2>
            <div class="workout-meta">
              <span>◷ ${treino.duracao}</span>
              <span>♧ ${treino.intensidade}</span>
            </div>
            <p class="subtitle">"${treino.frase}"</p>
          </article>

          <article class="card progress-card">
            <div class="progress-row">
              <span>Progresso</span>
              <strong>${treino.concluidos}/${treino.totalExercicios}</strong>
            </div>
          </article>

          ${treino.exercicios
            .map(
              (exercicio, index) => `
                <button class="exercise-item ${exercicio.concluido ? "is-selected" : ""}" type="button" data-exercise="${index}">
                  <span class="exercise-number">${index + 1}</span>
                  <span>
                    <strong class="exercise-name">${exercicio.nome}</strong>
                    <span class="exercise-desc">${exercicio.descricao}</span>
                  </span>
                  <span class="exercise-time">${exercicio.duracao}</span>
                </button>
              `
            )
            .join("")}

          <button class="outline-button" type="button" data-reset-workout>⟳ Gerar novo treino</button>
        </div>

        ${new BottomNav(this.app, "workout").html()}
      </section>
    `;
  }

  afterRender() {
    new BottomNav(this.app, "workout").afterRender();
    document.querySelectorAll("[data-exercise]").forEach((button) => {
      button.addEventListener("click", () => {
        this.app.state.treino.exercicios[Number(button.dataset.exercise)].alternarConclusao();
        this.app.render();
      });
    });
    document.querySelector("[data-reset-workout]").addEventListener("click", () => {
      this.app.state.treino.exercicios.forEach((exercicio) => {
        exercicio.concluido = false;
      });
      this.app.render();
    });
  }
}
