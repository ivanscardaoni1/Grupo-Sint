#include <stdio.h>
#include <stdlib.h>


//Prototipo de funcion que aplica el automata.(la comentamos porque no anda)
//void aplicoAutomata (int [][7], char , int, int, int);

//Prototipo funcion en la que entra una coma y evalua la palabra.
void evalua_palabra(FILE *, char, int);


int main(int argc, const char * argv[]) {

//Declaramos e inicializo el automata con 7 estados (hay un estado de palabra invalida).
int automata[7][7] = {{2, 1, 1, 6, 6, 0, 6},{1, 1, 1, 6, 6, 0, 6},{5, 5, 6, 3, 6, 0, 6},{4, 4, 4, 6, 4, 0, 6},{4, 4, 4, 6, 4, 0, 6},{5, 5, 6, 6, 6, 0, 6},{6, 6, 6, 6, 6, 0, 6}};

//abrimos archivo de entrada en modo lectura +.
FILE * archivoEntrada = fopen("entrada.txt","rb+");
//abrimos archivo de salida en modo escritura +.
FILE * archivoSalida = fopen("salida.txt","w+");
    
//Mensaje que denota un error en la apertura de un archivo.    
if(archivoEntrada == NULL){
        perror("Error en la apertura del archivo");
        return 1;
    }
 
 //Variable que almacena cada caracter leido.
 char caracter;
 //variable que almacena el ultimo estado.
 int ultimoEstado;
 //variables que almacenan las posiciones en la tabla de transiciones.
int i = 0;
int j = 0;

 //Ciclo en el que va a correr la implementacion del automata.
 while(feof(archivoEntrada) == 0) {
        caracter = fgetc(archivoEntrada);

//Funcion si ingresa una coma para evaluar la palabra.
evalua_palabra(archivoSalida, caracter, ultimoEstado);

//Construimos la funcion directamente en el main, ahora anda aunque este mas desprolijo.
if (caracter == '0'){j = 0;} else
            if (caracter == '1' || caracter == '2' || caracter == '3' || caracter == '4' || caracter == '5' || caracter == '6' || caracter == '7'){ j = 1;} else
            if (caracter == '8' || caracter == '9'){j = 2;} else
            if (caracter == 'x' || caracter == 'X'){ j = 3;} else
            if (caracter == 'a' || caracter == 'b' || caracter == 'c' || caracter == 'd' || caracter == 'e' || caracter == 'f' || caracter == 'A' || caracter == 'B' || caracter == 'C' || caracter == 'D' || caracter == 'E' || caracter == 'F'){ j = 4;} else
            if (caracter == ','){ j = 5;} else
                            { j = 6;}
            i = automata[i][j];
            ultimoEstado = i;

//Implementacion de la funcion que aplica el automata. (la comentamos porque no anda)
//aplicoAutomata (automata, caracter, ultimoEstado, i, j);



 }


//Cerramos los archivos.
fclose(archivoEntrada);
fclose(archivoSalida);

    return 0;
}

//mejoramos funcion entraUnaComa.
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








/*
void aplicoAutomata (int M[][7], char a, int b, int i, int j){
    if (a == '0'){j = 0;} else
    if (a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7'){ j = 1;} else
    if (a == '8' || a == '9'){j = 2;} else
    if (a == 'x' || a == 'X'){ j = 3;} else
    if (a == 'a' || a == 'b' || a == 'c' || a == 'd' || a == 'e' || a == 'f' || a == 'A' || a == 'B' || a == 'C' || a == 'D' || a == 'E' || a == 'F'){ j = 4;} else
    if (a == ','){ j = 5;} else
        { j = 6;}
    b = i = M[i][j];
    
    
} */