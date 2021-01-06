add_executable(t_stat ${CMAKE_CURRENT_SOURCE_DIR}/t_stat.cpp)
target_link_libraries(t_stat
	PRIVATE myc
)

add_executable(t_utime ${CMAKE_CURRENT_SOURCE_DIR}/t_utime.cpp)
target_link_libraries(t_utime
	PRIVATE myc
)

add_executable(t_umask ${CMAKE_CURRENT_SOURCE_DIR}/t_umask.cpp)
target_link_libraries(t_umask
	PRIVATE myc
)
