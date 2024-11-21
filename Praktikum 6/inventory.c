#include <stdio.h>
#include "stack.h"
#include "boolean.h"

boolean isOpp(char n) {
    return (n == 'A' || n == '+' || n == 'S' || n == 'X');
}

int main() {
    Stack S, S2;
    infotype val, val1, val2, temp, val3, x2;
    int n, total = 0, i, a;
    char x;
    CreateEmpty(&S);
    CreateEmpty(&S2);

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf(" %c", &x);
        if (!isOpp(x)) {
            x2 = x - '0'; 
            Push(&S, x2);
        } else if (x == '+') {
            Pop(&S, &val2);
            Pop(&S, &val1);
            temp = val1 + val2;
            Push(&S, val1);
            Push(&S, val2);
            Push(&S, temp);
        } else if (x == 'X') {
            Pop(&S, &val3); 
        } else if (x == 'S') {
            temp = 0;
            while (!IsEmpty(S)) {
                Pop(&S, &val1);
                temp += val1;
            }
            Push(&S, temp);
        } else if (x == 'A') {
            temp = 0;
            a = 0; 
            while (!IsEmpty(S)) {
                Pop(&S, &val);
                temp += val;
                a += 1;
            }
            if (a > 0) {
                temp = temp / a; 
            }
            Push(&S, temp);
        }
    }

    total = 0;
    while (!IsEmpty(S)) {
        Pop(&S, &val);
        total += val;
    }
    printf("%d\n", total);
    return 0;
}
