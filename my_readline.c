#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int READLINE_READ_SIZE = 512;
char* storage = NULL;
char* my_readline(int fd);

int main (int ac, char** av) {
    for (int index_arg = 1; index_arg < ac; index_arg++) {
        int fd = open(av[index_arg], O_RDONLY);
        char* final;
        while ((final = my_readline(fd)) != NULL) {
            printf("%s", final);
            free(final);
        }
        close(fd);

    }
    return 0;
}

int line_jump(char* buffer, ssize_t reading) {
    int index_jump = -1;
    for (int i = 0; i < reading; i++) {
        if (buffer[i] == '\n') {
            index_jump = i;
            break;
        }
    }
    return index_jump;
}

void init_my_readline(void) {
    free(storage);
    storage = NULL;
}

char* read_line(int fd, char* buffer) {

}

int save_storage(char* buffer, ssize_t reading) {
    if (storage == NULL) {
        storage = malloc(sizeof(char) * (reading + 1));
        int index_storage = 0;
        for (int index_buffer = 0; index_buffer < reading; index_buffer++) {
            storage[index_storage] = buffer[index_buffer];
            index_storage++;
        }
        storage[index_storage] = '\0';
        return my_readline(fd);
    }
    int size_storage = count_string(storage);
    char* storage2 = malloc(sizeof(char) * (size_storage + reading + 1));
    int index_storage = 0;
    while (index_storage < size_storage) {
        storage2[index_storage] = storage[index_storage];
        index_storage++;
    }
    
    for (int index_buffer = 0; index_buffer < reading; index_buffer++) {
        storage2[index_storage] = buffer[index_buffer];
        index_storage++;
    }
    storage2[index_storage] = '\0';
    free(storage);
    storage = storage2;
    return my_readline(fd);
}

char* extract_line(char* buffer, ssize_t reading, int index_jump) (

)

char* line_from_storage(void) {
    if (storage == NULL) {
        return NULL;
    }
    int size_storage = count_string(storage);
    char* final = malloc(sizeof(char) * (size_storage + 1));
    for (int i = 0; i < size_storage; i++) {
        final[i] = storage[i];
    }
    final[size_storage] = '\0';

    free(storage);
    storage = NULL;
    return final;
}

char* my_readline(int fd) {
    char buffer[READLINE_READ_SIZE];
    
    ssize_t reading = read(fd, buffer, READLINE_READ_SIZE);
    if (reading == -1) {
        return NULL;
    }
    if (reading == 0) {
        return line_from_storage(void);
    }

    int index_jump = line_jump(buffer, reading);

    if(index_jump == -1) {
        if(save_storage(buffer, reading)) {
            return NULL;
        } else {
            return my_readline(fd);
        }
    }

    if (storage == NULL) {
        if (index_jump != reading - 1) {
            int new_size_storage = reading - index_jump - 1;
            storage = malloc(sizeof(char) * new_size_storage + 1);
            int index_storage = 0, index_buffer = index_jump + 1;
            while (index_storage < new_size_storage) {
                storage[index_storage] = buffer[index_buffer];
                index_storage++;
                index_buffer++;
            }
            storage[index_storage] = '\0';
        }
        char* final = malloc(sizeof(char) * (index_jump + 1));
        for(int i = 0; i < index_jump; i++) {
            final[i] = buffer[i];
        }
        final[index_jump] = '\0';
        return final;
    }


    int size_storage = count_string(storage);
    char* final = malloc(sizeof(char) * (size_storage + index_jump + 1));
    int index_final = 0;
    while(index_final < size_storage) {
        final[index_final] = storage[index_final];
        index_final++;
    }
    for (int index_buffer = 0; index_buffer < index_jump; index_buffer++) {
        final[index_final] = buffer[index_buffer];
        index_final++;
    }
    final[index_final] = '\0';
    free(storage);
    storage = NULL;
    if (index_jump != reading - 1) {
        int new_size_storage = reading - index_jump - 1;
        storage = malloc(sizeof(char) * new_size_storage + 1);
        int index_storage = 0, index_buffer = index_jump + 1;
        while (index_storage < new_size_storage) {
            storage[index_storage] = buffer[index_buffer];
            index_storage++;
            index_buffer++;
        }
        storage[index_storage] = '\0';
    }
    return final;
}

int count_string(char* string) {
    int i = 0, count = 0;
    while (string[i] != '\0') {
        count++;
        i++;
    }
    return count;
}



char* reding_0 (void) {
    if (storage == NULL) {
        return NULL;
    }
    int size_storage = count_string(storage);
    char* final = malloc(sizeof(char) * (size_storage + 1));
    for (int i = 0; i < size_storage; i++) {
        final[i] = storage[i];
    }
    final[size_storage] = '\0';

    free(storage);
    storage = NULL;
    return final;
}
char* no_line_jump(char* buffer, ssize_t reading) {
    if (storage == NULL) {
        storage = malloc(sizeof(char) * (reading + 1));
        int index_storage = 0;
        for (int index_buffer = 0; index_buffer < reading; index_buffer++) {
            storage[index_storage] = buffer[index_buffer];
            index_storage++;
        }
        storage[index_storage] = '\0';
        return my_readline(fd);
    }
    int size_storage = count_string(storage);
    char* storage2 = malloc(sizeof(char) * (size_storage + reading + 1));
    int index_storage = 0;
    while (index_storage < size_storage) {
        storage2[index_storage] = storage[index_storage];
        index_storage++;
    }
    
    for (int index_buffer = 0; index_buffer < reading; index_buffer++) {
        storage2[index_storage] = buffer[index_buffer];
        index_storage++;
    }
    storage2[index_storage] = '\0';
    free(storage);
    storage = storage2;
    return my_readline(fd);
}