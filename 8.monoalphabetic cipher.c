#include <stdio.h>
#include <string.h>
#include <ctype.h>
void generateCipherSequence(char keyword[], char cipherSeq[]) {
    int i, j;
    char used[26] = {0}; 
    strcpy(cipherSeq, keyword);
    for (i = 0; i < strlen(keyword); i++) {
        if (isalpha(keyword[i])) {
            used[toupper(keyword[i]) - 'A'] = 1;
        }
    }
    j = strlen(keyword);
    for (i = 0; i < 26; i++) {
        if (!used[i]) {
            cipherSeq[j++] = 'A' + i;
        }
    }
    cipherSeq[j] = '\0';
}
void encryptMonoalphabetic(char plaintext[], char cipherSeq[]) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            plaintext[i] = cipherSeq[toupper(plaintext[i]) - 'A'];
        }
    }
}
int main() {
    char keyword[] = "CIPHER";
    char plaintext[100];
    char cipherSeq[26 + 1];
    generateCipherSequence(keyword, cipherSeq);
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;
    encryptMonoalphabetic(plaintext, cipherSeq);
    printf("Encrypted string: %s\n", plaintext);
    return 0;
}

