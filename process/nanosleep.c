#include <internal/syscall.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int check = syscall(35, req, rem);

    if (check == -1) {
        errno = EINTR;
        return -1;
    }

    return 0;
}
