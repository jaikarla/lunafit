const lunaFitData = {
  usuario: new Usuario({
    nome: "",
    idade: 19,
    peso: "62 kg",
    altura: "162 cm",
    objetivo: "Fortalecimento físico",
    nivel: "Iniciante",
    restricoes: "Nenhuma restrição cadastrada",
  }),
  ciclo: new CicloMenstrual({
    faseAtual: "Folicular",
    diaAtual: 8,
    proximaMenstruacao: "29 de maio",
    ultimaMenstruacao: "01/05/2026",
    mediaDias: 28,
    fases: [
      { nome: "Menstrual", dias: "Dias 1-5", cor: "#ef476f", emoji: "🌺", descricao: "Momento de recolher e respirar." },
      { nome: "Folicular", dias: "Dias 6-13", cor: "#d96bd6", emoji: "🌑", descricao: "Energia em alta, boa fase para experimentar." },
      { nome: "Ovulatória", dias: "Dias 14-16", cor: "#ffd166", emoji: "🌕", descricao: "Força e presença em destaque." },
      { nome: "Lútea", dias: "Dias 17-28", cor: "#7b2cbf", emoji: "🌘", descricao: "Treinos constantes e mais gentis." },
    ],
  }),
  treino: new Treino({
    titulo: "Construir e florescer",
    foco: "Yoga ativo + força leve",
    duracao: "30 min",
    intensidade: "leve",
    frase: "Sua energia está crescendo, explore novos limites com leveza.",
    exercicios: [
      { nome: "Saudação ao Sol (suave)", descricao: "Encaixe as posturas respeitando seu ritmo respiratório.", duracao: "3 séries" },
      { nome: "Guerreiro II", descricao: "Pernas afastadas, uma flexionada, braços paralelos ao chão.", duracao: "cada lado" },
      { nome: "Agachamento livre", descricao: "Pés na largura dos ombros, desça mantendo coluna alinhada.", duracao: "4x12" },
      { nome: "Postura da criança", descricao: "Ajoelhe-se, sente sobre os calcanhares e estenda os braços à frente.", duracao: "1 min" },
    ],
  }),
  checkin: new CheckinDiario(),
};
