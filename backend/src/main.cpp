#include <iostream>
#include "sqlite3.h"

int main(){
    sqlite3* db;
   
    int resultado = sqlite3_open("src/database/lunafit.db", &db);

    if(resultado){
        std:: cout << "Erro ao abrir banco de dados\n";
    }

    std::cout << "Banco de Dados funcionando!\n";

    sqlite3_close(db);
    return 0;
}