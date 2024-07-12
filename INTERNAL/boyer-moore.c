#include <stdio.h>
#include <string.h>

void boyer_moore(char *text, char *pattern) {
    int d[256]; // ASCII size
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;

    // Build bad character table
    for (i = 0; i < 256; i++)
        d[i] = M;
    for (i = 0; i < M - 1; i++)
        d[pattern[i]] = M - i - 1;

    i = 0;
    while (i <= N - M) {
        j = M - 1;

        while (text[i + j] == pattern[j])
            j--;

        if (j < 0) {
            printf("Pattern found at index %d\n", i);
            i += M - 1;
        } else
            i += d[text[i + j]];
    }
}

int main() {
    char text[] = "banana";
    char pattern[] = "ana";
    boyer_moore(text, pattern);
    return 0;
}