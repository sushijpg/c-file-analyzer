#include <stdio.h>
#include <stdlib.h>
#include "analyzer.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    FileStats stats = analyze_file(file);

    printf("Lines: %d\n", stats.lines);
    printf("Words: %d\n", stats.words);
    printf("Characters: %d\n", stats.characters);

    fclose(file);
    return 0;
}

FileStats analyze_file(FILE *file) {
    FileStats stats = {0, 0, 0};
    int c;
    int in_word = 0;

    while ((c = fgetc(file)) != EOF) {
        stats.characters++;

        if (c == '\n') {
            stats.lines++;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            stats.words++;
        }
    }

    return stats;
}