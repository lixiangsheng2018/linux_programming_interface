add_executable(t_sysconf ${CMAKE_CURRENT_SOURCE_DIR}/t_sysconf.cpp)
target_link_libraries(t_sysconf
	PRIVATE myc
)

add_executable(t_fpathconf ${CMAKE_CURRENT_SOURCE_DIR}/t_fpathconf.cpp)
target_link_libraries(t_fpathconf
	PRIVATE myc
)