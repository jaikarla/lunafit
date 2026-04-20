# o cmakelists serve para configurar o processo de construção do projeto usando o CMake. 
# Ele define as dependências, os arquivos de origem e as bibliotecas necessárias para compilar o backend do projeto.

cmake_minimum_required(VERSION 3.10) # Define a versão mínima do CMake

project(LunafitBackend) # Define o nome do projeto

set(CMAKE_CXX_STANDARD 17) # Define o padrão do C++ a ser usado

include_directories(backend/src) # Adiciona o diretório de inclusão para os arquivos de cabeçalho (headers)

# Adicione os arquivos de origem do backend
add_executable(lunafit_backend
    backend/src/main.cpp
    backend/src/services/RecomendadorTreino.cpp
    backend/src/services/FaseMenstrual.cpp
    backend/src/services/FaseFolicular.cpp
    backend/src/services/FaseLutea.cpp
    backend/src/services/FaseOvulatoria.cpp
    
    backend/src/controllers/UsuarioController.cpp


    # ainda falta adicionar os arquivos abaixo

    # backend/src/database/...
    # backend/src/models/...
    # Adicione outros arquivos de origem conforme necessário
)