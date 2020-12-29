//#define _LARGEFILE64_SOURCE
#include <sys/stat.h>
#include <fcntl.h>
#include <linux_header.h>

int main(int argc, char *argv[])
{
    int fd;
    off64_t off;

    if (argc != 3 || strcmp(argv[1], "--help") == 0)
        myc::usageErr("%s pathname offset\n", argv[0]);

    fd = open64(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    	myc::errExit("open64");

    off = atoll(argv[2]);
    if (lseek64(fd, off, SEEK_SET) == -1)
    	myc::errExit("lseek64");

    if (write(fd, "test", 4) == -1)
    	myc::errExit("write");
    exit(EXIT_SUCCESS);
}
