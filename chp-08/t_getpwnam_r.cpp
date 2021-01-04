#include <pwd.h>
#include <linux_header.h>

int main(int argc, char *argv[])
{
    struct passwd pwd;
    struct passwd *result;
    char *buf;
    size_t bufSize;
    int s;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        myc::usageErr("%s username\n", argv[0]);

    bufSize = sysconf(_SC_GETPW_R_SIZE_MAX);
    buf = (char *)malloc(bufSize);
    if (buf == NULL)
    	myc::errExit("malloc %d", bufSize);

    s = getpwnam_r(argv[1], &pwd, buf, bufSize, &result);
    if (s != 0)
    	myc::errExitEN(s, "getpwnam_r");

    if (result != NULL)
        printf("Name: %s\n", pwd.pw_gecos);
    else
        printf("Not found\n");

    exit(EXIT_SUCCESS);
}
