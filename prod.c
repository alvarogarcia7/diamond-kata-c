#include "prod.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_pattern_A_(char **result_ptr, char c) {
    *result_ptr = calloc(10, sizeof(char));

    char *result = *result_ptr;

    result[0] = ' ';
    result[1] = c;
    result[2] = ' ';
}

char **diamond(char *chars){
    char **result;
    result = calloc(1 + 1 + 1 + 1, sizeof(char *));
    result[0] = calloc(10, sizeof(char));
    if(strlen(chars) == 1) {
        result[0] = calloc(10, sizeof(char));
        result[0][0] = chars[0];
        result[1] = NULL;
    } else if(strlen(chars) == 2){
        fill_pattern_A_(&result[0], chars[0]);

        result[1] = calloc(10, sizeof(char));
        result[1][0] = chars[1];
        result[1][1] = ' ';
        result[1][2] = chars[1];

        fill_pattern_A_(&result[2], chars[0]);

        result[3] = NULL;
    }
    return result;
}
