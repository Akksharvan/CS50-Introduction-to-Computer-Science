#include <cs50.h>
#include <stdio.h>

int get_negative_int (void) {
    int n; do n = get_int("Negative Integer: ");
    while (n >= 0); return n;
}

int main (void) {
    printf("%i\n", get_negative_int());
}