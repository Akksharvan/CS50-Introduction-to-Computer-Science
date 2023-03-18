#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

typedef struct node
{ char word[LENGTH + 1]; struct node *next; } node;

const unsigned int N = 100000;
node *table[N];

unsigned int dictionary_size = 0;

bool check (const char *word) {
    node *n = table[hash(word)];
    while (n != NULL) {
        if (strcasecmp(word, n -> word) == 0) return 1;
        n = n -> next;
    }

    return 0;
}

unsigned int hash (const char *word) { unsigned int h = 0; for (int i = 0; i < strlen(word); i++) h += tolower(word[i]); return h % N; }

bool load (const char *dictionary) {
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL) return 0;

    char w[LENGTH + 1];
    while (fscanf(dict, "%s", w) != EOF) {
        node *n = malloc(sizeof(node));
        if (n == NULL) return 0;

        strcpy(n -> word, w); n -> next = table[hash(w)];
        table[hash(w)] = n; dictionary_size++;
    }

    fclose(dict);
    return 1;
}

unsigned int size (void) { return dictionary_size; }

bool unload (void) {
    for (int i = 0; i < N; i++) {
        node *n = table[i]; while (n != NULL) { node *r = n; n = n -> next; free(r); }
        if (n == NULL && i == N - 1) return true;
    }

    return false;
}