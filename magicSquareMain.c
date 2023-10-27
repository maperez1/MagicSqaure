//gcc magicSquare.c magicSquareMain.c 
#include "magicSquare.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0));                         // seed
    int count = 1;                          // count squares
    bool check = false;                     // check for magic square

    while (!check){
        int square[3][3];                   // allocate
        generateRandomSquare(square);       // init
        printf("\n");
        printf("Square %d:", count);
        printf("\n");
        printSquare(square);
        check = isMagicSquare(square);
        if (check)
            printf("The matrix is a magic square!");
        else
            printf("The matrix is NOT a magic square!");
        printf("\n");
        count++;
    }

    return 0;
}