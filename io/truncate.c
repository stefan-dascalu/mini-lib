// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

typedef long off_t;

int truncate(const char *path, off_t length)
{
    if (path == NULL) {
        errno = EFAULT;
        return -1;
    }

    if (length < 0) {
        errno = EINVAL;
        return -1;
    }

    int ret = syscall(45, path, length);

    if (ret == -1) {
        if (errno == EISDIR) {
            return -1;
        } else if (errno == ENOENT) {
            return -1;
        }
        return -1;
    }

    return 0;
}
