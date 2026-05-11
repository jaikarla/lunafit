export class BaseComponent {
  constructor(app) {
    this.app = app;
  }

  html() {
    return "";
  }

  afterRender() {}
}
