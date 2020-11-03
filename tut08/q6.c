#include <stdio.h>
#include <stdlib.h> 

int main (int argc, char* argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Error: wrong number of arguments, expected 2.");
    }

    // open file
    FILE* fp = fopen(argv[1], "a");
    // check for fail.
    if (fp == NULL) {
        perror(argv[1]);
        exit(1);
    }

    int c = fgetc(stdin);
    while (c != EOF && c != '\n') {
        int result = fputc(c, fp);
        if (result == EOF) {
            fprintf(stderr, "failed to write to file.");
        }
        c = fgetc(stdin);
    }


    fclose(fp);
    return 0;
}