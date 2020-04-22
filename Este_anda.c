//
//  main.c
//  TP N1 SSL
//
//  Created by Ivan Scardaoni on 20/04/2020.
//  Copyright © 2020 Ivan Scardaoni. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//protoripo de intento de funcion (no anda) void aplicoAutomata (int [7][7], char , int, int);
void evalua_palabra(FILE *, char, int);
int main(int argc, const char * argv[]) {
   
   int automata[7][7] = {{2, 1, 1, 6, 6, 0, 6},{1, 1, 1, 6, 6, 0, 6},{5, 5, 6, 3, 6, 0, 6},{4, 4, 4, 6, 4, 0, 6},{4, 4, 4, 6, 4, 0, 6},{5, 5, 6, 6, 6, 0, 6},{6, 6, 6, 6, 6, 0, 6}};

    FILE * archivoEntrada = fopen("entrada.txt","rb+");
    FILE * archivoSalida = fopen("salida.txt","w");
    
   if(archivoEntrada == NULL){
        perror("Error en la apertura del archivo");
        return 1;
    }
    
    char caracter;
   int ultimoEstado = 0;
   int i = 0;
   int j = 0;

    while(!feof(archivoEntrada)) {
        caracter = fgetc(archivoEntrada);
        
        evalua_palabra(archivoSalida, caracter, ultimoEstado);
        
 
        
        if (caracter == '0'){j = 0;} else
            if (caracter == '1' || caracter == '2' || caracter == '3' || caracter == '4' || caracter == '5' || caracter == '6' || caracter == '7'){ j = 1;} else
            if (caracter == '8' || caracter == '9'){j = 2;} else
            if (caracter == 'x' || caracter == 'X'){ j = 3;} else
            if (caracter == 'a' || caracter == 'b' || caracter == 'c' || caracter == 'd' || caracter == 'e' || caracter == 'f' || caracter == 'A' || caracter == 'B' || caracter == 'C' || caracter == 'D' || caracter == 'E' || caracter == 'F'){ j = 4;} else
            if (caracter == ','){ j = 5;} else
                            { j = 6;}
            i = automata[i][j];
            ultimoEstado = i;
    // intento de funcion(no anda) [aplicoAutomata (automata, caracter, ultimoEstado, i);]
            }
    //evaluo la ultima palabra
    
    
    fclose(archivoEntrada);
    fclose(archivoSalida);
    
    
    
    return 0;
            }










void evalua_palabra(FILE * archivoSalida, char caracter, int ultimoEstado){

if(caracter == ','||caracter==EOF){
    if(ultimoEstado == 0) {fprintf(archivoSalida, "%s", "- No hay palabra \n");} else
    if(ultimoEstado == 1) {fprintf(archivoSalida, "%s", "- Constante decimal \n");} else
    if(ultimoEstado == 2) {fprintf(archivoSalida, "%s", "- Constante octal = a 0 \n");} else
    if(ultimoEstado == 3) {fprintf(archivoSalida, "%s", "- Constante invalida \n");} else
    if(ultimoEstado == 4) {fprintf(archivoSalida, "%s", "- Constante hexadecimal \n");} else
    if(ultimoEstado == 5) {fprintf(archivoSalida, "%s", "- Constante octal \n");} else
    if(ultimoEstado == 6) {fprintf(archivoSalida, "%s", "- Constante invalida \n");}
}

}














//desarrollo de intento de funcion(no anda)
/* void aplicoAutomata (int automata[7][7], char caracter, int ultimoEstado, int i){
    int j = 0;
    if (caracter == '0'){j = 0;} else
    if (caracter == '1' || caracter == '2' || caracter == '3' || caracter == '4' || caracter == '5' || caracter == '6' || caracter == '7'){ j = 1;} else
    if (caracter == '8' || caracter == '9'){j = 2;} else
    if (caracter == 'x' || caracter == 'X'){ j = 3;} else
    if (caracter == 'a' || caracter == 'b' || caracter == 'c' || caracter == 'd' || caracter == 'e' || caracter == 'f' || caracter == 'A' || caracter == 'B' || caracter == 'C' || caracter == 'D' || caracter == 'E' || caracter == 'F'){ j = 4;} else
    if (caracter == ','){ j = 5;} else
        { j = 6;}
    i = automata[i][j];
    ultimoEstado = i;
}
*/
