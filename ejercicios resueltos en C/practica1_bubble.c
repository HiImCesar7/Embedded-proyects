//practica 1 micros bubble

//librerias
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//definicion de variables
typedef unsigned char uint_8;
typedef unsigned short uint_16;
typedef unsigned long uint_32;


//prototipo de funcion
uint_8 bubble(uint_8 *apuntador, uint_8 cant);


int main()
{
	uint_8 valores[10] = {5,3,7,6,9,2,1,10,4,8};
	uint_8 num = 10;
	//uint_8 cant = 10;
	uint_8 cont;
	
	
	bubble(valores,10);
	
	
	
	
	for(cont=0;cont<num;cont++)
	{
		
		printf("%d\n",valores[cont]);
	
	
	}
	
	
	
	

 return 0;
}

//funcion
uint_8 bubble(uint_8 *apuntador, uint_8 cant)
{
	uint_8 proceso1;
	uint_8 proceso2;
	uint_8 memory;
	
	for(proceso1 = 1; proceso1 < cant; proceso1++)
	{
		for(proceso2 = 0; proceso2 < cant - proceso1; proceso2++)
		{
			if(*(apuntador + proceso2) < *(apuntador +(proceso2 + 1)))
			{
				memory = *(apuntador + proceso2);
				*(apuntador + proceso2) = *(apuntador +(proceso2 + 1));
				*(apuntador +(proceso2 + 1)) = memory;
			}
		}	
	}

	return 0;


}







