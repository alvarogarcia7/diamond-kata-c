
char **diamond_create(char *chars);

void diamond_foreach(char **result, void (*function)(char *each));

void diamond_free(char **result);
