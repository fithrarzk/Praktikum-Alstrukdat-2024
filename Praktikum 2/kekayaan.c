#include <stdio.h>
#include "liststatik.h"

int main (){
    ListStatik l1;
    readList(&l1);
    int i,j;
    i = getLastIdx (l1);
    ELMT (l1,i) += 1;
    while (ELMT (l1,i) == 10){
        ELMT (l1,i) = 0;
        i--;
        ELMT (l1,i) += 1;

    }
    if (ELMT (l1, 0) == 0){
        insertFirst(&l1, 1);
    }

    printf("%d", ELMT (l1, 0));
    for (j=1; j <= listLength(l1)-1;j++){
        printf(" %d", ELMT (l1, j));
    }
    printf ("\n");
}

