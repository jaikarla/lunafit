#include "database/Database.h"

int main() {
    Database db;

    if (!db.connect("../backend/src/database/lunafit.db"))
        return 1;

    db.execute("CREATE TABLE IF NOT EXISTS Teste (id INTEGER PRIMARY KEY, nome TEXT);");
    db.execute("INSERT INTO Teste (nome) VALUES ('Mara');");

    db.close();
    return 0;
}