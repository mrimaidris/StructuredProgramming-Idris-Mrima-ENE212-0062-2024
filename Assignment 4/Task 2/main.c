#include <stdio.h>

int main(){
    int array[] = {2,5,8};
    int sum =0;

    for(int i=0;i<=3;i++){
        sum = sum + array[i-1];
    }
    printf("%d",sum);
}