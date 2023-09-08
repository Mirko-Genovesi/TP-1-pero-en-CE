#include <stdio.h>
#include <math.h>


#define REAL 0
#define IMAGINARIO 1
#define MODULO 0
#define FASE 1



void user_input(float binomica[]){
    printf("Introduzca la parte real y la imaginaria:\n");
    scanf("%f", &binomica[REAL]);
    scanf("%f", &binomica[IMAGINARIO]);
}


void binomica_a_polar(float binomica[], float polar[]){
    polar[MODULO] = sqrt(pow(binomica[REAL],2)+pow(binomica[IMAGINARIO],2));
    polar[FASE] = atan2(binomica[IMAGINARIO], binomica[REAL]);
    polar[FASE] = polar[FASE]*180/M_PI;
}


void main(){
    float binomica[2] = {0};
    float polar[2] = {0};

    printf("Bienvenido al programa que calcula el modulo y la fase de un numero binomica\n");
    user_input(binomica);
    binomica_a_polar(binomica, polar);
    printf("El numero en polar es:%fe^J%f°", polar[MODULO], polar[FASE]);
}
