#include <stdio.h>
#include <string.h>

char monocipher_encr(char);
char alpha[27][2] = {
    { 'a', 'f' }, { 'b', 'a' }, { 'c', 'g' }, { 'd', 'u' },
    { 'e', 'n' }, { 'f', 'i' }, { 'g', 'j' }, { 'h', 'k' },
    { 'i', 'l' }, { 'j', 'm' }, { 'k', 'o' }, { 'l', 'p' },
    { 'm', 'q' }, { 'n', 'r' }, { 'o', 's' }, { 'p', 't' },
    { 'q', 'v' }, { 'r', 'w' }, { 's', 'x' }, { 't', 'y' },
    { 'u', 'z' }, { 'v', 'b' }, { 'w', 'c' }, { 'x', 'd' },
    { 'y', 'e' }, { 'z', 'h' }
};
int main() {
    char str[100], str2[100];
    int i;
    printf("Enter String: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  
    for (i = 0; str[i]; i++) {
        str2[i] = monocipher_encr(str[i]);
    }
    str2[i] = '\0';
    printf("\nBefore Encryption: %s", str);
    printf("\nAfter Encryption: %s\n", str2);
    return 0;
}
char monocipher_encr(char a) {
    int i;
    if (a == ' ') { 
        return ' ';
    }
    for (i = 0; i < 26; i++) {
        if (a == alpha[i][0]) {
            return alpha[i][1];
        }
    }
    return a;  
}
