#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    char *home = getenv("HOME");
    if (home == NULL) {
        fprintf(stderr, "HOME variable failed");
        exit(1);
    }


    // combine .diary and home location string
    char* diary = "/.diary";
    size_t n_bytes = strlen(home) + strlen(diary) + 1;
    char dest[n_bytes];
    snprintf(dest, n_bytes, "%s%s", home, diary);

    FILE *fp= fopen(dest, "r");
    if (fp == NULL) {
        perror(dest);
    }

    int c = fgetc(fp);
    while (c != EOF) {
        fputc(c, stdout);
        c = fgetc(fp);
    }

    return 0;
}