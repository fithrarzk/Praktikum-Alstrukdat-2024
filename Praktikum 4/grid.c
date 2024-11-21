#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

#define MOD 1000000007

int main() {
    int N;
    Matrix grid, dp;

    scanf("%d", &N);

    createMatrix(N, N, &grid);
    createMatrix(N, N, &dp);

    readMatrix(&grid, N, N);

    if (ELMT(grid, 0, 0) == 1) {
        printf("0\n");
        return 0;
    }
    ELMT(dp, 0, 0) = 1; 

    
    for (int j = 1; j < N; j++) {
        if (ELMT(grid, 0, j) == 0) {
            ELMT(dp, 0, j) = ELMT(dp, 0, j - 1);
        } else {
            ELMT(dp, 0, j) = 0;
        }
    }


    for (int i = 1; i < N; i++) {
        if (ELMT(grid, i, 0) == 0) {
            ELMT(dp, i, 0) = ELMT(dp, i - 1, 0);
        } else {
            ELMT(dp, i, 0) = 0;
        }
    }

   
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (ELMT(grid, i, j) == 0) {
                ELMT(dp, i, j) = (ELMT(dp, i - 1, j) + ELMT(dp, i, j - 1)) % MOD;
            } else {
                ELMT(dp, i, j) = 0;
            }
        }
    }

   
    printf("%d\n", ELMT(dp, N - 1, N - 1));
    return 0;
}
