#include <stdio.h>
#include <stdlib.h>


int main() {
    int num = 1234;      // Declare and initialize integer variable
    int *ptr;          // Declare integer pointer

    ptr = &num;        // Store address of num in ptr

    printf("Value in num: %d\n", num);
    printf("Value stored in ptr: %p\n", (void *)ptr);
    printf("Address of password: %p\n", (void *)&num);
    printf("Value accessed using *ptr: %d\n", *ptr);

    return 0;
}
