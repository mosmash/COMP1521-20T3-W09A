#include <stdio.h>
#include <stdlib.h>

int get_bort(FILE *fp);

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

    // reading the borts
    int bort = get_bort(fp); 
    int i = 0;
    while (bort != EOF) {

        printf("bort %4ld: %d", i, bort);

        bort = get_bort(fp);
        i++;
    }


    fclose(fp);
    return 0;
}

int get_bort(FILE *fp) {
    int byte1 = fgetc(fp);
    int byte2 = fgetc(fp);

    if (byte1 == EOF || byte2 == EOF) {
        return EOF;     
    }

    byte1 = (unsigned int) byte1 << 8;

    return byte1 | byte2;
}