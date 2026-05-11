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

  render() {
    const view = this.getView();
    this.root.innerHTML = view.html();
    view.afterRender();
  }
}

document.addEventListener("DOMContentLoaded", () => {
  const app = new LunaFitApp(document.getElementById("app"), lunaFitData);
  app.render();
});
