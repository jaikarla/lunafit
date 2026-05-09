# o cmakelists serve para configurar o processo de construção do projeto usando o CMake. 
# Ele define as dependências, os arquivos de origem e as bibliotecas necessárias para compilar o backend do projeto.

# ainda tem que ser implementado, mas aqui está a "base":

cmake_minimum_required(VERSION 3.10) # Define a versão mínima do CMake

project(LunafitBackend) # Define o nome do projeto

set(CMAKE_CXX_STANDARD 17) # Define o padrão do C++ a ser usado

include_directories( # Adiciona o diretório de inclusão para os arquivos de cabeçalho (headers)
    src
    external
)

add_executable(crow_test #define o executável para os testes do Crow
    src/server_test.cpp
)

target_link_libraries(crow_test
    ws2_32
    mswsock
)

# Adicione os arquivos de origem do backend
add_executable(lunafit_backend
    src/main.cpp
    src/database/database.cpp
    src/models/Usuario.cpp
    src/models/CicloMenstrual.cpp
    src/services/RecomendadorTreino.cpp
    src/database/sqlite/sqlite3.c
    # Adicione outros arquivos de origem conforme necessário
)

target_include_directories(lunafit_backend PRIVATE
    src/database/sqlite
) # o executavel pode acessar arquivos .h (permite que se encontre o sqlite.h) - samara

target_compile_definitions(lunafit_backend PRIVATE
    _WIN32_WINNT=0x0600
)