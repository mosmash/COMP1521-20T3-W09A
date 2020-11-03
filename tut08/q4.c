#include <stdio.h>
#include <stdlib.h> 

int main (int argc, char* argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Error: wrong number of arguments, expected 2.");
    }

    // open the file
    FILE* fp = fopen(argv[1], "r");
    // did it fail?
    if (fp == NULL) {
        perror(argv[1]);
        exit(1);
    }

    // print out first line
    int c = fgetc(fp); 
    while (c != '\n' && c != EOF) {
        printf("%c", (char)c);

        c = fgetc(fp); 
    }


    fclose(fp);
    return 0;
}