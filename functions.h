#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

extern char* STORAGE;
extern int READLINE_READ_SIZE;

char* my_readline(int fd);
char* end_file(void);
int jump(char* buffer, ssize_t reading);
int no_jump_line(char* buffer, ssize_t reading);
char* jump_line(char* buffer, ssize_t reading, int index_jump);
char* jump_and_no_storage(char* buffer, ssize_t reading, int index_jump);
char* jump_and_storage(char* buffer, ssize_t reading, int index_jump);
int count_string(char* string);
void fill_string(char* string1, char* string2, int index1, int index2, int condition);
void init_my_readline(void);