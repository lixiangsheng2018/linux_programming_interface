add_executable(procfs_pidmax ${CMAKE_CURRENT_SOURCE_DIR}/procfs_pidmax.cpp)
target_link_libraries(procfs_pidmax
	PRIVATE myc
)

add_executable(t_uname ${CMAKE_CURRENT_SOURCE_DIR}/t_uname.cpp)
target_link_libraries(t_uname
	PRIVATE myc
)