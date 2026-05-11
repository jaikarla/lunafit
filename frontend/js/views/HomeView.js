class HomeView extends BaseComponent {
  html() {
    const { usuario, ciclo, treino, checkin } = this.app.state;
    const fase = ciclo.fase;

    return `
      <section class="screen">
        <header class="home-header">
          <img class="logo-mark" src="assets/logo-lunafit (sem fundo).png" alt="Logo LunaFit" />
          <div>
            <p class="eyebrow">${this.app.dataFormatada}</p>
            <h1 class="title">Olá, ${usuario.primeiroNome}</h1>
          </div>
        </header>

        <div class="stack">
          <article class="card phase-card">
            <div class="phase-card__top">
              <div>
                <p class="eyebrow">Fase atual</p>
                <h2 class="phase-name">${ciclo.faseAtual} <span aria-hidden="true">${fase.emoji}</span></h2>
              </div>
              <div class="phase-day">Dia ${ciclo.diaAtual}<small>de 28</small></div>
            </div>
            <p class="subtitle">${fase.descricao} Ótima fase para experimentar e construir força.</p>
            <div class="phase-scale">
              <span class="phase-scale__marker"></span>
              <span>Menstrual</span><span>Folicular</span><span>Ovulatória</span><span>Lútea</span>
            </div>
            <p class="subtitle">Próxima menstruação em <strong>21 dias</strong></p>
          </article>

          <button class="hint-card" type="button" data-checkin-start>
            <span aria-hidden="true">✦</span>
            <span>Mesmo nos dias difíceis, mover-se um pouco é um ato de amor próprio.</span>
          </button>

          <article class="card today-workout">
            <p class="eyebrow">Seu treino de hoje</p>
            <h2 class="workout-title">${treino.titulo}</h2>
            <p class="subtitle">${treino.foco} - ${treino.duracao}</p>
            <div class="badge-row">
              <span class="badge">${treino.intensidade}</span>
              <span class="badge">${treino.totalExercicios} exercícios</span>
            </div>
            <button class="gradient-button" type="button" data-start-workout>Iniciar treino</button>
          </article>

          <div class="metric-grid">
            <article class="card quick-stat">
              <span class="eyebrow">Humor</span>
              <strong>${checkin.humor || "Triste"}</strong>
            </article>
            <article class="card quick-stat">
              <span class="eyebrow">Disposicao</span>
              <strong>${checkin.disposicao || "Baixa"}</strong>
            </article>
          </div>
        </div>

        ${new BottomNav(this.app, "home").html()}
      </section>
    `;
  }

  afterRender() {
    new BottomNav(this.app, "home").afterRender();
    document.querySelector("[data-start-workout]").addEventListener("click", () => this.app.navigate("workout"));
    document.querySelector("[data-checkin-start]").addEventListener("click", () => this.app.navigate("checkin-1"));
  }
}
