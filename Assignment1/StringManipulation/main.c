#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
 char InputStr[100];


    printf("Enter a string: ");
    scanf("%99s", InputStr);
    int StrLength = strlen(InputStr);

// Display the string
    printf("You entered: %s\n", InputStr);

// Find and display its length
  printf("Length of the string: %d\n", StrLength);
    return 0;
}
