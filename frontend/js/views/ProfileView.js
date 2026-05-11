class ProfileView extends BaseComponent {
  html() {
    const { usuario, ciclo } = this.app.state;

    return `
      <section class="screen">
        <header class="screen-title">
          <p class="eyebrow">Seu perfil</p>
          <h1 class="title">${usuario.nome}</h1>
        </header>

        <div class="stack">
          <article class="card profile-card">
            <div class="user-summary">
              <span class="avatar">${usuario.inicial}</span>
              <div>
                <h2 class="profile-name">${usuario.nome}</h2>
                <p class="subtitle">${usuario.idade} anos</p>
              </div>
            </div>
            <div class="profile-facts">
              <span><span class="fact-label">Peso</span><strong class="fact-value">${usuario.peso}</strong></span>
              <span><span class="fact-label">Altura</span><strong class="fact-value">${usuario.altura}</strong></span>
            </div>
          </article>

          <article class="profile-row">
            <span class="row-icon">◎</span>
            <span><span class="row-label">Objetivo</span><strong class="row-value">${usuario.objetivo}</strong></span>
          </article>

          <article class="profile-row">
            <span class="row-icon">♙</span>
            <span><span class="row-label">Nivel</span><strong class="row-value">${usuario.nivel}</strong></span>
          </article>

          <article class="profile-row">
            <span class="row-icon">♡</span>
            <span><span class="row-label">Restrições</span><strong class="row-value">${usuario.restricoes}</strong></span>
          </article>

          <article class="profile-row">
            <span class="row-icon">☾</span>
            <span><span class="row-label">Ciclo</span><strong class="row-value">${ciclo.mediaDias} dias em média</strong><span class="subtitle">Última menstruação: ${ciclo.ultimaMenstruacao}</span></span>
          </article>

          <div class="profile-actions">
            <button class="outline-button" type="button">↪ Sair</button>
            <button class="outline-button danger-button" type="button">♧ Apagar conta</button>
          </div>

          <p class="version-note">LunaFit - Movimento que respeita seu ritmo</p>
        </div>

        ${new BottomNav(this.app, "profile").html()}
      </section>
    `;
  }

  afterRender() {
    new BottomNav(this.app, "profile").afterRender();
  }
}
