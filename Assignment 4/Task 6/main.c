#include <stdio.h>

int main(){
    int unsortedArray[] = {1,8,7,20};
    int index;
    int newValue;
    int newArray[5];

    printf("Enter Index :");
    scanf("%d", &index);
    printf("\nEnter New Value :");
    scanf("%d", &newValue);

    for(int i=0, j=0; i<5; i++){
        if(i == index){
            newArray[i] = newValue;
        } else {
            newArray[i] = unsortedArray[j];
            j++;
        }
    }

    printf("The new array is:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", newArray[i]);
    }
    printf("\n");
}