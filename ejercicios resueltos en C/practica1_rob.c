//practica 1 micros robot

//librerias
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//definicion de variables
typedef unsigned char uint_8;
typedef unsigned short uint_16;
typedef unsigned long uint_32;
typedef signed char uint8;


//prototipo de funcion
uint_8 prueba1(uint_8 *apuntador1, uint_8 cantidad);


int main()
{
	uint_8 z;
	uint_8 numero=10;
	uint_8 movimientos[10];		//U=up,D=down,L=left,R=right
	movimientos[1]='U';
	movimientos[2]='D';
	movimientos[3]='L';
	movimientos[4]='R';
	movimientos[5]='U';
	movimientos[6]='D';
	movimientos[7]='L';
	movimientos[8]='R';
	movimientos[9]='U';
	movimientos[10]='D'; 
	
	
	
	z=prueba1(&movimientos[1],numero);
	
	printf("%c\n",z);

	
	
	
 return 0;
}



uint_8 prueba1(uint_8 *apuntador1, uint_8 cantidad)
{
	uint8 x=0; //plano x en 2d
	uint8 y=0; //plano y en 2d
	uint_8 z=0;
	
	
	while(cantidad--)
	{

		if(*apuntador1 == 'U')
		{
			y = y+1;
		}	
		
		if(*apuntador1 == 'D')
		{
			y = y-1;
		}
		if(*apuntador1 == 'L')
		{
			x = x-1;
		}
		if(*apuntador1 == 'R')
		{
			x = x+1;
		}		
		*apuntador1++;
	}
	
	if( x == 0 && y == 0 )
	{
			z = 'T';
	}
	else
	{
			z = 'F';
	}
	
	
	return z;
}	