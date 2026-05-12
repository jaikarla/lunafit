#pragma once

#include "crow/app.h"

#include "../database/database.h"

class TreinoController {

public:

    static crow::response recomendarTreino(
        Database& db,
        const crow::request& req
    );
};