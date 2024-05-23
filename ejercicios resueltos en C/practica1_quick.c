//pendiente

//practica 1 micros quicksort

//librerias
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//definicion de variables
typedef unsigned char uint_8;
typedef unsigned short uint_16;
typedef unsigned long uint_32;

//prototipo de funcion
void quicksort(uint_8 numeros[10],uint_8 first,uint_8 last);


int main(){
   
   uint_8 cont;
   uint_8 y=10;
   uint_8 numeros[10] = {35,22,66,99,1,4,63,66,32,29};

   quicksort(numeros,0,y-1);

   for(cont=0;cont<y;cont++)
      printf("%d\n",numeros[cont]);

   return 0;
}

void quicksort(uint_8 numeros[10],uint_8 first,uint_8 last)
{
   uint_8 i, j, pivote, temp;

   if(first<last){
      pivote=first;
      i=first;
      j=last;

      while(i<j){
         while(numeros[i]<=numeros[pivote]&&i<last)
            i++;
         while(numeros[j]>numeros[pivote])
            j--;
         if(i<j){
            temp=numeros[i];
            numeros[i]=numeros[j];
            numeros[j]=temp;
         }
      }

      temp=numeros[pivote];
      numeros[pivote]=numeros[j];
      numeros[j]=temp;
      quicksort(numeros,first,j-1);
      quicksort(numeros,j+1,last);

   }
}

