#include <stdio.h>
#include "liststatik.h"

int main () {
    ListStatik l, l1, l2;
    readList(&l);
    int i,j,counter,k, m;

    CreateListStatik(&l1);
    CreateListStatik(&l2);
    for (i = 0; i < listLength(l); i ++){
        counter = 1;
        for (j = i+1; j <listLength(l); j++){
            if (l.contents[i] == l.contents[j]){
                counter += 1;
                deleteAt(&l, &l.contents[j], j);
                j--;
            }
        }
        insertFirst(&l1, l.contents[i]);
        insertFirst(&l2, counter);
    }

    int max=0, scdmax=0, temp = 0;
    for (k = 0; k < listLength(l2); k++){
        if (l2.contents[k] > max){
            scdmax = max;
            max = l2.contents[k];}
        else if (l2.contents[k] > scdmax && l2.contents[k] < max){
            scdmax = l2.contents[k];
        }
    }
    if (scdmax == max || l1.contents[indexOf(l2, scdmax)] == -9999){
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    }
    else{
        int scdmin = 999999; 
        for (i = 0; i < listLength(l2); i++) {
            if (l2.contents[i] == scdmax && l1.contents[i] < scdmin) {
                scdmin = l1.contents[i];
        }
        }
        printf("%d\n", scdmin);
    }
    return 0;
}