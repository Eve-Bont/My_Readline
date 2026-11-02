#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int READLINE_READ_SIZE = 512;
char* storage = NULL;

char* my_readline(int fd);
char* end_file(void);
int jump(char* buffer, ssize_t reading);
void no_jump_line(char* buffer, ssize_t reading);
char* jump_line(char* buffer, ssize_t reading, int index_jump);
char* jump_and_no_storage(char* buffer, ssize_t reading, int index_jump);
char* jump_and_storage(char* buffer, ssize_t reading, int index_jump);
void verif_read(ssize_t reading);
int count_string(char* string);
char* malloc_and_verif(int size);
void fill_string(char* string1, char* string2, int index1, int index2, int condition);
void init_my_readline(void);