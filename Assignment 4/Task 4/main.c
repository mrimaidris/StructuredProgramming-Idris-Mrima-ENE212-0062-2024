#include <stdio.h>

int main(){

    int array[] = {45,25,21};
    int min = array[0];
    int max = array[0];

    for(int i=0;i<=3;i++){
        if(array[i-1] > max){
            max = array[i];
        }
        if(array[i-1] < min){
            min = array[i];
        }
    }
    printf("Min: %d \n Max: %d",min,max);
    return 0;
}