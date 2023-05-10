#include "monty.h"
//* interpreter for monty files */

int main(int argc, char **argv) {

    char *buffer = NULL;
    size_t size = 0;
    ssize_t read;
    char *clean_code = NULL;

    if (argc != 2) {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "r");
    /* fopen returns 0, the NULL pointer, on failure */
    if ( fp == 0 ) {
            printf( "Could not open file\n" );
    }
    else {
        int x;
        while ((read = getline(&buffer, &size, fp) != -1)) {
            clean_code = strtok(buffer, "$\t\n");
            printf("%s\n", clean_code);
        }
        fclose(fp);
        if (buffer) {
            free(buffer);
        }
    }
    exit(EXIT_SUCCESS);
}
