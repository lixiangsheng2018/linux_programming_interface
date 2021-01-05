#include <sys/utsname.h>
#include <linux_header.h>

int main(int argc, char *argv[])
{
    struct utsname uts;

    if (uname(&uts) == -1)
         myc::errExit("uname");

    printf("Node name:   %s\n", uts.nodename);
    printf("System name: %s\n", uts.sysname);
    printf("Release:     %s\n", uts.release);
    printf("Version:     %s\n", uts.version);
    printf("Machine:     %s\n", uts.machine);

    printf("Domain name: %s\n", uts.domainname);

    exit(EXIT_SUCCESS);
}
