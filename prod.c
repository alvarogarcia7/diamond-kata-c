#include "prod.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_TERMINATOR 1

void fill_pattern_A_(char **result_ptr, char c, int columns) {
    *result_ptr = calloc(columns, sizeof(char));

    char *result = *result_ptr;

    for (int i = 0; i < columns; ++i) {
        result[i] = ' ';
    }

    result[columns/2] = c;
}

void fill_pattern_B_B(char **result_ptr, char c, int columns) {
    *result_ptr = calloc(columns, sizeof(char));

    char *result = *result_ptr;

    for (int i = 0; i < columns; ++i) {
        result[i] = ' ';
    }

    result[0] = c;
    result[columns-1] = c;
}

int number_of_rows(char *chars) {
    if(strlen(chars) == 1){
        return 1;
    }
    int repeated = strlen(chars)/2;
    return 1 + 2 * repeated;
}

int number_of_columns(char *chars){
    return number_of_rows(chars);
}

char **diamond(char *chars){
    char **result;

    result = calloc(number_of_rows(chars) + ROW_TERMINATOR, sizeof(char *));
    if(strlen(chars) == 1) {
        fill_pattern_A_(&result[0], chars[0], number_of_columns(chars));
        result[1] = NULL;
    } else if(strlen(chars) == 2){
        fill_pattern_A_(&result[0], chars[0], number_of_columns(chars));

        fill_pattern_B_B(&result[1], chars[1], number_of_columns(chars));

        fill_pattern_A_(&result[2], chars[0], number_of_columns(chars));

        result[3] = NULL;
    }
    return result;
}
