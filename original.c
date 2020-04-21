//
//  main.c
//  TP N1 SSL
//
//  Created by Ivan Scardaoni on 20/04/2020.
//  Copyright © 2020 Ivan Scardaoni. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void aplicoAutomata (int [][7], char , int);



int main(int argc, const char * argv[]) {
   int automata[7][7] = {{2, 1, 1, 6, 6, 0, 6},{1, 1, 1, 6, 6, 0, 6},{5, 5, 6, 3, 6, 0, 6},{4, 4, 4, 6, 4, 0, 6},{4, 4, 4, 6, 4, 0, 6},{5, 5, 6, 6, 6, 0, 6},{6, 6, 6, 6, 6, 0, 6}};
   
    FILE * archivoEntrada = fopen("entrada.txt","r+");
    FILE * archivoSalida = fopen("salida.txt","w+");
    
   if(archivoEntrada == NULL){
        perror("Error en la apertura del archivo");
        return 1;
    }
    
    char caracter;
   int ultimoEstado = 0;
    
    while(feof(archivoEntrada) == 0) {
        caracter = fgetc(archivoEntrada);
        //printf("%c",caracter);
        
        if(caracter == ',' && ultimoEstado == 0 ){fprintf(archivoSalida, "%s", "No hay palabra ");} else
        if(caracter == ',' && ultimoEstado == 1){fprintf(archivoSalida, "%s", "Constante decimal ");} else
        if(caracter == ',' && ultimoEstado == 2){fprintf(archivoSalida, "%s", "Constante octal = a 0 ");} else
        if(caracter == ',' && ultimoEstado == 3){fprintf(archivoSalida, "%s", "Constante invalida ");} else
        if(caracter == ',' && ultimoEstado == 4){fprintf(archivoSalida, "%s", "Constante hexadecimal ");} else
        if(caracter == ',' && ultimoEstado == 5){fprintf(archivoSalida, "%s", "Constante octal ");} else
        if(caracter == ',' && ultimoEstado == 6){fprintf(archivoSalida, "%s", "Constante invalida");}
        
    
     ultimoEstado = aplicoAutomata (automata, caracter, ultimoEstado);

            }
    fclose(archivoEntrada);
    fclose(archivoSalida);
    
    return 0;
            }

int aplicoAutomata (int M[][7], char a, int b){
    int i = 0;
    int j = 0;
    if (a == '0'){j = 0;} else
    if (a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7'){ j = 1;} else
    if (a == '8' || a == '9'){j = 2;} else
    if (a == 'x' || a == 'X'){ j = 3;} else
    if (a == 'a' || a == 'b' || a == 'c' || a == 'd' || a == 'e' || a == 'f' || a == 'A' || a == 'B' || a == 'C' || a == 'D' || a == 'E' || a == 'F'){ j = 4;} else
    if (a == ','){ j = 5;} else
        { j = 6;}
    b = i = M[i][j];
    return b;
}
