#include "UsuarioService.h"

#include <sstream>

//definindo do vetor estático para armazenar os usuários cadastrados
std::vector<Usuario> UsuarioService::usuarios;

Usuario UsuarioService::usuarioCache(
    0, 0, "", "", "", 0.0, 0.0,
    PerfilFisico("", ""),
    CicloMenstrual("", 28)
);

//juntar restrições em texto
static std::string juntarRestricoes(
    const std::vector<std::string>& restricoes
) {
    if (restricoes.empty()) return "nenhuma";
    std::string resultado;
    for (int i = 0; i < (int)restricoes.size(); i++) {
        if (i > 0) resultado += ",";
        resultado += restricoes[i];
    }
    return resultado;
}

//separa o texto em restrições
static std::vector<std::string> separarRestricoes(
    const std::string& texto
) {
    std::vector<std::string> resultado;
    if (texto.empty() || texto == "nenhuma")
        return resultado;
    std::stringstream ss(texto);
    std::string item;
    while (std::getline(ss, item, ','))
        resultado.push_back(item);
    return resultado;
}


void UsuarioService::criarUsuario(
    Database& db,
    const Usuario& usuario) {
    usuarios.push_back(usuario);

    //salvar no banco
    auto perfil = usuario.getPerfilFisico();
    auto ciclo  = usuario.getCicloMenstrual();
    std::string restricoes =
        juntarRestricoes(perfil.getRestricoes());

     db.execute(
        "INSERT OR IGNORE INTO users (id, nome, email, senha, idade, peso, altura) VALUES ("
        + std::to_string(usuario.getId()) + ", '"
        + usuario.getNome() + "', '"
        + usuario.getEmail() + "', '"
        + usuario.getSenha() + "', "
        + std::to_string(usuario.getIdade()) + ", "
        + std::to_string(usuario.getPeso()) + ", "
        + std::to_string(usuario.getAltura()) + ");"
    );

    db.execute(
        "INSERT OR IGNORE INTO perfil_fisico "
        "(user_id, objetivo, nivel_experiencia, restricao_fisica) VALUES ("
        + std::to_string(usuario.getId()) + ", '"
        + perfil.getObjetivo() + "', '"
        + perfil.getNivelExperiencia() + "', '"
        + restricoes + "');"
    );

    db.execute(
        "INSERT OR IGNORE INTO ciclos "
        "(user_id, data_ultima_menstruacao, duracao_media_ciclo) VALUES ("
        + std::to_string(usuario.getId()) + ", '"
        + ciclo.getDataUltimaMenstruacao() + "', "
        + std::to_string(ciclo.getDuracaoMediaCiclo()) + ");"
    );

}

//método para gerar um novo ID único para cada usuário criado
int UsuarioService::gerarNovoId(Database& db) {
    int novoId = 1;
    sqlite3_stmt* stmt;
    const char* sql = "SELECT MAX(id) FROM users;";

    if (sqlite3_prepare_v2(
            db.getDb(), sql, -1, &stmt, nullptr
        ) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            if (sqlite3_column_type(stmt, 0) != SQLITE_NULL)
                novoId = sqlite3_column_int(stmt, 0) + 1;
        }
        sqlite3_finalize(stmt);
    }
    return novoId;
}


//método para listar todos os usuários cadastrados
std::vector<Usuario> UsuarioService::listarUsuarios(Database& db) {
    std::vector<Usuario> lista;

    sqlite3_stmt* stmt;
    const char* sql =
        "SELECT u.id, u.nome, u.email, u.senha, u.idade, u.peso, u.altura, "
        "p.objetivo, p.nivel_experiencia, p.restricao_fisica, "
        "c.data_ultima_menstruacao, c.duracao_media_ciclo "
        "FROM users u "
        "LEFT JOIN perfil_fisico p ON p.user_id = u.id "
        "LEFT JOIN ciclos c ON c.user_id = u.id;";

    if (sqlite3_prepare_v2(
            db.getDb(), sql, -1, &stmt, nullptr
        ) != SQLITE_OK)
        return lista;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id        = sqlite3_column_int(stmt, 0);
        std::string nome  = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string senha = sqlite3_column_text(stmt, 3)
            ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)) : "";
        int    idade  = sqlite3_column_int(stmt, 4);
        double peso   = sqlite3_column_double(stmt, 5);
        double altura = sqlite3_column_double(stmt, 6);

        std::string objetivo = sqlite3_column_text(stmt, 7)
            ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7)) : "";
        std::string nivel = sqlite3_column_text(stmt, 8)
            ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8)) : "";
        std::string restricaoTexto = sqlite3_column_text(stmt, 9)
            ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9)) : "nenhuma";

        std::string dataUltima = sqlite3_column_text(stmt, 10)
            ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10)) : "";
        int duracaoCiclo = sqlite3_column_int(stmt, 11);

        PerfilFisico perfil(objetivo, nivel);
        for (const auto& r : separarRestricoes(restricaoTexto))
            perfil.adicionarRestricao(r);

        CicloMenstrual ciclo(dataUltima, duracaoCiclo);
        lista.push_back(Usuario(id, idade, nome, email, senha, peso, altura, perfil, ciclo));
    }
    sqlite3_finalize(stmt);
    return lista;
}

//método para buscar um usuário por ID, retornando um ponteiro para o usuário encontrado ou nullptr se não encontrado
Usuario* UsuarioService::buscarUsuarioPorId(
    Database &db,
    int id)
    {
    sqlite3_stmt* stmt;
    const char* sql =
        "SELECT u.id, u.nome, u.email, u.senha, u.idade, u.peso, u.altura, "
        "p.objetivo, p.nivel_experiencia, p.restricao_fisica, "
        "c.data_ultima_menstruacao, c.duracao_media_ciclo "
        "FROM users u "
        "LEFT JOIN perfil_fisico p ON p.user_id = u.id "
        "LEFT JOIN ciclos c ON c.user_id = u.id "
        "WHERE u.id = ?;";

    if (sqlite3_prepare_v2(
            db.getDb(), sql, -1, &stmt, nullptr
        ) != SQLITE_OK)
        return nullptr;

    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) != SQLITE_ROW) {
        sqlite3_finalize(stmt);
        return nullptr;
    }

    int uid           = sqlite3_column_int(stmt, 0);
    std::string nome  = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
    std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
    std::string senha = sqlite3_column_text(stmt, 3)
        ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)) : "";
    int    idade  = sqlite3_column_int(stmt, 4);
    double peso   = sqlite3_column_double(stmt, 5);
    double altura = sqlite3_column_double(stmt, 6);

    std::string objetivo = sqlite3_column_text(stmt, 7)
        ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7)) : "";
    std::string nivel = sqlite3_column_text(stmt, 8)
        ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8)) : "";
    std::string restricaoTexto = sqlite3_column_text(stmt, 9)
        ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9)) : "nenhuma";

    std::string dataUltima = sqlite3_column_text(stmt, 10)
        ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10)) : "";
    int duracaoCiclo = sqlite3_column_int(stmt, 11);

    sqlite3_finalize(stmt);

    PerfilFisico perfil(objetivo, nivel);
    for (const auto& r : separarRestricoes(restricaoTexto))
        perfil.adicionarRestricao(r);

    CicloMenstrual ciclo(dataUltima, duracaoCiclo);
    usuarioCache = Usuario(uid, idade, nome, email, senha, peso, altura, perfil, ciclo);
    return &usuarioCache;
}

//método para atualizar um usuário existente
bool UsuarioService::atualizarUsuario(
    Database& db,
    int id,
    const Usuario& usuarioAtualizado
) {

    for (auto& usuario : usuarios) {

        if (usuario.getId() == id) {

            usuario = usuarioAtualizado;

            break;
        }
    }

    auto perfil = usuarioAtualizado.getPerfilFisico();
    auto ciclo  = usuarioAtualizado.getCicloMenstrual();
    std::string restricoes = juntarRestricoes(perfil.getRestricoes());

    bool ok = db.execute(
        "UPDATE users SET nome='" + usuarioAtualizado.getNome()
        + "', email='" + usuarioAtualizado.getEmail()
        + "', senha='" + usuarioAtualizado.getSenha()
        + "', idade=" + std::to_string(usuarioAtualizado.getIdade())
        + ", peso=" + std::to_string(usuarioAtualizado.getPeso())
        + ", altura=" + std::to_string(usuarioAtualizado.getAltura())
        + " WHERE id=" + std::to_string(id) + ";"
    );
    if (!ok) return false;

    db.execute(
        "UPDATE perfil_fisico SET objetivo='" + perfil.getObjetivo()
        + "', nivel_experiencia='" + perfil.getNivelExperiencia()
        + "', restricao_fisica='" + restricoes
        + "' WHERE user_id=" + std::to_string(id) + ";"
    );

    db.execute(
        "UPDATE ciclos SET data_ultima_menstruacao='"
        + ciclo.getDataUltimaMenstruacao()
        + "', duracao_media_ciclo="
        + std::to_string(ciclo.getDuracaoMediaCiclo())
        + " WHERE user_id=" + std::to_string(id) + ";"
    );
    return true;
}

//método para deletar um usuário por ID
bool UsuarioService::deletarUsuario(
    Database& db,
    int id) {

    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {

        if (it->getId() == id) {
            usuarios.erase(it);
            break;
        }
    }
    db.execute("DELETE FROM ciclos WHERE user_id="
        + std::to_string(id) + ";");
    db.execute("DELETE FROM perfil_fisico WHERE user_id="
        + std::to_string(id) + ";");
    return db.execute("DELETE FROM users WHERE id="
        + std::to_string(id) + ";");
}
  