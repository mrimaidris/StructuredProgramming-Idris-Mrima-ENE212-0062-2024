#include <stdio.h>
#include <stdlib.h>

int main()
{
      int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

 //Operations
    int sum = num1 + num2;
    int diff = num1 - num2;
    int prod = num1 * num2;
    int div = num1 / num2;
    int mod = num1 % num2;

  //Results
    printf("\nResults:\n");
    printf("Addition: %d\n", sum);
    printf("Subtraction: %d\n", diff);
    printf("Multiplication: %d\n", prod);
    printf("Division: %d\n", div);
    printf("Modulus: %d\n", mod);
    return 0;
}
