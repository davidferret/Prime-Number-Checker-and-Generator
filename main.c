#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n);
int generateLargePrime(int lower, int upper);
void menu();

int main(void) {
    int choice, number;
    srand(time(NULL));

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a positive integer: ");
                scanf("%d", &number);
                if (isPrime(number)) {
                    printf("%d is a prime number.\n", number);
                } else {
                    printf("%d is NOT a prime number.\n", number);
                }
                break;
            case 2:
                printf("Generating a large prime number for cryptography...\n");
                number = generateLargePrime(1000, 9999);
                printf("Generated Prime: %d\n", number);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int generateLargePrime(int lower, int upper) {
    int num;
    do {
        num = (rand() % (upper - lower + 1)) + lower;
    } while (!isPrime(num));
    return num;
}

void menu() {
    printf("\n--- Prime Number & Cryptography Utility ---\n");
    printf("1. Check if a number is prime\n");
    printf("2. Generate a large prime for encryption key\n");
    printf("3. Exit\n");
}
