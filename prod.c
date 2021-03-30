#include "prod.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_TERMINATOR 1

void fill_pattern_letter_in_the_middle(char **result_ptr, char c, int columns) {
    *result_ptr = calloc(columns, sizeof(char));

    char *result = *result_ptr;

    for (int i = 0; i < columns; ++i) {
        result[i] = ' ';
    }

    result[columns/2] = c;
}

void fill_pattern_two_letters(char **result_ptr, char c, int columns, int shift_from_sides) {
    *result_ptr = calloc(columns, sizeof(char));

    char *result = *result_ptr;

    for (int i = 0; i < columns; ++i) {
        result[i] = ' ';
    }

    result[0 + shift_from_sides] = c;
    result[columns - 1 - shift_from_sides] = c;
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

char **diamond_create(char *chars) {
    char **result;

    result = calloc(number_of_rows(chars) + ROW_TERMINATOR, sizeof(char *));
    if (strlen(chars) == 1) {
        fill_pattern_letter_in_the_middle(&result[0], chars[0], number_of_columns(chars));
        result[1] = NULL;
    } else {
        fill_pattern_letter_in_the_middle(&result[0], chars[0], number_of_columns(chars));
        for (int i = 1; i < strlen(chars) - 1; ++i) {
           int row = i;
           int char_index = i;
           int shift = strlen(chars) - 1 - i;
            fill_pattern_two_letters(&result[row], chars[char_index], number_of_columns(chars), shift);
        }
        fill_pattern_two_letters(&result[number_of_columns(chars) / 2], chars[strlen(chars) - 1],
                                 number_of_columns(chars), 0);
        for (int i = 1; i < strlen(chars) -1 ; ++i) {
            int row = i + strlen(chars) - 1 ;
            int char_index = strlen(chars) - 1 - i;
            int shift = i;
            fill_pattern_two_letters(&result[row], chars[char_index], number_of_columns(chars), shift);
        }
        fill_pattern_letter_in_the_middle(&result[number_of_rows(chars) - 1], chars[0], number_of_columns(chars));

        result[number_of_rows(chars)] = NULL;
    }
    return result;
}

void diamond_foreach(char **result, void (*function)(char *)) {
    int i = 0;
    while (result[i] != NULL) {
        function(result[i]);
        i++;
    }
}

void diamond_free(char **result) {
    diamond_foreach(result, (void (*)(char *)) &free);
    free(result);
}
