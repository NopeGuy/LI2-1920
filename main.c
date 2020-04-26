#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "interface.h"
#include "logic.h"

#define BUF_SIZE 1024


int main() {
    srand((unsigned int) time(NULL));
    printf("\n      -----------------------\n\tWelcome to RASTROS!\n      -----------------------");
    ESTADO *e = inicializar_estado();
    printBoard(e);
    while (1) {
        if (interpretador(e) == 2) {
            break;
        }
    }
    return 0;
}

