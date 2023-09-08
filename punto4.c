#include <stdio.h>
#include <math.h>

#define RESISTIVO 0
#define REACTIVO 1


float user_input(float impedancia[]){
    float frecuencia;
    printf("Introduzca la parte resistiva, la reactiva y la frecuencia:\n");
    scanf("%f", &impedancia[RESISTIVO]);
    scanf("%f", &impedancia[REACTIVO]);
    scanf("%f", &frecuencia);

    return frecuencia;
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
        else printf("Flaco para que usas este programa si no vas a poner valores resistivos ni reactivos");
    }
        
}


void main(){
    float impedancia[2] = {0};

    printf("Hola te digo valores de componentes y esas cosas\n");
    float frecuencia = user_input(impedancia);
    mostrar_componentes(impedancia, frecuencia);
}
