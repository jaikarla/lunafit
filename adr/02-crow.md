# ADR-002 — Escolha do Crow como Framework Backend HTTP para o LunaFit

**Status:** Aceito  
**Data:** 01/05/2026  
**Decisor:** Ana Clara  

---

# Contexto

O projeto LunaFit necessitava de um backend capaz de:

- disponibilizar endpoints HTTP para comunicação com o frontend;
- receber e enviar dados em formato JSON;
- integrar-se facilmente com C++;
- permitir organização modular do sistema que já havia sendo desenvolvida;
- suportar arquitetura em camadas;
- possuir baixo custo de configuração;
- funcionar localmente sem dependências complexas.

Além disso, o projeto foi desenvolvido utilizando Programação Orientada a Objetos em C++, o que exigia uma solução compatível com o ecossistema da linguagem.

A equipe precisava de uma forma simples e eficiente de integrar frontend e backend através de API REST.

---

# Decisão

Foi decidido utilizar o Crow como framework backend do projeto.

O Crow foi escolhido por ser:

- capaz de trabalhar com JSON e rotas HTTP de maneira direta;
- compatível com middleware CORS;
- integrado facilmente ao restante da arquitetura orientada a objetos do sistema.

---

# Consequências Positivas

A utilização do framework favoreceu a separação em camadas:

~~~txt
routes/
controllers/
services/
models/
database/
~~~

---

# Consequências Negativas

Uma delas é a menor quantidade de abstrações prontas. Algumas funcionalidades precisaram ser implementadas manualmente, como:

- tratamento de erros;
- integração de lógica de negócio;
- parsing específico de dados.

Além disso, também há a complexidade inerente do C++. Apesar do Crow simplificar APIs HTTP, o desenvolvimento em C++ ainda exige maior controle de:

- memória;
- ponteiros;
- compilação;
- organização de dependências.

Com isso, o debugging foi mais trabalhoso. Erros de compilação e integração ficam mais difíceis de identificar.

---

# Notas de Implementação

Na estrutura principal, o Crow foi inicializado em:

~~~txt
backend/src/main.cpp
~~~ 

O middlewares cors foi configurado em:

~~~txt
crow::App<crow::CORSHandler> app
~~~

permitindo a conexão com o frontend.