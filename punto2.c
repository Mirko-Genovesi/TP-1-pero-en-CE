#include <stdio.h>
#include <math.h>


#define REAL 0
#define IMAGINARIO 1
#define MODULO 0
#define FASE 1


void user_input(float polar[]){
    printf("Introduzca el módulo y la fase:\n");
    scanf("%f", &polar[MODULO]);
    scanf("%f", &polar[FASE]);
}


void polar_a_binomica(float polar[], float binomica[]){
    binomica[REAL] = polar[MODULO]*cos(polar[FASE]*M_PI/180);
    binomica[IMAGINARIO] = polar[MODULO]*sin(polar[FASE]*M_PI/180);
}


void main(){
    float binomica[2] = {0};
    float polar[2] = {0};

    printf("Bienvenido al programa que calcula la parte real e imaginaria de un numero complejo en polar\n");
    user_input(polar);
    polar_a_binomica(polar, binomica);
    printf("El numero en binomica es:%f+J(%f)", binomica[REAL], binomica[IMAGINARIO]);
}
