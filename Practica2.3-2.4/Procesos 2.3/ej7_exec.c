#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){

  if (argc < 2) {
    printf("ERROR: Introduce el comando.\n");
    return -1;
  }

  //Ejecutamos el comando correspondiente a la entrada por argumentos
  if (execvp(argv[1], argv + 1) == -1) {
    printf("ERROR: No se ha ejecutado correctamente.\n");
  }

  printf("El comando terminó de ejecutarse.\n");


  return 0;
}
/*
La cadena "El comando terminó de ejecutarse" sólo se ejecuta cuando se usa system. 
Esto se debe al ejecutar el comando exec sustituye la imagen del programa a la imagen del programa que hemos pasado por argumentos.

Diferencia entre ps -el y "ps -el"

Cuando se pasa por parámetros de un programa ps -ef equivaldría a dos argumentos y si se quiere ejecutar como systme sería necesario unirlos. 
Mientras que "ps -el" equivale a un único string lo que nos permitiría ejecutar directamente el comando system sin necesidad de unirlos.
*/