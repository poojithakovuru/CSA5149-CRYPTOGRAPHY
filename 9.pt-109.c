#include <stdio.h>
#include <string.h>
#include <ctype.h>
void decryptPlayfair(char *ciphertext) {
    int len = strlen(ciphertext);
    char plaintext[len];
    int index = 0;
    int i;

    for ( i = 0; i < len; i += 2) {
        char first = toupper(ciphertext[i]);
        char second = toupper(ciphertext[i + 1]);

        if (first == second) {
            plaintext[index++] = first;
            plaintext[index++] = 'X';
            i--; 
        } else {
            int pos1 = (first - 'A') % 25;
            int pos2 = (second - 'A') % 25;

            plaintext[index++] = 'A' + pos1;
            plaintext[index++] = 'A' + pos2;
        }
    }

    plaintext[index] = '\0'; 
    printf("Decrypted message:\n%s\n", plaintext);
}

int main() {
    #define MAX_BUFFER_SIZE 1000
    char ciphertext[MAX_BUFFER_SIZE];

    printf("Enter the ciphertext to decrypt:\n");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    ciphertext[strcspn(ciphertext, "\n")] = '\0';

    decryptPlayfair(ciphertext);

    return 0;
}
