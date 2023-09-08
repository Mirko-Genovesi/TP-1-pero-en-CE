#include <stdio.h>
#include <math.h>


#define REAL 0
#define IMAGINARIO 1
#define MODULO 0
#define FASE 1


void polar_a_binomica(float complejo[]){
    float polar[2] = {0};

    printf("Introduzca el módulo y la fase:\n");
    scanf(" %f", &polar[MODULO]);
    scanf(" %f", &polar[FASE]);

    complejo[REAL] = polar[MODULO]*sin(polar[FASE]*M_PI/180);
    complejo[IMAGINARIO] = polar[MODULO]*cos(polar[FASE]*M_PI/180);
}


void binomica_input(float complejo[]){
    printf("Introduzca la parte real y la imaginaria:\n");
    scanf(" %f", &complejo[REAL]);
    scanf(" %f", &complejo[IMAGINARIO]);
}


void user_decision(float complejo[], int decision){
    if (decision) polar_a_binomica(complejo);

    else binomica_input(complejo);
}



void complejo_tipo(float complejo1[], float complejo2[]){
    int decision = 0;

    printf("\n¿El primer complejo que querés sumar están en binomica(0) o polar?(!0)\n");
    scanf(" %d", &decision);
    user_decision(complejo1, decision);

    printf("El segundo está en binómica(0) o polar(!0)\n");
    scanf(" %d", &decision);
    user_decision(complejo2, decision);

}


void suma_complejos(float complejo1[], float complejo2[], float complejo_sumado[]){
    complejo_sumado[REAL] = complejo1[REAL] + complejo2[REAL];
    complejo_sumado[IMAGINARIO] = complejo1[IMAGINARIO] + complejo2[IMAGINARIO];
}


void binomica_a_polar(float complejo[]){
    float binomica[2] = {0};

    binomica[REAL] = complejo[REAL];
    binomica[IMAGINARIO] = complejo[IMAGINARIO];
    
    complejo[MODULO] = sqrt(pow(binomica[REAL],2)+pow(binomica[IMAGINARIO],2));
    complejo[FASE] = atan2(binomica[IMAGINARIO], binomica[REAL]);
    complejo[FASE] = complejo[FASE]*180/M_PI;
}


void resultados(float complejo[]){
    int decision = 0;

    printf("Quiere ver el resultado en binomica(0) o polar(!0)\n");
    scanf(" %d", &decision);
    if (decision){
        binomica_a_polar(complejo);
        printf("%fe^J%f°", complejo[MODULO], complejo[FASE]);
    } 
    else printf("%f+J(%f)", complejo[REAL], complejo[IMAGINARIO]);
}


void main(){
    float complejo1[2] = {0};
    float complejo2[2] = {0};
    float complejo_sumado[2] = {0};

    printf("Bienvenido a la mejor calculdora y tal");
    complejo_tipo(complejo1, complejo2);
    suma_complejos(complejo1, complejo2, complejo_sumado);
    resultados(complejo_sumado);
}
