#include "functions.h"

char* STORAGE = NULL;
int  READLINE_READ_SIZE = 512;


char* my_readline(int fd) {
    char buffer[READLINE_READ_SIZE];
    ssize_t reading = read(fd, buffer, READLINE_READ_SIZE);
    if (reading == -1) {
        return NULL;
    }
    if (reading == 0) {
        return end_file();
    }
    int index_jump = jump(buffer, reading);
    if(index_jump == -1) {
        if (no_jump_line(buffer, reading)) {
            return NULL;
        }
        return my_readline(fd);
    }
    return jump_line(buffer, reading, index_jump);
}

char* end_file(void) {
    //NO STORAGE:
    if (STORAGE == NULL) {
        return NULL;
    }
    //STORAGE:
    int size_storage = count_string(STORAGE);
    char* final = malloc(sizeof(char) * (size_storage + 1));
    if (final == NULL)
        return NULL;
    fill_string(final, STORAGE, 0, 0, size_storage);
    init_my_readline();
    return final;
}

int jump(char* buffer, ssize_t reading) {
    int index_jump = -1;
    for (int i = 0; i < reading; i++) {
        if (buffer[i] == '\n') {
            index_jump = i;
            break;
        }
    }
    return index_jump;
}

int no_jump_line(char* buffer, ssize_t reading) {
    //NO STORAGE:
    if (STORAGE == NULL) {
        STORAGE = malloc(sizeof(char) * (reading + 1));
        if (STORAGE == NULL)
            return 1;
        fill_string(STORAGE, buffer, 0, 0, reading);
    } else {
    //STORAGE:
        int size_storage = count_string(STORAGE);
        char* storage2 = malloc(sizeof(char) * (size_storage + reading + 1));
        if (storage2 == NULL)
            return 1;
        fill_string(storage2, STORAGE, 0, 0, size_storage);
        fill_string(storage2, buffer, size_storage, 0, size_storage + reading);
        free(STORAGE);
        STORAGE = storage2;
    }
    return 0;
}

char* jump_line(char* buffer, ssize_t reading, int index_jump) {
    //NO STORAGE:
    if (STORAGE == NULL) {
        return jump_and_no_storage(buffer, reading, index_jump);
    }
    //STORAGE:
    return jump_and_storage(buffer, reading, index_jump);
}

char* jump_and_no_storage(char* buffer, ssize_t reading, int index_jump) {
    char* final = malloc(sizeof(char) * (index_jump + 1));
    if (final == NULL)
        return NULL;
    fill_string(final, buffer, 0, 0, index_jump);
    //JUMP IN THE MIDDLE:
    if (index_jump != (reading - 1)) {
        int new_size_storage = reading - index_jump - 1;
        STORAGE = malloc(sizeof(char) * (reading - index_jump - 1));
        if (STORAGE == NULL)
            return NULL;
        fill_string(STORAGE, buffer, 0, index_jump + 1, new_size_storage);
    }
    return final;
}

char* jump_and_storage(char* buffer, ssize_t reading, int index_jump) {
    int size_storage = count_string(STORAGE);
    char* final = malloc(sizeof(char) * (size_storage + index_jump + 1));
    if (final == NULL)
        return NULL;
    fill_string(final, STORAGE, 0, 0, size_storage);
    fill_string(final, buffer, size_storage, 0, size_storage + index_jump);
    init_my_readline();
    //JUMP IN THE MIDDLE:
    if (index_jump != reading - 1) {
        int new_size_storage = reading - index_jump - 1;
        STORAGE = malloc(sizeof(char) * (new_size_storage + 1));
        if (STORAGE == NULL)
            return NULL;
        fill_string(STORAGE, buffer, 0, index_jump + 1, new_size_storage);
    }
    return final;
}