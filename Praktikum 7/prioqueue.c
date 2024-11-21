#include "prioqueue.h"
#include <stdio.h>

void CreatePrioQueue(PrioQueue *pq){
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

/* ********* Prototype ********* */
boolean isEmpty(PrioQueue pq){
        return IDX_HEAD(pq) == IDX_UNDEF;

}
/* Mengirim true jika pq kosong: lihat definisi di atas */
boolean isFull(PrioQueue pq){
    return (IDX_TAIL(pq) + 1) % CAPACITY == IDX_HEAD(pq);
}
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(PrioQueue pq){
    if(isEmpty(pq)){
        return 0;
    }
    else{
        return (IDX_TAIL(pq) - IDX_HEAD(pq) + CAPACITY) % CAPACITY + 1;
    }
}
/* Mengirimkan banyaknya elemen prioqueue. Mengirimkan 0 jika pq kosong. */

void sort(PrioQueue *q){
    int i = IDX_HEAD(*q);
    int n = IDX_TAIL(*q);
    int cap = CAPACITY;
 
    while(i != n){
        int j = i + 1; 
        j %= cap;
        while (j != n){
            if(q->buffer[j] > q->buffer[i]){
                int tmp = q->buffer[j];
                q->buffer[j] = q->buffer[i];
                q->buffer[i] = tmp;
            }
            j++;
            j %= cap;
        }
        if(q->buffer[j] > q->buffer[i]){
                int tmp = q->buffer[j];
                q->buffer[j] = q->buffer[i];
                q->buffer[i] = tmp;
        }
        i++;
        i %= cap;
    }
    
   
}

/* *** Primitif Add/Delete *** */
void enqueue(PrioQueue *pq, ElType val){
    if(isEmpty(*pq)){
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
    }
    else{
        IDX_TAIL(*pq) = (IDX_TAIL(*pq) + 1) % CAPACITY;
    }
    TAIL(*pq) = val;
    sort(pq);
}
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val disisipkan pada posisi yang sesuai, IDX_TAIL "mundur" dalam buffer melingkar.,
        pq terurut mengecil */

void dequeue(PrioQueue *pq, ElType *val){
    *val = HEAD(*pq);
    if(IDX_HEAD(*pq) == IDX_TAIL(*pq)){
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*pq) = (IDX_HEAD(*pq) + 1) % CAPACITY;
    }
}
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        pq mungkin kosong */

/* *** Display Queue *** */
void displayPrioQueue(PrioQueue pq){
    if(isEmpty(pq)){
        printf("[]\n");
    }
    else{
        printf("[");
        int val;
        do{
            // use dequeue
            dequeue(&pq, &val);
            printf("%d", val);
            if(!isEmpty(pq)){
                printf(",");
            }
        }while(!isEmpty(pq));
        printf("]\n");
    }
}
