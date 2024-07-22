#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void numEncryption(char *text, int *encrypted_text) {
    int length = strlen(text);
    int i = 5;
    char tempStr[length];
    int factors[5] = {0, 1, 2, 3, 4};
    
    // Encrypt the text
    for (int j = 0; j < length; j++) {
        tempStr[j] = text[j] + i;
        i++;
    }
    tempStr[length] = '\0';

    // Perform first transformation
    for (int j = 0; j < length / 2; j++) {
        char temp = tempStr[j];
        tempStr[j] = tempStr[length - 1 - j];
        tempStr[length - 1 - j] = temp;
    }

    // Perform second transformation
    for (int j = 1; j < length; j += 2) {
        char temp = tempStr[j];
        tempStr[j] = tempStr[j - 1];
        tempStr[j - 1] = temp;
    }

    // Convert the encrypted text to an integer array
    int k = 0;
    for (int j = 0; j < length; j++) {
        encrypted_text[j] = (int)tempStr[j];
        encrypted_text[j] = encrypted_text[j];
        if (k == 5) k = 0;
        encrypted_text[j] = encrypted_text[j] * factors[k];
        k++;
    }
}

void numDecryption(int *encrypted_text, char *decrypted_text, int length) {
    int factors[5] = {0, 1, 2, 3, 4};
    int tempInt[length];
    int k = 0;

    // Revert the conversion from integer array to characters
    for (int j = 0; j < length; j++) {
        if (factors[k] != 0) {
            tempInt[j] = encrypted_text[j] / factors[k];
        } else {
            tempInt[j] = encrypted_text[j];
        }
        k++;
        if (k == 5) k = 0;
    }

    for (int j = 0; j < length; j++) {
        decrypted_text[j] = (char)tempInt[j];
    }
    decrypted_text[length] = '\0';

    // Reverse the second transformation
    for (int j = 1; j < length; j += 2) {
        char temp = decrypted_text[j];
        decrypted_text[j] = decrypted_text[j - 1];
        decrypted_text[j - 1] = temp;
    }

    // Reverse the first transformation
    for (int j = 0; j < length / 2; j++) {
        char temp = decrypted_text[j];
        decrypted_text[j] = decrypted_text[length - 1 - j];
        decrypted_text[length - 1 - j] = temp;
    }

    // Reverse the initial encryption transformation
    int i = 5;
    for (int j = 0; j < length; j++) {
        decrypted_text[j] -= i;
        i++;
    }
}

#include <stdio.h>
#include <string.h>

void numEncryptionWithKey(char *text, int *encrypted_text, int key) {

    int length = strlen(text);
    int i = 5;
    int tempStr[length];
    int factors[5] = {0, 1, 2, 3, 4};
    key = (key+1)<<2;

    // Convert the key to a int arr
    int keyLen = numDigits(key);
    int keyArr[keyLen];
    
    // Extract each digit and store in the array
    for (int i = keyLen - 1; i >= 0; i--) {
        digitArray[i] = num % 10;
        num /= 10;
    }

    // Convert text to integer array
    for int(i = 0; i < length; i++) {
        tempStr[j] = int(text[j]);
        i++;
    }

    // Encrypt the text using the key
    for (int j = 0; j < length; j++) {
        int keyIndex = j%keyLen;
        tempStr[j] = (tempStr[j] + i) * keyArr[keyIndex];
    }

    // Perform first transformation
    for (int j = 0; j < length / 2; j++) {
        char temp = tempStr[j];
        tempStr[j] = tempStr[length - 1 - j];
        tempStr[length - 1 - j] = temp;
    }

    // Perform second transformation
    for (int j = 1; j < length; j += 2) {
        char temp = tempStr[j];
        tempStr[j] = tempStr[j - 1];
        tempStr[j - 1] = temp;
    }

    //Put the result in encrypted_text
    for (int j = 0; j < length; j++) {
        encrypted_text[j] = tempStr[j];
    }
}

int main() {
    char text[] = "HelloWorld";
    int encrypted_text[strlen(text)];
    int key = 3;

    numEncryptionWithKey(text, encrypted_text, key);

    printf("Encrypted text: ");
    for (int i = 0; i < strlen(text); i++) {
        printf("%d ", encrypted_text[i]);
    }
    printf("\n");

    return 0;
}


// Main function to test the encryption and decryption
int main() {
    char plain_text[100];  // Adjust size as needed
    char encrypted_text[100];
    char decrypted_text[100];
    int num_encrypted[100];
    char num_decrypted[100];

    printf("Enter a plain text: ");
    fgets(plain_text, sizeof(plain_text), stdin);

    // Remove the newline character at the end of the input
    plain_text[strcspn(plain_text, "\n")] = 0;

    encryptNoKey(plain_text, encrypted_text);
    printf("Encrypted: %s\n", encrypted_text);

    decryptNoKey(encrypted_text, decrypted_text);
    printf("Decrypted: %s\n", decrypted_text);

    numEncryption(plain_text, num_encrypted);
    printf("Encrypted (numbers): ");
    for (int i = 0; i < (int)strlen(plain_text); i++) {
        printf("%d ", num_encrypted[i]);
    }
    printf("\n");

    numDecryption(num_encrypted, num_decrypted, strlen(plain_text));
    printf("Decrypted (numbers): %s\n", num_decrypted);


    return 0;
}
