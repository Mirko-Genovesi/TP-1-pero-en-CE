#include <stdio.h>
#include <math.h>

#define RESISTIVO 0
#define REACTIVO 1
#define TENSION 0
#define CORRIENTE 1
#define MODULO 0
#define FASE 1


float user_input(float bipol[2][2]){
    float frecuencia;

    printf("\nIntroduzca el módulo y fase de la tension:\n");
    scanf("%f", &bipol[TENSION][MODULO]);
    scanf("%f", &bipol[TENSION][FASE]);

    printf("Introduzca el modulo y fase de la corriente:\n");
    scanf("%f", &bipol[CORRIENTE][MODULO]);
    scanf("%f", &bipol[CORRIENTE][FASE]);

    printf("Introduzca la frecuencia:\n");
    scanf("%f", &frecuencia);
    return frecuencia;
}


void impedancia_calculo(float bipol[2][2], float impedancia[]){
    impedancia[MODULO] = bipol[TENSION][MODULO]/bipol[CORRIENTE][MODULO];
    impedancia[FASE] = bipol[TENSION][FASE]-bipol[CORRIENTE][FASE];
}


void polar_a_binomica(float impedancia[]){
    float mod = impedancia[MODULO];
    float fas = impedancia[FASE];
    impedancia[RESISTIVO] = mod*cos(fas*M_PI/180);
    impedancia[REACTIVO] = mod*sin(fas*M_PI/180);
    printf("Impedancia = %fΩ+J(%f)Ω\n", impedancia[RESISTIVO], impedancia[REACTIVO]);
}


void mostrar_componentes(float impedancia[], float frecuencia){
    if (impedancia[REACTIVO]){
        if (impedancia[REACTIVO] > 0){
            float inductor = impedancia[REACTIVO]/(2*M_PI*frecuencia);

            if ((int)impedancia[RESISTIVO]) printf("Resistor = %fΩ\nInductor = %fH", impedancia[RESISTIVO], inductor);
            else printf("Circuito puramente inductivo, Inductor = %fH", inductor);
        }
        else{
            float capacitor = 1/(impedancia[REACTIVO]*2*M_PI*frecuencia);

            if ((int)impedancia[RESISTIVO]) printf("Resistor = %fΩ\nCapacitor = %fF", impedancia[RESISTIVO], -capacitor);
            else printf("Circuito puramente capacitivo, Capacitor = %FF", -capacitor);
        }
    }
    else{
        if((int)impedancia[RESISTIVO]) printf("Circuito puramente resistivo, R = %fΩ", impedancia[RESISTIVO]);
        else printf("Flaco para que usas este programa si no vas a poner tensiones o corrientes");
    }
        
}


void main(){
    float bipol[2][2] = {0};
    float impedancia[2] = {0};

    printf("Hola bienvenido al programa que ingresada una tensión y corriente\
devuelve el valor de la impedancia y sus componentes");
    float frecuencia = user_input(bipol);
    impedancia_calculo(bipol, impedancia);
    polar_a_binomica(impedancia);
    mostrar_componentes(impedancia, frecuencia);
}
