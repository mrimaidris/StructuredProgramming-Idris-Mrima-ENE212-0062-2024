#include <stdio.h>
#include <string.h>

int currentBalance = 0;

/*=== Withdrawal ===*/
int withdraw(int amount) {
    if (amount <= 0) {
        printf("\nInvalid amount! Withdrawal must be positive.\n");
        return 0;
    }

    if (currentBalance < amount) {
        printf("\nTransaction Failed: Insufficient funds in your account %d.\n", amount);
        printf("Current Balance: %d\n", currentBalance);
        return 0;
    }

    currentBalance -= amount;
    printf("\nSuccessful Withdrawal of %d.\n", amount);
    printf("New Balance: %d\n", currentBalance);
    return 1;
}

/*=== Deposit ===*/
void deposit(int amount) {
    if (amount <= 0) {
        printf("\nInvalid amount! Deposit must be positive.\n");
        return;
    }

    currentBalance += amount;
    printf("\n%d has been deposited to your account.\n", amount);
    printf("New Balance: %d\n", currentBalance);
}

/*=== Check Balance ===*/
int checkBalance() {
    printf("\nYour Current Balance is: %d\n", currentBalance);
    return currentBalance;
}

/*=== Login Function with 3 Attempts ===*/
int login() {
    char PIN[16] = "7819";
    char inputPin[16];
    int attempts = 0;

    puts("AUTOMATIC TELLER MACHINE");
    puts("========================");

    while (attempts < 3) {
        printf("\nEnter Your Access PIN: ");
        scanf("%15s", inputPin);

        // Check PIN length
        if (strlen(inputPin) < 4) {
            printf("\033[31mPIN TOO SHORT\033[0m\n");
            attempts++;
            continue;
        }
        if (strlen(inputPin) > 4) {
            printf("\033[31mPIN TOO LONG\033[0m\n");
            attempts++;
            continue;
        }

        // Compare PIN
        if (strcmp(inputPin, PIN) == 0) {
            printf("\033[32mACCESS GRANTED\033[0m\n");
            return 1;  // Success
        } else {
            printf("\033[31mACCESS DENIED - Incorrect PIN\033[0m\n");
            attempts++;
        }
    }

    printf("\nToo many failed attempts. Exiting...\n");
    return 0;  // Failed login
}

/*=== MAIN PROGRAM ===*/
int main(void) {

    if (!login()) {
        return 0; // Stop program if login fails
    }

    int option = 0;
    int amount = 0;

    printf("\n======================================\n");
    printf("  Hello! Welcome To Our ATM System\n");
    printf("======================================\n");

    do {
        printf("\nHow can we help you?\n");
        printf(" 1. Deposit Cash\n");
        printf(" 2. Withdraw Cash\n");
        printf(" 3. Check Balance\n");
        printf(" 4. Exit\n");
        printf("Enter your option (1-4): ");

        if (scanf("%d", &option) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            option = 0;
            continue;
        }

        switch (option) {
            case 1:
                printf("Enter the amount to deposit: ");
                scanf("%d", &amount);
                deposit(amount);
                break;

            case 2:
                printf("Enter the amount to withdraw: ");
                scanf("%d", &amount);
                withdraw(amount);
                break;

            case 3:
                checkBalance();
                break;

            case 4:
                printf("\nThank you for banking with us. Goodbye! \n");
                break;

            default:
                printf("\nInvalid option. Please choose 1, 2, 3, or 4.\n");
        }

    } while (option != 4);

    return 0;
}

