#include <stdio.h>

int main() {
    int array[] = {2,7,4,5,9};
    int n = sizeof(array) / sizeof(array[0]);
    
   for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;j++){
        if(array[j]>array[j+1]){
             int temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;            
        }
    }
   }
   printf("The sorted array is:\n");
   for (int k=0;k<n;k++){
    printf("%d ",array[k]);
   }
    
    return 0;
}