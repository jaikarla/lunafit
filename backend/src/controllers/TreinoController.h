#pragma once

#include "crow/app.h"

class TreinoController {

public:

    static crow::response recomendarTreino(
        const crow::request& req
    );
};