// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
    if (flags & O_CREAT) {
        va_list args;
        va_start(args, flags);
        mode_t mode = va_arg(args, mode_t);
        va_end(args);
        int ret = syscall(2, filename, flags, mode);

        if (ret < 0) {
            errno = -ret;
            return -1;
        }

        return ret;
    } else {
        int ret = syscall(2, filename, flags);

        if (ret < 0) {
            errno = -ret;
            return -1;
        }

        return ret;
    }
}
