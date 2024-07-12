#include <stdio.h>
#include <string.h>

int bf(char *str, char *pattern){
    int str_len = strlen(str);
    int pat_len = strlen(pattern);
    int i,j;
    for (i = 0; i <= str_len - pat_len; i++) {
        for (j = 0; j < pat_len; j++) {
            if (str[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == pat_len) {
            return i; // Match found at index i
        }
    }
    return -1; // No match found
}

int main(){
    char str[100];
    char pattern[100];

    printf("Enter the String: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    printf("Enter the pattern to search for: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = 0;

    int idx = bf(str, pattern);
    if(idx != -1){
        printf("Pattern is found at: %d", idx);
    } else {
        printf("Pattern Not Found!");
}
return 0;
}