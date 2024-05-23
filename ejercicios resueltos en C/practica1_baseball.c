//practica 1 micros baseball

//librerias
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//definicion de variables
typedef unsigned char uint_8;
typedef unsigned short uint_16;
typedef unsigned long uint_32;

//prototipo de funcion
uint_8 baseball(uint_8 *jugadas, uint_8 tiempos);


int main()
{
   uint_8 result=0;
   uint_8 tiempos=5;
   uint_8 caracteres[5];			//posibles valores a ingresar: numeros enteros, +(suma los valores anteriores), D(tomas el doble de puntos de lo que tienes)
   caracteres[1] = 5;				//y la C(el valor anterior es invalido)
   caracteres[2] = 2;
   caracteres[3] = 'C';
   caracteres[4] = 'D';
   caracteres[5] = '+';   					
   
   result = baseball(&caracteres[1],tiempos);

   	printf("el resultado es = %d\n",result);
   
   
   return 0;
}

uint_8 baseball(uint_8 *jugadas, uint_8 tiempos)
{
	uint_8 output=0;
	uint_8 memory=0;
	
	while(tiempos--)
	{	
		if(*jugadas == 'C' || *jugadas == 'D' || *jugadas == '+')
		{
			
			switch(*jugadas)
			{
				case 'C':
				
				if(output > 0)
				{	
				output = output - *(jugadas - 1);
				memory = output;
				
				}	
				break;
				case 'D':
				if(output > 0)
				{
				output = output*2 + output;	
				memory = output;
		
				}	
				break;
				case '+':
				if(output > 0)
				{
					
					output = output + memory;  //falta condicion para numeros
				
					
					
				}				
				break;
				default:("holi\n");
			}
			
		}	
		else
		{
	
		
		output = output + *jugadas;	
		
		
	
		
		}
	*jugadas++;	
	}
	
	return output;
}	





				/*	if(*(jugadas-1) != 'D' != '+' != 'C' && *(jugadas-2) != 'D' != 'C' != '+')
					{
						output = output + *(jugadas -1) + *(jugadas -2);	
					
					}
					else
					{	*/