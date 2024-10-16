#include <internal/syscall.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req = { .tv_sec = seconds, .tv_nsec = 0 };
    struct timespec rem;

    if (nanosleep(&req, &rem) == 0) {
        return 0;
    }

    if (errno == EINTR) {
        return rem.tv_sec + (rem.tv_nsec > 0 ? 1 : 0);
    }

    return 0;
}
