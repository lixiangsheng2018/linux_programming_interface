#include <stdio.h>
#include <linux_header.h>
#include <gtest/gtest.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

TEST(errExit, errExitTest) {
	myc::errExit("errExit...");
}

TEST(errMsg, errMsgTest) {
	int fd = open("hello.txt",O_RDWR);
	if( fd == -1){
		myc::errMsg("errno(%d)",errno);
	}
	myc::errMsg("hello");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  myc::errMsg("main...");
  return ret;
}
