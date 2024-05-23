//practica 1 micros memory copy function

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
void copy(uint_8 *apuntador1,uint_8 *apuntador2,uint_8 size);

main()
{
	uint_8 y=10;
	uint_8 x=10;
	uint_8 arreglo1[10];
	uint_8 arreglo2[10];
	while(x--)
	{
	arreglo1[x]=x;
	//printf("arreglo1=[%d]=%d\n",x,arreglo1[x]);
	}
	while(y--)
	{
	arreglo2[y]=5;
	//printf("arreglo2=[%d]=%d\n",y,arreglo2[y]);
	}
	
	copy(&arreglo1[0],&arreglo2[0],10);
	
	y=10;
	
	while(y--)
	{
	printf("arreglo2=[%d]=%d\n",y,arreglo2[y]);
	}
	
	
	
	return 0;
	
}

void copy(uint_8 *apuntador1,uint_8 *apuntador2,uint_8 size)
{
	while(size--)
	{
	*apuntador2=*apuntador1;
	apuntador1++;
	apuntador2++;
	}
	
	
	
