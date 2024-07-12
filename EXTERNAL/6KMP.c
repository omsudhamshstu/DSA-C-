#include <stdio.h>
#include <string.h>

void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0;
    for (int i = 1; i < M; i++) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
        } else if (len!= 0) {
            len = lps[len - 1];
        } else {
            lps[i] = 0;
        }
    }
}

void KMPSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0, j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j]!= txt[i]) {
            if (j!= 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main() {
    char txt[] = "banana";
    char pat[] = "ana";
    KMPSearch(pat, txt);
    return 0;
}