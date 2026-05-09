cmake_minimum_required(VERSION 3.10)
project(LunafitBackend)

set(CMAKE_CXX_STANDARD 17)

# Adiciona os diretórios para que o C++ encontre os arquivos .h
include_directories(
    src 
    src/services 
    src/database/sqlite
)

# lista de arquivos
add_executable(lunafit_backend
    src/main.cpp
    src/database/database.cpp
    src/database/sqlite/sqlite3.c
    
    # Models 
    src/models/EstadoUsuario.cpp
    src/models/CicloMenstrual.cpp
    src/models/Exercicio.cpp
    src/models/ExercicioBemEstar.cpp
    src/models/ExercicioFortalecimento.cpp
    src/models/HistoricoTreinoDiario.cpp
    src/models/PerfilFisico.cpp
    src/models/PlanoTreinoDiario.cpp
    src/models/Treino.cpp
    src/models/TreinoRealizado.cpp
    src/models/Usuario.cpp
    
    # Services 
    src/services/RecomendadorTreino.cpp
    src/services/FaseMenstrual.cpp
    src/services/FaseFolicular.cpp
    src/services/FaseOvulatoria.cpp
    src/services/FaseLutea.cpp
)

# Permite que o executável encontre o sqlite3.h
target_include_directories(lunafit_backend PRIVATE
    src/database/sqlite
)

# Definições específicas para Windows (MinGW)
if(WIN32)
    target_compile_definitions(lunafit_backend PRIVATE _WIN32_WINNT=0x0600)
    # Necessário para linkar a biblioteca de threads/sistema se usar SQLite no Windows
    target_link_libraries(lunafit_backend PRIVATE m)
endif()

# Copia os arquivos SQL e o Banco para a pasta de build automaticamente
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/src/database/schema.sql" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/src/database/seed.sql" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/src/database/lunafit.db" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")