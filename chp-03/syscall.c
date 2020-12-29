/*
 * syscall.c
 *
 *  Created on: 2020年12月17日
 *      Author: lxs
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
	int fd = open("hello.txt",O_RDWR);
	if( fd == -1){
		int err = errno;
		printf("open failed %d,%s\n",err,strerror(err));
		perror("open hello.txt failed!");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}



