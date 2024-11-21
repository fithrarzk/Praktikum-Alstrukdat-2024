#include <stdio.h>
#include <string.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

boolean EndWord;
Word currentWord, bayangan;

boolean cekAkhirPoin(Word kata) {
    return (kata.TabWord[kata.Length - 1] == '.');
}

int main(){
    STARTWORD();
    Word bayangan;
    int i, j, k, c=1, panjangKata;
    while (!EndWord){
        strcpy(bayangan.TabWord, currentWord.TabWord);
        bayangan.Length = currentWord.Length;
        if (cekAkhirPoin(currentWord)) {
            currentWord.Length--;
        }
            if (c % 2 != 0){
                j = 0;
                k = currentWord.Length-1;
                while (j != currentWord.Length-1 && k != 0){
                    currentWord.TabWord[k] = bayangan.TabWord[j];
                    currentWord.TabWord[j] = bayangan.TabWord[k];
                    j++;
                    k--;
                }
            }
        panjangKata = currentWord.Length;
        if (c == 1){
        for (i = 0; i < panjangKata; i++){
            printf("%c", currentWord.TabWord[i]);
        }
        }
        else if (c != 1){
        printf(" ");
        for (i = 0; i < panjangKata; i++){
            printf("%c", currentWord.TabWord[i]);
        }           
        }
    ADVWORD();
    c++;
    }
    printf("\n");
    return 0;
}