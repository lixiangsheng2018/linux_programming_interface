#include <sys/xattr.h>
#include <linux_header.h>

#define XATTR_SIZE 10000

void getattr(int argc, char *argv[]){
    char list[XATTR_SIZE], value[XATTR_SIZE];
    ssize_t listLen, valueLen;
    int ns, j, k, opt;
    bool hexDisplay;

    hexDisplay = 0;
    while ((opt = getopt(argc, argv, "x")) != -1) {
        switch (opt) {
        case 'x': hexDisplay = 1;       break;
        case '?': myc::usageErr("Usage: %s [-x] file...\n",argv[0]);
        }
    }

    if (optind >= argc)
    	myc::usageErr("Usage: %s [-x] file...\n",argv[0]);

    for (j = optind; j < argc; j++) {
        listLen = listxattr(argv[j], list, XATTR_SIZE);
        if (listLen == -1)
            myc::errExit("listxattr");

        printf("%s:\n", argv[j]);

        /* Loop through all EA names, displaying name + value */

        for (ns = 0; ns < listLen; ns += strlen(&list[ns]) + 1) {
            printf("        name=%s; ", &list[ns]);

            valueLen = getxattr(argv[j], &list[ns], value, XATTR_SIZE);
            if (valueLen == -1) {
                printf("couldn't get value");
            } else if (!hexDisplay) {
                printf("value=%.*s", (int) valueLen, value);
            } else {
                printf("value=");
                for (k = 0; k < valueLen; k++)
                    printf("%02x ", (unsigned char) value[k]);
            }

            printf("\n");
        }

        printf("\n");
    }

}

int main(int argc, char *argv[])
{
    char *value;

    if (argc < 2 || strcmp(argv[1], "--help") == 0)
        myc::usageErr("%s file\n", argv[0]);

    value = (char*)"The past is not dead.";
    if (setxattr(argv[1], "user.x", value, strlen(value), 0) == -1)
    	myc::errExit("setxattr");

    value = (char*)"In fact, it's not even past.";
    if (setxattr(argv[1], "user.y", value, strlen(value), 0) == -1)
    	myc::errExit("setxattr");

    getattr(argc,argv);

    exit(EXIT_SUCCESS);
}
