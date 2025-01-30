#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n);
int generateLargePrime(int lower, int upper);
void generateRSAKeyPair(int bitSize);
void menu();

int main(void) {
    int choice, number, bitSize;
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
                printf("Enter the number of bits for the prime (e.g., 10, 12, 16): ");
                scanf("%d", &bitSize);
                printf("Generating a large prime number...\n");
                number = generateLargePrime(1 << (bitSize - 1), (1 << bitSize) - 1);
                printf("Generated Prime: %d\n", number);
                break;
            case 3:
                printf("Enter bit size for RSA Key Generation (e.g., 8, 16, 32): ");
                scanf("%d", &bitSize);
                generateRSAKeyPair(bitSize);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

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

void generateRSAKeyPair(int bitSize) {
    int p = generateLargePrime(1 << (bitSize - 1), (1 << bitSize) - 1);
    int q = generateLargePrime(1 << (bitSize - 1), (1 << bitSize) - 1);
    int n = p * q;
    printf("Generated RSA Key Pair:\n");
    printf("Public Key (n): %d\n", n);
    printf("Prime Factors (p, q): %d, %d\n", p, q);
}

void menu() {
    printf("\n--- Prime Number & Cryptography Utility ---\n");
    printf("1. Check if a number is prime\n");
    printf("2. Generate a large prime with custom bit size\n");
    printf("3. Generate RSA-like Key Pair\n");
    printf("4. Exit\n");
}
