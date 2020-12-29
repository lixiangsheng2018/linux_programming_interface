#生成文件默认在子目录下，若是在上级目录，需要用RUNTIME_OUTPUT_DIRECTORY来设置target属性，如：
#set_target_properties(glibc_version
#	PROPERTIES
#	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/chp-03"
#)

add_executable(glibc_version ${CMAKE_CURRENT_SOURCE_DIR}/glibc_version.c)

add_executable(syscall ${CMAKE_CURRENT_SOURCE_DIR}/syscall.c)

add_executable(error_function_test ${CMAKE_CURRENT_SOURCE_DIR}/error_function_test.cpp)
target_link_libraries(error_function_test
	PRIVATE myc gtest pthread
)
add_executable(get_number_test ${CMAKE_CURRENT_SOURCE_DIR}/get_number_test.cpp)
target_link_libraries(get_number_test
	PRIVATE myc gtest pthread
)