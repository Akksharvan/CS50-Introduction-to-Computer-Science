#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score (string word) {
    int score = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (toupper(word[i]) >= 65 && toupper(word[i]) <= 90) score += POINTS[(int) (toupper(word[i]) - 65)];
    }

    return score;
}

int main (void) {
    string word1 = get_string("Player 1: "), word2 = get_string("Player 2: ");
    int score1 = compute_score(word1), score2 = compute_score(word2);

    if (score1 > score2) printf("Player 1 wins!\n");
    else if (score1 < score2) printf("Player 2 wins!\n");
    else printf("Tie!\n");
}