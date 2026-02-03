#include <stdio.h>

#define BUFFER_SIZE 10

//global
int buffer[BUFFER_SIZE];
int head = 0;      
int count = 0;

void insertSample(int value) {
    buffer[head] = value;
    head = (head + 1) % BUFFER_SIZE; 
    
    if (count < BUFFER_SIZE) {
        count++; 
    }
}

void printSamples() {
    if (count == 0) {
        printf("Buffer  empty.\n");
        return;
    }
    
    printf("Stored samples (oldest -> newest): ");
    
    //starting position
    int start;
    if (count < BUFFER_SIZE) {
        start = 0;  
    } else {
        start = head;  
    }
    
    
    for (int i = 0; i < count; i++) {
        int index = (start + i) % BUFFER_SIZE;
        printf("%d ", buffer[index]);
    }
    printf("\n");
}


void printStatus() {
    printf("Buffer status: %d/%d slots used\n", count, BUFFER_SIZE);
}

int main() {
    int choice, value;
    
    printf("=== Circular Data Logger ===\n");
    printf("Buffer size: %d\n\n", BUFFER_SIZE);
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert sensor reading\n");
        printf("2. Print all samples\n");
        printf("3. Show buffer status\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter sensor value: ");
                scanf("%d", &value);
                insertSample(value);
                printf("Value %d inserted.\n", value);
                break;
                
            case 2:
                printSamples();
                break;
                
            case 3:
                printStatus();
                break;
                
            case 4:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}