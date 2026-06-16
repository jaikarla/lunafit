#include "HistoricoController.h"

#include "../services/UsuarioService.h"

#include "../models/TreinoRealizado.h"
#include "../models/Usuario.h"

#include "../database/database.h"

//Controlador para lidar com as requisições relacionadas ao histórico de treinos diários da usuária
crow::response HistoricoController::registrarTreino(
    Database& db,
    int usuarioId,
    const crow::request& req
) {

    auto body = crow::json::load(req.body);

    if (!body) {

        return crow::response(
            400,
            "JSON inválido"
        );
    }

    try {

        std::string data =
            body["data"].s();

        int nivelDisposicao =
            body["nivelDisposicao"].i();

        std::string nivel;
        if (nivelDisposicao <= 3)       nivel = "baixa";
        else if (nivelDisposicao <= 6)  nivel = "media";
        else                               nivel = "alta";

        // salva no banco
        std::string sql =
            "INSERT INTO historico_treino_diario "
            "(user_id, data, nivel_disposicao) VALUES ("
            + std::to_string(usuarioId) + ", '"
            + data + "', '"
            + nivel + "');";
        if (!db.execute(sql)){
            return crow::response(500, "Erro ao salvar treino");
        }

        return crow::response(
            201,
            "Treino registrado com sucesso"
        );

    } catch (...) {

        return crow::response(
            500,
            "Erro ao registrar treino"
        );
    }
}

//Controlador para lidar com as requisições relacionadas à listagem do histórico de treinos diários da usuária
crow::response HistoricoController::listarHistorico(
    Database& db,
    int usuarioId
) {

    // lê histórico do banco
    sqlite3_stmt* stmt;
    const char* sql =
        "SELECT data, nivel_disposicao "
        "FROM historico_treino_diario "
        "WHERE user_id = ? ORDER BY data DESC;";

    if (sqlite3_prepare_v2(
            db.getDb(), sql, -1, &stmt, nullptr
        ) != SQLITE_OK)
        return crow::response(500, "Erro ao buscar histórico");

    sqlite3_bind_int(stmt, 1, usuarioId);

    crow::json::wvalue resposta;
    int i = 0;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        resposta[i]["data"] = reinterpret_cast<const char*>(
            sqlite3_column_text(stmt, 0));
        resposta[i]["nivelDisposicao"] = reinterpret_cast<const char*>(
            sqlite3_column_text(stmt, 1));
        i++;
    }

    sqlite3_finalize(stmt);

    return crow::response(
        200,
        resposta
    );
}