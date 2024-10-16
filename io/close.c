// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
    int ret = syscall(3, fd);

    if (ret == -1) {
        errno = -ret;
        return -1;
    }

    return ret;
}
