//practica 1 micros set memory

//librerias
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//definicion de variables
typedef unsigned char uint_8;
typedef unsigned short uint_16;
typedef unsigned long uint_32;
typedef signed char uint8;


//prototipo
void copy(uint_8 *apuntador1,uint_8 size, uint_8 clear);

main()
{
	uint_8 x=10;
	uint_8 arreglo1[10];
	uint_8 clear=1;

	copy(&arreglo1[0],10,clear);
	
	while(x--)
	{
	printf("arreglo1=[%d]=%d\n",x,arreglo1[x]);
	}
	
	return 0;
	
}

void copy(uint_8 *apuntador1,uint_8 size, uint_8 clear)
{
	while(size--)
	{
	*apuntador1=clear;
	apuntador1++;
	}
	
	
	
}