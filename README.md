# RSA Cryptography Utility

This program provides a range of cryptographic functionalities, including primality testing, large prime number generation, and RSA-like key pair generation. It's designed to make cryptography more accessible by offering an easy-to-use interface for selecting cryptographic functions.

You can use this program to check if a number is prime, generate large prime numbers based on a custom bit size, and create RSA-like key pairs using two large primes. The prime number check determines whether a given integer is prime, and the custom bit-size prime generation feature allows you to specify the size of the prime number you need.

For key generation, the program uses the two large prime numbers to generate an RSA-like key pair. The user-friendly menu makes it easy for you to select and execute any of these cryptographic functions, while an optimized algorithm ensures efficient and accurate primality testing.

## Example Output
```
--- Prime Number & Cryptography Utility ---
1. Check if a number is prime
2. Generate a large prime with custom bit size
3. Generate RSA-like Key Pair
4. Exit
Enter your choice: 2
Enter the number of bits for the prime (e.g., 10, 12, 16): 12
Generating a large prime number...
Generated Prime: 4093

Enter your choice: 3
Enter bit size for RSA Key Generation (e.g., 8, 16, 32): 8
Generated RSA Key Pair:
Public Key (n): 2773
Prime Factors (p, q): 47, 59

Enter your choice: 4
Exiting program.

```

