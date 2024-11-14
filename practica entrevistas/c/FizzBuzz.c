/*
 * Instrucciones del Programa FizzBuzz:
 *
 * 1. Objetivo: Escribe un programa que imprima los números del 1 al 100.
 *
 * 2. Condiciones:
 *    - Si un número es divisible por 3, imprime "Fizz" en lugar del número.
 *    - Si un número es divisible por 5, imprime "Buzz" en lugar del número.
 *    - Si un número es divisible por ambos 3 y 5, imprime "FizzBuzz".
 *
 * 3. Salida:
 *    - Cada número o palabra ("Fizz", "Buzz" o "FizzBuzz") debe imprimirse en una línea separada.
 */
#include "stdlib.h"
#include "stdio.h"

void FizzBuzz(int numero);

int main(){

    int numero=0;

    scanf("%d",&numero);

    for(int i=1; i <= numero ; i++){
        FizzBuzz(i);
    }
   

    return 0;
}

void FizzBuzz(int numero){

    if (numero % 3 == 0 && numero % 5 == 0) {
            printf("FizzBuzz\n");
        } else if (numero % 3 == 0) {
            printf("Fizz\n");
        } else if (numero % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", numero);
        }
  
  


}