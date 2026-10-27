#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int READLINE_READ_SIZE = 512;
char* my_readline(int fd);

int main (int ac, char** av) {
    for (int index_arg = 1; index_arg < ac; index_arg++) {
        int fd = open(av[index_arg], O_RDONLY);
        char* final = my_readline(fd);
        printf("%s", final);
        free(final);
    }
    return 0;
}

char* my_readline(int fd) {
    char buffer[READLINE_READ_SIZE];
    
    size_t total = 0;
    while(total < size) {
        ssize_t reading = read(fd, buffer + total, READLINE_READ_SIZE - total);
        if (reading <= 0) {
            return 1;
        }
        total += reading;
    }
    if (reading == -1) {
        return NULL;
    }

    
    return final;
}