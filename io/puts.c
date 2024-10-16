// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int puts(const char *str) {
    ssize_t len = 0;

    while (str[len] != '\0') {
        ++len;
    }

    ssize_t writte = write(1, str, len);

    if (writte != len) {
        return -1;
    }
    
    write(1, "\n", 1);

    return 1;
}
