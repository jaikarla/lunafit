# o cmakelists serve para configurar o processo de construção do projeto usando o CMake. 
# Ele define as dependências, os arquivos de origem e as bibliotecas necessárias para compilar o backend do projeto.

# ainda tem que ser implementado, mas aqui está a "base":

cmake_minimum_required(VERSION 3.10) # Define a versão mínima do CMake

project(LunafitBackend) # Define o nome do projeto

set(CMAKE_CXX_STANDARD 17) # Define o padrão do C++ a ser usado

include_directories(src) # Adiciona o diretório de inclusão para os arquivos de cabeçalho (headers)

# Adicione os arquivos de origem do backend
add_executable(lunafit_backend
    src/main.cpp
    src/database/Database.cpp
    src/models/Usuario.cpp
    src/models/CicloMenstrual.cpp
    src/models/Recomendador.cpp
    # Adicione outros arquivos de origem conforme necessário
)