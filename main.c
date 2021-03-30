#include <stdio.h>

#include <stdlib.h>
#include "prod.h"

void usage(char *program_name) {
    printf("Usage: %s ALPHABET\n", program_name);
    printf("Examp: %s ABCD\n", program_name);
}

int main(int argc, char** argv){
    if(argc < 2){
        usage(argv[0]);
        return -1;
    }

    char *alphabet = argv[1];

    char **result = diamond(alphabet);
    {
        int i = 0;
        while (result[i] != NULL) {
            printf("%s\n", result[i]);
            i++;
        }
    }

    {
        int i = 0;
        while (result[i] != NULL) {
            free(result[i]);
            i++;
        }
        free(result);
    }
    return 0;
}