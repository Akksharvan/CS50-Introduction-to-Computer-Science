#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool onlydigits (string arg) {
    for (int i = 0; i < strlen(arg); i++) if (arg[i] < 48 || arg[i] > 57) return 0;
    return 1;
}

int main(int argc, string argv[])  {
    if (argc < 2 || argc > 2 || (argc == 2 && !onlydigits(argv[1]))) { printf("Usage: ./caesar key\n"); return 1; }
    else {
        int key = atoi(argv[1]);
        string text = get_string("plaintext: ");

        printf("ciphertext: ");
        for (int i = 0; i < strlen(text); i++) {
            if (text[i] >= 65 && text[i] <= 90) printf("%c", ((text[i] - 64 + key) % 26) + 64);
            else if (text[i] >= 97 && text[i] <= 122) printf("%c", ((text[i] - 96 + key) % 26) + 96);
            else printf("%c", text[i]);
        }

        printf("\n");
    }
}