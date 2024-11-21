#include <stdio.h>
#include <string.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

int main(){
    int i, n, count = 1;
    scanf ("%d", &n);
    STARTWORD();

    while (!EndWord){
        for (i = 0; i < currentWord.Length; i++){
            if (currentWord.TabWord[i] >= 'A' && currentWord.TabWord[i] <= 'Z'){
               currentWord.TabWord[i] -= n%26;
               if (currentWord.TabWord[i] < 65){
                    currentWord.TabWord[i] += 26;
               }
            }
            else if (currentWord.TabWord[i] >= 'a' && currentWord.TabWord[i] <= 'z'){
                currentWord.TabWord[i] -= n%26;
               if (currentWord.TabWord[i] < 97){
                currentWord.TabWord[i] += 26;
               } 
            }
        }
        int panjangKata = currentWord.Length;
        if (count == 1){
        for (i = 0; i < panjangKata; i++){
            printf("%c", currentWord.TabWord[i]);
        }
        }
        else if (count != 1){
        printf(" ");
        for (i = 0; i < panjangKata; i++){
            printf("%c", currentWord.TabWord[i]);
        }           
        }
    ADVWORD();
    count++;
    }
    printf("\n");
    return 0;
}
