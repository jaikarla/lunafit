# ADR-003 — Implementação do Banco de Dados SQLite

**Status:** Aceito  
**Data:** 09/05/2026  
**Decisor:** Samara Petrilly  

---

# Contexto

O sistema LunaFit precisa armazenar e recuperar dados de usuárias, ciclos menstruais, perfis físicos, catálogo de exercícios e histórico de treinos com persistência real entre sessões do servidor.

A equipe avaliou alternativas de banco de dados, porém soluções como PostgreSQL ou MySQL exigem servidor externo e configuração adicional de ambiente. Já soluções NoSQL e serviços cloud adicionam complexidade de integração com C++.

Dessa forma, buscou-se uma solução simples, leve e integrada diretamente ao backend.

---

# Decisão

Foi decidido adotar o SQLite 3 como banco de dados do sistema, com os arquivos `sqlite3.h` e `sqlite3.c` incluídos diretamente no repositório, dentro da pasta:

```txt
src/database/sqlite/
```

A estrutura do banco é definida em `schema.sql` e o catálogo inicial de exercícios é populado via `seed.sql`, ambos executados automaticamente na inicialização do servidor.

A arquitetura foi dividida em:

1. **Biblioteca embarcada (`sqlite3.h` / `sqlite3.c`)**  
   Compilada diretamente junto ao executável C++, sem necessidade de instalação externa.

2. **Classe Database (`database.h` / `database.cpp`)**  
   Encapsula a conexão com o banco, execução de comandos SQL e leitura de arquivos `.sql`.

3. **Schema relacional (`schema.sql`)**  
   Define as tabelas `users`, `perfil_fisico`, `ciclos`, `exercicios`, `treinos`, `treino_exercicios`, `plano_treino_diario`, `plano_treinos` e `historico_treino_diario`, utilizando chaves estrangeiras e constraints de validação.

4. **Seed de dados (`seed.sql`)**  
   Popula o catálogo com exercícios organizados por fase do ciclo, intensidade, tipo e restrição física.

A conexão com o banco é inicializada em:

```txt
backend/src/main.cpp
```

e reutilizada por referência (`Database& db`) entre controllers e services.

---

# Consequências Positivas

- **Integração nativa com C++**  
  O SQLite foi escrito em C e integra diretamente com C++ sem adaptadores ou requisições HTTP intermediárias.

- **Zero configuração de ambiente**  
  Qualquer membro da equipe consegue executar o projeto sem instalar servidores de banco de dados adicionais. O arquivo `.db` é criado automaticamente na primeira execução.

- **Portabilidade**  
  O banco acompanha o servidor onde quer que ele esteja.

- **Suporte completo a SQL**  
  Permite uso de `JOINs`, `constraints`, filtros e relacionamentos de forma nativa.

- **Facilidade para desenvolvimento acadêmico**  
  Simplifica testes locais e reduz complexidade de setup do ambiente.

---

# Consequências Negativas

- **Escrita sequencial**  
  O SQLite não suporta múltiplas escritas simultâneas de forma eficiente.

- **Banco não compartilhado entre máquinas da equipe**  
  Cada desenvolvedor possui sua própria instância local do banco.

- **Ausência de migração automática de schema**  
  Alterações estruturais exigem recriação manual do arquivo `.db`.

---

# Notas de Implementação

Para garantir compatibilidade com o padrão Strategy implementado em:

```txt
src/services/
```

o ponteiro `sqlite3*` é exposto via:

```cpp
Database::getDb()
```

e utilizado pelas estratégias através do `RecomendadorTreino`.

A conexão é aberta uma única vez no `main.cpp` e repassada por referência (`Database& db`) para controllers e services, evitando múltiplas conexões simultâneas com o mesmo arquivo `.db`.