#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

void chmod_if_needed(char *pathname);

int main (int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Incorrect number of arguments, expected at least 2 but got %d", argc);
        exit(1);
        // or return 1;
    }

    for (int i=1; i < argc; i++) {
        chmod_if_needed(argv[i]);
    }

    return 0;
}

void chmod_if_needed(char *pathname) {
    struct stat st;

    if (stat(pathname, &st) == -1) {
        perror(pathname);
        exit(1);
    }

    if ((st.st_mode & S_IWOTH) != 0) {
        // it is writable
        printf("removing public write from %s", pathname);

        // remove it.
        mode_t new_mode = st.st_mode & ~S_IWOTH;

        if (chmod(pathname, new_mode) == -1) {
            // we failed.
            perror("failed to change file");
            exit(1);
        }

    } else {
        // already not writable
        printf("%s is not publicallu writable", pathname);
        return;
    }
}