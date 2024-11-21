#include <stdio.h>
#include <math.h>
#include "point.h"
#include "circle.h"
#include "boolean.h"

boolean IsCIRCLEValid(float X, float Y, float R) {
    return R > 0;
}

void CreateCIRCLE(CIRCLE *C, float X, float Y, float R) {
    CreatePoint(&Center(*C), X, Y);
    Radius(*C) = R;
}

void ReadCIRCLE(CIRCLE *C) {
    float X, Y, R;
    do {
        scanf("%f %f %f", &X, &Y, &R);
        if (!IsCIRCLEValid(X, Y, R)) {
            printf("CIRCLE tidak valid\n");
        }
    } while (!IsCIRCLEValid(X, Y, R));
    CreateCIRCLE(C, X, Y, R);
}

void WriteCIRCLE(CIRCLE C) {
    printf("P(%.2f,%.2f) r=%.2f", Absis(Center(C)), Ordinat(Center(C)), Radius(C));
}

float Circumference(CIRCLE C) {
    return 2 * 3.14 * Radius(C);
}

float Area(CIRCLE C) {
    return 3.14 * Radius(C) * Radius(C);
}

boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P) {
    return Panjang(Center(C), P) < Radius(C);
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P) {
    float dist = Panjang(Center(C), P);
    return fabs(dist - Radius(C)) < 1e-5; 
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2) {
    float d = Panjang(Center(C1), Center(C2));
    return d + Radius(C1) < Radius(C2) || d + Radius(C2) < Radius(C1);
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2) {
    float d = Panjang(Center(C1), Center(C2));
    float r_sum = Radius(C1) + Radius(C2);
    float r_diff = fabs(Radius(C1) - Radius(C2));
    return fabs(d - r_sum) < 1e-5 || fabs(d - r_diff) < 1e-5;
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2) {
    float d = Panjang(Center(C1), Center(C2));
    float r_sum = Radius(C1) + Radius(C2);
    float r_diff = fabs(Radius(C1) - Radius(C2));
    return d < r_sum && d > r_diff;
}