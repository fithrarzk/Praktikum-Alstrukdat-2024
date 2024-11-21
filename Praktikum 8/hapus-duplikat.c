#include <stdio.h>
#include "boolean.h"
#include "listlinier.h"

List hapusDuplikat(List l){
    List result;
    CreateList(&result);

    Address current = l;
    while (current != NULL) {
        ElType currentVal = INFO(current);
        Address nextNode = NEXT(current);

        // Cek apakah elemen berikutnya memiliki nilai yang sama (duplikat)
        boolean hasDuplicate = false;
        while (nextNode != NULL && INFO(nextNode) == currentVal) {
            hasDuplicate = true;
            nextNode = NEXT(nextNode);
        }

        // Jika tidak ada duplikat, tambahkan ke result
        if (!hasDuplicate) {
            insertFirst(&result, currentVal);
        }

        // Pindah ke node berikutnya yang tidak duplikat
        current = nextNode;
    }

    return result;
}
/**
 * Menerima masukan sebuah list l yang terurut mengecil
 * Mengembalikan list yang merupakan hasil penghapusan elemen yang mempunyai duplikat pada list l, terurut membesar
 * Contoh: hapusDuplikat(3->3->2->1) = 1->2 (-> adalah panah next pada list linear)
 */
