# 🌙 LunaFit

LunaFit é uma aplicação desenvolvida em C++ com arquitetura orientada a objetos, voltada para recomendação personalizada de treinos físicos femininos com base no ciclo menstrual, perfil físico e estado emocional da usuária.

O sistema integra frontend e backend através de API REST utilizando o framework Crow, permitindo geração dinâmica de treinos adaptados às diferentes fases hormonais.

Acesse o site aqui - https://jaikarla.github.io/lunafit/ 

---

# Funcionalidades

- Cadastro de usuária
- Perfil físico personalizado
- Registro do ciclo menstrual
- Geração inteligente de treinos
- Recomendação baseada em:
  - fase do ciclo;
  - objetivo físico;
  - nível de experiência;
- Interface frontend integrada ao backend

---

# Regras de Negócio

O sistema adapta os treinos conforme:

| Fase do Ciclo | Objetivo |
|---|---|
| Menstrual | Recuperação, conforto e baixo impacto |
| Folicular | Crescimento de energia e fortalecimento |
| Ovulatória | Pico de desempenho e intensidade |
| Lútea | Manutenção e recuperação ativa |

Além disso, o sistema considera:

- intensidade adequada;
- restrições físicas;
- experiência da usuária.

---

# Arquitetura do Projeto

O projeto segue arquitetura em camadas.

```txt
backend/
│
├── src/
│   ├── controllers/
│   ├── services/
│   ├── routes/
│   ├── models/
│   ├── database/
│   └── main.cpp
│
frontend/
│
├── js/
│   ├── components/
│   ├── models/
│   ├── views/
│   ├── pages/
│   └── api.js
```

---

# Tecnologias Utilizadas

## Backend

- C++
- Crow Framework
- SQLite
- CMake

## Frontend

- HTML5
- CSS3
- JavaScript Vanilla

---

# Programação Orientada a Objetos

O projeto foi construído utilizando fortemente conceitos de POO.

## Encapsulamento

As classes encapsulam atributos e regras internas através de métodos getters/setters e controle de acesso.

Exemplo:

```cpp
class Usuario {
private:
    int id;
    std::string nome;
};
```

---

## Herança

As fases do ciclo menstrual herdam comportamento comum da abstração principal de fase.

Exemplo:

```txt
FaseMenstrual
FaseFolicular
FaseOvulatoria
FaseLutea
```

---

## Polimorfismo

O sistema utiliza polimorfismo para trocar dinamicamente o comportamento da recomendação de treino conforme a fase do ciclo.

Exemplo:

```cpp
recomendador.definirFaseDoCiclo(
    std::make_unique<FaseMenstrual>()
);
```

Cada fase implementa sua própria lógica de treino.

---

## Abstração

A lógica principal é abstraída através de interfaces e classes responsáveis apenas por seu domínio específico.

Exemplo:

- controllers → controle HTTP
- services → regras de negócio
- models → entidades
- database → persistência

---

# Principais Estruturas

## Models

Representam entidades do sistema:

- Usuario
- PerfilFisico
- CicloMenstrual
- EstadoUsuario
- HistoricoTreinoDiario
- Treino

---

## Services

Contêm a principal lógica de negócio do sistema:

- RecomendadorTreino
- FaseMenstrual
- FaseFolicular
- FaseOvulatoria
- FaseLutea
- UsuarioService

---

## Controllers

Responsáveis por:

- receber requisições;
- validar dados;
- chamar regras de negócio;
- retornar respostas JSON.

---

## Routes

Mapeiam endpoints HTTP.

Exemplo:

```cpp
CROW_ROUTE(app, "/treinos/recomendar")
```

---

# Principal Lógica do Sistema

A principal lógica está localizada em:

```txt
backend/src/services/
```

Especialmente em:

```txt
RecomendadorTreino.cpp
```

e nas implementações das fases:

```txt
FaseMenstrual.cpp
FaseFolicular.cpp
FaseOvulatoria.cpp
FaseLutea.cpp
```

---


# Banco de Dados

O projeto utiliza SQLite.

Os exercícios são armazenados em:

```txt
seed.sql
```

Separados por:

- fase do ciclo;
- intensidade;
- tipo;
- restrição física.

---

# Como Executar

## Backend

### 1. Entrar na pasta do backend

```bash
cd backend
```

### 2. Compilar

```bash
cmake -B build
cmake --build build
```

### 3. Executar

```bash
./build/lunafit_backend.exe
```

Servidor iniciado em:

```txt
http://localhost:18080
```

---

## Frontend

Abrir o frontend utilizando Live Server.

Exemplo:

```txt
frontend/js/pages/App/app.html
```

---


## Autoria

[Equipe CIntilante]
Ana Clara Bizarria, Byanca Souza, Jaianny Souza, Raiana Donato e Samara Petrilly.
