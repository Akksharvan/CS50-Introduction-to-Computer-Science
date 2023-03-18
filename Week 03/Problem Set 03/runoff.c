#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int MAX_VOTERS = 100;
const int MAX_CANDIDATES = 9;

typedef struct
{ string name; int votes; bool eliminated; } candidate;

int preferences[MAX_VOTERS][MAX_CANDIDATES];
candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

bool vote (int voter, int rank, string name) {
    for (int i = 0; i < candidate_count; i++) if (!strcmp(candidates[i].name, name)) { preferences[voter][rank] = i; return 1; }
    return 0;
}

void tabulate (void) {
    for (int i = 0; i < voter_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            if (!candidates[preferences[i][j]].eliminated) { candidates[preferences[i][j]].votes++; break; }
        }
    }

    return;
}

bool print_winner (void) {
    for (int i = 0; i < candidate_count; i++) {
        if (!candidates[i].eliminated && candidates[i].votes > (voter_count / 2)) { printf("%s\n", candidates[i].name); return 1; }
    }

    return 0;
}

int find_min (void) {
    int min_votes = voter_count;
    for (int i = 0; i < candidate_count; i++) if (!candidates[i].eliminated && candidates[i].votes < min_votes) min_votes = candidates[i].votes;
    return min_votes;
}

bool is_tie (int min) {
    for (int i = 0; i < candidate_count; i++) if (!candidates[i].eliminated && candidates[i].votes > min) return 0;
    return 1;
}

void eliminate (int min) {
    for (int i = 0; i < candidate_count; i++) if (candidates[i].votes == min) candidates[i].eliminated = 1;
    return;
}

int main (int argc, string argv[]) {
    if (argc < 2) { printf("Usage: runoff [candidate ...]\n"); return 1; }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES) { printf("Maximum number of candidates is %i\n", MAX_CANDIDATES); return 2; }

    for (int i = 0; i < candidate_count; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS) { printf("Maximum number of voters is %i\n", MAX_VOTERS); return 3; }

    for (int i = 0; i < voter_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            string name = get_string("Rank %i: ", j + 1);
            if (!vote(i, j, name)) { printf("Invalid vote.\n"); return 4; }
        }

        printf("\n");
    }

    while (true) {
        tabulate();
        if (print_winner()) break;

        if (is_tie(find_min())) {
            for (int i = 0; i < candidate_count; i++)if (!candidates[i].eliminated) printf("%s\n", candidates[i].name);
            break;
        }

        eliminate(find_min());
        for (int i = 0; i < candidate_count; i++) candidates[i].votes = 0;
    }

    return 0;
}