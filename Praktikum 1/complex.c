#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "complex.h"

boolean IsCOMPLEXValid(float Re, float Im){
    return true;
}

void CreateComplex(COMPLEX *C, float Re, float Im){
    Real(*C) = Re;
    Imag(*C) = Im;
}

void BacaCOMPLEX(COMPLEX *C){
    float Re, Im;
    scanf("%f %f", &Re, &Im);
    CreateComplex (C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C){
    if (C.Im >= 0){
        printf("%.2f+%.2fi\n", C.Re, C.Im);
    }
    else {
        printf("%.2f-%.2fi\n", C.Re, C.Im*(-1));
    }
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX Add;
    Add.Re = C1.Re + C2.Re;
    Add.Im =  C1.Im + C2.Im;
    return Add;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX Sub;
    Sub.Re = C1.Re - C2.Re;
    Sub.Im =  C1.Im - C2.Im;
    return Sub;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX Multi;
    Multi.Re = (C1.Re * C2.Re - C1.Im * C2.Im);
    Multi.Im = (C1.Re * C2.Im + C1.Im * C2.Re);
    return Multi;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX Divide;
    if (pow (C2.Re, 2) + pow (C2.Im, 2) == 0){
        Divide.Re = 0;
        Divide.Im = 0;
    }
    else {
        Divide.Re = (C1.Re * C2.Re + C1.Im * C2.Im) / (pow (C2.Re, 2) + pow (C2.Im, 2));
        Divide.Im = (C1.Im * C2.Re - C1.Re * C2.Im) / (pow (C2.Re, 2) + pow (C2.Im, 2)); 
    }
    return Divide;
}

float AbsCOMPLEX(COMPLEX C){
    return sqrt(pow (C.Re, 2) + pow (C.Im, 2));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C){
    COMPLEX result;
    result.Re = C.Re;
    result.Im = -C.Im;
    return result;
}

boolean CEQ(COMPLEX C1, COMPLEX C2){
    if (C1.Re ==  C2.Re && C1.Im == C2.Im){
        return true;
    }
    else {
        return false;
    }
}

boolean CNEQ(COMPLEX C1, COMPLEX C2){
    if (C1.Re !=  C2.Re && C1.Im != C2.Im){
        return true;
    }
    else {
        return false;
    }
}
