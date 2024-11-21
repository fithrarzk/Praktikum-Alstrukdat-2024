# include <stdio.h>
# include "rotating_point.h"
# include <math.h>


COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
    COMPLEX result;
    result.Re = 1.0; 
    result.Im = 0.0;

    for (int i = 0; i < p; i++) {
        COMPLEX temp; 
        temp.Re = result.Re * C.Re - result.Im * C.Im;
        temp.Im = result.Re * C.Im + result.Im * C.Re;
        result = temp;
    }

    return result;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n){
    if (n == 0) {
        printf("Titik keluar dari lingkaran pada iterasi ke 0");
        return;
    }
    
    for (int i = 1; i <=n; i++){
        COMPLEX pC = PowerCOMPLEX(C,i);
        float newX = Absis(*P)*pC.Re - Ordinat(*P)*pC.Im;
        float newY = Absis(*P)*pC.Im + Ordinat(*P)*pC.Re;
        Absis(*P) = newX;
        Ordinat(*P) = newY;
        if (Absis(*P)*Absis(*P) + Ordinat(*P)*Ordinat(*P) > 1){
            printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
            return;
        }
    }
    printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
}