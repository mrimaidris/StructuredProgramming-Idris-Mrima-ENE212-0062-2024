#include <stdio.h>

int main() {
    int arr[] = {3, 2, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, count;

    printf("The unique elements found in the array are: ");
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == 1) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}