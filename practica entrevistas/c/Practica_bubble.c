#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void BubleSort(int* list, int size);

int main(){

    int list[] = {2,3,4,10,9,8,7,1,6,5};

    int size = sizeof(list) / sizeof(list[0]);

    BubleSort(list,size);

   for(int i=0; i < size; i++){

    printf("%d, ",list[i]);

    }

    return 0;
}

void BubleSort(int* list, int size){

    int temp = 0;

    for(int i=0; i < size - 1; i++){
        for(int j=0; j < size - i - 1; j++){
            if(list[j] > list[j+1]){
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
            else{
                //do nothing
            }
        }
    }


}