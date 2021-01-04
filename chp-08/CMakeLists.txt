add_executable(t_getpwent ${CMAKE_CURRENT_SOURCE_DIR}/t_getpwent.cpp)

add_executable(t_getpwnam_r ${CMAKE_CURRENT_SOURCE_DIR}/t_getpwnam_r.cpp)
target_link_libraries(t_getpwnam_r
	PRIVATE myc
)

add_executable(check_password ${CMAKE_CURRENT_SOURCE_DIR}/check_password.cpp)
target_link_libraries(check_password
	PRIVATE myc crypt
)
