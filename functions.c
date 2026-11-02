#include "functions.h"

void verif_read(ssize_t reading) {
    if (reading == -1) {
        exit(NULL);
    }
}

int count_string(char* string) {
    int i = 0, count = 0;
    while (string[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

char* malloc_and_verif(int size) {
    char* string = malloc(sizeof(char) * size);
    if(string == NULL) {
        exit(NULL);
    }
    return string;
}

void fill_string(char* string1, char* string2, int index1, int index2, int condition) {
    while (index1 < condition) {
        string1[index1] = string2[index2];
        index1++;
        index2++;
    }
    string1[index1] = '\0';
}

void init_my_readline(void) {
    free(storage);
    storage = NULL;
}