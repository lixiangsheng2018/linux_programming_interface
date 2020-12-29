#include <linux_header.h>
#include <gtest/gtest.h>


TEST(errExit, errExitTest) {

}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
