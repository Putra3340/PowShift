#include <stdio.h>
#include <string.h>
#include "encryption.h"

int main() {
    char input[] = "Hello, World!";
    char encrypted[256];
    char decrypted[256];

    int key = 3; // Example key for shifting
    
    encrypt(input, encrypted, key);
    printf("Encrypted: %s\n", encrypted);

    decrypt(encrypted, decrypted, key);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
