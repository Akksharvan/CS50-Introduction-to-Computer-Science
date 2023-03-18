#include <cs50.h>
#include <stdio.h>
#include <string.h>

void print_bulb (int bit) {
    if (bit == 0) printf("\U000026AB");
    else if (bit == 1) printf("\U0001F7E1");
}

int main (void) {
    string s = get_string("Message: ");
    for (int i = 0; i < strlen(s); i++) {
        bool b[8]; for (int j = 0; j < 8; j++) b[j] = 0;
        int n = s[i]; for (int j = 7; j >= 0; j--) { if (n >= (1 << j)) { n -= (1 << j); b[j] = 1; } }

        for (int j = 7; j >= 0; j--) print_bulb(b[j]);
        printf("\n");
    }
}