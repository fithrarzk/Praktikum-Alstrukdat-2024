#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik l1, l2, l3;
    int i, j, k, point, count;
    readList (&l1);
    CreateListStatik (&l2);
    CreateListStatik (&l3);
    for (i = 0; i <= listLength (l1)-1;i++){
        point = 0;
        for (j=0; j<=listLength (l2)-1; j++){
        if (ELMT(l1, i) == ELMT (l2, j)){
            point += 1;
        }
        }
        if (point == 0){
            insertLast(&l2, ELMT(l1, i));
        } 
    }
    printList (l2);
    printf("\n");


    for (i = 0; i <= listLength (l2)-1; i ++){
        count = 0;
        for (j=0;j<=listLength(l1)-1; j++){
            if (ELMT(l2,i) == ELMT (l1,j)){
                count += 1;
            }
        }
        printf("%d %d\n", ELMT(l2,i), count);
    }
}

