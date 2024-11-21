#include <stdio.h>
#include "boolean.h"
#include "point.h"
#define _USE_MATH_DEFINES
#include <math.h>


void CreatePoint (POINT * P, float X, float Y){
    Absis (*P) = X;
    Ordinat (*P) = Y;
}
                                             
void BacaPOINT (POINT * P){
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint (P, X, Y);
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)",P.X,P.Y);
}

boolean EQ (POINT P1, POINT P2){
    return (P1.X == P2.X) && (P1.Y == P2.Y);
}

boolean NEQ (POINT P1, POINT P2){
    return !EQ(P1, P2);
}

boolean IsOrigin (POINT P){
    return (P.X == 0) && (P.Y == 0);
}

boolean IsOnSbX (POINT P){
    return P.Y == 0;
}

boolean IsOnSbY (POINT P){
    return P.X == 0;
}

int Kuadran (POINT P){
    if (!(IsOrigin(P)||IsOnSbX(P)||IsOnSbY(P))){
        if (P.X > 0 && P.Y > 0){
            return 1;
        }
        else if (P.X < 0 && P.Y > 0){
            return 2;
        }
        else if (P.X < 0 && P.Y < 0){
            return 3;
        }
        else if (P.X > 0 && P.Y < 0){
            return 4;
        }
}
}
                         
POINT NextX (POINT P){
    P.X += 1;
    return P;
}              

POINT NextY (POINT P){
    P.Y += 1;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    P.X += deltaX;
    P.Y += deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX){
    POINT P2;
    if (SbX == true){
        P2.Y = -P.Y;
        P2.X = P.X;
    }
    else if (SbX == false){
        P2.X = -P.X;
        P2.Y = P.Y;
    }
    return P2;
}

float Jarak0 (POINT P){
    return sqrt(pow(P.X, 2) + pow (P.Y,2));
}

float Panjang (POINT P1, POINT P2){
    return sqrt(pow((P2.X - P1.X), 2) + pow ((P2.Y - P1.Y),2));  
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis (*P) += deltaX;
    Ordinat (*P) += deltaY;
}

void GeserKeSbX (POINT *P){
    Ordinat (*P) = 0;
}

void GeserKeSbY (POINT *P){
    Absis (*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
    if (SbX == true){
        Ordinat (*P) *= (-1);
    }
    else if (SbX == false){
        Absis (*P) *= (-1);
    }
}

void Putar (POINT *P, float Sudut){
    float X, Y;
    X = Absis(*P);
    Y = Ordinat(*P);
    Sudut = -Sudut * M_PI / 180;
    Absis(*P) = X * cos(Sudut) - Y * sin(Sudut);
    Ordinat(*P) = X * sin(Sudut) + Y * cos(Sudut);
}       
void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
    int a, b;
    a = (P2.Y - P1.Y) / (P2.X - P1.X);
    b = P1.Y - P1.X * a ;
    printf("(%d,%d)", a, b);
}
