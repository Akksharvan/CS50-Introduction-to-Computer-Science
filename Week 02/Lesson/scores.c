#include <stdio.h>

float average (int length, int array[]) {
    int sum = 0;
    for (int i = 0; i < N; i++) sum += array[i];

    return (float) sum / (float) length;
}

int main (void) {
    const int N = 3; int scores[N];
    scores[0] = 72; scores[1] = 73, scores[2] = 33;

    printf("Average: %f\n", average(N, scores));
}