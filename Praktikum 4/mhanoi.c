#include <stdio.h>
#include <stdbool.h>

void rotate_2x2(int matrix[2][2], int rotations[4][2][2]) {
    // Rotasi 0 derajat
    rotations[0][0][0] = matrix[0][0];
    rotations[0][0][1] = matrix[0][1];
    rotations[0][1][0] = matrix[1][0];
    rotations[0][1][1] = matrix[1][1];
    // Rotasi 90 derajat
    rotations[1][0][0] = matrix[1][0];
    rotations[1][0][1] = matrix[0][0];
    rotations[1][1][0] = matrix[1][1];
    rotations[1][1][1] = matrix[0][1];
    // Rotasi 180 derajat
    rotations[2][0][0] = matrix[1][1];
    rotations[2][0][1] = matrix[1][0];
    rotations[2][1][0] = matrix[0][1];
    rotations[2][1][1] = matrix[0][0];
    // Rotasi 270 derajat
    rotations[3][0][0] = matrix[0][1];
    rotations[3][0][1] = matrix[1][1];
    rotations[3][1][0] = matrix[0][0];
    rotations[3][1][1] = matrix[1][0];
}

bool can_place(int board[100][100], int piece[2][2], int row, int col) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (piece[i][j] >= board[row + i][col + j]) {
                return false;
            }
        }
    }
    return true;
}

int count_valid_positions(int board[100][100], int piece[2][2], int N) {
    int rotations[4][2][2];
    rotate_2x2(piece, rotations);
    int valid_count = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            for (int r = 0; r < 4; r++) {
                if (can_place(board, rotations[r], i, j)) {
                    valid_count++;
                    break;
                }
            }
        }
    }
    return valid_count;
}

int main() {
    int N;
    int board[100][100];
    int piece[2][2];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &piece[i][j]);
        }
    }

    int result = count_valid_positions(board, piece, N);

    printf("%d\n", result);
    return 0;
}
