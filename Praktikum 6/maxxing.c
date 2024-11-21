# include <stdio.h>
# include "stack.h"

#define MXN 10007
int praj[MXN];
int mms[MXN];
int ki[MXN], ka[MXN];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &praj[i]);
        ki[i] = i;
        ka[i] = i;
        mms[i] = 0;
    }
    mms[n] = 0;

    for (int i = 0; i < n; i++) {
        while (ki[i] > 0 && praj[ki[i] - 1] >= praj[i]) {
            ki[i] = ki[ki[i] - 1];
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        while (ka[i] < n - 1 && praj[ka[i] + 1] >= praj[i]) {
            ka[i] = ka[ka[i] + 1];
        }
    }

    for (int i = 0; i < n; i++) {
        int groupSize = ka[i] - ki[i] + 1;
        if (praj[i] > mms[groupSize]) {
            mms[groupSize] = praj[i];
        }
    }

    for (int size = n - 1; size >= 1; size--) {
        if (mms[size + 1] > mms[size]) {
            mms[size] = mms[size + 1];
        }
    }

    for (int size = 1; size <= n; size++) {
        printf("%d", mms[size]);
        if (size < n) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}