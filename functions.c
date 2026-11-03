#include "functions.h"

int count_string(char* string) {
    int i = 0, count = 0;
    while (string[i] != '\0') {
        count++;
        i++;
    }
    return count;
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
    free(STORAGE);
    STORAGE = NULL;
}