#include "prod.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **diamond(char *chars){
    char **result;
    result = calloc(1 + 1 + 1 + 1, sizeof(char *));
    result[0] = calloc(10, sizeof(char));
    if(strlen(chars) == 1) {
        result[0] = calloc(10, sizeof(char));
        result[0][0] = chars[0];
        result[1] = NULL;
    } else if(strlen(chars) == 2){
        result[0] = calloc(10, sizeof(char));
        result[0][0] = ' ';
        result[0][1] = chars[0];
        result[0][2] = ' ';

        result[1] = calloc(10, sizeof(char));
        result[1][0] = chars[1];
        result[1][1] = ' ';
        result[1][2] = chars[1];

        result[2] = calloc(10, sizeof(char));
        result[2][0] = ' ';
        result[2][1] = chars[0];
        result[2][2] = ' ';

        result[3] = NULL;
    }
    return result;
}
