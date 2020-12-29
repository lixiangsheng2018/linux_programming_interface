execute_process(
	COMMAND sh ${CMAKE_CURRENT_SOURCE_DIR}/build_name.sh
	OUTPUT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/ename.inc.h #重定向输出文件
)

file(GLOB LIB_LXS_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)#找出当前目录下所有的.c文件,不会查找子目录

add_library(myc STATIC ${LIB_LXS_SOURCE})
