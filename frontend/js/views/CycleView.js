import { BaseComponent } from "../components/BaseComponent.js";
import { BottomNav } from "../components/BottomNav.js";

export class CycleView extends BaseComponent {
  html() {
    const { ciclo } = this.app.state;
    const moonClasses = {
      Menstrual: "moon-visual--menstrual",
      Folicular: "moon-visual--folicular",
      Ovulatória: "moon-visual--ovulatoria",
      Lútea: "moon-visual--lutea",
    };

    return `
      <section class="screen screen--cycle">
        <header class="screen-title cycle-title">
          <p class="eyebrow">Seu ciclo</p>
          <h1 class="title">Ritmo lunar</h1>
        </header>

        <div class="stack">
          <article class="card cycle-orbit">
            <div class="cycle-ring">
              <div class="cycle-ring__content">
                <span class="moon-visual moon-visual--large ${moonClasses[ciclo.faseAtual]}" aria-hidden="true"></span>
                <h2 class="phase-name">${ciclo.faseAtual}</h2>
                <p class="subtitle">Dia ${ciclo.diaAtual} de 28</p>
              </div>
              <span class="cycle-ring__point" aria-hidden="true"></span>
            </div>
            <p class="subtitle cycle-orbit__text">${ciclo.fase.descricao} Ótima fase para experimentar e construir força.</p>
          </article>

          <article class="card next-card">
            <span class="next-card__icon" aria-hidden="true">
              <svg viewBox="0 0 24 24" fill="none">
                <path d="M7 3.8v3.1M17 3.8v3.1M4.8 9h14.4M6.4 5.4h11.2a2.2 2.2 0 0 1 2.2 2.2v10.2a2.2 2.2 0 0 1-2.2 2.2H6.4a2.2 2.2 0 0 1-2.2-2.2V7.6a2.2 2.2 0 0 1 2.2-2.2Z" stroke="currentColor" stroke-width="1.8" stroke-linecap="round"/>
              </svg>
            </span>
            <span>
              <p class="eyebrow">Próxima menstruação</p>
              <strong>${ciclo.proximaMenstruacao} • em 21 dias</strong>
            </span>
          </article>

          <article class="card manual-card">
            <p class="manual-card__title">
              <svg viewBox="0 0 24 24" fill="none" aria-hidden="true">
                <path d="m4.8 16.7-.8 3.3 3.3-.8L18.8 7.7a2.2 2.2 0 0 0-3.1-3.1L4.8 15.5v1.2Z" stroke="currentColor" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"/>
                <path d="m14.6 5.7 3.1 3.1" stroke="currentColor" stroke-width="1.8" stroke-linecap="round"/>
              </svg>
              <strong>Corrigir fase manualmente</strong>
            </p>
            <p class="subtitle">Sente que está em outra fase? Ajuste para refinarmos suas recomendações.</p>
            <div class="option-grid">
              ${ciclo.fases
                .map(
                  (fase) => `
                    <button class="phase-option" type="button" data-phase="${fase.nome}">
                      <span class="moon-visual ${moonClasses[fase.nome]}" aria-hidden="true"></span>
                      <strong>${fase.nome}</strong>
                    </button>
                  `
                )
                .join("")}
            </div>
          </article>

          <article class="card phase-list">
            <p class="eyebrow">As 4 fases</p>
            ${ciclo.fases
              .map(
                (fase) => `
                  <div class="phase-list__row">
                    <span class="phase-list__label">
                      <span class="moon-visual moon-visual--small ${moonClasses[fase.nome]}" aria-hidden="true"></span>
                      ${fase.nome}
                    </span>
                    <span>${fase.dias}</span>
                  </div>
                `
              )
              .join("")}
          </article>
        </div>

        ${new BottomNav(this.app, "cycle").html()}
      </section>
    `;
  }

  afterRender() {
    new BottomNav(this.app, "cycle").afterRender();
    document.querySelectorAll("[data-phase]").forEach((button) => {
      button.addEventListener("click", () => {
        this.app.state.ciclo.corrigirFase(button.dataset.phase);
        this.app.render();
      });
    });
  }
}
