#include <stdio.h>
#include <string.h>

void kmp(char *str, char *pattern) {
    int strLen = strlen(str);
    int patternLen = strlen(pattern);
    int lps[patternLen], i, j;

    // Preprocess the pattern to build the lps array
    lps[0] = 0;
    for (i = 1, j = 0; i < patternLen; i++) {
        while (j > 0 && pattern[i]!= pattern[j])
            j = lps[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        lps[i] = j;
    }

    // Search for the pattern in the text
    for (i = 0, j = 0; i < strLen; i++) {
        while (j > 0 && str[i]!= pattern[j])
            j = lps[j - 1];
        if (str[i] == pattern[j])
            j++;
        if (j == patternLen) {
            printf("Pattern found at index %d\n", i - j + 1);
            j = lps[j - 1];
        }
    }
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0'; // remove the newline character

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strlen(pattern) - 1] = '\0'; // remove the newline character

    kmp(text, pattern);

    return 0;
}