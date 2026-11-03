#include "functions.h"

int main(int ac, char** av) {
    for (int index_arg = 1; index_arg < ac; index_arg++) {
        int fd = open(av[index_arg], O_RDONLY);
        char* final;
        while ((final = my_readline(fd)) != NULL) {
            printf("%s\n", final);
            free(final);
        }
        printf("NULL\n");
        close(fd);
        init_my_readline();
    }
    return 0;
}