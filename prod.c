#include "prod.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *diamond(char *chars){
    char *result;
    result = calloc(10, sizeof(char));
    result[0] = chars[0];
    return result;
}
