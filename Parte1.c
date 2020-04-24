#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

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
 
 //Ciclo en el que va a correr la implementacion del automata.
 while(feof(archivoEntrada) == 0) {
        caracter = fgetc(archivoEntrada);

//Aca va todo el codigo que tiene que ver con la evaluacion de las palabras.
 
 }


//Cerramos los archivos.
fclose(archivoEntrada);
fclose(archivoSalida);

    return 0;
}