#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main (void) {
    string text = get_string("Text: ");
    int W = 1, L = 0, S = 0;

    for (int i = 0; i < strlen(text); i++) if (text[i] == ' ') W++;
    for (int i = 0; i < strlen(text); i++) if (toupper(text[i]) >= 65 && toupper(text[i]) <= 90) L++;
    for (int i = 0; i < strlen(text); i++) if (text[i] == '.' || text[i] == '!' || text[i] == '?') S++;

    int index = round(0.0588 * 100 * ((float) L / (float) W) - 0.296 * 100 * ((float) S / (float) W) - 15.8);
    if (index >= 16) printf("Grade 16+\n");
    else if (index < 1) printf("Before Grade 1\n");
    else printf("Grade %i\n", index);
}