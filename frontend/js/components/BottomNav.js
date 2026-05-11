class BottomNav extends BaseComponent {
  constructor(app, active) {
    super(app);
    this.active = active;
    this.items = [
      { view: "home", label: "Hoje", icon: this.homeIcon() },
      { view: "cycle", label: "Ciclo", icon: this.calendarIcon() },
      { view: "workout", label: "Treino", icon: this.workoutIcon() },
      { view: "profile", label: "Perfil", icon: this.profileIcon() },
    ];
  }

  html() {
    return `
      <nav class="bottom-nav" aria-label="Navegação principal">
        ${this.items
          .map(
            (item) => `
              <button class="nav-item ${this.active === item.view ? "nav-item--active" : ""}" data-view="${item.view}" type="button">
                <span class="nav-item__icon" aria-hidden="true">${item.icon}</span>
                <span>${item.label}</span>
              </button>
            `
          )
          .join("")}
      </nav>
    `;
  }

  afterRender() {
    document.querySelectorAll("[data-view]").forEach((button) => {
      button.addEventListener("click", () => this.app.navigate(button.dataset.view));
    });
  }

  homeIcon() {
    return `
      <svg viewBox="0 0 24 24" fill="none">
        <path d="M4 10.8 12 4l8 6.8v8.1a1.6 1.6 0 0 1-1.6 1.6h-3.5v-6.1H9.1v6.1H5.6A1.6 1.6 0 0 1 4 18.9v-8.1Z" stroke="currentColor" stroke-width="1.8" stroke-linejoin="round"/>
      </svg>
    `;
  }

  calendarIcon() {
    return `
      <svg viewBox="0 0 24 24" fill="none">
        <path d="M7 3.8v3.1M17 3.8v3.1M4.8 9h14.4M6.4 5.4h11.2a2.2 2.2 0 0 1 2.2 2.2v10.2a2.2 2.2 0 0 1-2.2 2.2H6.4a2.2 2.2 0 0 1-2.2-2.2V7.6a2.2 2.2 0 0 1 2.2-2.2Z" stroke="currentColor" stroke-width="1.8" stroke-linecap="round"/>
        <path d="m8.2 14.1 2.1 2.1 5.4-5.1" stroke="currentColor" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"/>
      </svg>
    `;
  }

  workoutIcon() {
    return `
      <svg viewBox="0 0 24 24" fill="none">
        <path d="m8.1 8.5-3.4 3.4a2.3 2.3 0 0 0 0 3.2l.2.2a2.3 2.3 0 0 0 3.2 0l3.4-3.4M15.9 15.5l3.4-3.4a2.3 2.3 0 0 0 0-3.2l-.2-.2a2.3 2.3 0 0 0-3.2 0l-3.4 3.4" stroke="currentColor" stroke-width="1.8" stroke-linecap="round"/>
        <path d="M9 4.5v3M7.5 6h3M16.5 17.9v2.6M15.2 19.2h2.6" stroke="currentColor" stroke-width="1.7" stroke-linecap="round"/>
      </svg>
    `;
  }

  profileIcon() {
    return `
      <svg viewBox="0 0 24 24" fill="none">
        <path d="M12 12.2a4 4 0 1 0 0-8 4 4 0 0 0 0 8ZM4.8 20.1c.9-3.5 3.3-5.4 7.2-5.4s6.3 1.9 7.2 5.4" stroke="currentColor" stroke-width="1.8" stroke-linecap="round"/>
      </svg>
    `;
  }
}
