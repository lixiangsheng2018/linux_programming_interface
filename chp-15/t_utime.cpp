#include <sys/stat.h>
#include <time.h>
#include <utime.h>
#include <sys/time.h>
#include <linux_header.h>

int main(int argc, char *argv[])
{
    char *pathname;
    struct stat sb;
    struct utimbuf utb;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        myc::usageErr("%s file\n", argv[0]);

    pathname = argv[1];

    if (stat(pathname, &sb) == -1)    /* Retrieve current file times */
    	myc::errExit("stat");

//    utb.actime = sb.st_atime;         /* Leave access time unchanged */
//    utb.modtime = sb.st_atime;        /* Make modify time same as access time */
    time_t t = time(NULL);
    utb.actime = t;
    utb.modtime = t;

    if (utime(pathname, &utb) == -1)  /* Update file times */
    	myc::errExit("utime");


    struct timeval tv[2];
	tv[0].tv_sec = sb.st_atime;         /* Leave atime seconds unchanged */
	tv[0].tv_usec = 223344;             /* Change microseconds for atime */
	tv[1].tv_sec = sb.st_atime;         /* mtime seconds == atime seconds */
	tv[1].tv_usec = 667788;             /* mtime microseconds */
	if (utimes(argv[1], tv) == -1)
		myc::errExit("utimes");
    exit(EXIT_SUCCESS);
}
