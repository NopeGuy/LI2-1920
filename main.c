#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "interface.h"
#include "logic.h"
#include "lista.h"

#define BUF_SIZE 1024


int main() {
    srand(time(NULL));
    printf("\n      -----------------------\n\tWelcome to RASTROS!\n      -----------------------");
    ESTADO *e = inicializar_estado();
    printBoard(e);
    while (1) {
        if ((int) interpretador(e) == 2) {
            break;
        }
    }
    return 0;
}

