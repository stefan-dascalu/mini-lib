// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
    if (path == (void *)0) {
        errno = EFAULT;
        return -1;
    }

    if (buf == (void *)0) {
        errno = EFAULT;
        return -1;
    }

    int ret = syscall(4, path, buf);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

