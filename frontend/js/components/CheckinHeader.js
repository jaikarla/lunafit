import { BaseComponent } from "./BaseComponent.js";

export class CheckinHeader extends BaseComponent {
  constructor(app, step) {
    super(app);
    this.step = step;
  }

  html() {
    return `
      <header class="checkin-header">
        <div class="checkin-label"><span aria-hidden="true">&#9825;</span> check-in di&aacute;rio</div>
        <div class="checkin-progress" aria-label="Passo ${this.step} de 3">
          ${[1, 2, 3].map((number) => `<span class="${number <= this.step ? "is-done" : ""}"></span>`).join("")}
        </div>
      </header>
    `;
  }
}
