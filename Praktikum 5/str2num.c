#include <stdio.h>
#include <string.h>

#include "mesinkarakter.h"
#include "mesinkata.h"

boolean bandingkanKata(Word kata, char teks[]) {
    if (kata.Length != strlen(teks)) {
        return false;
    }
    for (int indeks = 0; indeks < kata.Length; indeks++) {
        if (kata.TabWord[indeks] != teks[indeks]) {
            return false;
        }
    }
    return true;
}

boolean cekAkhirPoin(Word kata) {
    return (kata.TabWord[kata.Length - 1] == '.');
}

int main(void) {
    STARTWORD();

    int val = 0;
    boolean counting = false;
    Word kataNow;

    while (!EndWord) {
        strcpy(kataNow.TabWord, currentWord.TabWord);
        kataNow.Length = currentWord.Length;
        if (cekAkhirPoin(kataNow)) {
            kataNow.Length--;
        }
        if (bandingkanKata(kataNow, "nol")) {
            counting = true;
        } else if (bandingkanKata(kataNow, "satu")) {
            counting = true;
            val += 1;
        } else if (bandingkanKata(kataNow, "dua")) {
            counting = true;
            val += 2;
        } else if (bandingkanKata(kataNow, "tiga")) {
            counting = true;
            val += 3;
        } else if (bandingkanKata(kataNow, "empat")) {
            counting = true;
            val += 4;
        } else if (bandingkanKata(kataNow, "lima")) {
            counting = true;
            val += 5;
        } else if (bandingkanKata(kataNow, "enam")) {
            counting = true;
            val += 6;
        } else if (bandingkanKata(kataNow, "tujuh")) {
            counting = true;
            val += 7;
        } else if (bandingkanKata(kataNow, "delapan")) {
            counting = true;
            val += 8;
        } else if (bandingkanKata(kataNow, "sembilan")) {
            counting = true;
            val += 9;
        } else if (bandingkanKata(kataNow, "sepuluh") || bandingkanKata(kataNow, "belas")) {
            counting = true;
            val += 10;
        } else if (bandingkanKata(kataNow, "sebelas")) {
            counting = true;
            val += 11;
        } else if (bandingkanKata(kataNow, "puluh")) {
            counting = true;
            val += 10 * (val % 10) - (val % 10);
        } else if (bandingkanKata(kataNow, "seratus")) {
            counting = true;
            val += 100;
        } else if (bandingkanKata(kataNow, "ratus")) {
            counting = true;
            val += 100 * (val % 100) - (val % 100);
        } else {
            if (counting) {
                printf("%d ", val);
                val = 0;
                counting = false;
            }
        }

        ADVWORD();
        if (!counting) {
            int panjangKata = kataNow.Length;
            for (int i = 0; i < panjangKata; i++) {
                printf("%c", kataNow.TabWord[i]);
            }
            if (!EndWord) {
                printf(" ");
            }
        }
    }
    if (counting) {
        printf("%d", val);
    }
    
    printf("\n");
    return 0;
}