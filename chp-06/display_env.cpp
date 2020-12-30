#include <linux_header.h>

extern char **environ;
                /* Or define _GNU_SOURCE to get it from <unistd.h> */

int main(int argc, char *argv[])
{
    char **ep;

    clearenv();

    for (int j = 1; j < argc; j++)
         if (putenv(argv[j]) != 0)
             myc::errExit("putenv: %s", argv[j]);

    char* myenv = (char *)"LXS=lixiangsheng";
    putenv(myenv);
    puts(getenv("LXS"));

    setenv("LXS","lichenxi",1);
    puts(getenv("LXS"));

    unsetenv("LXS");
    printf("LXS=%s\n",getenv("LXS"));

    for (ep = environ; *ep != NULL; ep++)
        puts(*ep);

    exit(EXIT_SUCCESS);
}
