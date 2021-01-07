add_executable(get_setxattr ${CMAKE_CURRENT_SOURCE_DIR}/get_setxattr.cpp)
target_link_libraries(get_setxattr
	PRIVATE myc
)