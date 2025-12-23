#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1 = 15;
    int num2 = 25;
    int *ptr1, *ptr2;
    int sum;

    ptr1 = &num1;
    ptr2 = &num2;

    sum = *ptr1 + *ptr2;

    printf("Sum = %d\n", sum);

    return 0;
}
