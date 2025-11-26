#include <stdio.h>
#include <stdlib.h>

int main()
{
float radius, surfaceArea;
const int PI = 3.14;

// Take radius as input
    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);

// Calculate surface area
    surfaceArea = 4 * PI * radius * radius;

// Display result
    printf("Surface Area of the sphere = %.2f\n", surfaceArea);
}
