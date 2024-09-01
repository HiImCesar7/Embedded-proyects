#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void BubleSort(int* palabra, int size);

int main(){

    int palabra[] = {30,20,10,50,100,70,90,80,60,50};

    int size = sizeof(palabra) / sizeof(palabra[0]);

    BubleSort(palabra,size);

    for(int x = 0; x < size; x++){
        printf("%d ",palabra[x]);
    }

return 0;
}

void BubleSort(int* palabra, int size){

    int temp = 0;

    for(int x=0; x < size - 1;x++){
        for(int y=0; y < size - x - 1; y++){
            if(palabra[y] > palabra[y + 1]){
                temp = palabra[y];
                palabra[y] = palabra[y + 1];
                palabra[y + 1] = temp;
            }


        }
    }


}