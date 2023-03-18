#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;

    FILE *card = fopen(argv[1], "r");
    if (card == NULL) return 1;

    int file_number = 0;
    char file_name[8];

    FILE *jpg = NULL;
    BYTE buffer[BLOCK_SIZE];

    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) {
            if (jpg != NULL) fclose(jpg);
            sprintf(file_name, "%03i.jpg", file_number); jpg = fopen(file_name, "w"); file_number++;
        }

        if (jpg != NULL) fwrite(buffer, 1, BLOCK_SIZE, jpg);
    }

    fclose(card);
    fclose(jpg);

    return 0;
}