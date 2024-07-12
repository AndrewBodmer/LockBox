#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text
void encryptNoKey(char *text, char *encrypted_text) {
    int length = strlen(text);
    int i = 3;
    for (int j = 0; j < length; j++) {
        encrypted_text[j] = text[j] + i;
        i++;
    }
    encrypted_text[length] = '\0';

    // Perform first transformation
    for (int j = 0; j < length / 2; j++) {
        char temp = encrypted_text[j];
        encrypted_text[j] = encrypted_text[length - 1 - j];
        encrypted_text[length - 1 - j] = temp;
    }

    // Perform second transformation
    for (int j = 1; j < length; j += 2) {
        char temp = encrypted_text[j];
        encrypted_text[j] = encrypted_text[j - 1];
        encrypted_text[j - 1] = temp;
    }
}

// Function to decrypt the text
void decryptNoKey(char *encrypted_text, char *decrypted_text) {
    int length = strlen(encrypted_text);
    strcpy(decrypted_text, encrypted_text);

    // Reverse the second transformation
    for (int i = 1; i < length; i += 2) {
        char temp = decrypted_text[i];
        decrypted_text[i] = decrypted_text[i - 1];
        decrypted_text[i - 1] = temp;
    }

    // Reverse the first transformation
    for (int i = 0; i < length / 2; i++) {
        char temp = decrypted_text[i];
        decrypted_text[i] = decrypted_text[length - 1 - i];
        decrypted_text[length - 1 - i] = temp;
    }

    // Reverse the initial encryption transformation
    int j = 3;
    for (int i = 0; i < length; i++) {
        decrypted_text[i] -= j;
        j++;
    }
    decrypted_text[length] = '\0';
}

// Main function to test the encryption and decryption
int main() {
    char plain_text[100];  // Adjust size as needed
    char encrypted_text[100];
    char decrypted_text[100];

    printf("Enter a plain text: ");
    fgets(plain_text, sizeof(plain_text), stdin);

    // Remove the newline character at the end of the input
    plain_text[strcspn(plain_text, "\n")] = 0;

    encryptNoKey(plain_text, encrypted_text);
    printf("Encrypted: %s\n", encrypted_text);

    decryptNoKey(encrypted_text, decrypted_text);
    printf("Decrypted: %s\n", decrypted_text);

    return 0;
}
