#include "functions.h"

char* my_readline(int fd) {
    char buffer[READLINE_READ_SIZE];
    ssize_t reading = read(fd, buffer, READLINE_READ_SIZE);
    verif_read(reading);
    
    if (reading == 0) {
        return end_file();
    }
    int index_jump = jump(buffer, reading);
    if(index_jump == -1) {
        no_jump_line(buffer, reading);
        return my_readline(fd);
    }
    return jump_line(buffer, reading, index_jump);
}

char* end_file(void) {
    //NO STORAGE:
    if (storage == NULL) {
        return NULL;
    }
    //STORAGE:
    int size_storage = count_string(storage);
    char* final = malloc_and_verif(size_storage + 1);
    fill_string(final, storage, 0, 0, size_storage);
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

void no_jump_line(char* buffer, ssize_t reading) {
    //NO STORAGE:
    if (storage == NULL) {
        storage = malloc_and_verif(reading + 1);
        fill_string(storage, buffer, 0, 0, reading);
    } else {
    //STORAGE:
        int size_storage = count_string(storage);
        char* storage2 = malloc_and_verif(size_storage + reading + 1);
        fill_string(storage2, storage, 0, 0, size_storage);
        fill_string(storage2, buffer, size_storage, 0, size_storage + reading);
        free(storage);
        storage = storage2;
    }
}

char* jump_line(char* buffer, ssize_t reading, int index_jump) {
    //NO STORAGE:
    if (storage == NULL) {
        return jump_and_no_storage(buffer, reading, index_jump);
    }
    //STORAGE:
    return jump_and_storage(buffer, reading, index_jump);
}

char* jump_and_no_storage(char* buffer, ssize_t reading, int index_jump) {
    char* final = malloc_and_verif(index_jump + 1);
    fill_string(final, buffer, 0, 0, index_jump);
    //JUMP IN THE MIDDLE:
    if (index_jump != (reading - 1)) {
        int new_size_storage = reading - index_jump - 1;
        storage = malloc_and_verif(reading - index_jump - 1);
        fill_string(storage, buffer, 0, index_jump + 1, new_size_storage);
    }
    return final;
}

char* jump_and_storage(char* buffer, ssize_t reading, int index_jump) {
    int size_storage = count_string(storage);
    char* final = malloc_and_verif(size_storage + index_jump + 1);
    fill_string(final, storage, 0, 0, size_storage);
    fill_string(final, buffer, size_storage, 0, size_storage + index_jump);
    init_my_readline();
    //JUMP IN THE MIDDLE:
    if (index_jump != reading - 1) {
        int new_size_storage = reading - index_jump - 1;
        storage = malloc_and_verif(new_size_storage + 1);
        fill_string(storage, buffer, 0, index_jump + 1, new_size_storage);
    }
    return final;
}