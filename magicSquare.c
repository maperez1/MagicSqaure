#include "magicSquare.h"
#include <stdlib.h>
#include <stdio.h>

void shuffle(int *arr, int size) {
    for(int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);  // get random index
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void generateRandomSquare(int square[3][3]) {
    // array with numbers 1 to 9
    int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(numbers, 9);

    // populate array with shuffled numbers
    int index = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            square[i][j] = numbers[index];
            index++;
        }
    }
}

void printSquare(int square[3][3]) {
    for(int i = 0; i < 3; i++) {
        printf("[");
        for(int j = 0; j < 3; j++) {
            if (j == 2)
                printf("%d", square[i][j]);
            else
                printf("%d ", square[i][j]);

        }
        printf("]");
        printf("\n");
    }
}

bool isMagicSquare(int arr[3][3]) {
    int ans[8];          // calculations container

//              Test array
//    int arr[3][3] = {   {4, 9, 2},
//                        {3, 5, 7},
//                        {8, 1, 6} };

    // Calculate sum of all rows
    ans[0] = arr[0][0] + arr[0][1] + arr[0][2];
    ans[1] = arr[1][0] + arr[1][1] + arr[1][2];
    ans[2] = arr[2][0] + arr[2][1] + arr[2][2];

    // Calculate sum of all columns
    ans[3] = arr[0][0] + arr[1][0] + arr[2][0];
    ans[4] = arr[0][1] + arr[1][1] + arr[2][1];
    ans[5] = arr[0][2] + arr[1][2] + arr[2][2];

    // Calculate sum of diagonal
    ans[6] = arr[0][0] + arr[1][1] + arr[2][2];
    ans[7] = arr[2][0] + arr[1][1] + arr[0][2];

    bool flag = true;
    for (int i = 0; i < 8; i++) {
        if (ans[i] != 15)
            flag = false;
    }
    return flag;
}
