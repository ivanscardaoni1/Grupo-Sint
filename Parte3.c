//La logica esta bien, pero el programa todavia no anda.


#include <stdio.h>
#include <stdlib.h>


//Prototipo de funcion que aplica el automata.
void aplicoAutomata (int [][7], char , int, int, int);


int main(int argc, const char * argv[]) {

//Declaramos e inicializo el automata con 7 estados (hay un estado de palabra invalida).
int automata[7][7] = {{2, 1, 1, 6, 6, 0, 6},{1, 1, 1, 6, 6, 0, 6},{5, 5, 6, 3, 6, 0, 6},{4, 4, 4, 6, 4, 0, 6},{4, 4, 4, 6, 4, 0, 6},{5, 5, 6, 6, 6, 0, 6},{6, 6, 6, 6, 6, 0, 6}};

//abrimos archivo de entrada en modo lectura +.
FILE * archivoEntrada = fopen("entrada.txt","r+");
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

//Procedimiento si ingresa una coma para evaluar la palabra.
if(fgetc(archivoEntrada) == ','){
            if(ultimoEstado == 0 ) {fprintf(archivoSalida, "%s", "No hay palabra ");} else
            if(ultimoEstado == 1)  {fprintf(archivoSalida, "%s", "Constante decimal ");} else
            if(ultimoEstado == 2)  {fprintf(archivoSalida, "%s", "Constante octal = a 0 ");} else
            if(ultimoEstado == 3)  {fprintf(archivoSalida, "%s", "Constante invalida ");} else
            if(ultimoEstado == 4){fprintf(archivoSalida, "%s", "Constante hexadecimal ");} else
            if(ultimoEstado == 5){fprintf(archivoSalida, "%s", "Constante octal ");} else
            if(ultimoEstado == 5){fprintf(archivoSalida, "%s", "Constante hexadecimal");}
            }

//Implementacion de la funcion que aplica el automata.
aplicoAutomata (automata, caracter, ultimoEstado, i, j);



 }


//Cerramos los archivos.
fclose(archivoEntrada);
fclose(archivoSalida);

    return 0;
}

void aplicoAutomata (int M[][7], char a, int b, int i, int j){
    if (a == '0'){j = 0;} else
    if (a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7'){ j = 1;} else
    if (a == '8' || a == '9'){j = 2;} else
    if (a == 'x' || a == 'X'){ j = 3;} else
    if (a == 'a' || a == 'b' || a == 'c' || a == 'd' || a == 'e' || a == 'f' || a == 'A' || a == 'B' || a == 'C' || a == 'D' || a == 'E' || a == 'F'){ j = 4;} else
    if (a == ','){ j = 5;} else
        { j = 6;}
    b = i = M[i][j];
    
    
}