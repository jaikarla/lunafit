--ORGANIZAÇÃO GERAL E GERAÇÃO DE TABELAS DO BANCO DE DADOS

--=============================================
-- TABELA: Users 
-- CLASSE: Usuario
--=============================================
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome      TEXT    NOT NULL,
    email     TEXT    NOT NULL UNIQUE,
    idade     INTEGER,
    criado_em TEXT    DEFAULT (datetime('now'))
);


--=============================================
-- TABELA: perfil_fisico
-- CLASSE: PerfilFisico
CREATE TABLE IF NOT EXISTS perfil_fisico (
    id                INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id           INTEGER NOT NULL UNIQUE,
    objetivo          TEXT    CHECK(objetivo IN ('fortalecimento', 'bem_estar')), -- limita os opções possíveis
    nivel_experiencia TEXT    CHECK(nivel_experiencia IN ('iniciante', 'intermediario', 'avancado')), -- limita opções possíveis
    restricao_fisica  TEXT    DEFAULT 'nenhuma',  -- pode ser uma combinação de valores
    FOREIGN KEY (user_id) REFERENCES users(id)
);


--=============================================
-- TABELA: ciclos
-- CLASSE: CicloMenstrual
CREATE TABLE IF NOT EXISTS ciclos (
    id                        INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id                   INTEGER NOT NULL,
    data_ultima_menstruacao   TEXT    NOT NULL,
    duracao_media_ciclo       INTEGER DEFAULT 28,
    duracao_media_menstruacao INTEGER DEFAULT 5,
    fase_atual                TEXT    DEFAULT 'menstrual'
        CHECK(fase_atual IN ('menstrual', 'folicular', 'ovulatoria', 'lutea')),
    data_proxima_menstruacao  TEXT,
    criado_em                 TEXT    DEFAULT (datetime('now')),
    FOREIGN KEY (user_id) REFERENCES users(id)
);


--=============================================
-- TABELA: exercicios
-- CLASSE: Exercicio 
-- + ExercicioFortalecimento
-- + ExercicioBemEstar
-- A coluna "tipo" diferencia qual subclasse é
-- A coluna "fase" diz para qual fase do ciclo serve
--=============================================
CREATE TABLE IF NOT EXISTS exercicios (
    id          INTEGER PRIMARY KEY AUTOINCREMENT,
    nome        TEXT    NOT NULL,
    duracao     TEXT,
    intensidade TEXT    NOT NULL
        CHECK(intensidade IN ('leve', 'moderado', 'alta')),
    tipo        TEXT    NOT NULL
        CHECK(tipo IN ('fortalecimento', 'bem_estar')),
    fase        TEXT    NOT NULL
        CHECK(fase IN ('menstrual', 'folicular', 'ovulatoria', 'lutea')),
    descricao   TEXT,
    restricao_fisica TEXT    DEFAULT 'nenhuma'
);


--=============================================
-- TABELA: treinos
-- CLASSE: Treino
CREATE TABLE IF NOT EXISTS treinos (
    id            INTEGER PRIMARY KEY AUTOINCREMENT,
    nome          TEXT    NOT NULL,
    duracao_total INTEGER DEFAULT 0
);


--=============================================
-- TABELA: treino_exercicios  -- tabela de ligação
-- Um treino tem vários exercícios, um exercício pode estar em vários treinos 
--=============================================
CREATE TABLE IF NOT EXISTS treino_exercicios (
    treino_id   INTEGER NOT NULL,
    exercicio_id INTEGER NOT NULL,
    PRIMARY KEY (treino_id, exercicio_id),
    FOREIGN KEY (treino_id)    REFERENCES treinos(id),
    FOREIGN KEY (exercicio_id) REFERENCES exercicios(id)
);


--=============================================
-- TABELA: plano_treino_diario
-- CLASSE: PlanoTreinoDiario
--=============================================
CREATE TABLE IF NOT EXISTS plano_treino_diario (
    id           INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id      INTEGER NOT NULL,
    data_geracao TEXT    DEFAULT (datetime('now')),
    fase_ciclo   TEXT,
    FOREIGN KEY (user_id) REFERENCES users(id)
);


--=============================================
-- TABELA: plano_treinos
--=============================================
CREATE TABLE IF NOT EXISTS plano_treinos (
    plano_id  INTEGER NOT NULL,
    treino_id INTEGER NOT NULL,
    PRIMARY KEY (plano_id, treino_id),
    FOREIGN KEY (plano_id)  REFERENCES plano_treino_diario(id),
    FOREIGN KEY (treino_id) REFERENCES treinos(id)
);

--=============================================
-- TABELA: historico_treino_diario
-- CLASSE: HistoricoTreinoDiario
--=============================================
CREATE TABLE IF NOT EXISTS historico_treino_diario (
    id               INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id          INTEGER NOT NULL,
    treino_id        INTEGER,
    data             TEXT    DEFAULT (datetime('now')),
    nivel_disposicao TEXT CHECK(nivel_disposicao IN ('baixa', 'media', 'alta')),
    como_se_sentiu   TEXT,
    fase_do_ciclo    TEXT,
    FOREIGN KEY (user_id)   REFERENCES users(id),
    FOREIGN KEY (treino_id) REFERENCES treinos(id)
); 