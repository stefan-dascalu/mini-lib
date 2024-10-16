// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

typedef long off_t;

off_t lseek(int fd, off_t offset, int whence)
{
    if (fd < 0) {
        errno = EBADF;
        return (off_t) -1;
    }

    if (whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END) {
        errno = EINVAL;
        return (off_t) -1;
    }

    off_t ret = syscall(8, fd, offset, whence);
    if (ret == (off_t) -1) {
        errno = -ret;
        return (off_t) -1;
    }

    return ret;
}


