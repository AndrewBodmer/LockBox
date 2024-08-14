#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//! THIS IS ONLY A SERIES OF EXPERIMENTAL FUNCTIONS THIS PARTICULAR
//!     FILE WILL NOT BE USED DIRECTLY FOR ANYTHING

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

#include <string.h>

#include <string.h>

void numEncryption(char *text, int *encrypted_text) {
    int length = strlen(text);
    int tempStr[length];
    int factors[5] = {1, 2, 3, 4, 5}; // Avoid zero to prevent multiplication by zero

    // Convert text to integer array
    for (int j = 0; j < length; j++) {
        tempStr[j] = (int)text[j];
    }

    // Encrypt the integer array
    int i = 5;
    for (int j = 0; j < length; j++) {
        tempStr[j] = (tempStr[j] + i);
        i++;
    }

    // Perform first transformation (reverse the array)
    for (int j = 0; j < length / 2; j++) {
        int temp = tempStr[j];
        tempStr[j] = tempStr[length - 1 - j];
        tempStr[length - 1 - j] = temp;
    }

    // Perform second transformation (swap adjacent elements)
    for (int j = 1; j < length; j += 2) {
        int temp = tempStr[j];
        tempStr[j] = tempStr[j - 1];
        tempStr[j - 1] = temp;
    }

    // Apply factors to the encrypted integer array and store in encrypted_text
    int k = 0;
    for (int j = 0; j < length; j++) {
        encrypted_text[j] = (tempStr[j] * factors[k]);
        k = (k + 1) % 5; // Cycle through factors
    }
}

void numDecryption(int *encrypted_text, char *decrypted_text, int length) {
    int tempStr[length];
    int factors[5] = {1, 2, 3, 4, 5}; // Same factors used in encryption
    int k = 0;

    // Reverse the application of factors from encrypted_text
    for (int j = 0; j < length; j++) {
        for (int i = 0; i < 256; i++) { // Try all possible values to reverse the multiplication
            if ((i * factors[k]) == encrypted_text[j]) {
                tempStr[j] = i;
                break;
            }
        }
        k = (k + 1) % 5; // Cycle through factors
    }

    // Reverse the second transformation (swap back adjacent elements)
    for (int j = 1; j < length; j += 2) {
        int temp = tempStr[j];
        tempStr[j] = tempStr[j - 1];
        tempStr[j - 1] = temp;
    }

    // Reverse the first transformation (reverse the array back)
    for (int j = 0; j < length / 2; j++) {
        int temp = tempStr[j];
        tempStr[j] = tempStr[length - 1 - j];
        tempStr[length - 1 - j] = temp;
    }

    // Reverse the encryption of the integer array
    int i = 5 + (length - 1); // Start from the last increment value
    for (int j = length - 1; j >= 0; j--) {
        tempStr[j] = (tempStr[j] - i); // Use modular arithmetic to handle negative values
        i--;
    }

    // Convert integer array back to text
    for (int j = 0; j < length; j++) {
        decrypted_text[j] = (char)tempStr[j];
    }
    decrypted_text[length] = '\0'; // Null-terminate the decrypted string
}

void numEncryptionWithKey(char *text, int *encrypted_text, int key) {
    int length = strlen(text);
    int tempStr[length];
    key = (key + 1) << 2;

    // Convert the key to an int array
    int tempKey = key;
    int keyLen = 0;
    while (tempKey != 0) {
        tempKey /= 10;
        keyLen++;
    }
    int keyArr[keyLen];
    tempKey = key;
    for (int i = keyLen - 1; i >= 0; i--) {
        keyArr[i] = tempKey % 10;
        tempKey /= 10;
    }

    // Convert text to integer array
    for (int i = 0; i < length; i++) {
        tempStr[i] = (int)text[i];
    }

    // Encrypt the text using the key
    int i = 5;
    for (int j = 0; j < length; j++) {
        int keyIndex = j % keyLen;
        tempStr[j] = ((tempStr[j] + i) * keyArr[keyIndex]); // Prevent overflow
        i++;
    }

    // Perform first transformation (reverse the array)
    for (int j = 0; j < length / 2; j++) {
        int temp = tempStr[j];
        tempStr[j] = tempStr[length - 1 - j];
        tempStr[length - 1 - j] = temp;
    }

    // Perform second transformation (swap adjacent elements)
    for (int j = 1; j < length; j += 2) {
        int temp = tempStr[j];
        tempStr[j] = tempStr[j - 1];
        tempStr[j - 1] = temp;
    }

    // Put the result in encrypted_text
    for (int j = 0; j < length; j++) {
        encrypted_text[j] = tempStr[j];
    }
}

void numDecryptionWithKey(int *encrypted_text, char *decrypted_text, int textLength, int key) {
    int length = textLength;
    int tempStr[length];
    key = (key + 1) << 2;

    // Convert the key to an int array
    int tempKey = key;
    int keyLen = 0;
    while (tempKey != 0) {
        tempKey /= 10;
        keyLen++;
    }
    int keyArr[keyLen];
    tempKey = key;
    for (int i = keyLen - 1; i >= 0; i--) {
        keyArr[i] = tempKey % 10;
        tempKey /= 10;
    }

    // Copy the encrypted text to tempStr
    for (int i = 0; i < length; i++) {
        tempStr[i] = encrypted_text[i];
    }

    // Perform the second transformation (swap adjacent elements) in reverse
    for (int j = 1; j < length; j += 2) {
        int temp = tempStr[j];
        tempStr[j] = tempStr[j - 1];
        tempStr[j - 1] = temp;
    }

    // Perform the first transformation (reverse the array) in reverse
    for (int j = 0; j < length / 2; j++) {
        int temp = tempStr[j];
        tempStr[j] = tempStr[length - 1 - j];
        tempStr[length - 1 - j] = temp;
    }

    // Decrypt the text using the key
    int i = 5;
    for (int j = 0; j < length; j++) {
        int keyIndex = j % keyLen;

        tempStr[j] /= keyArr[keyIndex];
        tempStr[j] -= i;
        i++;
    }

    // Convert the integer array back to text
    for (int i = 0; i < length; i++) {
        decrypted_text[i] = (char)tempStr[i];
    }
    decrypted_text[length] = '\0'; // Null-terminate the string
}

// Main function to test the encryption and decryption
int main() {
    char plain_text[100];  // Adjust size as needed
    char encrypted_text[100];
    char decrypted_text[100];
    int num_encrypted[100];
    char num_decrypted[100];
    int num_key_encrypted[100];
    char num_key_decrypted[100];

    printf("Enter a plain text: ");
    fgets(plain_text, sizeof(plain_text), stdin);

    // Remove the newline character at the end of the input
    plain_text[strcspn(plain_text, "\n")] = 0;

    printf("\nTest character encryption and decryption without key\n");
    encryptNoKey(plain_text, encrypted_text);
    printf("Encrypted: %s\n", encrypted_text);

    decryptNoKey(encrypted_text, decrypted_text);
    printf("Decrypted: %s\n", decrypted_text);

    printf("\nTest numeric encryption and decryption without key\n");
    numEncryption(plain_text, num_encrypted);
    printf("Encrypted (numbers): ");
    for (int i = 0; i < (int)strlen(plain_text); i++) {
        printf("%d ", num_encrypted[i]);
    }
    printf("\n");

    numDecryption(num_encrypted, num_decrypted, strlen(plain_text));
    printf("Decrypted (numbers): %s\n", num_decrypted);

    printf("\nTest the numeric encryption and decryption with key\n");
    numEncryptionWithKey(plain_text, num_key_encrypted, 12345);
    printf("Encrypted (numbers and key): ");
    for (int i = 0; i < (int)strlen(plain_text); i++) {
        printf("%d ", num_key_encrypted[i]);
    }
    printf("\n");

    numDecryptionWithKey(num_key_encrypted, num_key_decrypted, strlen(plain_text), 12345);
    printf("Decrypted (numbers and key): %s\n", num_key_decrypted);

    return 0;
}
