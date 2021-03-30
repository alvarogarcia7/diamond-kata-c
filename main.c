#include <stdio.h>

#include <stdlib.h>
#include "prod.h"

void usage(char *program_name) {
    printf("Usage: %s ALPHABET\n", program_name);
    printf("Examp: %s ABCD\n", program_name);
}

void print(char *line){
    printf("%s\n", line);
}

int main(int argc, char** argv){
    if(argc < 2){
        usage(argv[0]);
        return -1;
    }
    char *alphabet = argv[1];
    char **result = diamond(alphabet);
    diamond_foreach(result, &print);
    diamond_free(result);
    return 0;
}