#include <stdio.h>
#include "prioqueue.h"


int main() {
    int n; 
    scanf("%d", &n);
    
    PrioQueue q1;
    PrioQueue q2;
    CreatePrioQueue(&q1);
    CreatePrioQueue(&q2);
    
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        enqueue(&q1, a);
    }

    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        enqueue(&q2, b);
    }

    long long ans = 0;
    while (!isEmpty(q1))
    {
        int a, b;
        dequeue(&q1, &a);
        dequeue(&q2, &b);
        ans += (long long) a* (long long) b;
    }
    

    printf("%lld\n", ans);
}
