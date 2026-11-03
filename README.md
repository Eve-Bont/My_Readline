# Welcome to My Readline

## Task
The goal of this project is to recreate the behavior of a line-reading function in C.
The function `my_readline(int fd)` reads a file descriptor and returns its content one line at a time.
The main challenge is that the `read()` function does not necessarily read only one line.
It can read several lines at once, or only part of a line.

The program must therefore:
- Read a line without including the newline character (`\n`).
- Return the remaining characters when reaching the end of the file, even if there is no final newline.
- Return `NULL` when there is nothing left to read or when an error occurs.
- Keep the extra characters read after a newline for the next function call.
- Handle different file descriptors.

## Description
The project is implemented in C and uses dynamic memory allocation to manage the data read from a file descriptor.

The main function is:
```c
char *my_readline(int fd);
```
Each call to `my_readline()` returns the next available line as a dynamically allocated string.

### How it works
The program uses two global variables:
- `STORAGE`: stores characters that have been read but do not yet form a complete line, or characters remaining after a newline.
- `READLINE_READ_SIZE`: defines the number of bytes requested by each `read()` call. Its default value is `512`, but it can be modified.

The reading process works as follows:
1. The program reads data from the file descriptor into a buffer.
2. It searches for a newline character (`\n`).
3. If no newline is found, the data is added to `STORAGE` and the program continues reading.
4. If a newline is found, the program builds and returns the complete line.
5. Any characters read after the newline are saved in `STORAGE` for the next call.
6. When the end of the file is reached, the remaining characters are returned once. Subsequent calls return `NULL`.

The project also includes the function:
```c
void init_my_readline(void);
```
This function frees the memory allocated to `STORAGE` and resets it to `NULL`.

**Important:** When using `my_readline()` in another program, remember to call `init_my_readline()` whenever `my_readline()` returns `NULL`, so that the remaining allocated memory is released. In this project, this cleanup is handled in `main()` after the reading loop.

## Installation
Clone or download the project, then compile it using the Makefile.
```bash
make
```

To clean the object files:
```bash
make clean
```

To remove the executable and object files:
```bash
make fclean
```

To clean and recompile the project:
```bash
make re
```

## Usage
Run the program with one or more file paths as arguments:
```bash
./my_readline argument1 argument2
```

Example:
```bash
./my_readline file1.txt file2.txt
```

The program reads each file line by line and displays its contents.

### Example
If `file1.txt` contains:
```text
Hello
How are you?
Welcome to My Readline
```

Running:
```bash
./my_readline file1.txt
```

Displays:
```text
Hello
How are you?
Welcome to My Readline
NULL
```

## The Core Team
<span><i>Made at <a href="https://qwasar.io">Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width="20px" /></span>