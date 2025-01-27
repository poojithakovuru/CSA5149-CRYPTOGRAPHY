#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void generateKeyTable(char key[], char keyTable[SIZE][SIZE]);
void search(char keyTable[SIZE][SIZE], char a, char b, int pos[]);
void encrypt(char str[], char keyTable[SIZE][SIZE]);

int main() {
    char key[100], str[100];
    char keyTable[SIZE][SIZE];

    printf("Enter the keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 

    generateKeyTable(key, keyTable);

    printf("Enter the plaintext: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    encrypt(str, keyTable);

    printf("Ciphertext: %s\n", str);

    return 0;
}
void generateKeyTable(char key[], char keyTable[SIZE][SIZE]) {
    int dict[26] = {0};
    int i, j, k = 0;
    int len = strlen(key);

    for (i = 0; i < len; i++) {
        if (key[i] == 'j') key[i] = 'i';
        if (!dict[key[i] - 'a'] && key[i] != ' ') {
            keyTable[k / SIZE][k % SIZE] = key[i];
            dict[key[i] - 'a'] = 1;
            k++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (i + 'a' == 'j') continue;
        if (!dict[i]) {
            keyTable[k / SIZE][k % SIZE] = i + 'a';
            k++;
        }
    }
}
void search(char keyTable[SIZE][SIZE], char a, char b, int pos[]) {
    int i, j;

    if (a == 'j') a = 'i';
    if (b == 'j') b = 'i';

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyTable[i][j] == a) {
                pos[0] = i;
                pos[1] = j;
            }
            if (keyTable[i][j] == b) {
                pos[2] = i;
                pos[3] = j;
            }
        }
    }
}
void encrypt(char str[], char keyTable[SIZE][SIZE]) {
    int len = strlen(str);
    int pos[4];
    int i;
    for (i = 0; i < len; i += 2) {
        if (str[i] == str[i + 1]) {
            memmove(&str[i + 2], &str[i + 1], len - i);
            str[i + 1] = 'x';
            len++;
        }
    }
    if (len % 2 != 0) {
        str[len] = 'x';
        str[len + 1] = '\0';
    }
    for (i = 0; i < len; i += 2) {
        search(keyTable, str[i], str[i + 1], pos);
        if (pos[0] == pos[2]) {  
            str[i] = keyTable[pos[0]][(pos[1] + 1) % SIZE];
            str[i + 1] = keyTable[pos[2]][(pos[3] + 1) % SIZE];
        } else if (pos[1] == pos[3]) {  
            str[i] = keyTable[(pos[0] + 1) % SIZE][pos[1]];
            str[i + 1] = keyTable[(pos[2] + 1) % SIZE][pos[3]];
        } else {
            str[i] = keyTable[pos[0]][pos[3]];
            str[i + 1] = keyTable[pos[2]][pos[1]];
        }
    }
}

