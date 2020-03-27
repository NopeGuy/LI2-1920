#include <stdio.h>
#include "interface.h"
#include "logic.h"

int main() {
    printf("\n      -----------------------\n\tWelcome to RASTROS!\n      -----------------------");
    ESTADO *e = inicializar_estado();
    printBoard(e);
    while (1) {
        if ((bool)add_position == false) {
            break;
        }
        else interpretador(e);

    }

    return 0;
}

