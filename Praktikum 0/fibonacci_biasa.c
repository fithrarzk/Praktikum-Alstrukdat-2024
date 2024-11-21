#include <stdio.h>

int main(){
    int n, a, b, i;
    scanf("%d %d %d", &n, &a, &b);
    int f[20];
    f[0] = a;
    f[1] = b;
    for (i=2 ; i < n; i++){
        f[i] = f[i-1] + f[i-2];

    }
    printf("%d\n", f[n-1]);
    return 0;
}