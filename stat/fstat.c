// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
    if (fd < 0) {
        errno = EBADF;
        return -1;
    }

    if (st == (void *)0) {
        errno = EFAULT;
        return -1;
    }

    int ret = syscall(5, fd, st);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

