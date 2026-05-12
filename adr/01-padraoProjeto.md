# ADR-001 — Implementação do Padrão Strategy para Recomendações de Treino

**Status:** Aceito  
**Data:** 09/05/2026  
**Decisor:** Ana Clara 

---

# Contexto

O sistema Lunafit precisa fornecer recomendações de exercícios baseadas na fase do ciclo menstrual da usuária (Menstrual, Folicular, Ovulatória e Lútea). Cada fase possui regras de negócio distintas, intensidades recomendadas variadas e objetivos específicos (bem-estar vs. fortalecimento). Inicialmente, o código correria o risco de se tornar um amontoado de condicionais `if/else ou switch`, dificultando a manutenção e a aplicação de filtros de restrição física.

--- 

# Decisão

Decidimos implementar o Strategy Pattern na camada de Services. A arquitetura foi dividida em:

1. Interface Base (EstrategiaTreino): Uma classe abstrata que define o contrato `gerarTreino()`.
2. Estratégias Concretas: Classes específicas para cada fase (FaseMenstrual, FaseFolicular, etc.) que encapsulam a lógica de consulta ao banco de dados e filtros específicos.
3. Contexto (RecomendadorTreino): Uma classe que recebe a estratégia correta em tempo de execução e delega a execução da recomendação.

--- 

# Consequências Positivas

* Princípio Aberto/Fechado (Solid): Podemos adicionar novas fases ou tipos de recomendação (ex: fase pós-parto) criando novas classes sem alterar o código existente do RecomendadorTreino.
* Separação de Preocupações: A lógica de filtragem SQL e regras de cada fase ficam isoladas, facilitando testes unitários.
* Limpeza de Código: Eliminamos grandes blocos de `if/else`, tornando o main.cpp mais legível e focado em orquestração.
* Flexibilidade de Filtros: Permite que restrições físicas (como lesões no joelho) sejam tratadas de forma granular dentro de cada estratégia.

--- 

# Consequências Negativas

* Aumento no número de arquivos: O projeto agora possui mais arquivos de cabeçalho **(.h)** e implementação **(.cpp)** devido à criação de classes para cada fase.
* Complexidade Inicial: Exige que o desenvolvedor entenda conceitos de polimorfismo e ponteiros inteligentes em C++.

--- 

# Notas de Implementação

Para garantir a compatibilidade com a branch *feat/models*, as estratégias devem consumir objetos do tipo Usuario ou CicloMenstrual para extrair os parâmetros necessários (objetivo, intensidade, restricao_fisica).