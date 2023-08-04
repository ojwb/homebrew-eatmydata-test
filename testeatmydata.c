#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd;
    for (fd = 0; fd <= 2; ++fd) {
	int r = fsync(fd);
	if (r != 0) {
	    printf("fsync of fd %d failed: %s\n", fd, strerror(errno));
	}
#ifdef __APPLE__
	r = fcntl(fd, F_FULLFSYNC, 0);
	if (r != 0) {
	    printf("F_FULLFSYNC of fd %d failed: %s\n", fd, strerror(errno));
	}
#endif
    }
    return 0;
}
