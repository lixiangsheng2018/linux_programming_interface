#include <gnu/libc-version.h>
#include <stdio.h>

int main(){
	printf("glbc version is %d.%d\n",__GLIBC__,__GLIBC_MINOR__);
	printf("glbc version is %s\n",gnu_get_libc_version());
	return 0;
}
