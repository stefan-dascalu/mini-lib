# Dascălu Ștefan-Nicolae 321CA
## Mini-libc

### Objectives
- Learn about the structure and functionalities provided by the standard C library.
- Acquaint with the syscall interface in Linux.
- Gain a better understanding of strings and memory management functions.
- Learn how the standard C library supports low-level input/output operations.

### Statement
Build a minimalistic [standard C library](https://en.wikipedia.org/wiki/C_standard_library) implementation for Linux systems (named **mini-libc**) that can be used as a replacement for the system libc (glibc in Linux). The goal is to have a minimally functional libc with features such as string management, basic memory support, and POSIX file I/O.

The implementation of mini-libc will be **freestanding**, meaning it will not use any outside library calls. It will be built on top of the system call interface provided by Linux on an x86_64 architecture. Any function you require that is typically part of libc must be implemented by you. Functions that you implement can be reused in other parts of the mini-libc.

If using a macOS device with ARM64/Aarch64, an x86_64 virtual machine must be installed.

### Support Code
The support code consists of three directories:

- **libc/**: The skeleton mini-libc implementation where you will implement the missing parts marked as TODO items.
- **samples/**: Contains use cases and tests for mini-libc.
- **tests/**: Includes states used to validate (and grade) the assignment.

System call invocation is done via the **syscall()** function defined in **libc/syscall.c**, which calls the architecture-specific function in **libc/internal/arch/x86_64/syscall_arch.h**, thus depending on the x86_64 architecture.

### API and Implementation Tasks
The application programming interface (API) of the C standard library is declared in several header files. For your minimal implementation, the following header files are of interest:

- **<string.h>**: Defines string-handling functions. Implement the following functions: 
  - `strcpy()`, `strcat()`, `strlen()`, `strncpy()`, `strncat()`, `strcmp()`, `strncmp()`, `strstr()`, `strrstr()`, `memcpy()`, `memset()`, `memmove()`, `memcmp()`.

- **<stdio.h>**: Defines printing and I/O functions. Implement:
  - `puts()`.

- **<unistd.h>, <sys/fcntl.h>, and <sys/stat.h>**: Define I/O primitives. Implement:
  - `open()`, `close()`, `lseek()`, `stat()`, `fstat()`, `truncate()`, `ftruncate()`, `nanosleep()`, and `sleep()`.

- **<stdlib.h> and <sys/mman.h>**: Define memory allocation functions. Implement:
  - `malloc()`, `free()`, `calloc()`, `realloc()`, `realloc_array()`, `mmap()`, `mremap()`, and `munmap()`.

- **<errno.h> and errno.c**: Declare and define the integer variable `errno`, which is set by system calls and some library functions to indicate errors.

Some tests may not build; this is intentional. You will need to add the missing features to compile those tests, including:
- The `time.h` header.
- The declaration and implementation of `puts()`, `nanosleep()`, and `sleep()`.
- Updating the libc Makefile to build the source code files for `puts()`, `nanosleep()`, and `sleep()`.

### Building mini-libc
To build mini-libc, run `make` in the **libc/** directory:
```bash
student@so:~/.../assignments/mini-libc$ cd libc/
student@so:~/.../assignments/mini-libc/libc$ make
