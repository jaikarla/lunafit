cmake_minimum_required(VERSION 3.10)

project(LunafitBackend)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    src
    src/services
    src/database/sqlite
    external
)

#executável principal do backend
add_executable(lunafit_backend

    #main
    src/main.cpp

    #database
    src/database/database.cpp
    src/database/sqlite/sqlite3.c

    #controllers
    src/controllers/UsuarioController.cpp
    src/controllers/TreinoController.cpp
    src/controllers/HistoricoController.cpp

    #models
    src/models/Usuario.cpp
    src/models/EstadoUsuario.cpp
    src/models/PerfilFisico.cpp
    src/models/CicloMenstrual.cpp
    src/models/HistoricoTreinoDiario.cpp
    src/models/TreinoRealizado.cpp

    src/models/Exercicio.cpp
    src/models/ExercicioBemEstar.cpp
    src/models/ExercicioFortalecimento.cpp
    src/models/PlanoTreinoDiario.cpp
    src/models/Treino.cpp

    #services
    src/services/UsuarioService.cpp

    src/services/RecomendadorTreino.cpp
    src/services/EstrategiaTreino.cpp

    src/services/FaseMenstrual.cpp
    src/services/FaseFolicular.cpp
    src/services/FaseOvulatoria.cpp
    src/services/FaseLutea.cpp
)

#include do sqlite
target_include_directories(lunafit_backend PRIVATE
    src/database/sqlite
)

#configurações específicas Windows
if(WIN32)

    target_compile_definitions(
        lunafit_backend
        PRIVATE
        _WIN32_WINNT=0x0600
    )

    target_link_libraries(
        lunafit_backend
        PRIVATE
        ws2_32
        mswsock
        m
    )

endif()

#copia arquivos do banco para build
file(
    COPY
    "${CMAKE_CURRENT_SOURCE_DIR}/src/database/schema.sql"
    DESTINATION
    "${CMAKE_CURRENT_BINARY_DIR}"
)

file(
    COPY
    "${CMAKE_CURRENT_SOURCE_DIR}/src/database/seed.sql"
    DESTINATION
    "${CMAKE_CURRENT_BINARY_DIR}"
)

