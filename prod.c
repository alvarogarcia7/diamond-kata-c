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

void fill_pattern_B_B_shifted(char **result_ptr, char c, int columns, int shift) {
    *result_ptr = calloc(columns, sizeof(char));

    char *result = *result_ptr;

    for (int i = 0; i < columns; ++i) {
        result[i] = ' ';
    }

    result[0+shift] = c;
    result[columns-1-shift] = c;
}

int number_of_rows(char *chars) {
    if(strlen(chars) == 1){
        return 1;
    }
    return 1 + 2 * (strlen(chars) - 1);
}

int number_of_columns(char *chars){
    return number_of_rows(chars);
}

char **diamond(char *chars) {
    char **result;

    result = calloc(number_of_rows(chars) + ROW_TERMINATOR, sizeof(char *));
    if (strlen(chars) == 1) {
        fill_pattern_A_(&result[0], chars[0], number_of_columns(chars));
        result[1] = NULL;
    } else if (strlen(chars) == 2) {
        fill_pattern_A_(&result[0], chars[0], number_of_columns(chars));

        fill_pattern_B_B(&result[1], chars[1], number_of_columns(chars));

        fill_pattern_A_(&result[2], chars[0], number_of_columns(chars));

        result[3] = NULL;
    } else if (strlen(chars) == 3) {
        fill_pattern_A_(&result[0], chars[0], number_of_columns(chars));
        fill_pattern_B_B_shifted(&result[1], chars[1], number_of_columns(chars), 1);
        fill_pattern_B_B(&result[2], chars[2], number_of_columns(chars));
        fill_pattern_B_B_shifted(&result[3], chars[1], number_of_columns(chars), 1);
        fill_pattern_A_(&result[4], chars[0], number_of_columns(chars));

        result[5] = NULL;
    } else if (strlen(chars) == 4) {
        fill_pattern_A_(&result[0], chars[0], number_of_columns(chars));
        fill_pattern_B_B_shifted(&result[1], chars[1], number_of_columns(chars), 2);
        fill_pattern_B_B_shifted(&result[2], chars[2], number_of_columns(chars), 1);
        fill_pattern_B_B(&result[3], chars[3], number_of_columns(chars));
        fill_pattern_B_B_shifted(&result[4], chars[2], number_of_columns(chars), 1);
        fill_pattern_B_B_shifted(&result[5], chars[1], number_of_columns(chars), 2);
        fill_pattern_A_(&result[6], chars[0], number_of_columns(chars));

        result[7] = NULL;//"   A   "
    } else if (strlen(chars) == 5) {
        fill_pattern_A_(&result[0], chars[0], number_of_columns(chars));
        for (int i = 1; i <= 3 ; ++i) {
           int row = i;
           int char_index = i;
           int shift = 4 - i;
           fill_pattern_B_B_shifted(&result[row], chars[char_index], number_of_columns(chars), shift);
        }
        fill_pattern_B_B(&result[4], chars[4], number_of_columns(chars));
        for (int i = 1; i <= 3 ; ++i) {
            int row = i + 4;
            int char_index = 4 - i;
            int shift = i;
            fill_pattern_B_B_shifted(&result[row], chars[char_index], number_of_columns(chars), shift);
        }
        fill_pattern_A_(&result[8], chars[0], number_of_columns(chars));

        result[9] = NULL;//"   A   "
    }
    return result;
}
