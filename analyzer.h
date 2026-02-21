#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdio.h>

typedef struct {
    int lines;
    int words;
    int characters;
} FileStats;

/**
 * Analyzes the given file stream and returns basic statistics.
 *
 * @param file Pointer to an open file
 * @return FileStats containing line, word, and character counts
 */
FileStats analyze_file(FILE *file);

#endif