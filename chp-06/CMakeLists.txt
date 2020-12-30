add_executable(mem_segments ${CMAKE_CURRENT_SOURCE_DIR}/mem_segments.cpp)

add_executable(display_env ${CMAKE_CURRENT_SOURCE_DIR}/display_env.cpp)
target_link_libraries(display_env
	PRIVATE myc
)

add_executable(longjump ${CMAKE_CURRENT_SOURCE_DIR}/longjump.cpp)