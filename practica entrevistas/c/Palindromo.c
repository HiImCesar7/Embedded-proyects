#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//palabra palindromo

#define TRUE (1)
#define FALSE (0)


int Palindromo(char* palabra, int size);

int main(){

    char palabra[] = {"reconocer"};
    int size = strlen(palabra);
    int state = FALSE;


    state = Palindromo(palabra,size);

    if(state == TRUE){
        printf("La palabra es palindromo\n");
    }
    else{
        printf("La palabra no es palindromo\n");
    }

    return 0;
}

int Palindromo(char* palabra, int size){

    int state;

    for(int x = 0; x < size / 2; x++)
    {
        if(palabra[x] != palabra[size - x - 1]){
            state = FALSE;
            break;
        }
        else{
            state = TRUE;
        }
    }

    return state;

}