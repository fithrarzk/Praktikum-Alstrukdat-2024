#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"

#define INF 10000

// Deklarasi global
char arr[100][100];
int res[100][100];
boolean vis[100][100];
int N;
int mv[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
Queue q;
int x, y;

// Fungsi untuk mengambil elemen dari antrean
void get() {
    ElType val;
    dequeue(&q, &val);
    x = val.row;
    y = val.col;
}

// Fungsi untuk memasukkan elemen ke dalam antrean
void push(int i, int j) {
    ElType coor;
    coor.row = i;
    coor.col = j;
    enqueue(&q, coor);
}

// Fungsi untuk mengecek apakah kotak aman untuk dilewati
boolean isSafe(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N && !vis[i][j] && arr[i][j] != '#';
}

// Program utama
int main() {
    int sx, sy; // Koordinat titik awal
    scanf("%d", &N);

    // Inisialisasi grid, visited, dan result
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &arr[i][j]);
            res[i][j] = INF; // Inisialisasi panjang jalur menjadi nilai besar
            vis[i][j] = false;
            if (arr[i][j] == 'A') {
                sx = i;
                sy = j;
            }
        }
    }

    // Inisialisasi BFS
    CreateQueue(&q);
    boolean flag = false; // Penanda apakah jalur ditemukan
    push(sx, sy);
    res[sx][sy] = 0;

    // BFS
    while (!isEmpty(q)) {
        get(); // Ambil elemen dari antrean
        if (arr[x][y] == 'B') { // Jika mencapai titik akhir
            flag = true;
            break;
        }
        vis[x][y] = true; // Tandai sebagai sudah dikunjungi
        for (int i = 0; i < 4; i++) { // Periksa semua arah
            int xx = x + mv[i][0];
            int yy = y + mv[i][1];
            if (isSafe(xx, yy)) {
                push(xx, yy);
                vis[xx][yy] = true; // Tandai sebagai sudah dimasukkan ke antrean
                res[xx][yy] = res[x][y] + 1;
            }
        }
    }

    // Output hasil
    if (flag) {
        printf("Ya\n%d\n", res[x][y]);
    } else {
        printf("Tidak\n");
    }

    return 0;
}
